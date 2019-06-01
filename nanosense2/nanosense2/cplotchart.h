#ifndef CPLOTCHART_H
#define CPLOTCHART_H

#include <QLogValueAxis>
#include <QObject>
#include <qvalueaxis.h>

#include <QChart>
#include <QtCharts/QChartGlobal>
#include <QtCharts/QLineSeries>

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE


//This type definitions create suitable list to handle data
//that will be plotted
typedef QPair<QPointF, QString> DataPoint;
typedef QList<DataPoint> DataTrace;
typedef QList<DataTrace> DataTable;

enum plotType {
  NORMAL,
  LOGLOG,
  SEMILOGX
};

typedef enum plotType plotType;

class CPlotChart : public QChart
{
public:
    CPlotChart();
    void initializePlot();
    void setTitles(const QString &title,const QString &xaxis,const QString &yaxis);
    void updatePlot();
    void addTrace(const DataTrace &trace);
    void clearTable();
    void setXMinXax(double min, double max);
    void setYMinXax(double min, double max);
    void setType(plotType ptype);

private:
    QString m_title;
    QString m_xAxisName;
    QString m_yAxisName;
    double m_minX;
    double m_maxX;
    double m_minY;
    double m_maxY;

    DataTable m_DataTable;

    QValueAxis *axisX;
    QValueAxis *axisY;

    QLogValueAxis *axisXlog;
    QLogValueAxis *axisYlog;

    plotType m_type;
    QColor colors[10];
    int m_linewidth;

};

#endif // CPLOTCHART_H
