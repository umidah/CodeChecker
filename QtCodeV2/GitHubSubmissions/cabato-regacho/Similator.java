package sample;
import java.io.*;

public class Similator{
    public static void main (String [] args){
        float [][] correlation = new float[36][36];
        String[][] files = {{"Go, J","Submissions/11812249_Module0/LBYCPD2_Module0/src/sample/Main.java"},
                {"Portugal","Submissions/11815027_Mod0/src/main.java"},
                {"Chua", "Submissions/act1/src/check.java"},
                {"Khow", "Submissions/ACTIVITY 0/src/Compare.java"},
                {"Bayeta", "Submissions/BayetaExer0/CompareTwoFiles/src/CompareFile.java"},
                {"Lopez", "Submissions/Lopez_Module0_CodeComparison/Module0_CodeComparison/src/Main.java"},
                {"Magallanes", "Submissions/Magallanes_Module0_11828668/LBYCP2D_Module0_11828668/src/Similaritor.java"},
                {"Vicente", "Submissions/Mod1/src/Main.java"},
                {"Magcamit", "Submissions/Module/prog.cpp"},
                {"Ongsitco", "Submissions/Module0/src/Compare.java"},
                {"Regacho", "Submissions/Module0_Regacho/main.cpp"},
                {"Vasquez", "Submissions/Module0-Vasquez/src/Module0Vasquez.java"},
                {"Cabato", "Submissions/Module0_CABATO/src/Main.java"},
                {"Bombita", "Submissions/Module 0/src/PlagiarismChecker.java"},
                {"Go, M", "Submissions/Module 0 2/src/Main.java"},
                {"Sabularse", "Submissions/Module 0 3/src/SoftwareSimilarity.java"},
                {"Antoc", "Submissions/Module 0 4/src/Main.java"},
                {"Co", "Submissions/malcolm_src/FileToString.java"},
                {"Caoile", "Submissions/MODULE 0 5/testmain.cpp"},
                {"Megino", "Submissions/ProgramComparison_Megino/programcomparison_Megino.cpp"},
                {"See", "Submissions/see/Main.java"},
                {"Contreras", "Submissions/Similarity_Checker/src/Compare.java"},
                {"Solis", "Submissions/Solis-Checker-Module0/Solis-Checker-Module0/src/programChecker.java"},
                {"Tiu", "Submissions/src/CompareCode.java"},
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
                Metric.filename = dev1[1];
                Metric.main(args);

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
                Metric.filename = dev2[1];
                Metric.main(args);

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
                System.out.print(String.format("%.2f", perLine) + "\t");
                correlation[o][q] = perLine;
            }
            System.out.print("\n");
        }
        System.out.println("\n# of Operators | # of Operands | # of unique Oprts | # of unique Opnds | Program Length | Vocabulary Size | " +
                "Program Volume | Difficulty | Program Level | Effort to Implement | Time to implement | # of delivered bugs ");

    }
}
