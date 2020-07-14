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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *action_Go;
    QAction *action_Stop;
    QAction *action_Reset;
    QAction *actionS_tep;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QListWidget *ProgramlistWidget;
    QListWidget *ReglistWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuRun;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(805, 664);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        action_Go = new QAction(MainWindow);
        action_Go->setObjectName(QString::fromUtf8("action_Go"));
        action_Stop = new QAction(MainWindow);
        action_Stop->setObjectName(QString::fromUtf8("action_Stop"));
        action_Reset = new QAction(MainWindow);
        action_Reset->setObjectName(QString::fromUtf8("action_Reset"));
        actionS_tep = new QAction(MainWindow);
        actionS_tep->setObjectName(QString::fromUtf8("actionS_tep"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        ProgramlistWidget = new QListWidget(splitter);
        ProgramlistWidget->setObjectName(QString::fromUtf8("ProgramlistWidget"));
        splitter->addWidget(ProgramlistWidget);
        ReglistWidget = new QListWidget(splitter);
        ReglistWidget->setObjectName(QString::fromUtf8("ReglistWidget"));
        splitter->addWidget(ReglistWidget);

        horizontalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 805, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuRun = new QMenu(menubar);
        menuRun->setObjectName(QString::fromUtf8("menuRun"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuRun->menuAction());
        menuFile->addAction(actionOpen);
        menuRun->addAction(action_Go);
        menuRun->addAction(action_Stop);
        menuRun->addAction(action_Reset);
        menuRun->addAction(actionS_tep);
        toolBar->addAction(action_Reset);
        toolBar->addAction(action_Go);
        toolBar->addAction(action_Stop);
        toolBar->addAction(actionS_tep);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "&Open", nullptr));
        action_Go->setText(QApplication::translate("MainWindow", "&Go", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Go->setShortcut(QApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        action_Stop->setText(QApplication::translate("MainWindow", "&Stop", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Stop->setShortcut(QApplication::translate("MainWindow", "Shift+F5", nullptr));
#endif // QT_NO_SHORTCUT
        action_Reset->setText(QApplication::translate("MainWindow", "&Reset", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Reset->setShortcut(QApplication::translate("MainWindow", "F6", nullptr));
#endif // QT_NO_SHORTCUT
        actionS_tep->setText(QApplication::translate("MainWindow", "S&tep", nullptr));
#ifndef QT_NO_SHORTCUT
        actionS_tep->setShortcut(QApplication::translate("MainWindow", "F10", nullptr));
#endif // QT_NO_SHORTCUT
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menuRun->setTitle(QApplication::translate("MainWindow", "&Run", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
