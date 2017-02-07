
#ifndef CPLOTCUSTOMWIDGET_H
#define CPLOTCUSTOMWIDGET_H

#include <QWidget>
#include "QPainter"

class CPlotCustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CPlotCustomWidget(QWidget *parent = 0);

    void SetXAxisName(QString name);  // X Axis name
    void SetYAxisName(QString name);  // Y Axis name

    void setXMax(double max); // Max X value for linear plot
    void setXMin(double min); // Min X value for linear plot
    void setYMax(double max); // Max Y value for linear plot
    void setYMin(double min); // Min Y value for linear plot

    void setXMinLog(double min); // Min X value for logarithmic plot
    void setYMinLog(double min); // Min Y value for logarithmic plot

    void enableGrid(bool en); // enable/disable the grid

    void setXTicksNum(int num); // number of X ticks for linear plot
    void setYTicksNum(int num); // number of Y ticks for linear plot

    void enableLinPlot();   // Selects linear plot (default)
    void enableLogPlot();   // Selects Log plot
    void enableSemiLogPlot();   // Selects semilog plot


    void setDataPoints(QList<double> &x, QList<double> &y);

    void DrawDataPoints(QPainter &painter, int color);
    void DrawCurves(QPainter &painter);

    void DrawLinearGrid(QPainter &painter);
    void DrawLogGrid(QPainter &painter);
    void DrawSemiLogGrid(QPainter &painter);

    void SetGridStyle(Qt::PenStyle a);

    void setTickLog(bool en);

    void appendCurve(QList<double> &x, QList<double> &y);

protected:
    void paintEvent(QPaintEvent *e);

signals:

public slots:

private:

    QString m_xAxis; // X Axis name
    QString m_yAxis; // Y Axis name

    QColor m_backgroundColor;
    QColor m_axisColor;
    QColor m_lineColor[10];

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

    QList<double> m_xdata;
    QList<double> m_ydata;

   double m_xcurve[10][50];
   double m_ycurve[10][50];
   int m_size_curve[10];
   int m_numUsedCurves;
   //int m_numMaxCurves;

};

#endif // CPLOTCUSTOMWIDGET_H

