#include "cplotchart.h"

#include <QLogValueAxis>
#include <QScatterSeries>
#include <QValueAxis>

CPlotChart::CPlotChart()
{
    m_title = "No title";
    m_xAxisName = "X";
    m_yAxisName = "Y";

    m_minX = 0.0;
    m_maxX = 10.0;
    m_minY = 0.1;
    m_maxY = 10000.0;

    axisX = new QValueAxis();
    axisY = new QLogValueAxis();
}

void CPlotChart::initializePlot()
{

    //Add an initial point in the origin to avoid an exception when plotting
    //QLineSeries *series = new QLineSeries();
    QScatterSeries *series = new QScatterSeries(); //scattered points
    series->setMarkerShape(QScatterSeries::MarkerShapeRectangle);
    series->setMarkerSize(7);
    series->setColor(Qt::blue);
    //series->setBorderColor(Qt::red);
    //series->setBrush(Qt::NoPen);
    series->append(0.1,2e-09);
    series->append(0.4,2e-8);

    addSeries(series);

    setAnimationOptions(QChart::NoAnimation); //Activate animations 0-3
    setTheme(static_cast<QChart::ChartTheme>(QChart::ChartThemeLight)); // select a theme  0-7

    //createDefaultAxes(); //Select an axis
    axisX->setTitleText(m_xAxisName);
    axisX->setLabelFormat("%3.2f");
    axisX->setRange(m_minX, m_maxX);
    axisX->setTickCount(7);

    addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY->setTitleText(m_yAxisName);
    axisY->setLabelFormat("%3.1e");
    axisY->setBase(10.0);
    axisY->setRange(m_minY, m_maxY);
    axisY->setMinorTickCount(-1);

    addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    legend()->hide(); // hide()/show()
    //legend()->setAlignment(Qt::AlignmentFlag::AlignRight);
    setTitle(m_title);

}

void CPlotChart::setTitles(const QString &title, const QString &xaxis, const QString &yaxis)
{
    m_title = title;
    m_xAxisName = xaxis;
    m_yAxisName = yaxis;
}

void CPlotChart::updatePlot()
{
    removeAllSeries();
    removeAxis(axisX);
    removeAxis(axisY);


    int size = m_DataTable.count();

   // QLineSeries *series; //Contains points, colors, etc of a single trace
    QScatterSeries *series;

    if (size) {
        for (int i = 0; i < size; i++) {
            series = new QScatterSeries(); //create a new trace
            series->setMarkerShape(QScatterSeries::MarkerShapeRectangle);
            series->setMarkerSize(7);
            series->setColor(Qt::blue);

            int N = m_DataTable[i].count();

            //update series to be plotted
            for (int j = 0; j < N; j++) {
                double x = (m_DataTable[i])[j].first.rx();
                double y = (m_DataTable[i])[j].first.ry();
                series->append(x,y);
            }

            series->setName((m_DataTable[i])[0].second); //
            addSeries(series);

            //createDefaultAxes();
            //axisX()->setRange(m_minX, m_maxX);
            //axisY()->setRange(m_minY, m_maxY);

            //QValueAxis *axisX = new QValueAxis();
            axisX->setTitleText(m_xAxisName);
            axisX->setLabelFormat("%3.2f");
            axisX->setRange(m_minX, m_maxX);
            axisX->setTickCount(7);
            addAxis(axisX, Qt::AlignBottom);
            series->attachAxis(axisX);

            //QLogValueAxis *axisY = new QLogValueAxis();
            axisY->setTitleText(m_yAxisName);
            axisY->setLabelFormat("%3.1e");
            axisY->setBase(10.0);
            axisY->setRange(m_minY, m_maxY);
            axisY->setMinorTickCount(-1);
            addAxis(axisY, Qt::AlignLeft);
            series->attachAxis(axisY);

        }
    }

    setTitle(m_title);
   // axisX()->setTitleText(m_xAxisName);
   // axisY()->setTitleText(m_yAxisName);
   //legend()->show(); // hide()/show()
   // legend()->setAlignment(Qt::AlignmentFlag::AlignRight);

}

void CPlotChart::addTrace(const DataTrace &trace)
{
    m_DataTable << trace;
}

void CPlotChart::clearTable()
{
    m_DataTable.clear();
}

void CPlotChart::setXMinXax(double min, double max)
{
    m_minX = min;
    m_maxX = max;
}

void CPlotChart::setYMinXax(double min, double max)
{
    m_minY = min;
    m_maxY = max;
}


