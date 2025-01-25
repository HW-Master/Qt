#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sys/types.h>
#include <unistd.h>
#include <QProcess>
#include <QDebug>
QProcess *p;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p = new QProcess(this);
    connect(p,SIGNAL(readyRead()),this,SLOT(get_date()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    p->start("ping www.baidu.com");
}

void MainWindow::get_date()
{
    QString msg = p->readAll();
    qDebug() << msg;
}
