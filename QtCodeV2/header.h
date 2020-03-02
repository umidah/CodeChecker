#pragma once

#include "includes.h"

using namespace std;


class wordAmount{
public:

    //Kyle's stuff
    string line;
    queue<string> qLine;
    queue<string> qPrint;
    int count = 0, commentloc, linelength;
    bool comment;

    void loadFileKyle(string path){
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

    float testCode(wordAmount a){
        float testTotal;
        float sameTotal;
        float average;
        int same = 0;
        auto x = this->qLine;
        auto y = a.qLine;
        while(!x.empty()&&!y.empty()){
            if(x.front()==y.front()){
                same++;
            }
            x.pop();
            y.pop();
        }
        testTotal=this->count+a.count;
        sameTotal=same*2;
        average=(sameTotal/testTotal);
        return average;
    }

    //Parco's Stuff
    struct wordCount{
        string word;
        int count = 0;
    };

    vector<string> currentWords;
    vector<wordCount> currentWordsAmount;
    vector<string> currentWordsRepeat;
    vector<string> lines;
    vector<float> lineDiff;
    string entireThing;

    void insertWord(string word){
        auto it = find(currentWords.begin(), currentWords.end(), word);
        int dist = distance(currentWords.begin(), it);
        if(it != currentWords.end()){
            currentWordsAmount[dist].count++;
        }
        else{
            wordCount word2;
            word2.count++;
            word2.word = word;
            currentWords.push_back(word);
            currentWordsAmount.push_back(word2);
        }
        currentWordsRepeat.push_back(word);
    }

    /*
    void printWords(){
        int x, n;
        n = currentWords.size();
        for(x = 0; x < n; x++){
            cout << currentWords[x] << "\t" << currentWordsAmount[x].count << endl;
        }
        cout << endl;
    }
    */

    string loadFile(string filename){
        ifstream file(filename);
        string line;
        string substring1;
        bool block=false;
        int x;
        entireThing = "";
        if(!file.is_open()) return "";
        while(!file.eof()){
            file >> line;
            /*
            for(x = 0; line.at(x) != '\n'; x++){
                    if(line.at(x) != ' ' && line.at(x) != '\t') break;
            }
            if(x == line.size()) continue;
            if(line.size() == 0) continue;
            if(line.at(x) == '\n') continue;
            if(line.at(x) == '/'){
                if (line.at(x+1) == '*') block = true;
                continue;
            }
            if(line.at(x) == '*'){
                block  = false;
                continue;
            }
            if(block) continue;
            if(line.size() > 0) substring1 = line.substr(x, line.size());
            else substring1 = "";
            */
            //cout << "thing" << endl;
            substring1 = line;
            this->insertWord(substring1);
            entireThing += substring1;
        }
        file.close();
        return entireThing;
    }

    void loadFileLines(string filename){
        ifstream file(filename);
        string line, substring1;
        if(!file.is_open()) return;
        while(!file.eof()){
            getline(file, line, '\n');
            substring1 = line;
            lines.push_back(substring1);
        }
        file.close();
    }

    void loadFileDebug(string filename){
        ifstream file(filename);
        string word;
        while(!file.eof()){
            file >> word;
            this->insertWord(word);
            //this->printWords();
        }
        file.close();
    }

    int size(){
        return currentWordsRepeat.size();
    }

    int getStringValue(string word){
        int s = word.size();
        int amt = 0;
        const char* cstr = word.c_str();
        for(int x = 0; x < s; x++){
            amt = amt + cstr[x];
        }
        return amt;
    }

    int vecStringValue(){
        int x, n;
        vector<wordCount> temp = this->currentWordsAmount;
        sort(temp.begin(), temp.end(), [](wordCount a, wordCount b){
                return a.word > b.word;
            }
        );
        n = temp.size();
        string str;
        int amt = 0;
        int curr;
        for(x = 0; x < n; x++){
            str = temp[x].word;
            curr = this->getStringValue(str);
            curr = curr*temp[x].count;
            amt = amt + curr;
        }
        return amt;
    }

    int wordSimilarity(wordAmount comp){
        int count = 0;
        auto a = this->currentWordsRepeat;
        auto b = comp.currentWordsRepeat;
        int size = a.size();
        if(a.size() > b.size()) size = b.size();
        for(int x = 0; x<size; x++){
            if(a[x].compare(b[x])==0) count++;
        }
        return count;
    }

    float getLineDiff(wordAmount comp){
        auto a = this->lines;
        auto b = comp.lines;
        int size = a.size();
        float diff=0.f;
        float avg, pDiff, pDiffAvg, pDiffTotal = 0.f;
        if(a.size() > b.size()) size = b.size();
        for(int x = 0; x<size; x++){
            diff = getStringValue(a[x])-getStringValue(b[x]);
            avg = (getStringValue(a[x])+getStringValue(b[x]))/2;
            pDiff = diff/avg;
            lineDiff.push_back(pDiff);
            pDiffTotal=pDiffTotal+pDiff;
        }
        pDiffAvg = pDiffTotal/(float)size;
        return pDiffAvg;
    }
};

class wordAmountArr{
private:
    vector<string> allDirs;
    vector<wordAmount> data;

public:
    float** matrix;
    int matrixSize = 0;

    void push(wordAmount& a){
        this->data.push_back(a);
    }

    string getDir(int at){
        return allDirs[at];
    }

    void pushFile(string path){
        wordAmount temp;
        temp.loadFile(path);
        temp.loadFileLines(path);
        this->data.push_back(temp);
    }

    wordAmount at(int x){
        return data[x];
    }

    void comparisonMatrix(){
        wordAmount temp;
    }

    wordAmount &operator[] (int ind){
        if(ind >= 0 && ind < data.size()) return data[ind];
    }

    void deleteMatrix(){
        for(size_t i = 0; i<this->matrixSize; i++){
                delete[] matrix[i];
        }
        delete[] matrix;
        this->matrixSize = 0;
    }

    void makeMatrix1(){
        if(this->matrixSize != 0) deleteMatrix();
        int a, b, diff;
        wordAmount *temp;
        size_t size = this->data.size();
        this->matrixSize = size;
        this->matrix = new float*[size];
        for(size_t i = 0; i< size; i++){
            this->matrix[i] = new float[size];
            temp = &this->data[i];
            a = temp->vecStringValue();
            for(size_t j = 0; j < size; j++){
                b = this->data[j].vecStringValue();
                if(a < b) diff = a;
                else diff = b;
                if(diff < 0.f) diff = -diff;
                this->matrix[i][j] = 2*(getPercentDiff(a, b, diff)-0.5);
            }
        }
    }

    void makeMatrix2(){
        if(this->matrixSize ==0) deleteMatrix();
        float a;
        wordAmount *temp;
        size_t size = this->data.size();
        this->matrix = new float*[size];
        this->matrixSize = size;
        for(size_t i = 0; i< size; i++){
            this->matrix[i] = new float[size];
            temp = &this->data[i];
            for(size_t j = 0; j < size; j++){
                a = temp->getLineDiff(this->data[j]);
                if(a < 0) a = -a;
                this->matrix[i][j] =2*(0.5-a);
            }
        }
    }

    void makeMatrix3(){
        if(this->matrixSize ==0) deleteMatrix();
        float a;
        wordAmount *temp;
        size_t size = this->data.size();
        this->matrix = new float*[size];
        this->matrixSize = size;
        for(size_t i = 0; i< size; i++){
            this->matrix[i] = new float[size];
            temp = &this->data[i];
            for(size_t j = 0; j < size; j++){
                a = temp->testCode(this->data[j]);
                if(a < 0) a = -a;
                this->matrix[i][j] =(a);
            }
        }
    }

    float** getMatrix(){
        return this->matrix;
    }


    /*
    void printMatrix(){
        char fill = ' ';
        int base = 5;
        size_t size = this->data.size();
        cout << "\t";
        for(size_t i = 0; i< size; i++) cout << i << "\t";
        cout << endl;
        for(size_t i = 0; i< size; i++){
            //cout << "|";
            cout << i << "\t";
            for(size_t j = 0; j< size; j++){
                cout << fixed << setprecision(1) << setbase(base) << setfill(fill);
                cout << this->matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
    */

    float getPercentDiff(int a, int b, int diff){
        float avg = ((float)a+(float)b)/2;
        float fDiff = (float) diff;
        return fDiff/avg;
    }

    void addDir(string directory){
        DIR *dir;
        struct dirent *ent;
        char *temp;
        string all = "";
        vector<string> allLines;
        queue<string> qLine;
        int count;
        qDebug() << QString::fromStdString(directory);
        allDirs.push_back(directory);
        if((dir = opendir(directory.c_str())) != nullptr){
            qDebug("start");
            while ((ent = readdir (dir)) != nullptr) {
                qDebug("Start file");
                temp = ent->d_name;
                qDebug() << QString::fromLocal8Bit(temp);
                string str(temp);
                if(str.at(0)!='.'){
                    string tempDir = directory+"/"+str;
                    qDebug() << QString::fromStdString(tempDir) << endl;
                    wordAmount temp;
                    all += temp.loadFile(tempDir);
                    qDebug() << QString::fromStdString(all);
                    //cout << 1;
                    temp.loadFileLines(tempDir);
                    //cout << 2;
                    temp.loadFileKyle(tempDir);
                    //cout << 3;
                    qLine = temp.qLine;
                    //cout << 4;
                    count = temp.count;
                    //cout << 5;
                    allLines.insert(allLines.end(), temp.lines.begin(), temp.lines.end());
                    //cout << 6 << endl;
                }
                qDebug("End file");
            }
            qDebug("end");
            closedir (dir);
        }
        wordAmount temp2;
        temp2.insertWord(all);
        temp2.entireThing = all;
        temp2.qLine = qLine;
        temp2.count = count;
        temp2.lines = allLines;
        this->push(temp2);
    }

    void loadSuperDir(string superDir){
        DIR *dir;
        dirent *ent;
        char *temp;
        qDebug() << QString::fromStdString(superDir);
        if((dir = opendir(superDir.c_str())) != nullptr){
            qDebug("start");
            while((ent = readdir(dir)) != nullptr){
                qDebug("Start dir");
                if(ent->d_name[0]=='.'){
                    qDebug("skip");
                    continue;
                }
                temp = ent->d_name;
                qDebug() << QString::fromLocal8Bit(temp);
                string str(temp);
                //qDebug()<<QString::fromStdString(str);
                //cout << superDir+str+"/" << endl;
                addDir(superDir+"/"+str);
                qDebug("End dir");
            }
            qDebug("end");
            closedir(dir);
        }
        /*
        QString QsuperDir = QString::fromStdString(superDir);
        qDebug() << QsuperDir;
        QDir superDirectory(QsuperDir + "/");
        qDebug() << superDirectory.filePath("angel-parco");
        superDirectory.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
        if(!superDirectory.exists()) qDebug() << "File or Directory does not exist";
        QStringList list = superDirectory.entryList();
        qDebug() << superDirectory << endl << list;
        foreach (QString folder, list) {
            qDebug() << folder;
        }
        */
    }
};
