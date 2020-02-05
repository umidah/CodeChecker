#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir dir;
    foreach (QFileInfo temp, dir.drives()) {
        ui->comboBox->addItem(temp.absolutePath());
    }

    QDir dir2("C:/Users/ajtpa/Documents/GitHub/CodeChecker/QtCodeV2/Submissions");
    foreach (QFileInfo temp, dir2.entryInfoList()) {
        if(temp.isDir()){
            ui->listWidget->addItem(temp.absoluteFilePath());
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

float truncate(float a){
    float digit = 0.01;
    return (int)(a/digit)*digit;
}

void MainWindow::on_pushButton_clicked()
{
    QWidget *wdg = new QWidget;
    wordAmountArr temp;
    QTableWidget *table = new QTableWidget;
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
    table->setRowCount(size);
    table->setColumnCount(size);
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            float tempF = (code[x][y]/2) + 0.5;
            int r = (int) (255*tempF), g = 50, b = (int) (255*(1-tempF));
            QColor color(r, g, b);
            QString temp;
            temp.setNum(truncate(code[x][y]));
            QTableWidgetItem *curr = new QTableWidgetItem(temp);
            curr->setBackgroundColor(color);
            table->setItem(x,y, curr);
        }
    }
    table->showMaximized();
}
