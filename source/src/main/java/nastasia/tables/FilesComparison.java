package nastasia.tables;

/*
 test=# \d filescomparison
 Таблица "public.filescomparison"
 Столбец    |   Тип   | Модификаторы
 --------------+---------+--------------
 file_base    | integer | NOT NULL
 file_to_test | integer | NOT NULL
 match_rating | integer | NOT NULL
 Индексы:
 "pk_filescomparison" PRIMARY KEY, btree (file_base, file_to_test)
 */

import nastasia.connectionholder.ConnectionHolder;
import nastasia.datatypes.FilePair;
import pro.skor.lexems.Coords;
import nastasia.datatypes.ChunkInfo;
import nastasia.datatypes.ChunkList;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;




public class FilesComparison {
    public final static String FILE_BASE    = "file_base";    //int    - integer
    public final static String FILE_TO_TEST = "file_to_test"; //int    - integer
    public final static String MATCH_RATING = "match_rating"; //int    - integer
    public final static String TABLENAME    = "FilesComparison";

    // ----------------------------------------------------------------------------------------

    private ChunkList to_test_file, base_file;

    private FilesComparison(ChunkList to_test_file, ChunkList base_file) {
        this.to_test_file = to_test_file;
        this.base_file    = base_file;
    }

    public FilesComparison optimizeOutput() {
        if (to_test_file.isEmpty()) {
            return this;
        }
        ChunkList list1 = new ChunkList(to_test_file.getFile_id());
        ChunkList list2 = new ChunkList(base_file.getFile_id());
        ChunkInfo chunk1 = to_test_file.get(0);
        ChunkInfo chunk2 = base_file.get(0);
        for (int i = 1; i < base_file.size(); ++i) {
            ChunkInfo next1 = to_test_file.get(i);
            ChunkInfo next2 = base_file.get(i);
            if (ChunkInfo.mayBeUnioned(chunk1, next1)
                    && ChunkInfo.mayBeUnioned(chunk2, next2)) {
                chunk1.append(next1);
                chunk2.append(next2);
            } else {
                list1.add(chunk1);
                list2.add(chunk2);
                chunk1 = next1;
                chunk2 = next2;
            }
        }
        list1.add(chunk1);
        list2.add(chunk2);
        return new FilesComparison(list1, list2);
    }


    public ChunkList getBaseFile() {
        return base_file;
    }

    public ChunkList getToTestFile() {
        return to_test_file;
    }


    // ----------------------------------- Static functions -----------------------------------

    public static  int add2fileIntersectionRate(int base_file, int file_to_test, ConnectionHolder holder)
            throws SQLException {
        Statement statement = holder.getEmptyStatement();
        FilesComparison compares = intersect2FilesChunks(file_to_test, base_file, holder);
//                System.out.println("[FilesComparison.findAllMatches()]: chunks_sizes " + compares.base_file.size() + " " + compares.to_test_file.size());
        String fileSizes = "SELECT countDigestArrayLength(" + SourceFile.FILE_ID + ")" +
                " AS " + SourceFile.LEXEM_NUM +
                " FROM " + SourceFile.TABLENAME +
                " WHERE " + SourceFile.FILE_ID + " = " + file_to_test + ";";
        ResultSet resultSet;
        if (compares.to_test_file.size() == 0) {
            throw new RuntimeException("[FilesComparison.findAllMatches()]: Logical mistake: files was filtered such that they must have common hashes, but the list is empty.");
        }
        // Удалить повторяющиеся участки кода
        compares.normalize();
        resultSet = statement.executeQuery(fileSizes);
        if (resultSet.next()) {
            int srcLen = resultSet.getInt(SourceFile.LEXEM_NUM);
            int matchLen = compares.to_test_file.size();
            int rate = 100 * matchLen / srcLen;
            resultSet.close();
            String insertQuery = String.format(
                    "INSERT INTO " + FilesComparison.TABLENAME +
                            "(%s, %s, %s) VALUES (%d, %d, %d);",
                    FILE_BASE, FILE_TO_TEST, MATCH_RATING,
                    base_file, file_to_test, rate
            );
            statement.executeUpdate(insertQuery);
            return rate;
        }

        return -1;
    }

    public static int findAllUncheckedMatches(int task, ConnectionHolder holder) throws SQLException {
        Statement statement = holder.getEmptyStatement();
        ArrayList<FilePair> file_pairs = SourceFile.filePairsOrderedBySendTimeNotChecked(task, holder);
        System.out.println("[FilesComparison.findAllMatches]: number of pairs: " + file_pairs.size());
        if (file_pairs == null) {
            System.out.println("[FilesComparison.findAllMatches()]: no matches were found.");
            return 0;
        } else {
            for (FilePair pair: file_pairs) {
                int base_file    = pair.getBaseFileId();
                int file_to_test = pair.getTestFileId();
                try {
                    add2fileIntersectionRate(base_file, file_to_test, holder);
                } catch (SQLException ex) {
                    holder.addError("FilesComparison.findAllUncheckedMatches",
                            "Exception while FilesComparison.add2fileIntersectionRate execute.", ex);
                    ex.printStackTrace();
                    throw ex;
//                    return -1;
                }
            }
            return file_pairs.size();
        }
    }

    public static void findAllMatches(int task, ConnectionHolder holder) {
        Statement statement = holder.getEmptyStatement();
        ArrayList<FilePair> file_pairs = SourceFile.filePairsOrderedBySendTime(task, statement);
        System.out.println("[FilesComparison.findAllMatches]: number of pairs: " + file_pairs.size());
        if (file_pairs == null) {
            System.out.println("[FilesComparison.findAllMatches()]: no matches were found.");
            return;
        } else {
            for (FilePair pair: file_pairs) {
                int base_file    = pair.getBaseFileId();
                int file_to_test = pair.getTestFileId();
                FilesComparison compares = intersect2FilesChunks(file_to_test, base_file, holder);
                System.out.println("[FilesComparison.findAllMatches()]: chunks_sizes " + compares.base_file.size() + " " + compares.to_test_file.size());
                String fileSizes = "SELECT countDigestArrayLength(" + SourceFile.FILE_ID + ")" +
                        " AS " + SourceFile.LEXEM_NUM +
                        " FROM " + SourceFile.TABLENAME +
                        " WHERE " + SourceFile.FILE_ID + " = " + file_to_test + ";";
                ResultSet resultSet;
                if (compares.to_test_file.size() == 0) {
                    throw new RuntimeException("[FilesComparison.findAllMatches()]: Logical mistake: files was filtered such that they must have common hashes, but the list is empty.");
                }
                try {
                    resultSet = statement.executeQuery(fileSizes);
                    if (resultSet.next()) {
                        int srcLen = resultSet.getInt(SourceFile.LEXEM_NUM);
                        int matchLen = compares.to_test_file.size();
                        int rate = 100 * matchLen / srcLen;
                        resultSet.close();
                        String insertQuery = String.format(
                                "INSERT INTO " + FilesComparison.TABLENAME +
                                        "(%s, %s, %s) VALUES (%s, %s, %S);",
                                FILE_BASE, FILE_TO_TEST, MATCH_RATING,
                                base_file, file_to_test, rate
                        );
                        statement.executeUpdate(insertQuery);
                    }
                } catch (SQLException ex) {
                    ex.printStackTrace();
                }
            }
        }
    }

    public static FilesComparison intersect2FilesChunks(int test_file, int base_file, ConnectionHolder holder) {
        try {
            Statement statement = holder.getEmptyStatement();
            String query = "SELECT\n" +
                    "d1.array_index  AS \"d1.array_index\",\n" +
                    "d1.start_coord  AS \"d1.start_coord\",\n" +
                    "d1.follow_coord AS \"d1.follow_coord\",\n" +
                    "d1.digest,\n" +
                    "d2.array_index  AS \"d2.array_index\",\n" +
                    "d2.start_coord  AS \"d2.start_coord\",\n" +
                    "d2.follow_coord AS \"d2.follow_coord\"\n" +
                    "FROM Digests d1, Digests d2\n" +
                    "WHERE d1.from_file_fk = " + test_file + " "  +
                    "AND   d2.from_file_fk = " + base_file + "\n" +
                    "AND   d1.digest = d2.digest " +
                    "ORDER BY d1.array_index;";
            ResultSet result = statement.executeQuery(query);
            ChunkList file1 = new ChunkList(test_file);
            ChunkList file2 = new ChunkList(base_file);
            while (result.next()) {
                String digest = result.getString("digest");
                int index_1 = result.getInt("d1.array_index");
                int index_2 = result.getInt("d2.array_index");
                Coords start_1 = Lexem.parseCoord(result.getString("d1.start_coord"));
                Coords start_2 = Lexem.parseCoord(result.getString("d2.start_coord"));

                Coords follow_1 = Lexem.parseCoord(result.getString("d1.follow_coord"));
                Coords follow_2 = Lexem.parseCoord(result.getString("d2.follow_coord"));

                ChunkInfo chunk_1 = new ChunkInfo(digest, index_1, start_1, follow_1);
                ChunkInfo chunk_2 = new ChunkInfo(digest, index_2, start_2, follow_2);

                file1.add(chunk_1);
                file2.add(chunk_2);
            }
            FilesComparison files = new FilesComparison(file1, file2);
            return files;
        } catch (SQLException exception) {
            exception.printStackTrace();
            return null;
        }
    }

    // Если один и тот же чанк встречается в base-файле несколько раз, мы не должны его дублировать в to_test-файле
    private void normalize() {
        for (int i = 1; i < to_test_file.size();) {
            if (to_test_file.get(i-1).equals(to_test_file.get(i))) {
                to_test_file.remove(i);
                base_file.remove(i);
            } else {
                ++i;
            }
        }
    }
}
