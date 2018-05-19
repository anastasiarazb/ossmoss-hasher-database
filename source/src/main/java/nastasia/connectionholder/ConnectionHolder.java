package nastasia.connectionholder;

import nastasia.tables.SourceFile;

import java.sql.*;
import java.util.Properties;

public class ConnectionHolder {

    private PreparedStatement findMatchesForFile;
    private PreparedStatement insertSourceFile;
    private PreparedStatement findFileByLoginTime;// FIND_BY_LOGIN_TIME_QUERY
    private Statement         emptyStatement;
    private Connection        connection;
    private Exception         lastException;

    private boolean       success = true;
    private StringBuilder message = new StringBuilder();
    private Object        result = null;

    public ConnectionHolder(String url, String db_user, String pass) throws SQLException {
        Properties props = new Properties();
        props.setProperty("user", db_user);
        if (pass != null) {
            props.setProperty("password", pass);
        }
     /*1*/   this.connection = DriverManager.getConnection(url, props);
     /*2*/   this.emptyStatement     = connection.createStatement();
     /*3*/   this.findMatchesForFile = connection.prepareStatement(SourceFile.FIND_EARLIER_MATCHES_FOR_FILE);
     /*4*/   this.insertSourceFile   = connection.prepareStatement(SourceFile.INSERT_QUERY);
     /*5*/   this.findFileByLoginTime = connection.prepareStatement(SourceFile.FIND_BY_LOGIN_TIME_QUERY);
    }

    public void destroy() throws SQLException {
        if (findFileByLoginTime != null) { /*5*/
            findFileByLoginTime.close();
        }
        if (insertSourceFile   != null) { /*4*/
            insertSourceFile.close();
        }
        if (findMatchesForFile != null) { /*3*/
            findMatchesForFile.close();
        }
        if (emptyStatement     != null) { /*2*/
            emptyStatement.close();
        }
        if (connection != null) {        /*1*/
            connection.close();
        }
    }

// ************************************** Getters **************************************

    public Connection getConnection() { /*1*/
        return connection;
    }

    public Statement getEmptyStatement() { /*2*/
        return emptyStatement;
    }

    public PreparedStatement getFindMatchesForFileStmt() throws SQLException { /*3*/
        findMatchesForFile.clearParameters();
        return findMatchesForFile;
    }

    public PreparedStatement getInsertSourceFileStmt() throws SQLException { /*4*/
        insertSourceFile.clearParameters();
        return insertSourceFile;
    }

    public PreparedStatement getFindFileByLoginTime() throws SQLException { /*5*/
        findFileByLoginTime.clearParameters();
        return findFileByLoginTime;
    }

// ************************************** Transactions **************************************

    public void beginTransaction() throws SQLException {
        connection.setAutoCommit(false);
    }

    public void endTransaction() throws SQLException {
        connection.commit();
        connection.setAutoCommit(true);
    }

// ************************************** Results sharing **************************************

    public static final String NO_NAME_FUNCTION = "...";

    public boolean isSuccess() {
        return success;
    }

    public Exception getLastException() {
        return lastException;
    }

    public void addError(String functionTag, String message, Exception exception) {
        this.success = false;
        this.message.append("[").append(functionTag).append("]: ").append(message).append("\r\n\r\n");
        lastException = exception;
    }

    public void setSuccess() {
        lastException = null;
    }

    public void setResult(Object result) {
        this.result = result;
    }

    public void setSuccess(String functionTag, String message) {
        success = true;
        this.message.append("[").append(functionTag).append("]: ").append(message).append("\r\n\r\n");
        lastException = null;
    }

    public String getMessage() {
        return message.toString();
    }

    public Object getResult() {
        return result;
    }

    public void reset() {
        success = true;
        message.setLength(0);
        lastException = null;
        result = null;
    }
}