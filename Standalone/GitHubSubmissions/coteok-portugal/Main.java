/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
import java.util.concurrent.SubmissionPublisher;

/**
 * Rough Java MOSS Program
 * Functionalities:
 * Compares Two Java and C++ Programs Similarity by Comparing the Lines
 * @Theodore Benito C. Coteok II
 * START - 01/21/2020 - 1009
 * END - 01/21/2020 - 1145
 */
public class Main {

    public static String[] filePath = new String[200];
    public static int fileCount = 0;

    /*
     * @param args the command line arguments
     */

    static void teddy() throws IOException {
        //initializing counters
        int stringCountJ1 = 0;
        int stringCountJ2 = 0;
        int stringCountC1 = 0;
        int stringCountC2 = 0;

        int pRawScore = 0;
        int pRawScoreC = 0;

        int lineCount = 0;
        int lineCountC = 0;

        double pGrade = 0;
        double pGradeC = 0;
        //opening files
        File fileJ1 = new File("C:\\Users\\ECE\\Documents\\NetBeansProjects\\Module 0\\src\\module\\pkg0\\HelloAgain.java");
        File fileJ2 = new File("C:\\Users\\ECE\\Documents\\NetBeansProjects\\Module0Pair2\\src\\module0pair2\\HelloAgain.java");
        File fileC1 = new File("C:\\Users\\ECE\\Desktop\\Module 0\\test_program1.cpp");
        File fileC2 = new File("C:\\Users\\ECE\\Desktop\\Module 0\\test_program2.cpp");

        FileInputStream fileStreamJ1 = new FileInputStream(fileJ1);
        FileInputStream fileStreamJ2 = new FileInputStream(fileJ2);
        FileInputStream fileStreamC1 = new FileInputStream(fileC1);
        FileInputStream fileStreamC2 = new FileInputStream(fileC2);

        InputStreamReader inputJ1 = new InputStreamReader(fileStreamJ1);
        InputStreamReader inputJ2 = new InputStreamReader(fileStreamJ2);
        InputStreamReader inputC1 = new InputStreamReader(fileStreamC1);
        InputStreamReader inputC2 = new InputStreamReader(fileStreamC2);

        BufferedReader readerJ1 = new BufferedReader(inputJ1);
        BufferedReader readerJ2 = new BufferedReader(inputJ2);
        BufferedReader readerC1 = new BufferedReader(inputC1);
        BufferedReader readerC2 = new BufferedReader(inputC2);

        String lineJ1;
        String lineJ2;
        String lineC1;
        String lineC2;

        String[] charsJ1;
        String[] charsJ2;
        String[] charsC1;
        String[] charsC2;
        //compare and count similar words
        while(((lineJ1 = readerJ1.readLine()) != null) && ((lineJ2 = readerJ2.readLine()) != null)){
            if(!(lineJ1.equals(""))){
                charsJ1 = lineJ1.split("\\s+");
                stringCountJ1 += charsJ1.length;
            }
            if(!(lineJ2.equals(""))){
                charsJ2 = lineJ2.split("\\s+");
                stringCountJ2 += charsJ2.length;
            }
            if(lineJ1.equals(lineJ2)) pRawScore++;
            lineCount++;
            //if(checkEquality(charsJ1, charsJ2)) pRawScore++;
        }
        //score computation
        pGrade = (Double.valueOf(pRawScore)/Double.valueOf(lineCount))*100;

        //sa C naman
        //compare and count similar words
        while(((lineC1 = readerC1.readLine()) != null) && ((lineC2 = readerC2.readLine()) != null)){
            if(!(lineC1.equals(""))){
                charsC1 = lineC1.split("\\s+");
                stringCountC1 += charsC1.length;
            }
            if(!(lineC2.equals(""))){
                charsC2 = lineC2.split("\\s+");
                stringCountC2 += charsC2.length;
            }
            if(lineC1.equals(lineC2)) pRawScoreC++;
            lineCountC++;
        }
        //score computation
        pGradeC = (Double.valueOf(pRawScoreC)/Double.valueOf(lineCountC))*100;

        //display results
        System.out.println("Number of words in Java File 1: " + stringCountJ1);
        System.out.println("Number of words in Java File 2: " + stringCountJ2);
        //System.out.println("Number of similar words: " + pRawScore);
        System.out.println("Number of similar lines in the two Java Files: " + pRawScore);
        System.out.println("Java Program Similarity Score: " + pGrade);
        if(pGrade >= 50) System.out.println("The two Java Programs are similar!");
        else System.out.println("The two Java Programs are not similar");
        System.out.println();
        System.out.println("Number of words in C File 1: " + stringCountC1);
        System.out.println("Number of words in C File 2: " + stringCountC2);
        System.out.println("Number of similar lines in the two C Files: " + pRawScoreC);
        System.out.println("C Program Similarity Score: " + pGradeC);
        if(pGrade >= 50) System.out.println("The two C Programs are similar!");
        else System.out.println("The two C Programs are not similar");
    }

    static void listFiles(File[] arr, int index, int level){
        if(index == arr.length) return;

        if(arr[index].isDirectory()){
            listFiles(arr[index].listFiles(), 0, level+1);
        }

        else if(arr[index].isFile()) {
            if (arr[index].getName().endsWith(".java") || arr[index].getName().endsWith(".cpp")){
                System.out.println(arr[index].getPath());
                filePath[fileCount] = arr[index].getPath();
                fileCount++;
            }
        }

        else if(arr[index].isDirectory()){
            System.out.print(arr[index].getName() + "/");
            listFiles(arr[index].listFiles(), 0, level+1);
        }
        listFiles(arr, ++index, level);
    }

    static class submittedPrograms implements FilenameFilter{
        @Override
        public boolean accept(File dir, String name) {
            if(name.endsWith(".cpp") || name.endsWith(".java")) return true;
            else return false;
        }
    }

    static void portu() throws IOException {
        DecimalFormat df = new DecimalFormat("0.00");
        String directoryPath = "assets/Submissions";
        File submissionsFolder = new File(directoryPath);

        if(submissionsFolder.exists() && submissionsFolder.isDirectory()){
            File arr[] = submissionsFolder.listFiles();
            System.out.println("**********************************************");
            System.out.println("Files from main directory : " + submissionsFolder);
            System.out.println("**********************************************");

            listFiles(arr, 0 ,0);
        }

        BufferedReader bFile1 = null;
        BufferedReader bFile2 = null;

        String line1 = "";
        String line2 = "";

        String line1SansSpaces = "";
        String line2SansSpaces = "";
        String longestLine = "";
        String longestLineFile1 = "";
        String longestLineFile2 = "";

        int currentCharacterCount = 0;
        int longestCharacterCount = 0;
        int lineCount = 0;
        int longestLineNum = 0;

        int lineCount1 = 0;
        int lineCount2 = 0;
        int otherLC2 = 0;


        double[][] lineReader = new double[200][200];
        double[][] similarityCount = new double[200][200];

        String[][] lineStorage1 = new String[200][500];
        String[][] lineStorage2 = new String[200][500];

        for(int i = 0; i <= fileCount; i++){
            for(int j = 0; j <= fileCount; j++){
                lineReader[i][j] = 0;
                similarityCount[i][j] = 1;
            }
        }

        for(int i = 1; i < 200; i++){
            for(int j = 1; j < 500; j++){
                lineStorage1[i][j] = "";
                lineStorage2[i][j] = "";
            }
        }

        // LINE TO ARRAY PUSHING
        for(int i = 0; i <= fileCount-1; i++){
            for(int j = 0; j <= fileCount-1; j++){
                bFile1 = new BufferedReader(new FileReader(filePath[i]));
                bFile2 = new BufferedReader(new FileReader(filePath[j]));

                lineCount1 = 0;
                while ((line1 = bFile1.readLine()) != null){
                    line1SansSpaces = line1.replaceAll("\\s+", "");
                    lineCount1 = lineCount1 + 1;
                    lineStorage1[i][lineCount1] = line1SansSpaces;

                    if(bFile2.readLine() != null) {
                        lineCount2 = 0;
                        while ((line2 = bFile2.readLine()) != null) {
                            line2SansSpaces = line2.replaceAll("\\s+", "");
                            lineCount2 = lineCount2 + 1;
                            lineStorage2[j][lineCount2] = line2SansSpaces;
                        }
                    }
                }
            }
        }

        // TOTAL LINE COUNTER
        for(int i = 0; i <= fileCount-1; i++){
            for(int j = 0; j <= fileCount-1; j++){
                bFile1 = new BufferedReader(new FileReader(filePath[i]));
                bFile2 = new BufferedReader(new FileReader(filePath[j]));
                if(bFile1.readLine() != null) {
                    lineCount1 = 0;
                    while (bFile1.readLine() != null) {
                        lineCount1 = lineCount1 + 1;
                    }
                }
                if(bFile2.readLine() != null) {
                    lineCount2 = 0;
                    while (bFile2.readLine() != null) {
                        lineCount2 = lineCount2 + 1;
                    }
                }
                // gets the total amount of lines for similarity of the file with the largest number of lines.
                //System.out.println("\nFILE" + i + " vs " + j +" - "+ lineCount1 + " vs " + lineCount2);
                if (lineCount1 < lineCount2) lineReader[i][j] = lineCount1;
                else lineReader[i][j] = lineCount2;
            }
        }

        // LINE SIMILARITY CHECKER
        for(int i = 0; i <= fileCount-1; i++){
            for(int j = 0; j <= fileCount-1; j++){
                //System.out.println("\nFILE " + i + " vs " + j);
                lineCount1 = 0;
                while (lineCount1 < lineReader[i][j]){
                    lineCount1++;
                    lineCount2 = 0;
                    while(lineCount2 < lineReader[i][j]){
                        lineCount2++;
                        if (lineStorage1[i][lineCount1].equals(lineStorage2[j][lineCount2])) {
                            //System.out.print("FOUND!");
                            similarityCount[i][j]++;
                            break;
                        }
                    }
                }
            }
        }

        // SEARCH FOR THE LONGEST LINE SIMILARITY
        for(int i = 0; i <= fileCount-1; i++){
            for(int j = 0; j <= fileCount-1; j++){
                bFile1 = new BufferedReader(new FileReader(filePath[i]));
                bFile2 = new BufferedReader(new FileReader(filePath[j]));
                while (((line1 = bFile1.readLine()) != null) && ((line2 = bFile2.readLine()) != null)) {
                    lineCount = 0;
                    lineCount = lineCount + 1;

                    line1SansSpaces = line1.replaceAll("\\s+","");
                    line2SansSpaces = line2.replaceAll("\\s+","");

                    if (line1SansSpaces.toLowerCase().equals(line2SansSpaces.toLowerCase())) {
                        if(!filePath[i].equals(filePath[j])){
                            currentCharacterCount = 0;
                            for(int k = 0; k < line1SansSpaces.length(); k++) {
                                currentCharacterCount++;
                            }
                            if (currentCharacterCount > longestCharacterCount){
                                longestCharacterCount = currentCharacterCount;
                                longestLine = line1;
                                longestLineFile1 = filePath[i];
                                longestLineFile2 = filePath[j];
                                longestLineNum = lineCount;
                            }
                        }
                    }
                }
            }
        }

        /*
        ========================
            OUTPUTS
        ========================
         */

        double[][] similarityIndex = new double[200][200];

        System.out.println("\nSimilarity index matrix");
        for(int i = 0; i <= fileCount-1; i++){
            for(int j = 0; j <= fileCount-1; j++){
                similarityIndex[i][j] = similarityCount[i][j] / lineReader[i][j];
                System.out.print(df.format(similarityIndex[i][j]) + " ");
            }
            System.out.print("\n");
        }

        longestLineFile1 = longestLineFile1.replace("assets\\Submissions\\","");
        longestLineFile2 = longestLineFile2.replace("assets\\Submissions\\","");

        System.out.println("\nLongest String Similarity: " + longestLine);
        System.out.println("Found in Files: " + longestLineFile1 + "\t\tAND\t\t" + longestLineFile2);
        System.out.println("Found in Line: " + longestLineNum);

        // THE PROGRAM COMPARES 102 FILES

        bFile1.close();
        bFile2.close();
    }

    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);
        System.out.println("[1] Teddy's MOSS");
        System.out.println("[2] Joseph's MOSS");
        System.out.print(">> ");
        int choice = input.nextInt();
        switch(choice){
            case 1:
                teddy();
                break;
            case 2:
                portu();
                break;
            default:
                System.out.println("Invalid input. The program will now stop.");
        }
    }
}
