#include "fileReader.h"
#include "ui_mainmenu.h"
#include "mainmenu.h"


QDir *listDir;
QDir *comboDir;
QString qDir;
QString defDir;
QList<fileToken> fileList;



void changeDir(const QString &arg1, QListWidget *list, QComboBox *combo);

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    qDir = "../QtCodeCheckerV3";
    QDir master(qDir);
    QComboBox* combo = ui->comboBox;
    QListWidget* list = ui->listWidget;
    changeDir(qDir, list, combo);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_pushButton_clicked(){
    QDir* current = listDir;
    foreach(QFileInfo var, current->entryInfoList()){
        fileToken temp(var);
        temp.getFileList(var);
        temp.printFileList();
        //temp.readFile(temp.fInfo);
        //temp.printQStrings();
        //temp.printByteArrays();
        fileList.append(temp);
    }
}

void MainMenu::on_comboBox_currentTextChanged(const QString &arg1){
}

void MainMenu::on_listWidget_itemDoubleClicked(QListWidgetItem *item){\
    QString arg1 = item->text();
    changeDir(arg1, ui->listWidget, ui->comboBox);
}

void changeDir(const QString &arg1, QListWidget *list, QComboBox *combo){

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
