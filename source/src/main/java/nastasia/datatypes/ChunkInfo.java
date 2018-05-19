package nastasia.datatypes;

import pro.skor.lexems.Coords;

public class ChunkInfo {
    String digest;
    int    index;
    Coords start;
    Coords follow;

    public ChunkInfo(String digest, int index, Coords start, Coords follow) {
        this.digest = digest;
        this.index  = index;
        this.start  = start;
        this.follow = follow;
    }

    public int getStartPos() {
        return start.getPos();
    }

    public int getFollowPos() {
        return follow.getPos();
    }

    public static ChunkInfo append(ChunkInfo src1, ChunkInfo src2) {
        return new ChunkInfo(null, src1.index, src1.start, src2.follow);
    }

    public static boolean mayBeUnioned(ChunkInfo src1, ChunkInfo src2) {
        // Полагаем, что последовательность чанков "правильная", то есть ни один не включен строго в другой
        // И проверяем, находится ли start2 между start1 и follow1
        return     (src1.start.getPos() < src2.start.getPos()) // start1 < start2 < follow1 < follow2
                && (src2.start.getPos() < src1.follow.getPos());
    }

    public void append(ChunkInfo another) {
        this.digest = null;
        this.follow = another.follow;
    }

    @Override
    public boolean equals(Object x) {
        return (x instanceof ChunkInfo)
            && (index == ((ChunkInfo)x).index);
    }
}