package sample;

import java.io.File;
import java.nio.file.Files;
import java.nio.file.Paths;

public class getSimilarity {
    double percent;
    int wordcount;
    double wordpercent;

    getSimilarity(){
        percent = 0;
        wordcount = 0;
        wordpercent = 0.0;
    }

    double getPercent(File[] files, int i, int j) throws Exception {
        percent = 0;
        wordcount = 0;
        wordpercent = 0.0;

        String text1 = readFileAsString("C:\\Users\\Jan Go\\Desktop\\Files\\"+files[i].getName());
        String text2 = readFileAsString("C:\\Users\\Jan Go\\Desktop\\Files\\"+files[j].getName());

        String[] words1 = text1.split("\\W+");
        String[] words2 = text2.split("\\W+");

        wordpercent = (100.0/(((double)words2.length+(double) words1.length)/2));

        for(i =0; i< words2.length;i++){
            for (j=0; j<words1.length;j++) {
                if (words1[j].equalsIgnoreCase(words2[i])) {
                    words1[j]="";
                    percent = percent + wordpercent;
                }
            }
        }
        return percent;
    }

    public static String readFileAsString(String fileName)throws Exception
    {
        String data = "";
        data = new String(Files.readAllBytes(Paths.get(fileName)));
        return data;
    }
}
