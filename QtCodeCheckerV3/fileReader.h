#ifndef FILEREADER_H
#define FILEREADER_H

#include <QFile>
#include <QDir>
#include <QHash>
#include <QList>
#include <QTextCodec>
#include <QDebug>


class fileToken{
public:
    QList< QHash<QString, int> > list;
    QStringList fNameList;
    QStringList sList;
    QByteArrayList bList;
    QFileInfo fInfo;
    QDir dir;

    fileToken(QFileInfo fInfo): fInfo(fInfo){}
    fileToken(){}

    void getFileList(QFileInfo fileInfo){
        QDir dir;
        dir.setPath(fileInfo.absoluteFilePath());
        foreach(QFileInfo var, dir.entryInfoList(QDir::NoDotDot)){
            if(var.isDir()){
                fileToken::getFileList(var.absoluteFilePath());
            }
            else{
                fNameList.append(var.absoluteFilePath());
            }
        }
    }

    void readFile(QFileInfo fileInfo){
        QString tempPath = fileInfo.absoluteFilePath();
        if(fileInfo.isDir()){
            qDebug() << fileInfo.absoluteFilePath() << " is a dir";
            //QDir tempDir(tempPath);
            //qDebug() << tempDir.absolutePath() << "will be processed";
            foreach (QFileInfo var, fileInfo.absoluteDir().entryInfoList()) {
                qDebug() << "processing " << var.absoluteFilePath();
                //fileToken::readFile(var);
            }
        }
        else{
            qDebug() << fileInfo.absoluteFilePath() << " is a file";
            QFile file(tempPath);
            if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
            while(!file.atEnd()){
                QByteArray line = file.readLine();
                line = line.simplified();
                this->bList.append(line);
                this->sList.append(QString::fromLocal8Bit(line.data()));
            }
        }

    }

    void printQStrings(){
        foreach (QString temp, this->sList) {
            qDebug() << temp;
        }
    }

    void printByteArrays(){
        foreach(QByteArray temp, this->bList){
            qDebug() << temp;
        }
    }

    void printFileList(){
        foreach(QString temp, this->fNameList){
            qDebug() << temp;
        }
    }
};

extern QList<fileToken> fileList;
extern QDir *listDir;
extern QDir *comboDir;
extern QString qDir;
extern QString defDir;

#endif // FILEREADER_H
