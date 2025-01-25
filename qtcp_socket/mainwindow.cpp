#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpSocket>
QTcpSocket *socket = NULL;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    socket->connectToHost("172.19.82.38",8000);
    connect(socket,SIGNAL(readyRead()),this,SLOT(read_date()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString msg = ui->textEdit->toPlainText();
    socket->write(msg.toUtf8());
}

void MainWindow::read_date()
{
    QString msg = socket->readAll();
    ui->textBrowser->setPlainText(msg);
}
