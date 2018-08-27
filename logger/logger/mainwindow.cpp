#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts/QChartView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_MaxDataPlot = 640;
    m_DataCounter = 0;

    //Bluetooth
    m_bt = new BTClient(this);
    connect(m_bt, SIGNAL(BTnewDeviceDiscovered(QString)),
            this, SLOT(BTgetDevice(QString)));
    connect(m_bt, SIGNAL(BTnewDeviceConnected(QString)),
            this, SLOT(BTConnected(QString)));
    connect(m_bt, SIGNAL(BTrxData(QByteArray)),
            this, SLOT(BTrxData(const QByteArray)));

    //Plot
    m_chart = new CPlotChart();
    m_chart->setTitles("","Time","ADC");
    m_chart->setXMinXax(0,m_MaxDataPlot);
    m_chart->setYMinXax(0,1024);
    m_chart->initializePlot();
    m_chartView = new QChartView(static_cast<QChart*>(m_chart));
    //Set antialising properties and the chartview object to a place in layout
    m_chartView->setRenderHint(QPainter::Antialiasing, true); //false or true
    ui->verticalLayout_3->addWidget(m_chartView,1,0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BTgetDevice(QString name)
{
    qDebug()<< name;
    ui->comboBoxBTdevices->addItem(name);
}

void MainWindow::BTConnected(QString name)
{
    QString message = "Connected to: " + name;
    ui->labelBTstatus->setText(message);
    qDebug()<< message;
}

void MainWindow::BTrxData(const QByteArray &data)
{
    ui->plainTextEditAT->appendPlainText(QString::fromStdString(data.toStdString()));

    //if data is a 64bytes binary packet, then send it to plot
    if (data.count() == 64) {
        PlotRx(data);
    }
}

void MainWindow::PlotRx(const QByteArray &data)
{
    DataPoint aux_point;

    int index = 0;
    int plot_index = 0;
    quint16 value;
    for (int i = 0; i < 32; i++) {
        value = data.at(index++) & 0xff;
        value |= (data.at(index++) << 8) & 0xff00;


        aux_point.first.setX(m_DataCounter);
        aux_point.first.setY(value);
        aux_point.second = QString::number(m_DataCounter);

        m_trace.append(aux_point);

        plot_index = m_DataCounter%m_MaxDataPlot;
        if (plot_index == 0) {
            m_plot_trace.clear();
        } else {
            aux_point.first.setX(plot_index);
            m_plot_trace.append(aux_point);
        }



        m_DataCounter++;
    }

/*
    int block_num =  m_DataCounter/(m_MaxDataPlot+1);
    int block_rest = m_DataCounter%(m_MaxDataPlot+1);

    int tail = block_num*(m_MaxDataPlot);
    int head = tail + block_rest;

    if (tail == head) return;

    for (int i = tail; i < head; i++) {
        aux_trace.append(m_trace[i]);
    }
*/
    if(m_plot_trace.count()) {
        m_chart->clearTable();
        m_chart->addTrace(m_plot_trace);
        m_chart->updatePlot();
    }
}


void MainWindow::on_pushButtonBTdiscoverDevices_clicked()
{
    m_bt->BTfindDevices();
}

void MainWindow::on_pushButtonBTconnect_clicked()
{
    QString name;
    name = ui->comboBoxBTdevices->currentText();
    m_bt->BTconnect(name);
    ui->labelBTstatus->setText("Connecting...");
}

void MainWindow::on_pushButtonATSend_clicked()
{
    QString aux = ui->lineEditAT->text();

    QByteArray data;
    data.append(aux);
    //data.append('\r');
    //data.append('\n');
    m_bt->BTwrite(data);
}
