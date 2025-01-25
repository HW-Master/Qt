#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(){}
    MyThread(QObject *parent = nullptr,Ui::MainWindow *ui_1=nullptr):QThread(parent),ui(ui_1){}
//    ~MyThread();
    void run() override;
private:
    Ui::MainWindow *ui;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    MyThread *thread;
};
#endif // MAINWINDOW_H
