/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
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
    QAction *actionStop_Search;
    QAction *actionShow_pin_map;
    QWidget *centralWidget;
    QFormLayout *formLayout_2;
    QTabWidget *tabWidget;
    QWidget *Connect;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBoxWirelessInterface;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_4;
    QPushButton *pushButtonBTdiscoverDevices;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonBLEdiscover;
    QRadioButton *radioButtonWiFi;
    QComboBox *comboBoxBTdevices;
    QRadioButton *radioButtonBT;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBoxBLEdevices;
    QPushButton *pushButtonBTconnect;
    QPushButton *pushButtonBTdisconnect;
    QLabel *labelBTstatus;
    QLabel *labelBLEStatus;
    QPushButton *pushButtonBLEconnect;
    QPushButton *pushButtonBLEdisconnect;
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
    QVBoxLayout *verticalLayout_11;
    QLabel *labelEnergy2;
    QProgressBar *progressBarEnergy2;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_16;
    QLabel *labelEnergyRange;
    QLabel *label_20;
    QLabel *labelThreshold;
    QLabel *label_17;
    QLabel *labelEnergyValue;
    QLabel *label_21;
    QLabel *labelEnergyMax;
    QLabel *label_23;
    QLabel *labelEnergyValue2;
    QLabel *label_24;
    QLabel *labelEnergyMax2;
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
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_motorpoint;
    QPushButton *pushButtonUpdateCh1MotorPoint;
    QPushButton *pushButtonUpdateCh2MotorPoint;
    QLabel *label_25;
    QLineEdit *lineEditAnode;
    QLabel *label_37;
    QLineEdit *lineEditStartElectrodes;
    QLabel *label_22;
    QLineEdit *lineEditStopElectrodes;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_35;
    QLineEdit *lineEditSearchStartCurrent;
    QLabel *label_36;
    QLineEdit *lineEditSearchStopCurrent;
    QLabel *label_38;
    QLineEdit *lineEditPeriod;
    QCheckBox *checkBoxSuperElectrode;
    QCheckBox *checkBoxAuto;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_27;
    QRadioButton *AlgorithmPermutationradioButton;
    QRadioButton *AlgorithmRefradioButton;
    QPlainTextEdit *plainTextEditSearch;
    QWidget *tab_6;
    QGridLayout *gridLayout_11;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_27;
    QLabel *label_28;
    QLineEdit *lineEditDualStim1_1;
    QLabel *label_29;
    QLineEdit *lineEditDualStim1_2;
    QLabel *label_33;
    QLineEdit *lineEditDualAmp1;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_32;
    QLabel *label_30;
    QLineEdit *lineEditDualStim2_1;
    QLabel *label_31;
    QLineEdit *lineEditDualStim2_2;
    QLabel *label_34;
    QLineEdit *lineEditDualAmp2;
    QHBoxLayout *horizontalLayout_25;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_26;
    QLineEdit *lineEditDelay;
    QPushButton *pushButtonStartDualStim;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menu_Measurement;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1119, 687);
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
        actionStop_Search = new QAction(MainWindow);
        actionStop_Search->setObjectName(QString::fromUtf8("actionStop_Search"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop_Search->setIcon(icon8);
        actionShow_pin_map = new QAction(MainWindow);
        actionShow_pin_map->setObjectName(QString::fromUtf8("actionShow_pin_map"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        formLayout_2 = new QFormLayout(centralWidget);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
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

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButtonBLEdiscover = new QPushButton(groupBoxWirelessInterface);
        pushButtonBLEdiscover->setObjectName(QString::fromUtf8("pushButtonBLEdiscover"));

        horizontalLayout_3->addWidget(pushButtonBLEdiscover);


        gridLayout_4->addLayout(horizontalLayout_3, 1, 2, 1, 1);

        radioButtonWiFi = new QRadioButton(groupBoxWirelessInterface);
        radioButtonWiFi->setObjectName(QString::fromUtf8("radioButtonWiFi"));

        gridLayout_4->addWidget(radioButtonWiFi, 0, 2, 1, 1);

        comboBoxBTdevices = new QComboBox(groupBoxWirelessInterface);
        comboBoxBTdevices->setObjectName(QString::fromUtf8("comboBoxBTdevices"));

        gridLayout_4->addWidget(comboBoxBTdevices, 2, 0, 1, 1);

        radioButtonBT = new QRadioButton(groupBoxWirelessInterface);
        radioButtonBT->setObjectName(QString::fromUtf8("radioButtonBT"));
        radioButtonBT->setChecked(true);

        gridLayout_4->addWidget(radioButtonBT, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        comboBoxBLEdevices = new QComboBox(groupBoxWirelessInterface);
        comboBoxBLEdevices->setObjectName(QString::fromUtf8("comboBoxBLEdevices"));

        horizontalLayout_4->addWidget(comboBoxBLEdevices);


        gridLayout_4->addLayout(horizontalLayout_4, 2, 2, 1, 1);

        pushButtonBTconnect = new QPushButton(groupBoxWirelessInterface);
        pushButtonBTconnect->setObjectName(QString::fromUtf8("pushButtonBTconnect"));

        gridLayout_4->addWidget(pushButtonBTconnect, 5, 0, 1, 1);

        pushButtonBTdisconnect = new QPushButton(groupBoxWirelessInterface);
        pushButtonBTdisconnect->setObjectName(QString::fromUtf8("pushButtonBTdisconnect"));

        gridLayout_4->addWidget(pushButtonBTdisconnect, 6, 0, 1, 1);

        labelBTstatus = new QLabel(groupBoxWirelessInterface);
        labelBTstatus->setObjectName(QString::fromUtf8("labelBTstatus"));

        gridLayout_4->addWidget(labelBTstatus, 3, 0, 1, 1);

        labelBLEStatus = new QLabel(groupBoxWirelessInterface);
        labelBLEStatus->setObjectName(QString::fromUtf8("labelBLEStatus"));

        gridLayout_4->addWidget(labelBLEStatus, 3, 2, 1, 1);

        pushButtonBLEconnect = new QPushButton(groupBoxWirelessInterface);
        pushButtonBLEconnect->setObjectName(QString::fromUtf8("pushButtonBLEconnect"));

        gridLayout_4->addWidget(pushButtonBLEconnect, 5, 2, 1, 1);

        pushButtonBLEdisconnect = new QPushButton(groupBoxWirelessInterface);
        pushButtonBLEdisconnect->setObjectName(QString::fromUtf8("pushButtonBLEdisconnect"));

        gridLayout_4->addWidget(pushButtonBLEdisconnect, 6, 2, 1, 1);


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
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonChannel4->sizePolicy().hasHeightForWidth());
        pushButtonChannel4->setSizePolicy(sizePolicy);

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
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditRampUp->sizePolicy().hasHeightForWidth());
        lineEditRampUp->setSizePolicy(sizePolicy1);

        horizontalLayout_12->addWidget(lineEditRampUp);

        pushButtonRampUp = new QPushButton(tab_3);
        pushButtonRampUp->setObjectName(QString::fromUtf8("pushButtonRampUp"));
        sizePolicy1.setHeightForWidth(pushButtonRampUp->sizePolicy().hasHeightForWidth());
        pushButtonRampUp->setSizePolicy(sizePolicy1);

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
        sizePolicy1.setHeightForWidth(pushButtonRampDown->sizePolicy().hasHeightForWidth());
        pushButtonRampDown->setSizePolicy(sizePolicy1);

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
        sizePolicy.setHeightForWidth(lineEditChannel3->sizePolicy().hasHeightForWidth());
        lineEditChannel3->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(lineEditChannel3);

        pushButtonChannel3 = new QPushButton(tab_3);
        pushButtonChannel3->setObjectName(QString::fromUtf8("pushButtonChannel3"));
        sizePolicy.setHeightForWidth(pushButtonChannel3->sizePolicy().hasHeightForWidth());
        pushButtonChannel3->setSizePolicy(sizePolicy);

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
        sizePolicy1.setHeightForWidth(lineEditSymetry->sizePolicy().hasHeightForWidth());
        lineEditSymetry->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(lineEditSymetry);

        pushButtonSymetry = new QPushButton(tab_3);
        pushButtonSymetry->setObjectName(QString::fromUtf8("pushButtonSymetry"));
        sizePolicy1.setHeightForWidth(pushButtonSymetry->sizePolicy().hasHeightForWidth());
        pushButtonSymetry->setSizePolicy(sizePolicy1);

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
        sizePolicy1.setHeightForWidth(lineEditPhase->sizePolicy().hasHeightForWidth());
        lineEditPhase->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(lineEditPhase);

        pushButtonPhase = new QPushButton(tab_3);
        pushButtonPhase->setObjectName(QString::fromUtf8("pushButtonPhase"));
        sizePolicy1.setHeightForWidth(pushButtonPhase->sizePolicy().hasHeightForWidth());
        pushButtonPhase->setSizePolicy(sizePolicy1);

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
        sizePolicy1.setHeightForWidth(lineEditAmplitude->sizePolicy().hasHeightForWidth());
        lineEditAmplitude->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(lineEditAmplitude);

        pushButtonAmplitude = new QPushButton(tab_3);
        pushButtonAmplitude->setObjectName(QString::fromUtf8("pushButtonAmplitude"));
        sizePolicy1.setHeightForWidth(pushButtonAmplitude->sizePolicy().hasHeightForWidth());
        pushButtonAmplitude->setSizePolicy(sizePolicy1);

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
        sizePolicy1.setHeightForWidth(lineEditOFF->sizePolicy().hasHeightForWidth());
        lineEditOFF->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(lineEditOFF);

        pushButtonOFF = new QPushButton(tab_3);
        pushButtonOFF->setObjectName(QString::fromUtf8("pushButtonOFF"));
        sizePolicy1.setHeightForWidth(pushButtonOFF->sizePolicy().hasHeightForWidth());
        pushButtonOFF->setSizePolicy(sizePolicy1);

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
        sizePolicy1.setHeightForWidth(pushButtonContractions->sizePolicy().hasHeightForWidth());
        pushButtonContractions->setSizePolicy(sizePolicy1);

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
        sizePolicy1.setHeightForWidth(lineEditChannel2->sizePolicy().hasHeightForWidth());
        lineEditChannel2->setSizePolicy(sizePolicy1);

        horizontalLayout_16->addWidget(lineEditChannel2);

        pushButtonChannel2 = new QPushButton(tab_3);
        pushButtonChannel2->setObjectName(QString::fromUtf8("pushButtonChannel2"));
        sizePolicy1.setHeightForWidth(pushButtonChannel2->sizePolicy().hasHeightForWidth());
        pushButtonChannel2->setSizePolicy(sizePolicy1);

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
        sizePolicy1.setHeightForWidth(lineEditChannel1->sizePolicy().hasHeightForWidth());
        lineEditChannel1->setSizePolicy(sizePolicy1);

        horizontalLayout_15->addWidget(lineEditChannel1);

        pushButtonChannel1 = new QPushButton(tab_3);
        pushButtonChannel1->setObjectName(QString::fromUtf8("pushButtonChannel1"));
        sizePolicy1.setHeightForWidth(pushButtonChannel1->sizePolicy().hasHeightForWidth());
        pushButtonChannel1->setSizePolicy(sizePolicy1);

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
        sizePolicy1.setHeightForWidth(lineEditON->sizePolicy().hasHeightForWidth());
        lineEditON->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(lineEditON);

        pushButtonOnTime = new QPushButton(tab_3);
        pushButtonOnTime->setObjectName(QString::fromUtf8("pushButtonOnTime"));
        sizePolicy1.setHeightForWidth(pushButtonOnTime->sizePolicy().hasHeightForWidth());
        pushButtonOnTime->setSizePolicy(sizePolicy1);

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
        sizePolicy1.setHeightForWidth(lineEditFrequency->sizePolicy().hasHeightForWidth());
        lineEditFrequency->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(lineEditFrequency);

        pushButtonFrequency = new QPushButton(tab_3);
        pushButtonFrequency->setObjectName(QString::fromUtf8("pushButtonFrequency"));
        sizePolicy1.setHeightForWidth(pushButtonFrequency->sizePolicy().hasHeightForWidth());
        pushButtonFrequency->setSizePolicy(sizePolicy1);

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
        sizePolicy.setHeightForWidth(pushButtonAmplitude2->sizePolicy().hasHeightForWidth());
        pushButtonAmplitude2->setSizePolicy(sizePolicy);

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

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        labelEnergy2 = new QLabel(tab_4);
        labelEnergy2->setObjectName(QString::fromUtf8("labelEnergy2"));

        verticalLayout_11->addWidget(labelEnergy2);

        progressBarEnergy2 = new QProgressBar(tab_4);
        progressBarEnergy2->setObjectName(QString::fromUtf8("progressBarEnergy2"));
        progressBarEnergy2->setValue(24);
        progressBarEnergy2->setOrientation(Qt::Vertical);

        verticalLayout_11->addWidget(progressBarEnergy2);


        horizontalLayout_19->addLayout(verticalLayout_11);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_16 = new QLabel(tab_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_8->addWidget(label_16);

        labelEnergyRange = new QLabel(tab_4);
        labelEnergyRange->setObjectName(QString::fromUtf8("labelEnergyRange"));

        verticalLayout_8->addWidget(labelEnergyRange);

        label_20 = new QLabel(tab_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_8->addWidget(label_20);

        labelThreshold = new QLabel(tab_4);
        labelThreshold->setObjectName(QString::fromUtf8("labelThreshold"));

        verticalLayout_8->addWidget(labelThreshold);

        label_17 = new QLabel(tab_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_8->addWidget(label_17);

        labelEnergyValue = new QLabel(tab_4);
        labelEnergyValue->setObjectName(QString::fromUtf8("labelEnergyValue"));

        verticalLayout_8->addWidget(labelEnergyValue);

        label_21 = new QLabel(tab_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_8->addWidget(label_21);

        labelEnergyMax = new QLabel(tab_4);
        labelEnergyMax->setObjectName(QString::fromUtf8("labelEnergyMax"));

        verticalLayout_8->addWidget(labelEnergyMax);

        label_23 = new QLabel(tab_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        verticalLayout_8->addWidget(label_23);

        labelEnergyValue2 = new QLabel(tab_4);
        labelEnergyValue2->setObjectName(QString::fromUtf8("labelEnergyValue2"));

        verticalLayout_8->addWidget(labelEnergyValue2);

        label_24 = new QLabel(tab_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout_8->addWidget(label_24);

        labelEnergyMax2 = new QLabel(tab_4);
        labelEnergyMax2->setObjectName(QString::fromUtf8("labelEnergyMax2"));

        verticalLayout_8->addWidget(labelEnergyMax2);

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
        verticalLayout_9 = new QVBoxLayout(tab_5);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_motorpoint = new QLabel(tab_5);
        label_motorpoint->setObjectName(QString::fromUtf8("label_motorpoint"));

        horizontalLayout_20->addWidget(label_motorpoint);

        pushButtonUpdateCh1MotorPoint = new QPushButton(tab_5);
        pushButtonUpdateCh1MotorPoint->setObjectName(QString::fromUtf8("pushButtonUpdateCh1MotorPoint"));

        horizontalLayout_20->addWidget(pushButtonUpdateCh1MotorPoint);

        pushButtonUpdateCh2MotorPoint = new QPushButton(tab_5);
        pushButtonUpdateCh2MotorPoint->setObjectName(QString::fromUtf8("pushButtonUpdateCh2MotorPoint"));

        horizontalLayout_20->addWidget(pushButtonUpdateCh2MotorPoint);

        label_25 = new QLabel(tab_5);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_20->addWidget(label_25);

        lineEditAnode = new QLineEdit(tab_5);
        lineEditAnode->setObjectName(QString::fromUtf8("lineEditAnode"));

        horizontalLayout_20->addWidget(lineEditAnode);

        label_37 = new QLabel(tab_5);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        horizontalLayout_20->addWidget(label_37);

        lineEditStartElectrodes = new QLineEdit(tab_5);
        lineEditStartElectrodes->setObjectName(QString::fromUtf8("lineEditStartElectrodes"));

        horizontalLayout_20->addWidget(lineEditStartElectrodes);

        label_22 = new QLabel(tab_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_20->addWidget(label_22);

        lineEditStopElectrodes = new QLineEdit(tab_5);
        lineEditStopElectrodes->setObjectName(QString::fromUtf8("lineEditStopElectrodes"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEditStopElectrodes->sizePolicy().hasHeightForWidth());
        lineEditStopElectrodes->setSizePolicy(sizePolicy2);

        horizontalLayout_20->addWidget(lineEditStopElectrodes);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_2);


        verticalLayout_9->addLayout(horizontalLayout_20);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_35 = new QLabel(tab_5);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        horizontalLayout_22->addWidget(label_35);

        lineEditSearchStartCurrent = new QLineEdit(tab_5);
        lineEditSearchStartCurrent->setObjectName(QString::fromUtf8("lineEditSearchStartCurrent"));

        horizontalLayout_22->addWidget(lineEditSearchStartCurrent);

        label_36 = new QLabel(tab_5);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        horizontalLayout_22->addWidget(label_36);

        lineEditSearchStopCurrent = new QLineEdit(tab_5);
        lineEditSearchStopCurrent->setObjectName(QString::fromUtf8("lineEditSearchStopCurrent"));

        horizontalLayout_22->addWidget(lineEditSearchStopCurrent);

        label_38 = new QLabel(tab_5);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        horizontalLayout_22->addWidget(label_38);

        lineEditPeriod = new QLineEdit(tab_5);
        lineEditPeriod->setObjectName(QString::fromUtf8("lineEditPeriod"));

        horizontalLayout_22->addWidget(lineEditPeriod);

        checkBoxSuperElectrode = new QCheckBox(tab_5);
        checkBoxSuperElectrode->setObjectName(QString::fromUtf8("checkBoxSuperElectrode"));

        horizontalLayout_22->addWidget(checkBoxSuperElectrode);

        checkBoxAuto = new QCheckBox(tab_5);
        checkBoxAuto->setObjectName(QString::fromUtf8("checkBoxAuto"));

        horizontalLayout_22->addWidget(checkBoxAuto);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_3);


        verticalLayout_9->addLayout(horizontalLayout_22);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        AlgorithmPermutationradioButton = new QRadioButton(tab_5);
        AlgorithmPermutationradioButton->setObjectName(QString::fromUtf8("AlgorithmPermutationradioButton"));

        horizontalLayout_27->addWidget(AlgorithmPermutationradioButton);

        AlgorithmRefradioButton = new QRadioButton(tab_5);
        AlgorithmRefradioButton->setObjectName(QString::fromUtf8("AlgorithmRefradioButton"));
        AlgorithmRefradioButton->setChecked(true);

        horizontalLayout_27->addWidget(AlgorithmRefradioButton);


        verticalLayout_9->addLayout(horizontalLayout_27);

        plainTextEditSearch = new QPlainTextEdit(tab_5);
        plainTextEditSearch->setObjectName(QString::fromUtf8("plainTextEditSearch"));

        verticalLayout_9->addWidget(plainTextEditSearch);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_11 = new QGridLayout(tab_6);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_27 = new QLabel(tab_6);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        horizontalLayout_23->addWidget(label_27);

        label_28 = new QLabel(tab_6);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        horizontalLayout_23->addWidget(label_28);

        lineEditDualStim1_1 = new QLineEdit(tab_6);
        lineEditDualStim1_1->setObjectName(QString::fromUtf8("lineEditDualStim1_1"));

        horizontalLayout_23->addWidget(lineEditDualStim1_1);

        label_29 = new QLabel(tab_6);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_23->addWidget(label_29);

        lineEditDualStim1_2 = new QLineEdit(tab_6);
        lineEditDualStim1_2->setObjectName(QString::fromUtf8("lineEditDualStim1_2"));

        horizontalLayout_23->addWidget(lineEditDualStim1_2);

        label_33 = new QLabel(tab_6);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        horizontalLayout_23->addWidget(label_33);

        lineEditDualAmp1 = new QLineEdit(tab_6);
        lineEditDualAmp1->setObjectName(QString::fromUtf8("lineEditDualAmp1"));

        horizontalLayout_23->addWidget(lineEditDualAmp1);


        verticalLayout_12->addLayout(horizontalLayout_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_32 = new QLabel(tab_6);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        horizontalLayout_24->addWidget(label_32);

        label_30 = new QLabel(tab_6);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        horizontalLayout_24->addWidget(label_30);

        lineEditDualStim2_1 = new QLineEdit(tab_6);
        lineEditDualStim2_1->setObjectName(QString::fromUtf8("lineEditDualStim2_1"));

        horizontalLayout_24->addWidget(lineEditDualStim2_1);

        label_31 = new QLabel(tab_6);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_24->addWidget(label_31);

        lineEditDualStim2_2 = new QLineEdit(tab_6);
        lineEditDualStim2_2->setObjectName(QString::fromUtf8("lineEditDualStim2_2"));

        horizontalLayout_24->addWidget(lineEditDualStim2_2);

        label_34 = new QLabel(tab_6);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        horizontalLayout_24->addWidget(label_34);

        lineEditDualAmp2 = new QLineEdit(tab_6);
        lineEditDualAmp2->setObjectName(QString::fromUtf8("lineEditDualAmp2"));

        horizontalLayout_24->addWidget(lineEditDualAmp2);


        verticalLayout_12->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_26 = new QLabel(tab_6);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_21->addWidget(label_26);

        lineEditDelay = new QLineEdit(tab_6);
        lineEditDelay->setObjectName(QString::fromUtf8("lineEditDelay"));
        sizePolicy.setHeightForWidth(lineEditDelay->sizePolicy().hasHeightForWidth());
        lineEditDelay->setSizePolicy(sizePolicy);

        horizontalLayout_21->addWidget(lineEditDelay);


        horizontalLayout_25->addLayout(horizontalLayout_21);

        pushButtonStartDualStim = new QPushButton(tab_6);
        pushButtonStartDualStim->setObjectName(QString::fromUtf8("pushButtonStartDualStim"));
        sizePolicy1.setHeightForWidth(pushButtonStartDualStim->sizePolicy().hasHeightForWidth());
        pushButtonStartDualStim->setSizePolicy(sizePolicy1);

        horizontalLayout_25->addWidget(pushButtonStartDualStim);


        verticalLayout_12->addLayout(horizontalLayout_25);


        gridLayout_11->addLayout(verticalLayout_12, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_2, 1, 0, 1, 1);

        tabWidget->addTab(tab_6, QString());

        formLayout_2->setWidget(0, QFormLayout::FieldRole, tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1119, 22));
        menu_Measurement = new QMenu(menuBar);
        menu_Measurement->setObjectName(QString::fromUtf8("menu_Measurement"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setIconSize(QSize(96, 96));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
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
        QWidget::setTabOrder(radioButtonWiFi, plainTextEditAT);
        QWidget::setTabOrder(plainTextEditAT, radioButtonBT);
        QWidget::setTabOrder(radioButtonBT, pushButtonBTdisconnect);

        menuBar->addAction(menu_Measurement->menuAction());
        menu_Measurement->addAction(action_Run);
        menu_Measurement->addAction(actionStop);
        menu_Measurement->addAction(action_Open);
        menu_Measurement->addAction(action_Save);
        menu_Measurement->addAction(action_Clean);
        menu_Measurement->addAction(action_Display_program);
        menu_Measurement->addAction(actionSensors);
        menu_Measurement->addAction(actionSearch);
        menu_Measurement->addAction(actionStop_Search);
        menu_Measurement->addAction(actionShow_pin_map);
        mainToolBar->addAction(action_Run);
        mainToolBar->addAction(actionStop);
        mainToolBar->addAction(actionSensors);
        mainToolBar->addAction(action_Open);
        mainToolBar->addAction(action_Save);
        mainToolBar->addAction(action_Display_program);
        mainToolBar->addAction(actionSearch);
        mainToolBar->addAction(actionStop_Search);
        mainToolBar->addAction(action_Clean);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "NMES V0.65", nullptr));
        action_Run->setText(QCoreApplication::translate("MainWindow", "&Run", nullptr));
#if QT_CONFIG(shortcut)
        action_Run->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Save->setText(QCoreApplication::translate("MainWindow", "&Save ", nullptr));
#if QT_CONFIG(shortcut)
        action_Save->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Clean->setText(QCoreApplication::translate("MainWindow", "&Clean", nullptr));
#if QT_CONFIG(shortcut)
        action_Clean->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStop->setText(QCoreApplication::translate("MainWindow", "S&top", nullptr));
#if QT_CONFIG(tooltip)
        actionStop->setToolTip(QCoreApplication::translate("MainWindow", "Stop", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionStop->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Open->setText(QCoreApplication::translate("MainWindow", "&Open", nullptr));
#if QT_CONFIG(shortcut)
        action_Open->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Display_program->setText(QCoreApplication::translate("MainWindow", "&Display program", nullptr));
#if QT_CONFIG(shortcut)
        action_Display_program->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSensors->setText(QCoreApplication::translate("MainWindow", "Sensors", nullptr));
        actionSearch->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        actionStop_Search->setText(QCoreApplication::translate("MainWindow", "Stop Search", nullptr));
        actionShow_pin_map->setText(QCoreApplication::translate("MainWindow", "Show pin map", nullptr));
        groupBoxWirelessInterface->setTitle(QCoreApplication::translate("MainWindow", "Wireless interface:", nullptr));
        pushButtonBTdiscoverDevices->setText(QCoreApplication::translate("MainWindow", "Discover BT", nullptr));
        pushButtonBLEdiscover->setText(QCoreApplication::translate("MainWindow", "Discover BLE", nullptr));
        radioButtonWiFi->setText(QCoreApplication::translate("MainWindow", "Bluetooth BLE", nullptr));
        radioButtonBT->setText(QCoreApplication::translate("MainWindow", "Bluetooth Classic", nullptr));
        pushButtonBTconnect->setText(QCoreApplication::translate("MainWindow", "Connect BT", nullptr));
        pushButtonBTdisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect BT", nullptr));
        labelBTstatus->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        labelBLEStatus->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        pushButtonBLEconnect->setText(QCoreApplication::translate("MainWindow", "Connect BLE", nullptr));
        pushButtonBLEdisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect BLE", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Connect), QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Ch2 Electrode 2", nullptr));
        pushButtonChannel4->setText(QCoreApplication::translate("MainWindow", "Update Ch2 El2", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Ramp up time (ds)", nullptr));
        pushButtonRampUp->setText(QCoreApplication::translate("MainWindow", "Update Ramp up", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Ramp down time (ds)", nullptr));
        pushButtonRampDown->setText(QCoreApplication::translate("MainWindow", "Update Ramp down", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Ch2 Electrode 1", nullptr));
        pushButtonChannel3->setText(QCoreApplication::translate("MainWindow", "Update Ch2 El1", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Symmetry Factor", nullptr));
        pushButtonSymetry->setText(QCoreApplication::translate("MainWindow", "Update Symmetry", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Phase Duration (us/50)", nullptr));
        pushButtonPhase->setText(QCoreApplication::translate("MainWindow", "Update Pulse width", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Amp. Ch1 0-31mA", nullptr));
        pushButtonAmplitude->setText(QCoreApplication::translate("MainWindow", "Update Amp. Ch1", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Off time (ds)", nullptr));
        pushButtonOFF->setText(QCoreApplication::translate("MainWindow", "Update OFF time", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Number Contractions", nullptr));
        pushButtonContractions->setText(QCoreApplication::translate("MainWindow", "Update Contractions", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Ch1 Electrode 2", nullptr));
        pushButtonChannel2->setText(QCoreApplication::translate("MainWindow", "Update Ch1 El2", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Ch1 Electrode 1", nullptr));
        pushButtonChannel1->setText(QCoreApplication::translate("MainWindow", "Update Ch1 El1", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "On time (ds)", nullptr));
        pushButtonOnTime->setText(QCoreApplication::translate("MainWindow", "Update ON time", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Frequency Hz", nullptr));
        pushButtonFrequency->setText(QCoreApplication::translate("MainWindow", "Update Frequency", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Amp. Ch2 0-31mA", nullptr));
        pushButtonAmplitude2->setText(QCoreApplication::translate("MainWindow", "Update Amp. Ch2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Config", nullptr));
        pushButtonATSend->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "AT", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Plot", nullptr));
        labelScale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        labelEnergy->setText(QCoreApplication::translate("MainWindow", "Energy1", nullptr));
        labelEnergy2->setText(QCoreApplication::translate("MainWindow", "Energy2", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Max Range", nullptr));
        labelEnergyRange->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Threshold", nullptr));
        labelThreshold->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Energy1", nullptr));
        labelEnergyValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Max Energy1", nullptr));
        labelEnergyMax->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Energy2", nullptr));
        labelEnergyValue2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Max Energy2", nullptr));
        labelEnergyMax2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButtonResetMaxEnergy->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Theshold", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Movement", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Sensors", nullptr));
        label_motorpoint->setText(QCoreApplication::translate("MainWindow", "Motor point: -,- ", nullptr));
        pushButtonUpdateCh1MotorPoint->setText(QCoreApplication::translate("MainWindow", "Update MP1 ", nullptr));
        pushButtonUpdateCh2MotorPoint->setText(QCoreApplication::translate("MainWindow", "Update MP2", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Anode Elec:", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "Start Elec:", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Stop Elec:", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "Start Current:", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "Stop Current:", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "Period (ms)", nullptr));
        checkBoxSuperElectrode->setText(QCoreApplication::translate("MainWindow", "Super Electrode", nullptr));
        checkBoxAuto->setText(QCoreApplication::translate("MainWindow", "Auto Search", nullptr));
        AlgorithmPermutationradioButton->setText(QCoreApplication::translate("MainWindow", "Permutation Algorithm", nullptr));
        AlgorithmRefradioButton->setText(QCoreApplication::translate("MainWindow", "Reference Algorithm", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Search", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Motor Point 1:", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Electrode1", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Electrode2", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "Amplitude1:", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Motor Point 2:", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Electrode1", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Electrode2", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "Amplitude2:", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Delay (ms)", nullptr));
        pushButtonStartDualStim->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "D-Stim", nullptr));
        menu_Measurement->setTitle(QCoreApplication::translate("MainWindow", "&Measurement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
