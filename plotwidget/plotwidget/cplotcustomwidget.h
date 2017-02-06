#ifndef CPLOTCUSTOMWIDGET_H
#define CPLOTCUSTOMWIDGET_H

#include <QWidget>
#include "QPainter"

class CPlotCustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CPlotCustomWidget(QWidget *parent = 0);

    void SetXAxisName(QString name);
    void SetYAxisName(QString name);

    void setXMax(double max);
    void setXMin(double min);
    void setYMax(double max);
    void setYMin(double min);

    void setXMinLog(double min);
    void setYMinLog(double min);

    void enableGrid(bool en);

    void setXTicksNum(int num);
    void setYTicksNum(int num);

    void enableLinPlot();
    void enableLogPlot();
    void enableSemiLogPlot();

    void DrawLinearGrid(QPainter &painter);
    void DrawLogGrid(QPainter &painter);
    void DrawSemiLogGrid(QPainter &painter);

    void SetGridStyle(Qt::PenStyle a);

    void setTickLog(bool en);

protected:
    void paintEvent(QPaintEvent *e);


signals:

public slots:

private:

    QString m_xAxis; // X Axis name
    QString m_yAxis; // Y Axis name

    QColor m_backgroundColor;
    QColor m_axisColor;

    QPen m_gridPen;

    QPoint origin;

    double m_xMin; // Minimum X
    double m_xMax; // Maximum X

    double m_yMin; // Minimum Y
    double m_yMax; // Maximum Y

    double m_xMinlog; //minimum log value x
    double m_yMinlog; //minimum log value y

    bool m_ticklog; // display ticks as exp instead as float



    bool m_gridEnabled;

    int m_xTicks; // Number of ticks X
    int m_yTicks; // Numer of ticks Y

    bool m_linEnabled;
    bool m_logEnabled;
    bool m_semilogEnabled;

    int m_xlogNumDecades;
    int m_ylogNumDecades;

    int x_dimension;
    int y_dimension;

    double scalefactorx;
    double scalefactory;
};

#endif // CPLOTCUSTOMWIDGET_H
