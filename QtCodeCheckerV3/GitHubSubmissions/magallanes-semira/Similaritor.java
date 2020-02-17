import CodeBusterClasses.*;
import java.io.*;

public class Similaritor {

    private static void Print2DArray(float array[][], String arraySecond[], int length){
        //length is the size of the matrix

        System.out.print("\t\t\t");
        for (String name : arraySecond) {
            System.out.printf("%-11s ", name);
        }
        System.out.println();

        for (int i = 0; i < length; i++) {

            System.out.printf("%-10s \t",arraySecond[i]);

            for (int j = 0 ; j < length ; j++){

                System.out.printf("%7.2f \t",array[i][j]);

            }

            System.out.println();

        }

    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here

        float matrixSimilarity[][];
        String names[];
        File folder = new File("./src/Programs_To_Compare");
        matrixSimilarity = new float[folder.listFiles().length][folder.listFiles().length];
        names = new String[folder.listFiles().length];

        float highestScore = 0;
        int jIndex = 0;
        int iIndex =0;

        System.out.println("File names inside the directory:");
        for (int i = 0; i < folder.listFiles().length; i++) {
            String temp [] = folder.listFiles()[i].getName().split("_");
            names[i] = temp[0];
            System.out.println(names[i] + " : " + folder.listFiles()[i].getName());
        }

        System.out.println("\n\nPairs with more than 90 as score:");
        for (int i = 0; i < folder.listFiles().length ; i++) {

            for (int j = 0; j<folder.listFiles().length;j++){

                matrixSimilarity[i][j] = new CompareClass(folder.listFiles()[i].getAbsolutePath(),folder.listFiles()[j].getAbsolutePath()).getSimilarityScore();

                if(matrixSimilarity[i][j] > 90 && matrixSimilarity[i][j] < 100){
                    System.out.printf("%s and %s with a score of %.2f\n", names[i],names[j],matrixSimilarity[i][j] );

                }

                if(matrixSimilarity[i][j] >highestScore && matrixSimilarity[i][j] != 100){
                    highestScore = matrixSimilarity[i][j] ;
                    jIndex = j;
                    iIndex = i;
                }

            }
        }

        System.out.printf("\n\n\nPair with the highest score is %s and %s with the score of %.2f",  names[iIndex], names[jIndex], matrixSimilarity[iIndex][jIndex]);

        System.out.println("\n\nMatrix:");

        Print2DArray(matrixSimilarity, names, folder.listFiles().length);

    }

}
