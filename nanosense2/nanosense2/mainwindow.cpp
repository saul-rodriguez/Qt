#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts/QChartView>

#include <QMessageBox>
#include <QtMath>


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
    // plot Magnitude
    m_chartMag = new CPlotChart();
    m_chartMag->setType(LOGLOG);
    m_chartMag->setTitles("","Frequency","Magnitude");
  //  m_chart->setXMinXax(0,m_MaxDataPlot);
  //  m_chart->setYMinXax(0,1024);
    m_chartMag->setXMinXax(100.0,10e6);
    m_chartMag->setYMinXax(10,1e6);
    m_chartMag->initializePlot();
    m_chartViewMag = new QChartView(static_cast<QChart*>(m_chartMag));
    //Set antialising properties and the chartview object to a place in layout
    m_chartViewMag->setRenderHint(QPainter::Antialiasing, false); //false or true
    ui->verticalLayout_3->addWidget(m_chartViewMag,1,0);

    //plot Phase
    m_chartPha = new CPlotChart();
    m_chartPha->setType(SEMILOGX);
    m_chartPha->setTitles("","Frequency","Phase");
    m_chartPha->setXMinXax(100.0,10e6);
    m_chartPha->setYMinXax(0,100);
    m_chartPha->initializePlot();
    m_chartViewPha = new QChartView(static_cast<QChart*>(m_chartPha));
    //Set antialising properties and the chartview object to a place in layout
    m_chartViewPha->setRenderHint(QPainter::Antialiasing, false); //false or true
    ui->verticalLayout_3->addWidget(m_chartViewPha,1,0);


    //timer to refresh the plot
    //m_timer = new QTimer(this);
    //connect(m_timer, SIGNAL(timeout()), this, SLOT(PlotTimeout()));
    //m_timer->start(m_PlotTimeout);

    //nanosense
    m_currentMeasurement = 0;
    m_timerMeas = new QTimer(this);
    m_timerMeas->setSingleShot(true);
    connect(m_timerMeas, SIGNAL(timeout()), this, SLOT(MeasurementTimeout()));

    for (int i=0; i < 11; i++) {
        m_gainCalFactor[i] = 0;
        m_phaseCalFactor[i] = 0;
    }

    //Tables
    setUpTables();


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
    int size = m_data.count();

    if (size == 7) { //Check for correct packet size
        p_bioimpedance = new bioimpedance();
        if(p_bioimpedance->setData(m_data)) {

            if (ui->checkBoxGainCalibration->isChecked()) {
                int ind = p_bioimpedance->getFrequencyIndex(REVERSE);
                p_bioimpedance->calibrateMagnitude(m_gainCalFactor[ind]);
                p_bioimpedance->calibratePhase(m_phaseCalFactor[ind]);
            }


            m_measurements[m_currentMeasurement].addImpedance(p_bioimpedance);
            qDebug()<<"arrival time: "<<m_timearrival.elapsed();

        } else {
            qDebug("bioimpedance packet corrupted");
            delete p_bioimpedance;
        }

        m_data.clear();
    } else if (size < 7) {
        qDebug()<<"Packet imcomplete, waiting for the rest of the packet!";
        return;
    } else {
        qDebug()<<"Packet error, discarding ";
        return;
    }

    /*
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
    */


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
        //aux_point.first.setY(m_current[i]);
        aux_point.second = QString::number(value);


        //Save the data point for further processing/plotting
        m_trace.append(aux_point);
        m_DataCounter++;
    }

    if(m_trace.count()) {
        m_chartMag->clearTable();
        m_chartMag->addTrace(m_trace);
        m_chartMag->updatePlot();
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
        m_chartMag->clearTable();
        m_chartMag->addTrace(m_plot_trace);
        m_chartMag->updatePlot();
    }

    //Check if number of samples are exceeded
    if (m_trace.count() >= m_MaxNumSamples) {
        m_trace.clear();
        m_DataCounter = 0;
        m_plot_trace.clear();
        m_PlotCounter = 0;
    }
}

void MainWindow::MeasurementTimeout()
{
    //check if the measurement is complete
    int count = m_measurements[m_currentMeasurement].getCount();

    qDebug()<<"Sweep: "<<m_currentMeasurement<<" has: "<<count<<" elements";

    if (count != 11) { //failed sweep, removing it!
        m_measurements[m_currentMeasurement].cleanSweep();
        qDebug()<<"Erasing sweep";
        return;
    }

    m_measurements->printSweep(); //print sweep in debug mode

    PlotMeasurement();

    //increment index in circular buffer, clean the next sweep object
    m_currentMeasurement++;
    if (m_currentMeasurement == 10)
        m_currentMeasurement = 0;

    m_measurements[m_currentMeasurement].cleanSweep();

    //reenable measurement button
    ui->pushButtonMeas->setEnabled(true);

}

void MainWindow::PlotMeasurement()
{
    //DataPoint aux_point;
    DataTrace aux_trace;

    m_chartMag->clearTable();
    m_chartPha->clearTable();

    for (int i = 0; i < 10; i++) {

        int count = m_measurements[i].getCount();

        if (count) {
            aux_trace = m_measurements[i].getTraceMag();
            m_chartMag->addTrace(aux_trace);

            aux_trace =m_measurements[i].getTracePha();
            m_chartPha->addTrace(aux_trace);
        }

    }
    m_chartMag->updatePlot();
    m_chartPha->updatePlot();

    //update the tables with the
    updateTables();


}

void MainWindow::clearTables()
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 11; j++) {
            QModelIndex index = modelMag->index(i,j,QModelIndex());
            modelMag->setData(index,"");

            index = modelPha->index(i,j,QModelIndex());
            modelMag->setData(index,"");

        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 11; j++) {
            QModelIndex index = modelMagStat->index(i,j,QModelIndex());
            modelMag->setData(index,"");

            index = modelPhaStat->index(i,j,QModelIndex());
            modelMag->setData(index,"");

        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 11; j++) {
            QModelIndex index = modelCal->index(i,j,QModelIndex());
            modelMag->setData(index,"");
        }
    }



}

void MainWindow::updateTables()
{
    DataTrace aux_trace;

    for (int i = 0; i < 10; i++) {

        int count = m_measurements[i].getCount();

        if (count) { //Only valid measurements are appended!
            aux_trace = m_measurements[i].getTraceMag();

            for (int j = 0; j < 11; j++) {
                QModelIndex index = modelMag->index(i,j,QModelIndex());
                modelMag->setData(index,aux_trace[j].first.y());
            }

            aux_trace = m_measurements[i].getTracePha();

            for (int j = 0; j < 11; j++) {
                QModelIndex index = modelPha->index(i,j,QModelIndex());
                modelPha->setData(index,aux_trace[j].first.y());
            }

        }

    }

    updateStatistics();

}

void MainWindow::updateStatistics()
{
    double average[11], rms[11], aux, diff;
    int count;

    //Magnitude
    for (int i = 0; i < 11; i++) {
        average[i] = 0;
        rms[i] = 0;
    }

    //Average Mag
    for (int j = 0; j < 11; j++) {
        for (count = 0; count < 10; count++) {
            QModelIndex indexmag = modelMag->index(count,j,QModelIndex());
            aux = modelMag->data(indexmag).toDouble();
            if (aux == 0) break; //No more valid rows available!

            average[j] += (aux);
        }

        average[j] /= count;
    }

    for (int i=0; i < 11; i++) {
        QModelIndex index = modelMagStat->index(0,i,QModelIndex());
        modelMagStat->setData(index,QString("%1").arg(average[i]));
    }

    //RMS Mag
    for (int j = 0; j < 11; j++) {
        for (count = 0; count < 10; count++) {
            QModelIndex indexmag = modelMag->index(count,j,QModelIndex());
            aux = modelMag->data(indexmag).toDouble();
            if (aux == 0) break; //No more valid rows available!

            diff = aux - average[j];
            rms[j] += diff*diff;
        }

        rms[j] /= count;
        rms[j] = qSqrt(rms[j]);

        //Conversion to %
        rms[j] = rms[j]/average[j]*100.0;
    }

    for (int i=0; i < 11; i++) {
        QModelIndex index = modelMagStat->index(1,i,QModelIndex());
        //modelMagStat->setData(index,rms[i]);
        modelMagStat->setData(index,QString::number(rms[i],'g',4));
    }

    //Phase
    for (int i = 0; i < 11; i++) {
        average[i] = 0;
        rms[i] = 0;
    }

    //Average Phase
    for (int j = 0; j < 11; j++) {
        for (count = 0; count < 10; count++) {
            QModelIndex indexmag = modelPha->index(count,j,QModelIndex());
            aux = modelPha->data(indexmag).toDouble();
            if (aux == 0) break; //No more valid rows available!

            average[j] += (aux);
        }

        average[j] /= count;
    }

    for (int i=0; i < 11; i++) {
        QModelIndex index = modelPhaStat->index(0,i,QModelIndex());
        modelPhaStat->setData(index,QString("%1").arg(average[i]));
    }

    //Phase Error
    for (int j = 0; j < 11; j++) {
        for (count = 0; count < 10; count++) {
            QModelIndex indexmag = modelPha->index(count,j,QModelIndex());
            aux = modelPha->data(indexmag).toDouble();
            if (aux == 0) break; //No more valid rows available!

            diff = aux - average[j];
            rms[j] += diff*diff;
        }

        rms[j] /= count;
        rms[j] = qSqrt(rms[j]);

        //Conversion to %
        //rms[j] = rms[j]/average[j]*100.0;
    }

    for (int i=0; i < 11; i++) {
        QModelIndex index = modelPhaStat->index(1,i,QModelIndex());
        //modelMagStat->setData(index,rms[i]);
        modelPhaStat->setData(index,QString::number(rms[i],'g',4));
    }


}

void MainWindow::setUpTables()
{
    modelMag = new QStandardItemModel(10,11,this);
    modelMagStat = new QStandardItemModel(2,11,this);

    modelPha = new QStandardItemModel(10,11,this);
    modelPhaStat = new QStandardItemModel(2,11,this);

    modelCal = new QStandardItemModel(2,11,this);

    ui->tableViewMag->setModel(modelMag);
    ui->tableViewMagStat->setModel(modelMagStat);

    ui->tableViewPha->setModel(modelPha);
    ui->tableViewPhaStat->setModel(modelPhaStat);

    ui->tableViewCalibration->setModel(modelCal);

    int widthTable = ui->tableViewMag->width()/12;

    for (int i = 0; i < 11; i++) {
        ui->tableViewMag->setColumnWidth(i,widthTable);
        ui->tableViewMagStat->setColumnWidth(i,widthTable);
        ui->tableViewPha->setColumnWidth(i,widthTable);
        ui->tableViewPhaStat->setColumnWidth(i,widthTable);
    }

    widthTable = ui->tableViewCalibration->width()/12;
    for (int i = 0; i < 11; i++)
        ui->tableViewCalibration->setColumnWidth(i,widthTable);

    clearTables();

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
        m_chartViewMag->setRenderHint(QPainter::Antialiasing, true); //false or true
        m_chartViewPha->setRenderHint(QPainter::Antialiasing, true); //false or true
    } else {
        m_chartViewMag->setRenderHint(QPainter::Antialiasing, false); //false or true
        m_chartViewPha->setRenderHint(QPainter::Antialiasing, false); //false or true
    }
}

void MainWindow::on_pushButtonBTdisconnect_clicked()
{
    m_bt->BTdisconnect();
    ui->labelBTstatus->setText("Disconnected");
}

/*
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
*/

void MainWindow::on_pushButtonMeas_clicked()
{
    //Check if the timer is running
    if (m_timerMeas->isActive())
        return;

    ui->lineEditAT->setText("f");
    on_pushButtonATSend_clicked();
    m_timerMeas->start(2000); //sweep must be completed before this timeout!
    m_timearrival.start(); //This is used to determine the measurement total time

    ui->pushButtonMeas->setEnabled(false);

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    /*
    int widthTable = ui->tableViewMag->width()/12;

    for (int i = 0; i < 11; i++) {
        ui->tableViewMag->setColumnWidth(i,widthTable);
        ui->tableViewMagStat->setColumnWidth(i,widthTable);
       // ui->tableViewPha->setColumnWidth(i,widthTable);
       // ui->tableViewPhaStat->setColumnWidth(i,widthTable);
    }*/

}

void MainWindow::on_pushButtonGenerateCalibration_clicked()
{
    //Calibration requires measurement of a 1 kOhm resistor
    for (int i=0; i < 11; i++) {
        QModelIndex index = modelMagStat->index(0,i,QModelIndex());
        //modelMagStat->setData(index,rms[i]);
        //modelMagStat->setData(index,QString::number(rms[i],'g',4));
        m_gainCalFactor[i] = 1.0e3/modelMagStat->data(index).toDouble();

        index = modelPhaStat->index(0,i,QModelIndex());
        m_phaseCalFactor[i] = - modelPhaStat->data(index).toDouble();
    }

    for (int i=0; i < 11; i++) {
        QModelIndex index = modelCal->index(0,i,QModelIndex());
        modelCal->setData(index,QString::number(m_gainCalFactor[i],'g',4));

        index = modelCal->index(1,i,QModelIndex());
        modelCal->setData(index,QString::number(m_phaseCalFactor[i],'g',4));
    }




}


















