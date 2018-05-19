package nastasia.tables;

/**
 test=# \d test
 Таблица "public.test"
 Столбец   |   Тип   |                      Модификаторы
 -------------+---------+--------------------------------------------------------
 test_id     | integer | NOT NULL DEFAULT nextval('test_test_id_seq'::regclass)
 problem_fk  | integer | NOT NULL
 test_number | integer | NOT NULL
 content     | text    | NOT NULL
 answer      | text    | NOT NULL
 Индексы:
 "test_pkey" PRIMARY KEY, btree (test_id)
 "ak_test" UNIQUE CONSTRAINT, btree (problem_fk, test_number)
 Ограничения внешнего ключа:
 "test_problem_fk_fkey" FOREIGN KEY (problem_fk) REFERENCES problemversion(problem_ver_id)

 */
public class Test {
    final String test_id     = "test_id";
    final String problem_fk  = "problem_fk";
    final String test_number = "test_number";
    final String content     = "content";
    final String answer      = "answer";
}

