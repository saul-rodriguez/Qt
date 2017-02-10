#include "cplotcustomwidget.h"
#include "QPainter"

#include <QtMath>

CPlotCustomWidget::CPlotCustomWidget(QWidget *parent) : QWidget(parent)
{
    x_dimension = 0;
    y_dimension = 0;

    scalefactorx = 0;
    scalefactory = 0;

    m_backgroundColor = QColor(Qt::black);
    m_axisColor = QColor(Qt::white);

    m_lineColor[0] = QColor(Qt::blue);
    m_lineColor[1] = QColor(Qt::red);
    m_lineColor[2] = QColor(Qt::green);
    m_lineColor[3] = QColor(Qt::darkCyan);
    m_lineColor[4] = QColor(Qt::lightGray);
    m_lineColor[5] = QColor(Qt::cyan);
    m_lineColor[6] = QColor(Qt::yellow);
    m_lineColor[7] = QColor(Qt::magenta);
    m_lineColor[8] = QColor(Qt::darkRed);
    m_lineColor[9] = QColor(Qt::darkBlue);


    m_xAxis = "X";
    m_yAxis = "Y";

    m_xMin = 0;
    m_xMax = 100;

    m_yMin = 0;
    m_yMax = 500;

    m_xTicks = 10;
    m_yTicks = 10;

    m_gridEnabled = true;

    m_linEnabled = true;
    m_logEnabled = true;
    m_semilogEnabled = false;

    m_xlogNumDecades = 3;
    m_ylogNumDecades = 3;

    m_xMinlog = 1;
    m_yMinlog = 1;

    m_ticklog = false;

    //SetGridStyle(Qt::DotLine);
    SetGridStyle(Qt::DashLine);

    m_numUsedCurves = 0;

    for (int i = 0; i < 10; i++)
        m_size_curve[i] = 0;


}

void CPlotCustomWidget::SetXAxisName(QString name)
{
    m_xAxis = name;
}

void CPlotCustomWidget::SetYAxisName(QString name)
{
    m_yAxis = name;
}

void CPlotCustomWidget::setXMax(double max)
{
    m_xMax = max;
}

void CPlotCustomWidget::setXMin(double min)
{
    m_xMin = min;
}

void CPlotCustomWidget::setYMax(double max)
{
    m_yMax = max;
}

void CPlotCustomWidget::setYMin(double min)
{
    m_yMin = min;
}

void CPlotCustomWidget::setXMinLog(double min)
{
    m_xMinlog = min;
}

void CPlotCustomWidget::setYMinLog(double min)
{
    m_yMinlog = min;
}

void CPlotCustomWidget::setXNumDec(int num)
{
    m_xlogNumDecades = num;
}

void CPlotCustomWidget::setYNumDec(int num)
{
    m_ylogNumDecades = num;
}

void CPlotCustomWidget::enableGrid(bool en)
{
    m_gridEnabled = en;
}

void CPlotCustomWidget::setXTicksNum(int num)
{
    m_xTicks = num;
}

void CPlotCustomWidget::setYTicksNum(int num)
{
    m_yTicks = num;
}

void CPlotCustomWidget::enableLinPlot()
{
    m_linEnabled = true;
    m_logEnabled = false;
    m_semilogEnabled = false;
}

void CPlotCustomWidget::enableLogPlot()
{
    m_logEnabled = true;
    m_linEnabled = false;
    m_semilogEnabled = false;
}

void CPlotCustomWidget::enableSemiLogPlot()
{
    m_semilogEnabled = true;
    m_linEnabled = false;
    m_logEnabled = false;
}

void CPlotCustomWidget::setTheme(int theme)
{
    switch (theme) {
        case 1:
            m_backgroundColor = QColor(Qt::white);
            m_axisColor = QColor(Qt::black);
            break;
        default:
            m_backgroundColor = QColor(Qt::black);
            m_axisColor = QColor(Qt::white);
    }
    m_gridPen.setColor(m_axisColor);
}

void CPlotCustomWidget::setDataPoints(QList<double> &x, QList<double> &y)
{
    if (!x.size() || !y.size()) return; // no data points!

    m_xdata = x;
    m_ydata = y;
}

void CPlotCustomWidget::DrawDataPoints(QPainter &painter, int color)
{
    //Set pen
    QPen axispen(m_lineColor[color]);
    axispen.setWidth(1);
    axispen.setStyle(Qt::SolidLine);
    painter.setPen(axispen);

    int N = m_xdata.size();

    QList<QPointF> data_points;
    QPointF point;
    double aux;

    //Prepare plot points depending on the selected plot
    if (m_linEnabled) {
        for (int i = 0; i < N; i++) {
            aux = origin.x() + m_xdata[i]*scalefactorx;
            point.setX(aux);
            //aux = origin.y() - m_ydata[i]*scalefactory;
            aux = origin.y() - (m_ydata[i]-m_yMin)*scalefactory;
            point.setY(aux);
            data_points.append(point);
        }
    } else if (m_logEnabled) {
        double scalelogx = x_dimension/m_xlogNumDecades;
        double scalelogy = y_dimension/m_ylogNumDecades;

        for (int i = 0; i < N; i++) {
            aux = origin.x() + qLn(m_xdata[i]/m_xMinlog)/2.30258509299*scalelogx;
            point.setX(aux);
            aux = origin.y() - qLn(m_ydata[i]/m_yMinlog)/2.30258509299*scalelogy;
            point.setY(aux);
            data_points.append(point);
        }
    } else { //semilog
        double scalelogx = x_dimension/m_xlogNumDecades;

        for (int i = 0; i < N; i++) {
            aux = origin.x() + qLn(m_xdata[i]/m_xMinlog)/2.30258509299*scalelogx;
            point.setX(aux);
            //aux = origin.y() - m_ydata[i]*scalefactory;
            aux = origin.y() - (m_ydata[i]-m_yMin)*scalefactory;
            //aux = origin.y() - qLn(m_ydata[i]/m_yMinlog)/2.30258509299*scalelogy;
            point.setY(aux);
            data_points.append(point);
        }
    }

    QPointF P1,P2;

    for (int i = 0; i < (N-1); i++) {
        P1.setX(data_points[i].x());
        P1.setY(data_points[i].y());
        P2.setX(data_points[i+1].x());
        P2.setY(data_points[i+1].y());
        painter.drawLine(P1,P2);
    }

    //points
    QPen dotpen(m_lineColor[color]);
    dotpen.setWidth(4);
    painter.setPen(dotpen);

    for (int i = 0; i < N; i++) {
        painter.drawPoint(data_points[i].x(),data_points[i].y());
    }

}

void CPlotCustomWidget::DrawCurves(QPainter &painter)
{
    for (int i = 0; i < m_numUsedCurves; i++) {
        //Update x,y lists
        m_xdata.clear();
        m_ydata.clear();

        for (int j = 0; j < m_size_curve[i]; j++) {
            m_xdata.append(m_xcurve[i][j]);
            m_ydata.append(m_ycurve[i][j]);
        }

        DrawDataPoints(painter,i);

    }
}

void CPlotCustomWidget::DrawLinearGrid(QPainter &painter)
{

    //Draw Linear Grid
    //QPen axispen(m_axisColor);
    //axispen.setWidth(1);
    //axispen.setStyle(Qt::DashLine);
    //painter.setPen(axispen);
    painter.setPen(m_gridPen);

    double tickXoffset = (m_xMax - m_xMin)/m_xTicks;
    double tickYoffset = (m_yMax - m_yMin)/m_yTicks;

    double tickXoffsetDraw = tickXoffset*scalefactorx;
    double tickYoffsetDraw = tickYoffset*scalefactory;

    QPoint P1,P2;

    double aux;
    QString tick;

    for(int i = 0; i < m_xTicks; i++) {
        P1.setX(origin.x()+ tickXoffsetDraw*(i+1));
        P1.setY(origin.y());
        P2.setX(origin.x()+ tickXoffsetDraw*(i+1));
        P2.setY(origin.y()-y_dimension);
        painter.drawLine(P1,P2);

        aux = m_xMin + tickXoffset*(i+1);
        if (!m_ticklog) {
            tick.sprintf("%3.1f",aux);
        } else {
            tick.sprintf("%3.1e",aux);
        }
        painter.drawText(P1.x(),P1.y(),tick);
    }

    for(int i = 0; i < m_yTicks; i++) {
        P1.setX(origin.x());
        P1.setY(origin.y() - tickYoffsetDraw*(i+1));
        P2.setX(origin.x() + x_dimension);
        P2.setY(origin.y() - tickYoffsetDraw*(i+1));
        painter.drawLine(P1,P2);

        aux = m_yMin + tickYoffset*(i+1);
        if (!m_ticklog) {
            tick.sprintf("%3.1f",aux);
        } else {
            tick.sprintf("%3.1e",aux);
        }
        painter.drawText(P1.x(),P1.y(),tick);
    }
}

void CPlotCustomWidget::DrawLogGrid(QPainter &painter)
{
    //Draw Log grid
    //QPen axispen(m_axisColor);
    //axispen.setWidth(1);
    //axispen.setStyle(Qt::DashLine);
   // Qt::PenStyle a = Qt::DotLine;
   // axispen.setStyle(a);
    //painter.setPen(axispen);
    painter.setPen(m_gridPen);

    //Vertical lines
    QList<double> tickXlog;
    QList<double> tickXlogPlot;

    for (int j = 0; j < m_xlogNumDecades; j++) {
        for (int i = 0; i < 9; i++) {
            tickXlog.append((i+1)*qPow(10,j));
        }
    }
    tickXlog.append(qPow(10,m_xlogNumDecades));

    double scalelogx = x_dimension/m_xlogNumDecades;

    for (int i = 0; i < tickXlog.size(); i++) {
        tickXlogPlot.append(qLn(tickXlog[i])/2.30258509299*scalelogx);
    }

    QPoint P1,P2;
    QString tick;

    for(int i = 0; i < tickXlogPlot.size(); i++) {
        P1.setX(origin.x()+ tickXlogPlot[i]);
        P1.setY(origin.y());
        P2.setX(origin.x()+ tickXlogPlot[i]);
        P2.setY(origin.y()-y_dimension);
        painter.drawLine(P1,P2);

        //Text
        if (!(i%9)) {
            if (!m_ticklog) {
                tick.sprintf("%3.1f",tickXlog[i]*m_xMinlog);
            } else {
                tick.sprintf("%3.1e",tickXlog[i]*m_xMinlog);
            }
            painter.drawText(P1.x(),P1.y()+11,tick);
        }
    }

    //Horizontal Lines
    QList<double> tickYlog;
    QList<double> tickYlogPlot;

    for (int j = 0; j < m_ylogNumDecades; j++) {
        for (int i = 0; i < 9; i++) {
            tickYlog.append((i+1)*qPow(10,j));
        }
    }
    tickYlog.append(qPow(10,m_ylogNumDecades));

    double scalelogy = y_dimension/m_ylogNumDecades;

    for (int i = 0; i < tickYlog.size(); i++) {
        tickYlogPlot.append(qLn(tickYlog[i])/2.30258509299*scalelogy);
    }

    for(int i = 0; i < tickYlogPlot.size(); i++) {
        P1.setX(origin.x());
        P1.setY(origin.y() - tickYlogPlot[i]);
        P2.setX(origin.x() + x_dimension);
        P2.setY(origin.y() - tickYlogPlot[i]);
        painter.drawLine(P1,P2);
        //Text
        if (!(i%9)) {
            if (!m_ticklog) {
                tick.sprintf("%3.1f",tickYlog[i]*m_yMinlog);
            } else {
                tick.sprintf("%3.1e",tickYlog[i]*m_yMinlog);
            }
            painter.drawText(P1.x(),P1.y()-2,tick);
        }

    }


}

void CPlotCustomWidget::DrawSemiLogGrid(QPainter &painter)
{
    //Draw Log grid
    //QPen axispen(m_axisColor);
    //axispen.setWidth(1);
    //axispen.setStyle(Qt::SolidLine);
    //painter.setPen(axispen);
    //m_gridPen.setStyle(Qt::SolidLine);
    painter.setPen(m_gridPen);


    //Vertical lines logarithm
    QList<double> tickXlog;
    QList<double> tickXlogPlot;

    for (int j = 0; j < m_xlogNumDecades; j++) {
        for (int i = 0; i < 9; i++) {
            tickXlog.append((i+1)*qPow(10,j));
        }
    }
    tickXlog.append(qPow(10,m_xlogNumDecades));

    double scalelogx = x_dimension/m_xlogNumDecades;

    for (int i = 0; i < tickXlog.size(); i++) {
        tickXlogPlot.append(qLn(tickXlog[i])/2.30258509299*scalelogx);
    }

    QPoint P1,P2;
    QString tick;

    for(int i = 0; i < tickXlogPlot.size(); i++) {
        P1.setX(origin.x()+ tickXlogPlot[i]);
        P1.setY(origin.y());
        P2.setX(origin.x()+ tickXlogPlot[i]);
        P2.setY(origin.y()-y_dimension);
        painter.drawLine(P1,P2);

       //Text
        if (!(i%9)) {
            if (!m_ticklog) {
                tick.sprintf("%3.1f",tickXlog[i]*m_xMinlog);
            } else {
                tick.sprintf("%3.1e",tickXlog[i]*m_xMinlog);
            }
            painter.drawText(P1.x(),P1.y()+11,tick);
        }

    }

    //Horizontal Lines linear
    double tickYoffset = (m_yMax - m_yMin)/m_yTicks;

    double tickYoffsetDraw = tickYoffset*scalefactory;

    double aux;

    for(int i = 0; i < m_yTicks; i++) {
        P1.setX(origin.x());
        P1.setY(origin.y() - tickYoffsetDraw*(i+1));
        P2.setX(origin.x() + x_dimension);
        P2.setY(origin.y() - tickYoffsetDraw*(i+1));
        painter.drawLine(P1,P2);

        aux = m_yMin + tickYoffset*(i+1);
        if (!m_ticklog) {
            tick.sprintf("%3.1f",aux);
        } else {
            tick.sprintf("%3.1f",aux);
        }
        painter.drawText(P1.x(),P1.y(),tick);
    }
}

void CPlotCustomWidget::SetGridStyle(Qt::PenStyle a)
{
    m_gridPen.setColor(m_axisColor);
    m_gridPen.setWidth(1);
    m_gridPen.setStyle(a);
}

void CPlotCustomWidget::setTickLog(bool en)
{
    m_ticklog = en;
}

void CPlotCustomWidget::appendCurve(QList<double> &x, QList<double> &y)
{
    if (m_numUsedCurves == 10) {
        m_numUsedCurves = 0;
    }

    int N = x.size();
    m_size_curve[m_numUsedCurves] = N;
    for (int i = 0; i < N; i++) {
        m_xcurve[m_numUsedCurves][i] = x[i];
        m_ycurve[m_numUsedCurves][i] = y[i];
    }

    m_numUsedCurves++;


}

void CPlotCustomWidget::appendPoint(double x, double y, int curve)
{

    int index = m_size_curve[curve];

    if (index == 50) return; //Buffer limit reached!

    m_xcurve[curve][index] = x;
    m_ycurve[curve][index] = y;
    m_size_curve[curve]++;
}

void CPlotCustomWidget::setNumUsedCurves(int num)
{
    m_numUsedCurves = num;
}

void CPlotCustomWidget::clearCurve(int curve)
{
    m_size_curve[curve] = 0;
}

void CPlotCustomWidget::paintEvent(QPaintEvent *e)
{
    //Get the dimensions of the widget
    int width, height;

    width = this->width();
    height = this->height();

    QPainter painter(this);

    //Background
    QRect rec(0, 0, width, height);
    QBrush backbrush;
    backbrush.setColor(m_backgroundColor);
    backbrush.setStyle(Qt::SolidPattern);
    painter.setBrush(backbrush);
    painter.drawRect(rec);

    //Draw axis
    int offset_factorx = 20;
    int offset_factory = 15;

    int offsetx = width/offset_factorx;
    int offsety = height/offset_factory;

    x_dimension = width - 2*offsetx;
    y_dimension = height - 2*offsety;

    //These scale factors are valid only for linear plots!
    scalefactorx = x_dimension/(m_xMax - m_xMin);
    scalefactory = y_dimension/(m_yMax - m_yMin);


    QPoint axis_y1(offsetx,offsety);
    QPoint axis_y2(offsetx,height - offsety);
    QPoint axis_x1(offsetx,height - offsety);
    QPoint axis_x2(width- offsetx,height - offsety);

    origin = QPoint(width/offset_factorx,height - height/offset_factory);

    QPen axispen(m_axisColor);
    axispen.setWidth(2);
    painter.setPen(axispen);

    painter.drawLine(axis_y1,axis_y2);
    painter.drawLine(axis_x1,axis_x2);

    //Draw Axis names
    QPoint xAxispos(width/2,height - offsety/10);
    painter.drawText(xAxispos,m_xAxis);

    QPoint yAxispos(offsetx/2,height/2);
    painter.save();
    painter.translate(yAxispos);
    painter.rotate(-90.0);
    painter.drawText(0,0,m_yAxis);
    painter.rotate(90);
    painter.restore();


    //Draw Thicks
    if (m_gridEnabled) {
        if (m_linEnabled) {
            DrawLinearGrid(painter);
        } else if (m_logEnabled) {
            DrawLogGrid(painter);
        } else if (m_semilogEnabled) {
            DrawSemiLogGrid(painter);
        }
    }

    //Draw datapoints
    //DrawDataPoints(painter); //Single curve
    DrawCurves(painter);

}
