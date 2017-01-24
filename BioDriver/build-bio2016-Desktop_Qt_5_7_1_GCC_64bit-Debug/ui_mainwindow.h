/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
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
    QSpacerItem *verticalSpacer_2;
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
    QWidget *tab_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(739, 463);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 701, 391));
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
        groupBox->setGeometry(QRect(60, 10, 131, 311));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 30, 101, 271));
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

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

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
        groupBox_3->setGeometry(QRect(230, 10, 120, 311));
        verticalLayoutWidget_3 = new QWidget(groupBox_3);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 30, 91, 271));
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
        pushButtonConfigure->setGeometry(QRect(360, 30, 80, 22));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 739, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
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
        pushButtonConfigure->setText(QApplication::translate("MainWindow", "Configure", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Configure ASIC", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Plot", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
