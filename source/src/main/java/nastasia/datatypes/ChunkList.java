package nastasia.datatypes;

import java.util.ArrayList;

public class ChunkList extends ArrayList<ChunkInfo> {
    private final int file_id;

    public ChunkList(int file_id) {
        super();
        this.file_id = file_id;
    }

    public int getFile_id() {
        return  file_id;
    }
}