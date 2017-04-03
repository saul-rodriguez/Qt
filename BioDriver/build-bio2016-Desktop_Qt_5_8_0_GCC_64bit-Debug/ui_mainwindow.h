/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "cplotcustomwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSweep;
    QAction *actionSave_Measurement;
    QAction *actionAbout;
    QAction *actionClean_Tables;
    QAction *actionSave_Tables;
    QAction *actionDelete_icon;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_8;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButtonRefreshPorts;
    QComboBox *comboBoxPorts;
    QLabel *label;
    QPushButton *pushButtonConnect;
    QPlainTextEdit *plainTextEditLog;
    QLabel *label_2;
    QPushButton *pushButtonTest;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBoxF3;
    QCheckBox *checkBoxF2;
    QCheckBox *checkBoxF1;
    QCheckBox *checkBoxF0;
    QCheckBox *checkBoxGS3;
    QCheckBox *checkBoxGS2;
    QCheckBox *checkBoxGS1;
    QCheckBox *checkBoxGS0;
    QCheckBox *checkBoxCE;
    QCheckBox *checkBoxNS;
    QSpacerItem *verticalSpacer_6;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBoxF3_2;
    QCheckBox *checkBoxF2_2;
    QCheckBox *checkBoxF1_2;
    QCheckBox *checkBoxF0_2;
    QCheckBox *checkBoxGS3_2;
    QCheckBox *checkBoxGS2_2;
    QCheckBox *checkBoxGS1_2;
    QCheckBox *checkBoxGS0_2;
    QCheckBox *checkBoxCE_2;
    QCheckBox *checkBoxNS_2;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBoxIQ;
    QCheckBox *checkBoxGD2;
    QCheckBox *checkBoxGD1;
    QCheckBox *checkBoxGD0;
    QCheckBox *checkBoxFS;
    QCheckBox *checkBoxRE;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonConfigure;
    QComboBox *comboBoxFreqs;
    QLabel *label_11;
    QComboBox *comboBoxGain;
    QLabel *label_12;
    QCheckBox *checkBoxFilterEnable;
    QCheckBox *checkBoxSingleOffsetMeas;
    QPushButton *pushButtonMeasureOffset;
    QCheckBox *checkBoxSingleEnded;
    QCheckBox *checkBoxErrorCheck;
    QCheckBox *checkBoxSingleShot;
    QWidget *tab_4;
    QGroupBox *groupBox_4;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBoxEnMF;
    QCheckBox *checkBoxEnHF;
    QCheckBox *checkBoxDN1;
    QCheckBox *checkBoxDN0;
    QCheckBox *checkBoxDP2;
    QCheckBox *checkBoxDP1;
    QCheckBox *checkBoxDP0;
    QCheckBox *checkBoxEnRdeg;
    QSpacerItem *verticalSpacer_4;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *checkBoxEnRdegHF1;
    QCheckBox *checkBoxEnRdegHF0;
    QCheckBox *checkBoxCcompSel1;
    QCheckBox *checkBoxCcompSel0;
    QCheckBox *checkBoxCapSel3;
    QCheckBox *checkBoxCapSel2;
    QCheckBox *checkBoxCapSel1;
    QCheckBox *checkBoxCapSel0;
    QSpacerItem *verticalSpacer_5;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *checkBoxEnLF;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButtonConfigAll;
    QWidget *tab_3;
    QGroupBox *groupBox_5;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_CH2;
    QLabel *label_CH3;
    QLabel *label_CH5;
    QPushButton *pushButtonTestADC;
    QPushButton *pushButtonAllTest;
    QGroupBox *groupBox_6;
    QPushButton *pushButtonSaveOffset;
    QLineEdit *lineEditOffsetDiff;
    QLineEdit *lineEditOffsetSE;
    QGroupBox *groupBox_7;
    QLineEdit *lineEditIDiff;
    QLineEdit *lineEditISE;
    QPushButton *pushButtonSaveI;
    QGroupBox *groupBox_8;
    QPushButton *pushButtonSaveQ;
    QLineEdit *lineEditQDiff;
    QLineEdit *lineEditQSE;
    QLineEdit *lineEditMag;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEditPhase;
    QPushButton *pushButtonCalcZ;
    QWidget *tab_5;
    QPushButton *pushButtonMeasureZ;
    QLineEdit *lineEditMeasuredMag;
    QLineEdit *lineEditMeasuredPhase;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonSweep;
    QCheckBox *checkBoxAppend;
    QCheckBox *checkBoxLightTheme;
    QCheckBox *checkBoxSemilog;
    QLabel *label_7;
    QLineEdit *lineEditMinY;
    QLabel *label_8;
    QLineEdit *lineEditMaxY;
    QLabel *label_9;
    QLineEdit *lineEditMinYLog;
    QLabel *label_10;
    QLineEdit *lineEditNumDec;
    CPlotCustomWidget *widgetMagnitude;
    CPlotCustomWidget *widgetPhase;
    QWidget *tab_8;
    QTableView *tableViewPhase;
    QTableView *tableViewAveragePhase;
    QLabel *label_13;
    QLineEdit *lineEditStatisticSamples;
    QPushButton *pushButtonClearTables;
    QWidget *tab_7;
    QTableView *tableViewMag;
    QTableView *tableViewAverageMag;
    QCheckBox *checkBoxRMSasPercentage;
    QWidget *tab_9;
    QTableView *tableViewCalibration;
    QPushButton *pushButtonUpdateCalibration;
    QCheckBox *checkBoxCalibratePhase;
    QLineEdit *lineEditCalRes;
    QLabel *label_14;
    QPushButton *pushButtonSaveCal;
    QPushButton *pushButtonLoadCal;
    QMenuBar *menuBar;
    QMenu *menuMeasure;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(977, 622);
        actionSweep = new QAction(MainWindow);
        actionSweep->setObjectName(QStringLiteral("actionSweep"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/Button-Play-icon.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSweep->setIcon(icon);
        actionSave_Measurement = new QAction(MainWindow);
        actionSave_Measurement->setObjectName(QStringLiteral("actionSave_Measurement"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("images/Save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/images/Save-icon.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave_Measurement->setIcon(icon1);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionClean_Tables = new QAction(MainWindow);
        actionClean_Tables->setObjectName(QStringLiteral("actionClean_Tables"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/Clean-icon.png"), QSize(), QIcon::Normal, QIcon::On);
        actionClean_Tables->setIcon(icon2);
        actionSave_Tables = new QAction(MainWindow);
        actionSave_Tables->setObjectName(QStringLiteral("actionSave_Tables"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/Save-table-icon.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave_Tables->setIcon(icon3);
        actionDelete_icon = new QAction(MainWindow);
        actionDelete_icon->setObjectName(QStringLiteral("actionDelete_icon"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/Delete-icon.png"), QSize(), QIcon::Normal, QIcon::On);
        actionDelete_icon->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_8 = new QVBoxLayout(centralWidget);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButtonRefreshPorts = new QPushButton(tab);
        pushButtonRefreshPorts->setObjectName(QStringLiteral("pushButtonRefreshPorts"));
        pushButtonRefreshPorts->setGeometry(QRect(360, 20, 101, 22));
        comboBoxPorts = new QComboBox(tab);
        comboBoxPorts->setObjectName(QStringLiteral("comboBoxPorts"));
        comboBoxPorts->setGeometry(QRect(240, 20, 111, 22));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 20, 121, 20));
        pushButtonConnect = new QPushButton(tab);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(470, 20, 80, 22));
        plainTextEditLog = new QPlainTextEdit(tab);
        plainTextEditLog->setObjectName(QStringLiteral("plainTextEditLog"));
        plainTextEditLog->setGeometry(QRect(110, 100, 441, 231));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 80, 59, 14));
        pushButtonTest = new QPushButton(tab);
        pushButtonTest->setObjectName(QStringLiteral("pushButtonTest"));
        pushButtonTest->setGeometry(QRect(470, 50, 91, 22));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(60, 10, 131, 341));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 30, 101, 304));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBoxF3 = new QCheckBox(verticalLayoutWidget);
        checkBoxF3->setObjectName(QStringLiteral("checkBoxF3"));

        verticalLayout->addWidget(checkBoxF3);

        checkBoxF2 = new QCheckBox(verticalLayoutWidget);
        checkBoxF2->setObjectName(QStringLiteral("checkBoxF2"));

        verticalLayout->addWidget(checkBoxF2);

        checkBoxF1 = new QCheckBox(verticalLayoutWidget);
        checkBoxF1->setObjectName(QStringLiteral("checkBoxF1"));

        verticalLayout->addWidget(checkBoxF1);

        checkBoxF0 = new QCheckBox(verticalLayoutWidget);
        checkBoxF0->setObjectName(QStringLiteral("checkBoxF0"));

        verticalLayout->addWidget(checkBoxF0);

        checkBoxGS3 = new QCheckBox(verticalLayoutWidget);
        checkBoxGS3->setObjectName(QStringLiteral("checkBoxGS3"));

        verticalLayout->addWidget(checkBoxGS3);

        checkBoxGS2 = new QCheckBox(verticalLayoutWidget);
        checkBoxGS2->setObjectName(QStringLiteral("checkBoxGS2"));

        verticalLayout->addWidget(checkBoxGS2);

        checkBoxGS1 = new QCheckBox(verticalLayoutWidget);
        checkBoxGS1->setObjectName(QStringLiteral("checkBoxGS1"));

        verticalLayout->addWidget(checkBoxGS1);

        checkBoxGS0 = new QCheckBox(verticalLayoutWidget);
        checkBoxGS0->setObjectName(QStringLiteral("checkBoxGS0"));

        verticalLayout->addWidget(checkBoxGS0);

        checkBoxCE = new QCheckBox(verticalLayoutWidget);
        checkBoxCE->setObjectName(QStringLiteral("checkBoxCE"));

        verticalLayout->addWidget(checkBoxCE);

        checkBoxNS = new QCheckBox(verticalLayoutWidget);
        checkBoxNS->setObjectName(QStringLiteral("checkBoxNS"));

        verticalLayout->addWidget(checkBoxNS);

        verticalSpacer_6 = new QSpacerItem(86, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(200, 0, 151, 351));
        verticalLayoutWidget_2 = new QWidget(groupBox_2);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 30, 111, 301));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBoxF3_2 = new QCheckBox(verticalLayoutWidget_2);
        checkBoxF3_2->setObjectName(QStringLiteral("checkBoxF3_2"));

        verticalLayout_2->addWidget(checkBoxF3_2);

        checkBoxF2_2 = new QCheckBox(verticalLayoutWidget_2);
        checkBoxF2_2->setObjectName(QStringLiteral("checkBoxF2_2"));

        verticalLayout_2->addWidget(checkBoxF2_2);

        checkBoxF1_2 = new QCheckBox(verticalLayoutWidget_2);
        checkBoxF1_2->setObjectName(QStringLiteral("checkBoxF1_2"));

        verticalLayout_2->addWidget(checkBoxF1_2);

        checkBoxF0_2 = new QCheckBox(verticalLayoutWidget_2);
        checkBoxF0_2->setObjectName(QStringLiteral("checkBoxF0_2"));

        verticalLayout_2->addWidget(checkBoxF0_2);

        checkBoxGS3_2 = new QCheckBox(verticalLayoutWidget_2);
        checkBoxGS3_2->setObjectName(QStringLiteral("checkBoxGS3_2"));

        verticalLayout_2->addWidget(checkBoxGS3_2);

        checkBoxGS2_2 = new QCheckBox(verticalLayoutWidget_2);
        checkBoxGS2_2->setObjectName(QStringLiteral("checkBoxGS2_2"));

        verticalLayout_2->addWidget(checkBoxGS2_2);

        checkBoxGS1_2 = new QCheckBox(verticalLayoutWidget_2);
        checkBoxGS1_2->setObjectName(QStringLiteral("checkBoxGS1_2"));

        verticalLayout_2->addWidget(checkBoxGS1_2);

        checkBoxGS0_2 = new QCheckBox(verticalLayoutWidget_2);
        checkBoxGS0_2->setObjectName(QStringLiteral("checkBoxGS0_2"));

        verticalLayout_2->addWidget(checkBoxGS0_2);

        checkBoxCE_2 = new QCheckBox(verticalLayoutWidget_2);
        checkBoxCE_2->setObjectName(QStringLiteral("checkBoxCE_2"));

        verticalLayout_2->addWidget(checkBoxCE_2);

        checkBoxNS_2 = new QCheckBox(verticalLayoutWidget_2);
        checkBoxNS_2->setObjectName(QStringLiteral("checkBoxNS_2"));

        verticalLayout_2->addWidget(checkBoxNS_2);

        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(230, 10, 120, 341));
        verticalLayoutWidget_3 = new QWidget(groupBox_3);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 30, 91, 301));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        checkBoxIQ = new QCheckBox(verticalLayoutWidget_3);
        checkBoxIQ->setObjectName(QStringLiteral("checkBoxIQ"));

        verticalLayout_3->addWidget(checkBoxIQ);

        checkBoxGD2 = new QCheckBox(verticalLayoutWidget_3);
        checkBoxGD2->setObjectName(QStringLiteral("checkBoxGD2"));

        verticalLayout_3->addWidget(checkBoxGD2);

        checkBoxGD1 = new QCheckBox(verticalLayoutWidget_3);
        checkBoxGD1->setObjectName(QStringLiteral("checkBoxGD1"));

        verticalLayout_3->addWidget(checkBoxGD1);

        checkBoxGD0 = new QCheckBox(verticalLayoutWidget_3);
        checkBoxGD0->setObjectName(QStringLiteral("checkBoxGD0"));

        verticalLayout_3->addWidget(checkBoxGD0);

        checkBoxFS = new QCheckBox(verticalLayoutWidget_3);
        checkBoxFS->setObjectName(QStringLiteral("checkBoxFS"));

        verticalLayout_3->addWidget(checkBoxFS);

        checkBoxRE = new QCheckBox(verticalLayoutWidget_3);
        checkBoxRE->setObjectName(QStringLiteral("checkBoxRE"));

        verticalLayout_3->addWidget(checkBoxRE);

        verticalSpacer = new QSpacerItem(86, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        pushButtonConfigure = new QPushButton(tab_2);
        pushButtonConfigure->setObjectName(QStringLiteral("pushButtonConfigure"));
        pushButtonConfigure->setGeometry(QRect(530, 30, 101, 22));
        comboBoxFreqs = new QComboBox(tab_2);
        comboBoxFreqs->setObjectName(QStringLiteral("comboBoxFreqs"));
        comboBoxFreqs->setGeometry(QRect(380, 40, 101, 25));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(390, 10, 81, 17));
        comboBoxGain = new QComboBox(tab_2);
        comboBoxGain->setObjectName(QStringLiteral("comboBoxGain"));
        comboBoxGain->setGeometry(QRect(380, 160, 101, 25));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(400, 130, 67, 17));
        checkBoxFilterEnable = new QCheckBox(tab_2);
        checkBoxFilterEnable->setObjectName(QStringLiteral("checkBoxFilterEnable"));
        checkBoxFilterEnable->setGeometry(QRect(530, 70, 231, 23));
        checkBoxSingleOffsetMeas = new QCheckBox(tab_2);
        checkBoxSingleOffsetMeas->setObjectName(QStringLiteral("checkBoxSingleOffsetMeas"));
        checkBoxSingleOffsetMeas->setGeometry(QRect(530, 100, 231, 23));
        pushButtonMeasureOffset = new QPushButton(tab_2);
        pushButtonMeasureOffset->setObjectName(QStringLiteral("pushButtonMeasureOffset"));
        pushButtonMeasureOffset->setGeometry(QRect(530, 140, 141, 25));
        checkBoxSingleEnded = new QCheckBox(tab_2);
        checkBoxSingleEnded->setObjectName(QStringLiteral("checkBoxSingleEnded"));
        checkBoxSingleEnded->setGeometry(QRect(530, 190, 231, 23));
        checkBoxErrorCheck = new QCheckBox(tab_2);
        checkBoxErrorCheck->setObjectName(QStringLiteral("checkBoxErrorCheck"));
        checkBoxErrorCheck->setGeometry(QRect(530, 220, 111, 23));
        checkBoxSingleShot = new QCheckBox(tab_2);
        checkBoxSingleShot->setObjectName(QStringLiteral("checkBoxSingleShot"));
        checkBoxSingleShot->setGeometry(QRect(530, 290, 161, 23));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_4 = new QGroupBox(tab_4);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(70, 10, 401, 321));
        verticalLayoutWidget_4 = new QWidget(groupBox_4);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(140, 30, 121, 281));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        checkBoxEnMF = new QCheckBox(verticalLayoutWidget_4);
        checkBoxEnMF->setObjectName(QStringLiteral("checkBoxEnMF"));

        verticalLayout_4->addWidget(checkBoxEnMF);

        checkBoxEnHF = new QCheckBox(verticalLayoutWidget_4);
        checkBoxEnHF->setObjectName(QStringLiteral("checkBoxEnHF"));

        verticalLayout_4->addWidget(checkBoxEnHF);

        checkBoxDN1 = new QCheckBox(verticalLayoutWidget_4);
        checkBoxDN1->setObjectName(QStringLiteral("checkBoxDN1"));

        verticalLayout_4->addWidget(checkBoxDN1);

        checkBoxDN0 = new QCheckBox(verticalLayoutWidget_4);
        checkBoxDN0->setObjectName(QStringLiteral("checkBoxDN0"));

        verticalLayout_4->addWidget(checkBoxDN0);

        checkBoxDP2 = new QCheckBox(verticalLayoutWidget_4);
        checkBoxDP2->setObjectName(QStringLiteral("checkBoxDP2"));

        verticalLayout_4->addWidget(checkBoxDP2);

        checkBoxDP1 = new QCheckBox(verticalLayoutWidget_4);
        checkBoxDP1->setObjectName(QStringLiteral("checkBoxDP1"));

        verticalLayout_4->addWidget(checkBoxDP1);

        checkBoxDP0 = new QCheckBox(verticalLayoutWidget_4);
        checkBoxDP0->setObjectName(QStringLiteral("checkBoxDP0"));

        verticalLayout_4->addWidget(checkBoxDP0);

        checkBoxEnRdeg = new QCheckBox(verticalLayoutWidget_4);
        checkBoxEnRdeg->setObjectName(QStringLiteral("checkBoxEnRdeg"));

        verticalLayout_4->addWidget(checkBoxEnRdeg);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        verticalLayoutWidget_5 = new QWidget(groupBox_4);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(270, 30, 121, 281));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        checkBoxEnRdegHF1 = new QCheckBox(verticalLayoutWidget_5);
        checkBoxEnRdegHF1->setObjectName(QStringLiteral("checkBoxEnRdegHF1"));

        verticalLayout_5->addWidget(checkBoxEnRdegHF1);

        checkBoxEnRdegHF0 = new QCheckBox(verticalLayoutWidget_5);
        checkBoxEnRdegHF0->setObjectName(QStringLiteral("checkBoxEnRdegHF0"));

        verticalLayout_5->addWidget(checkBoxEnRdegHF0);

        checkBoxCcompSel1 = new QCheckBox(verticalLayoutWidget_5);
        checkBoxCcompSel1->setObjectName(QStringLiteral("checkBoxCcompSel1"));

        verticalLayout_5->addWidget(checkBoxCcompSel1);

        checkBoxCcompSel0 = new QCheckBox(verticalLayoutWidget_5);
        checkBoxCcompSel0->setObjectName(QStringLiteral("checkBoxCcompSel0"));

        verticalLayout_5->addWidget(checkBoxCcompSel0);

        checkBoxCapSel3 = new QCheckBox(verticalLayoutWidget_5);
        checkBoxCapSel3->setObjectName(QStringLiteral("checkBoxCapSel3"));

        verticalLayout_5->addWidget(checkBoxCapSel3);

        checkBoxCapSel2 = new QCheckBox(verticalLayoutWidget_5);
        checkBoxCapSel2->setObjectName(QStringLiteral("checkBoxCapSel2"));

        verticalLayout_5->addWidget(checkBoxCapSel2);

        checkBoxCapSel1 = new QCheckBox(verticalLayoutWidget_5);
        checkBoxCapSel1->setObjectName(QStringLiteral("checkBoxCapSel1"));

        verticalLayout_5->addWidget(checkBoxCapSel1);

        checkBoxCapSel0 = new QCheckBox(verticalLayoutWidget_5);
        checkBoxCapSel0->setObjectName(QStringLiteral("checkBoxCapSel0"));

        verticalLayout_5->addWidget(checkBoxCapSel0);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        verticalLayoutWidget_6 = new QWidget(groupBox_4);
        verticalLayoutWidget_6->setObjectName(QStringLiteral("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(10, 30, 121, 281));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        checkBoxEnLF = new QCheckBox(verticalLayoutWidget_6);
        checkBoxEnLF->setObjectName(QStringLiteral("checkBoxEnLF"));

        verticalLayout_6->addWidget(checkBoxEnLF);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_3);

        pushButtonConfigAll = new QPushButton(tab_4);
        pushButtonConfigAll->setObjectName(QStringLiteral("pushButtonConfigAll"));
        pushButtonConfigAll->setGeometry(QRect(480, 30, 89, 25));
        tabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(40, 30, 171, 181));
        verticalLayoutWidget_7 = new QWidget(groupBox_5);
        verticalLayoutWidget_7->setObjectName(QStringLiteral("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(10, 79, 151, 91));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_CH2 = new QLabel(verticalLayoutWidget_7);
        label_CH2->setObjectName(QStringLiteral("label_CH2"));

        verticalLayout_7->addWidget(label_CH2);

        label_CH3 = new QLabel(verticalLayoutWidget_7);
        label_CH3->setObjectName(QStringLiteral("label_CH3"));

        verticalLayout_7->addWidget(label_CH3);

        label_CH5 = new QLabel(verticalLayoutWidget_7);
        label_CH5->setObjectName(QStringLiteral("label_CH5"));

        verticalLayout_7->addWidget(label_CH5);

        pushButtonTestADC = new QPushButton(groupBox_5);
        pushButtonTestADC->setObjectName(QStringLiteral("pushButtonTestADC"));
        pushButtonTestADC->setGeometry(QRect(20, 40, 111, 25));
        pushButtonAllTest = new QPushButton(tab_3);
        pushButtonAllTest->setObjectName(QStringLiteral("pushButtonAllTest"));
        pushButtonAllTest->setGeometry(QRect(80, 230, 89, 25));
        groupBox_6 = new QGroupBox(tab_3);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(230, 30, 141, 181));
        pushButtonSaveOffset = new QPushButton(groupBox_6);
        pushButtonSaveOffset->setObjectName(QStringLiteral("pushButtonSaveOffset"));
        pushButtonSaveOffset->setGeometry(QRect(30, 40, 89, 25));
        lineEditOffsetDiff = new QLineEdit(groupBox_6);
        lineEditOffsetDiff->setObjectName(QStringLiteral("lineEditOffsetDiff"));
        lineEditOffsetDiff->setGeometry(QRect(40, 80, 81, 25));
        lineEditOffsetSE = new QLineEdit(groupBox_6);
        lineEditOffsetSE->setObjectName(QStringLiteral("lineEditOffsetSE"));
        lineEditOffsetSE->setGeometry(QRect(40, 140, 81, 25));
        groupBox_7 = new QGroupBox(tab_3);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(390, 30, 151, 181));
        lineEditIDiff = new QLineEdit(groupBox_7);
        lineEditIDiff->setObjectName(QStringLiteral("lineEditIDiff"));
        lineEditIDiff->setGeometry(QRect(40, 80, 81, 25));
        lineEditISE = new QLineEdit(groupBox_7);
        lineEditISE->setObjectName(QStringLiteral("lineEditISE"));
        lineEditISE->setGeometry(QRect(40, 140, 81, 25));
        pushButtonSaveI = new QPushButton(groupBox_7);
        pushButtonSaveI->setObjectName(QStringLiteral("pushButtonSaveI"));
        pushButtonSaveI->setGeometry(QRect(30, 40, 89, 25));
        groupBox_8 = new QGroupBox(tab_3);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(550, 30, 141, 181));
        pushButtonSaveQ = new QPushButton(groupBox_8);
        pushButtonSaveQ->setObjectName(QStringLiteral("pushButtonSaveQ"));
        pushButtonSaveQ->setGeometry(QRect(30, 40, 89, 25));
        lineEditQDiff = new QLineEdit(groupBox_8);
        lineEditQDiff->setObjectName(QStringLiteral("lineEditQDiff"));
        lineEditQDiff->setGeometry(QRect(40, 80, 81, 25));
        lineEditQSE = new QLineEdit(groupBox_8);
        lineEditQSE->setObjectName(QStringLiteral("lineEditQSE"));
        lineEditQSE->setGeometry(QRect(40, 140, 81, 25));
        lineEditMag = new QLineEdit(tab_3);
        lineEditMag->setObjectName(QStringLiteral("lineEditMag"));
        lineEditMag->setGeometry(QRect(420, 240, 71, 25));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(330, 240, 81, 17));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 280, 67, 17));
        lineEditPhase = new QLineEdit(tab_3);
        lineEditPhase->setObjectName(QStringLiteral("lineEditPhase"));
        lineEditPhase->setGeometry(QRect(420, 280, 71, 25));
        pushButtonCalcZ = new QPushButton(tab_3);
        pushButtonCalcZ->setObjectName(QStringLiteral("pushButtonCalcZ"));
        pushButtonCalcZ->setGeometry(QRect(230, 240, 89, 25));
        tabWidget->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        pushButtonMeasureZ = new QPushButton(tab_5);
        pushButtonMeasureZ->setObjectName(QStringLiteral("pushButtonMeasureZ"));
        pushButtonMeasureZ->setGeometry(QRect(100, 30, 89, 25));
        lineEditMeasuredMag = new QLineEdit(tab_5);
        lineEditMeasuredMag->setObjectName(QStringLiteral("lineEditMeasuredMag"));
        lineEditMeasuredMag->setGeometry(QRect(100, 70, 113, 25));
        lineEditMeasuredPhase = new QLineEdit(tab_5);
        lineEditMeasuredPhase->setObjectName(QStringLiteral("lineEditMeasuredPhase"));
        lineEditMeasuredPhase->setGeometry(QRect(100, 110, 113, 25));
        label_5 = new QLabel(tab_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 70, 81, 17));
        label_6 = new QLabel(tab_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 110, 51, 17));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        verticalLayout_9 = new QVBoxLayout(tab_6);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonSweep = new QPushButton(tab_6);
        pushButtonSweep->setObjectName(QStringLiteral("pushButtonSweep"));

        horizontalLayout->addWidget(pushButtonSweep);

        checkBoxAppend = new QCheckBox(tab_6);
        checkBoxAppend->setObjectName(QStringLiteral("checkBoxAppend"));

        horizontalLayout->addWidget(checkBoxAppend);

        checkBoxLightTheme = new QCheckBox(tab_6);
        checkBoxLightTheme->setObjectName(QStringLiteral("checkBoxLightTheme"));

        horizontalLayout->addWidget(checkBoxLightTheme);

        checkBoxSemilog = new QCheckBox(tab_6);
        checkBoxSemilog->setObjectName(QStringLiteral("checkBoxSemilog"));

        horizontalLayout->addWidget(checkBoxSemilog);

        label_7 = new QLabel(tab_6);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        lineEditMinY = new QLineEdit(tab_6);
        lineEditMinY->setObjectName(QStringLiteral("lineEditMinY"));

        horizontalLayout->addWidget(lineEditMinY);

        label_8 = new QLabel(tab_6);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout->addWidget(label_8);

        lineEditMaxY = new QLineEdit(tab_6);
        lineEditMaxY->setObjectName(QStringLiteral("lineEditMaxY"));

        horizontalLayout->addWidget(lineEditMaxY);

        label_9 = new QLabel(tab_6);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout->addWidget(label_9);

        lineEditMinYLog = new QLineEdit(tab_6);
        lineEditMinYLog->setObjectName(QStringLiteral("lineEditMinYLog"));

        horizontalLayout->addWidget(lineEditMinYLog);

        label_10 = new QLabel(tab_6);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout->addWidget(label_10);

        lineEditNumDec = new QLineEdit(tab_6);
        lineEditNumDec->setObjectName(QStringLiteral("lineEditNumDec"));

        horizontalLayout->addWidget(lineEditNumDec);


        verticalLayout_9->addLayout(horizontalLayout);

        widgetMagnitude = new CPlotCustomWidget(tab_6);
        widgetMagnitude->setObjectName(QStringLiteral("widgetMagnitude"));

        verticalLayout_9->addWidget(widgetMagnitude);

        widgetPhase = new CPlotCustomWidget(tab_6);
        widgetPhase->setObjectName(QStringLiteral("widgetPhase"));

        verticalLayout_9->addWidget(widgetPhase);

        tabWidget->addTab(tab_6, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        tableViewPhase = new QTableView(tab_8);
        tableViewPhase->setObjectName(QStringLiteral("tableViewPhase"));
        tableViewPhase->setGeometry(QRect(20, 30, 861, 331));
        tableViewAveragePhase = new QTableView(tab_8);
        tableViewAveragePhase->setObjectName(QStringLiteral("tableViewAveragePhase"));
        tableViewAveragePhase->setGeometry(QRect(20, 400, 861, 81));
        label_13 = new QLabel(tab_8);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(310, 370, 241, 20));
        lineEditStatisticSamples = new QLineEdit(tab_8);
        lineEditStatisticSamples->setObjectName(QStringLiteral("lineEditStatisticSamples"));
        lineEditStatisticSamples->setGeometry(QRect(550, 370, 41, 25));
        pushButtonClearTables = new QPushButton(tab_8);
        pushButtonClearTables->setObjectName(QStringLiteral("pushButtonClearTables"));
        pushButtonClearTables->setGeometry(QRect(30, 370, 101, 25));
        tabWidget->addTab(tab_8, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tableViewMag = new QTableView(tab_7);
        tableViewMag->setObjectName(QStringLiteral("tableViewMag"));
        tableViewMag->setGeometry(QRect(9, 9, 881, 351));
        tableViewAverageMag = new QTableView(tab_7);
        tableViewAverageMag->setObjectName(QStringLiteral("tableViewAverageMag"));
        tableViewAverageMag->setGeometry(QRect(10, 390, 881, 91));
        checkBoxRMSasPercentage = new QCheckBox(tab_7);
        checkBoxRMSasPercentage->setObjectName(QStringLiteral("checkBoxRMSasPercentage"));
        checkBoxRMSasPercentage->setGeometry(QRect(360, 360, 92, 23));
        tabWidget->addTab(tab_7, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        tableViewCalibration = new QTableView(tab_9);
        tableViewCalibration->setObjectName(QStringLiteral("tableViewCalibration"));
        tableViewCalibration->setGeometry(QRect(30, 80, 841, 91));
        pushButtonUpdateCalibration = new QPushButton(tab_9);
        pushButtonUpdateCalibration->setObjectName(QStringLiteral("pushButtonUpdateCalibration"));
        pushButtonUpdateCalibration->setGeometry(QRect(30, 40, 141, 25));
        checkBoxCalibratePhase = new QCheckBox(tab_9);
        checkBoxCalibratePhase->setObjectName(QStringLiteral("checkBoxCalibratePhase"));
        checkBoxCalibratePhase->setGeometry(QRect(440, 40, 171, 23));
        lineEditCalRes = new QLineEdit(tab_9);
        lineEditCalRes->setObjectName(QStringLiteral("lineEditCalRes"));
        lineEditCalRes->setGeometry(QRect(340, 40, 71, 25));
        label_14 = new QLabel(tab_9);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(240, 40, 101, 17));
        pushButtonSaveCal = new QPushButton(tab_9);
        pushButtonSaveCal->setObjectName(QStringLiteral("pushButtonSaveCal"));
        pushButtonSaveCal->setGeometry(QRect(30, 190, 131, 25));
        pushButtonLoadCal = new QPushButton(tab_9);
        pushButtonLoadCal->setObjectName(QStringLiteral("pushButtonLoadCal"));
        pushButtonLoadCal->setGeometry(QRect(190, 190, 131, 25));
        tabWidget->addTab(tab_9, QString());

        verticalLayout_8->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 977, 22));
        menuMeasure = new QMenu(menuBar);
        menuMeasure->setObjectName(QStringLiteral("menuMeasure"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMeasure->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuMeasure->addAction(actionSweep);
        menuMeasure->addAction(actionSave_Measurement);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionSweep);
        mainToolBar->addAction(actionDelete_icon);
        mainToolBar->addAction(actionSave_Measurement);
        mainToolBar->addAction(actionSave_Tables);
        mainToolBar->addAction(actionClean_Tables);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "NanoSense V1.0", Q_NULLPTR));
        actionSweep->setText(QApplication::translate("MainWindow", "Sweep", Q_NULLPTR));
        actionSweep->setShortcut(QApplication::translate("MainWindow", "M", Q_NULLPTR));
        actionSave_Measurement->setText(QApplication::translate("MainWindow", "Save Measurement", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        actionClean_Tables->setText(QApplication::translate("MainWindow", "Clean Tables", Q_NULLPTR));
        actionClean_Tables->setShortcut(QApplication::translate("MainWindow", "E", Q_NULLPTR));
        actionSave_Tables->setText(QApplication::translate("MainWindow", "Save Tables", Q_NULLPTR));
        actionSave_Tables->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        actionDelete_icon->setText(QApplication::translate("MainWindow", "Delete icon", Q_NULLPTR));
        actionDelete_icon->setShortcut(QApplication::translate("MainWindow", "Del", Q_NULLPTR));
        pushButtonRefreshPorts->setText(QApplication::translate("MainWindow", "Refresh Ports", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Available Serial Ports:", Q_NULLPTR));
        pushButtonConnect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Log:", Q_NULLPTR));
        pushButtonTest->setText(QApplication::translate("MainWindow", "Test Comm.", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Signal Generator", Q_NULLPTR));
        checkBoxF3->setText(QApplication::translate("MainWindow", "F3", Q_NULLPTR));
        checkBoxF2->setText(QApplication::translate("MainWindow", "F2", Q_NULLPTR));
        checkBoxF1->setText(QApplication::translate("MainWindow", "F1", Q_NULLPTR));
        checkBoxF0->setText(QApplication::translate("MainWindow", "F0", Q_NULLPTR));
        checkBoxGS3->setText(QApplication::translate("MainWindow", "GS3", Q_NULLPTR));
        checkBoxGS2->setText(QApplication::translate("MainWindow", "GS2", Q_NULLPTR));
        checkBoxGS1->setText(QApplication::translate("MainWindow", "GS1", Q_NULLPTR));
        checkBoxGS0->setText(QApplication::translate("MainWindow", "GS0", Q_NULLPTR));
        checkBoxCE->setText(QApplication::translate("MainWindow", "CE", Q_NULLPTR));
        checkBoxNS->setText(QApplication::translate("MainWindow", "NS", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Signal Generator", Q_NULLPTR));
        checkBoxF3_2->setText(QApplication::translate("MainWindow", "F3", Q_NULLPTR));
        checkBoxF2_2->setText(QApplication::translate("MainWindow", "F2", Q_NULLPTR));
        checkBoxF1_2->setText(QApplication::translate("MainWindow", "F1", Q_NULLPTR));
        checkBoxF0_2->setText(QApplication::translate("MainWindow", "F0", Q_NULLPTR));
        checkBoxGS3_2->setText(QApplication::translate("MainWindow", "GS3", Q_NULLPTR));
        checkBoxGS2_2->setText(QApplication::translate("MainWindow", "GS2", Q_NULLPTR));
        checkBoxGS1_2->setText(QApplication::translate("MainWindow", "GS1", Q_NULLPTR));
        checkBoxGS0_2->setText(QApplication::translate("MainWindow", "GS0", Q_NULLPTR));
        checkBoxCE_2->setText(QApplication::translate("MainWindow", "CE", Q_NULLPTR));
        checkBoxNS_2->setText(QApplication::translate("MainWindow", "NS", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Demodulator", Q_NULLPTR));
        checkBoxIQ->setText(QApplication::translate("MainWindow", "IQ", Q_NULLPTR));
        checkBoxGD2->setText(QApplication::translate("MainWindow", "GD2", Q_NULLPTR));
        checkBoxGD1->setText(QApplication::translate("MainWindow", "GD1", Q_NULLPTR));
        checkBoxGD0->setText(QApplication::translate("MainWindow", "GD0", Q_NULLPTR));
        checkBoxFS->setText(QApplication::translate("MainWindow", "FS", Q_NULLPTR));
        checkBoxRE->setText(QApplication::translate("MainWindow", "RE", Q_NULLPTR));
        pushButtonConfigure->setText(QApplication::translate("MainWindow", "Config Radio", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Frequency", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Gain", Q_NULLPTR));
        checkBoxFilterEnable->setText(QApplication::translate("MainWindow", "Enable Signal Generator Filter", Q_NULLPTR));
        checkBoxSingleOffsetMeas->setText(QApplication::translate("MainWindow", "Single offset measurement", Q_NULLPTR));
        pushButtonMeasureOffset->setText(QApplication::translate("MainWindow", "Measure Offset", Q_NULLPTR));
        checkBoxSingleEnded->setText(QApplication::translate("MainWindow", "Singled Ended Measurement", Q_NULLPTR));
        checkBoxErrorCheck->setText(QApplication::translate("MainWindow", "Error Check", Q_NULLPTR));
        checkBoxSingleShot->setText(QApplication::translate("MainWindow", "Single shot sweep", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "ASIC Radio Conf.", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Filter Settings", Q_NULLPTR));
        checkBoxEnMF->setText(QApplication::translate("MainWindow", "EnMF", Q_NULLPTR));
        checkBoxEnHF->setText(QApplication::translate("MainWindow", "EnHF", Q_NULLPTR));
        checkBoxDN1->setText(QApplication::translate("MainWindow", "DN1", Q_NULLPTR));
        checkBoxDN0->setText(QApplication::translate("MainWindow", "DN0", Q_NULLPTR));
        checkBoxDP2->setText(QApplication::translate("MainWindow", "DP2", Q_NULLPTR));
        checkBoxDP1->setText(QApplication::translate("MainWindow", "DP1", Q_NULLPTR));
        checkBoxDP0->setText(QApplication::translate("MainWindow", "DP0", Q_NULLPTR));
        checkBoxEnRdeg->setText(QApplication::translate("MainWindow", "EnRdeg", Q_NULLPTR));
        checkBoxEnRdegHF1->setText(QApplication::translate("MainWindow", "EnRdegHF1", Q_NULLPTR));
        checkBoxEnRdegHF0->setText(QApplication::translate("MainWindow", "EnRdegHF0", Q_NULLPTR));
        checkBoxCcompSel1->setText(QApplication::translate("MainWindow", "CcompSel1", Q_NULLPTR));
        checkBoxCcompSel0->setText(QApplication::translate("MainWindow", "CcompSel0", Q_NULLPTR));
        checkBoxCapSel3->setText(QApplication::translate("MainWindow", "CapSel3", Q_NULLPTR));
        checkBoxCapSel2->setText(QApplication::translate("MainWindow", "CapSel2", Q_NULLPTR));
        checkBoxCapSel1->setText(QApplication::translate("MainWindow", "CapSel1", Q_NULLPTR));
        checkBoxCapSel0->setText(QApplication::translate("MainWindow", "CapSel0", Q_NULLPTR));
        checkBoxEnLF->setText(QApplication::translate("MainWindow", "EnLF", Q_NULLPTR));
        pushButtonConfigAll->setText(QApplication::translate("MainWindow", "Config ASIC", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", " ASIC Filter Conf.", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Test ADC", Q_NULLPTR));
        label_CH2->setText(QApplication::translate("MainWindow", "CH2 (VP):", Q_NULLPTR));
        label_CH3->setText(QApplication::translate("MainWindow", "CH4 (VN):", Q_NULLPTR));
        label_CH5->setText(QApplication::translate("MainWindow", "CH5 (VSE):", Q_NULLPTR));
        pushButtonTestADC->setText(QApplication::translate("MainWindow", "Measure ADC", Q_NULLPTR));
        pushButtonAllTest->setText(QApplication::translate("MainWindow", "Test ", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Offset", Q_NULLPTR));
        pushButtonSaveOffset->setText(QApplication::translate("MainWindow", "Save Offset", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "I", Q_NULLPTR));
        pushButtonSaveI->setText(QApplication::translate("MainWindow", "Save I", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Q", Q_NULLPTR));
        pushButtonSaveQ->setText(QApplication::translate("MainWindow", "Save Q", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Magnitude", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Phase", Q_NULLPTR));
        pushButtonCalcZ->setText(QApplication::translate("MainWindow", "Calculate Z", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Measure ADC", Q_NULLPTR));
        pushButtonMeasureZ->setText(QApplication::translate("MainWindow", "Measure Z", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Magnitude", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Phase", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Measure Z", Q_NULLPTR));
        pushButtonSweep->setText(QApplication::translate("MainWindow", "Sweep Freq", Q_NULLPTR));
        checkBoxAppend->setText(QApplication::translate("MainWindow", "Append", Q_NULLPTR));
        checkBoxLightTheme->setText(QApplication::translate("MainWindow", "LightTheme", Q_NULLPTR));
        checkBoxSemilog->setText(QApplication::translate("MainWindow", "Semilog Plot", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Min Y", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Max Y", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Min Y Log", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Num Dec", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Sweep Freq", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Number of rows used for statistics", Q_NULLPTR));
        pushButtonClearTables->setText(QApplication::translate("MainWindow", "Clear Tables", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "Phase Data", Q_NULLPTR));
        checkBoxRMSasPercentage->setText(QApplication::translate("MainWindow", "RMS as %", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "Mag Data", Q_NULLPTR));
        pushButtonUpdateCalibration->setText(QApplication::translate("MainWindow", "Update Calibration", Q_NULLPTR));
        checkBoxCalibratePhase->setText(QApplication::translate("MainWindow", "Enable Calibration", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Calibration R", Q_NULLPTR));
        pushButtonSaveCal->setText(QApplication::translate("MainWindow", "Save Calibration", Q_NULLPTR));
        pushButtonLoadCal->setText(QApplication::translate("MainWindow", "Load Calibration", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QApplication::translate("MainWindow", "Calib.", Q_NULLPTR));
        menuMeasure->setTitle(QApplication::translate("MainWindow", "Measure", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
