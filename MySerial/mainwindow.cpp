#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    int a = 1;
    ui->send->setEnabled(false);
       foreach(const QSerialPortInfo &info ,QSerialPortInfo::availablePorts()){

           QSerialPort serial(info);
           if(serial.open(QIODevice::ReadWrite)){
               ui->ports->addItem(serial.portName());
               serial.close();
           }else{
               ui->ports->addItem(serial.portName()+"已占用");
           }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readData()
{
    QByteArray data = ser->readAll();
    if(!data.isEmpty()){
        ui->textBrowser->append(data);
    }
}


void MainWindow::on_open_clicked()
{
    if(ui->open->text() == "open"){
            qDebug() << ui->ports->currentText();
            ser = new QSerialPort(ui->ports->currentText(),this);
            if(!ser->open(QIODevice::ReadWrite)){
                QMessageBox::warning(this,"提示","打开失败",QMessageBox::Ok);
                ser->deleteLater();
                return;
            }
            //设置波特率
            switch (ui->Baud->currentIndex()) {
            case 0:
                ser->setBaudRate(QSerialPort::Baud115200);
                break;
            case 1:
                ser->setBaudRate(QSerialPort::Baud2400);
                break;
            case 2:
                ser->setBaudRate(QSerialPort::Baud4800);
                break;
            case 3:
                ser->setBaudRate(QSerialPort::Baud9600);
                break;
            case 4:
                ser->setBaudRate(QSerialPort::Baud38400);
                break;
            default:
                break;
            }
            //设置数据位位数
            switch (ui->data_bit->currentIndex()) {
            case 0:
                ser->setBaudRate(QSerialPort::Data8);
                break;
            case 1:
                ser->setBaudRate(QSerialPort::Data5);
                break;
            case 2:
                ser->setBaudRate(QSerialPort::Data6);
                break;
            case 3:
                ser->setBaudRate(QSerialPort::Data7);
                break;
            default:
                break;
            }
            //设置校验方式
            switch (ui->check->currentIndex()) {
            case 0:
                ser->setBaudRate(QSerialPort::NoParity);
                break;
            case 1:
                ser->setBaudRate(QSerialPort::EvenParity);
                break;
            case 2:
                ser->setBaudRate(QSerialPort::OddParity);
                break;

            default:
                break;
            }
            //设置停止位数
            switch (ui->sop_bit->currentIndex()) {
            case 0:
                ser->setBaudRate(QSerialPort::OneStop);
                break;
            case 1:
                ser->setBaudRate(QSerialPort::OneAndHalfStop);
                break;
            case 2:
                ser->setBaudRate(QSerialPort::TwoStop);
                break;

            default:
                break;
            }

            //设置流控
            ser->setFlowControl(QSerialPort::NoFlowControl);

            //关闭
            ui->port->setEnabled(false);
            ui->Baud->setEnabled(false);
            ui->data_bit->setEnabled(false);
            ui->sop_bit->setEnabled(false);
            ui->check->setEnabled(false);
            ui->send->setEnabled(true);
            //修改按钮显示
            ui->open->setText("close");

            //连接
            connect(ser,&QSerialPort::readyRead,this,&MainWindow::readData);


        }else {
            ser->clear();
            ser->close();
            ser->deleteLater();

            ui->port->setEnabled(true);
            ui->Baud->setEnabled(true);
            ui->data_bit->setEnabled(true);
            ui->sop_bit->setEnabled(true);
            ui->check->setEnabled(true);
            ui->send->setEnabled(false);
            ui->open->setText("open");
        }
}

void MainWindow::on_send_clicked()
{
    QByteArray data = ui->textEdit->toPlainText().toUtf8();
    //toPlainText()  方法返回一个 QString
    //toUtf8 ：将 QString 对象转换为 UTF-8 编码的 QByteArray
    ser->write(data);
}
