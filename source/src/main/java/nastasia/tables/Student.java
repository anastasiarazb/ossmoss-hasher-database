package nastasia.tables;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/**
 test=# \d student
 Таблица "public.student"
 Столбец    |          Тип          |                         Модификаторы
 --------------+-----------------------+--------------------------------------------------------------
 student_id   | integer               | NOT NULL DEFAULT nextval('student_student_id_seq'::regclass)
 login        | character varying(20) |
 surname      | character varying(50) |
 student_name | character varying(50) |
 patronymic   | character varying(50) |
 department   | character varying(5)  |
 group_num    | integer               |
 Индексы:
 "student_pkey" PRIMARY KEY, btree (STUDENT_ID)
 "student_login_key" UNIQUE CONSTRAINT, btree (LOGIN)

 */
public class Student {
    public final static String STUDENT_ID   = "student_id";   //int    - integer
    public final static String LOGIN        = "login";        //String - character varying(20)
    public final static String SURNAME      = "surname";      //String - character varying(50)
    public final static String STUDENT_NAME = "student_name"; //String - character varying(50)
    public final static String PATRONIMIC   = "patronimic";   //String - character varying(50)
    public final static String DEPARTMENT   = "department";   //String - character varying(5)
    public final static String GROUP_NUM    = "group_num";    //int    - integer

    public final static String TABLENAME = "Student";

    public static String findIdQuery(String student_login) {
        return "SELECT " + STUDENT_ID + " FROM Student WHERE " + LOGIN + "=" + student_login + ";";
    }

    public static int findId(String student_login, Statement statement) throws SQLException {
        int id;
        String quoted_login = "'" + student_login + "'"; //Нигде далее имя без кавычек смысла не имеет
        try {
            String select_query = "SELECT " + STUDENT_ID + " FROM Student WHERE " + LOGIN + "=" + quoted_login + ";";
            ResultSet result = statement.executeQuery(select_query);
            if (result.next()) {
                id = result.getInt(STUDENT_ID);
                result.close();
                return id;
            } else {
                System.out.println("[Student.findId()]: Login " + quoted_login + " is not found. New entry created.");
                //тут диалог с пользователем
                String insert_query = "INSERT INTO Student(" + LOGIN + ")" + " VALUES (" + quoted_login + ");";
                int inserted = statement.executeUpdate(insert_query);
                if (inserted == 0) {
                    throw new RuntimeException("Could not add new student " + quoted_login + ".\n");
                }
                return findId(student_login, statement);
            }
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
            return -1;
        }
    }
}
