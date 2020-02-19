#include "header.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"



TEST_CASE("int values can be taken from strings", "[string]"){
    wordAmount a;
    wordAmount b;
    wordAmount c;
    string as("word"), bs("werd"), cs("word");
    int x = a.getStringValue(as);
    int y = a.getStringValue(bs);
    int z = a.getStringValue(cs);
    REQUIRE(x == y);
    REQUIRE(x == z);
}

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
