#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QTime>

#include "/home/saul/projects/Qt/SerialDriver/serial_driver/cserialdriver.h"
#include "cbio2016.h"
#include "cvin2016.h"
#include "calibration.h"


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

    void on_lineEditStatisticSamples_editingFinished();

    void on_pushButtonClearTables_clicked();

    void on_pushButtonUpdateCalibration_clicked();

    void on_pushButtonSaveCal_clicked();

    void on_pushButtonLoadCal_clicked();



    void on_actionSweep_triggered();

    void on_actionSave_Measurement_triggered();

    void on_checkBoxRMSasPercentage_clicked();

    void on_actionClean_Tables_triggered();

    void on_actionSave_Tables_triggered();

    void on_pushButtonMeasureOffset_clicked();

    void measurement_timeout();

    void on_actionDelete_icon_triggered();

    void on_tableViewPhase_clicked(const QModelIndex &index);

    void on_tableViewMag_clicked(const QModelIndex &index);

    void tableChanged(const QModelIndex &index1, const QModelIndex &index2);



    void on_actionPlay_Delay_triggered();

    void delayed_trigger_timeout();

private:
    Ui::MainWindow *ui;

    QSerialPort serialPort;
    CSerialDriver *myserial;

    CBIO2016 m_bioASIC;
    //CVIN2016 m_vinASIC;

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

    //Tables Related
    QStandardItemModel *modelMag;
    QStandardItemModel *modelPha;
    QStandardItemModel *modelAveragePha;
    QStandardItemModel *modelAverageMag;

    QStandardItemModel *modelCalibration;

    QItemSelectionModel *sm_mag;
    QItemSelectionModel *sm_pha;

    int m_current_table_row;
    int m_current_table_column;

    //Calibration related
    double m_PhaseCalibration[11];
    double m_MagCalibration[11];

    Calibration m_cal;

    //timeout related

    QTime m_time;

    int m_iterations;

    QTimer *measurement_timer;
    int m_measurement_retrial;

    int m_singleShot;

    QTimer *shotmeas_timer;
    int m_shotTime;
    int m_delcount;

private:
    void readPorts();
    void setComboFreq();
    void setComboGain();
    void readADC(const QByteArray &Data);
    void receiveImpedance(const QByteArray &Data);
    void receiveImpedanceSingleShot(const QByteArray &Data);
    void receiveOffset(const QByteArray &Data);
    void measureImpedance();
    void processSweep(double mag, double phase);
    void setTables();
    void clearTable();
    void updateTable(double mag, double phase);
    void updateStatistics();
    void clearCurves();
    void extractVoltagesOffset(const QByteArray &Data, double* offset, double* I, double* Q);
    void extractVoltagesNoOffset(const QByteArray &Data, double* I, double* Q);
    int extractVoltagesOffsetSE(const QByteArray &Data, double* offset, double* I, double* Q);
    int extractVoltagesSingleShot(const QByteArray &Data, double* I, double* Q);
    quint8 calculate_checksum(const char *data, quint8 num);


};

#endif // MAINWINDOW_H
