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
    sweep m_measurements[10];
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
    QXmlStreamReader xmlRead;


private slots:
    void BTgetDevice(QString name);
    void BTConnected(QString name);
    void BTrxData(const QByteArray &data);

    void WiFiRead();
    void WiFiDisplayError(QAbstractSocket::SocketError socketError);

    void PlotRx(const QByteArray &data);
    void PlotTimeout();

    void MeasurementTimeout();
    void PlotMeasurement();

    void setUpTables();
    void clearTables();
    void updateTables();
    void updateStatistics();

    void saveCalibrationXml();


    void on_pushButtonBTdiscoverDevices_clicked();
    void on_pushButtonBTconnect_clicked();
    void on_pushButtonATSend_clicked();
    void on_radioButtonWiFi_toggled(bool checked);
    void on_radioButtonBT_toggled(bool checked);
    void on_pushButtonWiFiConnect_clicked();
    void on_pushButtonWiFiDisconnect_clicked();       
    void on_checkBoxConfigAntialias_toggled(bool checked);
    void on_pushButtonBTdisconnect_clicked();    
    void on_pushButtonMeas_clicked();

    void resizeEvent(QResizeEvent* event);
    void on_pushButtonGenerateCalibration_clicked();
    void on_pushButtonOpenCalFile_clicked();
    void on_pushButtonSaveCalFile_clicked();
};

#endif // MAINWINDOW_H
