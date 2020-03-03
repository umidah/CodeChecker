package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;

import java.io.File;

public class Controller {
    @FXML
    private TextArea textarea;

    @FXML
    private Button startButton;

    @FXML
    void startProgram(ActionEvent event) throws Exception {
        int filecount = 0;
        int pair1 = 0, pair2 = 0;
        Double percent1, percent2;
        File f = new File("C:\\Users\\Jan Go\\Desktop\\Files");
        File[] files = f.listFiles();
        getSimilarity sim = new getSimilarity();
        StringBuilder s = new StringBuilder();

        try {

            System.out.println("Files are:");
            filecount = files.length;
            for (int i = 0; i < files.length; i++) {
                System.out.println(files[i].getName());
            }
        }
        catch (Exception e) {
            System.err.println(e.getMessage());
        }

        String[][] percentmatrix = new String[filecount][filecount];
        Double[][] percentmatrixdouble = new Double[filecount][filecount];

        for (int i =0; i <filecount;i++){
            for (int j=0; j<filecount;j++){
                String formatedString = String.format("%.1f",sim.getPercent(files, i, j));
                percentmatrixdouble[i][j] = sim.getPercent(files, i, j);
                percentmatrix[i][j] = formatedString;
            }
        }

        textarea.setPrefColumnCount(filecount+1);
        textarea.setPrefRowCount(filecount);

        System.out.println("\n\nMatrix of Percentage Similarity (follow format from 'Files are:'): \n");
        s.append("\n\nMatrix of Percentage Similarity (follow format from 'Files are:'): \n");
        s.append(String.format("%50s", ""));
        System.out.format("%16s", "");
        for (int i=0; i<filecount; i++) {
            System.out.format("%16s",files[i].getName());
            s.append(String.format("%50s", files[i].getName()));
        }
        System.out.println();
        s.append("\n");
        for (int i =0; i <filecount;i++) {
            System.out.format("%16s",files[i].getName());
            s.append(String.format("%50s", files[i].getName()));
            for (int j = 0; j < filecount; j++) {
                System.out.format("%16s", percentmatrix[i][j]);
                s.append(String.format("%53s",percentmatrix[i][j]));
            }
            System.out.println();
            s.append("\n");
        }

        textarea.setText(s.toString());

        percent1 = 0.0;

        for (int i=0; i<filecount; i++) {
            for (int j=0; j<filecount; j++) {
                if(i==j) continue;
                if(percent1 < percentmatrixdouble[i][j]) {
                    percent1 = percentmatrixdouble[i][j];
                    pair1 = i;
                    pair2 = j;
                }
            }
        }

        String formatedString = String.format("%.1f", percent1);
        System.out.println("Highest word percentage similarity: " + formatedString);
        System.out.println("Pair: " + files[pair1].getName() + " & " + files[pair2].getName());

    }
}
