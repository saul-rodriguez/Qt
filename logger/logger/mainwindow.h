#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "btclient.h"
#include "cplotchart.h"

#include <QMainWindow>
#include <QDataStream>
#include <QTcpSocket>
#include <QNetworkSession>



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
    int m_DataCounter; //Stores number of received binary samples (same as m_trac.count())

    //Plot
    QChartView *m_chartView;
    CPlotChart *m_chart;    
    DataTrace m_plot_trace;
    int m_MaxDataPlot; //Max number of samples to plot
    int m_PlotCounter;
    int m_PlotNumUpdate; // Number of additional data points to plot at timeout
    QTimer *m_timer;
    int m_PlotTimeout;


private slots:
    void BTgetDevice(QString name);
    void BTConnected(QString name);
    void BTrxData(const QByteArray &data);

    void WiFiRead();
    void WiFiDisplayError(QAbstractSocket::SocketError socketError);

    void PlotRx(const QByteArray &data);
    void PlotTimeout();

    void on_pushButtonBTdiscoverDevices_clicked();
    void on_pushButtonBTconnect_clicked();
    void on_pushButtonATSend_clicked();
    void on_radioButtonWiFi_toggled(bool checked);
    void on_radioButtonBT_toggled(bool checked);
    void on_pushButtonWiFiConnect_clicked();
    void on_pushButtonWiFiDisconnect_clicked();       
    void on_checkBoxConfigAntialias_toggled(bool checked);
};

#endif // MAINWINDOW_H
