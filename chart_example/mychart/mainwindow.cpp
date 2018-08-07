#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QValueAxis>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_trace_factor = 1;
    generate_data();



   // lineEdit = new QLineEdit;
    //lineEdit2 = new QLineEdit;
    //pbutton = new QPushButton;
    //ui->gridLayout->addWidget(lineEdit,0,0);
    //ui->gridLayout->addWidget(pbutton,0,1);
    //ui->verticalLayout->addWidget(pbutton);
    //pbutton->setMaximumHeight(55);
    //ui->verticalLayout->addStretch(100);

    QChartView *chartView;

    chartView = new QChartView(createLineChart());
    ui->myverticalLayout->addWidget(chartView,1,0);
    m_chart = chartView;



}

MainWindow::~MainWindow()
{
    delete ui;
}

QChart *MainWindow::createLineChart() const
{
    QChart *chart = new QChart();
    chart->setTitle("Line chart");

    QLineSeries *series = new QLineSeries(chart);

    int size = traces.size();

    if (size) {
        for (int i = 0; i < size; i++) {
            series->append(traces[i]);
            series->setName(QString::number(i));
        }

        chart->addSeries(series);

    }

    chart->createDefaultAxes();
    chart->axisX()->setRange(0, 1);
    chart->axisY()->setRange(0, 1);

   // static_cast<QValueAxis *>(chart->axisY())->setLabelFormat("%.1f  ");


    return chart;
}

void MainWindow::generate_data()
{
    trace aux_trace;
    double x,y;
    QPointF aux;

    for (int i = 0; i < 10; i++) {
        x = (double)i/10;
        y = m_trace_factor*x*x;
        aux_trace.append(QPointF(x,y));
    }

    traces.append(aux_trace);

}

void MainWindow::on_pushButton_clicked()
{
    m_trace_factor *= 2;

  // QLineSeries *series = new QLineSeries();

   // series->append(0,5)
   // m_chart->add


}
