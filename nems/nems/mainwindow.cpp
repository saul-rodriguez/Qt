#include "mainwindow.h"
#include "QtCore5Compat/qregexp.h"
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

    /**** Toolbar ******/
   ui->mainToolBar->setIconSize(QSize(100, 100));


  // ui->mainToolBar->setFixedHeight(50);

    /**** config initialization, WiFi disabled  *****/

    ui->pushButtonBTconnect->setEnabled(true);
    ui->pushButtonBTdiscoverDevices->setEnabled(true);
    ui->pushButtonBTdisconnect->setEnabled(true);
    ui->pushButtonBLEdiscover->setEnabled(false);
    ui->pushButtonBLEconnect->setEnabled(false);
    ui->pushButtonBLEdisconnect->setEnabled(false);


    /**** Config plot ****/
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
   // m_WiFiTcpSocket = new QTcpSocket(this);
   // m_WiFi_in.setDevice(m_WiFiTcpSocket);
   // m_WiFi_in.setVersion(QDataStream::Qt_5_11);
   // connect(m_WiFiTcpSocket, SIGNAL(readyRead()),this, SLOT(WiFiRead()));
   // connect(m_WiFiTcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
   //            this, &MainWindow::WiFiDisplayError);

    m_ble = new BLEClient(this);
    connect(m_ble, &BLEClient::deviceFound, this, &MainWindow::deviceFound);
    connect(m_ble, &BLEClient::rxData, this, &MainWindow::rxData);
    connect(m_ble, &BLEClient::BLEupdateStatus, this, &MainWindow::updateBLEstatus);

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
    //ui->verticalLayout_3->addWidget(m_chartViewSen1,1,0);
    ui->verticalLayout_3->addWidget(m_chartViewSen1,1);

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
    //ui->verticalLayout_3->addWidget(m_chartViewSen2,1,0);
    ui->verticalLayout_3->addWidget(m_chartViewSen2,1);

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

    /******* Mapping Pins ******/
    m_pinmap = new NMESPinMap();
    m_pinmap->loadMapping();

    /****** Search motor points  *****/

    m_search = new NMESsearch(this);
    connect(m_search,SIGNAL(updateSearchText(QString)),this,SLOT(updateSearchText(QString)));
    connect(m_search,SIGNAL(send(QByteArray)),this,SLOT(send(QByteArray)));
    connect(m_search,SIGNAL(CopyResetMaxEnergy()),this,SLOT(on_pushButtonResetMaxEnergy_clicked()));
    connect(m_search,SIGNAL(scanDone()),this,SLOT(SearchDone()));
    m_search->setAlgorithm(REFERENCE_ALG);
    m_search->setMappingPins(m_pinmap);

    //m_numSearchElectrodes = 16;
    //ui->lineEditStopElectrodes->setText(QString::number((int)m_numSearchElectrodes));
    ui->lineEditStartElectrodes->setText("2");
    ui->lineEditStopElectrodes->setText("16");
    ui->lineEditAnode->setText("1");
    /***** Automatic search configuration ****/
    m_startAmplitude = 6;
    m_stopAmplitude = 10;
    ui->lineEditSearchStartCurrent->setText(QString::number(m_startAmplitude));
    ui->lineEditSearchStopCurrent->setText(QString::number(m_stopAmplitude));
    m_autosearch.setSearch(m_search);
    ui->checkBoxAuto->setChecked(true);
    ui->lineEditPeriod->setText("2500");

    /**** Dual Motor Point Stimulation *****/
    ui->lineEditDualStim1_1->setText("0");
    ui->lineEditDualStim1_2->setText("0");
    ui->lineEditDualStim2_1->setText("0");
    ui->lineEditDualStim2_2->setText("0");
    ui->lineEditDelay->setText("0");
    ui->lineEditDualAmp1->setText("0");
    ui->lineEditDualAmp2->setText("0");

    m_dualMPstim = new NMESDualMP(this);
    connect(m_dualMPstim,SIGNAL(send(QByteArray)),this,SLOT(send(QByteArray)));
    //m_timer_dualStim = new QTimer(this);
    //m_timer_dualStim->setSingleShot(true);
    //connect(m_timer_dualStim, SIGNAL(timeout()), this, SLOT(DualStimulationTimeout()));
    m_dualMPstim->setPinMap(m_pinmap);

    /* display version in AT */
    ui->plainTextEditAT->appendPlainText(windowTitle());

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

/*
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
*/

/*
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
*/


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

/*
void MainWindow::DualStimulationTimeout()
{
    unsigned char amp2, ch1, ch2, go;

    QString aux;

    // Get Motor point 1 parameters
    aux = ui->lineEditDualAmp2->text();
    amp2 = aux.toInt();
    aux = ui->lineEditDualStim2_1->text();
    ch1 = aux.toInt();
    aux = ui->lineEditDualStim2_2->text();
    ch2 = aux.toInt();
    go = 1;





}
*/

void MainWindow::send(QByteArray data)
{
    if (ui->radioButtonBT->isChecked()) {
        m_bt->BTwrite(data);
    } else {    //The communication with the ESP-01 module is always terminated by cr + nl
       // data.append('\r');
       // data.append('\n');
       // m_WiFiTcpSocket->write(data);
        m_ble->write(data);
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

    m_program.append(data);


    //dataStr = QString::fromStdString(data.toStdString());
    dataStr = QString::fromStdString(m_program.toStdString());

    //TODO
    dataLst = dataStr.split(QRegularExpression("\n"));

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
    m_program.clear();

    //Amplitude1
    aux = dataLst.at(2);
    parameterLst = aux.split(QRegularExpression(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditAmplitude->setText(parameter);

    //Amplitude2
    aux = dataLst.at(3);
    parameterLst = aux.split(QRegularExpression(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditAmplitude2->setText(parameter);

    //Frequency
    aux = dataLst.at(4);
    parameterLst = aux.split(QRegularExpression(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditFrequency->setText(parameter);

    //Phase Duration
    aux = dataLst.at(5);
    parameterLst = aux.split(QRegularExpression(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditPhase->setText(parameter);

    //Symmetry Factor
    aux = dataLst.at(6);
    parameterLst = aux.split(QRegularExpression(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditSymetry->setText(parameter);

    //ON Time
    aux = dataLst.at(7);
    parameterLst = aux.split(QRegularExpression(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditON->setText(parameter);

    //OFF Time
    aux = dataLst.at(8);
    parameterLst = aux.split(QRegularExpression(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditOFF->setText(parameter);

    //Ramp up
    aux = dataLst.at(9);
    parameterLst = aux.split(QRegularExpression(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditRampUp->setText(parameter);

    //Ramp down
    aux = dataLst.at(10);
    parameterLst = aux.split(QRegularExpression(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditRampDown->setText(parameter);

    //Contractions
    aux = dataLst.at(11);
    parameterLst = aux.split(QRegularExpression(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    ui->lineEditContractions->setText(parameter);

    //TODO: Need to remap pins!
    QString pmap;

    //channel1
    aux = dataLst.at(12);
    parameterLst = aux.split(QRegularExpression(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    pmap = m_pinmap->getIndString(parameter);
    ui->lineEditChannel1->setText(pmap);

    //channel2
    aux = dataLst.at(13);
    parameterLst = aux.split(QRegularExpression(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    pmap = m_pinmap->getIndString(parameter);
    ui->lineEditChannel2->setText(pmap);

    //channel3
    aux = dataLst.at(14);
    parameterLst = aux.split(QRegularExpression(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    pmap = m_pinmap->getIndString(parameter);
    ui->lineEditChannel3->setText(pmap);

    //channel4
    aux = dataLst.at(15);
    parameterLst = aux.split(QRegularExpression(" "));
    n = parameterLst.count();
    parameter = parameterLst.at(n-1);
    pmap = m_pinmap->getIndString(parameter);
    ui->lineEditChannel4->setText(pmap);

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
    data.append(aux.toUtf8());


    if (ui->radioButtonBT->isChecked()) {
        m_bt->BTwrite(data);
    } else {    //The communication with the ESP-01 module is always terminated by cr + nl
       // data.append('\r');
       // data.append('\n');
       // m_WiFiTcpSocket->write(data);
        m_ble->write(data);
    }

}

void MainWindow::on_radioButtonWiFi_toggled(bool checked)
{
    if (checked) {
        ui->pushButtonBTconnect->setEnabled(false);
        ui->pushButtonBTdiscoverDevices->setEnabled(false);
        ui->pushButtonBTdisconnect->setEnabled(false);
        ui->pushButtonBLEdiscover->setEnabled(true);
        ui->pushButtonBLEconnect->setEnabled(true);
        ui->pushButtonBLEdisconnect->setEnabled(true);
        //ui->lineEditWiFiAddress->setEnabled(true);
        //ui->lineEditWiFiPort->setEnabled(true);
    }
}

void MainWindow::on_radioButtonBT_toggled(bool checked)
{
    if (checked) {
        ui->pushButtonBTconnect->setEnabled(true);
        ui->pushButtonBTdiscoverDevices->setEnabled(true);
        ui->pushButtonBTdisconnect->setEnabled(true);
        ui->pushButtonBLEdiscover->setEnabled(false);
        ui->pushButtonBLEconnect->setEnabled(false);
        ui->pushButtonBLEdisconnect->setEnabled(false);
        //ui->lineEditWiFiAddress->setEnabled(false);
        //ui->lineEditWiFiPort->setEnabled(false);
    }
}

/*
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
*/

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
    if (ui->labelBTstatus->text() != "Connected" && ui->labelBLEStatus->text() != "Connected")
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
    QByteArray data;
    QString aux = ui->lineEditAmplitude->text();

    int amp = aux.toInt();

    data.append('a');

    if (amp <= 99) { //Saul's board
        if (aux.size()==1) {
            data.append('0');
        }
        data.append(aux.toUtf8());

    } else { // Svekon's board
        quint8 amp_svekon = amp;
        data.append('B');
        data.append(amp_svekon);
    }

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
    data.append(aux.toUtf8());

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
    data.append(aux.toUtf8());

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
    data.append(aux.toUtf8());

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
    data.append(aux.toUtf8());

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
    data.append(aux.toUtf8());

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
    data.append(aux.toUtf8());

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
    data.append(aux.toUtf8());

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
    data.append(aux.toUtf8());

    send(data);
}

void MainWindow::on_pushButtonChannel1_clicked()
{
    QString aux = ui->lineEditChannel1->text();

    QString auxm = m_pinmap->getPinString(aux);

    QByteArray data;

    data.append('M');
    if (auxm.size()==1) {
        data.append('0');
    }
    data.append(auxm.toUtf8());

    send(data);
}

void MainWindow::on_pushButtonChannel2_clicked()
{
    QString aux = ui->lineEditChannel2->text();

    QString auxm = m_pinmap->getPinString(aux);

    QByteArray data;

    data.append('m');
    if (auxm.size()==1) {
        data.append('0');
    }
    data.append(auxm.toUtf8());

    send(data);
}

void MainWindow::on_actionStop_triggered()
{
    //Ceck if BT is connected    
    if (ui->labelBTstatus->text() != "Connected" && ui->labelBLEStatus->text() != "Connected")
        return;

    QByteArray data;
    data.append('N');
    send(data);

    //m_timer->stop();
    ui->action_Run->setEnabled(true);

    if (m_search->isActive()) {
       on_actionStop_Search_triggered();
    }
 //
    /*
        m_search->stopScan();
     if (m_search->isActive()) {
        updateSearchText("Search stopped");
    }
    */


}

void MainWindow::on_action_Open_triggered()
{
    //Check if BT is connected
    if (ui->labelBTstatus->text() != "Connected" && ui->labelBLEStatus->text() != "Connected")
        return;

    QByteArray data;
    data.append('l');
    send(data);
}

void MainWindow::on_action_Display_program_triggered()
{
    //Check if BT is connected
    if (ui->labelBTstatus->text() != "Connected" && ui->labelBLEStatus->text() != "Connected")
        return;

    m_program.clear();

    QByteArray data;
    data.append('p');
    send(data);
}

void MainWindow::on_pushButtonChannel3_clicked()
{
    QString aux = ui->lineEditChannel3->text();

    QString auxm = m_pinmap->getPinString(aux);

    QByteArray data;

    data.append('Q');
    if (auxm.size()==1) {
        data.append('0');
    }
    data.append(auxm.toUtf8());

    send(data);
}

void MainWindow::on_pushButtonChannel4_clicked()
{
    QString aux = ui->lineEditChannel4->text();

    QString auxm = m_pinmap->getPinString(aux);

    QByteArray data;

    data.append('q');
    if (auxm.size()==1) {
        data.append('0');
    }
    data.append(auxm.toUtf8());

    send(data);
}

void MainWindow::on_pushButtonAmplitude2_clicked()
{
    QByteArray data;
    QString aux = ui->lineEditAmplitude2->text();

    int amp = aux.toInt();

    data.append('A');

    if (amp <= 99) { //Saul's board
        if (aux.size()==1) {
            data.append('0');
        }
        data.append(aux.toUtf8());

    } else { // Svekon's board
        quint8 amp_svekon = amp;
        data.append('B');
        data.append(amp_svekon);
    }

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
    bool dv1 = m_sens1.getDataValid();
    bool dv2 = m_sens2.getDataValid();

    m_search->updateDataValid(dv1,dv2);

    m_sens1.clear_datavalid();
    m_sens2.clear_datavalid();

    m_maxEnergy = 0;
    ui->labelEnergyMax->setText(QString::number((int)m_maxEnergy));

    m_maxEnergy2 = 0;
    ui->labelEnergyMax2->setText(QString::number((int)m_maxEnergy2));
}

void MainWindow::on_actionSearch_triggered()
{
    //Ceck if BT is connected
    if (ui->labelBTstatus->text() != "Connected" && ui->labelBLEStatus->text() != "Connected")
        return;

    QString start_electrode;
    start_electrode = ui->lineEditStartElectrodes->text();

    QString stop_electrode;
    stop_electrode = ui->lineEditStopElectrodes->text();

    QString amplitude;
    amplitude = ui->lineEditAmplitude->text();

    QString anode;
    anode = ui->lineEditAnode->text();

    int SuperElec = ui->checkBoxSuperElectrode->isChecked();

    //m_search->scan(num_electrodes.toInt(),amplitude.toInt());
    m_startAmplitude = ui->lineEditSearchStartCurrent->text().toInt();
    m_stopAmplitude = ui->lineEditSearchStopCurrent->text().toInt();

    bool autosearch = ui->checkBoxAuto->isChecked();

    int period = ui->lineEditPeriod->text().toInt();

    if (ui->AlgorithmRefradioButton->isChecked()) {
        m_search->setAlgorithm(REFERENCE_ALG);
    } else {
        m_search->setAlgorithm(PERMUTATION_ALG);
    }

    m_autosearch.start(m_startAmplitude,
                       m_stopAmplitude,
                       anode.toInt(),
                       stop_electrode.toInt(),
                       start_electrode.toInt(),
                       SuperElec,
                       autosearch,
                       period);

    on_pushButtonResetMaxEnergy_clicked();
}

void MainWindow::on_pushButtonUpdateCh1MotorPoint_clicked()
{
    /*
    ui->lineEditChannel1->setText(QString::number(m_motorPoint.ch1));
    ui->lineEditChannel2->setText(QString::number(m_motorPoint.ch2));

    m_search->m_go = 0;
    m_search->m_ch1 = m_motorPoint.ch1;
    m_search->m_ch2 = m_motorPoint.ch2;
    m_search->programNEMSbin();
    */

    // Send motor points to dual stimulation tab
    ui->lineEditDualStim1_1->setText(QString::number(m_motorPoint.ch1));
    ui->lineEditDualStim1_2->setText(QString::number(m_motorPoint.ch2));

}

void MainWindow::on_pushButtonStartDualStim_clicked()
{

    // Get Motor point parameters
    dual_motorPoint mp_config;
    QString aux;

    aux = ui->lineEditDualAmp1->text();
    mp_config.amp1 = aux.toInt();

    aux = ui->lineEditDualAmp2->text();
    mp_config.amp2 = aux.toInt();

    aux = ui->lineEditDualStim1_1->text();
    mp_config.ch1_1 = aux.toInt();

    aux = ui->lineEditDualStim1_2->text();
    mp_config.ch1_2 = aux.toInt();

    aux = ui->lineEditDualStim2_1->text();
    mp_config.ch2_1 = aux.toInt();

    aux = ui->lineEditDualStim2_2->text();
    mp_config.ch2_2 = aux.toInt();

    aux = ui->lineEditDelay->text();
    mp_config.delay = aux.toInt(); //ms

    aux = ui->lineEditON->text(); // sec
    mp_config.ON = aux.toInt()*1000;

    aux = ui->lineEditRampUp->text(); // ds
    mp_config.rampUp = aux.toInt()*100;

    aux = ui->lineEditRampDown->text(); // ds
    mp_config.rampDown = aux.toInt()*100;

    m_dualMPstim->start(&mp_config);




}

void MainWindow::on_pushButtonUpdateCh2MotorPoint_clicked()
{
    ui->lineEditDualStim2_1->setText(QString::number(m_motorPoint.ch1));
    ui->lineEditDualStim2_2->setText(QString::number(m_motorPoint.ch2));
}

void MainWindow::on_actionStop_Search_triggered()
{

    if (m_search->isActive()) {
       updateSearchText("Search stopped");
    }

    m_search->stopScan();


}

void MainWindow::on_actionShow_pin_map_triggered()
{
    ui->plainTextEditAT->appendPlainText("Logic Physical");
    QString aux;
    int pin;
    for (int i = 0; i < 33; i++) {
        aux = QString::number(i);
        aux += "  ";
        pin = m_pinmap->getPin(i);
        aux += QString::number(pin);
        ui->plainTextEditAT->appendPlainText(aux);

    }
}

void MainWindow::deviceFound(QString device)
{
    ui->comboBoxBLEdevices->addItem(device);
}

void MainWindow::rxData(const QByteArray &data)
{
    QString aux;
    aux = QString::fromStdString(data.toStdString());
    //ui->labelBLEStatus->setText(aux);
    qDebug()<< aux;
    BTrxData(data);
}

void MainWindow::updateBLEstatus(QString &status)
{
    ui->labelBLEStatus->setText(status);
}


void MainWindow::on_pushButtonBLEdiscover_clicked()
{
    ui->comboBoxBLEdevices->clear();
    m_ble->discover();
}


void MainWindow::on_pushButtonBLEconnect_clicked()
{
    int index = ui->comboBoxBLEdevices->currentIndex();
    m_ble->BLEconnect(index);
}


void MainWindow::on_pushButtonBLEdisconnect_clicked()
{
    m_ble->BLEdisconnect();
}

