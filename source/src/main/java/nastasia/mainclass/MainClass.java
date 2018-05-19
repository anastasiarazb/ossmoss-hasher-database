package nastasia.mainclass; /**
 * Created by nastasia on 27.02.17.
 */


import nastasia.connectionholder.ConnectionHolder;
import nastasia.gui.MainForm;
import nastasia.gui.MatchIterator;
import nastasia.gui.MessageBox;
import nastasia.gui.PasswordEnter;
import org.apache.commons.lang.StringEscapeUtils;
import pro.skor.ossmoss.SourceCode;
import nastasia.tables.FilesComparison;
import nastasia.tables.SourceFile;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;

/*

sudo systemctl start postgresql-9.5
psql test testUser

"/home/nastasia/6sem/DB_courseProject/hasher_db/data/011 Подсчёт слов в строке/"

        // dolgikh 2013-02-18_21:34:47
        // shubin  2013-09-30_21:23:19

        2 куска совпадений:
        anokhina 2012-10-28 17:23:06
        mansurova 2011-09-23 00:10:38
 */

public class MainClass {

    static class Message {
        public static final String NO_URL_USERNAME =
                "The database url and user are not correct. Please, try again.";
        public static final String NO_CONSOLE =
                "Please, open app in a console";
        static final String DRIVER_NOT_LOADED = "PostgreSQL Driver is not loaded.\n"+
                "1) Include PostgreSQL JDBC Driver to the library path.\n" +
                "2) Add \"-Djdbc.drivers=org.postgresql.Driver\" to the VM options.";
        public static final String USAGE =
                "Usage:\n   -f <path to properties.json>\nor\n  -d <database url> -u <user>\n";
    }

//    public static ConnectionHolder connectionHolder;

//    static void addFiles(ArrayList<SourceCode> sources, ConnectionHolder holder) {
//        int cleared = SourceFile.clear(holder.getEmptyStatement());
//        System.out.println("[nastasia.mainclass.MainClass.addFiles()]: " + cleared + " files deleted.");
//        for (SourceCode file: sources) {
//            SourceFile.addFileToDB(file, 9, holder);
//        }
//    }

    static void printJSON(ArrayList<SourceCode> sources) {
        System.out.println("[");
        for (SourceCode src : sources) {
            System.out.println("\t{");
            System.out.printf("\t\t\"Stamp\": %s,\n", src.stamp().toJSON());
            System.out.printf("\t\t\"Text\": \"%s\",\n", StringEscapeUtils.escapeJavaScript(src.text()));
            System.out.println("\t\t\"Tokens\": [");
            src.tokenStream().forEach(tok -> {
                System.out.printf("\t\t\t%s,\n", tok.toJSON());
//                int st = tok.start().getPos(); //для проверки адекватности индексов, хранящихся в coord
//                int fol = tok.follow().getPos();
//                String image = src.text().substring(st, fol);
//                System.out.println("image = " + image);

            });
            System.out.println("\t\t],");
            System.out.println("\t\t\"Chunks\": [");
            src.chunkStream().forEach(chunk -> System.out.printf("\t\t\t%s,\n", chunk.toJSON()));
            System.out.println("\t\t]");
            System.out.println("\t},");
        }
        System.out.println("]");
    }

    static void comparefiles(int id1, int id2, ConnectionHolder connectionHolder) {
        FilesComparison x = FilesComparison.intersect2FilesChunks(10664, 11047, connectionHolder).optimizeOutput();
        SourceFile file1 = SourceFile.getFileInfo(x.getToTestFile().getFile_id(), connectionHolder);
        SourceFile file2 = SourceFile.getFileInfo(x.getBaseFile().getFile_id(), connectionHolder);

        String code1 = file1.getCode();
        String code2 = file2.getCode();

        MatchIterator matchIterator = new MatchIterator(code1, code2, x.getToTestFile(), x.getBaseFile());

        System.out.println(matchIterator.getText1());
        System.out.println(matchIterator.getText2());

        int lol = SourceFile.findIdByLoginTime("dolgikh", "2013-02-18_21:34:47", connectionHolder);
    }

    static void showSourceFileList(Statement statement) throws SQLException {
        ResultSet result = statement.executeQuery("SELECT * FROM Sourcefile;");

        while (result.next()) {
            System.out.println("№ в выборке #" + result.getRow() + " " + result.getString(SourceFile.CODE)
                    + " " + result.getInt(SourceFile.STUDENT_FK));
        }

        result.close();
    }

    public static void innerMain(ConnectionHolder connectionHolder) {
        if (connectionHolder.getConnection() != null) {
            System.out.println("Connection success.");
        } else {
            System.out.println("Failed to make connection!");
        }

        // ------------------------------------------------------------------

        MainForm form = new MainForm(connectionHolder);
        JFrame frame = new JFrame("Hasher Database");
        frame.setContentPane(form.getPanel1());
//        frame.setSize(300, 200);
        frame.setLocationRelativeTo(null);
        frame.pack();
        frame.setVisible(true);

        frame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent event) {
                frame.dispose();
                try {
                    connectionHolder.destroy();
                    System.out.println("All resources are cleared.");
                } catch (SQLException ex) {
                    ex.printStackTrace();
                }
                System.exit(0);
            }
        });

    }

    public static String[] ARGS = null;
    public static final String PREFERENCES_FILE = "saved_properties.json";

    public static void main(String[] args) throws SQLException {

        if (args.length == 0) {
            ARGS = new String[] {"-f", PREFERENCES_FILE};
            File f = new File(PREFERENCES_FILE);
            if (!f.exists()) {
                try {
//                    f.getParentFile().mkdirs();
                    f.createNewFile();
                } catch (IOException e) {
                    new MessageBox(e.getMessage());
                    e.printStackTrace();
                }
            }
        } else {
            ARGS = args;
        }

        try {
            Class.forName("org.postgresql.Driver");
        } catch (Exception ex) {
            if (System.console() == null) {
                new MessageBox(Message.DRIVER_NOT_LOADED);
            }
            System.out.println("PostgreSQL Driver is not loaded.\n"+
                    "1) Include PostgreSQL JDBC Driver to the library path.\n" +
                    "2) Add \"-Djdbc.drivers=org.postgresql.Driver\" to the VM options.");
            System.out.println(ex.getMessage());
            return;
        }
        System.out.println("PostgreSQL JDBC Driver registered.");
        new PasswordEnter();

//        String db_name = "test";
//        String url     = "jdbc:postgresql://localhost/" + db_name;
//        String db_user = "testUser";
//        ConnectionHolder connectionHolder;


    }
}
/*
* Tables:
* test=# \dt
               Список отношений
 Схема  |       Имя       |   Тип   | Владелец
--------+-----------------+---------+----------
 public | filescomparison | таблица | testUser
 public | lexem           | таблица | testUser
 public | problem         | таблица | testUser
 public | problemversion  | таблица | testUser
 public | sourcefile      | таблица | testUser
 public | student         | таблица | testUser
 public | test            | таблица | testUser

* */

// https://habrahabr.ru/sandbox/41444/

/*

try (Connection connection = dataSource.getConnection();
    Statement statement = connection.createStatement()) {
    try (ResultSet resultSet = statement.executeQuery("some query")) {
        // Do stuff with the result set.
    }
    try (ResultSet resultSet = statement.executeQuery("some query")) {
        // Do more stuff with the second result set.
    }
}

*/