/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
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
    QAction *action_Run;
    QAction *action_Save;
    QAction *action_Clean;
    QAction *actionStop;
    QAction *action_Open;
    QAction *action_Display_program;
    QAction *actionSensors;
    QAction *actionSearch;
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
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_14;
    QLineEdit *lineEditChannel4;
    QPushButton *pushButtonChannel4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_8;
    QLineEdit *lineEditRampUp;
    QPushButton *pushButtonRampUp;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_9;
    QLineEdit *lineEditRampDown;
    QPushButton *pushButtonRampDown;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_13;
    QLineEdit *lineEditChannel3;
    QPushButton *pushButtonChannel3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QLineEdit *lineEditSymetry;
    QPushButton *pushButtonSymetry;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *lineEditPhase;
    QPushButton *pushButtonPhase;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *lineEditAmplitude;
    QPushButton *pushButtonAmplitude;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_7;
    QLineEdit *lineEditOFF;
    QPushButton *pushButtonOFF;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_10;
    QLineEdit *lineEditContractions;
    QPushButton *pushButtonContractions;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_12;
    QLineEdit *lineEditChannel2;
    QPushButton *pushButtonChannel2;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_11;
    QLineEdit *lineEditChannel1;
    QPushButton *pushButtonChannel1;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QLineEdit *lineEditON;
    QPushButton *pushButtonOnTime;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *lineEditFrequency;
    QPushButton *pushButtonFrequency;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_15;
    QLineEdit *lineEditAmplitude2;
    QPushButton *pushButtonAmplitude2;
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
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelScale;
    QSlider *verticalSliderEnergyMax;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelEnergy;
    QProgressBar *progressBarEnergy;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_16;
    QLabel *labelEnergyRange;
    QLabel *label_17;
    QLabel *labelEnergyValue;
    QLabel *label_20;
    QLabel *labelThreshold;
    QLabel *label_21;
    QLabel *labelEnergyMax;
    QPushButton *pushButtonResetMaxEnergy;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_18;
    QSlider *verticalSliderEnergyThreshold;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_19;
    QProgressBar *progressBarMuscle;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_5;
    QPlainTextEdit *plainTextEditSearch;
    QMenuBar *menuBar;
    QMenu *menu_Measurement;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(877, 611);
        action_Run = new QAction(MainWindow);
        action_Run->setObjectName(QString::fromUtf8("action_Run"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Button-Play-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Run->setIcon(icon);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/Save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save->setIcon(icon1);
        action_Clean = new QAction(MainWindow);
        action_Clean->setObjectName(QString::fromUtf8("action_Clean"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/Clean-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Clean->setIcon(icon2);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/Stop-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon3);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/Open_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open->setIcon(icon4);
        action_Display_program = new QAction(MainWindow);
        action_Display_program->setObjectName(QString::fromUtf8("action_Display_program"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/Read_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Display_program->setIcon(icon5);
        actionSensors = new QAction(MainWindow);
        actionSensors->setObjectName(QString::fromUtf8("actionSensors"));
        actionSensors->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/sensor.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSensors->setIcon(icon6);
        actionSearch = new QAction(MainWindow);
        actionSearch->setObjectName(QString::fromUtf8("actionSearch"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSearch->setIcon(icon7);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        Connect = new QWidget();
        Connect->setObjectName(QString::fromUtf8("Connect"));
        gridLayout_3 = new QGridLayout(Connect);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBoxWirelessInterface = new QGroupBox(Connect);
        groupBoxWirelessInterface->setObjectName(QString::fromUtf8("groupBoxWirelessInterface"));
        gridLayout_2 = new QGridLayout(groupBoxWirelessInterface);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButtonBTdiscoverDevices = new QPushButton(groupBoxWirelessInterface);
        pushButtonBTdiscoverDevices->setObjectName(QString::fromUtf8("pushButtonBTdiscoverDevices"));

        gridLayout_4->addWidget(pushButtonBTdiscoverDevices, 1, 0, 1, 1);

        radioButtonWiFi = new QRadioButton(groupBoxWirelessInterface);
        radioButtonWiFi->setObjectName(QString::fromUtf8("radioButtonWiFi"));

        gridLayout_4->addWidget(radioButtonWiFi, 0, 2, 1, 1);

        labelBTstatus = new QLabel(groupBoxWirelessInterface);
        labelBTstatus->setObjectName(QString::fromUtf8("labelBTstatus"));

        gridLayout_4->addWidget(labelBTstatus, 3, 0, 1, 1);

        radioButtonBT = new QRadioButton(groupBoxWirelessInterface);
        radioButtonBT->setObjectName(QString::fromUtf8("radioButtonBT"));
        radioButtonBT->setChecked(true);

        gridLayout_4->addWidget(radioButtonBT, 0, 0, 1, 1);

        comboBoxBTdevices = new QComboBox(groupBoxWirelessInterface);
        comboBoxBTdevices->setObjectName(QString::fromUtf8("comboBoxBTdevices"));

        gridLayout_4->addWidget(comboBoxBTdevices, 2, 0, 1, 1);

        pushButtonBTconnect = new QPushButton(groupBoxWirelessInterface);
        pushButtonBTconnect->setObjectName(QString::fromUtf8("pushButtonBTconnect"));

        gridLayout_4->addWidget(pushButtonBTconnect, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(groupBoxWirelessInterface);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        lineEditWiFiAddress = new QLineEdit(groupBoxWirelessInterface);
        lineEditWiFiAddress->setObjectName(QString::fromUtf8("lineEditWiFiAddress"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditWiFiAddress->sizePolicy().hasHeightForWidth());
        lineEditWiFiAddress->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lineEditWiFiAddress);


        gridLayout_4->addLayout(horizontalLayout_3, 1, 2, 1, 1);

        pushButtonWiFiConnect = new QPushButton(groupBoxWirelessInterface);
        pushButtonWiFiConnect->setObjectName(QString::fromUtf8("pushButtonWiFiConnect"));

        gridLayout_4->addWidget(pushButtonWiFiConnect, 5, 2, 1, 1);

        labelWiFiStatus = new QLabel(groupBoxWirelessInterface);
        labelWiFiStatus->setObjectName(QString::fromUtf8("labelWiFiStatus"));

        gridLayout_4->addWidget(labelWiFiStatus, 3, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelWiFiPort = new QLabel(groupBoxWirelessInterface);
        labelWiFiPort->setObjectName(QString::fromUtf8("labelWiFiPort"));

        horizontalLayout_4->addWidget(labelWiFiPort);

        lineEditWiFiPort = new QLineEdit(groupBoxWirelessInterface);
        lineEditWiFiPort->setObjectName(QString::fromUtf8("lineEditWiFiPort"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditWiFiPort->sizePolicy().hasHeightForWidth());
        lineEditWiFiPort->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lineEditWiFiPort);


        gridLayout_4->addLayout(horizontalLayout_4, 2, 2, 1, 1);

        pushButtonWiFiDisconnect = new QPushButton(groupBoxWirelessInterface);
        pushButtonWiFiDisconnect->setObjectName(QString::fromUtf8("pushButtonWiFiDisconnect"));

        gridLayout_4->addWidget(pushButtonWiFiDisconnect, 6, 2, 1, 1);

        pushButtonBTdisconnect = new QPushButton(groupBoxWirelessInterface);
        pushButtonBTdisconnect->setObjectName(QString::fromUtf8("pushButtonBTdisconnect"));

        gridLayout_4->addWidget(pushButtonBTdisconnect, 6, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBoxWirelessInterface, 0, 0, 1, 1);

        tabWidget->addTab(Connect, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_7 = new QGridLayout(tab_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_18->addWidget(label_14);

        lineEditChannel4 = new QLineEdit(tab_3);
        lineEditChannel4->setObjectName(QString::fromUtf8("lineEditChannel4"));

        horizontalLayout_18->addWidget(lineEditChannel4);

        pushButtonChannel4 = new QPushButton(tab_3);
        pushButtonChannel4->setObjectName(QString::fromUtf8("pushButtonChannel4"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonChannel4->sizePolicy().hasHeightForWidth());
        pushButtonChannel4->setSizePolicy(sizePolicy2);

        horizontalLayout_18->addWidget(pushButtonChannel4);


        gridLayout_7->addLayout(horizontalLayout_18, 19, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_12->addWidget(label_8);

        lineEditRampUp = new QLineEdit(tab_3);
        lineEditRampUp->setObjectName(QString::fromUtf8("lineEditRampUp"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEditRampUp->sizePolicy().hasHeightForWidth());
        lineEditRampUp->setSizePolicy(sizePolicy3);

        horizontalLayout_12->addWidget(lineEditRampUp);

        pushButtonRampUp = new QPushButton(tab_3);
        pushButtonRampUp->setObjectName(QString::fromUtf8("pushButtonRampUp"));
        sizePolicy3.setHeightForWidth(pushButtonRampUp->sizePolicy().hasHeightForWidth());
        pushButtonRampUp->setSizePolicy(sizePolicy3);

        horizontalLayout_12->addWidget(pushButtonRampUp);


        gridLayout_7->addLayout(horizontalLayout_12, 7, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_13->addWidget(label_9);

        lineEditRampDown = new QLineEdit(tab_3);
        lineEditRampDown->setObjectName(QString::fromUtf8("lineEditRampDown"));

        horizontalLayout_13->addWidget(lineEditRampDown);

        pushButtonRampDown = new QPushButton(tab_3);
        pushButtonRampDown->setObjectName(QString::fromUtf8("pushButtonRampDown"));
        sizePolicy3.setHeightForWidth(pushButtonRampDown->sizePolicy().hasHeightForWidth());
        pushButtonRampDown->setSizePolicy(sizePolicy3);

        horizontalLayout_13->addWidget(pushButtonRampDown);


        gridLayout_7->addLayout(horizontalLayout_13, 8, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_8->addWidget(label_13);

        lineEditChannel3 = new QLineEdit(tab_3);
        lineEditChannel3->setObjectName(QString::fromUtf8("lineEditChannel3"));
        sizePolicy2.setHeightForWidth(lineEditChannel3->sizePolicy().hasHeightForWidth());
        lineEditChannel3->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(lineEditChannel3);

        pushButtonChannel3 = new QPushButton(tab_3);
        pushButtonChannel3->setObjectName(QString::fromUtf8("pushButtonChannel3"));
        sizePolicy2.setHeightForWidth(pushButtonChannel3->sizePolicy().hasHeightForWidth());
        pushButtonChannel3->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(pushButtonChannel3);


        gridLayout_7->addLayout(horizontalLayout_8, 12, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_9->addWidget(label_5);

        lineEditSymetry = new QLineEdit(tab_3);
        lineEditSymetry->setObjectName(QString::fromUtf8("lineEditSymetry"));
        sizePolicy3.setHeightForWidth(lineEditSymetry->sizePolicy().hasHeightForWidth());
        lineEditSymetry->setSizePolicy(sizePolicy3);

        horizontalLayout_9->addWidget(lineEditSymetry);

        pushButtonSymetry = new QPushButton(tab_3);
        pushButtonSymetry->setObjectName(QString::fromUtf8("pushButtonSymetry"));
        sizePolicy3.setHeightForWidth(pushButtonSymetry->sizePolicy().hasHeightForWidth());
        pushButtonSymetry->setSizePolicy(sizePolicy3);

        horizontalLayout_9->addWidget(pushButtonSymetry);


        gridLayout_7->addLayout(horizontalLayout_9, 4, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_7->addWidget(label_4);

        lineEditPhase = new QLineEdit(tab_3);
        lineEditPhase->setObjectName(QString::fromUtf8("lineEditPhase"));
        sizePolicy3.setHeightForWidth(lineEditPhase->sizePolicy().hasHeightForWidth());
        lineEditPhase->setSizePolicy(sizePolicy3);

        horizontalLayout_7->addWidget(lineEditPhase);

        pushButtonPhase = new QPushButton(tab_3);
        pushButtonPhase->setObjectName(QString::fromUtf8("pushButtonPhase"));
        sizePolicy3.setHeightForWidth(pushButtonPhase->sizePolicy().hasHeightForWidth());
        pushButtonPhase->setSizePolicy(sizePolicy3);

        horizontalLayout_7->addWidget(pushButtonPhase);


        gridLayout_7->addLayout(horizontalLayout_7, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, 0, -1);
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        lineEditAmplitude = new QLineEdit(tab_3);
        lineEditAmplitude->setObjectName(QString::fromUtf8("lineEditAmplitude"));
        sizePolicy3.setHeightForWidth(lineEditAmplitude->sizePolicy().hasHeightForWidth());
        lineEditAmplitude->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(lineEditAmplitude);

        pushButtonAmplitude = new QPushButton(tab_3);
        pushButtonAmplitude->setObjectName(QString::fromUtf8("pushButtonAmplitude"));
        sizePolicy3.setHeightForWidth(pushButtonAmplitude->sizePolicy().hasHeightForWidth());
        pushButtonAmplitude->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(pushButtonAmplitude);


        gridLayout_7->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_11->addWidget(label_7);

        lineEditOFF = new QLineEdit(tab_3);
        lineEditOFF->setObjectName(QString::fromUtf8("lineEditOFF"));
        sizePolicy3.setHeightForWidth(lineEditOFF->sizePolicy().hasHeightForWidth());
        lineEditOFF->setSizePolicy(sizePolicy3);

        horizontalLayout_11->addWidget(lineEditOFF);

        pushButtonOFF = new QPushButton(tab_3);
        pushButtonOFF->setObjectName(QString::fromUtf8("pushButtonOFF"));
        sizePolicy3.setHeightForWidth(pushButtonOFF->sizePolicy().hasHeightForWidth());
        pushButtonOFF->setSizePolicy(sizePolicy3);

        horizontalLayout_11->addWidget(pushButtonOFF);


        gridLayout_7->addLayout(horizontalLayout_11, 6, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_14->addWidget(label_10);

        lineEditContractions = new QLineEdit(tab_3);
        lineEditContractions->setObjectName(QString::fromUtf8("lineEditContractions"));

        horizontalLayout_14->addWidget(lineEditContractions);

        pushButtonContractions = new QPushButton(tab_3);
        pushButtonContractions->setObjectName(QString::fromUtf8("pushButtonContractions"));
        sizePolicy3.setHeightForWidth(pushButtonContractions->sizePolicy().hasHeightForWidth());
        pushButtonContractions->setSizePolicy(sizePolicy3);

        horizontalLayout_14->addWidget(pushButtonContractions);


        gridLayout_7->addLayout(horizontalLayout_14, 9, 0, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_16->addWidget(label_12);

        lineEditChannel2 = new QLineEdit(tab_3);
        lineEditChannel2->setObjectName(QString::fromUtf8("lineEditChannel2"));
        sizePolicy3.setHeightForWidth(lineEditChannel2->sizePolicy().hasHeightForWidth());
        lineEditChannel2->setSizePolicy(sizePolicy3);

        horizontalLayout_16->addWidget(lineEditChannel2);

        pushButtonChannel2 = new QPushButton(tab_3);
        pushButtonChannel2->setObjectName(QString::fromUtf8("pushButtonChannel2"));
        sizePolicy3.setHeightForWidth(pushButtonChannel2->sizePolicy().hasHeightForWidth());
        pushButtonChannel2->setSizePolicy(sizePolicy3);

        horizontalLayout_16->addWidget(pushButtonChannel2);


        gridLayout_7->addLayout(horizontalLayout_16, 11, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_15->addWidget(label_11);

        lineEditChannel1 = new QLineEdit(tab_3);
        lineEditChannel1->setObjectName(QString::fromUtf8("lineEditChannel1"));
        sizePolicy3.setHeightForWidth(lineEditChannel1->sizePolicy().hasHeightForWidth());
        lineEditChannel1->setSizePolicy(sizePolicy3);

        horizontalLayout_15->addWidget(lineEditChannel1);

        pushButtonChannel1 = new QPushButton(tab_3);
        pushButtonChannel1->setObjectName(QString::fromUtf8("pushButtonChannel1"));
        sizePolicy3.setHeightForWidth(pushButtonChannel1->sizePolicy().hasHeightForWidth());
        pushButtonChannel1->setSizePolicy(sizePolicy3);

        horizontalLayout_15->addWidget(pushButtonChannel1);


        gridLayout_7->addLayout(horizontalLayout_15, 10, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_10->addWidget(label_6);

        lineEditON = new QLineEdit(tab_3);
        lineEditON->setObjectName(QString::fromUtf8("lineEditON"));
        sizePolicy3.setHeightForWidth(lineEditON->sizePolicy().hasHeightForWidth());
        lineEditON->setSizePolicy(sizePolicy3);

        horizontalLayout_10->addWidget(lineEditON);

        pushButtonOnTime = new QPushButton(tab_3);
        pushButtonOnTime->setObjectName(QString::fromUtf8("pushButtonOnTime"));
        sizePolicy3.setHeightForWidth(pushButtonOnTime->sizePolicy().hasHeightForWidth());
        pushButtonOnTime->setSizePolicy(sizePolicy3);

        horizontalLayout_10->addWidget(pushButtonOnTime);


        gridLayout_7->addLayout(horizontalLayout_10, 5, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        lineEditFrequency = new QLineEdit(tab_3);
        lineEditFrequency->setObjectName(QString::fromUtf8("lineEditFrequency"));
        sizePolicy3.setHeightForWidth(lineEditFrequency->sizePolicy().hasHeightForWidth());
        lineEditFrequency->setSizePolicy(sizePolicy3);

        horizontalLayout_6->addWidget(lineEditFrequency);

        pushButtonFrequency = new QPushButton(tab_3);
        pushButtonFrequency->setObjectName(QString::fromUtf8("pushButtonFrequency"));
        sizePolicy3.setHeightForWidth(pushButtonFrequency->sizePolicy().hasHeightForWidth());
        pushButtonFrequency->setSizePolicy(sizePolicy3);

        horizontalLayout_6->addWidget(pushButtonFrequency);


        gridLayout_7->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_17->addWidget(label_15);

        lineEditAmplitude2 = new QLineEdit(tab_3);
        lineEditAmplitude2->setObjectName(QString::fromUtf8("lineEditAmplitude2"));

        horizontalLayout_17->addWidget(lineEditAmplitude2);

        pushButtonAmplitude2 = new QPushButton(tab_3);
        pushButtonAmplitude2->setObjectName(QString::fromUtf8("pushButtonAmplitude2"));
        sizePolicy2.setHeightForWidth(pushButtonAmplitude2->sizePolicy().hasHeightForWidth());
        pushButtonAmplitude2->setSizePolicy(sizePolicy2);

        horizontalLayout_17->addWidget(pushButtonAmplitude2);


        gridLayout_7->addLayout(horizontalLayout_17, 1, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEditAT = new QLineEdit(tab_2);
        lineEditAT->setObjectName(QString::fromUtf8("lineEditAT"));

        horizontalLayout->addWidget(lineEditAT);

        pushButtonATSend = new QPushButton(tab_2);
        pushButtonATSend->setObjectName(QString::fromUtf8("pushButtonATSend"));

        horizontalLayout->addWidget(pushButtonATSend);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout_5->addLayout(verticalLayout_2, 0, 0, 1, 1);

        plainTextEditAT = new QPlainTextEdit(tab_2);
        plainTextEditAT->setObjectName(QString::fromUtf8("plainTextEditAT"));

        gridLayout_5->addWidget(plainTextEditAT, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout_6->addLayout(verticalLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_8 = new QGridLayout(tab_4);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        labelScale = new QLabel(tab_4);
        labelScale->setObjectName(QString::fromUtf8("labelScale"));

        verticalLayout_5->addWidget(labelScale);

        verticalSliderEnergyMax = new QSlider(tab_4);
        verticalSliderEnergyMax->setObjectName(QString::fromUtf8("verticalSliderEnergyMax"));
        verticalSliderEnergyMax->setMaximum(5);
        verticalSliderEnergyMax->setOrientation(Qt::Vertical);

        verticalLayout_5->addWidget(verticalSliderEnergyMax);


        horizontalLayout_19->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelEnergy = new QLabel(tab_4);
        labelEnergy->setObjectName(QString::fromUtf8("labelEnergy"));

        verticalLayout_4->addWidget(labelEnergy);

        progressBarEnergy = new QProgressBar(tab_4);
        progressBarEnergy->setObjectName(QString::fromUtf8("progressBarEnergy"));
        progressBarEnergy->setValue(24);
        progressBarEnergy->setOrientation(Qt::Vertical);

        verticalLayout_4->addWidget(progressBarEnergy);


        horizontalLayout_19->addLayout(verticalLayout_4);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_16 = new QLabel(tab_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_8->addWidget(label_16);

        labelEnergyRange = new QLabel(tab_4);
        labelEnergyRange->setObjectName(QString::fromUtf8("labelEnergyRange"));

        verticalLayout_8->addWidget(labelEnergyRange);

        label_17 = new QLabel(tab_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_8->addWidget(label_17);

        labelEnergyValue = new QLabel(tab_4);
        labelEnergyValue->setObjectName(QString::fromUtf8("labelEnergyValue"));

        verticalLayout_8->addWidget(labelEnergyValue);

        label_20 = new QLabel(tab_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_8->addWidget(label_20);

        labelThreshold = new QLabel(tab_4);
        labelThreshold->setObjectName(QString::fromUtf8("labelThreshold"));

        verticalLayout_8->addWidget(labelThreshold);

        label_21 = new QLabel(tab_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_8->addWidget(label_21);

        labelEnergyMax = new QLabel(tab_4);
        labelEnergyMax->setObjectName(QString::fromUtf8("labelEnergyMax"));

        verticalLayout_8->addWidget(labelEnergyMax);

        pushButtonResetMaxEnergy = new QPushButton(tab_4);
        pushButtonResetMaxEnergy->setObjectName(QString::fromUtf8("pushButtonResetMaxEnergy"));

        verticalLayout_8->addWidget(pushButtonResetMaxEnergy);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);


        horizontalLayout_19->addLayout(verticalLayout_8);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_18 = new QLabel(tab_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_6->addWidget(label_18);

        verticalSliderEnergyThreshold = new QSlider(tab_4);
        verticalSliderEnergyThreshold->setObjectName(QString::fromUtf8("verticalSliderEnergyThreshold"));
        verticalSliderEnergyThreshold->setOrientation(Qt::Vertical);

        verticalLayout_6->addWidget(verticalSliderEnergyThreshold);


        horizontalLayout_19->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_19 = new QLabel(tab_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_7->addWidget(label_19);

        progressBarMuscle = new QProgressBar(tab_4);
        progressBarMuscle->setObjectName(QString::fromUtf8("progressBarMuscle"));
        progressBarMuscle->setValue(24);
        progressBarMuscle->setOrientation(Qt::Vertical);

        verticalLayout_7->addWidget(progressBarMuscle);


        horizontalLayout_19->addLayout(verticalLayout_7);


        gridLayout_8->addLayout(horizontalLayout_19, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer, 0, 1, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        plainTextEditSearch = new QPlainTextEdit(tab_5);
        plainTextEditSearch->setObjectName(QString::fromUtf8("plainTextEditSearch"));
        plainTextEditSearch->setGeometry(QRect(60, 130, 421, 261));
        tabWidget->addTab(tab_5, QString());

        verticalLayout->addWidget(tabWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 877, 22));
        menu_Measurement = new QMenu(menuBar);
        menu_Measurement->setObjectName(QString::fromUtf8("menu_Measurement"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(pushButtonBTdiscoverDevices, comboBoxBTdevices);
        QWidget::setTabOrder(comboBoxBTdevices, pushButtonBTconnect);
        QWidget::setTabOrder(pushButtonBTconnect, lineEditAT);
        QWidget::setTabOrder(lineEditAT, pushButtonATSend);
        QWidget::setTabOrder(pushButtonATSend, lineEditAmplitude);
        QWidget::setTabOrder(lineEditAmplitude, pushButtonAmplitude);
        QWidget::setTabOrder(pushButtonAmplitude, lineEditFrequency);
        QWidget::setTabOrder(lineEditFrequency, pushButtonFrequency);
        QWidget::setTabOrder(pushButtonFrequency, lineEditPhase);
        QWidget::setTabOrder(lineEditPhase, pushButtonPhase);
        QWidget::setTabOrder(pushButtonPhase, lineEditSymetry);
        QWidget::setTabOrder(lineEditSymetry, pushButtonSymetry);
        QWidget::setTabOrder(pushButtonSymetry, lineEditON);
        QWidget::setTabOrder(lineEditON, pushButtonOnTime);
        QWidget::setTabOrder(pushButtonOnTime, lineEditOFF);
        QWidget::setTabOrder(lineEditOFF, pushButtonOFF);
        QWidget::setTabOrder(pushButtonOFF, lineEditRampUp);
        QWidget::setTabOrder(lineEditRampUp, pushButtonRampUp);
        QWidget::setTabOrder(pushButtonRampUp, lineEditRampDown);
        QWidget::setTabOrder(lineEditRampDown, pushButtonRampDown);
        QWidget::setTabOrder(pushButtonRampDown, lineEditContractions);
        QWidget::setTabOrder(lineEditContractions, pushButtonContractions);
        QWidget::setTabOrder(pushButtonContractions, lineEditChannel1);
        QWidget::setTabOrder(lineEditChannel1, pushButtonChannel1);
        QWidget::setTabOrder(pushButtonChannel1, lineEditChannel2);
        QWidget::setTabOrder(lineEditChannel2, pushButtonChannel2);
        QWidget::setTabOrder(pushButtonChannel2, radioButtonWiFi);
        QWidget::setTabOrder(radioButtonWiFi, lineEditWiFiAddress);
        QWidget::setTabOrder(lineEditWiFiAddress, plainTextEditAT);
        QWidget::setTabOrder(plainTextEditAT, pushButtonWiFiConnect);
        QWidget::setTabOrder(pushButtonWiFiConnect, radioButtonBT);
        QWidget::setTabOrder(radioButtonBT, lineEditWiFiPort);
        QWidget::setTabOrder(lineEditWiFiPort, pushButtonWiFiDisconnect);
        QWidget::setTabOrder(pushButtonWiFiDisconnect, pushButtonBTdisconnect);

        menuBar->addAction(menu_Measurement->menuAction());
        menu_Measurement->addAction(action_Run);
        menu_Measurement->addAction(actionStop);
        menu_Measurement->addAction(action_Open);
        menu_Measurement->addAction(action_Save);
        menu_Measurement->addAction(action_Clean);
        menu_Measurement->addAction(action_Display_program);
        menu_Measurement->addAction(actionSensors);
        menu_Measurement->addAction(actionSearch);
        mainToolBar->addAction(action_Run);
        mainToolBar->addAction(actionStop);
        mainToolBar->addAction(actionSensors);
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_Save);
        mainToolBar->addAction(action_Display_program);
        mainToolBar->addAction(actionSearch);
        mainToolBar->addAction(action_Clean);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "NMES V0.1", nullptr));
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
        actionStop->setText(QApplication::translate("MainWindow", "S&top", nullptr));
#ifndef QT_NO_TOOLTIP
        actionStop->setToolTip(QApplication::translate("MainWindow", "Stop", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionStop->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        action_Open->setText(QApplication::translate("MainWindow", "&Open", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Open->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        action_Display_program->setText(QApplication::translate("MainWindow", "&Display program", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Display_program->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionSensors->setText(QApplication::translate("MainWindow", "Sensors", nullptr));
        actionSearch->setText(QApplication::translate("MainWindow", "Search", nullptr));
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
        label_14->setText(QApplication::translate("MainWindow", "Ch2 Electrode 2", nullptr));
        pushButtonChannel4->setText(QApplication::translate("MainWindow", "Update Ch2 El2", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Ramp up time (ds)", nullptr));
        pushButtonRampUp->setText(QApplication::translate("MainWindow", "Update Ramp up", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Ramp down time (ds)", nullptr));
        pushButtonRampDown->setText(QApplication::translate("MainWindow", "Update Ramp down", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Ch2 Electrode 1", nullptr));
        pushButtonChannel3->setText(QApplication::translate("MainWindow", "Update Ch2 El1", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Symmetry Factor", nullptr));
        pushButtonSymetry->setText(QApplication::translate("MainWindow", "Update Symmetry", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Phase Duration (us/50)", nullptr));
        pushButtonPhase->setText(QApplication::translate("MainWindow", "Update Pulse width", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Amp. Ch1 0-31mA", nullptr));
        pushButtonAmplitude->setText(QApplication::translate("MainWindow", "Update Amp. Ch1", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Off time (s)", nullptr));
        pushButtonOFF->setText(QApplication::translate("MainWindow", "Update OFF time", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Number Contractions", nullptr));
        pushButtonContractions->setText(QApplication::translate("MainWindow", "Update Contractions", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Ch1 Electrode 2", nullptr));
        pushButtonChannel2->setText(QApplication::translate("MainWindow", "Update Ch1 El2", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Ch1 Electrode 1", nullptr));
        pushButtonChannel1->setText(QApplication::translate("MainWindow", "Update Ch1 El1", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "On time (s)", nullptr));
        pushButtonOnTime->setText(QApplication::translate("MainWindow", "Update ON time", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Frequency Hz", nullptr));
        pushButtonFrequency->setText(QApplication::translate("MainWindow", "Update Frequency", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "Amp. Ch2 0-31mA", nullptr));
        pushButtonAmplitude2->setText(QApplication::translate("MainWindow", "Update Amp. Ch2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Config", nullptr));
        pushButtonATSend->setText(QApplication::translate("MainWindow", "Send", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "AT", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Plot", nullptr));
        labelScale->setText(QApplication::translate("MainWindow", "Scale", nullptr));
        labelEnergy->setText(QApplication::translate("MainWindow", "Energy", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Max Range", nullptr));
        labelEnergyRange->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "Energy Value", nullptr));
        labelEnergyValue->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "Threshold", nullptr));
        labelThreshold->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "Max Energy", nullptr));
        labelEnergyMax->setText(QApplication::translate("MainWindow", "0", nullptr));
        pushButtonResetMaxEnergy->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Theshold", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "Movement", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Sensors", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Search", nullptr));
        menu_Measurement->setTitle(QApplication::translate("MainWindow", "&Measurement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
