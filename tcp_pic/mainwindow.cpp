#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <string.h>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcp = new QTcpSocket(this);
    connect(tcp,&QTcpSocket::connected,this,&MainWindow::connect1);
    connect(tcp,&QTcpSocket::readyRead,this,&MainWindow::rececive1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_clicked()
{
    ip = ui->lineEdit->text();
    port = ui->lineEdit_2->text().toShort();

    tcp->connectToHost(ip,port);
//    qDebug() << "连接成功";
}

void MainWindow::on_pause_clicked()
{
    tcp->close();
}

void MainWindow::connect1()
{
    qDebug() << "连接成功\n";
    tcp->write("pic",3);
}

void MainWindow::rececive1()
{
    if(flag == 0){
        if(tcp->bytesAvailable() < 4){
            return;
        }
        tcp->read((char *)&length,4);
        qDebug() << "length:"<<length;
        flag = 1;
    }
    else if (flag == 1) {

        if(tcp->bytesAvailable() < length){
            return;
        }
        uchar buf[1024*1024];
        tcp->read((char *)buf,length);

        QPixmap pic;
        pic.loadFromData(buf,length);
        ui->label->setPixmap(pic.scaled(ui->label->width(),ui->label->height()));

        flag = 0;
    }else {
        flag = 0;
        qDebug() << "flag error\n";
    }
}





