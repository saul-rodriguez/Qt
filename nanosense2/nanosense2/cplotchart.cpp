#include "cplotchart.h"

#include <QLogValueAxis>
#include <QScatterSeries>
#include <QValueAxis>

CPlotChart::CPlotChart()
{
    m_title = "No title";
    m_xAxisName = "X";
    m_yAxisName = "Y";

    m_minX = 0.1;
    m_maxX = 100.0;
    m_minY = 0.1;
    m_maxY = 10000.0;

    axisX = new QValueAxis();
    axisY = new QValueAxis();

    axisXlog = new QLogValueAxis();
    axisYlog = new QLogValueAxis();

    m_type = NORMAL;

    colors[0] = Qt::blue;
    colors[1] = Qt::black;
    colors[2] = Qt::red;
    colors[3] = Qt::green;
    colors[4] = Qt::yellow;
    colors[5] = Qt::cyan;
    colors[6] = Qt::gray;
    colors[7] = Qt::magenta;
    colors[8] = Qt::darkRed;
    colors[9] = Qt::darkYellow;

}

void CPlotChart::initializePlot()
{

    //Add an initial point in the origin to avoid an exception when plotting
    QLineSeries *series = new QLineSeries();
    //QScatterSeries *series = new QScatterSeries(); //scattered points
   // series->setMarkerShape(QScatterSeries::MarkerShapeRectangle);
    //series->setMarkerSize(10);
    series->setColor(Qt::blue);
    //series->setBorderColor(Qt::red);
    //series->setBrush(Qt::NoPen);
    series->append(2e-3,2e-09);
    series->append(4e-2,2e-8);

    addSeries(series);

    setAnimationOptions(QChart::NoAnimation); //Activate animations 0-3
    setTheme(static_cast<QChart::ChartTheme>(QChart::ChartThemeLight)); // select a theme  0-7

    switch (m_type) {
        case NORMAL:
                        axisX->setTitleText(m_xAxisName);
                        axisX->setLabelFormat("%3.2f");
                        axisX->setRange(m_minX, m_maxX);
                        axisX->setTickCount(7);
                        addAxis(axisX, Qt::AlignBottom);
                        series->attachAxis(axisX);

                        axisY->setTitleText(m_yAxisName);
                        axisY->setLabelFormat("%3.1e");
                        axisY->setRange(m_minY, m_maxY);
                        axisY->setMinorTickCount(-1);
                        addAxis(axisY, Qt::AlignLeft);
                        series->attachAxis(axisY);
                        break;
        case LOGLOG:
                        axisXlog->setTitleText(m_xAxisName);
                        axisXlog->setLabelFormat("%3.1e");
                        axisXlog->setBase(10.0);
                        axisXlog->setRange(m_minX, m_maxX);
                        axisXlog->setMinorTickCount(-1);
                        addAxis(axisXlog, Qt::AlignBottom);
                        series->attachAxis(axisXlog);

                        axisYlog->setTitleText(m_yAxisName);
                        axisYlog->setLabelFormat("%3.1e");
                        axisYlog->setBase(10.0);
                        axisYlog->setRange(m_minY, m_maxY);
                        axisYlog->setMinorTickCount(-1);
                        addAxis(axisYlog, Qt::AlignLeft);
                        series->attachAxis(axisYlog);
                        break;
        case SEMILOGX:
                        axisXlog->setTitleText(m_xAxisName);
                        axisXlog->setLabelFormat("%3.1e");
                        axisXlog->setBase(10.0);
                        axisXlog->setRange(m_minX, m_maxX);
                        axisXlog->setMinorTickCount(-1);
                        addAxis(axisXlog, Qt::AlignBottom);
                        series->attachAxis(axisXlog);

                        axisY->setTitleText(m_yAxisName);
                        axisY->setLabelFormat("%3.1f");
                        axisY->setRange(m_minY, m_maxY);
                        axisY->setMinorTickCount(-1);
                        addAxis(axisY, Qt::AlignLeft);
                        series->attachAxis(axisY);
                        break;
        default:
                        break;
    }

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

    switch (m_type) {
        case NORMAL:
                    removeAxis(axisX);
                    removeAxis(axisY);
                    break;
        case LOGLOG:
                    removeAxis(axisXlog);
                    removeAxis(axisYlog);
                    break;
        case SEMILOGX:
                    removeAxis(axisXlog);
                    removeAxis(axisX);
                    break;
        default:
                    break;


    }

//    removeAxis(axisX);
//    removeAxis(axisY);

    int size = m_DataTable.count();

    QLineSeries *series; //Contains points, colors, etc of a single trace
   // QScatterSeries *series;

    if (size) {
        for (int i = 0; i < size; i++) {
              series = new QLineSeries();
 //           series = new QScatterSeries(); //create a new trace
 //           series->setMarkerShape(QScatterSeries::MarkerShapeRectangle);
 //           series->setMarkerSize(10);
            //series->setColor(Qt::blue);
              series->setColor(colors[i%10]);

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
/*
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
            series->attachAxis(axisY); */

            switch (m_type) {
                case NORMAL:
                                axisX->setTitleText(m_xAxisName);
                                axisX->setLabelFormat("%3.2f");
                                axisX->setRange(m_minX, m_maxX);
                                axisX->setTickCount(7);
                                addAxis(axisX, Qt::AlignBottom);
                                series->attachAxis(axisX);

                                axisY->setTitleText(m_yAxisName);
                                axisY->setLabelFormat("%3.1e");
                                axisY->setRange(m_minY, m_maxY);
                                axisY->setMinorTickCount(-1);
                                addAxis(axisY, Qt::AlignLeft);
                                series->attachAxis(axisY);
                                break;
                case LOGLOG:
                                axisXlog->setTitleText(m_xAxisName);
                                axisXlog->setLabelFormat("%3.1e");
                                axisXlog->setBase(10.0);
                                axisXlog->setRange(m_minX, m_maxX);
                                axisXlog->setMinorTickCount(-1);
                                addAxis(axisXlog, Qt::AlignBottom);
                                series->attachAxis(axisXlog);

                                axisYlog->setTitleText(m_yAxisName);
                                axisYlog->setLabelFormat("%3.1e");
                                axisYlog->setBase(10.0);
                                axisYlog->setRange(m_minY, m_maxY);
                                axisYlog->setMinorTickCount(-1);
                                addAxis(axisYlog, Qt::AlignLeft);
                                series->attachAxis(axisYlog);
                                break;
                case SEMILOGX:
                                axisXlog->setTitleText(m_xAxisName);
                                axisXlog->setLabelFormat("%3.1e");
                                axisXlog->setBase(10.0);
                                axisXlog->setRange(m_minX, m_maxX);
                                axisXlog->setMinorTickCount(-1);
                                addAxis(axisXlog, Qt::AlignBottom);
                                series->attachAxis(axisXlog);

                                axisY->setTitleText(m_yAxisName);
                                axisY->setLabelFormat("%3.1f");
                                axisY->setRange(m_minY, m_maxY);
                                axisY->setMinorTickCount(-1);
                                addAxis(axisY, Qt::AlignLeft);
                                series->attachAxis(axisY);
                                break;
                default:
                                break;
            }

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

void CPlotChart::setType(plotType ptype)
{
    m_type = ptype;
}


