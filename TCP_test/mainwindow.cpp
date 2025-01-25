#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QDebug>
#include <QMessageBox>
#include <QtNetwork>
#include <QIcon>
QTcpServer *Server;
QTcpSocket *Socket;
QTcpSocket *new_socket;
bool tmp = true;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Server = new QTcpServer(this);
    Socket = new QTcpSocket(this);
//    connect(Server,&QTcpServer::newConnection,this,&MainWindow::accept_connect);
//    connect(Socket,&QTcpSocket::readyRead,this,&MainWindow::read_date);
    ui->pushButton_listen->setEnabled(false);
    setWindowIcon(QIcon(":/favicon.ico"));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_radioButton_2_clicked(bool checked)
{
    QString ip = ui->comboBox->currentText();
    QString port = ui->lineEdit_local_port->text();
    ui->pushButton_listen->setEnabled(true);
    disconnect(Socket,&QTcpSocket::readyRead,this,&MainWindow::read_date);
    disconnect(Socket, &QTcpSocket::connected, this, &MainWindow::onConnected);
    if(checked){
        connect(Server,&QTcpServer::newConnection,this,&MainWindow::accept_connect);
        ui->pushButton_listen->setText("开始监听");
        Socket->connectToHost(ip,port.toShort());
    }
    tmp = true;
}

void MainWindow::on_radioButton_clicked(bool checked)
{
    disconnect(Server,&QTcpServer::newConnection,this,&MainWindow::accept_connect);
    connect(Socket,&QTcpSocket::readyRead,this,&MainWindow::read_date);
    ui->pushButton_listen->setEnabled(true);
    Server->close();
    if(checked){
        ui->pushButton_listen->setText("连接网络");
    }
    tmp = true;
}

void MainWindow::on_pushButton_listen_clicked()
{
    QString msg = ui->pushButton_listen->text();

    if(msg == "开始监听"  && tmp){
        QString ip = ui->comboBox->currentText();      //2222222222222222222222222
        QString port = ui->lineEdit_local_port->text();
        qDebug() << "ip" << ip <<"port:"<< port;

        if(Server->listen(QHostAddress(ip),port.toShort())){
            ui->label_4->setText("正在监听");
        }else{
            ui->label_4->setText("监听失败");
        }
        tmp = false;
    }
    else if(msg == "连接网络"){
        QString ip = ui->comboBox->currentText();
        QString port = ui->lineEdit_port->text();
        Socket->connectToHost(ip,port.toShort());
        connect(Socket, &QTcpSocket::connected, this, &MainWindow::onConnected);
    }
}

void MainWindow::accept_connect()
{
    int ret = QMessageBox::warning(this,tr("连接提示"),tr("有新的客户端请求是否接受"),QMessageBox::Yes|QMessageBox::No);
    if(ret == QMessageBox::Yes){
        new_socket = Server->nextPendingConnection();
        connect(new_socket,&QTcpSocket::readyRead,this,&MainWindow::read_date);
    }
}

void MainWindow::read_date()
{
    QByteArray msg=0;
    QString ip= 0;
    if(ui->pushButton_listen->text()=="开始监听"){
        msg = new_socket->readAll();
        ip = new_socket->peerAddress().toString();
    }else{
        msg = Socket->readAll();
        ip = Socket->peerAddress().toString();
    }

    ui->plainTextEdit->appendPlainText(ip+":"+msg);
}


void MainWindow::on_pushButton_send_clicked()
{
    if(ui->pushButton_listen->text() == "开始监听"){
        QString msg = ui->textEdit_2->toPlainText();
        new_socket->write(msg.toUtf8());
    }
    else if (ui->pushButton_listen->text() == "连接网络") {
        QString msg = ui->textEdit_2->toPlainText();
        Socket->write(msg.toUtf8());
    }

}

void MainWindow::on_pushButton_listen_clicked(bool checked)
{

}

void MainWindow::on_pushButton_clear_s_clicked()
{
    ui->textEdit_2->clear();

}

void MainWindow::on_pushButton_clear_J_clicked()
{
    ui->plainTextEdit->clear();
}

void MainWindow::onConnected(){
    ui->label_4->setText("连接成功");
}

void MainWindow::on_pushButton_clicked()
{
    QList<QHostAddress> list =QNetworkInterface::allAddresses();
    QStringList p;
    foreach (QHostAddress address, list)
    {
         if(address.protocol() ==QAbstractSocket::IPv4Protocol){
             //我们使用IPv4地址
             qDebug() << address.toString();
             ui->comboBox->addItem(address.toString());

         }

    }

}
