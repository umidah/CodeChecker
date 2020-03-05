#include "mainwindow.h"
#include "ui_mainwindow.h"

QTableWidget *table;
QListWidget *legend;
QListWidget *guide;
QDir *listDir;
QDir *comboDir;

QString qDir;
QString defDir;

void changeDir(QString &arg1, QListWidget *list, QComboBox *combo);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ifstream file("./defaultDir.txt");
    string temp;
    if(file.is_open()){
        getline(file, temp, '\n');
        qDir = QString::fromStdString(temp);
    }
    else{
        qDir = "./";
    }
    file.close();
    ui->setupUi(this);
    ui->spinBox->setRange(0,1);
    comboDir = new QDir(qDir);
    changeDir(qDir, ui->listWidget, ui->comboBox);
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
        table->clear();
        table->clearContents();
        table->close();
        delete table;
    }
    if(legend != nullptr){
        legend->close();
        delete legend;
    }
    if(guide != nullptr){
        guide->close();
        delete guide;
    }
    //QWidget *wdg = new QWidget;
    wordAmountArr temp;
    table = new QTableWidget;
    legend = new QListWidget;
    guide = new QListWidget;
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
    chooseMatrix(i, temp);
    int size = temp.matrixSize;
    float **code = temp.getMatrix();
    table->setRowCount(size);
    table->setColumnCount(size);
    for(int x = 0; x < size; x++){
        QString legendItem = QString::number(x+1) + ": " + QString::fromStdString(temp.getDir(x));
        legend->addItem(legendItem);
        for(int y = 0; y < size; y++){
            if(x == 0 )
            table->setColumnWidth(y, 40);
            float tempF = (code[x][y]/2) + 0.5;
            int r = (int) (255*tempF), g = 50, b = (int) (255*(1-tempF));
            QColor color(r, g, b);
            QString temp;
            temp.setNum(truncate(code[x][y]));
            QTableWidgetItem *curr = new QTableWidgetItem(temp);
            curr->setBackgroundColor(color);
            curr->setFlags(curr->flags() ^ Qt::ItemIsEditable);
            table->setItem(x,y, curr);
        }
    }

    QObject::connect(legend,  &QListWidget::itemDoubleClicked, [=] (QListWidgetItem *item) {
        int i = legend->currentRow();
        table->selectRow(i);
        table->selectColumn(i);
    });
    table->showMaximized();
    legend->show();
    QListWidgetItem *a, *b, *c;
    QColor good(0, 50, 255), bad(255, 50, 0);
    a = new QListWidgetItem("Guide: (How similar are the strings in each code?)");
    b = new QListWidgetItem("Good or Very Different");
    c = new QListWidgetItem("Bad or Very Similar");

    b->setBackgroundColor(good);
    c->setBackgroundColor(bad);

    guide->addItem(a);
    guide->addItem(b);
    guide->addItem(c);

    guide->show();
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
    ofstream file("./defaultDir.txt");
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
