#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QMessageBox>

QTableWidget *table;
QDir *listDir;
QDir *comboDir;

QString qDir;
QString defDir;

void changeDir(QString &arg1, QListWidget *list, QComboBox *combo);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ifstream file("../QtCodeV2/defaultDir.txt");
    string temp;
    if(file.is_open()){
        getline(file, temp, '\n');
        qDir = QString::fromStdString(temp);
    }
    else{
        qDir = "../QtCodeV2";
    }
    file.close();
    ui->setupUi(this);
    ui->spinBox->setRange(0,1);
    comboDir = new QDir(qDir);
    changeDir(qDir, ui->listWidget, ui->comboBox);
    /*
    foreach (QFileInfo temp, comboDir->entryInfoList()) {
        if(temp.isDir())
        ui->comboBox->addItem(temp.absolutePath());
    }
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

float truncate(float a){
    float digit = 0.01;
    return (int)(a/digit)*digit;
}

void chooseMatrix(int i, wordAmountArr &arr){
    if(i == 0){
        arr.makeMatrix1();
    }
    else if(i == 1){
        arr.makeMatrix3();
    }
}

void MainWindow::on_pushButton_clicked()
{
    int i = ui->spinBox->value();
    if(table != nullptr){
        table->close();
        delete table;
    }
    //QWidget *wdg = new QWidget;
    wordAmountArr temp;
    table = new QTableWidget;
    string path = "C:/Users/Laptop/Documents/CodeChecker/QtCodeV2/Submissions";
    path = "../QtCodeV2/Submissions";
    path = qDir.toUtf8().constData();
    qDebug() << QString::fromStdString(path);
    QString Qpath = "../QtCodeV2/Submissions";
    //path = "Submissions";
    QDir dir(Qpath);
    if(dir.exists()){
        qDebug() << Qpath;
    }
    else{
        qDebug() << "Does not exist";
    }
    temp.loadSuperDir(path);
    temp.loadSuperDir("Submissions/");
    chooseMatrix(i, temp);
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

void MainWindow::on_pushButton_2_clicked()
{
    QString arg1 = ui->comboBox->currentText();
    changeDir(arg1, ui->listWidget, ui->comboBox);
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    auto arg1 = item->text();
    changeDir(arg1, ui->listWidget, ui->comboBox);
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{

}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{

}

void MainWindow::on_comboBox_highlighted(const QString &arg1)
{

}

void changeDir(QString &arg1, QListWidget *list, QComboBox *combo){

    qDir = arg1;
    qDebug() << arg1;
    if(listDir != nullptr){
        delete listDir;
        list->clear();
    }
    if(comboDir != nullptr){
        delete comboDir;
        combo->clear();
    }

    comboDir = new QDir(arg1);
    foreach (QFileInfo temp, comboDir->entryInfoList()) {
        if(temp.isDir())
        combo->addItem(temp.absoluteFilePath());
    }

    listDir = new QDir(arg1);
    foreach (QFileInfo temp, listDir->entryInfoList()) {
       list->addItem(temp.absoluteFilePath());
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{

}

void MainWindow::on_pushButton_3_clicked()
{
    defDir = ui->comboBox->currentText();
    ofstream file("../QtCodeV2/defaultDir.txt");
    if(!file.is_open()){
        QMessageBox error;
        error.setText("Default path file DNE!");
        error.setIcon(QMessageBox::Icon(2));
        error.exec();
    }
    else{
        QMessageBox success;
        file << defDir.toStdString();
        success.setText("Current default directory is " + defDir);
        success.setIcon(QMessageBox::Icon(1));
        success.exec();
        file.close();
    }
}
