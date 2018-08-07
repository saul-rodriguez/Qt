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

    m_trace_factor = 0;
    m_color = 0;
    generate_data();



   // lineEdit = new QLineEdit;
    //lineEdit2 = new QLineEdit;
    //pbutton = new QPushButton;
    //ui->gridLayout->addWidget(lineEdit,0,0);
    //ui->gridLayout->addWidget(pbutton,0,1);
    //ui->verticalLayout->addWidget(pbutton);
    //pbutton->setMaximumHeight(55);
    //ui->verticalLayout->addStretch(100);

   // QChartView *chartView;


    //Creates a QChart object, attach it to a QChartView, and assign it to a place in layout
   // m_chart = createLineChart();
   // m_chartView = new QChartView(m_chart);
    initializeChart();
    ui->myverticalLayout->addWidget(m_chartView,1,0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeChart()
{
    QChart *chart = new QChart();
    chart->setTitle("Line chart"); //Title
    m_chart = chart;

    QLineSeries *series = new QLineSeries();
    series->append(0,0);
    //series->append(0,1);
    m_chart->addSeries(series);

    //updateChartOptions
    updateChartOptions();


    m_chartView = new QChartView(m_chart);
    m_chartView->setRenderHint(QPainter::Antialiasing, true);
}

void MainWindow::updateChartOptions()
{
    m_chart->createDefaultAxes();
    m_chart->axisX()->setRange(0, 1);
    m_chart->axisX()->setTitleText("time");
    m_chart->axisY()->setRange(0, 1);
    m_chart->axisY()->setTitleText("Voltage");
    m_chart->legend()->hide();
    //m_chart->setAnimationOptions(QChart::AllAnimations);
    static_cast<QValueAxis *>(m_chart->axisY())->setLabelFormat("%.1f  ");
}

void MainWindow::generate_data()
{
    QLineSeries aux_series;
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
   m_trace_factor +=0.1;
   generate_data();


   //Update the data in the chart
   QLineSeries *series; //Contains points, colors, etc of a single trace
   series = new QLineSeries();

   int size = traces.size();

   m_chart->removeAllSeries(); //removes and deletes series objects
   if (size) {
       for (int i = 0; i < size; i++) {
           series = new QLineSeries(); //create a new trace
           series->append(traces[i]); //Append the trace (QList <QPointF>)
           series->setName(QString::number(i));
           m_chart->addSeries(series);
       }

    //Update the axis
       m_chart->createDefaultAxes();
       m_chart->axisX()->setRange(0, 1);
       m_chart->axisY()->setRange(0, 1);
       m_chart->createDefaultAxes();
       m_chart->axisX()->setRange(0, 1);
       m_chart->axisX()->setTitleText("time");
       m_chart->axisY()->setRange(0, 1);
       m_chart->axisY()->setTitleText("Voltage");
       m_chartView->setRenderHint(QPainter::Antialiasing, true);

   }

}

void MainWindow::on_pushButton_Test_clicked()
{
    if (m_color < 7) {
        m_color++;

        m_chart->setTheme(static_cast<QChart::ChartTheme>(m_color));

    } else {
        m_color = 0;
    }
}
