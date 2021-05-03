#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "btclient.h"
#include "cplotchart.h"
#include "nmessensor.h"
#include "nmessearch.h"
#include "nmesautomaticsearch.h"
#include "nmesdualmp.h"

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
    QTimer *m_timer_silence;
    int m_PlotTimeout;

    //NMES sensors
    NmesSensor m_sens1;
    NmesSensor m_sens2;
    int m_energy_range;
    int m_energy_threshold;
    int m_maxEnergy;
    int m_maxEnergy2;

    //Search motorpoints
    NMESsearch *m_search;
    channel m_motorPoint;
    //int m_numSearchElectrodes;

    //Automatic Search
    int m_startAmplitude;
    int m_stopAmplitude;

    NMESAutomaticSearch m_autosearch;

    //Dual motor point stimulation
    NMESDualMP *m_dualMPstim;

public slots:
    void updateSearchText(QString text);

private slots:
    void BTgetDevice(QString name);
    void BTConnected(QString name);
    void BTrxData(const QByteArray &data);


    void WiFiRead();
    void WiFiDisplayError(QAbstractSocket::SocketError socketError);

    void PlotRx(const QByteArray &data);
    void PlotTimeout();    
    void SilenceTimeout();
    void UpdateSensorData();
    void SearchDone();
    //void DualStimulationTimeout();


    void send(QByteArray data);

    void parseProgram(const QByteArray &data);

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
    void on_actionSensors_triggered(bool checked);
    void on_verticalSliderEnergyMax_valueChanged(int value);
    void on_verticalSliderEnergyThreshold_valueChanged(int value);
    void on_pushButtonResetMaxEnergy_clicked();
    void on_actionSearch_triggered();
    void on_pushButtonUpdateCh1MotorPoint_clicked();
    void on_pushButtonStartDualStim_clicked();
    void on_pushButtonUpdateCh2MotorPoint_clicked();
    void on_actionStop_Search_triggered();
};

#endif // MAINWINDOW_H
