/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_port;
    QLineEdit *lineEdit_local_port;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_listen;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_send;
    QPushButton *pushButton_clear_s;
    QPushButton *pushButton_clear_J;
    QPushButton *pushButton_quit;
    QGroupBox *groupBox_5;
    QTextEdit *textEdit_2;
    QGroupBox *groupBox_4;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(919, 726);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 20, 291, 641));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 190, 267, 227));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 72, 15));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 110, 72, 15));
        label_2->setFont(font);
        lineEdit_port = new QLineEdit(groupBox_3);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));
        lineEdit_port->setGeometry(QRect(80, 100, 121, 31));
        lineEdit_local_port = new QLineEdit(groupBox_3);
        lineEdit_local_port->setObjectName(QString::fromUtf8("lineEdit_local_port"));
        lineEdit_local_port->setGeometry(QRect(80, 140, 121, 31));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 150, 61, 16));
        label_3->setFont(font);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 190, 101, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        pushButton_listen = new QPushButton(groupBox_3);
        pushButton_listen->setObjectName(QString::fromUtf8("pushButton_listen"));
        pushButton_listen->setGeometry(QRect(120, 190, 141, 31));
        pushButton_listen->setFont(font1);
        comboBox = new QComboBox(groupBox_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 50, 191, 41));
        comboBox->setEditable(true);
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 60, 51, 24));
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(12, 27, 267, 151));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(10, 40, 107, 19));
        radioButton->setFont(font);
        radioButton->setStyleSheet(QString::fromUtf8(""));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 80, 107, 19));
        radioButton_2->setFont(font);
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 120, 51, 19));
        radioButton_3->setFont(font);
        verticalLayoutWidget = new QWidget(groupBox_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 430, 271, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_send = new QPushButton(verticalLayoutWidget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setFont(font1);

        verticalLayout->addWidget(pushButton_send);

        pushButton_clear_s = new QPushButton(verticalLayoutWidget);
        pushButton_clear_s->setObjectName(QString::fromUtf8("pushButton_clear_s"));
        pushButton_clear_s->setFont(font1);

        verticalLayout->addWidget(pushButton_clear_s);

        pushButton_clear_J = new QPushButton(verticalLayoutWidget);
        pushButton_clear_J->setObjectName(QString::fromUtf8("pushButton_clear_J"));
        pushButton_clear_J->setFont(font1);

        verticalLayout->addWidget(pushButton_clear_J);

        pushButton_quit = new QPushButton(verticalLayoutWidget);
        pushButton_quit->setObjectName(QString::fromUtf8("pushButton_quit"));
        pushButton_quit->setFont(font1);

        verticalLayout->addWidget(pushButton_quit);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(330, 370, 581, 301));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        groupBox_5->setFont(font2);
        textEdit_2 = new QTextEdit(groupBox_5);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 30, 561, 261));
        textEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(330, 30, 581, 311));
        groupBox_4->setFont(font2);
        plainTextEdit = new QPlainTextEdit(groupBox_4);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 30, 561, 271));
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 919, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\357\274\210-_-\357\274\211", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("MainWindow", "\350\277\234\347\250\213\344\270\273\346\234\272", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\350\277\234\347\250\213\347\253\257\345\217\243", nullptr));
        lineEdit_port->setText(QApplication::translate("MainWindow", "8000", nullptr));
        lineEdit_local_port->setText(QApplication::translate("MainWindow", "8000", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\234\254\345\234\260\347\253\257\345\217\243", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201", nullptr));
        pushButton_listen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\351\200\232\344\277\241\346\250\241\345\274\217", nullptr));
        radioButton->setText(QApplication::translate("MainWindow", "TCP client", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "TCP Server", nullptr));
        radioButton_3->setText(QApplication::translate("MainWindow", "UDP", nullptr));
        pushButton_send->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        pushButton_clear_s->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\345\217\221\351\200\201\345\214\272", nullptr));
        pushButton_clear_J->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", nullptr));
        pushButton_quit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\214\272", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\346\216\245\346\224\266\345\214\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
