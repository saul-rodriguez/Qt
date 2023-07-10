/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonDiscover;
    QComboBox *comboBoxDevices;
    QPushButton *pushButtonConnect;
    QLabel *labelStatus;
    QLineEdit *lineEditMessage;
    QPushButton *pushButtonSend;
    QLabel *labelReceived;
    QPushButton *pushButtonDisconnect;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(496, 587);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButtonDiscover = new QPushButton(centralwidget);
        pushButtonDiscover->setObjectName("pushButtonDiscover");

        verticalLayout->addWidget(pushButtonDiscover);

        comboBoxDevices = new QComboBox(centralwidget);
        comboBoxDevices->setObjectName("comboBoxDevices");

        verticalLayout->addWidget(comboBoxDevices);

        pushButtonConnect = new QPushButton(centralwidget);
        pushButtonConnect->setObjectName("pushButtonConnect");

        verticalLayout->addWidget(pushButtonConnect);

        labelStatus = new QLabel(centralwidget);
        labelStatus->setObjectName("labelStatus");

        verticalLayout->addWidget(labelStatus);

        lineEditMessage = new QLineEdit(centralwidget);
        lineEditMessage->setObjectName("lineEditMessage");

        verticalLayout->addWidget(lineEditMessage);

        pushButtonSend = new QPushButton(centralwidget);
        pushButtonSend->setObjectName("pushButtonSend");

        verticalLayout->addWidget(pushButtonSend);

        labelReceived = new QLabel(centralwidget);
        labelReceived->setObjectName("labelReceived");

        verticalLayout->addWidget(labelReceived);

        pushButtonDisconnect = new QPushButton(centralwidget);
        pushButtonDisconnect->setObjectName("pushButtonDisconnect");

        verticalLayout->addWidget(pushButtonDisconnect);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 496, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "BLE NUS Test", nullptr));
        pushButtonDiscover->setText(QCoreApplication::translate("MainWindow", "Discover BLE", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "Disconnected", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        labelReceived->setText(QCoreApplication::translate("MainWindow", "Text Received from BLE", nullptr));
        pushButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
