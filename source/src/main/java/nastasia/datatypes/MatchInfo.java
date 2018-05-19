package nastasia.datatypes;

public class MatchInfo {
    final private int    id1;
    final private int    id2;
    final private String login1;
    final private String login2;
    final private String sendTime1;
    final private String sendTime2;
    final private String matchRating;

    public MatchInfo (int id1, int id2, String login1, String login2, String sendTime1, String sendTime2, String matchRating) {
        this.id1 = id1;
        this.id2 = id2;
        this.login1 = login1;
        this.login2 = login2;
        this.sendTime1 = sendTime1;
        this.sendTime2 = sendTime2;
        this.matchRating = matchRating;
    }

    private MatchInfo (String message) {
        id1 = -1;
        id2 = -1;
        this.login1 = message;
        this.login2 = null;
        this.sendTime1 = null;
        this.sendTime2 = null;
        this.matchRating = null;
    }

    private MatchInfo() {
        id1 = -1;
        id2 = -1;
        this.login1 = "";
        this.login2 = null;
        this.sendTime1 = null;
        this.sendTime2 = null;
        this.matchRating = null;
    }

    @Override
    public String toString() {
        if (login2 == null) return login1;
        return new StringBuilder().append("(").append(login1).append(")(").append(sendTime1).append(")  ")
                .append(matchRating)
                .append("%   FROM   (").append(login2).append(")(").append(sendTime2).append(")")
                .toString();
    }

    public static MatchInfo defalut() {
        return new MatchInfo(-1, -1, "login_test", "login_base",
                "send_time_test", "send_time_base", "match_rate");
    }

    public static MatchInfo errorMessage(String message) {
        return new MatchInfo(message);
    }

    public static MatchInfo empty() {
        return new MatchInfo();
    }

    public String getLogin1() {
        return login1;
    }

    public String getLogin2() {
        return login2;
    }

    public String getSendTime1() {
        return sendTime1;
    }

    public String getSendTime2() {
        return sendTime2;
    }

    public String getMatchRating() {
        return matchRating;
    }

    public int getId1() {
        return id1;
    }

    public int getId2() {
        return id2;
    }
}