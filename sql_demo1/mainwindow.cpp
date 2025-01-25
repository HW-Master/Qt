#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("stu.db");

    if(! db.open()){
         qDebug() << "open fail !";
    }

    model = new QSqlTableModel(this);
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}


void MainWindow::on_create_clicked()
{
    QString sql = QString("create table if not exists %1(id int unique,name ntext,age int);").
                      arg(ui->lineEdit->text());
    QSqlQuery query;
    if(!query.exec(sql)){
        qDebug() << "create table failure !";
    }

    model->setTable(ui->lineEdit->text());
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    model->select();
    ui->tableView->setModel(model);

    ui->create->setEnabled(false);
    ui->lineEdit->setEnabled(false);
}

void MainWindow::on_add_clicked()
{
    int row = model->rowCount();
        model->insertRow(row);
        int id = 100;

        model->setData(model->index(row,0),id);
        model->submitAll();
}

void MainWindow::on_save_clicked()
{
    model->submitAll();
}

void MainWindow::on_withdraw_clicked()
{

}

void MainWindow::on_inquire_clicked()
{
    model->setTable(ui->lineEdit->text());
    model->select();
    model->submitAll();
}

void MainWindow::on_drop_clicked()
{
    int delrow = ui->tableView->currentIndex().row();

        model->removeRow(delrow);
        if(QMessageBox::No == QMessageBox::warning(this,"drop","are you sure?",QMessageBox::Yes|QMessageBox::No)){
            model->revertAll();
        }else{
            model->submitAll();
        }
}
