#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->closePushButton,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_findPushButton_clicked()
{
    ui->textBrowser->clear();
    QString file_name=ui->fileLineEdit->text();
    QString find_text=ui->keyLineEdit->text();
    qDebug() << file_name ;
    qDebug() << find_text ;
    QFile file(file_name);
    string x;
    string file_name_string=file_name.toStdString();
    string find_text_string=find_text.toStdString();
    ifstream input_file_object(file_name_string);
    if(input_file_object && find_text==""){
        ui->textBrowser->append("File Found");

        input_file_object.close();
    }
    else if(input_file_object && find_text!=""){
        ui->textBrowser->append("File Found");
        while ( getline (input_file_object,x) ){
            if(ui->matchCheckBox->isChecked()){
                transform(x.begin(), x.end(), x.begin(), ::toupper);
                transform(find_text_string.begin(), find_text_string.end(), find_text_string.begin(), ::toupper);
                if (x.find(find_text_string, 0) != string::npos){
                    ui->textBrowser->clear();
                    ui->textBrowser->append("Word found");
                    break;
                }
                else{
                    ui->textBrowser->clear();
                    ui->textBrowser->append("Word not found");
                    break;
                }
            }
            else{
                if (x.find(find_text_string, 0) != string::npos){
                    ui->textBrowser->clear();
                    ui->textBrowser->append("Word found");
                    break;
                }
                else{
                    ui->textBrowser->clear();
                    ui->textBrowser->append("Word not found");
                    break;
                }
            }
        }
        input_file_object.close();
    }
    else{
        ui->textBrowser->append("File not found");
    }

}
