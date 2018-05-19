-- ---------------------------------------------------------------
--                Создание пользовательских типов данных
-- ---------------------------------------------------------------
CREATE TYPE proglang AS ENUM ('c', 'cpp', 'go', 'java', 'unknown');
CREATE TYPE verdict AS ENUM ('Passed tests', 'Failed tests', 'Draft', 'Not tested');
CREATE TYPE lexem_type AS ENUM ('keyword', 'special', 'ident', 'skippable', 'literal', 'pragma', 'other');
create type coord as (pos int, line int, col int, tab int);      

-- Для просмотра типов, добавленных пользователем, выполнить
-- select n.nspname as enum_schema,  
--        t.typname as enum_name,  
--        e.enumlabel as enum_value
-- from pg_type t 
--    join pg_enum e on t.oid = e.enumtypid  
--    join pg_catalog.pg_namespace n ON n.oid = t.typnamespace;

CREATE TABLE Problem(
problem_id int  PRIMARY KEY,
content    text,
points     int
);

CREATE TABLE ProblemVersion(
problem_ver_id SERIAL    PRIMARY KEY,
problem_fk        int  NOT NULL
    REFERENCES Problem(problem_id)  ON DELETE CASCADE,
ver            int       NOT NULL,
creation_time  timestamp NOT NULL DEFAULT localtimestamp,
CONSTRAINT AK_ProblemVersion UNIQUE(problem_fk, ver)
);

CREATE TABLE Test(
test_id     SERIAL PRIMARY KEY,
problem_fk  int    NOT NULL
    REFERENCES ProblemVersion(problem_ver_id) ON DELETE CASCADE,
test_number int    NOT NULL,
content     text   NOT NULL,
answer      text   NOT NULL,
CONSTRAINT AK_Test UNIQUE(problem_fk, test_number)
);

CREATE TABLE Student(
student_id   SERIAL      PRIMARY KEY,
login        varchar(20) UNIQUE NOT NULL,
surname      varchar(50) NULL,
student_name varchar(50) NULL,
patronymic   varchar(50) NULL,
department   varchar(5)  NULL,
group_num    int         NULL
);

CREATE TABLE SourceFile(
file_id       SERIAL PRIMARY KEY,
task_fk       int    NOT NULL REFERENCES ProblemVersion(problem_ver_id) ON DELETE CASCADE,
student_fk    int    NOT NULL REFERENCES Student(student_id) ON DELETE CASCADE,
code          text   NOT NULL,
code_language proglang  NOT NULL,
send_time     timestamp NOT NULL,
tests_verdict verdict   NOT NULL,
plagiarised   boolean   NULL,
CONSTRAINT ak_sourcefile UNIQUE (student_fk, send_time)
);

CREATE TABLE FilesComparison(
file_to_test int NOT NULL REFERENCES SourceFile(file_id) ON DELETE CASCADE,
file_base    int NOT NULL REFERENCES SourceFile(file_id) ON DELETE CASCADE,
match_rating int NOT NULL,
CONSTRAINT PK_FilesComparison
    PRIMARY KEY(file_base, file_to_test)
);

CREATE TABLE Lexem(
from_file_fk int    REFERENCES SourceFile(file_id) ON DELETE CASCADE,
array_index  int,
digest       numeric(39),
lexem_type   lexem_type,
start_coord   coord NOT NULL,
follow_coord  coord NOT NULL,
CONSTRAINT PK_Lexem PRIMARY KEY(from_file_fk, array_index)
);

-- --------------------------------------------------------
--                Создание представлений
-- --------------------------------------------------------
CREATE VIEW LexemSourceFile AS
SELECT
SourceFile.file_id, SourceFile.student_fk, SourceFile.task_fk, SourceFile.code, SourceFile.code_language, SourceFile.send_time,
Lexem.array_index, Lexem.digest, Lexem.lexem_type, Lexem.start_coord, Lexem.follow_coord
FROM SourceFile JOIN Lexem ON SourceFile.file_id = Lexem.from_file_fk;

CREATE VIEW Digests AS
SELECT
l1.from_file_fk, l1.array_index, l1.digest,
l1.start_coord, l2.follow_coord
FROM Lexem l1 JOIN Lexem l2
ON
l1.from_file_fk = l2.from_file_fk
AND
l1.digest IS NOT NULL
AND
l2.array_index  = l1.array_index + 19; -- Follow последней лексемы в чанке => chunk_len - 1

CREATE VIEW SourceFileStudentName AS
SELECT
SourceFile.*,
Student.login
FROM SourceFile JOIN Student
ON SourceFile.student_fk = Student.student_id;

CREATE VIEW FilesComparisonStudentName AS
SELECT
f1.task_fk, 
f1.file_id AS "f1.file_id", f1.login AS "f1.login", f1.send_time AS "f1.send_time",
fc.match_rating,
f2.file_id AS "f2.file_id", f2.login AS "f2.login", f2.send_time AS "f2.send_time"
FROM SourceFileStudentName f1, FilesComparison fc, SourceFileStudentName f2
WHERE f1.file_id = fc.file_to_test AND f2.file_id = fc.file_base;

-- ---------------------------------------------------------------
--    Добавление триггера на вставку файла по логину студента
-- ---------------------------------------------------------------

CREATE OR REPLACE FUNCTION insertsourcefile_fn() RETURNS TRIGGER AS $SourceFileStudentName$
DECLARE
    student_id int := (SELECT Student.student_id FROM Student WHERE NEW.login = Student.login);
BEGIN
    INSERT INTO SourceFile (task_fk, student_fk, code, code_language, send_time, lexem_num, digest_num)
    VALUES (NEW.task_fk, student_id, NEW.code, NEW.code_language, NEW.send_time, NEW.lexem_num, NEW.digest_num);
    RETURN NEW;
END;
$SourceFileStudentName$ LANGUAGE plpgsql;

CREATE TRIGGER insertsourcefile_trigger
INSTEAD OF INSERT ON SourceFileStudentName
    FOR EACH ROW EXECUTE PROCEDURE insertsourcefile_fn();
    
    
-- ---------------------------------------------------------------
--    Функция для подсчета длины массива дайджестов в файле
-- ---------------------------------------------------------------

CREATE OR REPLACE FUNCTION countDigestArrayLength(IN id int)
RETURNS int AS $$
DECLARE counter int := (SELECT COUNT(digest) FROM Lexem WHERE from_file_fk = id);
BEGIN
RETURN counter;
END;
$$ LANGUAGE plpgsql;


