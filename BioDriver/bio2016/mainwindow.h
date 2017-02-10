#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include "/home/saul/projects/Qt/SerialDriver/serial_driver/cserialdriver.h"
#include "cbio2016.h"
#include "cvin2016.h"

#define IDLE 0
#define RUN 1

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonRefreshPorts_clicked();

    void on_pushButtonConnect_clicked();

    void on_pushButtonTest_clicked();

    void SerialRx(const QByteArray &Data);


    void on_pushButtonConfigure_clicked();

    void on_pushButtonConfigAll_clicked();

    void on_pushButtonTestADC_clicked();

    void on_pushButtonAllTest_clicked();

    void on_pushButtonSaveOffset_clicked();

    void on_pushButtonSaveI_clicked();

    void on_pushButtonSaveQ_clicked();

    void on_pushButtonCalcZ_clicked();

    void on_pushButtonMeasureZ_clicked();

    void on_checkBoxLightTheme_toggled(bool checked);

    void on_checkBoxSemilog_toggled(bool checked);

    void on_comboBoxFreqs_currentIndexChanged(int index);

    void on_pushButtonSweep_clicked();

    void on_checkBoxAppend_stateChanged(int arg1);

    void on_comboBoxGain_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    QSerialPort serialPort;
    CSerialDriver *myserial;

    CBIO2016 m_bioASIC;
    CVIN2016 m_vinASIC;

    double m_ADC_diff;
    double m_ADC_se;

    double m_offset_diff;
    double m_offset_se;
    double m_I_diff;
    double m_I_se;
    double m_Q_diff;
    double m_Q_se;

    //Plot Related
    double m_minY;
    double m_maxY;
    bool   m_semilog; //0 == log , 1 == semilog
    bool   m_light_theme; //0 == black, //1 == white

    double m_currentFreq;
    int m_currentFreqIndex;

    int m_sweep_state;
    bool m_append;
    int m_append_curve_num;

    int m_current_gain;
    int m_current_gain_counter; //avoids bouncing conditions in the gain control

private:
    void readPorts();
    void setComboFreq();
    void setComboGain();
    void readADC(const QByteArray &Data);
    void receiveImpedance(const QByteArray &Data);
    void measureImpedance();
    void processSweep(double mag, double phase);

};

#endif // MAINWINDOW_H
