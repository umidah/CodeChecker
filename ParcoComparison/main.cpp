#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <dirent.h>

using namespace std;


class wordAmount{
public:

    //Kyle's stuff
    string line;
    queue<string> qLine;
    queue<string> qPrint;
    int count = 0, commentloc, linelength, same = 0;
    float testTotal = 0;
    float sameTotal = 0;
    float average = 0;
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

    void testCode(wordAmount a){
        while(!this->qLine.empty()&&!a.qLine.empty()){
            if(this->qLine.front()==a.qLine.front()) same++;
            this->qLine.pop();
            a.qLine.pop();
        }
        testTotal=this->count+a.count;
        sameTotal=same*2;
        average=(sameTotal/testTotal)*100;
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

    void printWords(){
        int x, n;
        n = currentWords.size();
        for(x = 0; x < n; x++){
            cout << currentWords[x] << "\t" << currentWordsAmount[x].count << endl;
        }
        cout << endl;
    }

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
            for(x = 0; line.at(x) != '\n'; x++){
                    if(line.at(x) != ' ' && line.at(x) != '\t') break;
            }
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
            this->insertWord(substring1);
            entireThing += substring1;
        }
        file.close();
        return entireThing;
    }

    void loadFileLines(string filename){
        ifstream file(filename);
        string line, substring1;
        bool block=false;
        int x;
        if(!file.is_open()) return;
        while(!file.eof()){
            getline(file, line, '\n');
            if(line.size() == 0) continue;
            for(x = 0; line.at(x) != '\n'; x++){
                    if(line.at(x) != ' ') break;
            }
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
            this->printWords();
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
    queue<string> allDirs;
    queue<string> currentDir;
    vector<wordAmount> data;
    float** matrix;
    int matrixSize;

public:

    void push(wordAmount& a){
        this->data.push_back(a);
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
        /*
        for(size_t i = 0; i<this->matrixSize; i++){
                delete[] matrix[i];
        }
        */
        delete[] matrix;
        this->matrixSize = 0;
    }

    void makeMatrix1(){
        //if(this->matrixSize ==0) deleteMatrix();
        int a, b, diff;
        wordAmount *temp;
        size_t size = this->data.size();
        cout << size << endl;
        this->matrixSize = size;
        this->matrix = new float*[size];
        for(size_t i = 0; i< size; i++){
            this->matrix[i] = new float[size];
            temp = &this->data[i];
            a = temp->vecStringValue();
            for(size_t j = 0; j < size; j++){
                b = this->data[j].vecStringValue();
                diff = a-b;
                if(diff < 0.f) diff = -diff;
                this->matrix[i][j] = 2*(0.5-getPercentDiff(a, b, diff));
            }
        }
    }

    void makeMatrix2(){
        //if(this->matrixSize ==0) deleteMatrix();
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

    void printMatrix(){
        size_t size = this->data.size();
        for(size_t i = 0; i< size; i++){
            for(size_t j = 0; j< size; j++){
                cout << this->matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    float getPercentDiff(int a, int b, int diff){
        float avg = (a+b)/2;
        float fDiff = (float) diff;
        return fDiff/avg;
    }

    void addDir(string directory){
        DIR *dir;
        struct dirent *ent;
        char *temp;
        string all = "";
        vector<string> allLines;
        allDirs.push(directory);
        if((dir = opendir(directory.c_str())) != NULL){
            while ((ent = readdir (dir)) != NULL) {
                temp = ent->d_name;
                string str(temp);
                if(str.at(0)!='.'){
                    wordAmount temp;
                    all += temp.loadFile(directory+str);
                    temp.loadFileLines(directory+str);
                    allLines.insert(allLines.end(), temp.lines.begin(), temp.lines.end());
                }
            }
            closedir (dir);
        }
        wordAmount temp2;
        temp2.insertWord(all);
        temp2.lines = allLines;
        this->push(temp2);
    }
};

int main()
{
    wordAmountArr temp;
    DIR *dir;
    struct dirent *ent;
    string directory = "filesToRead/0/";
    temp.addDir(directory);
    if((dir = opendir(directory.c_str())) != NULL){
        while ((ent = readdir (dir)) != NULL) {
            if(ent->d_name[0]!='.') cout << directory << ent->d_name << endl;
        }
        closedir (dir);
    }
    directory = "filesToRead/1/";
    temp.addDir(directory);
    if((dir = opendir(directory.c_str())) != NULL){
        while ((ent = readdir (dir)) != NULL) {
            if(ent->d_name[0]!='.') cout << directory << ent->d_name << endl;
        }
        closedir (dir);
    }
    cout << endl;
    temp.makeMatrix1();
    temp.printMatrix();
    cout << endl;
    temp.makeMatrix2();
    temp.printMatrix();
}
