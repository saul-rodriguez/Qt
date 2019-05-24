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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
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
    QWidget *tab_4;
    QLabel *label_2;
    QTableView *tableViewMag;
    QLabel *label_3;
    QTableView *tableViewMagStat;
    QWidget *tab_5;
    QLabel *label_4;
    QTableView *tableViewPha;
    QTableView *tableViewPhaStat;
    QLabel *label_5;
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
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(799, 584);
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
        action_Delete_sweep = new QAction(MainWindow);
        action_Delete_sweep->setObjectName(QString::fromUtf8("action_Delete_sweep"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/Delete-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Delete_sweep->setIcon(icon3);
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
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_7 = new QGridLayout(tab_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_9 = new QGridLayout(groupBox);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        checkBoxConfigSmoothPlot = new QCheckBox(groupBox);
        checkBoxConfigSmoothPlot->setObjectName(QString::fromUtf8("checkBoxConfigSmoothPlot"));

        gridLayout_9->addWidget(checkBoxConfigSmoothPlot, 0, 0, 1, 1);

        checkBoxConfigAntialias = new QCheckBox(groupBox);
        checkBoxConfigAntialias->setObjectName(QString::fromUtf8("checkBoxConfigAntialias"));

        gridLayout_9->addWidget(checkBoxConfigAntialias, 1, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_10 = new QGridLayout(groupBox_2);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        lineEditTagName = new QLineEdit(groupBox_2);
        lineEditTagName->setObjectName(QString::fromUtf8("lineEditTagName"));

        horizontalLayout_6->addWidget(lineEditTagName);

        pushButtonAddTag = new QPushButton(groupBox_2);
        pushButtonAddTag->setObjectName(QString::fromUtf8("pushButtonAddTag"));

        horizontalLayout_6->addWidget(pushButtonAddTag);


        gridLayout_10->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        comboBoxTagSelect = new QComboBox(groupBox_2);
        comboBoxTagSelect->setObjectName(QString::fromUtf8("comboBoxTagSelect"));

        horizontalLayout_8->addWidget(comboBoxTagSelect);


        gridLayout_10->addLayout(horizontalLayout_8, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushButtonSaveTag = new QPushButton(groupBox_2);
        pushButtonSaveTag->setObjectName(QString::fromUtf8("pushButtonSaveTag"));

        horizontalLayout_7->addWidget(pushButtonSaveTag);

        pushButtonLoadTag = new QPushButton(groupBox_2);
        pushButtonLoadTag->setObjectName(QString::fromUtf8("pushButtonLoadTag"));

        horizontalLayout_7->addWidget(pushButtonLoadTag);


        gridLayout_10->addLayout(horizontalLayout_7, 2, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        lineEditAdditionalData = new QLineEdit(groupBox_2);
        lineEditAdditionalData->setObjectName(QString::fromUtf8("lineEditAdditionalData"));

        horizontalLayout_10->addWidget(lineEditAdditionalData);


        gridLayout_10->addLayout(horizontalLayout_10, 3, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        gridLayout_7->addLayout(verticalLayout_4, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
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
        label_2 = new QLabel(tab_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 179, 17));
        tableViewMag = new QTableView(tab_4);
        tableViewMag->setObjectName(QString::fromUtf8("tableViewMag"));
        tableViewMag->setGeometry(QRect(10, 33, 761, 331));
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 370, 243, 17));
        tableViewMagStat = new QTableView(tab_4);
        tableViewMagStat->setObjectName(QString::fromUtf8("tableViewMagStat"));
        tableViewMagStat->setGeometry(QRect(10, 390, 761, 81));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableViewMagStat->sizePolicy().hasHeightForWidth());
        tableViewMagStat->setSizePolicy(sizePolicy2);
        tableViewMagStat->setBaseSize(QSize(0, 0));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        label_4 = new QLabel(tab_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 146, 17));
        tableViewPha = new QTableView(tab_5);
        tableViewPha->setObjectName(QString::fromUtf8("tableViewPha"));
        tableViewPha->setGeometry(QRect(10, 33, 761, 331));
        tableViewPhaStat = new QTableView(tab_5);
        tableViewPhaStat->setObjectName(QString::fromUtf8("tableViewPhaStat"));
        tableViewPhaStat->setGeometry(QRect(10, 390, 761, 81));
        label_5 = new QLabel(tab_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 370, 279, 17));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout_8 = new QGridLayout(tab_6);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        tableViewCalibration = new QTableView(tab_6);
        tableViewCalibration->setObjectName(QString::fromUtf8("tableViewCalibration"));

        gridLayout_8->addWidget(tableViewCalibration, 1, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        checkBoxGainCalibration = new QCheckBox(tab_6);
        checkBoxGainCalibration->setObjectName(QString::fromUtf8("checkBoxGainCalibration"));

        verticalLayout_5->addWidget(checkBoxGainCalibration);

        label_6 = new QLabel(tab_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_5->addWidget(label_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButtonGenerateCalibration = new QPushButton(tab_6);
        pushButtonGenerateCalibration->setObjectName(QString::fromUtf8("pushButtonGenerateCalibration"));

        horizontalLayout_5->addWidget(pushButtonGenerateCalibration);

        pushButtonOpenCalFile = new QPushButton(tab_6);
        pushButtonOpenCalFile->setObjectName(QString::fromUtf8("pushButtonOpenCalFile"));

        horizontalLayout_5->addWidget(pushButtonOpenCalFile);

        pushButtonSaveCalFile = new QPushButton(tab_6);
        pushButtonSaveCalFile->setObjectName(QString::fromUtf8("pushButtonSaveCalFile"));

        horizontalLayout_5->addWidget(pushButtonSaveCalFile);


        verticalLayout_5->addLayout(horizontalLayout_5);


        gridLayout_8->addLayout(verticalLayout_5, 0, 0, 1, 1);

        tabWidget->addTab(tab_6, QString());

        verticalLayout->addWidget(tabWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 799, 22));
        menu_Measurement = new QMenu(menuBar);
        menu_Measurement->setObjectName(QString::fromUtf8("menu_Measurement"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(radioButtonBT, radioButtonWiFi);
        QWidget::setTabOrder(radioButtonWiFi, lineEditWiFiAddress);
        QWidget::setTabOrder(lineEditWiFiAddress, lineEditWiFiPort);
        QWidget::setTabOrder(lineEditWiFiPort, pushButtonWiFiConnect);
        QWidget::setTabOrder(pushButtonWiFiConnect, pushButtonWiFiDisconnect);
        QWidget::setTabOrder(pushButtonWiFiDisconnect, pushButtonBTdiscoverDevices);
        QWidget::setTabOrder(pushButtonBTdiscoverDevices, comboBoxBTdevices);
        QWidget::setTabOrder(comboBoxBTdevices, pushButtonBTconnect);
        QWidget::setTabOrder(pushButtonBTconnect, lineEditAT);
        QWidget::setTabOrder(lineEditAT, pushButtonATSend);
        QWidget::setTabOrder(pushButtonATSend, plainTextEditAT);

        menuBar->addAction(menu_Measurement->menuAction());
        menu_Measurement->addAction(action_Run);
        menu_Measurement->addAction(action_Save);
        menu_Measurement->addAction(action_Clean);
        menu_Measurement->addAction(action_Delete_sweep);
        mainToolBar->addAction(action_Run);
        mainToolBar->addAction(action_Save);
        mainToolBar->addAction(action_Clean);
        mainToolBar->addAction(action_Delete_sweep);

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
