#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QDebug>
#include <QFileDialog>
#include <QModelIndex>
#include <QMessageBox>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu *m = new QMenu(ui->toolButton);
    m->addAction("导入文件");
    m->addAction("清空文件");
    m->addAction("删除文件");
    ui->toolButton->setMenu(m);

}

MainWindow::~MainWindow()
{
    delete ui;
}
//自定义显示显示函数
void MainWindow::pic_show(QString pic_path){
    x = ui->label->width();
    y = ui->label->height();
    QPixmap pic(pic_path);
    pic = pic.scaled(ui->label->width(),ui->label->height());
    ui->label->setPixmap(pic);
}


void MainWindow::on_toolButton_clicked()
{
    ui->toolButton->showMenu();
}

void MainWindow::on_toolButton_triggered(QAction *arg1)
{
    if("导入文件" == arg1->text()){
        qDebug() << "导入文件";

        QStringList files = QFileDialog::getOpenFileNames(
                                        this,
                                        "Select one or more files to open",
                                        "C:\\Users\\hewan\\WPS Cloud Files",
                                        "Images (*.png *.bmp *.jpg)");
        ui->listWidget->addItems(files);
    }
    else if ("清空文件" == arg1->text()) {
        qDebug() <<"清空文件";
        ui->listWidget->clear();
    }
    else if ("删除文件" == arg1->text()){
        qDebug() <<"删除文件";
        int row = ui->listWidget->currentRow();

        int ret = QMessageBox::warning(this, tr("温馨提示"),
                                            tr("确定需要删除该文件？？.\n"),
                                            QMessageBox::Yes| QMessageBox::No);
        if(ret == QMessageBox::Yes){
            ui->listWidget->takeItem(row);
            qDebug() << row <<"删除成功\n";
        }

    }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString pic_path = item->text();
//    QPixmap pic(pic_path);
//    pic = pic.scaled(ui->label->width(),ui->label->height());
//    ui->label->setPixmap(pic);
    pic_show(pic_path);
}

void MainWindow::on_pushButton_4_clicked()
{
    int line = ui->listWidget->currentRow();
    line--;
    if(line < 0){
        line = ui->listWidget->count()-1;
    }
    ui->listWidget->setCurrentRow(line);
    pic_show(ui->listWidget->currentItem()->text());
}

void MainWindow::on_pushButton_5_clicked()
{
    int line = ui->listWidget->currentRow();

    line++;
    if(line >= ui->listWidget->count()){
        line=0;
    }
    ui->listWidget->setCurrentRow(line);
    pic_show(ui->listWidget->currentItem()->text());
}

void MainWindow::on_pushButton_clicked()
{
    x = x*1.2;
    y = y*1.2;
    QPixmap pic(ui->listWidget->currentItem()->text());
    pic = pic.scaled(x,y);
    ui->label->setPixmap(pic);
}

void MainWindow::on_pushButton_3_clicked()
{
    x = x*0.8;
    y = y*0.8;
    QPixmap pic(ui->listWidget->currentItem()->text());
    pic = pic.scaled(x,y);
    ui->label->setPixmap(pic);
}

void MainWindow::on_pushButton_2_clicked()
{
    //初始化图片
        QPixmap pic(ui->listWidget->currentItem()->text());

        static  int s = 180;
        QMatrix  ro;
        //设置转角为 45 度
        ro = ro.rotate(s);
        //旋转图片
        pic =  pic.transformed(ro);

        ui->label->setPixmap(pic);
        s+=180;
}
