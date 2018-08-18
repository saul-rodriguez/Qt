#include "cplotchart.h"

CPlotChart::CPlotChart()
{
    m_title = "No title";
    m_xAxisName = "X";
    m_yAxisName = "Y";

    m_minX = 0.0;
    m_maxX = 1.0;
    m_minY = -1.0;
    m_maxY = 1.0;
}

void CPlotChart::initializePlot()
{

    //Add an initial point in the origin to avoid an exception when plotting
    QLineSeries *series = new QLineSeries();
    series->append(0,0);
    addSeries(series);

    setAnimationOptions(QChart::NoAnimation); //Activate animations 0-3
    setTheme(static_cast<QChart::ChartTheme>(QChart::ChartThemeLight)); // select a theme  0-7
    createDefaultAxes(); //Select an axis
    axisX()->setRange(m_minX, m_maxX);
    axisY()->setRange(m_minY, m_maxY);
    legend()->hide(); // hide()/show()
    // legend()->setAlignment(Qt::AlignmentFlag::AlignRight);

}

void CPlotChart::setTitles(const QString &title, const QString &xaxis, const QString &yaxis)
{
    m_title = title;
    m_xAxisName = xaxis;
    m_xAxisName = yaxis;
}

void CPlotChart::updatePlot()
{
    removeAllSeries();


    int size = m_DataTable.count();

    QLineSeries *series; //Contains points, colors, etc of a single trace
    if (size) {
        for (int i = 0; i < size; i++) {
            series = new QLineSeries(); //create a new trace

            int N = m_DataTable[i].count();

            //update series to be plotted
            for (int j = 0; j < N; j++) {
                series->append((m_DataTable[i])[j].first);
            }

            series->setName((m_DataTable[i])[0].second); //
            addSeries(series);
            createDefaultAxes();
            axisX()->setRange(m_minX, m_maxX);
            axisY()->setRange(m_minY, m_maxY);
        }
    }

    setTitle(m_title);
    axisX()->setTitleText(m_xAxisName);
    axisY()->setTitleText(m_yAxisName);
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


