#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QChart>
#include <QtCharts/QChartGlobal>
#include <QtCharts/QLineSeries>

#include "cplotchart.h"

namespace Ui {
class MainWindow;
}


QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QChartView *m_chartView;
    CPlotChart *m_chart;

    DataTrace generateData();

    DataTrace m_sin;
    quint32 m_counter;

private slots:
    void updatePlot();



};

#endif // MAINWINDOW_H
