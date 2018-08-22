/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_IPaddress;
    QLabel *label_2;
    QLineEdit *lineEdit_port;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_disconnect;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_message;
    QPushButton *pushButton_send;
    QPlainTextEdit *plainTextEdit_log;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(481, 380);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_IPaddress = new QLineEdit(centralWidget);
        lineEdit_IPaddress->setObjectName(QStringLiteral("lineEdit_IPaddress"));

        horizontalLayout->addWidget(lineEdit_IPaddress);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_port = new QLineEdit(centralWidget);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));

        horizontalLayout->addWidget(lineEdit_port);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_connect = new QPushButton(centralWidget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));

        horizontalLayout_2->addWidget(pushButton_connect);

        pushButton_disconnect = new QPushButton(centralWidget);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));

        horizontalLayout_2->addWidget(pushButton_disconnect);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_message = new QLineEdit(centralWidget);
        lineEdit_message->setObjectName(QStringLiteral("lineEdit_message"));

        horizontalLayout_3->addWidget(lineEdit_message);

        pushButton_send = new QPushButton(centralWidget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));

        horizontalLayout_3->addWidget(pushButton_send);


        verticalLayout->addLayout(horizontalLayout_3);

        plainTextEdit_log = new QPlainTextEdit(centralWidget);
        plainTextEdit_log->setObjectName(QStringLiteral("plainTextEdit_log"));

        verticalLayout->addWidget(plainTextEdit_log);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 481, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "IP Address:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Port:", nullptr));
        pushButton_connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        pushButton_disconnect->setText(QApplication::translate("MainWindow", "Disconnect", nullptr));
        pushButton_send->setText(QApplication::translate("MainWindow", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
