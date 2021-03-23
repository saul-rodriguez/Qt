#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts/QChartView>

#include <QFileDialog>
#include <QMessageBox>
#include <QXmlStreamWriter>
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
    m_chartMag->setType(NORMAL);
    m_chartMag->setTitles("","Time","Sensor 1");
  //  m_chart->setXMinXax(0,m_MaxDataPlot);
  //  m_chart->setYMinXax(0,1024);
    m_chartMag->setXMinXax(0,1000);
    m_chartMag->setYMinXax(0,1024);
    m_chartMag->initializePlot();
    m_chartViewMag = new QChartView(static_cast<QChart*>(m_chartMag));
    //Set antialising properties and the chartview object to a place in layout
    m_chartViewMag->setRenderHint(QPainter::Antialiasing, false); //false or true
    ui->verticalLayout_3->addWidget(m_chartViewMag,1,0);

    //plot Phase
    m_chartPha = new CPlotChart();
    m_chartPha->setType(NORMAL);
    m_chartPha->setTitles("","Time","Sensor 2");
    m_chartPha->setXMinXax(0,1000);
    m_chartPha->setYMinXax(0,1024);
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
    //Update AT
    ui->plainTextEditAT->appendPlainText(QString::fromStdString(data.toStdString()));

    int num_lines = ui->plainTextEditAT->document()->blockCount();

    if (num_lines == 200) {
        ui->plainTextEditAT->clear();
    }

    /*
    //Update PA label
    QString aux;
    aux = "Answer: " + QString::fromStdString(data.toStdString());
    ui->label_PA_Config->setText(aux);

    m_data.append(data);
    int size = m_data.count();

    int res_packet = size%7; //sweep packets are 7 bytes

    if(!res_packet) {
        parseRxSweepData();

    } else if (res_packet == 1 && size < 15) { //Filter echo (only relevant for implantable reader!)
        const char* aux = m_data.constData();
        if (aux[0] == 'f' && aux[1] == 'f') {
            qDebug()<<"Filtering echo";
            m_data.remove(0,1);
            parseRxSweepData();
        }
    } else {
        qDebug()<<"Size: "<< size << " Packet incomplete";
        return;
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
    head = 0;

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
/*
    if (ui->checkBoxConfigSmoothPlot->isChecked()) { //Only add M_PlotNumUpdate samples to the plot
        head = m_PlotCounter + m_PlotNumUpdate;
        if (head > m_DataCounter) {
                head = m_DataCounter;
        }
    } else {    //Add all new samples to the plot
        head = m_DataCounter;
    }
*/
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

void MainWindow::send(QByteArray data)
{
    if (ui->radioButtonBT->isChecked()) {
        m_bt->BTwrite(data);
    } else {    //The communication with the ESP-01 module is always terminated by cr + nl
        data.append('\r');
        data.append('\n');
        m_WiFiTcpSocket->write(data);
    }

}



void MainWindow::on_pushButtonBTdiscoverDevices_clicked()
{
    ui->comboBoxBTdevices->clear();
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

void MainWindow::on_action_Run_triggered()
{
    //Ceck if BT is connected
    if (ui->labelBTstatus->text() != "Connected")
        return;

    QByteArray data;
    data.append('n');
    send(data);
}

void MainWindow::on_action_Clean_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Clean Measurements");
    msgBox.setInformativeText("Do you want to delete all the measurements?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if (ret == QMessageBox::No) return;

}

void MainWindow::on_action_Delete_sweep_triggered()
{
  /*  m_measurements[m_currentMeasurement].cleanSweep();

    PlotMeasurement();*/
}

void MainWindow::on_action_Save_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Save Program in EEPROM");
    msgBox.setInformativeText("Press Yes to save program");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if (ret == QMessageBox::No) return;

    QByteArray data;
    data.append('s');
    send(data);


}


void MainWindow::on_pushButtonAmplitude_clicked()
{
    QString aux = ui->lineEditAmplitude->text();

    QByteArray data;

    data.append('a');
    if (aux.size()==1) {
        data.append('0');
    }
    data.append(aux);

    send(data);



}

void MainWindow::on_pushButtonFrequency_clicked()
{
    QString aux = ui->lineEditFrequency->text();

    QByteArray data;

    data.append('f');
    if (aux.size()==1) {
        data.append('0');
    }
    data.append(aux);

    send(data);
}

void MainWindow::on_pushButtonPhase_clicked()
{
    QString aux = ui->lineEditPhase->text();

    QByteArray data;

    data.append('d');
    if (aux.size()==1) {
        data.append('0');
    }
    data.append(aux);

    send(data);
}

void MainWindow::on_pushButtonSymetry_clicked()
{
    QString aux = ui->lineEditSymetry->text();

    QByteArray data;

    data.append('k');
    if (aux.size()==1) {
        data.append('0');
    }
    data.append(aux);

    send(data);
}

void MainWindow::on_pushButtonOnTime_clicked()
{
    QString aux = ui->lineEditON->text();

    QByteArray data;

    data.append('o');
    if (aux.size()==1) {
        data.append('0');
    }
    data.append(aux);

    send(data);
}

void MainWindow::on_pushButtonOFF_clicked()
{
    QString aux = ui->lineEditOFF->text();

    QByteArray data;

    data.append('O');
    if (aux.size()==1) {
        data.append('0');
    }
    data.append(aux);

    send(data);
}

void MainWindow::on_pushButtonRampUp_clicked()
{
    QString aux = ui->lineEditRampUp->text();

    QByteArray data;

    data.append('r');
    if (aux.size()==1) {
        data.append('0');
    }
    data.append(aux);

    send(data);
}

void MainWindow::on_pushButtonRampDown_clicked()
{
    QString aux = ui->lineEditRampDown->text();

    QByteArray data;

    data.append('R');
    if (aux.size()==1) {
        data.append('0');
    }
    data.append(aux);

    send(data);
}

void MainWindow::on_pushButtonContractions_clicked()
{
    QString aux = ui->lineEditContractions->text();

    QByteArray data;

    data.append('c');
    if (aux.size()==1) {
        data.append('0');
    }
    data.append(aux);

    send(data);
}

void MainWindow::on_pushButtonChannel1_clicked()
{
    QString aux = ui->lineEditChannel1->text();

    QByteArray data;

    data.append('M');
    if (aux.size()==1) {
        data.append('0');
    }
    data.append(aux);

    send(data);
}

void MainWindow::on_pushButtonChannel2_clicked()
{
    QString aux = ui->lineEditChannel2->text();

    QByteArray data;

    data.append('m');
    if (aux.size()==1) {
        data.append('0');
    }
    data.append(aux);

    send(data);
}

void MainWindow::on_actionStop_triggered()
{
    //Ceck if BT is connected
    if (ui->labelBTstatus->text() != "Connected")
        return;

    QByteArray data;
    data.append('N');
    send(data);



}

void MainWindow::on_action_Open_triggered()
{
    //Ceck if BT is connected
    if (ui->labelBTstatus->text() != "Connected")
        return;

    QByteArray data;
    data.append('l');
    send(data);
}

void MainWindow::on_action_Display_program_triggered()
{
    //Ceck if BT is connected
    if (ui->labelBTstatus->text() != "Connected")
        return;

    QByteArray data;
    data.append('p');
    send(data);
}
