#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "btclient.h"
#include "cplotchart.h"

#include <QMainWindow>
#include <QDataStream>
#include <QTcpSocket>
//#include <QNetworkSession>

#include "bleclient.h"

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
    //QTcpSocket *m_WiFiTcpSocket = nullptr;
    //QNetworkSession *m_WiFiNetworkSession = nullptr;
    //QDataStream m_WiFi_in;

    //BLE
    BLEClient *m_ble;
    bluetoothleState m_state;

    //Data storage
    DataTrace m_trace;
    int m_DataCounter; //Stores number of received binary samples (same as m_trace.count())
    int m_MaxNumSamples; //Maximum number of samples that are recorder before the m_trace buffer is cleared

    //Plot
    QChartView *m_chartView;
    CPlotChart *m_chart = nullptr;
    DataTrace m_plot_trace;
    int m_MaxDataPlot; //Max number of samples to plot
    int m_PlotCounter;
    int m_PlotNumUpdate; // Number of additional data points to plot at timeout
    QTimer *m_timer;
    int m_PlotTimeout;
    int m_MaxVerticalRange; // This is the ADC full range 2^n-1


private slots:
    void BTgetDevice(QString name);
    void BTConnected(QString name);
    void BTrxData(const QByteArray &data);

    /*Slots BLE*/
    void BLEdeviceFound(QString device);
    void BLErxData(const QByteArray &data);
    void BLEupdatestatus(QString &status);

    //void WiFiRead();
    //void WiFiDisplayError(QAbstractSocket::SocketError socketError);

    void PlotRx(const QByteArray &data);
    void PlotTimeout();

    void on_pushButtonBTdiscoverDevices_clicked();
    void on_pushButtonBTconnect_clicked();
    void on_pushButtonATSend_clicked();
    //void on_radioButtonWiFi_toggled(bool checked);
    void on_radioButtonBT_toggled(bool checked);
    //void on_pushButtonWiFiConnect_clicked();
    //void on_pushButtonWiFiDisconnect_clicked();
    void on_checkBoxConfigAntialias_toggled(bool checked);
    void on_pushButtonBTdisconnect_clicked();
    void on_actionStart_triggered();
    void on_actionStop_triggered();
    void on_radioButtonBLE_toggled(bool checked);
    void on_pushButtonBLEDiscover_clicked();
    void on_pushButtonBLEConnect_clicked();
    void on_pushButtonBLEDisconnect_clicked();
    //void on_comboBoxHorizontalScale_currentIndexChanged(int index);
    void on_comboBoxHorizontalScale_currentTextChanged(const QString &arg1);
    void on_pushButtonSendSPI_clicked();
    void on_actionOut1_triggered();
    void on_actionOut2_triggered();
    void on_actionCLK_triggered();

    void on_checkBoxPlotText_stateChanged(int arg1);
};

#endif // MAINWINDOW_H
