#include <iostream>
//fstream is a stream class to both read and write from/to files.
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;

main(){
	string line1[50];
	string line2[50];
	string line3[50];
	string line4[50];
	string first;
	string second;
	string third;
	string fourth;
	
	ifstream file1;
	ifstream file2;
	ifstream file3;
	ifstream file4;
	
	//first program to read
	file1.open("prog1.cpp", ios::in);
	//ios::in is opening a file for input operations
	int a=0;
	if(file1.is_open()){
		cout<<"prog1.cpp opened."<<'\n';
		while(getline(file1, first)){
			cout<<first<<'\n';
			line1[a] = first;
			a++;
		}
		file1.close();
	}
	else cout<<"Unable to open file";
	
	//second program to read
	file2.open("prog2.cpp", ios::in);
	//ios::in is opening a file for input operations
	int b=0;
	if(file2.is_open()){
		cout<<"\nprog2.cpp opened."<<'\n';
		while(getline(file2, second)){
			cout<<second<<'\n';
			line2[b] = second;
			b++;
		}
		file2.close();
	}
	else cout<<"Unable to open file";
	
	//comparing both programs
	int counter1=0, i=0;
	float total1 = a+b, different1=0;//checkers
	float percent1=0;
	if(a>b){
		for(i=0; i<a; i++){
			if(line1[i]==line2[i]) continue;
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
		for(i=0; i<b; i++){
			if(line1[i]==line2[i]) continue;
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
	
	
	/*************************************************/
	
	//first java program to read
	file3.open("prog1.java", ios::in);
	//ios::in is opening a file for input operations
	int c=0;
	if(file3.is_open()){
		cout<<"\nprog1.java opened."<<'\n';
		while(getline(file3, third)){
			cout<<third<<'\n';
			line3[c] = third;
			c++;
		}
		file3.close();
	}
	else cout<<"Unable to open file";
	
	//second java program to read
	file4.open("prog2.java", ios::in);
	//ios::in is opening a file for input operations
	int d=0;
	if(file4.is_open()){
		cout<<"\nprog2.java opened."<<'\n';
		while(getline(file4, fourth)){
			cout<<fourth<<'\n';
			line4[d] = fourth;
			d++;
		}
		file4.close();
	}
	else cout<<"Unable to open file";
	
	//comparing both programs
	int counter2=0, j=0;
	float total2 = c+d, different2=0;//checkers
	float percent2=0;
	if(c>d){
		for(j=0; j<c; j++){
			if(line3[j]==line4[j]) continue;
			else{
				counter2++;
			}
		}
		different2 = total2 - counter2;
		percent2=(different2/total2)*100;
		cout<<"\nSimilarity Percentage:";
		std::cout << std::fixed << std::setprecision(2) << percent2;
		cout<<'\n';
	}
	else{
		for(j=0; j<d; j++){
			if(line3[j]==line4[j]) continue;
			else{
				counter2++;				
			}
		}
		different2 = total2 - counter2;
		percent2=(different2/total2)*100;
		cout<<"\nSimilarity Percentage:";
		std::cout << std::fixed << std::setprecision(2) << percent2;
		cout<<'\n';
	}
	
	return 0;
}

//reference: http://www.cplusplus.com/doc/tutorial/files/
