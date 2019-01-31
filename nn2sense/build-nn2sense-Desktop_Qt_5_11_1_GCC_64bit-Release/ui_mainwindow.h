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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
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
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBoxConfigSmoothPlot;
    QCheckBox *checkBoxConfigAntialias;
    QSpacerItem *verticalSpacer;
    QWidget *Connect;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBoxWirelessInterface;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_4;
    QPushButton *pushButtonBTdiscoverDevices;
    QRadioButton *radioButtonWiFi;
    QLabel *labelBTstatus;
    QRadioButton *radioButtonBT;
    QComboBox *comboBoxBTdevices;
    QPushButton *pushButtonBTconnect;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEditWiFiAddress;
    QPushButton *pushButtonWiFiConnect;
    QLabel *labelWiFiStatus;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelWiFiPort;
    QLineEdit *lineEditWiFiPort;
    QPushButton *pushButtonWiFiDisconnect;
    QPushButton *pushButtonBTdisconnect;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditAT;
    QPushButton *pushButtonATSend;
    QPlainTextEdit *plainTextEditAT;
    QWidget *tab;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonTestNN2S;
    QPushButton *pushButtonMeasNN2S;
    QPushButton *pushButtonClearPlot;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(598, 461);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_7 = new QGridLayout(tab_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        checkBoxConfigSmoothPlot = new QCheckBox(tab_3);
        checkBoxConfigSmoothPlot->setObjectName(QStringLiteral("checkBoxConfigSmoothPlot"));

        verticalLayout_4->addWidget(checkBoxConfigSmoothPlot);

        checkBoxConfigAntialias = new QCheckBox(tab_3);
        checkBoxConfigAntialias->setObjectName(QStringLiteral("checkBoxConfigAntialias"));

        verticalLayout_4->addWidget(checkBoxConfigAntialias);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        gridLayout_7->addLayout(verticalLayout_4, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        Connect = new QWidget();
        Connect->setObjectName(QStringLiteral("Connect"));
        gridLayout_3 = new QGridLayout(Connect);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBoxWirelessInterface = new QGroupBox(Connect);
        groupBoxWirelessInterface->setObjectName(QStringLiteral("groupBoxWirelessInterface"));
        gridLayout_2 = new QGridLayout(groupBoxWirelessInterface);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        pushButtonBTdiscoverDevices = new QPushButton(groupBoxWirelessInterface);
        pushButtonBTdiscoverDevices->setObjectName(QStringLiteral("pushButtonBTdiscoverDevices"));

        gridLayout_4->addWidget(pushButtonBTdiscoverDevices, 1, 0, 1, 1);

        radioButtonWiFi = new QRadioButton(groupBoxWirelessInterface);
        radioButtonWiFi->setObjectName(QStringLiteral("radioButtonWiFi"));

        gridLayout_4->addWidget(radioButtonWiFi, 0, 2, 1, 1);

        labelBTstatus = new QLabel(groupBoxWirelessInterface);
        labelBTstatus->setObjectName(QStringLiteral("labelBTstatus"));

        gridLayout_4->addWidget(labelBTstatus, 3, 0, 1, 1);

        radioButtonBT = new QRadioButton(groupBoxWirelessInterface);
        radioButtonBT->setObjectName(QStringLiteral("radioButtonBT"));
        radioButtonBT->setChecked(true);

        gridLayout_4->addWidget(radioButtonBT, 0, 0, 1, 1);

        comboBoxBTdevices = new QComboBox(groupBoxWirelessInterface);
        comboBoxBTdevices->setObjectName(QStringLiteral("comboBoxBTdevices"));

        gridLayout_4->addWidget(comboBoxBTdevices, 2, 0, 1, 1);

        pushButtonBTconnect = new QPushButton(groupBoxWirelessInterface);
        pushButtonBTconnect->setObjectName(QStringLiteral("pushButtonBTconnect"));

        gridLayout_4->addWidget(pushButtonBTconnect, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(groupBoxWirelessInterface);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        lineEditWiFiAddress = new QLineEdit(groupBoxWirelessInterface);
        lineEditWiFiAddress->setObjectName(QStringLiteral("lineEditWiFiAddress"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditWiFiAddress->sizePolicy().hasHeightForWidth());
        lineEditWiFiAddress->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lineEditWiFiAddress);


        gridLayout_4->addLayout(horizontalLayout_3, 1, 2, 1, 1);

        pushButtonWiFiConnect = new QPushButton(groupBoxWirelessInterface);
        pushButtonWiFiConnect->setObjectName(QStringLiteral("pushButtonWiFiConnect"));

        gridLayout_4->addWidget(pushButtonWiFiConnect, 5, 2, 1, 1);

        labelWiFiStatus = new QLabel(groupBoxWirelessInterface);
        labelWiFiStatus->setObjectName(QStringLiteral("labelWiFiStatus"));

        gridLayout_4->addWidget(labelWiFiStatus, 3, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelWiFiPort = new QLabel(groupBoxWirelessInterface);
        labelWiFiPort->setObjectName(QStringLiteral("labelWiFiPort"));

        horizontalLayout_4->addWidget(labelWiFiPort);

        lineEditWiFiPort = new QLineEdit(groupBoxWirelessInterface);
        lineEditWiFiPort->setObjectName(QStringLiteral("lineEditWiFiPort"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditWiFiPort->sizePolicy().hasHeightForWidth());
        lineEditWiFiPort->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lineEditWiFiPort);


        gridLayout_4->addLayout(horizontalLayout_4, 2, 2, 1, 1);

        pushButtonWiFiDisconnect = new QPushButton(groupBoxWirelessInterface);
        pushButtonWiFiDisconnect->setObjectName(QStringLiteral("pushButtonWiFiDisconnect"));

        gridLayout_4->addWidget(pushButtonWiFiDisconnect, 6, 2, 1, 1);

        pushButtonBTdisconnect = new QPushButton(groupBoxWirelessInterface);
        pushButtonBTdisconnect->setObjectName(QStringLiteral("pushButtonBTdisconnect"));

        gridLayout_4->addWidget(pushButtonBTdisconnect, 6, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBoxWirelessInterface, 0, 0, 1, 1);

        tabWidget->addTab(Connect, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEditAT = new QLineEdit(tab_2);
        lineEditAT->setObjectName(QStringLiteral("lineEditAT"));

        horizontalLayout->addWidget(lineEditAT);

        pushButtonATSend = new QPushButton(tab_2);
        pushButtonATSend->setObjectName(QStringLiteral("pushButtonATSend"));

        horizontalLayout->addWidget(pushButtonATSend);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout_5->addLayout(verticalLayout_2, 0, 0, 1, 1);

        plainTextEditAT = new QPlainTextEdit(tab_2);
        plainTextEditAT->setObjectName(QStringLiteral("plainTextEditAT"));

        gridLayout_5->addWidget(plainTextEditAT, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonTestNN2S = new QPushButton(tab);
        pushButtonTestNN2S->setObjectName(QStringLiteral("pushButtonTestNN2S"));

        horizontalLayout_2->addWidget(pushButtonTestNN2S);

        pushButtonMeasNN2S = new QPushButton(tab);
        pushButtonMeasNN2S->setObjectName(QStringLiteral("pushButtonMeasNN2S"));

        horizontalLayout_2->addWidget(pushButtonMeasNN2S);

        pushButtonClearPlot = new QPushButton(tab);
        pushButtonClearPlot->setObjectName(QStringLiteral("pushButtonClearPlot"));

        horizontalLayout_2->addWidget(pushButtonClearPlot);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout_6->addLayout(verticalLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 598, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(radioButtonBT, radioButtonWiFi);
        QWidget::setTabOrder(radioButtonWiFi, lineEditWiFiAddress);
        QWidget::setTabOrder(lineEditWiFiAddress, lineEditWiFiPort);
        QWidget::setTabOrder(lineEditWiFiPort, pushButtonWiFiConnect);
        QWidget::setTabOrder(pushButtonWiFiConnect, pushButtonWiFiDisconnect);
        QWidget::setTabOrder(pushButtonWiFiDisconnect, pushButtonBTdiscoverDevices);
        QWidget::setTabOrder(pushButtonBTdiscoverDevices, comboBoxBTdevices);
        QWidget::setTabOrder(comboBoxBTdevices, pushButtonBTconnect);
        QWidget::setTabOrder(pushButtonBTconnect, tabWidget);
        QWidget::setTabOrder(tabWidget, lineEditAT);
        QWidget::setTabOrder(lineEditAT, pushButtonATSend);
        QWidget::setTabOrder(pushButtonATSend, plainTextEditAT);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Nanonets2Sense", nullptr));
        checkBoxConfigSmoothPlot->setText(QApplication::translate("MainWindow", "Smooth Plot", nullptr));
        checkBoxConfigAntialias->setText(QApplication::translate("MainWindow", "Antialias filtering", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Config", nullptr));
        groupBoxWirelessInterface->setTitle(QApplication::translate("MainWindow", "Wireless interface:", nullptr));
        pushButtonBTdiscoverDevices->setText(QApplication::translate("MainWindow", "Discover BT", nullptr));
        radioButtonWiFi->setText(QApplication::translate("MainWindow", "WiFi", nullptr));
        labelBTstatus->setText(QApplication::translate("MainWindow", "Status:", nullptr));
        radioButtonBT->setText(QApplication::translate("MainWindow", "Bluetooth", nullptr));
        pushButtonBTconnect->setText(QApplication::translate("MainWindow", "Connect BT", nullptr));
        label->setText(QApplication::translate("MainWindow", "IP Address:", nullptr));
        pushButtonWiFiConnect->setText(QApplication::translate("MainWindow", "Connect WiFi", nullptr));
        labelWiFiStatus->setText(QApplication::translate("MainWindow", "Status:", nullptr));
        labelWiFiPort->setText(QApplication::translate("MainWindow", "Port:", nullptr));
        pushButtonWiFiDisconnect->setText(QApplication::translate("MainWindow", "Disconnect WiFi", nullptr));
        pushButtonBTdisconnect->setText(QApplication::translate("MainWindow", "Disconnect BT", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Connect), QApplication::translate("MainWindow", "Connect", nullptr));
        pushButtonATSend->setText(QApplication::translate("MainWindow", "Send", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "AT", nullptr));
        pushButtonTestNN2S->setText(QApplication::translate("MainWindow", "Self Test", nullptr));
        pushButtonMeasNN2S->setText(QApplication::translate("MainWindow", "Measure", nullptr));
        pushButtonClearPlot->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Plot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
