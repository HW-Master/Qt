#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_open_clicked();

    void on_pause_clicked();

    void connect1();

    void rececive1();

private:
    Ui::MainWindow *ui;
    QString ip;
    quint16 port;
    QTcpSocket *tcp;
    int flag = 0;
//    char * start;
    int length;//图片长度
};
#endif // MAINWINDOW_H
