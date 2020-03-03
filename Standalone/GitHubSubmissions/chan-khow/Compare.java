package Algorithms;

import java.text.DecimalFormat;

public class Compare {
    private static DecimalFormat two_point = new DecimalFormat("#,##0.00");


    public static void main(String[] args) {
        double [][]correlation_matrix;
        int count=0;
        Read file = new Read();
        Directory_checker dir= new Directory_checker();
        count = dir.count_files();
        correlation_matrix=file.read_files(".java");
        for(int i=0; i<count; i++){
            for(int j=0; j<count; j++){
                    System.out.print(two_point.format(correlation_matrix[i][j])+"\t");
                }
            System.out.println();
        }
    }
}