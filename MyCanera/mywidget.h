#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:


    void on_start_clicked();

    void on_stop_clicked();

    void on_jieping_clicked();

private:
    Ui::MyWidget *ui;
    QCamera * ca;
    QCameraViewfinder * w;
    QCameraImageCapture *cp;
};
#endif // MYWIDGET_H
