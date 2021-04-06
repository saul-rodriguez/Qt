#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "btclient.h"
#include "cplotchart.h"
//#include "sweep.h"
//#include "bioimpedance.h"

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
    DataTrace m_trace2;

    int m_DataCounter; //Stores number of received binary samples (same as m_trace.count())
    int m_MaxNumSamples; //Maximum number of samples that are recorder before the m_trace buffer is cleared

    //Plot
    QChartView *m_chartViewSen1;
    CPlotChart *m_chartSen1;

    QChartView *m_chartViewSen2;
    CPlotChart *m_chartSen2;

    DataTrace m_plot_trace;
    DataTrace m_plot_trace2;

    int m_MaxDataPlot; //Max number of samples to plot
    int m_PlotCounter;
    int m_PlotNumUpdate; // Number of additional data points to plot at timeout
    QTimer *m_timer;
    int m_PlotTimeout;

    //nanosense

    QTimer *m_timerMeas;    //timeout for the measurent
    QTime m_timearrival;    //used to check speed of the measurement (time elapsed)

    double m_gainCalFactor[11];
    double m_phaseCalFactor[11];


private slots:
    void BTgetDevice(QString name);
    void BTConnected(QString name);
    void BTrxData(const QByteArray &data);

    void WiFiRead();
    void WiFiDisplayError(QAbstractSocket::SocketError socketError);

    void PlotRx(const QByteArray &data);
    void PlotTimeout();

    void send(QByteArray data);

    void on_pushButtonBTdiscoverDevices_clicked();
    void on_pushButtonBTconnect_clicked();
    void on_pushButtonATSend_clicked();
    void on_radioButtonWiFi_toggled(bool checked);
    void on_radioButtonBT_toggled(bool checked);
    void on_pushButtonWiFiConnect_clicked();
    void on_pushButtonWiFiDisconnect_clicked();       
    void on_checkBoxConfigAntialias_toggled(bool checked);
    void on_pushButtonBTdisconnect_clicked();    


    void resizeEvent(QResizeEvent* event);

    void on_action_Run_triggered();
    void on_action_Clean_triggered();   
    void on_action_Delete_sweep_triggered();   
    void on_action_Save_triggered();

    void on_pushButtonAmplitude_clicked();
    void on_pushButtonFrequency_clicked();
    void on_pushButtonPhase_clicked();
    void on_pushButtonSymetry_clicked();
    void on_pushButtonOnTime_clicked();
    void on_pushButtonOFF_clicked();
    void on_pushButtonRampUp_clicked();
    void on_pushButtonRampDown_clicked();
    void on_pushButtonContractions_clicked();
    void on_pushButtonChannel1_clicked();
    void on_pushButtonChannel2_clicked();
    void on_actionStop_triggered();
    void on_action_Open_triggered();
    void on_action_Display_program_triggered();
    void on_pushButtonChannel3_clicked();
    void on_pushButtonChannel4_clicked();
    void on_pushButtonAmplitude2_clicked();
};

#endif // MAINWINDOW_H