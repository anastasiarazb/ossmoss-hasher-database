package nastasia.gui;

import nastasia.datatypes.ChunkInfo;

public class FilesFormatter {

    public static String GREEN  = "102";
    public static String YELLOW = "103";

    public static String GREEN_HTML  = "#00FF00";
    public static String YELLOW_HTML = "#FFFF00";

    public static String setStringColor(String src, String color) {
        return "\033[" + color + "m" + src + "\033[0m";
    }

    public static String highlightText(String src, ChunkInfo bound, String color) {
        int color_escape_length = 16;
        int highlightStart  = bound.getStartPos();
        int highlightFollow = bound.getFollowPos();
        StringBuilder result = new StringBuilder(src.length() + color_escape_length )
                .append(src.substring(0, highlightStart))
                .append(
                        setStringColor(src.substring(highlightStart, highlightFollow), color)
                )
                .append(src.substring(highlightFollow));
        return result.toString();
    }

    public static String escape(String s) {
        StringBuilder builder = new StringBuilder();
        boolean previousWasASpace = false;
        for( char c : s.toCharArray() ) {
            if( c == ' ' ) {
                if( previousWasASpace ) {
                    builder.append("&nbsp;");
                    previousWasASpace = false;
                    continue;
                }
                previousWasASpace = true;
            } else {
                previousWasASpace = false;
            }
            switch(c) {
                case '<': builder.append("&lt;"); break;
                case '>': builder.append("&gt;"); break;
                case '&': builder.append("&amp;"); break;
                case '"': builder.append("&quot;"); break;
                case '\n': builder.append("<br>"); break;
                // We need Tab support here, because we print StackTraces as HTML
                case '\t': builder.append("&nbsp; &nbsp; &nbsp;"); break;
                default:
                    if( c < 128 ) {
                        builder.append(c);
                    } else {
                        builder.append("&#").append((int)c).append(";");
                    }
            }
        }
        return builder.toString();
    }

    public static String htmlHighlight(String src, ChunkInfo bound, String color) {
        int sumTagsLen = 70;
        StringBuilder result = new StringBuilder(src.length() + sumTagsLen);
        int highlightStart  = bound.getStartPos();
        int highlightFollow = bound.getFollowPos();
        result.append("<html><body>")
                .append(escape(src.substring(0, highlightStart)))
                .append("<span style=\"background-color: ")
                .append(color)
                .append("\">")
                .append(escape(src.substring(highlightStart, highlightFollow)))
                .append("</span>")
                .append(escape(src.substring(highlightFollow)))
                .append("</html></body>");
//        <span style="background-color: #FFFF00">draw attention</span>
        return result.toString();
    }
}