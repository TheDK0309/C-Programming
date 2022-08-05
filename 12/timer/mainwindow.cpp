#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::timer_up);
    connect(ui->closeButton,SIGNAL(clicked()),this,SLOT(close()));
    ui->lcdNumberMin->setStyleSheet("""QLCDNumber {background-color: cyan;}""");
    ui->lcdNumberSec->setStyleSheet("""QLCDNumber {background-color: green;}""");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    if (timer->isActive()) return;
    timer->start(1000);
    //qDebug() << "HELlo";
}

void MainWindow::on_stopButton_clicked()
{
    timer->stop();
}

void MainWindow::on_resetButton_clicked()
{
    ui->lcdNumberSec->display(QString::number(0));
    ui->lcdNumberMin->display(QString::number(0));
    timer->stop();
}

void MainWindow::timer_up()
{
    int sec=ui->lcdNumberSec->value();
    int min=ui->lcdNumberMin->value();
    if(sec<60){
        //ui->lcdNumberSec->setDigitCount(++sec);
        ui->lcdNumberSec->display(QString::number(++sec));
    }
    else if(sec>=60){
        sec=0;
        //ui->lcdNumberSec->setDigitCount(sec);
        ui->lcdNumberSec->display(QString::number(sec));
        min+=1;
        //ui->lcdNumberMin->setDigitCount(min);
        ui->lcdNumberMin->display(QString::number(min));
    }
}

