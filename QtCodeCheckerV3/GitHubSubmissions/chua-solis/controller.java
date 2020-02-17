import javafx.fxml.FXML;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.text.Text;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Map;

public class controller {
    @FXML
    private GridPane correlationMatrix;
    private String path;

    public void setPath(String path){
        this.path = path;
    }

    @FXML
   public void initialize() throws IOException {
    }

    public void printTable() throws IOException {
        int row = 1;
        programSimilarityChecker test =  new programSimilarityChecker(path);
        ArrayList<StackPane> names = new ArrayList<>();
        names.add(new StackPane(new Text("Scores")));
        for (String name : test.crossCompare().keySet()) {
            names.add(new StackPane(new Text(name)));
        }
        StackPane[] nameList = new StackPane[names.size()];
        names.toArray(nameList);
        correlationMatrix.addRow(row++, nameList);
        for (Map.Entry<String, ArrayList<Double>> entry1 : test.crossCompare().entrySet()) {
            String name = entry1.getKey();
            ArrayList<Double> scores = entry1.getValue();
            ArrayList<Pane> scorePanes = new ArrayList<>();
            Pane namePane = new StackPane();
            namePane.getChildren().add(new Text(name));
            scorePanes.add(namePane);
            for (Double score : scores){
                Pane newPane = new StackPane();
                newPane.setBackground(new Background(new BackgroundFill(Color.color(score / 100, 1 - (score / 100), 0), null,null)));
                newPane.getChildren().add(new Text(String.format("%.2f", score)));
                scorePanes.add(newPane);
            }

            Pane[] scorePaneArray = new Pane[scorePanes.size()];
            scorePanes.toArray(scorePaneArray);
            correlationMatrix.addRow(row++, scorePaneArray);
        }
    }
}
