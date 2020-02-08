#include <iostream>
#include<fstream>
#include<queue>
using namespace std;


int main(){
    fstream reader;
    queue<string> qreader;
    string line,check;
    int linelength,cmtloc,colonloc;
    bool comment,colontrue;
    int stringcount=0,coloncount=0,dotcount=0,equalcount=0;
    int less2xcount=0,lesscount=0,more2xcount=0,morecount=0;
    int arrowcount=0,forcount=0,found=0,bracketcount=0;
    int pluscount=0,pluspluscount=0,returncount=0,intcount=0;



    reader.open("filestoread/header.h");
    if(reader.is_open()){
        while(!reader.eof()){
            getline(reader,line);
            linelength=line.size();
            if (!line.empty()){
                if (!line.compare("\t")==0){
                if (line.at(0)!='/') {

                    for(int i=0;i<linelength;i++){

                            if (line.at(i)==';') colonloc=i;
                            if(line.at(i)=='/'&&i<colonloc){

                                cmtloc=i;
                                comment=true;
                                break;
                            }


                        else{
                                comment=false;
                            }
                            colonloc=0;
                    }
                    if(comment){
                        if (line.at(cmtloc-1)==' '){
                            line.erase(cmtloc-1,linelength);
                            qreader.push(line);
                        }
                        else{
                            line.erase(cmtloc-1,linelength);
                            qreader.push(line);                        }
                    }
                    else qreader.push(line);
                }

            }
            }

    }
    reader.close();
    }

    else cout<<"File not Found!\n";
/*
    queue<string> qprint;
    qprint=qreader;
    while(!qprint.empty()){
        cout<<qprint.front()<<"\n";
        qprint.pop();
    }
*/

    while(!qreader.empty()){
        check=qreader.front();
        linelength=check.length();
        for(int i=0;i<linelength;i++){
            if (check.at(i)==';'){
                coloncount++;
            }
            else if(check.at(i)=='s'){
                if(check.at(i+1)=='t'){
                    if(check.at(i+2)=='r'){
                        if(check.at(i+3)=='i'){
                            if(check.at(i+4)=='n'){
                                if(check.at(i+5)=='g'){
                                    if(check.at(i-1)!='(')
                                        stringcount++;

            }
            }
            }
            }
            }
            }
            else if(check.at(i)=='+'){
                pluscount++; //gets + and ++
                found=check.find("++"); //only gets ++
                if (found==i) pluspluscount++;
            }
            else if(check.at(i)=='f'){

                    found=check.find("for");
                    if(found==i) forcount++;

            }
            else if(check.at(i)=='r'){
                found=check.find("return");
                if(found==i) returncount++;
            }
            else if(check.at(i)=='>'){
                morecount++; //gets > and >>
                found=check.find(">>"); //only gets >>
                if(found==i) more2xcount++;
            }

            else if(check.at(i)=='-'){
                found=check.find("->");
                if(found==i) arrowcount++;
            }

            else if(check.at(i)=='.'){
                dotcount++;
            }
            else if(check.at(i)=='='){
                equalcount++;
            }
            else if(check.at(i)=='<'){
                if(check.at(i+1)!='<'&&check.at(i-1!='<')){
                    lesscount++;
                }
                else less2xcount++;
            }
            else if(check.at(i)=='{'){
                bracketcount++;
            }
            else if(check.at(i)=='i'){
                found=check.find("int");
                if (found==i) intcount++;
            }



        }
        qreader.pop();
    }

    morecount=morecount-more2xcount; //removes the >> found in morecount
    pluscount=pluscount-pluspluscount; //removes the ++ found in pluscount
    cout<<"String count: "<<stringcount<<"\n";
    cout<<"; count: "<<coloncount<<"\n";
    cout<<". count: "<<dotcount<<"\n";
    cout<<"= count: "<<equalcount<<"\n";
    cout<<"< count: "<<lesscount<<"\n";
    cout<<"<< count: "<<less2xcount<<"\n";
    cout<<">> count: "<<more2xcount<<"\n";
    cout<<"> count: "<<morecount<<"\n";
    cout<<"for count: "<<forcount<<"\n";
    cout<<"-> count: "<<arrowcount<<"\n";
    cout<<"+ count: "<<pluscount<<"\n";
    cout<<"++ count: "<<pluspluscount<<"\n";
    cout<<"return count: "<<returncount<<"\n";
    cout<<"{} count: "<<bracketcount<<"\n";
    cout<<"int count: "<<intcount<<"\n";




}
