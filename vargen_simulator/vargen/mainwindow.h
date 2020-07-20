#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QMainWindow>
#include <QTableWidget>
#include "cvargen.h"
#include "crom.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void clkTimeout();

    void openCfile(QString filename);
    void openAsmFile(QString filename);
    void openHexFile(QString filename);
    void setArguments(int argc, char *argv[]);


private slots:
    void on_action_Go_triggered();

    void on_action_Reset_triggered();

    //void on_actionS_tep_triggered();

    void on_actionOpen_triggered();

    void on_action_Clk_step_triggered();

    void on_action_Next_inst_triggered();

    void on_action_Stop_triggered();

    void on_actionOpen_C_source_triggered();

    void on_actionOpen_Hex_triggered();

    void on_action_Clear_Color_Markers_triggered();

private:
    void updateCdebug();
    void updateSim();

private:
    Ui::MainWindow *ui;

    CVargen pico;

    QStringList src_code;
    QStringList src_C_code;

    QString currentFunctionName;
    uint32_t currentFunctionAddress;

    QListWidget *ReglistWidget;
    QListWidget *ProgramlistWidget;
    QListWidget *CProgramlistWidget;
    QTableWidget *RamTableWidget;

    QTimer *clk;

    CRom ROM;



};
#endif // MAINWINDOW_H
