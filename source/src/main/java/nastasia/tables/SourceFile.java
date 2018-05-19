package nastasia.tables;

import nastasia.connectionholder.ConnectionHolder;
import nastasia.datatypes.FilePair;
import pro.skor.ossmoss.SourceCode;
import pro.skor.ossmoss.stamp.Verdict;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

/*
-- Просмотреть типы, добавленные пользователем
select n.nspname as enum_schema,
       t.typname as enum_name,
       e.enumlabel as enum_value
from pg_type t
   join pg_enum e on t.oid = e.enumtypid
   join pg_catalog.pg_namespace n ON n.oid = t.typnamespace;
 */

/**
 test=# \d sourcefile
 Таблица "public.sourcefile"
 Столбец    |             Тип             |                         Модификаторы
 ---------------+-----------------------------+--------------------------------------------------------------
 file_id       | integer                     | NOT NULL DEFAULT nextval('sourcefile_file_id_seq'::regclass)
 task_fk       | integer                     | NOT NULL
 student_fk    | integer                     | NOT NULL
 code          | text                        | NOT NULL
 send_time     | timestamp without time zone | NOT NULL
 code_language | proglang                    | NOT NULL
 lexem_num     | bigint                      |
 digest_num    | bigint                      |
 Индексы:
 "sourcefile_pkey" PRIMARY KEY, btree (file_id)
 "ak_sourcefile" UNIQUE CONSTRAINT, btree (task_fk, student_fk, code, code_language, send_time)
 Ограничения внешнего ключа:
 "sourcefile_task_fk_fkey" FOREIGN KEY (task_fk) REFERENCES problemversion(problem_ver_id)Кла
 Ссылки извне:
 TABLE "lexem" CONSTRAINT "lexem_from_file_fk_fkey" FOREIGN KEY (from_file_fk) REFERENCES sourcefile(file_id)

 public      | proglang  | c
 public      | proglang  | go
 public      | proglang  | java
 public      | proglang  | unknown
 public      | proglang  | cpp


 */
public class SourceFile {
    public static final String TABLENAME     = "SourceFile";
    public static final String CLASS_TAG     = "SourceFile";

    public static final String FILE_ID       = "file_id";
    public static final String TASK_FK       = "task_fk";
    public static final String STUDENT_FK    = "student_fk";
    public static final String CODE          = "code";
    public static final String CODE_LANGUAGE = "code_language";
    public static final String SEND_TIME     = "send_time";
    public static final String LEXEM_NUM     = "lexem_num";
    public static final String DIGEST_NUM    = "digest_num";
    public static final String PLAGIARIZED   = "plagiarized";
    public static final String TEST_VERDICT  = "tests_verdict";

    public static final String TIME_FORMAT   = "YYYY-MM-DD_HH24:MI:SS";

    int file_id, task, student_id;
    String code, send_time;
//    int lexem_num, digest_num;
    int digest_num;

    public SourceFile(int file, int task, int student_id, String code, String time, int digest_num) {
        this.file_id = file;
        this.task = task;
        this.student_id = student_id;
        this.code = code;
        this.send_time = time;
//        this.lexem_num  = -1;
        this.digest_num = digest_num;
    }


    public String getCode() {
        return code;
    }

    public int getDigestNum() {
        return digest_num;
    }

    // ---------------------------------------------- QUERIES ----------------------------------------------

    public static String FIND_EARLIER_MATCHES_FOR_FILE = String.format(
            "SELECT * FROM LexemSourceFile  WHERE\n" +
                    " %s = ?\n" + //Выбрать решения той же задачи
                    "AND %s != ?\n" + // Не смотреть файлы, написанные тем же человеком
                    "AND %s <= ?\n" + // Искать только среди файлов, отправленных до данного
                    "AND digest IN (\n" +
                    //Искать файлы, в которых содержаться те же хеши
                    " SELECT l." + Lexem.DIGEST +
                    " FROM " + Lexem.TABLENAME + " l WHERE l.%s = ?\n" +
                    ");",
            TASK_FK, STUDENT_FK, SEND_TIME, Lexem.FROM_FILE_FK
    );

    public static String INSERT_QUERY = String.format(
            "INSERT INTO %s (%s, %s, %s, %s, %s, %s) " +
                    "VALUES (?, ?, ?, CAST (? AS PROGLANG), CAST(? AS TIMESTAMP), CAST(? AS VERDICT)) RETURNING " + FILE_ID + ";",
            TABLENAME,
            TASK_FK, STUDENT_FK, CODE, CODE_LANGUAGE, SEND_TIME, TEST_VERDICT
    );

    public static String FIND_BY_LOGIN_TIME_QUERY = String.format(
            "SELECT " + FILE_ID + " FROM SourceFileStudentName " +
                    " WHERE %s = ? AND %s = CAST(? AS TIMESTAMP);",
            Student.LOGIN, SEND_TIME
    );


    // -----------------------------------------------------------------------------------------------------

    public static String addFileToDB(SourceCode file, int problem_id, ConnectionHolder holder) {
        if (findIdByLoginTime(file.stamp().getName(), file.stamp().getTime(), holder) != -1) {
            return null;
        }
        try {
            PreparedStatement insertStmt = holder.getInsertSourceFileStmt();
            Statement statement = holder.getEmptyStatement();
            int student_id = Student.findId(file.stamp().getName(), statement);
            // TASK_FK, STUDENT_FK, CODE, CODE_LANGUAGE, SEND_TIME, LEXEM_NUM, DIGEST_NUM
            insertStmt.setInt   (1, problem_id);
            insertStmt.setInt   (2, student_id);
            insertStmt.setString(3, file.text());
            insertStmt.setObject(4, file.language());
            insertStmt.setString(5, file.stamp().getTime());
            insertStmt.setString(6, file.stamp().getVerdict());
//            insertStmt.setInt   (6, file.tokensList().size());
//            insertStmt.setInt   (7, file.chunksList().size());
            holder.beginTransaction();
            ResultSet result = insertStmt.executeQuery();
            if (result.next()) {
                String file_id = result.getString(FILE_ID); //lexem.from_file_fk
                result.close();


                boolean inserted = Lexem.addLexemArrayToDB(file, file_id, statement);
                holder.endTransaction();
                holder.setSuccess();
                return file_id;
            } else {
                result.close();
                throw new RuntimeException("file is not added");
            }
            // добавлять чанки
        } catch (SQLException ex) {
            holder.addError("Sourcefile.addFileToDB", ex.getMessage(), ex);
            System.out.println(ex.getMessage());
            ex.printStackTrace();
        }
        return null;
    }

    public static int clear(Statement statement) {
        String delete_query = "DELETE FROM " + TABLENAME + ";";
        try {
            return statement.executeUpdate(delete_query);
        } catch (SQLException ex) {
            ex.printStackTrace();
            return 0;
        }
    }


    public static ArrayList<FilePair> filePairsOrderedBySendTime(int task, Statement statement) {
        final String a_name = "to_test_file";
        final String b_name = "base_file";

//        String query = String.format(
//                "SELECT a.%s AS %s, b.%s  AS %s FROM %s a, %s b WHERE a.%s < b.%s;",
//                FILE_ID, a_name, FILE_ID, b_name, TABLENAME, TABLENAME, SEND_TIME, SEND_TIME
//        );
        String query = String.format(
                "SELECT\n" +
                        "f1." + FILE_ID + " AS " + a_name + ", f2." + FILE_ID + " AS " + b_name + "\n" +
                        "FROM " + TABLENAME + " f1 JOIN " + TABLENAME + " AS f2\n" +
                        "ON\n" +
                        "f1." + TASK_FK + " = %d\n" +
                        "AND\n" +
                        "f2." + TASK_FK + " = %d\n" + // Выбираем в пределах одной задачи
                        "AND\n" +
                        "f1." + STUDENT_FK + " != f2." + STUDENT_FK+ "\n" +   // Не смотрим на файлы того же студента
                        "AND\n" +
                        "f1." + SEND_TIME + " > f2." + SEND_TIME + "\n" +     //Смотрим только пары (текущий, добавленный ранее)
                        "WHERE EXISTS(SELECT l1.digest FROM Lexem l1 JOIN Lexem l2\n" +
                        "ON  l1.digest = l2.digest\n" +
                        "AND l1.digest IS NOT NULL\n" +
                        "WHERE l1.from_file_fk = f1.file_id\n" +
                        "AND   l2.from_file_fk = f2.file_id);",
                task, task

        );
        try {
            ArrayList<FilePair> file_pairs = new ArrayList<>();
            ResultSet result = statement.executeQuery(query);
            while (result.next()) {
                int to_test_file_id = result.getInt(a_name);
                int base_file_id    = result.getInt(b_name);
                file_pairs.add(new FilePair(to_test_file_id, base_file_id));
            }
            result.close();
            return file_pairs;

        } catch (SQLException ex) {
            ex.printStackTrace();
        }

        return null;
    }

    public static ArrayList<FilePair> filePairsOrderedBySendTimeNotChecked(int task, ConnectionHolder holder)
    throws SQLException {
        final String a_name = "to_test_file";
        final String b_name = "base_file";

//        String query = String.format(
//                "SELECT a.%s AS %s, b.%s  AS %s FROM %s a, %s b WHERE a.%s < b.%s;",
//                FILE_ID, a_name, FILE_ID, b_name, TABLENAME, TABLENAME, SEND_TIME, SEND_TIME
//        );
        String query = String.format(
                "SELECT\n" +
                        "f1." + FILE_ID + " AS " + a_name + ", f2." + FILE_ID + " AS " + b_name + "\n" +
                        "FROM " + TABLENAME + " f1 JOIN " + TABLENAME + " AS f2\n" +
                        "ON\n" +
                            "f1." + TEST_VERDICT + " = '" + Verdict.PASSED_TESTS.toString() + "'\n" +
                        "AND\n" +
                            "f1." + TASK_FK + " = %d\n" +
                        "AND\n" +
                            "f2." + TASK_FK + " = %d\n" + // Выбираем в пределах одной задачи
                        "AND\n" +
                            "f1." + STUDENT_FK + " != f2." + STUDENT_FK+ "\n" +   // Не смотрим на файлы того же студента
                        "AND\n" +
                            "f1." + SEND_TIME + " > f2." + SEND_TIME + "\n" +     //Смотрим только пары (текущий, добавленный ранее) +
                        "AND\n" +
                            "f1." + FILE_ID + " NOT IN (SELECT " + FilesComparison.FILE_TO_TEST +
                                " FROM " + FilesComparison.TABLENAME + ")\n" +
                        "WHERE EXISTS(SELECT l1.digest FROM Lexem l1 JOIN Lexem l2\n" +
                            "ON  l1.digest = l2.digest\n" +
                            "AND l1.digest IS NOT NULL\n" +
                            "WHERE l1.from_file_fk = f1.file_id\n" +
                            "AND   l2.from_file_fk = f2.file_id);",
                task, task

        );
        try {
            Statement statement = holder.getEmptyStatement();
            ArrayList<FilePair> file_pairs = new ArrayList<>();
            ResultSet result = statement.executeQuery(query);
            while (result.next()) {
                int to_test_file_id = result.getInt(a_name);
                int base_file_id    = result.getInt(b_name);
                file_pairs.add(new FilePair(to_test_file_id, base_file_id));
            }
            result.close();
            return file_pairs;

        } catch (SQLException ex) {
            ex.printStackTrace();
            holder.addError("SourceFile.filePairsOrderedBySendTimeNotChecked",
                    "Exception while execute query", null);
            throw ex;
        }

//        return null;
    }

    public void setPlagiarized(int file_id, boolean isPlag, ConnectionHolder holder) {
        final String FUNCTION_TAG = CLASS_TAG + ".setPlagiarized";
        try {
            String updateQuery = String.format(
                    "UPDATE " + TABLENAME
                            + " SET %s = %s WHERE %s = %d;",
                    PLAGIARIZED, isPlag ? "true" : "false", FILE_ID, file_id);
            int updated = holder.getEmptyStatement().executeUpdate(updateQuery);
            if (updated != 1) {
                holder.addError(FUNCTION_TAG, "Changes was not affected.", null);
            }
        } catch (SQLException ex) {
            holder.addError(FUNCTION_TAG, "Changes was not affected.", ex);
            ex.printStackTrace();
        }
    }


    public ArrayList<Integer> findMatches(int task, int student, int file, String time, ConnectionHolder holder) {
        try {
            PreparedStatement statement = holder.getFindMatchesForFileStmt();
            statement.clearParameters();
            statement.setInt   (1, task);
            statement.setInt   (2, student);
            statement.setString(3, time);
            statement.setInt   (4, file);
            ResultSet resultSet = statement.executeQuery();
            ArrayList<Integer> files = new ArrayList<>();
            while (resultSet.next()) {
                int file_id = resultSet.getInt(SourceFile.FILE_ID);
                files.add(file_id);
            }
            resultSet.close();
            return files;
        } catch (SQLException ex) {
            ex.printStackTrace();
            return null;
        }
    }

    public static SourceFile getFileInfo(int file, ConnectionHolder holder) {
        try {
            final String DIGEST_NUM = "digests_num";
            Statement statement = holder.getEmptyStatement();
            String query = "SELECT *, countDigestArrayLength(" + file + ") AS " + DIGEST_NUM +
                    " FROM " + TABLENAME + " WHERE " + FILE_ID + " = " + file + ";";
            ResultSet resultSet = statement.executeQuery(query);
            if (resultSet.next()) {
                int task = resultSet.getInt(TASK_FK);
                int studentId = resultSet.getInt(STUDENT_FK);
                int digestsnum = resultSet.getInt(DIGEST_NUM);
                String sendTime = resultSet.getString(SEND_TIME);
                String code = resultSet.getString(CODE);
                return new SourceFile(file, task, studentId, code, sendTime, digestsnum);
            }

        } catch (SQLException ex) {
            ex.printStackTrace();
            return null;
        }
        return null;
    }

    public static int findIdByLoginTime(String login, String time, ConnectionHolder holder) {
        try {
            PreparedStatement statement = holder.getFindFileByLoginTime();//MainClass.connectionHolder.getFindFileByLoginTime();
            //Student.LOGIN, SEND_TIME
            statement.setString(1, login);
            statement.setString(2, time);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                int id = resultSet.getInt(FILE_ID);
                resultSet.close();
                return id;
            } else {
                return -1;
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
            return -1;
        }
    }


//    private int    problemNum;
//    private String studentLogin;
//    private String code;
//    private String codeLanguage;
//    private String sendTime;
//
//    public SourceFile(int problemNum, String studentLogin, String code, String codeLanguage, String sendTime) {
//        this.problemNum = problemNum;
//        this.studentLogin = studentLogin;
//        this.code = code;
//        this.codeLanguage = codeLanguage;
//        this.sendTime = sendTime;
//    }
}

