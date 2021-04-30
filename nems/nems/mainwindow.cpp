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

    /**** config initialization, WiFi disabled  *****/

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

    /****** Bluetooth *******/

    m_bt = new BTClient(this);
    connect(m_bt, SIGNAL(BTnewDeviceDiscovered(QString)),
            this, SLOT(BTgetDevice(QString)));
    connect(m_bt, SIGNAL(BTnewDeviceConnected(QString)),
            this, SLOT(BTConnected(QString)));
    connect(m_bt, SIGNAL(BTrxData(QByteArray)),
            this, SLOT(BTrxData(const QByteArray)));

    /***** WiFi ****/
    m_WiFiTcpSocket = new QTcpSocket(this);
    m_WiFi_in.setDevice(m_WiFiTcpSocket);
    m_WiFi_in.setVersion(QDataStream::Qt_5_11);
    connect(m_WiFiTcpSocket, SIGNAL(readyRead()),this, SLOT(WiFiRead()));
    connect(m_WiFiTcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
               this, &MainWindow::WiFiDisplayError);

    /***** Plot *****/

    // plot Sensor1
    m_chartSen1 = new CPlotChart();
    m_chartSen1->setType(NORMAL);
    m_chartSen1->setTitles("","Time","Sensor 1");
  //  m_chart->setXMinXax(0,m_MaxDataPlot);
  //  m_chart->setYMinXax(0,1024);
    m_chartSen1->setXMinXax(0,m_MaxDataPlot);
    m_chartSen1->setYMinXax(0,4096);
    m_chartSen1->initializePlot();
    m_chartViewSen1 = new QChartView(static_cast<QChart*>(m_chartSen1));
    //Set antialising properties and the chartview object to a place in layout
    m_chartViewSen1->setRenderHint(QPainter::Antialiasing, false); //false or true
    ui->verticalLayout_3->addWidget(m_chartViewSen1,1,0);

    //plot Sensor2
    m_chartSen2 = new CPlotChart();
    m_chartSen2->setType(NORMAL);
    m_chartSen2->setTitles("","Time","Sensor 2");
    m_chartSen2->setXMinXax(0,m_MaxDataPlot);
    m_chartSen2->setYMinXax(0,4096);
    m_chartSen2->initializePlot();
    m_chartViewSen2 = new QChartView(static_cast<QChart*>(m_chartSen2));
    //Set antialising properties and the chartview object to a place in layout
    m_chartViewSen2->setRenderHint(QPainter::Antialiasing, false); //false or true
    ui->verticalLayout_3->addWidget(m_chartViewSen2,1,0);

    //timer to refresh the plot
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(PlotTimeout()));
    //m_timer->start(m_PlotTimeout);

    //timer to inhibit the sensors during communication
    m_timer_silence = new QTimer(this);
    connect(m_timer_silence, SIGNAL(timeout()), this, SLOT(SilenceTimeout()));

    /******* sensors *******/

    ui->verticalSliderEnergyMax->setRange(0,5); // m_energy_range up to 1000*10^5
    ui->verticalSliderEnergyMax->setValue(0);

    double aux;
    aux = 1000*qPow(10,0);
    m_energy_range = aux;
    m_energy_threshold = aux;

    m_maxEnergy = 0;
    m_maxEnergy2 = 0;

    ui->labelEnergyRange->setText(QString::number((int)aux));

    ui->progressBarEnergy->setRange(0,m_energy_range);
    ui->progressBarEnergy->setValue(0);

    ui->progressBarEnergy2->setRange(0,m_energy_range);
    ui->progressBarEnergy2->setValue(0);

    ui->verticalSliderEnergyThreshold->setRange(0,m_energy_range);
    ui->verticalSliderEnergyThreshold->setValue(m_energy_threshold);
    ui->labelThreshold->setText(QString::number((int)m_energy_threshold));

    ui->progressBarMuscle->setRange(0,1);
    ui->progressBarMuscle->setValue(0);

    ui->labelEnergyMax->setText(QString::number((int)m_maxEnergy));
    ui->labelEnergyMax2->setText(QString::number((int)m_maxEnergy2));

    /****** Search motor points  *****/

    m_search = new NMESsearch(this);
    connect(m_search,SIGNAL(updateSearchText(QString)),this,SLOT(updateSearchText(QString)));
    connect(m_search,SIGNAL(send(QByteArray)),this,SLOT(send(QByteArray)));
    connect(m_search,SIGNAL(CopyResetMaxEnergy()),this,SLOT(on_pushButtonResetMaxEnergy_clicked()));
    connect(m_search,SIGNAL(scanDone()),this,SLOT(SearchDone()));


    //m_numSearchElectrodes = 16;
    //ui->lineEditStopElectrodes->setText(QString::number((int)m_numSearchElectrodes));
    ui->lineEditStopElectrodes->setText("16");
    ui->lineEditAnode->setText("1");
    /***** Automatic search configuration ****/
    m_startAmplitude = 6;
    m_stopAmplitude = 10;
    m_autosearch.setSearch(m_search);


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

    //Check if received data is current program configuration
    parseProgram(data);

    //Process sensor data only if NMES is active or when
    //sensors are not inhibited
    if (!m_timer->isActive())
        return;

    if (m_timer_silence->isActive())
        return;


    //Receive sensor data
     m_data.append(data);

    int size = data.count();
    if (size%2) { //each sample is 2 bytes. There is an incomplete value!
        qDebug()<<"Odd number of bytes received, appending";
        return; //wait for the next rx to complete

    } else if (size < 4) { // at least one sample per channel needs to arrive
        qDebug()<<"Incomplete packet received, appending";
        return; //wait for the next rx to complete

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

/*
    //Single channel
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
  */
    // Dual channel
    int size = data.count()/4; //Each converted value comes in 2 bytes unsigned short.

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
        m_sens1.add_point(value);

        //reconstruct the digital value2
        value = data.at(index++) & 0xff;
        value |= (data.at(index++) << 8) & 0xff00;

        //Create a data point2
        aux_point.first.setX(m_DataCounter);
        aux_point.first.setY(value);
        aux_point.second = QString::number(m_DataCounter);

        //Save the data point for further processing/plotting
        m_trace2.append(aux_point);
        m_sens2.add_point(value);

        m_DataCounter++;
    }
    //The data is plotted using PlotTimeout()

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

    //Uncomment the next lines in order to update the plot with the available data
    head = m_PlotCounter + m_PlotNumUpdate;
    if (head > m_DataCounter) {
            head = m_DataCounter;
    }
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
            m_plot_trace2.clear();
        } else {
            aux_point = m_trace.at(i);
            aux_point.first.setX(plot_index);
            m_plot_trace.append(aux_point);

            aux_point = m_trace2.at(i);
            aux_point.first.setX(plot_index);
            m_plot_trace2.append(aux_point);
        }
        m_PlotCounter++;
    }

    //replot the trace
    if(m_plot_trace.count()) {
        m_chartSen1->clearTable();
        m_chartSen1->addTrace(m_plot_trace);
        m_chartSen1->updatePlot();

        m_chartSen2->clearTable();
        m_chartSen2->addTrace(m_plot_trace2);
        m_chartSen2->updatePlot();
    }

    //Check if number of samples are exceeded
    if (m_trace.count() >= m_MaxNumSamples) {
        m_trace.clear();
        m_trace2.clear();
        m_DataCounter = 0;
        m_plot_trace.clear();
        m_plot_trace2.clear();
        m_PlotCounter = 0;
    }

    //Update sensor data
    UpdateSensorData();
}

void MainWindow::SilenceTimeout()
{
    m_timer_silence->stop();
}

void MainWindow::UpdateSensorData()
{

    // Get the energy data from the sensors

    double energy1 = m_sens1.getEnergy();
    QString text;
    text = QString::number((int)energy1) + "\n" +
           QString::number((int)(10*qLn(energy1)/qLn(10))) +
           " dB";

    double energy2 = m_sens2.getEnergy();
    QString text2;
    text2 = QString::number((int)energy2) + "\n" +
           QString::number((int)(10*qLn(energy2)/qLn(10))) +
           " dB";

    // Update the Energy text fields

    ui->labelEnergyValue->setText(text);
    ui->labelEnergyValue2->setText(text2);

    // Update the progress bars

    if (energy1 > m_energy_range) {
        ui->progressBarEnergy->setValue(m_energy_range);
    } else {
        ui->progressBarEnergy->setValue((int)energy1);
    }

    if (energy2 > m_energy_range) {
        ui->progressBarEnergy2->setValue(m_energy_range);
    } else {
        ui->progressBarEnergy2->setValue((int)energy2);
    }

    // Sensor fussion and updating of the muscle movement bar
    double energy_tot;

    energy_tot = qSqrt((energy1*energy1) + (energy2*energy2));

    if (energy_tot > m_energy_threshold) {
        ui->progressBarMuscle->setValue(1);
    } else {
        ui->progressBarMuscle->setValue(0);
    }

    // Update max energy

    if (energy1 > m_maxEnergy) {
        m_maxEnergy = energy1;

        double aux;
        QString endB;
        if (m_maxEnergy > 0) {
            aux = 10*qLn(m_maxEnergy)/qLn(10);
            endB = QString::number((int)aux) + " dB";
        } else {
            endB = "- dB";
        }

        QString text = QString::number((int)m_maxEnergy) + "\n" + endB;

        ui->labelEnergyMax->setText(text);
    }

    if (energy2 > m_maxEnergy2) {
        m_maxEnergy2 = energy2;

        double aux2;
        QString endB2;
        if (m_maxEnergy2 > 0) {
            aux2 = 10*qLn(m_maxEnergy2)/qLn(10);
            endB2 = QString::number((int)aux2) + " dB";
        } else {
            endB2 = "- dB";
        }

        QString text2 = QString::number((int)m_maxEnergy2) + "\n" + endB2;

        ui->labelEnergyMax2->setText(text2);
    }

}

void MainWindow::SearchDone()
{
    channel aux;
    aux = m_search->getMotorPoint();

    QString motorPoint;

    motorPoint = "Motor point: " + QString::number(aux.ch1) +
                 "," + QString::number(aux.ch2);

    ui->label_motorpoint->setText(motorPoint);

    ui->plainTextEditSearch->appendPlainText(motorPoint);
    m_motorPoint = aux;

    int search_done =  m_autosearch.addMotorPoint(&m_motorPoint);

    if (search_done == 1) {
        //Motor point found
        ui->plainTextEditSearch->appendPlainText("Motor point found, search stopped");
    }

    if (search_done == 2) {
        //Search finished without motor point
        ui->plainTextEditSearch->appendPlainText("Search finished, no motor point found");
    }

    if (search_done == 3) {
        //Search finished without motor point
        ui->plainTextEditSearch->appendPlainText("Search cancelled");
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

    m_timer_silence->start(150);
}

void MainWindow::parseProgram(const QByteArray &data)
{
    QString dataStr;
    QStringList dataLst;
    QStringList parameterLst;
    QString aux;
    QString parameter;

    dataStr = QString::fromStdString(data.toStdString());

    dataLst = dataStr.split(QRegExp("\n"));

    int n = dataLst.count();

    // check that message is program configuration
    if (n != 17) {
        return;
    }

    aux = dataLst.at(1);
    if (aux.compare("NEMS program")) {
            return;
    }

    // extract program data

    //Amplitude1
    aux = dataLst.at(2);
    parameterLst = aux.split(QRegExp(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditAmplitude->setText(parameter);

    //Amplitude2
    aux = dataLst.at(3);
    parameterLst = aux.split(QRegExp(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditAmplitude2->setText(parameter);

    //Frequency
    aux = dataLst.at(4);
    parameterLst = aux.split(QRegExp(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditFrequency->setText(parameter);

    //Phase Duration
    aux = dataLst.at(5);
    parameterLst = aux.split(QRegExp(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditPhase->setText(parameter);

    //Symmetry Factor
    aux = dataLst.at(6);
    parameterLst = aux.split(QRegExp(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditSymetry->setText(parameter);

    //ON Time
    aux = dataLst.at(7);
    parameterLst = aux.split(QRegExp(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditON->setText(parameter);

    //OFF Time
    aux = dataLst.at(8);
    parameterLst = aux.split(QRegExp(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditOFF->setText(parameter);

    //Ramp up
    aux = dataLst.at(9);
    parameterLst = aux.split(QRegExp(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditRampUp->setText(parameter);

    //Ramp down
    aux = dataLst.at(10);
    parameterLst = aux.split(QRegExp(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditRampDown->setText(parameter);

    //Contractions
    aux = dataLst.at(11);
    parameterLst = aux.split(QRegExp(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditContractions->setText(parameter);

    //channel1
    aux = dataLst.at(12);
    parameterLst = aux.split(QRegExp(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditChannel1->setText(parameter);

    //channel2
    aux = dataLst.at(13);
    parameterLst = aux.split(QRegExp(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditChannel2->setText(parameter);

    //channel3
    aux = dataLst.at(14);
    parameterLst = aux.split(QRegExp(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditChannel3->setText(parameter);

    //channel4
    aux = dataLst.at(15);
    parameterLst = aux.split(QRegExp(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditChannel4->setText(parameter);

}

void MainWindow::updateSearchText(QString text)
{
    ui->plainTextEditSearch->appendPlainText(text);

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
        m_chartViewSen1->setRenderHint(QPainter::Antialiasing, true); //false or true
        m_chartViewSen2->setRenderHint(QPainter::Antialiasing, true); //false or true
    } else {
        m_chartViewSen1->setRenderHint(QPainter::Antialiasing, false); //false or true
        m_chartViewSen2->setRenderHint(QPainter::Antialiasing, false); //false or true
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

    //m_timer->start(m_PlotTimeout);
    ui->action_Run->setEnabled(false);
}

void MainWindow::on_action_Clean_triggered()
{
    /*QMessageBox msgBox;
    msgBox.setText("Clean Measurements");
    msgBox.setInformativeText("Do you want to delete all the measurements?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if (ret == QMessageBox::No) return;
*/
    ui->plainTextEditAT->clear();
    ui->plainTextEditSearch->clear();
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

    //m_timer->stop();
    ui->action_Run->setEnabled(true);

 //
        m_search->stopScan();
     if (m_search->isActive()) {
        updateSearchText("Search stopped");
    }

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

void MainWindow::on_pushButtonChannel3_clicked()
{
    QString aux = ui->lineEditChannel3->text();

    QByteArray data;

    data.append('Q');
    if (aux.size()==1) {
        data.append('0');
    }
    data.append(aux);

    send(data);
}

void MainWindow::on_pushButtonChannel4_clicked()
{
    QString aux = ui->lineEditChannel4->text();

    QByteArray data;

    data.append('q');
    if (aux.size()==1) {
        data.append('0');
    }
    data.append(aux);

    send(data);
}

void MainWindow::on_pushButtonAmplitude2_clicked()
{
    QString aux = ui->lineEditAmplitude2->text();

    QByteArray data;

    data.append('A');
    if (aux.size()==1) {
        data.append('0');
    }
    data.append(aux);

    send(data);
}

void MainWindow::on_actionSensors_triggered(bool checked)
{
    QByteArray data;

    if (!checked) {
        data.append("B"); // stop sensors
        m_timer->stop();
    } else {
        data.append("b"); // start sensors
        if(!m_timer->isActive()) {
             m_timer->start(m_PlotTimeout);
        }
    }

    send(data);
}

void MainWindow::on_verticalSliderEnergyMax_valueChanged(int value)
{
    double aux;
    aux = 1000*qPow(10,value);
    m_energy_range = aux;

    //m_energy_range = value;
    ui->progressBarEnergy->setRange(0,m_energy_range);
    ui->progressBarEnergy2->setRange(0,m_energy_range);
    ui->verticalSliderEnergyThreshold->setRange(0,m_energy_range);

    QString text;
    text = QString::number((int)m_energy_range) +
           " " +
           QString::number((int)qCeil(10*qLn(m_energy_range)/qLn(10))) +
            "dB";

    //ui->labelEnergyRange->setText(QString::number((int)m_energy_range));
    ui->labelEnergyRange->setText(text);

}

void MainWindow::on_verticalSliderEnergyThreshold_valueChanged(int value)
{
    m_energy_threshold = value;

    QString text;
    text = QString::number((int)m_energy_threshold) +
           " " +
           QString::number((int)qCeil(10*qLn(m_energy_threshold)/qLn(10))) +
            "dB";

    //ui->labelThreshold->setText(QString::number((int)value));
    ui->labelThreshold->setText(text);
}

void MainWindow::on_pushButtonResetMaxEnergy_clicked()
{
    m_search->updateMaxEnergy(m_maxEnergy, m_maxEnergy2);

    m_maxEnergy = 0;
    ui->labelEnergyMax->setText(QString::number((int)m_maxEnergy));

    m_maxEnergy2 = 0;
    ui->labelEnergyMax2->setText(QString::number((int)m_maxEnergy2));
}

void MainWindow::on_actionSearch_triggered()
{
    //Ceck if BT is connected
    if (ui->labelBTstatus->text() != "Connected")
        return;

    QString stop_electrode;
    stop_electrode = ui->lineEditStopElectrodes->text();

    QString amplitude;
    amplitude = ui->lineEditAmplitude->text();

    QString anode;
    anode = ui->lineEditAnode->text();

    //m_search->scan(num_electrodes.toInt(),amplitude.toInt());
    m_autosearch.start(m_startAmplitude,m_stopAmplitude, anode.toInt(),stop_electrode.toInt());
}

void MainWindow::on_pushButtonUpdateCh1MotorPoint_clicked()
{
    ui->lineEditChannel1->setText(QString::number(m_motorPoint.ch1));
    ui->lineEditChannel2->setText(QString::number(m_motorPoint.ch2));

    m_search->m_go = 0;
    m_search->m_ch1 = m_motorPoint.ch1;
    m_search->m_ch2 = m_motorPoint.ch2;
    m_search->programNEMSbin();
}
