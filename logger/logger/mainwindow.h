#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "btclient.h"
#include "cplotchart.h"

#include <QMainWindow>

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

    BTClient *m_bt;
    QByteArray m_data;

    QChartView *m_chartView;
    CPlotChart *m_chart;
    DataTrace m_trace;
    DataTrace m_plot_trace;
    int m_DataCounter; //Stores number of received bin samples    

    int m_MaxDataPlot; //Max number of samples to plot
    int m_PlotCounter;
    int m_PlotNumUpdate; // Number of additional data points to plot at timeout
    QTimer *m_timer;

    int m_PlotTimeout;

private slots:
    void BTgetDevice(QString name);
    void BTConnected(QString name);
    void BTrxData(const QByteArray &data);

    void PlotRx(const QByteArray &data);
    void PlotTimeout();

    void on_pushButtonBTdiscoverDevices_clicked();
    void on_pushButtonBTconnect_clicked();
    void on_pushButtonATSend_clicked();
};

#endif // MAINWINDOW_H
