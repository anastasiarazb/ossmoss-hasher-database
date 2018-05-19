package nastasia.tables;

import java.math.BigInteger;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.List;
/*
          Таблица "public.lexem"
          Таблица "public.lexem"
   Столбец    |    Тип     | Модификаторы
--------------+------------+--------------
 from_file_fk | integer    | NOT NULL
 digest       | bigint     | NOT NULL
 lexem_type   | lexem_type |
 start_idx    | bigint     | NOT NULL
 follow_idx   | bigint     |
 pos          | coord      |
Индексы:
    "pk_lexem" PRIMARY KEY, btree (from_file_fk, start_idx)
Ограничения внешнего ключа:
    "lexem_from_file_fk_fkey" FOREIGN KEY (from_file_fk) REFERENCES sourcefile(file_id)



create type coord as (line int, col int);

 */


/*
keyword, special, ident, skippable, literal, pragma
 */

import pro.skor.lexems.Coords;
import pro.skor.lexems.Token;
import pro.skor.lexems.collective.Ident;
import pro.skor.lexems.collective.Literal;
import pro.skor.lexems.collective.Skippable;
import pro.skor.lexems.collective.Special;
import pro.skor.lexems.standard.Keyword;
import pro.skor.lexems.standard.Pragma;
import pro.skor.ossmoss.Chunk;
import pro.skor.ossmoss.SourceCode;


public class Lexem {

    /*
           Таблица "public.lexem"
   Столбец    |      Тип      | Модификаторы
--------------+---------------+--------------
 from_file_fk | integer       | NOT NULL
 array_index  | integer       | NOT NULL
 digest       | numeric(39,0) | NOT NULL
 lexem_type   | lexem_type    |
 start_coord  | coord         | NOT NULL
 follow_coord | coord         | NOT NULL
Индексы:
    "pk_lexem" PRIMARY KEY, btree (from_file_fk, array_index)
Ограничения внешнего ключа:
    "lexem_from_file_fk_fkey" FOREIGN KEY (from_file_fk) REFERENCES sourcefile(file_id) ON DELETE CASCADE


type coord (pos bigint, line int, col int);

    */

    public static final String TABLENAME = "Lexem";

    public static final String FROM_FILE_FK = "from_file_fk"; //integer
    public static final String ARRAY_INDEX  = "array_index";  //integer
    public static final String DIGEST       = "digest";       //numeric(39,0)
    public static final String LEXEM_TYPE   = "lexem_type";   //lexem_type (см. Types)
    public static final String START_COORD  = "start_coord";  //coord (pos, line, col)
    public static final String FOLLOW_COORD = "follow_coord"; //coord (pos, line, col)

    public static class Types {
        public static final String TYPE_NAME = "lexem_type";

        public static final String KEYWORD   = "'keyword'";
        public static final String SPECIAL   = "'special'";
        public static final String IDENT     = "'ident'";
        public static final String SKIPPABLE = "'skippable'";
        public static final String LITERAL   = "'literal'";
        public static final String PRAGMA    = "'pragma'";
        public static final String OTHER     = "'other'";
    }

    //Ближайшие потомки Lexem в иерархии классов
    public static String typeOf(pro.skor.lexems.Lexem lexem) {
        if (lexem instanceof Keyword) return Types.KEYWORD;
        if (lexem instanceof Special) return Types.SPECIAL;
        if (lexem instanceof Ident)   return Types.IDENT;
        if (lexem instanceof Skippable) return Types.SKIPPABLE;
        if (lexem instanceof Literal) return Types.LITERAL;
        if (lexem instanceof Pragma) return Types.PRAGMA;
        return Types.OTHER;
    }

    public static boolean addLexemArrayToDB(SourceCode file, String file_id, Statement statement) throws SQLException {
        boolean result = false;
        List<Chunk> chunks = file.chunksList();
        List<Token> tokens = file.tokensList();
        //Алгоритм работает в предположении, что чанки идут последовательно
        //Тогда чанк записывается лексему, с которой он начинается
        //Лексемы в конце файла, с которых "не начинается" ни один чанк, имеют пустое поле digest
        int i;
        for (i = 0; i < chunks.size(); ++i) {
            Token tok = tokens.get(i);
            BigInteger chunk = chunks.get(i).digest(); //lexem.digest
//            System.out.println(String.format("file %s, %d tokens, %d chunks, i=%d", file_id, tokens.size(), chunks.size(), i));
            result |= addLexemToDB(tok, i, chunk, file_id, statement);
        }
        //Токены без чанка
        for (; i < tokens.size(); ++i) {
            Token tok = tokens.get(i);
            result |= addLexemToDB(tok, i, null, file_id, statement);
        }
// Возможно эта проверка не нужна тут.
//        result &= check(file_id, statement);
        return result;
    }
// https://msdn.microsoft.com/ru-ru/library/ms187746(v=sql.120).aspx
    //Добавление лексемы вместе с чанком
    public static boolean addLexemToDB(pro.skor.lexems.Token token, int index, BigInteger digest,
                                       String file_id, Statement statement) throws SQLException {

        String start  = Lexem.coordsToRow(token.start());
        String follow = Lexem.coordsToRow(token.follow());
        String lexem_type = typeOf(token.lexem());
        String insert_query;
        if (digest == null) {
            insert_query = String.format("INSERT INTO %s(%s, %s, %s, %s, %s) VALUES (%s, %d, %s, %s, %s);",
                    TABLENAME,
                    FROM_FILE_FK, ARRAY_INDEX, LEXEM_TYPE, START_COORD, FOLLOW_COORD,
                    file_id,      index,       lexem_type, start,        follow
            );
        } else {
            insert_query = String.format(
                    "INSERT INTO %s(%s, %s, %s, %s, %s, %s) VALUES (%s, %d, %s, %s, %s, %s);",
                    TABLENAME,
                    FROM_FILE_FK, ARRAY_INDEX, DIGEST, LEXEM_TYPE, START_COORD, FOLLOW_COORD,
                    file_id,      index,  digest.toString(), lexem_type, start, follow
            );
        }
//        System.out.println("[addLexemToDB]: " + insert_query);
        int inserted = statement.executeUpdate(insert_query);
        return inserted == 1;
    }

    public static String coordsToRow(Coords coords) {
        return String.format("ROW(%d, %d, %d, %d)", coords.getPos(), coords.getLine(), coords.getCol(), coords.getTabCount());
    }

    public static Coords parseCoord(String coordsAsString) throws RuntimeException {
        String[] elements = coordsAsString.substring(1, coordsAsString.length()-1).split("[ ,]+");
        if (elements.length != 4) {
            throw new RuntimeException("[" + Lexem.class.getName() + "]: expected 4 coordinates, " + elements.length + " found.\n");
        }
        int pos  = Integer.parseInt(elements[0]);
        int line = Integer.parseInt(elements[1]);
        int col  = Integer.parseInt(elements[2]);
        int tabs = Integer.parseInt(elements[3]);
        Coords res = new Coords(line, col, tabs, pos);
        return res;
    }


    public static boolean check(String file_id, Statement statement) throws SQLException {
        String get_arrays_lens_query = String.format("SELECT %s, %s FROM %s WHERE %s = %s;",
                SourceFile.LEXEM_NUM, SourceFile.DIGEST_NUM, SourceFile.TABLENAME, SourceFile.FILE_ID, file_id);
        ResultSet result = statement.executeQuery(get_arrays_lens_query);
        boolean is_array_full = false;
        if (result.next()) {
            int lexem_num = result.getInt(SourceFile.LEXEM_NUM);
            int digest_num = result.getInt(SourceFile.DIGEST_NUM);
            String added_lexems = String.format(
                    "SELECT COUNT(*) AS lexems_count, COUNT(digest) AS digest_count FROM %s WHERE %s = %s;",
                    Lexem.TABLENAME, Lexem.FROM_FILE_FK, file_id
            );
            result.close();
            result = statement.executeQuery(added_lexems);
            if (result.next()) {
                int added_lexems_num = result.getInt("lexems_count");
                int added_digest_num = result.getInt("digest_count");
                is_array_full = (lexem_num == added_lexems_num) & (digest_num == added_digest_num);
                if (!is_array_full) {
                    result.close();
                    throw new RuntimeException(lexem_num + " lexems expected, " + added_lexems_num + " found. " +
                    digest_num  + " digests expected, " + added_digest_num + " found. ");
                }
            }
            result.close();
        } else {
            throw new RuntimeException("Cannot get lexem array length from source file with id: " + file_id + ";");
        }
        return is_array_full;
    }

    public static ResultSet getSharedChunks(int base_file_id, int to_test_file_id, Statement statement) {
        String find_query = String.format(
                "SELECT a.*, b.* FROM %s a JOIN %s b ON a.%s = b.%s WHERE a.%s IS NOT NULL AND a.%s = %d AND b.%s = %d;",
                TABLENAME, TABLENAME, DIGEST, DIGEST, DIGEST, FROM_FILE_FK, base_file_id, FROM_FILE_FK, to_test_file_id
        );

        try {
            ResultSet result = statement.executeQuery(find_query);
            return result;
        } catch (SQLException ex) {
            ex.printStackTrace();
            return null;
        }
    }

    public static Coords findChunkFollow(int file_fk, int start_index, int chunkSize, Statement statement) {
        int follow_index = start_index + chunkSize - 1;
        String positions = String.format(
                "(%s).pos, \n" +
                "(%s).line,\n" +
                "(%s).col, \n" +
                "(%s).tab \n",
                FOLLOW_COORD, FOLLOW_COORD, FOLLOW_COORD, FOLLOW_COORD
        );
        String query = String.format(
                "SELECT " + positions + " FROM " + TABLENAME +
                        " WHERE %s = %d AND %s = %d",
               FROM_FILE_FK, file_fk, ARRAY_INDEX, follow_index
        );
        try {
            ResultSet    result = statement.executeQuery(query);
            Coords follow_coord = null;
            if (result.next()) {
                follow_coord = new Coords(
                        result.getInt("line"),
                        result.getInt("col"),
                        result.getInt("tab"),
                        result.getInt("pos")
                );
            }
            result.close();
            return follow_coord;
        } catch (SQLException ex) {
            ex.printStackTrace();
            return null;
        }
    }

}
