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
    ui->pushButtonWiFiDisconnect->setEnabled(false);
    ui->lineEditWiFiAddress->setEnabled(false);
    ui->lineEditWiFiPort->setEnabled(false);

    m_MaxDataPlot = 640;
    m_DataCounter = 0;
    m_MaxNumSamples = 6000; //Max Number of samples to be recorded before the buffers are cleared
    m_PlotCounter = 0;
    m_PlotTimeout = 100; //time in ms
    m_PlotNumUpdate = 10; //number of samples to update every m_PlotTimeout

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
    m_chart->setTitles("","VSG","ID");
  //  m_chart->setXMinXax(0,m_MaxDataPlot);
  //  m_chart->setYMinXax(0,1024);
    m_chart->setXMinXax(0,1.8);
    m_chart->setYMinXax(0.1e-9,10e-6);
    m_chart->initializePlot();
    m_chartView = new QChartView(static_cast<QChart*>(m_chart));
    //Set antialising properties and the chartview object to a place in layout
    m_chartView->setRenderHint(QPainter::Antialiasing, false); //false or true
    ui->verticalLayout_3->addWidget(m_chartView,1,0);

    //timer to refresh the plot
    //m_timer = new QTimer(this);
    //connect(m_timer, SIGNAL(timeout()), this, SLOT(PlotTimeout()));
    //m_timer->start(m_PlotTimeout);


    //nn2sense
    double aux = 2e-6; //dac Bias current
    for (int i=0; i<12; i++) {
        aux /= 2.0;
        m_current[i] = aux;
    }

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
    //ui->labelBTstatus->setText(message);
    ui->labelBTstatus->setText("Connected");
    qDebug()<< message;
}

void MainWindow::BTrxData(const QByteArray &data)
{
    ui->plainTextEditAT->appendPlainText(QString::fromStdString(data.toStdString()));

    m_data.append(data);

    /*//Continuous sampling processing
    if (!m_timer->isActive())
        return;
    */

    //int size = data.count();
    int size = m_data.count();

    if (size == 24) {
        PlotRx(m_data);
        m_data.clear();
    } else if (size < 24) {
        qDebug()<<"Waiting for rest of packet";
        return; //wait for the next rx
    } else {
        qDebug()<<"packet error, discarding";
        return; //wait for the next rx
    }

}

void MainWindow::WiFiRead()
{
    m_WiFi_in.startTransaction();

    QByteArray data = m_WiFiTcpSocket->readAll();

    if(!m_WiFi_in.commitTransaction()) {
        return;
    }

    //Data is valid
    ui->plainTextEditAT->appendPlainText(QString::fromStdString(data.toStdString()));


    //Continuous sampling processing
    if (!m_timer->isActive())
        return;

    m_data.append(data);

    int size = data.count();
    if (size%2) { //each value is 2 bytes. There is an incomplete value!
        qDebug()<<"Odd number of bytes received";
        return; //wait for the next rx
    } else { // Process the received values
        PlotRx(m_data);
        m_data.clear();
    }


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
    double val;

    int size = data.count()/2; //Each converted value comes in 2 bytes unsigned short.

    m_trace.clear();
    for (int i = 0; i < size; i++) {
        //reconstruct the digital value
        value = data.at(index++) & 0xff;
        value |= (data.at(index++) << 8) & 0xff00;

        val = value*1.8/4096.0;
      /*  //Create a data point
        aux_point.first.setX(m_DataCounter);
        aux_point.first.setY(value);
        aux_point.second = QString::number(m_DataCounter); */

        aux_point.first.setX(val);
        aux_point.first.setY(m_current[i]);
        aux_point.second = QString::number(value);


        //Save the data point for further processing/plotting
        m_trace.append(aux_point);
        m_DataCounter++;
    }

    if(m_trace.count()) {
        m_chart->clearTable();
        m_chart->addTrace(m_trace);
        m_chart->updatePlot();
    }
}

void MainWindow::PlotTimeout()
{
    int head;
    int plot_index;
     DataPoint aux_point;

    if (m_PlotCounter == m_DataCounter) // No new samples added at this time
        return;

    //Update the plot's trace list
    //Uncomment the following lines in order to smooth the updating ofplot (only works fine in desktop)
   /* head = m_PlotCounter + m_PlotNumUpdate;
    if (head > m_DataCounter)
        head = m_DataCounter;
   */

    //Uncomment the next line in order to update the plot with all the new data at once
    //head = m_DataCounter;

    if (ui->checkBoxConfigSmoothPlot->isChecked()) { //Only add M_PlotNumUpdate samples to the plot
        head = m_PlotCounter + m_PlotNumUpdate;
        if (head > m_DataCounter) {
                head = m_DataCounter;
        }
    } else {    //Add all new samples to the plot
        head = m_DataCounter;
    }

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

    //Check if number of samples are exceeded
    if (m_trace.count() >= m_MaxNumSamples) {
        m_trace.clear();
        m_DataCounter = 0;
        m_plot_trace.clear();
        m_PlotCounter = 0;
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
  /*  QByteArray mydat;
    mydat.append(0xff);
    mydat.append((unsigned char)0x00);
    mydat.append(0xff);
    mydat.append(0x01);
    mydat.append(0xff);
    mydat.append(0x2);
    mydat.append(0xff);
    mydat.append(0x3);
    mydat.append(0xff);
    mydat.append(0x4);
    mydat.append(0xff);
    mydat.append(0x05);
    mydat.append(0xff);
    mydat.append(0x06);
    mydat.append(0xff);
    mydat.append(0x07);
    mydat.append(0xff);
    mydat.append(0x08);
    mydat.append(0xff);
    mydat.append(0x09);
    mydat.append(0xff);
    mydat.append(0x0a);
    mydat.append(0xff);
    mydat.append(0x0b);

    PlotRx(mydat);
    return;
*/
    QString aux = ui->lineEditAT->text();

    QByteArray data;
    data.append(aux);


    if (ui->radioButtonBT->isChecked()) {
        m_bt->BTwrite(data);
    } else {    //The communication with the ESP-01 module is always terminated by cr + nl
        data.append('\r');
        data.append('\n');
        m_WiFiTcpSocket->write(data);
    }

    //if continuous sampling is sent, start the timer
 /*   switch (data.at(0)) {
        case 's':   m_timer->start(m_PlotTimeout);
                    break;
        case 'S':   m_timer->stop();
                    break;
        default:
                    break;

    }*/
}

void MainWindow::on_radioButtonWiFi_toggled(bool checked)
{
    if (checked) {
        ui->pushButtonBTconnect->setEnabled(false);
        ui->pushButtonBTdiscoverDevices->setEnabled(false);
        ui->pushButtonWiFiConnect->setEnabled(true);
        ui->pushButtonWiFiDisconnect->setEnabled(true);
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
        ui->pushButtonWiFiDisconnect->setEnabled(false);
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

void MainWindow::on_pushButtonWiFiDisconnect_clicked()
{
    ui->labelWiFiStatus->setText("Disconnecting...");
    m_WiFiTcpSocket->disconnectFromHost();;

}


void MainWindow::on_checkBoxConfigAntialias_toggled(bool checked)
{
    if (checked) {
        m_chartView->setRenderHint(QPainter::Antialiasing, true); //false or true
    } else {
        m_chartView->setRenderHint(QPainter::Antialiasing, false); //false or true
    }
}

void MainWindow::on_pushButtonBTdisconnect_clicked()
{
    m_bt->BTdisconnect();
    ui->labelBTstatus->setText("Disconnected");
}

void MainWindow::on_pushButtonTestNN2S_clicked()
{
    ui->lineEditAT->setText("t");
    on_pushButtonATSend_clicked();
}

void MainWindow::on_pushButtonClearPlot_clicked()
{
    m_trace.clear();

    DataPoint aux_point;
    aux_point.first.setX(2.5);
    aux_point.first.setY(1e-9);

    m_trace.append(aux_point);



    if(m_trace.count()) {
        m_chart->clearTable();
        m_chart->addTrace(m_trace);
        m_chart->updatePlot();
    }

}
