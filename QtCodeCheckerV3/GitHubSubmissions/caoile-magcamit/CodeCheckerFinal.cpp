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
    DIR *folder;
    struct dirent *entry;
    int fileCount=0;
    string file[100] = "";

	//this opens the folder where this file is saved
    folder = opendir(".");
    if(folder == NULL){
        perror("Unable to read directory");
        return 1;
    }

    while(entry=readdir(folder)){
    	file[fileCount] += entry->d_name; 
		fileCount++;
    }
    closedir(folder);
    
    //this starts at 2 because the first two files from the directory are only period
    
	char file1[1000];
	char file2[1000];
	int a=0;
	int b=0;
	
	
	for(int i=2; i<11; i++){
		for(int j=2; j<11; j++){
			strcpy(file1, file[i].c_str());
			ifstream inFile(file1);
			string line1[10000];
			string line2[10000];
			
			if(inFile.is_open()){
				while(!inFile.eof()){
					getline(inFile, line1[a], '\n');
					cout<<line1[a]<<'\n';
					a++;
				}
				inFile.close();
			}
		
			cout<<"\n";
			
			strcpy(file2, file[j].c_str());
			ifstream inFile2(file2);
			if(inFile2.is_open()){
				while(!inFile2.eof()){
					getline(inFile2, line2[b], '\n');
					cout<<line2[b]<<'\n';
					b++;
				}
				inFile2.close();
			}
			
			int counter1=0;
			float total1 = a+b, different1=0;//checkers
			float percent1=0;
		
			if(a>b){
				for(int x=0; x<a; x++){
					if(line1[x]==line2[x]) continue;
					else{
						counter1++;
					}
				}
				different1 = total1-counter1;
				percent1=(different1/total1)*100;
				cout<<"\nSimilarity Percentage:";
				std::cout << std::fixed << std::setprecision(2) << percent1;
				cout<<'\n';
			}
			else{
				for(int x=0; x<b; x++){
					if(line1[x]==line2[x]) continue;
					else{
						counter1++;
					}
				}
				different1 = total1-counter1;
				percent1=(different1/total1)*100;
				cout<<"\nSimilarity Percentage:";
				std::cout << std::fixed << std::setprecision(2) << percent1;
				cout<<'\n';
			}
			cout<<"\n\nNEXT FILE!!\n\n";
		}	
	}
	
    return 0;
}
