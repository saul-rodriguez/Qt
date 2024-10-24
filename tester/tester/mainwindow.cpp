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
    //ui->pushButtonWiFiConnect->setEnabled(false);
    //ui->pushButtonWiFiDisconnect->setEnabled(false);
    //ui->lineEditWiFiAddress->setEnabled(false);
    //ui->lineEditWiFiPort->setEnabled(false);

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
    //m_WiFiTcpSocket = new QTcpSocket(this);
    //m_WiFi_in.setDevice(m_WiFiTcpSocket);
    //m_WiFi_in.setVersion(QDataStream::Qt_5_11);
    //connect(m_WiFiTcpSocket, SIGNAL(readyRead()),this, SLOT(WiFiRead()));
    //connect(m_WiFiTcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
    //           this, &MainWindow::WiFiDisplayError);

    //Plot
    // plot Magnitude
    m_chartMag = new CPlotChart();
    m_chartMag->setType(LOGLOG);
    m_chartMag->setTitles("","Frequency","Magnitude");
  //  m_chart->setXMinXax(0,m_MaxDataPlot);
  //  m_chart->setYMinXax(0,1024);
    m_chartMag->setXMinXax(900.0,1.1e6);
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
    m_chartPha->setXMinXax(900,1.1e6);
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

    //Properties
    ui->comboBoxTagSelect->addItem("default");
    QString aux = "Measurement Tag: " + ui->comboBoxTagSelect->currentText();
    ui->statusBar->showMessage(aux);
    //ui->comboBoxTagSelect->set

    //Reader config
    ui->comboBoxPA_config->addItem("CS");
    ui->comboBoxPA_config->addItem("0V90");
    ui->comboBoxPA_config->addItem("0V95");
    ui->comboBoxPA_config->addItem("1V00");
    ui->comboBoxPA_config->addItem("1V05");
    ui->comboBoxPA_config->addItem("1V10");
    ui->comboBoxPA_config->addItem("1V15");
    ui->comboBoxPA_config->addItem("1V20");
    ui->comboBoxPA_config->addItem("1V25");
    ui->comboBoxPA_config->addItem("1V30");
    ui->comboBoxPA_config->addItem("1V35");
    ui->comboBoxPA_config->addItem("1V40");
    ui->comboBoxPA_config->addItem("1V45");
    ui->comboBoxPA_config->addItem("1V50");
    ui->comboBoxPA_config->addItem("1V55");
    ui->comboBoxPA_config->addItem("1V60");
    ui->comboBoxPA_config->addItem("1V65");
    ui->comboBoxPA_config->addItem("1V70");
    ui->comboBoxPA_config->addItem("1V75");
    ui->comboBoxPA_config->addItem("1V80");
    ui->comboBoxPA_config->addItem("1V85");
    ui->comboBoxPA_config->addItem("1V90");
    ui->comboBoxPA_config->addItem("1V95");
    ui->comboBoxPA_config->addItem("2V00");
    ui->comboBoxPA_config->addItem("2V05");
    ui->comboBoxPA_config->addItem("2V10");
    ui->comboBoxPA_config->addItem("2V15");
    ui->comboBoxPA_config->addItem("2V20");
    ui->comboBoxPA_config->addItem("2V25");
    ui->comboBoxPA_config->addItem("2V30");
    ui->comboBoxPA_config->addItem("2V35");
    ui->comboBoxPA_config->addItem("2V40");
    ui->comboBoxPA_config->addItem("2V45");
    ui->comboBoxPA_config->addItem("2V50");
    ui->comboBoxPA_config->addItem("2V55");
    ui->comboBoxPA_config->addItem("2V60");
    ui->comboBoxPA_config->addItem("2V65");
    ui->comboBoxPA_config->addItem("2V70");
    ui->comboBoxPA_config->addItem("2V75");
    ui->comboBoxPA_config->addItem("2V80");
    ui->comboBoxPA_config->addItem("2V85");
    ui->comboBoxPA_config->addItem("2V90");
    ui->comboBoxPA_config->addItem("2V95");
    ui->comboBoxPA_config->addItem("3V00");
    ui->comboBoxPA_config->addItem("3V05");
    ui->comboBoxPA_config->addItem("3V10");
    ui->comboBoxPA_config->addItem("3V15");
    ui->comboBoxPA_config->addItem("3V20");
    ui->comboBoxPA_config->addItem("3V25");
    ui->comboBoxPA_config->addItem("3V30");
    ui->comboBoxPA_config->addItem("3V35");
    ui->comboBoxPA_config->addItem("3V40");
    ui->comboBoxPA_config->addItem("3V45");
    ui->comboBoxPA_config->addItem("3V50");

    //Measurement with time delay
    m_measDelaytime = 0;
    m_timerDelay = new QTimer(this);
    m_timerDelay->setSingleShot(true);
    connect(m_timerDelay, SIGNAL(timeout()), this, SLOT(MeasurementDelayedTimeout()));

    //Automatic Mode
    m_am = 0;
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
    //reenable measurement button    
    ui->action_Run->setEnabled(true);

    //clean the rx buffer
    m_data.clear();

    //check if the measurement is complete
   int count = m_temp_measurement.getCount();

    qDebug()<<"Coming Sweep has: "<<count<<" elements";

    if (count != 11) { //failed sweep, removing it!        
        m_temp_measurement.cleanSweep();
        qDebug()<<"Failed sweep";
        return;
    }

    //Copy the coming sweep to the permanent measurements array and clean the temporal sweep.
    m_measurements[m_currentMeasurement].cleanSweep();

    for (int i = 0; i < 11; i++) {
        p_bioimpedance = new bioimpedance();
        p_bioimpedance->setMagnitude(m_temp_measurement.m_measurement[i]->getMagnitude());
        p_bioimpedance->setPhase(m_temp_measurement.m_measurement[i]->getPhase());
        p_bioimpedance->setFrequency(m_temp_measurement.m_measurement[i]->getFrequency());
        p_bioimpedance->setFrequencyIndex(m_temp_measurement.m_measurement[i]->getFrequencyIndex(ASIC));

        m_measurements[m_currentMeasurement].addImpedance(p_bioimpedance);
    }
    m_temp_measurement.cleanSweep();


    m_measurements[m_currentMeasurement].printSweep(); //print sweep in debug mode

    PlotMeasurement();    

    //increment index in circular buffer
    m_currentMeasurement++;
    if (m_currentMeasurement == 10)
        m_currentMeasurement = 0;

    ui->tableViewMag->selectRow(m_currentMeasurement);
    ui->tableViewPha->selectRow(m_currentMeasurement);

    //Repeat measurement if automode is active
    if(m_am) {
        on_action_Run_triggered();
    }
}

void MainWindow::parseRxSweepData()
{
    QByteArray rxdata;
    const char* aux = m_data.constData();

    int size = m_data.count();

    int count = 0;
    int num_packet = size/7;
    for (int i = 0; i < num_packet; i++) {
        rxdata.clear();
        for (int j = 0; j < 7; j++) {
            rxdata.append(aux[count++]);
        }

        p_bioimpedance = new bioimpedance();
        if(p_bioimpedance->setData(rxdata)) {

            if (ui->checkBoxGainCalibration->isChecked()) {
                int ind = p_bioimpedance->getFrequencyIndex(REVERSE);
                p_bioimpedance->calibrateMagnitude(m_gainCalFactor[ind]);
                p_bioimpedance->calibratePhase(m_phaseCalFactor[ind]);
            }

            //m_measurements[m_currentMeasurement].addImpedance(p_bioimpedance);
            m_temp_measurement.addImpedance(p_bioimpedance);
            qDebug()<<"arrival time: "<<m_timearrival.elapsed();

        } else {
            qDebug("bioimpedance packet corrupted");
            delete p_bioimpedance;
        }

    }

    m_data.clear();
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
            modelPha->setData(index,"");

        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 11; j++) {
            QModelIndex index = modelMagStat->index(i,j,QModelIndex());
            modelMagStat->setData(index,"");

            index = modelPhaStat->index(i,j,QModelIndex());
            modelPhaStat->setData(index,"");

        }
    }

    ui->tableViewMag->selectRow(m_currentMeasurement);
    ui->tableViewPha->selectRow(m_currentMeasurement);

    /*
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 11; j++) {
            QModelIndex index = modelCal->index(i,j,QModelIndex());
            modelCal->setData(index,"");
        }
    }
    */


}

void MainWindow::updateTables()
{
    DataTrace aux_trace;

    clearTables();

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
        count = 0;
        for (int i = 0; i < 10; i++) {
            QModelIndex indexmag = modelMag->index(i,j,QModelIndex());
            aux = modelMag->data(indexmag).toDouble();
            if (aux == 0) continue; //empty row detected!

            count++;
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
        count = 0;
        for (int i = 0; i < 10; i++) {
            QModelIndex indexmag = modelMag->index(i,j,QModelIndex());
            aux = modelMag->data(indexmag).toDouble();
            if (aux == 0) continue; //empty row detected!

            count++;
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
        count = 0;
        for (int i = 0; i < 10; i++) {
            QModelIndex indexmag = modelPha->index(i,j,QModelIndex());
            aux = modelPha->data(indexmag).toDouble();
            if (aux == 0) continue; //empty row detected!

            count++;
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
        count = 0;
        for (int i = 0; i < 10; i++) {
            QModelIndex indexmag = modelPha->index(i,j,QModelIndex());
            aux = modelPha->data(indexmag).toDouble();
            if (aux == 0) continue; //No more valid rows available!

            count++;
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

void MainWindow::MeasurementDelayedTimeout()
{
    m_measDelaytime++;
    qDebug() << "Time: " << m_measDelaytime;
    if (m_measDelaytime == 3) {
        on_action_Run_triggered();
        m_measDelaytime = 0;
    } else {                
        m_timerDelay->start(1000);
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
        ui->tableViewMag->setColumnWidth(i,20*widthTable);
        ui->tableViewMagStat->setColumnWidth(i,20*widthTable);
        ui->tableViewPha->setColumnWidth(i,20*widthTable);
        ui->tableViewPhaStat->setColumnWidth(i,20*widthTable);
    }


    widthTable = ui->tableViewCalibration->width()/12;
    for (int i = 0; i < 11; i++)
        ui->tableViewCalibration->setColumnWidth(i,20*widthTable);

    clearTables();

    //clear calibration table
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 11; j++) {
            QModelIndex index = modelCal->index(i,j,QModelIndex());
            modelCal->setData(index,"");
        }
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
        //m_WiFiTcpSocket->write(data);
    }

}

void MainWindow::on_radioButtonBT_toggled(bool checked)
{
    if (checked) {
        ui->pushButtonBTconnect->setEnabled(true);
        ui->pushButtonBTdiscoverDevices->setEnabled(true);
        //ui->pushButtonWiFiConnect->setEnabled(false);
        //ui->pushButtonWiFiDisconnect->setEnabled(false);
        //ui->lineEditWiFiAddress->setEnabled(false);
        //ui->lineEditWiFiPort->setEnabled(false);
    }

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

/*
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
*/

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

void MainWindow::on_pushButtonOpenCalFile_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Xml"), ".",
                                                    tr("Xml files (*.xml)"));
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug()<<"calibration file not opened!";
        return;
    }

    QXmlStreamReader xmlRead;

    xmlRead.setDevice(&file);
    xmlRead.readNextStartElement();
    QStringRef aux = xmlRead.name();

    while(!xmlRead.atEnd()){
        if (xmlRead.isStartElement()){
            QStringRef aux = xmlRead.name();
            if(xmlRead.name() == "CALIBRATION") {
                xmlRead.readNext(); //enter next level
            } else if (xmlRead.name() == "MAGNITUDE") {
                for (int i = 0; i < 11; i ++) {
                    xmlRead.readNextStartElement();
                    m_gainCalFactor[i] = xmlRead.readElementText().toDouble();
                }
            } else if (xmlRead.name() == "PHASE") {
                for (int i = 0; i < 11; i ++) {
                    xmlRead.readNextStartElement();
                    m_phaseCalFactor[i] = xmlRead.readElementText().toDouble();
                }
            }
        } else {
            xmlRead.readNext();
        }
    }

    file.close();

    //Update table
    for (int i=0; i < 11; i++) {
        QModelIndex index = modelCal->index(0,i,QModelIndex());
        modelCal->setData(index,QString::number(m_gainCalFactor[i],'g',4));

        index = modelCal->index(1,i,QModelIndex());
        modelCal->setData(index,QString::number(m_phaseCalFactor[i],'g',4));
    }
}

void MainWindow::on_pushButtonSaveCalFile_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save Xml"), ".",
                                                    tr("Xml files (*.xml)"));
    QFile file(filename);
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("CALIBRATION");

    xmlWriter.writeStartElement("MAGNITUDE");
    for (int i = 0; i < 11; i++) {
        QString aux = "f" + QString::number(i);
        //QString aux = QString::number(i);
        xmlWriter.writeTextElement(aux,QString::number(m_gainCalFactor[i],'g',4));
    }
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("PHASE");
    for (int i = 0; i < 11; i++) {
        QString aux = "f" + QString::number(i);
        //QString aux = QString::number(i);
        xmlWriter.writeTextElement(aux,QString::number(m_phaseCalFactor[i],'g',4));
    }
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement(); //close CALIBRATION

    xmlWriter.writeEndDocument();
    file.close();

}

void MainWindow::on_action_Run_triggered()
{
    //Ceck if BT is connected
    if (ui->labelBTstatus->text() != "Connected")
        return;

    //Check if the timer is running
    if (m_timerMeas->isActive())
        return;

    m_data.clear(); //Clear the receiving buffer

    m_temp_measurement.cleanSweep(); //Clear the temporal measurement

    ui->lineEditAT->setText("f");
    on_pushButtonATSend_clicked();
    m_timerMeas->start(2000); //sweep must be completed before this timeout!
    m_timearrival.start(); //This is used to determine the measurement total time

    //ui->pushButtonMeas->setEnabled(false);
    ui->action_Run->setEnabled(false);
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

    for (int i = 0; i < 10; i++) {
        m_measurements[i].cleanSweep();
    }
    m_currentMeasurement = 0;

    clearTables();

    m_chartMag->clearTable();
    m_chartPha->clearTable();

    m_chartMag->updatePlot();
    m_chartPha->updatePlot();

    m_temp_measurement.cleanSweep();

}

void MainWindow::on_tableViewMag_clicked(const QModelIndex &index)
{
    int row = index.row();

    m_currentMeasurement = row;

    ui->tableViewMag->selectRow(m_currentMeasurement);
    ui->tableViewPha->selectRow(m_currentMeasurement);

}

void MainWindow::on_tableViewPha_clicked(const QModelIndex &index)
{
    int row = index.row();

    m_currentMeasurement = row;

    ui->tableViewMag->selectRow(m_currentMeasurement);
    ui->tableViewPha->selectRow(m_currentMeasurement);

}

void MainWindow::on_action_Delete_sweep_triggered()
{
    m_measurements[m_currentMeasurement].cleanSweep();

    PlotMeasurement();
}

void MainWindow::on_pushButtonAddTag_clicked()
{
    QString tag;
    tag = ui->lineEditTagName->text();
    m_tags << tag;

    QString serial;
    serial = ui->lineEditSerialNumber->text();
    m_serialnumbers << serial;

    QString aux;
    aux = tag + "," + serial;

    ui->comboBoxTagSelect->addItem(aux);
}

void MainWindow::on_comboBoxTagSelect_currentIndexChanged(const QString &arg1)
{
    QString aux;
    aux = "Measurement Tag: " + ui->comboBoxTagSelect->currentText();
    ui->statusBar->showMessage(aux);
}

void MainWindow::on_pushButtonSaveTag_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save Xml"), ".",
                                                    tr("Xml files (*.xml)"));
    QFile file(filename);
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    //int count = ui->comboBoxTagSelect->count();
    int count = m_tags.count();
    // TAGLIST

    xmlWriter.writeStartElement("TAGLIST");
    QString aux;
        for (int i=0; i < (count); i++) {
            //QString tag = ui->comboBoxTagSelect->itemText(i);
            QString ele = "t" + QString::number(i);
            aux = m_tags.at(i) + "," + m_serialnumbers.at(i);

            xmlWriter.writeTextElement(ele,aux);
        }

    xmlWriter.writeEndElement(); //close TAGLIST 

    xmlWriter.writeEndDocument();
    file.close();
}

void MainWindow::on_pushButtonLoadTag_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Xml"), ".",
                                                    tr("Xml files (*.xml)"));
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug()<<"calibration file not opened!";
        return;
    }
    m_tags.clear();
    m_serialnumbers.clear();
    ui->comboBoxTagSelect->clear();
    ui->comboBoxTagSelect->addItem("default");

    QXmlStreamReader xmlRead;
    xmlRead.setDevice(&file);

    xmlRead.readNextStartElement();

    QString aux;

    int ret;
    while(!xmlRead.atEnd()){
        if (xmlRead.isStartElement()) {
            if (xmlRead.name()=="TAGLIST") {
                ret = xmlRead.readNextStartElement();
            } else if (xmlRead.name().contains("t")) {
                aux = xmlRead.readElementText();
                QStringList data = aux.split(",", QString::SkipEmptyParts);

                if (data.count() != 2) {
                    QMessageBox msgBox;
                    msgBox.setText("Invalid Tag file");
                    msgBox.exec();
                    return;
                }

                m_tags << data.at(0);
                m_serialnumbers << data.at(1);
                ui->comboBoxTagSelect->addItem(aux);
                ret = xmlRead.readNextStartElement();
            }

        } else {
            xmlRead.readNext();
        }
    }

    file.close();
}

void MainWindow::on_action_Save_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Save Measurements");
    msgBox.setInformativeText("Press Yes to save the measurements");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if (ret == QMessageBox::No) return;

    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();

    //QString date = cd.toString("yyMMdd");
    QString date = cd.toString(Qt::ISODate);

    QString time = "T" + ct.toString("hh") + "-" + ct.toString("mm") + "-" + ct.toString("ss");

    QString time2 = "T" + ct.toString("hh") + ":" + ct.toString("mm") + ":" + ct.toString("ss");

    int time_sec = (ct.toString("hh")).toInt()*3600 + (ct.toString("mm")).toInt()*60 + (ct.toString("ss")).toInt(); // Time in sec

    //QString name = ui->comboBoxTagSelect->currentText();
    int ind = ui->comboBoxTagSelect->currentIndex();
    QString name, snumber;
    if (ind == 0) {
        name = "default";
        snumber = "0";
    } else {
        name = m_tags.at(ind-1);
        snumber = m_serialnumbers.at(ind-1);
    }

    QString date_time;
    date_time =  date + "_" + time;

    QString date_time2;
    date_time2 =  date + "" + time2;

    QString filename;
    //filename = name + "_" + date + "_" + QString::number(time_sec) + ".xml";
    filename = name + "_" + date_time + ".xml";

    QFile file(filename);
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement(name);
        xmlWriter.writeStartElement("D" + date_time);

                //write <datetime>
                xmlWriter.writeTextElement("datetime", date_time2);

                //wire <serialnumber>
                xmlWriter.writeTextElement("serialnumber", snumber);

                xmlWriter.writeTextElement("TS", QString::number(time_sec));

                xmlWriter.writeStartElement("frequency");
                    bioimpedance auxbio;
                    for (int i = 0; i < 11; i++) {
                        QString sfreq = QString::number(auxbio.getFrequencies(i));
                        QString aux = "f" + QString::number(i);
                        //QString aux = "item";
                        xmlWriter.writeTextElement(aux,sfreq);
                    }
                xmlWriter.writeEndElement();

                xmlWriter.writeStartElement("amplitude");
                    for (int i = 0; i < 11; i++) {
                        QString aux = "a" + QString::number(i);

                        QModelIndex index = modelMagStat->index(0,i,QModelIndex());
                        double data = modelMagStat->data(index).toDouble();
                        xmlWriter.writeTextElement(aux,QString::number(data));
                    }
                xmlWriter.writeEndElement();

                xmlWriter.writeStartElement("phase");
                    for (int i = 0; i < 11; i++) {
                        QString aux = "p" + QString::number(i);

                        QModelIndex index = modelPhaStat->index(0,i,QModelIndex());
                        double data = modelPhaStat->data(index).toDouble();
                        xmlWriter.writeTextElement(aux,QString::number(data));
                    }
                xmlWriter.writeEndElement();

                xmlWriter.writeStartElement("amplitude_rms");
                    for (int i = 0; i < 11; i++) {
                        QString aux = "ar" + QString::number(i);

                       QModelIndex index = modelMagStat->index(1,i,QModelIndex());
                       double data = modelMagStat->data(index).toDouble();
                       xmlWriter.writeTextElement(aux,QString::number(data));
                    }
                xmlWriter.writeEndElement();

                xmlWriter.writeStartElement("phase_rms");
                    for (int i = 0; i < 11; i++) {
                         QString aux = "pr" + QString::number(i);

                         QModelIndex index = modelPhaStat->index(1,i,QModelIndex());
                         double data = modelPhaStat->data(index).toDouble();
                         xmlWriter.writeTextElement(aux,QString::number(data));
                    }
                xmlWriter.writeEndElement();

                xmlWriter.writeTextElement("additional1", ui->lineEditAdditionalData1->text());

                xmlWriter.writeTextElement("additional2", ui->lineEditAdditionalData2->text());

        xmlWriter.writeEndElement(); //close date
    xmlWriter.writeEndElement(); //close name
    xmlWriter.writeEndDocument();
    file.close();
}

void MainWindow::on_comboBoxPA_config_currentIndexChanged(const QString &arg1)
{


}

void MainWindow::on_pushButtonPA_Config_clicked()
{
    QString aux;
    aux =ui->comboBoxPA_config->currentText();

    QByteArray data;
    data.append(aux);


    if (ui->radioButtonBT->isChecked()) {
        m_bt->BTwrite(data);
    } else {    //The communication with the ESP-01 module is always terminated by cr + nl
        data.append('\r');
        data.append('\n');
       // m_WiFiTcpSocket->write(data);
    }
}

void MainWindow::on_actionRun_Timer_triggered()
{
    m_timerDelay->start(1000);
}

/*
void MainWindow::on_actionAM_toggled(bool arg1)
{
    if (arg1) {
        m_am = true;
    } else {
        m_am = false;
    }

}*/

void MainWindow::on_actionAM_triggered()
{
    ui->lineEditAT->setText("a");
    on_pushButtonATSend_clicked();
}
