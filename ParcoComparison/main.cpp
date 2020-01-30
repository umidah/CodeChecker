#include "header.h"

int main()
{
    wordAmountArr temp;
    string superDir = "Submissions/";
    temp.loadSuperDir(superDir);
    /*
    string test = superDir+"anjelo-vicente/";
    temp.addDir(test);
    test = superDir + "angelo-parco/";
    temp.addDir(test);
    */
    temp.makeMatrix1();
    temp.printMatrix();
    cout << endl;
    temp.makeMatrix3();
    temp.printMatrix();
    /*
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

    directory = "filesToRead/";
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
    cout << endl;
    temp.makeMatrix3();
    temp.printMatrix();
    */
}
