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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Run;
    QAction *action_Save;
    QAction *action_Clean;
    QAction *action_Delete_sweep;
    QAction *action0V90;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
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
    QWidget *tab_3;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_9;
    QCheckBox *checkBoxConfigSmoothPlot;
    QCheckBox *checkBoxConfigAntialias;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_10;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *lineEditTagName;
    QPushButton *pushButtonAddTag;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QComboBox *comboBoxTagSelect;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButtonSaveTag;
    QPushButton *pushButtonLoadTag;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLineEdit *lineEditAdditionalData;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QComboBox *comboBoxPA_config;
    QLabel *label_PA_ID;
    QSpacerItem *verticalSpacer;
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
    QWidget *tab_4;
    QGridLayout *gridLayout_11;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QTableView *tableViewMag;
    QLabel *label_3;
    QTableView *tableViewMagStat;
    QWidget *tab_5;
    QGridLayout *gridLayout_12;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QTableView *tableViewPha;
    QLabel *label_5;
    QTableView *tableViewPhaStat;
    QWidget *tab_6;
    QGridLayout *gridLayout_8;
    QTableView *tableViewCalibration;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *checkBoxGainCalibration;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonGenerateCalibration;
    QPushButton *pushButtonOpenCalFile;
    QPushButton *pushButtonSaveCalFile;
    QMenuBar *menuBar;
    QMenu *menu_Measurement;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(878, 599);
        action_Run = new QAction(MainWindow);
        action_Run->setObjectName(QStringLiteral("action_Run"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/Button-Play-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Run->setIcon(icon);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QStringLiteral("action_Save"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/Save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon1);
        action_Clean = new QAction(MainWindow);
        action_Clean->setObjectName(QStringLiteral("action_Clean"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/Clean-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Clean->setIcon(icon2);
        action_Delete_sweep = new QAction(MainWindow);
        action_Delete_sweep->setObjectName(QStringLiteral("action_Delete_sweep"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/images/Delete-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Delete_sweep->setIcon(icon3);
        action0V90 = new QAction(MainWindow);
        action0V90->setObjectName(QStringLiteral("action0V90"));
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
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_7 = new QGridLayout(tab_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_9 = new QGridLayout(groupBox);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        checkBoxConfigSmoothPlot = new QCheckBox(groupBox);
        checkBoxConfigSmoothPlot->setObjectName(QStringLiteral("checkBoxConfigSmoothPlot"));

        gridLayout_9->addWidget(checkBoxConfigSmoothPlot, 0, 0, 1, 1);

        checkBoxConfigAntialias = new QCheckBox(groupBox);
        checkBoxConfigAntialias->setObjectName(QStringLiteral("checkBoxConfigAntialias"));

        gridLayout_9->addWidget(checkBoxConfigAntialias, 1, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_10 = new QGridLayout(groupBox_2);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        lineEditTagName = new QLineEdit(groupBox_2);
        lineEditTagName->setObjectName(QStringLiteral("lineEditTagName"));

        horizontalLayout_6->addWidget(lineEditTagName);

        pushButtonAddTag = new QPushButton(groupBox_2);
        pushButtonAddTag->setObjectName(QStringLiteral("pushButtonAddTag"));

        horizontalLayout_6->addWidget(pushButtonAddTag);


        gridLayout_10->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        comboBoxTagSelect = new QComboBox(groupBox_2);
        comboBoxTagSelect->setObjectName(QStringLiteral("comboBoxTagSelect"));

        horizontalLayout_8->addWidget(comboBoxTagSelect);


        gridLayout_10->addLayout(horizontalLayout_8, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButtonSaveTag = new QPushButton(groupBox_2);
        pushButtonSaveTag->setObjectName(QStringLiteral("pushButtonSaveTag"));

        horizontalLayout_7->addWidget(pushButtonSaveTag);

        pushButtonLoadTag = new QPushButton(groupBox_2);
        pushButtonLoadTag->setObjectName(QStringLiteral("pushButtonLoadTag"));

        horizontalLayout_7->addWidget(pushButtonLoadTag);


        gridLayout_10->addLayout(horizontalLayout_7, 2, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_10->addWidget(label_9);

        lineEditAdditionalData = new QLineEdit(groupBox_2);
        lineEditAdditionalData->setObjectName(QStringLiteral("lineEditAdditionalData"));

        horizontalLayout_10->addWidget(lineEditAdditionalData);


        gridLayout_10->addLayout(horizontalLayout_10, 3, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        formLayout = new QFormLayout(groupBox_3);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_11->addWidget(label_10);

        comboBoxPA_config = new QComboBox(groupBox_3);
        comboBoxPA_config->setObjectName(QStringLiteral("comboBoxPA_config"));

        horizontalLayout_11->addWidget(comboBoxPA_config);

        label_PA_ID = new QLabel(groupBox_3);
        label_PA_ID->setObjectName(QStringLiteral("label_PA_ID"));

        horizontalLayout_11->addWidget(label_PA_ID);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_11);


        verticalLayout_4->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        gridLayout_7->addLayout(verticalLayout_4, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
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

        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout_6->addLayout(verticalLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_11 = new QGridLayout(tab_4);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_2 = new QLabel(tab_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_6->addWidget(label_2);

        tableViewMag = new QTableView(tab_4);
        tableViewMag->setObjectName(QStringLiteral("tableViewMag"));

        verticalLayout_6->addWidget(tableViewMag);

        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_6->addWidget(label_3);

        tableViewMagStat = new QTableView(tab_4);
        tableViewMagStat->setObjectName(QStringLiteral("tableViewMagStat"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableViewMagStat->sizePolicy().hasHeightForWidth());
        tableViewMagStat->setSizePolicy(sizePolicy2);
        tableViewMagStat->setBaseSize(QSize(0, 0));

        verticalLayout_6->addWidget(tableViewMagStat);


        gridLayout_11->addLayout(verticalLayout_6, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_12 = new QGridLayout(tab_5);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_4 = new QLabel(tab_5);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_7->addWidget(label_4);

        tableViewPha = new QTableView(tab_5);
        tableViewPha->setObjectName(QStringLiteral("tableViewPha"));

        verticalLayout_7->addWidget(tableViewPha);

        label_5 = new QLabel(tab_5);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_7->addWidget(label_5);

        tableViewPhaStat = new QTableView(tab_5);
        tableViewPhaStat->setObjectName(QStringLiteral("tableViewPhaStat"));

        verticalLayout_7->addWidget(tableViewPhaStat);


        gridLayout_12->addLayout(verticalLayout_7, 0, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        gridLayout_8 = new QGridLayout(tab_6);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        tableViewCalibration = new QTableView(tab_6);
        tableViewCalibration->setObjectName(QStringLiteral("tableViewCalibration"));

        gridLayout_8->addWidget(tableViewCalibration, 1, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        checkBoxGainCalibration = new QCheckBox(tab_6);
        checkBoxGainCalibration->setObjectName(QStringLiteral("checkBoxGainCalibration"));

        verticalLayout_5->addWidget(checkBoxGainCalibration);

        label_6 = new QLabel(tab_6);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_5->addWidget(label_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButtonGenerateCalibration = new QPushButton(tab_6);
        pushButtonGenerateCalibration->setObjectName(QStringLiteral("pushButtonGenerateCalibration"));

        horizontalLayout_5->addWidget(pushButtonGenerateCalibration);

        pushButtonOpenCalFile = new QPushButton(tab_6);
        pushButtonOpenCalFile->setObjectName(QStringLiteral("pushButtonOpenCalFile"));

        horizontalLayout_5->addWidget(pushButtonOpenCalFile);

        pushButtonSaveCalFile = new QPushButton(tab_6);
        pushButtonSaveCalFile->setObjectName(QStringLiteral("pushButtonSaveCalFile"));

        horizontalLayout_5->addWidget(pushButtonSaveCalFile);


        verticalLayout_5->addLayout(horizontalLayout_5);


        gridLayout_8->addLayout(verticalLayout_5, 0, 0, 1, 1);

        tabWidget->addTab(tab_6, QString());

        verticalLayout->addWidget(tabWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 878, 22));
        menu_Measurement = new QMenu(menuBar);
        menu_Measurement->setObjectName(QStringLiteral("menu_Measurement"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(pushButtonBTdiscoverDevices, comboBoxBTdevices);
        QWidget::setTabOrder(comboBoxBTdevices, pushButtonBTconnect);
        QWidget::setTabOrder(pushButtonBTconnect, lineEditTagName);
        QWidget::setTabOrder(lineEditTagName, pushButtonAddTag);
        QWidget::setTabOrder(pushButtonAddTag, pushButtonSaveTag);
        QWidget::setTabOrder(pushButtonSaveTag, pushButtonLoadTag);
        QWidget::setTabOrder(pushButtonLoadTag, pushButtonGenerateCalibration);
        QWidget::setTabOrder(pushButtonGenerateCalibration, pushButtonOpenCalFile);
        QWidget::setTabOrder(pushButtonOpenCalFile, pushButtonSaveCalFile);
        QWidget::setTabOrder(pushButtonSaveCalFile, checkBoxGainCalibration);
        QWidget::setTabOrder(checkBoxGainCalibration, plainTextEditAT);
        QWidget::setTabOrder(plainTextEditAT, tabWidget);
        QWidget::setTabOrder(tabWidget, checkBoxConfigSmoothPlot);
        QWidget::setTabOrder(checkBoxConfigSmoothPlot, checkBoxConfigAntialias);
        QWidget::setTabOrder(checkBoxConfigAntialias, lineEditWiFiPort);
        QWidget::setTabOrder(lineEditWiFiPort, pushButtonWiFiConnect);
        QWidget::setTabOrder(pushButtonWiFiConnect, comboBoxTagSelect);
        QWidget::setTabOrder(comboBoxTagSelect, pushButtonWiFiDisconnect);
        QWidget::setTabOrder(pushButtonWiFiDisconnect, radioButtonBT);
        QWidget::setTabOrder(radioButtonBT, lineEditAdditionalData);
        QWidget::setTabOrder(lineEditAdditionalData, pushButtonBTdisconnect);
        QWidget::setTabOrder(pushButtonBTdisconnect, tableViewMag);
        QWidget::setTabOrder(tableViewMag, tableViewMagStat);
        QWidget::setTabOrder(tableViewMagStat, tableViewPha);
        QWidget::setTabOrder(tableViewPha, tableViewPhaStat);
        QWidget::setTabOrder(tableViewPhaStat, tableViewCalibration);
        QWidget::setTabOrder(tableViewCalibration, pushButtonATSend);
        QWidget::setTabOrder(pushButtonATSend, radioButtonWiFi);
        QWidget::setTabOrder(radioButtonWiFi, lineEditWiFiAddress);
        QWidget::setTabOrder(lineEditWiFiAddress, lineEditAT);

        menuBar->addAction(menu_Measurement->menuAction());
        menu_Measurement->addAction(action_Run);
        menu_Measurement->addAction(action_Save);
        menu_Measurement->addAction(action_Clean);
        menu_Measurement->addAction(action_Delete_sweep);
        mainToolBar->addAction(action_Run);
        mainToolBar->addAction(action_Save);
        mainToolBar->addAction(action_Clean);
        mainToolBar->addAction(action_Delete_sweep);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Nanonets2Sense", nullptr));
        action_Run->setText(QApplication::translate("MainWindow", "&Run", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Run->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        action_Save->setText(QApplication::translate("MainWindow", "&Save ", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Save->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        action_Clean->setText(QApplication::translate("MainWindow", "&Clean", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Clean->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        action_Delete_sweep->setText(QApplication::translate("MainWindow", "&Delete sweep", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Delete_sweep->setShortcut(QApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_NO_SHORTCUT
        action0V90->setText(QApplication::translate("MainWindow", "0V90", nullptr));
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
        groupBox->setTitle(QApplication::translate("MainWindow", "Plot Properties", nullptr));
        checkBoxConfigSmoothPlot->setText(QApplication::translate("MainWindow", "Smooth Plot", nullptr));
        checkBoxConfigAntialias->setText(QApplication::translate("MainWindow", "Antialias filtering", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Measurement Properties", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "New Tag name:", nullptr));
        pushButtonAddTag->setText(QApplication::translate("MainWindow", "Add Tag", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Selected Tag", nullptr));
        pushButtonSaveTag->setText(QApplication::translate("MainWindow", "Save List", nullptr));
        pushButtonLoadTag->setText(QApplication::translate("MainWindow", "Load List", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Additional Data:", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Reader Configuration", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "VDD PA", nullptr));
        label_PA_ID->setText(QApplication::translate("MainWindow", "ID = ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Config", nullptr));
        pushButtonATSend->setText(QApplication::translate("MainWindow", "Send", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "AT", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Plot", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Magnitude Measurements", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Average and Standard deviation (%)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Mag", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Phase Measurements", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Average and Standard deviation (degree)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Pha", nullptr));
        checkBoxGainCalibration->setText(QApplication::translate("MainWindow", "Enable Gain calibration", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Calibration table for 1 kOhm reference", nullptr));
        pushButtonGenerateCalibration->setText(QApplication::translate("MainWindow", "Generate Calibration coeff.", nullptr));
        pushButtonOpenCalFile->setText(QApplication::translate("MainWindow", "Open Cal. File", nullptr));
        pushButtonSaveCalFile->setText(QApplication::translate("MainWindow", "Save Cal. File", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Cal", nullptr));
        menu_Measurement->setTitle(QApplication::translate("MainWindow", "&Measurement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
