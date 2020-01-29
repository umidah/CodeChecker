#include <iostream>
#include<fstream>
#include<string>
#include<queue>
using namespace std;

class test{
public:
    string line;
    queue<string> qLine;
    queue<string> qPrint;
    int count = 0, commentloc, linelength, same = 0;
    float testTotal = 0;
    float sameTotal = 0;
    float average = 0;
    bool comment;

    void loadFile(string path){
        ifstream file(path);
        if (file.is_open()){
            while(!file.eof()){
                getline(file,line);
                linelength=line.size();
                if (!line.empty()) {
                    if(!line.compare("\t")==0) {
                        if (line.at(0)!='/') {
                            for(int i=0;i<linelength;i++){
                                    //comment=false;
                                    if (line.at(i)=='/'){
                                        commentloc=i;
                                        comment=true;
                                        break;
                                    }
                                    else{
                                            comment=false;
                                    }
                            }
                            if(comment) {
                                if (line.at(commentloc-1)==' '){
                                    line.erase(commentloc-1,linelength);
                                    qLine.push(line);
                                    count++;
                                }
                                else{
                                    line.erase(commentloc,linelength);
                                    qLine.push(line);
                                    count++;
                                }
                            }
                            else{
                                qLine.push(line);
                                count++;
                            }
                        }
                    }
                }
            }
        file.close();
        }
    }

    void testCode(test a){
        while(!this->qLine.empty()&&!a.qLine.empty()){
            if(this->qLine.front()==a.qLine.front()) same++;
            this->qLine.pop();
            a.qLine.pop();
        }
        testTotal=this->count+a.count;
        sameTotal=same*2;
        average=(sameTotal/testTotal)*100;
    }
};


int main(){
    test a, b;
    a.loadFile("test_program1.cpp");
    b.loadFile("test_program2.cpp");
    a.testCode(b);
    /*
	fstream test1;
	fstream test2;
	string line;

	queue<string> qtest1;
	queue<string> qtest2;

	queue<string> test1print;
	queue<string> test2print;


	test1.open("test_program1.cpp");
	test2.open("test_program2.cpp");
//	test1.open("test_program1.java");
//	test2.open("test_program2.java");

	int test1count=0,test2count=0,same=0;
	//int check;
	int linelength,commentloc;
	float average=0;
	float testtotal=0;
	float sametotal=0;
	bool comment;
	//test1.open("test_program1.cpp");
	//qtest1.push("1");
	//qtest1.push("2");



	if (test1.is_open()){
		while(!test1.eof()){
			getline(test1,line);
			linelength=line.size();
			if (!line.empty()) {
				if(!line.compare("\t")==0) {
					if (line.at(0)!='/') {

						for(int i=0;i<linelength;i++){
								//comment=false;
								if (line.at(i)=='/'){
									commentloc=i;
									comment=true;
									break;
								}
								else{
										comment=false;
									//qtest1.push(line);
									//test1count++;
								}
						}

								if(comment) {
										if (line.at(commentloc-1)==' '){
													line.erase(commentloc-1,linelength);
													qtest1.push(line);
													test1count++;
													}
										else{
													line.erase(commentloc,linelength);
													qtest1.push(line);
													test1count++;
										}

								}
								else{
									qtest1.push(line);
									test1count++;
								}



			}

			}

		}
		}
		test1.close();
	}
	else cout<<"test 1 is not opening"<<"\t";


	if (test2.is_open()){
		while(!test2.eof()){
			getline(test2,line);
			linelength=line.size();
			if (!line.empty()) {
				if(!line.compare("\t")==0) {
					if (line.at(0)!='/') {

						for(int i=0;i<linelength;i++){
								//comment=false;
								if (line.at(i)=='/'){
									commentloc=i;
									comment=true;
									break;
								}
								else{
										comment=false;
									//qtest1.push(line);
									//test1count++;
								}
						}

								if(comment) {
										if (line.at(commentloc-1)==' '){
													line.erase(commentloc-1,linelength);
													qtest2.push(line);
													test2count++;
													}
										else{
													line.erase(commentloc,linelength);
													qtest2.push(line);
													test2count++;
										}

								}
								else{
									qtest2.push(line);
									test2count++;
								}



			}

			}

		}
		}
		test2.close();
	}
	else cout<<"test 2 is not opening"<<"\t";


	test1print=qtest1;
	cout<<"Test 1:"<<"\n";
	while(!test1print.empty()){
		cout<<test1print.front()<<"\n";
		test1print.pop();
	}
	cout<<"\n";

	test2print=qtest2;
	cout<<"Test 2:"<<"\n";
	while (!test2print.empty()){
		cout<<test2print.front()<<"\n";
		test2print.pop();
	}

	cout<<"\n";

	while(!qtest1.empty()&&!qtest2.empty()){
		if(qtest1.front()==qtest2.front()) same++;
		qtest1.pop();
		qtest2.pop();
	}


	testtotal=test1count+test2count;
	sametotal=same*2;
	average=(sametotal/testtotal)*100;
	*/
	cout<<"Number of lines in Test 1: "<<a.count<<"\n";
	cout<<"Number of lines in Test 2: "<<b.count<<"\n";
	cout<<"Number of same lines: "<<a.same<<"\n";
	cout<<"Similarity Percentage: "<<a.average<<"%";





}
