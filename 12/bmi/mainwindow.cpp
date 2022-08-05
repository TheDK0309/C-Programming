#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <string>
#include <iomanip>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->closeButton,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_countButton_clicked()
{
    ui->infoTextBrowser->clear();
    QString weight=ui->weightLineEdit->text();
    QString height=ui->heightLineEdit->text();
    double weight_int= weight.toDouble();
    qDebug() << weight_int ;
    double height_int= height.toDouble();
    qDebug() << height_int ;
    double BMI= weight_int/((height_int/100)*(height_int/100));
    std::setprecision(4);
    qDebug() << BMI ;
    std::string BMI_string=std::to_string(BMI);
    ui->resultLabel->setText(QString::fromStdString(BMI_string));
    if(BMI<18.5){
        ui->infoTextBrowser->append("You are underweight.");
    }
    else if(BMI>25){
        ui->infoTextBrowser->append("You are overweight.");
    }
    else{
        ui->infoTextBrowser->append("Your weight is normal.");
    }

}
