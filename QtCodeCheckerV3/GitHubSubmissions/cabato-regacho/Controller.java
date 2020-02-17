package sample;

import javafx.scene.control.TextField;
import javafx.scene.layout.TilePane;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class Controller {

    public TextField developer;
    public TilePane t1;
    public TilePane t2;
    public TilePane t3;
    public TilePane t4;
    public TilePane t5;
    public TilePane t6;
    public TilePane t7;
    public TilePane t8;
    public TilePane t9;
    public TilePane t10;
    public TilePane t11;
    public TilePane t12;
    public TilePane t13;
    public TilePane t14;
    public TilePane t15;
    public TilePane t16;
    public TilePane t17;
    public TilePane t18;
    public TilePane t19;
    public TilePane t20;
    public TilePane t21;
    public TilePane t22;
    public TilePane t23;
    public TilePane t24;
    public TilePane t25;
    public TilePane t26;
    public TilePane t27;
    public TilePane t28;
    public TilePane t29;
    public TilePane t30;
    public TilePane t31;
    public TilePane t32;
    public TilePane t33;
    public TilePane t34;
    public TilePane t35;

    public void viewCorrelation() {
        float[] correlation = individualCorrelation(developer.getText());
    }

    public void viewFullMatrix() {
        Similator();

    }

    private void Similator() {
        float [][] correlation = new float[35][35];
        String[][] files = {{"11812249","Submissions/11812249_Module0/LBYCPD2_Module0/src/sample/Main.java"},
                {"11815027","Submissions/11815027_Mod0/src/main.java"},
                {"meh", "Submissions/act1/src/check.java"},
                {"meh", "Submissions/ACTIVITY 0/src/Compare.java"},
                {"Bayeta", "Submissions/BayetaExer0/CompareTwoFiles/src/CompareFile.java"},
                {"Lopez", "Submissions/Lopez_Module0_CodeComparison/Module0_CodeComparison/src/Main.java"},
                {"Magallanes", "Submissions/Magallanes_Module0_11828668/LBYCP2D_Module0_11828668/src/Similaritor.java"},
                {"Vicente", "Submissions/Mod1/src/Main.java"},
                {"meh", "Submissions/Module/prog.cpp"},
                {"meh", "Submissions/Module0/src/Compare.java"},
                {"meh", "Submissions/Module0 2/src/Compare.java"},
                {"Vasquez", "Submissions/Module0-Vasquez/src/Module0Vasquez.java"},
                {"Cabato", "Submissions/Module0_CABATO/src/Main.java"},
                {"meh", "Submissions/Module 0/src/PlagiarismChecker.java"},
                {"meh", "Submissions/Module 0 2/src/Main.java"},
                {"meh", "Submissions/Module 0 3/src/SoftwareSimilarity.java"},
                {"meh", "Submissions/Module 0 4/src/Main.java"},
                {"Portugal", "Submissions/MODULE 0 5/testmain.cpp"},
                {"Megino", "Submissions/ProgramComparison_Megino/programcomparison_Megino.cpp"},
                {"See", "Submissions/see/Main.java"},
                {"Contreras", "Submissions/Similarity_Checker/src/Compare.java"},
                {"Solis", "Submissions/Solis-Checker-Module0/Solis-Checker-Module0/src/programChecker.java"},
                {"meh", "Submissions/src/CompareCode.java"},
                {"Tupal", "Submissions/Submission/Similarity/src/Main.java"},
                {"Chan", "Submissions/CHAN-module0.cpp"},
                {"Chiu", "Submissions/ChiuPlagiarism.java"},
                {"Enghoy", "Submissions/Enghoy_Main.java"},
                {"Gabay", "Submissions/Gabay.0.cpp"},
                {"Llarenas", "Submissions/Llarenas_Main.java"},
                {"Panes", "Submissions/PanesSimilarityChecker.java"},
                {"Parco", "Submissions/Parco_main.cpp"},
                {"Semira", "Submissions/semira_M0.cpp"},
                {"Coteok", "Submissions/TeddyMoss.java"},
                {"Toro", "Submissions/Toro_Module_0.cpp"},
                {"Vhong", "Submissions/VHONG-11814888 - Module 0.cpp"}};

        for (int o = 0; o < files.length; o++) {
            for (int q = 0; q < files.length; q++) {
                String dev1[] = files[o];
                String dev2[] = files[q];
                String[] first = new String[1000];
                String[] second = new String[1000];
                String[] words1 = new String[1000];
                String[] words2 = new String[1000];
                int i = 0;
                int y = 0;
                int j = 0;

                //System.out.println(dev1[0]);
                File code1 = new File(dev1[1]);
                try (BufferedReader br = new BufferedReader(new FileReader(code1))) {
                    String line;
                    while ((line = br.readLine()) != null) {
                        first[i] = line;
                        i++;
                        String[] words = line.split("\\s+");
                        for (int x = 0; x < words.length; x++) {
                            words1[y] = words[x];
                            y++;
                        }
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }

                //System.out.println(dev2[0]);
                y = 0;
                File code2 = new File(dev2[1]);
                try (BufferedReader br = new BufferedReader(new FileReader(code2))) {
                    String line;
                    while ((line = br.readLine()) != null) {
                        second[j] = line;
                        j++;
                        String[] words = line.split("\\s+");
                        for (int x = 0; x < words.length; x++) {
                            words2[y] = words[x];
                            y++;
                        }
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }

                float x = 0;
                for (int z = 0; z < i; z++) {
                    for (int n = 0; n < j; n++) {
                        if (first[z].equals(second[n])) {
                            x++;
                            break;
                        }
                    }
                }

                float perLine = (x / i);
                //System.out.print(String.format("%.2f", perLine) + "\t");
                correlation[o][q] = perLine;
            }
            //System.out.print("\n");
        }
    }

    private float[] individualCorrelation(String lastName) {
        float [] correlation = new float[34];
        int index = 0;
        String[] dev;
        String[][] files = {{"11812249","Submissions/11812249_Module0/LBYCPD2_Module0/src/sample/Main.java"},
                {"11815027","Submissions/11815027_Mod0/src/main.java"},
                {"meh", "Submissions/act1/src/check.java"},
                {"meh", "Submissions/ACTIVITY 0/src/Compare.java"},
                {"Bayeta", "Submissions/BayetaExer0/CompareTwoFiles/src/CompareFile.java"},
                {"Lopez", "Submissions/Lopez_Module0_CodeComparison/Module0_CodeComparison/src/Main.java"},
                {"Magallanes", "Submissions/Magallanes_Module0_11828668/LBYCP2D_Module0_11828668/src/Similaritor.java"},
                {"Vicente", "Submissions/Mod1/src/Main.java"},
                {"meh", "Submissions/Module/prog.cpp"},
                {"meh", "Submissions/Module0/src/Compare.java"},
                {"meh", "Submissions/Module0 2/src/Compare.java"},
                {"Vasquez", "Submissions/Module0-Vasquez/src/Module0Vasquez.java"},
                {"Cabato", "Submissions/Module0_CABATO/src/Main.java"},
                {"meh", "Submissions/Module 0/src/PlagiarismChecker.java"},
                {"meh", "Submissions/Module 0 2/src/Main.java"},
                {"meh", "Submissions/Module 0 3/src/SoftwareSimilarity.java"},
                {"meh", "Submissions/Module 0 4/src/Main.java"},
                {"Portugal", "Submissions/MODULE 0 5/testmain.cpp"},
                {"Megino", "Submissions/ProgramComparison_Megino/programcomparison_Megino.cpp"},
                {"See", "Submissions/see/Main.java"},
                {"Contreras", "Submissions/Similarity_Checker/src/Compare.java"},
                {"Solis", "Submissions/Solis-Checker-Module0/Solis-Checker-Module0/src/programChecker.java"},
                {"meh", "Submissions/src/CompareCode.java"},
                {"Tupal", "Submissions/Submission/Similarity/src/Main.java"},
                {"Chan", "Submissions/CHAN-module0.cpp"},
                {"Chiu", "Submissions/ChiuPlagiarism.java"},
                {"Enghoy", "Submissions/Enghoy_Main.java"},
                {"Gabay", "Submissions/Gabay.0.cpp"},
                {"Llarenas", "Submissions/Llarenas_Main.java"},
                {"Panes", "Submissions/PanesSimilarityChecker.java"},
                {"Parco", "Submissions/Parco_main.cpp"},
                {"Semira", "Submissions/semira_M0.cpp"},
                {"Coteok", "Submissions/TeddyMoss.java"},
                {"Toro", "Submissions/Toro_Module_0.cpp"},
                {"Vhong", "Submissions/VHONG-11814888 - Module 0.cpp"}};

        for (int i = 0; i < files.length; i++) {
            dev = files[i];
            if (dev[0].equals(lastName)) {
                index = i;
            }
        }

        for (int o = 0; o < files.length; o++) {
            String[] dev2 = files[o];
            String[] first = new String[1000];
            String[] words1 = new String[1000];
            String[] second = new String[1000];
            String[] words2 = new String[1000];
            int i = 0;
            int y = 0;
            int j = 0;

            dev = files[index];
            File code1 = new File(dev[1]);
            try (BufferedReader br = new BufferedReader(new FileReader(code1))) {
                String line;
                while ((line = br.readLine()) != null) {
                    first[i] = line;
                    i++;
                    String[] words = line.split("\\s+");
                    for (int x = 0; x < words.length; x++) {
                        words1[y] = words[x];
                        y++;
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            }

            File code2 = new File(dev2[1]);
            try (BufferedReader br = new BufferedReader(new FileReader(code2))) {
                String line;
                while ((line = br.readLine()) != null) {
                    second[j] = line;
                    j++;
                    String[] words = line.split("\\s+");
                    for (int x = 0; x < words.length; x++) {
                        words2[y] = words[x];
                        y++;
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            }

            float x = 0;
            for (int z = 0; z < i; z++) {
                for (int n = 0; n < j; n++) {
                    if (first[z].equals(second[n])) {
                        x++;
                        break;
                    }
                }
            }
            float perLine = (x / i);
            correlation[o] = perLine;
        }
        return correlation;
    }
}
