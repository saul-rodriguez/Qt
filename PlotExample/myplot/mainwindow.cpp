#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts/QChartView>

#include <QTimer>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Create a PlotChart object, initialize it and attacht it to a chartView
    m_chart = new CPlotChart();

    m_chart->initializePlot();
    m_chart->setTitles("Test Plot","time","voltage");

    m_chartView = new QChartView(static_cast<QChart*>(m_chart));

    //Set antialising properties and the chartview object to a place in layout
    m_chartView->setRenderHint(QPainter::Antialiasing, true); //false or true
    ui->verticalLayout->addWidget(m_chartView,1,0);

    //Test plot
    /*
    DataTrace aux_trace;
    aux_trace = generateData();

    m_chart->addTrace(aux_trace);
    m_chart->updatePlot();
    */

    //Timer for testing real time plot

    m_sin = generateData();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlot()));
    timer->start(25);
    m_counter = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

DataTrace MainWindow::generateData()
{
    double x,y;

    DataTrace aux_trace;
    DataPoint aux_point;

    for (int i=0; i < 100; i++) {
        x = static_cast<double>(i)/100.;
        y = qSin(2*M_PI*x);

        aux_point.first.setX(x);
        aux_point.first.setY(y);
        aux_point.second = "Tag: " + QString::number(i);

        aux_trace.append(aux_point);
    }
    return aux_trace;
}

void MainWindow::updatePlot()
{


    DataTrace aux_trace;

    int size = m_sin.count();

    int head = m_counter%size + 1;

    for (int i = 0; i < head; i++) {
        aux_trace.append(m_sin[i]);
    }

    m_chart->clearTable();
    m_chart->addTrace(aux_trace);
    m_chart->updatePlot();

    m_counter++;

}
