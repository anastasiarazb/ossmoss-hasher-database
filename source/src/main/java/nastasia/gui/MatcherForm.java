package nastasia.gui;

import com.intellij.uiDesigner.core.GridConstraints;
import com.intellij.uiDesigner.core.GridLayoutManager;
import nastasia.connectionholder.ConnectionHolder;
import nastasia.datatypes.MatchInfo;
import nastasia.tables.FilesComparison;
import nastasia.tables.SourceFile;

import javax.swing.*;
import javax.swing.text.DefaultFormatterFactory;
import javax.swing.text.MaskFormatter;
import java.awt.*;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class MatcherForm extends JFrame {

    private JTextPane FileToTest;
    private JTextPane BaseFile;
    private JTextArea matchRating;
    private JTextArea chunkCounter;
    private JButton previousButton;
    private JButton nextButton;
    private JButton compareFilesButton;
    private JPanel mainPanel;
    private JTextField testLogin;
    private JTextField baseLogin;
    private JFormattedTextField baseTime;
    private JFormattedTextField testTime;

    private MatchInfo matchInfo;
    private ConnectionHolder connectionHolder;
    private MatchIterator matchIterator;
    private int matchedContinuousAreasNum;

    private void adjustDataTextFormat(JFormattedTextField field) {
        try {
            DateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
            MaskFormatter mf = new MaskFormatter("####-##-## ##:##:##");
            field.setFormatterFactory(new DefaultFormatterFactory(mf));
            field.addFocusListener(new FocusAdapter() {
                public void focusGained(FocusEvent e) {
                    if (field.getFocusLostBehavior() == JFormattedTextField.PERSIST)
                        field.setFocusLostBehavior(JFormattedTextField.COMMIT_OR_REVERT);
                }

                public void focusLost(FocusEvent e) {
                    try {
                        Date date = (Date) df.parseObject(field.getText());
                        field.setValue(df.format(date));
                    } catch (ParseException pe) {
                        field.setFocusLostBehavior(JFormattedTextField.PERSIST);
                        field.setText("");
                        field.setValue(null);
                    }
                }
            });
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public MatcherForm(MatchInfo matchInfo, ConnectionHolder holder) {
        super("Compare two files");
        this.matchInfo = matchInfo;
        setContentPane(mainPanel);
//        frame.setSize(300, 200);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        pack();

        this.connectionHolder = holder;
        adjustDataTextFormat(baseTime);
        adjustDataTextFormat(testTime);
        testTime.setText(matchInfo.getSendTime1());
        baseTime.setText(matchInfo.getSendTime2());
        testLogin.setText(matchInfo.getLogin1());
        baseLogin.setText(matchInfo.getLogin2());
        FileToTest.setContentType("text/html");
        BaseFile.setContentType("text/html");

        compareFilesById(matchInfo.getId1(), matchInfo.getId2());

        compareFilesButton.addActionListener(actionEvent -> compareFiles());
        nextButton.addActionListener(actionEvent -> shiftMatchIterator(MatchIterator.Direction.FORWARD));
        previousButton.addActionListener(actionEvent -> shiftMatchIterator(MatchIterator.Direction.BACK));

    }

    private void shiftMatchIterator(MatchIterator.Direction direction) {
        switch (direction) {
            case FORWARD:
                matchIterator.next();
                break;
            case BACK:
                matchIterator.prev();
        }
        FileToTest.setText(matchIterator.getText1());
        BaseFile.setText(matchIterator.getText2());
        int position = matchIterator.getPos() + 1;

        String curPos = String.format(
                "Match: %d/%d", position, matchedContinuousAreasNum
        );

        chunkCounter.setText(curPos);
    }

    private void compareFilesById(int test_file, int base_file) {
        FilesComparison x = FilesComparison.intersect2FilesChunks(test_file, base_file, connectionHolder);
        SourceFile file1 = SourceFile.getFileInfo(x.getToTestFile().getFile_id(), connectionHolder);
        SourceFile file2 = SourceFile.getFileInfo(x.getBaseFile().getFile_id(), connectionHolder);

        String code1 = file1.getCode();
        String code2 = file2.getCode();

        int matchedChunksNum = x.getBaseFile().size();

        String info = String.format(
                "File to test: %d symbols, %d digests; \n" +
                        "Base file:    %d symbols, %d digests; \n" +
                        "Matched %d digests, %d%% from test file.",
                code1.length(), file1.getDigestNum(),
                code2.length(), file2.getDigestNum(),
                matchedChunksNum, 100 * matchedChunksNum / file1.getDigestNum()
        );

        x = x.optimizeOutput();

        matchIterator = new MatchIterator(code1, code2, x.getToTestFile(), x.getBaseFile());

        matchedContinuousAreasNum = x.getBaseFile().size();
        int position = matchIterator.getPos() + 1;

        String curPos = String.format(
                "Match: %d/%d", position, matchedContinuousAreasNum
        );

        matchRating.setText(info);
        chunkCounter.setText(curPos);
        FileToTest.setText(matchIterator.getText1());
        BaseFile.setText(matchIterator.getText2());

    }

    private void compareFiles() {
        String login1 = testLogin.getText();
        String login2 = baseLogin.getText();
        String time1 = testTime.getText();
        String time2 = baseTime.getText();

        if (login1.isEmpty() || login2.isEmpty() || time1.isEmpty() || time2.isEmpty()) {
            matchRating.setText(
                    "Pity, FILE TO TEST is not found. Are the fields filled correctly?"
            );
            return;
        }

        System.out.println(login1 + time1);
        int test_file = SourceFile.findIdByLoginTime(login1, time1, connectionHolder);

        if (test_file < 0) {
            matchRating.setText(
                    "Pity, FILE TO TEST is not found. Are the fields filled correctly?"
            );
            return;
        }
        int base_file = SourceFile.findIdByLoginTime(login2, time2, connectionHolder);
        if (base_file < 0) {
            matchRating.setText(
                    "Pity, BASE FILE is not found. Are the fields filled correctly?"
            );
            return;
        }

        compareFilesById(test_file, base_file);

    }


    {
// GUI initializer generated by IntelliJ IDEA GUI Designer
// >>> IMPORTANT!! <<<
// DO NOT EDIT OR ADD ANY CODE HERE!
        $$$setupUI$$$();
    }

    /**
     * Method generated by IntelliJ IDEA GUI Designer
     * >>> IMPORTANT!! <<<
     * DO NOT edit this method OR call it in your code!
     *
     * @noinspection ALL
     */
    private void $$$setupUI$$$() {
        mainPanel = new JPanel();
        mainPanel.setLayout(new GridLayoutManager(3, 1, new Insets(0, 0, 0, 0), -1, -1));
        mainPanel.setMinimumSize(new Dimension(700, 500));
        mainPanel.setPreferredSize(new Dimension(700, 600));
        final JPanel panel1 = new JPanel();
        panel1.setLayout(new GridLayoutManager(1, 2, new Insets(0, 0, 0, 0), -1, -1));
        mainPanel.add(panel1, new GridConstraints(2, 0, 1, 1, GridConstraints.ANCHOR_CENTER, GridConstraints.FILL_BOTH, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_CAN_GROW, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_CAN_GROW, null, new Dimension(-1, 50), null, 0, true));
        final JScrollPane scrollPane1 = new JScrollPane();
        panel1.add(scrollPane1, new GridConstraints(0, 0, 1, 1, GridConstraints.ANCHOR_CENTER, GridConstraints.FILL_BOTH, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_WANT_GROW, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_WANT_GROW, null, null, null, 0, false));
        FileToTest = new JTextPane();
        FileToTest.setText("");
        scrollPane1.setViewportView(FileToTest);
        final JScrollPane scrollPane2 = new JScrollPane();
        panel1.add(scrollPane2, new GridConstraints(0, 1, 1, 1, GridConstraints.ANCHOR_CENTER, GridConstraints.FILL_BOTH, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_WANT_GROW, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_WANT_GROW, null, null, null, 0, false));
        BaseFile = new JTextPane();
        BaseFile.setText("");
        scrollPane2.setViewportView(BaseFile);
        final JPanel panel2 = new JPanel();
        panel2.setLayout(new GridLayoutManager(3, 4, new Insets(0, 0, 0, 0), -1, -1));
        mainPanel.add(panel2, new GridConstraints(0, 0, 1, 1, GridConstraints.ANCHOR_NORTH, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_CAN_GROW, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, true));
        final JLabel label1 = new JLabel();
        label1.setText("Base file");
        panel2.add(label1, new GridConstraints(0, 3, 1, 1, GridConstraints.ANCHOR_CENTER, GridConstraints.FILL_NONE, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JLabel label2 = new JLabel();
        label2.setText("To test file");
        panel2.add(label2, new GridConstraints(0, 1, 1, 1, GridConstraints.ANCHOR_CENTER, GridConstraints.FILL_NONE, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        testLogin = new JTextField();
        panel2.add(testLogin, new GridConstraints(1, 1, 1, 1, GridConstraints.ANCHOR_WEST, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_WANT_GROW, GridConstraints.SIZEPOLICY_FIXED, null, new Dimension(150, -1), null, 0, false));
        baseLogin = new JTextField();
        baseLogin.setText("");
        panel2.add(baseLogin, new GridConstraints(1, 3, 1, 1, GridConstraints.ANCHOR_WEST, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_WANT_GROW, GridConstraints.SIZEPOLICY_FIXED, null, new Dimension(150, -1), null, 0, false));
        final JLabel label3 = new JLabel();
        label3.setText("Login");
        panel2.add(label3, new GridConstraints(1, 0, 1, 1, GridConstraints.ANCHOR_WEST, GridConstraints.FILL_NONE, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JLabel label4 = new JLabel();
        label4.setText("Login");
        panel2.add(label4, new GridConstraints(1, 2, 1, 1, GridConstraints.ANCHOR_WEST, GridConstraints.FILL_NONE, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JLabel label5 = new JLabel();
        label5.setText("Send time");
        panel2.add(label5, new GridConstraints(2, 0, 1, 1, GridConstraints.ANCHOR_WEST, GridConstraints.FILL_NONE, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JLabel label6 = new JLabel();
        label6.setText("Send time");
        panel2.add(label6, new GridConstraints(2, 2, 1, 1, GridConstraints.ANCHOR_WEST, GridConstraints.FILL_NONE, GridConstraints.SIZEPOLICY_FIXED, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        baseTime = new JFormattedTextField();
        panel2.add(baseTime, new GridConstraints(2, 3, 1, 1, GridConstraints.ANCHOR_WEST, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_WANT_GROW, GridConstraints.SIZEPOLICY_FIXED, null, new Dimension(150, -1), null, 0, false));
        testTime = new JFormattedTextField();
        testTime.setText("");
        panel2.add(testTime, new GridConstraints(2, 1, 1, 1, GridConstraints.ANCHOR_WEST, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_WANT_GROW, GridConstraints.SIZEPOLICY_FIXED, null, new Dimension(150, -1), null, 0, false));
        final JPanel panel3 = new JPanel();
        panel3.setLayout(new GridLayoutManager(1, 5, new Insets(0, 0, 0, 0), -1, -1));
        mainPanel.add(panel3, new GridConstraints(1, 0, 1, 1, GridConstraints.ANCHOR_NORTH, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_CAN_GROW, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, false));
        matchRating = new JTextArea();
        matchRating.setRows(5);
        matchRating.setText("");
        panel3.add(matchRating, new GridConstraints(0, 1, 1, 1, GridConstraints.ANCHOR_SOUTH, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_WANT_GROW, GridConstraints.SIZEPOLICY_CAN_GROW, null, new Dimension(150, -1), null, 0, false));
        chunkCounter = new JTextArea();
        chunkCounter.setColumns(3);
        chunkCounter.setRows(3);
        chunkCounter.setText("");
        panel3.add(chunkCounter, new GridConstraints(0, 2, 1, 1, GridConstraints.ANCHOR_SOUTHEAST, GridConstraints.FILL_NONE, GridConstraints.SIZEPOLICY_WANT_GROW, GridConstraints.SIZEPOLICY_WANT_GROW, null, new Dimension(150, -1), null, 0, false));
        previousButton = new JButton();
        previousButton.setText("Previous");
        panel3.add(previousButton, new GridConstraints(0, 3, 1, 1, GridConstraints.ANCHOR_SOUTH, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_CAN_GROW, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        nextButton = new JButton();
        nextButton.setText("Next");
        panel3.add(nextButton, new GridConstraints(0, 4, 1, 1, GridConstraints.ANCHOR_SOUTH, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_CAN_GROW, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        compareFilesButton = new JButton();
        compareFilesButton.setText("Update");
        panel3.add(compareFilesButton, new GridConstraints(0, 0, 1, 1, GridConstraints.ANCHOR_CENTER, GridConstraints.FILL_HORIZONTAL, GridConstraints.SIZEPOLICY_CAN_SHRINK | GridConstraints.SIZEPOLICY_CAN_GROW, GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
    }

    /**
     * @noinspection ALL
     */
    public JComponent $$$getRootComponent$$$() {
        return mainPanel;
    }
}