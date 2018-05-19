package nastasia.tables;

/**
 test=# \d problem
 Таблица "public.problem"
 Столбец   |   Тип   | Модификаторы
 ------------+---------+--------------
 problem_id | integer | NOT NULL
 content    | text    |
 points     | integer |
 Индексы:
 "problem_pkey" PRIMARY KEY, btree (problem_id)
 Ссылки извне:
 TABLE "problemversion" CONSTRAINT "problemversion_problem_fk_fkey" FOREIGN KEY (problem_fk) REFERENCES problem(problem_id)

 */
public class Problem {
    final String problem_id = "problem_id"; //integer
    final String content    = "content";    //text
    final String points     = "points";     //integer

}