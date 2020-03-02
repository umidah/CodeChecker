#include "header.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

    wordAmount a;
    wordAmount b;
    wordAmount c;
    wordAmount t1;
    wordAmount t2;
    wordAmountArr temp;
    string as("word"), bs("werd"), cs("word");
    int x = a.getStringValue(as);
    int y = a.getStringValue(bs);
    int z = a.getStringValue(cs);

SCENARIO("the wordAmount class properly reads words", "[wordAmount]"){
    WHEN("Word int values are taken properly"){
        REQUIRE(x == z);
        REQUIRE(x != y);
    }

    WHEN("inserting words works; repeated words do not get added"){
        a.insertWord(as);
        a.insertWord(bs);
        a.insertWord(cs);
        REQUIRE(a.currentWordsAmount[0].count == 2);
        REQUIRE(a.currentWordsAmount[0].word.compare(as) == 0);
    }

    WHEN("Inserting the same words will result in no difference"){
        b.insertWord(as);
        b.insertWord(bs);
        b.insertWord(cs);
        float x, y;
        x = a.vecStringValue();
        y = b.vecStringValue();
        REQUIRE(x == y);
    }

    WHEN("The matrix properly forms"){
        string path = "./filesToRead/";
        temp.loadSuperDir(path);
        temp.makeMatrix1();
        float** mat = temp.getMatrix();
        for(int x = 0; x < temp.matrixSize; x++){
            for(int y = 0; y < temp.matrixSize; y++){
                    if (x == y) REQUIRE(mat[x][y] == 1.f);
                    else REQUIRE(mat[x][y] != 1.f);
            }
        }
    }

}

/*
TEST_CAST(){
}

TEST_CAST(){
}
*/

/*
int main()
{
    wordAmountArr temp;
    string superDir = "filesToRead/";
    temp.loadSuperDir(superDir);
    temp.makeMatrix1();
    temp.printMatrix();
    cout << endl;
    temp.makeMatrix3();
    temp.printMatrix();
}
*/
