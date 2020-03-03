import org.apache.poi.xssf.usermodel.XSSFRow;
import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;


import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class CompareCode {
    ArrayList<String> codes = new ArrayList<>();
    int count = 0;
    String filename = "grades.txt";

    public static void main(String[] args) throws IOException {
        /*
        String file1 = "C:\\Users\\11812508\\IdeaProjects\\Module0\\test_program1.java";
        String file2 = "C:\\Users\\11812508\\IdeaProjects\\Module0\\test_program2.java";
        BufferedReader reader1 = new BufferedReader(new FileReader(file1));
        BufferedReader reader2 = new BufferedReader(new FileReader(file2));
        int i=0;
        int score=0;

        StringBuilder code1 = new StringBuilder();
        StringBuilder code2 = new StringBuilder();
        String line1 = "";
        String line2 = "";
        while(((line1=reader1.readLine())!=null)&&((line2=reader2.readLine())!=null)){
            if(line1.equals(line2)){
                score++;
            }
            i++;
        }
        double grade = (Double.valueOf(score)/Double.valueOf(i-1))*100;
        System.out.println("Programs are " + (int)grade + "% similar!");
        if(grade>=70){
            System.out.println("Programs are plagiarized");


        }

         */
        CompareCode c = new CompareCode();
        c.run();
    }

    private void run() throws IOException {
        getFilenames();/*
        Scanner myObj = new Scanner(System.in);
        System.out.println("Enter name of file to compare with: ");
        String filename = myObj.nextLine();
        */
        String myFile;
        String filename;

        System.out.println();


        for(int i=0; i<codes.size();i++){
            for(int j=0; j<codes.size(); j++){
                compareFiles(i, j, codes.get(i), codes.get(j));
            }
            System.out.println();
        }

        //compareFiles(0, 0, "Teddy_main.java", "Rhennie_main.cpp");
    }

    private void getFilenames(){
        File folder = new File("C:\\Users\\Lenard Llarenas\\IdeaProjects\\CP2Dcourse\\Module1\\Submissions");
        File[] fileList = folder.listFiles();
        System.out.println("Available files: ");
        for(int i = 0; i<fileList.length; i++){
            System.out.println(fileList[i].getName());
            codes.add(fileList[i].getName());
        }
    }

    private void compareFiles(int x, int y, String thisfile, String comparefile) throws IOException {

            String file1 = "C:\\Users\\Lenard Llarenas\\IdeaProjects\\CP2Dcourse\\Module1\\Submissions\\" + thisfile;
            String file2 = "C:\\Users\\Lenard Llarenas\\IdeaProjects\\CP2Dcourse\\Module1\\Submissions\\" + comparefile;
            /*
            if (!codes.get(count).equals(myFile)) {
                file2 = "C:\\Users\\Lenard Llarenas\\IdeaProjects\\CP2Dcourse\\Module1\\Submissions\\" + codes.get(count);
            } else
                file2 = "C:\\Users\\Lenard Llarenas\\IdeaProjects\\CP2Dcourse\\Module1\\Submissions\\" + codes.get(count + 1);

             */
            InputStream firstFile = new FileInputStream(file1);
            InputStream secondFile = new FileInputStream(file2);
            BufferedReader reader1 = new BufferedReader(new InputStreamReader(firstFile));
            BufferedReader reader2 = new BufferedReader(new InputStreamReader(secondFile));
            int i = 0;
            double score = 0;
            double avg;
            double grade;

            StringBuilder code1 = new StringBuilder();
            StringBuilder code2 = new StringBuilder();
            String line1 = "";
            String line2 = "";
            int lineCount1 = 0;
            int lineCount2 = 0;
            while((line1=reader1.readLine())!=null){
                if((!line1.equals(""))&&(!line1.equals("\t"))&&(!line1.contains("}"))&&(!line1.equals("{"))) {
                    line1 = line1.replaceAll("\\s+","");
                    //line1 = line1.replace("\n", "");
                    lineCount1++;
                    //System.out.println("Iteration " + i);
                    //System.out.println(line1);
                    while ((line2 = reader2.readLine()) != null) {
                        if ((!line2.equals(""))&&(!line2.equals("\t"))&&(!line2.contains("}"))&&(!line2.equals("{"))) {
                            line2 = line2.replaceAll("\\s+","");
                            //line2 = line2.replace("\n", "");
                            //System.out.println(line2);
                            if(lineCount1==1) lineCount2++;
                            if ((line1.equals(line2))) {
                                //System.out.println(line1);
                                score++;
                                //System.out.println(score);
                            }
                        }
                    }
                    reader2 = new BufferedReader(new FileReader(file2));
                    i++;
                }
            }

            /*
            System.out.println(score);
            System.out.println(lineCount1);
            System.out.println(lineCount2);

             */


            avg = (lineCount1+lineCount2)/2;
            if(score>avg) grade = 100;
            else grade = (score/avg)*100;
            System.out.println(thisfile + " - " + comparefile);
            System.out.println("  The programs are " + (Math.round(grade * 100.0) / 100.0) + "% similar!");
            //compareFiles();
            //writeToFile(thisfile, y, grade);

    }

    public void writeToFile(String name, int count, double grade) throws IOException {
        /*
        FileInputStream myXLSXFile = new FileInputStream("CorrelationMatrix.xlsx");

        XSSFWorkbook wBook = new XSSFWorkbook(myXLSXFile);

        XSSFSheet wSheet = wBook.getSheetAt(0);

        XSSFRow row = wSheet.createRow(i+1);
        row.createCell(j).setCellValue(grade);

        myXLSXFile.close();

        FileOutputStream output_file = new FileOutputStream(new File("CorrelationMatrix.xlsx"));
        wBook.write(output_file);
        output_file.close();


        FileWriter fw = new FileWriter(file);
        String newLine = System.getProperty("line.separator");
        BufferedWriter bw = new BufferedWriter(fw);
        if(count==34){
            bw.write(String.valueOf(grade/100) + newLine);
            bw.write("");
        }
        else bw.write(String.valueOf(grade/100) + newLine);
        bw.close();

         */

        FileWriter fw = new FileWriter(filename,true);
        BufferedWriter bw=new BufferedWriter(fw);
        PrintWriter out = new PrintWriter(bw);

        if(count==0) {
            out.write(name + "\n");
        }
        if(count==34){
            out.write(String.valueOf(grade/100) + "\n");
            out.write("\n\n");
        }
        else out.write(String.valueOf(grade/100) + "\n");
        out.close();
    }
}
