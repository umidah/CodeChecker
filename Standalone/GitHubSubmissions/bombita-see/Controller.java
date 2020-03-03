package sample;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.text.DecimalFormat;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;

public class Controller {

    public TextField directoryText;
    public AnchorPane newPane;

    public void compute() throws Exception {
        Queue<String> access_paths = new LinkedList<>();
        Queue<String> matrix_maker = new LinkedList<>();
        String[] paths = new String[37];

        double same_counter = 0;
        double line_counter1 = 0;
        double line_counter2 = 0;
        double line_total;
        int count_file=0;
        String[][] matrix = new String[37][37];

        int spacerX = 0;
        int spacerY =0;

        try (Stream<Path> walk = Files.walk(Paths.get(directoryText.getText()))) {

            List<String> output = walk.map(x -> x.toString())
                    .filter(f -> f.endsWith(".java")).collect(Collectors.toList());

            count_file=output.size();
            //System.out.println(count_file);

            for(int i=0;i<count_file;i++) {
                access_paths.add(output.get(i));
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        try (Stream<Path> walk = Files.walk(Paths.get(directoryText.getText()))) {

            List<String> output = walk.map(x -> x.toString())
                    .filter(f -> f.endsWith(".cpp")).collect(Collectors.toList());

            count_file=count_file+output.size();
            //System.out.println(count_file);

            for(int i=0;i<output.size();i++) {
                access_paths.add(output.get(i));
            }


        } catch (IOException e) {
            e.printStackTrace();
        }

        for(int i=0;i<count_file;i++) {
            paths[i] = access_paths.remove();
        }

        for(int i=0;i<count_file;i++) {
            for (int j = 0; j < count_file; j++) {
                File file1 = new File(paths[i]);
                File file2 = new File(paths[j]);

                BufferedReader reader1 = new BufferedReader(new FileReader(file1));
                BufferedReader reader2 = new BufferedReader(new FileReader(file2));

                String text1 = reader1.readLine();
                String text2 = reader2.readLine();

                while (text1 != null && text2 != null) {
                    if (text1.equalsIgnoreCase(text2)) {
                        same_counter++;
                    }

                    text1 = reader1.readLine();
                    text2 = reader2.readLine();
                }

                BufferedReader reader3 = new BufferedReader(new FileReader(file1));
                BufferedReader reader4 = new BufferedReader(new FileReader(file2));

                text1 = reader3.readLine();
                text2 = reader4.readLine();

                while (text1 != null) {
                    text1 = reader3.readLine();
                    line_counter1++;
                }

                while (text2 != null) {
                    text2 = reader4.readLine();
                    line_counter2++;
                }

                line_total = (line_counter1 + line_counter2) / 2;
                //System.out.println(line_counter1);
                //System.out.println(line_counter2);
                //System.out.println("Number of lines that are the same: " + same_counter);
                //System.out.println("Total number of lines: " + line_total);

                double score = ((same_counter / line_total)-0.5) * 2;
                if (score==1){
                    matrix_maker.add("1.00");
                }
                else if(score==-1){
                    matrix_maker.add("-1.00");
                }
                else {
                    //System.out.println("Your plagiarism score is: " + score);

                    matrix_maker.add(new DecimalFormat("#.##").format(score));
                }

                line_counter1=0;
                line_counter2=0;
                same_counter=0;
            }
        }

        /*for (int c = 0; c < count_file; c++) {
            for (int d = 0; d < count_file; d++) {
                matrix[c][d] = matrix_maker.remove();
            }
        }*/

        for (int c = 0; c < count_file; c++) {
            spacerX=0;
            for (int d = 0; d < count_file; d++) {
                Label data;
                data = new Label(matrix_maker.remove());
                data.setLayoutX(spacerX);
                data.setLayoutY(spacerY);
                newPane.getChildren().add(data);

                //System.out.print(matrix[c][d]+"\t");
                spacerX = spacerX +45;
            }

            spacerY=spacerY+20;
            //System.out.println("");
            /*Label data;
            data = new Label();
            data.setLayoutX(spacerX);
            data.setLayoutY(spacerY);
            newPane.getChildren().add(data);*/
        }
    }
}
