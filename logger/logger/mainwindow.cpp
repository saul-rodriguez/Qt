#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts/QChartView>

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //config initialization, WiFi disabled
    ui->pushButtonBTconnect->setEnabled(true);
    ui->pushButtonBTdiscoverDevices->setEnabled(true);
    ui->pushButtonWiFiConnect->setEnabled(false);
    ui->lineEditWiFiAddress->setEnabled(false);
    ui->lineEditWiFiPort->setEnabled(false);

    m_MaxDataPlot = 640;
    m_DataCounter = 0;
    m_PlotCounter = 0;
    m_PlotTimeout = 20; //time in ms
    m_PlotNumUpdate = 2; //number of samples to update every m_PlotTimeout

    //Bluetooth
    m_bt = new BTClient(this);
    connect(m_bt, SIGNAL(BTnewDeviceDiscovered(QString)),
            this, SLOT(BTgetDevice(QString)));
    connect(m_bt, SIGNAL(BTnewDeviceConnected(QString)),
            this, SLOT(BTConnected(QString)));
    connect(m_bt, SIGNAL(BTrxData(QByteArray)),
            this, SLOT(BTrxData(const QByteArray)));

    //WiFi
    m_WiFiTcpSocket = new QTcpSocket(this);
    m_WiFi_in.setDevice(m_WiFiTcpSocket);
    m_WiFi_in.setVersion(QDataStream::Qt_5_11);
    connect(m_WiFiTcpSocket, SIGNAL(readyRead()),this, SLOT(WiFiRead()));
    connect(m_WiFiTcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
               this, &MainWindow::WiFiDisplayError);

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

void MainWindow::WiFiRead()
{
    m_WiFi_in.startTransaction();

    QByteArray data = m_WiFiTcpSocket->readAll();

    if(!m_WiFi_in.commitTransaction()) {
        return;
    }

    m_data.append(data);

    int size = data.count();
    if (size%2) { //each values is 2 bytes. There is an incomplete value!
        qDebug()<<"Odd number of bytes received";
        return; //wait for the next rx
    } else { // Process the received values
        PlotRx(m_data);
        m_data.clear();
    }

    //Data is valid
    ui->plainTextEditAT->appendPlainText(QString::fromStdString(data.toStdString()));
}

void MainWindow::WiFiDisplayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
         case QAbstractSocket::RemoteHostClosedError:
             break;
         case QAbstractSocket::HostNotFoundError:
             QMessageBox::information(this, tr("TCP client"),
                                      tr("The host was not found. Please check the "
                                         "host name and port settings."));
             break;
         case QAbstractSocket::ConnectionRefusedError:
             QMessageBox::information(this, tr("TCP client"),
                                      tr("The connection was refused by the peer. "
                                         "Make sure the fortune server is running, "
                                         "and check that the host name and port "
                                         "settings are correct."));
             break;
         default:
             QMessageBox::information(this, tr("TCP client"),
                                      tr("The following error occurred: %1.")
                                      .arg(m_WiFiTcpSocket->errorString()));
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

    if (ui->radioButtonBT->isChecked()) {
        m_bt->BTwrite(data);
    } else {
        m_WiFiTcpSocket->write(data);
    }
}

void MainWindow::on_radioButtonWiFi_toggled(bool checked)
{
    if (checked) {
        ui->pushButtonBTconnect->setEnabled(false);
        ui->pushButtonBTdiscoverDevices->setEnabled(false);
        ui->pushButtonWiFiConnect->setEnabled(true);
        ui->lineEditWiFiAddress->setEnabled(true);
        ui->lineEditWiFiPort->setEnabled(true);
    }
}

void MainWindow::on_radioButtonBT_toggled(bool checked)
{
    if (checked) {
        ui->pushButtonBTconnect->setEnabled(true);
        ui->pushButtonBTdiscoverDevices->setEnabled(true);
        ui->pushButtonWiFiConnect->setEnabled(false);
        ui->lineEditWiFiAddress->setEnabled(false);
        ui->lineEditWiFiPort->setEnabled(false);
    }

}

void MainWindow::on_pushButtonWiFiConnect_clicked()
{
    QString address = ui->lineEditWiFiAddress->text();
    QString port = ui->lineEditWiFiPort->text();

       ui->labelWiFiStatus->setText("Connecting...");

       m_WiFiTcpSocket->connectToHost(address,port.toInt());

       if(!m_WiFiTcpSocket->waitForConnected(5000)) {
              QString aux = "Error connecting: " + m_WiFiTcpSocket->errorString();
              ui->labelWiFiStatus->setText(aux);
              return;
       }

       ui->labelWiFiStatus->setText("Connected");

}
