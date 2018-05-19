package nastasia.tables;

import nastasia.connectionholder.ConnectionHolder;

import java.sql.ResultSet;
import java.sql.SQLException;

/**

 test=# \d problemversion
 Таблица "public.problemversion"
 Столбец     |             Тип             |                              Модификаторы
 ----------------+-----------------------------+-------------------------------------------------------------------------
 problem_ver_id | integer                     | NOT NULL DEFAULT nextval('problemversion_problem_ver_id_seq'::regclass)
 problem_fk     | integer                     | NOT NULL
 ver            | integer                     | NOT NULL
 creation_time  | timestamp without time zone | NOT NULL DEFAULT ('now'::text)::timestamp without time zone
 Индексы:
 "problemversion_pkey" PRIMARY KEY, btree (problem_ver_id)
 "ak_problemversion" UNIQUE CONSTRAINT, btree (problem_fk, ver)
 Ограничения внешнего ключа:
 "problemversion_problem_fk_fkey" FOREIGN KEY (problem_fk) REFERENCES problem(problem_id)
 Ссылки извне:
 TABLE "sourcefile" CONSTRAINT "sourcefile_task_fk_fkey" FOREIGN KEY (task_fk) REFERENCES problemversion(problem_ver_id)
 TABLE "test" CONSTRAINT "test_problem_fk_fkey" FOREIGN KEY (problem_fk) REFERENCES problemversion(problem_ver_id)

 */
public class ProblemVersion {

    final static String TABLENAME = "ProblemVersion";

    final static String PROBLEM_VER_ID = "problem_ver_id";
    final static String PROBLEM_FK     = "problem_fk";
    final static String VER            = "ver";
    final static String CREATION_TIME  = "creation_time";

    public static int findId(int problem_num, int version, ConnectionHolder holder) {
        int id;
        try {
            String select_query = String.format("SELECT %s FROM %s WHERE %s = %d AND %s = %d;",
                    PROBLEM_VER_ID, TABLENAME, PROBLEM_FK, problem_num, VER, version);
            ResultSet result = holder.getEmptyStatement().executeQuery(select_query);
            if (result.next()) {
                id = result.getInt(PROBLEM_VER_ID);
                result.close();
                return id;
            } else {

                holder.addError("ProblemVersion.findId",
                        "Add " + problem_num + " version " + version + ".", null);
                return -1;

//                throw new RuntimeException("[ProblemVersion.findId()]: Problem " + problem_num + " version " + version + " is not found.");
            }
        } catch (SQLException ex) {
            System.out.println("[ProblemVersion.findId()]: EXCEPTION. Problem " + problem_num + " version " + version + " is not found.");
            System.out.println(ex.getMessage());
        }
        return -1;
    }
}

