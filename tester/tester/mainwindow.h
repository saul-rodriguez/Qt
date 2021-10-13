#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "btclient.h"
#include "cplotchart.h"
#include "sweep.h"
#include "bioimpedance.h"

#include <QMainWindow>
#include <QDataStream>
#include <QTcpSocket>
#include <QNetworkSession>
#include <QTime>
#include <QStandardItemModel>
#include <QXmlStreamWriter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //Bluetooth
    BTClient *m_bt;
    QByteArray m_data;

    //WiFi
    QTcpSocket *m_WiFiTcpSocket = nullptr;
    QNetworkSession *m_WiFiNetworkSession = nullptr;
    QDataStream m_WiFi_in;

    //Data storage
    DataTrace m_trace;
    int m_DataCounter; //Stores number of received binary samples (same as m_trace.count())
    int m_MaxNumSamples; //Maximum number of samples that are recorder before the m_trace buffer is cleared

    //Plot
    QChartView *m_chartViewMag;
    CPlotChart *m_chartMag;
    QChartView *m_chartViewPha;
    CPlotChart *m_chartPha;
    DataTrace m_plot_trace;
    int m_MaxDataPlot; //Max number of samples to plot
    int m_PlotCounter;
    int m_PlotNumUpdate; // Number of additional data points to plot at timeout
    QTimer *m_timer;
    int m_PlotTimeout;

    //nanosense
    bioimpedance *p_bioimpedance;
    sweep m_measurements[10]; // Stores all valid measurements
    sweep m_temp_measurement;  // receiving buffer to store coming data
    int m_currentMeasurement;
    QTimer *m_timerMeas;    //timeout for the measurent
    QTime m_timearrival;    //used to check speed of the measurement (time elapsed)

    double m_gainCalFactor[11];
    double m_phaseCalFactor[11];

    //Tables
    QStandardItemModel *modelMag;
    QStandardItemModel *modelMagStat;

    QStandardItemModel *modelPha;
    QStandardItemModel *modelPhaStat;

    //Calibration
    QStandardItemModel *modelCal;
    //QXmlStreamReader xmlRead;

    //XML data
    QStringList m_tags;
    QStringList m_serialnumbers;

    //Timer for delayed measurement
    QTimer *m_timerDelay;
    int m_measDelaytime;

    //Automatic Mode
    bool m_am;


private slots:
    void BTgetDevice(QString name);
    void BTConnected(QString name);
    void BTrxData(const QByteArray &data);

    void WiFiRead();
    void WiFiDisplayError(QAbstractSocket::SocketError socketError);

    void PlotRx(const QByteArray &data);
    void PlotTimeout();

    //void measurement_receive(const QByteArray &rxdata);
    void MeasurementTimeout();
    void parseRxSweepData();
    void PlotMeasurement();

    void setUpTables();
    void clearTables();
    void updateTables();
    void updateStatistics();

    void MeasurementDelayedTimeout();

    void on_pushButtonBTdiscoverDevices_clicked();
    void on_pushButtonBTconnect_clicked();
    void on_pushButtonATSend_clicked();
    void on_radioButtonWiFi_toggled(bool checked);
    void on_radioButtonBT_toggled(bool checked);
    void on_pushButtonWiFiConnect_clicked();
    void on_pushButtonWiFiDisconnect_clicked();       
    void on_checkBoxConfigAntialias_toggled(bool checked);
    void on_pushButtonBTdisconnect_clicked();    
    //void on_pushButtonMeas_clicked();

    void resizeEvent(QResizeEvent* event);
    void on_pushButtonGenerateCalibration_clicked();
    void on_pushButtonOpenCalFile_clicked();
    void on_pushButtonSaveCalFile_clicked();
    void on_action_Run_triggered();
    void on_action_Clean_triggered();
    void on_tableViewMag_clicked(const QModelIndex &index);
    void on_tableViewPha_clicked(const QModelIndex &index);
    void on_action_Delete_sweep_triggered();
    void on_pushButtonAddTag_clicked();
    void on_comboBoxTagSelect_currentIndexChanged(const QString &arg1);
    void on_pushButtonSaveTag_clicked();
    void on_pushButtonLoadTag_clicked();
    void on_action_Save_triggered();
    void on_comboBoxPA_config_currentIndexChanged(const QString &arg1);
    void on_pushButtonPA_Config_clicked();
    void on_actionRun_Timer_triggered();
    void on_actionAM_toggled(bool arg1);
};

#endif // MAINWINDOW_H
