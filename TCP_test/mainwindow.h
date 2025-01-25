#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_radioButton_2_clicked(bool checked);



    void on_radioButton_clicked(bool checked);

    void on_pushButton_listen_clicked();

    void accept_connect();

    void read_date();


    void on_pushButton_send_clicked();

    void on_pushButton_listen_clicked(bool checked);

    void on_pushButton_clear_s_clicked();

    void on_pushButton_clear_J_clicked();

    void onConnected();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
