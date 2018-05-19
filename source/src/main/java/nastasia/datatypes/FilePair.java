package nastasia.datatypes;

public class FilePair {
    private int to_test_file, base_file;

    public FilePair(int to_test_file, int base_file) {
        this.to_test_file = to_test_file;
        this.base_file    = base_file;
    }

    public int getTestFileId() {
        return to_test_file;
    }

    public int getBaseFileId() {
        return base_file;
    }
}