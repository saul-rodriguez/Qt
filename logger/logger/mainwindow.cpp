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
    m_PlotCounter = 0;
    m_PlotTimeout = 20;
    m_PlotNumUpdate = 2;

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

    //timer to refresh the plot
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(PlotTimeout()));
    m_timer->start(m_PlotTimeout);

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

    m_data.append(data);

    int size = data.count();
    if (size%2) { //each values is 2 bytes. There is an incomplete value!
        qDebug()<<"Odd number of bytes received";
        return; //wait for the next rx
    } else { // Process the received values
        PlotRx(m_data);
        m_data.clear();
    }

}

void MainWindow::PlotRx(const QByteArray &data)
{
    DataPoint aux_point;
    int index = 0;   
    quint16 value;

    int size = data.count()/2; //Each converted value comes in 2 bytes unsigned short.

    for (int i = 0; i < size; i++) {
        //reconstruct the digital value
        value = data.at(index++) & 0xff;
        value |= (data.at(index++) << 8) & 0xff00;

        //Create a data point
        aux_point.first.setX(m_DataCounter);
        aux_point.first.setY(value);
        aux_point.second = QString::number(m_DataCounter);

        //Save the data point for further processing/plotting
        m_trace.append(aux_point);
        m_DataCounter++;
    }
    //The data is plotted using a time_out
}

void MainWindow::PlotTimeout()
{
    int plot_index;
     DataPoint aux_point;

    if (m_PlotCounter == m_DataCounter) // No new samples added at this time
        return;

    //Update the plot's trace list
    int head = m_PlotCounter + m_PlotNumUpdate;
    for (int i = m_PlotCounter; i < head; i++) {
        plot_index = m_PlotCounter%m_MaxDataPlot; //create a index between 0 - m_MaxDataPot
        if (plot_index == 0) {  //clear the plot trace
            m_plot_trace.clear();
        } else {
            aux_point = m_trace.at(i);
            aux_point.first.setX(plot_index);
            m_plot_trace.append(aux_point);
        }
        m_PlotCounter++;
    }

    //replot the trace
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
