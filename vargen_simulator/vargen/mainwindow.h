#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cvargen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_Go_triggered();

    void on_action_Reset_triggered();

    void on_actionS_tep_triggered();

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;

    CVargen pico;

    QStringList src_code;


    void updateSim();

};
#endif // MAINWINDOW_H
