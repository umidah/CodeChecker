#include "mainwindow.h"

#include "header.h"

#include <QApplication>
#include <QLabel>
#include <QTableWidget>
#include <QMessageBox>

float truncate(float a){
    float digit = 0.01;
    return (int)(a/digit)*digit;
}


int main(int argc, char *argv[])
{
    wordAmountArr temp;
    string path = "C:/Users/ajtpa/Documents/GitHub/CodeChecker/QtCodeChecker/Submissions";
    QString Qpath = "C:/Users/ajtpa/Documents/GitHub/CodeChecker/QtCodeChecker/Submissions";
    //path = "Submissions";
    QDir dir(Qpath);
    if(dir.exists()){
        qDebug() << "it exists";
    }
    else{
        qDebug() << "Does not exist";
    }
    temp.loadSuperDir(path);
    temp.loadSuperDir("Submissions/");
    temp.makeMatrix1();
    int size = 10;
    size = temp.matrixSize;
    float **code = temp.getMatrix();
    qDebug() << temp.matrix[0][0];
    QApplication prog(argc, argv);
    QTableWidget table(size,size);
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            float tempF = (code[x][y]/2) + 0.5;
            int r = (int) (255*tempF), g = 50, b = (int) (255*(1-tempF));
            QColor color(r, g, b);
            QString temp;
            temp.setNum(truncate(code[x][y]));
            QTableWidgetItem *curr = new QTableWidgetItem(temp);
            curr->setBackgroundColor(color);
            table.setItem(x,y, curr);
        }
    }
    table.show();
    return prog.exec();
}
