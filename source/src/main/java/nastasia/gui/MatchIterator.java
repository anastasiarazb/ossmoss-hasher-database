package nastasia.gui;

import nastasia.datatypes.ChunkList;

public class MatchIterator {

    enum Direction {
        FORWARD, BACK
    }
    private int curPos;
    private final int maxPos;
    private final String text1;
    private final String text2;

    private final ChunkList list1;
    private final ChunkList list2;

    private final String color1;
    private final String color2;

    public MatchIterator(String text1, String text2, ChunkList list1, ChunkList list2) {
        maxPos = list1.size();
        curPos = 0;
        this.text1 = text1;
        this.text2 = text2;
        this.list1 = list1;
        this.list2 = list2;

        color1 = FilesFormatter.YELLOW_HTML;
        color2 = FilesFormatter.GREEN_HTML;
    }

    public MatchIterator(String text1, String text2, ChunkList list1, ChunkList list2, String color1, String color2) {
        maxPos = list1.size();
        curPos = 0;
        this.text1 = text1;
        this.text2 = text2;
        this.list1 = list1;
        this.list2 = list2;

        this.color1 = color1;
        this.color2 = color2;
    }

    public void next() {
        if (curPos + 1 == maxPos) {
            curPos = 0;
        } else {
            ++curPos;
        }
    }

    public void prev() {
        if (curPos - 1 < 0) {
            curPos = maxPos - 1;
        } else {
            --curPos;
        }
    }

    public String getText1() {
        return FilesFormatter.htmlHighlight(text1, list1.get(curPos), color1);
//        return FilesFormatter.highlightText(text1, list1.get(curPos), color1);
    }

    public String getText2() {
        return FilesFormatter.htmlHighlight(text2, list2.get(curPos), color2);
//        return FilesFormatter.highlightText(text2, list2.get(curPos), color2);
    }

    public int getPos() {
        return curPos;
    }


}