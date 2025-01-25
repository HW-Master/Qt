#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QDir>
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    QList<QCameraInfo> infos = QCameraInfo::availableCameras();
    foreach(QCameraInfo info,infos){
        qDebug() << info.deviceName()  << info.description();
        ui->comboBox->addItem(info.deviceName());
    }
    ui->stop->setEnabled(false);
}

MyWidget::~MyWidget()
{
    delete ui;
}



void MyWidget::on_start_clicked()
{
    ca = new QCamera(ui->comboBox->currentText().toUtf8(),this);
    w = new QCameraViewfinder(ui->widget);
    cp = new QCameraImageCapture(ca,this);
    w->resize(ui->widget->size());
    //设置摄像头的显示窗口
    ca->setViewfinder(w);

    w->show();
    ca->start();
    ui->stop->setEnabled(true);
    ui->start->setEnabled(false);
    ui->jieping->setEnabled(true);
}

void MyWidget::on_stop_clicked()
{
    ca->stop();
    w->hide();   //隐藏窗口
    delete  ca;
    delete w;
    delete cp;
    ui->stop->setEnabled(false);
    ui->start->setEnabled(true);
    ui->jieping->setEnabled(false);
}

void MyWidget::on_jieping_clicked()
{
    if(ca->state() == QCamera::ActiveState){
        ui->jieping->setEnabled(true);
        QString path = QDir::currentPath();
        qDebug() << path;
        cp->capture("C:\\Users\\hewan\\Desktop\\1.jpg");
        return;
    }

}
