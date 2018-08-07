#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QChart>
#include <QtCharts/QChartGlobal>

namespace Ui {
class MainWindow;
}

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

typedef QList <QPointF> trace;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QLineEdit *lineEdit;
    QLineEdit *lineEdit2;
    QPushButton *pbutton;

    QChartView *m_chart;
    QChart *createLineChart() const;
    void generate_data(void);

    QList <trace> traces;

    int m_trace_factor;


};

#endif // MAINWINDOW_H
