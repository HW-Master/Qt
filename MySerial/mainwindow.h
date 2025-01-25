#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QSerialPort>

QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void readData();
private slots:
    void on_open_clicked();

    void on_send_clicked();

private:
    Ui::MainWindow *ui;

    QSerialPort * ser;
};
#endif // MAINWINDOW_H
