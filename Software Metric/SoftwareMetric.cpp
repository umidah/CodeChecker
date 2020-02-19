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
    int arrowcount=0,forcount=0,found=0,bracketcount=0,icount=0;
    int pluscount=0,pluspluscount=0,returncount=0,intcount=0;
    int doubleampcount=0, ifcount=0, commacount=0, minuscount=0;
    int mplycount=0,notequalcount=0,notcount=0,orcount=0;
    int ampcount=0;

    int operandcount;


    /*
    string linelengtht = "linelength";
    string linet ="line";
    int linetest=0;
    int linelengthtest=0;
*/

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

    cout<<"Enter number of operands to find: ";
    cin>>operandcount;
    string operands[operandcount];
    int operandtotal[operandcount];
    for (int i=0;i<operandcount;i++){
         operandtotal[i]=0;
    }

    for (int i=0;i<operandcount;i++){
        cout<<"operand #"<<i+1<<": ";
        cin>>operands[i];
    }
    cout<<"\n\n";
/*
    queue<string> qprint;
    qprint=qreader;
    while(!qprint.empty()){
        cout<<qprint.front()<<"\n";
        qprint.pop();
    }
*/
    queue<string> qoperand = qreader;

    for (int i=0;i<operandcount;i++){
        while(!qoperand.empty()){
            check=qoperand.front();
            found=check.find(operands[i]);
            if (found!=-1) operandtotal[i]++;
            qoperand.pop();
        }
    qoperand=qreader;
}

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
/*
            else if(check.at(i)=='l'){
                found=check.find(linet);
                if(found==i) linetest++;
                else {
                    found=check.find(linelengtht);
                    if(found==i) linelengthtest++;
                }
            }
*/
            else if(check.at(i)=='>'){
                morecount++; //gets > and >>
                found=check.find(">>"); //only gets >>
                if(found==i) more2xcount++;
            }

            else if(check.at(i)=='-'){
                minuscount++; //gets - and ->
                found=check.find("->"); //only gets ->
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
                else{ found=check.find("if");
                if (found==i) ifcount++;

                }
            }
            else if(check.at(i)=='&'){
                ampcount++;
                found=check.find("&&");
                if (found==i) doubleampcount++;
            }

            else if(check.at(i)==','){
                commacount++;
            }

            else if(check.at(i)=='*'){
                mplycount++;
            }

            else if(check.at(i)=='!'){
                notcount++; //gets all !
                found=check.find("!=");
                if (found==i) notequalcount++;
            }

            else if(check.at(i)=='|'){
                found=check.find("||");
                if (found==i) orcount++;
            }







        }
        qreader.pop();
    }

    morecount=morecount-more2xcount; //removes the >> found in morecount
    pluscount=pluscount-pluspluscount; //removes the ++ found in pluscount
    minuscount=minuscount-arrowcount; //removes -> found in minuscount
    icount=icount-(ifcount+intcount);
    notcount=notcount-notequalcount;
    ampcount=ampcount-doubleampcount;

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
    cout<<"&& count: "<<doubleampcount<<"\n";
    cout<<"if count: "<<ifcount<<"\n";
    cout<<", count: "<<commacount<<"\n";
    cout<<"- count: "<<minuscount<<"\n";
    cout<<"[] count: "<<bracketcount<<"\n";
    cout<<"multiply count: "<<mplycount<<"\n";
    cout<<"! count: "<<notcount<<"\n";
    cout<<"!= count: "<<notequalcount<<"\n";
    cout<<"|| count: "<<orcount<<"\n";
    cout<<"& count: "<<ampcount<<"\n";

    cout<<"\n\n";

    cout<<"Operand Total:\n";

    for(int i=0;i<operandcount;i++){
        cout<<operands[i]<<" count: "<<operandtotal[i]<<"\n";
    }




   // cout<<"Test line: "<<linetest<<"\n";
    //cout<<"Test linelength: "<<linelengthtest<<"\n";



}
