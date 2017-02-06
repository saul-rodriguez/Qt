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

    m_xAxis = "X";
    m_yAxis = "Y";

    m_xMin = 0;
    m_xMax = 10000;

    m_yMin = 0;
    m_yMax = 100;

    m_xTicks = 10;
    m_yTicks = 10;

    m_gridEnabled = true;
    m_linEnabled = false;

    m_logEnabled = true;
    m_semilogEnabled = true;

    m_xlogNumDecades = 3;
    m_ylogNumDecades = 2;

    m_xMinlog = 1;
    m_yMinlog = 1;

    m_ticklog = true;

    //SetGridStyle(Qt::DotLine);
    SetGridStyle(Qt::DashLine);


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

void CPlotCustomWidget::DrawLinearGrid(QPainter &painter)
{

    //Draw Linear Grid
    QPen axispen(m_axisColor);
    axispen.setWidth(1);
    axispen.setStyle(Qt::DashLine);
    painter.setPen(axispen);

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

        aux = m_xMin + tickYoffset*(i+1);
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
    QPen axispen(m_axisColor);
    axispen.setWidth(1);
    axispen.setStyle(Qt::DashLine);
   // Qt::PenStyle a = Qt::DotLine;
   // axispen.setStyle(a);
    painter.setPen(axispen);

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
            tick.sprintf("%3.1e",tickXlog[i]);
            painter.drawText(P1.x(),P1.y()+10,tick);
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

    for(int i = 0; i < tickXlogPlot.size(); i++) {
        P1.setX(origin.x()+ tickXlogPlot[i]);
        P1.setY(origin.y());
        P2.setX(origin.x()+ tickXlogPlot[i]);
        P2.setY(origin.y()-y_dimension);
        painter.drawLine(P1,P2);
    }

    //Horizontal Lines linear
    double tickYoffset = (m_yMax - m_yMin)/m_yTicks;

    double tickYoffsetDraw = tickYoffset*scalefactory;

    for(int i = 0; i < m_yTicks; i++) {
        P1.setX(origin.x());
        P1.setY(origin.y() - tickYoffsetDraw*(i+1));
        P2.setX(origin.x() + x_dimension);
        P2.setY(origin.y() - tickYoffsetDraw*(i+1));
        painter.drawLine(P1,P2);
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


}
