package nastasia.mainclass;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import nastasia.gui.MessageBox;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Properties implements Serializable {
    public String saved_db_url  = "";
    public String saved_db_user = "";

//    final static String FILE = "src/main/java/nastasia/mainclass/properties.json";

    public void save() {
        Gson g = new GsonBuilder().setPrettyPrinting().create();
        BufferedWriter output = null;
        String json = g.toJson(this);
        try {
            File file = new File(MainClass.PREFERENCES_FILE);
            output = new BufferedWriter(new FileWriter(file));
            output.write(json);
        } catch ( IOException e ) {
            System.out.println("Can't save preferences to " + MainClass.PREFERENCES_FILE + ".");
            e.printStackTrace();
        } finally {
            if ( output != null ) {
                try{
                    output.close();
                } catch (IOException ex){
                    ex.printStackTrace();
                }
            }
        }
    }

    public static Properties extract() {
        Gson g = new Gson();
        if (MainClass.ARGS.length < 2) {
            new MessageBox(MainClass.Message.USAGE);
            System.out.println(MainClass.Message.USAGE);
        }
        if (MainClass.ARGS[0].equals("-f")) {
            if (MainClass.ARGS.length > 2) {
                new MessageBox(MainClass.Message.USAGE);
                System.out.println(MainClass.Message.USAGE);
            }
            String source_file = MainClass.ARGS[1];
            try {
                byte[] encoded = Files.readAllBytes(Paths.get(source_file));
                String content = new String(encoded);
                Properties prop = g.fromJson(content, Properties.class);
                if (prop == null) {
                    return new Properties("", "");
                }
                return g.fromJson(content, Properties.class);
            } catch (IOException ex) {
                String message = "Can't read JSON file '" + source_file + "'.";
                new MessageBox(message);
                System.out.println(message);
                ex.printStackTrace();
            }
        } else if (MainClass.ARGS.length != 4
                || !(MainClass.ARGS[0].equals("-u") &&  MainClass.ARGS[2].equals("-d")
                     ||  MainClass.ARGS[2].equals("-u") &&  MainClass.ARGS[0].equals("-d"))) {
            new MessageBox(MainClass.Message.USAGE);
            System.out.println(MainClass.Message.USAGE);
        } else {
            if (MainClass.ARGS[0].equals("-u")) {
                return new Properties(MainClass.ARGS[3], MainClass.ARGS[1]);
            } else {
                return new Properties(MainClass.ARGS[1], MainClass.ARGS[3]);
            }
        }
        return new Properties("", "");
    }

    public Properties(String url, String user) {
        this.saved_db_url  = url;
        this.saved_db_user = user;
    }
}