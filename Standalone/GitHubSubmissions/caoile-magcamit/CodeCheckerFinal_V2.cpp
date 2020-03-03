/*******************************************

this is the version 2 of the program checker
it prints a correlation matrix for each file

********************************************/

#include <iostream>
//fstream is a stream class to both read and write from/to files.
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <dirent.h>

using namespace std;

int main()
{
    DIR *fold;
    struct dirent *entry;
    int fileCount=0;
    float matrix[100][100];
    string file[100] = "";

	//this opens the folder where this file is saved
    fold = opendir(".");
    if(fold == NULL){
        perror("Unable to read directory");
        return 1;
    }

    while(entry=readdir(fold)){
    	file[fileCount] += entry->d_name; 
		fileCount++;
    }
    closedir(fold);
    
    //this starts at 2 because the first two files from the directory are only period
    
	char file1[1000];
	char file2[1000];
	
	cout<<"Similarity Percentage:\n";
	for(int i=2; i<fileCount; i++){
		for(int j=2; j<fileCount; j++){
			strcpy(file1, file[i].c_str());
			ifstream inFile(file1);
			string line1[100000];
			string line2[100000];
			int a=0;
			int b=0;
			
			if(inFile.is_open()){
				while(!inFile.eof()){
					getline(inFile, line1[a], '\n');
					a++;
				}
				inFile.close();
			}
			
			strcpy(file2, file[j].c_str());
			ifstream inFile2(file2);
			if(inFile2.is_open()){
				while(!inFile2.eof()){
					getline(inFile2, line2[b], '\n');
					b++;
				}
				inFile2.close();
			}
			
			int counter1=0;
			float total1 = a+b, different1=0;//checkers
			float percent1=0;
		
			if(a>b){
				for(int x=0; x<a; x++){
					if (line1[x]==line2[x]) continue;
					else{
						counter1++;
					}
				}
				different1 = total1-counter1;
				percent1=(different1/total1);
				matrix[i][j] = percent1;
			}
			else{
				for(int x=0; x<b; x++){
					if (line1[x] == line2[x]) continue;
					else{
						counter1++;
					}
				}
				different1 = total1-counter1;
				percent1=(different1/total1);
				matrix[i][j] = percent1;
			}
		}	
	}
	
	cout<<'\n';
	
	for(int m=2; m<fileCount; m++){
		for(int n=2; n<fileCount; n++){
			std::cout << std::fixed << std::setprecision(2) << matrix[m][n];
			cout<<"  ";
		}
		cout<<'\n';
	}
	
    return 0;
}
