#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <pthread.h>
#include <unistd.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    thread = new MyThread(this,ui);
    thread->start();


}

MainWindow::~MainWindow()
{
    delete ui;

}

int i = 0;
void MyThread::run()
{
    while(1)
    {   ui->label->setNum(i++);
        this->sleep(1);
    }
}
