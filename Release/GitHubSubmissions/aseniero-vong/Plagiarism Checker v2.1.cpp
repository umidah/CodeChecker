#include <iostream>
#include <string.h>
#include <dirent.h>

//This is the updated version of the Plagiarism Checker v2
//The changes here include the fix for the trapping for my .exe file
//Instead of having the exact file numbering in the list be hard coded, the file name instead will be used and be skipped over
//If the code should read the said name like in Line 60.

//The code also is arranged more neatly where the names of the code owners are seen in the left side of the screen.

//Furthermore, the comparison and printing part of the code has been turned into a function instead of having everything cluttered into
//The main() function.


using namespace std;

double comparison(string con1[], string con2[]){
	
	double equalcounter = 0;
	double notequalcounter = 0;
	
	for (int i = 0; i < 1000; i++){
		int g = equalcounter;
		if (con1[i] == ""){
			continue;
		}
		for (int j = 0; j < 1000; j++){
			if (con1[i] == con2[j]){
				equalcounter++;
				break;
			}
		}
		if (g == equalcounter){
			notequalcounter++;
		}
	}
	
	double total = equalcounter + notequalcounter;
	
	double compare = equalcounter / total * 100;
	
	return compare;
			
}

int main(){
	
	struct dirent *dc;
	string file[100] = "";
	int count = 0;
	
	DIR *de = opendir(".");

    while ((dc = readdir(de)) != NULL){
    	file[count] += dc->d_name; 
    	count++;
	}
    closedir(de); 
	
	char ch, file1[50], file2[50];
	FILE *fp;
	
	for (int i = 2; i < 39; i++){
		if (file[i] == "JM.exe"){
			continue;
		}

		else{
			printf("%16s",file[i].c_str());
		}
		for (int j = 2; j < 39; j++){
			if (file[j] == "JM.exe"){
				continue;
			}

			string content1[1000] = "", content2[1000] = "";
			
			strcpy(file1, file[i].c_str());
			
			fp = fopen(file1, "r");
			
			int c = 0;
			while ((ch = fgetc(fp)) != EOF){
				if (ch == '\n' || ch == '  '){
					c++;
					continue;
				}
				else{
					content1[c] += ch;
				}
			}
			
			fclose(fp);
			
			strcpy(file2, file[j].c_str());
			fp = fopen(file2,"r");
			c = 0;
			while ((ch = fgetc(fp)) != EOF){
				if (ch == '\n' || ch == '  '){
					c++;
					continue;
				}
				else{
					content2[c] += ch;
				}
			}
	
			fclose(fp);

			printf("%4.0f ",comparison(content1,content2));
		}
		cout << endl;
	}
}
