#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts/QChartView>

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /**** Toolbar ******/
    //   ui->mainToolBar->setIconSize(QSize(120, 120));

    //config initialization, BLE set as default

    ui->pushButtonBTconnect->setEnabled(false);
    ui->pushButtonBTdiscoverDevices->setEnabled(false);
    ui->pushButtonBTdisconnect->setEnabled(false);

    ui->pushButtonBLEConnect->setEnabled(true);
    ui->pushButtonBLEDiscover->setEnabled(true);
    ui->pushButtonBLEDisconnect->setEnabled(false);

    ui->comboBoxHorizontalScale->addItem("640");
    ui->comboBoxHorizontalScale->addItem("1280");
    ui->comboBoxHorizontalScale->addItem("2560");
    ui->comboBoxHorizontalScale->addItem("5120");


    ui->lineEditClkFreq->setText("1");

    // Plot configuration



    m_MaxDataPlot = 640;
    //m_MaxDataPlot = 1280;
    //m_MaxDataPlot = 2560;
    m_DataCounter = 0;
    //m_MaxNumSamples = 6000; //Max Number of samples to be recorded before the buffers are cleared
    m_MaxNumSamples = m_MaxDataPlot*4; //Max Number of samples to be recorded before the buffers are cleared
    m_PlotCounter = 0;
    m_PlotTimeout = 100; //time in ms
    m_PlotNumUpdate = 10; //number of samples to update every m_PlotTimeout
    m_MaxVerticalRange = 4096;

    //Bluetooth
    m_bt = new BTClient(this);
    connect(m_bt, SIGNAL(BTnewDeviceDiscovered(QString)),
            this, SLOT(BTgetDevice(QString)));
    connect(m_bt, SIGNAL(BTnewDeviceConnected(QString)),
            this, SLOT(BTConnected(QString)));
    connect(m_bt, SIGNAL(BTrxData(QByteArray)),
            this, SLOT(BTrxData(const QByteArray)));


    //BLE
    m_ble = new BLEClient(this);
    connect(m_ble, &BLEClient::deviceFound, this, &MainWindow::BLEdeviceFound);
    connect(m_ble, &BLEClient::rxData, this, &MainWindow::BLErxData);
    connect(m_ble, &BLEClient::BLEupdateStatus, this, &MainWindow::BLEupdatestatus);

    //Plot
    m_chart = new CPlotChart();
    m_chart->setTitles("","Time","ADC");
    m_chart->setXMinXax(0,m_MaxDataPlot);
    //m_chart->setYMinXax(0,1024);
    m_chart->setYMinXax(0,m_MaxVerticalRange);
    m_chart->initializePlot();
    m_chartView = new QChartView(static_cast<QChart*>(m_chart));
    //Set antialising properties and the chartview object to a place in layout
    m_chartView->setRenderHint(QPainter::Antialiasing, false); //false or true
    ui->verticalLayout_3->addWidget(m_chartView,1);

    //timer to refresh the plot
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(PlotTimeout()));
    //m_timer->start(m_PlotTimeout);

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

    ui->pushButtonBTdisconnect->setEnabled(true);
}

void MainWindow::BTrxData(const QByteArray &data)
{
    ui->plainTextEditAT->appendPlainText(QString::fromStdString(data.toStdString()));

    m_data.append(data);

    //Continuous sampling processing
    if (!m_timer->isActive())
        return;

    //int size = data.count();
    int size = data.length();
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

    //int size = data.count()/2; //Each converted value comes in 2 bytes unsigned short.
    int size = data.length()/2; //Each converted value comes in 2 bytes unsigned short.

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
    QString aux = ui->lineEditAT->text();

    QByteArray data;
    data.append(aux.toUtf8());
    //data.append()

    if (ui->radioButtonBT->isChecked()) {
        m_bt->BTwrite(data);
    } else {    //The communication with the ESP-01 module is always terminated by cr + nl
        data.append('\r');
        data.append('\n');
        //m_WiFiTcpSocket->write(data);
    }

    //if continuous sampling is sent, start the timer
    switch (data.at(0)) {
        case 's':   m_timer->start(m_PlotTimeout);
                    break;
        case 'S':   m_timer->stop();
                    break;
        default:
                    break;

    }
}

void MainWindow::on_radioButtonBT_toggled(bool checked)
{
    if (checked) {
        ui->pushButtonBTconnect->setEnabled(true);
        ui->pushButtonBTdiscoverDevices->setEnabled(true);
        ui->pushButtonBTdisconnect->setEnabled(false);

        ui->pushButtonBLEConnect->setEnabled(false);
        ui->pushButtonBLEDiscover->setEnabled(false);
        ui->pushButtonBLEDisconnect->setEnabled(false);

    }

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

void MainWindow::on_actionStart_triggered()
{
    QByteArray data;
    data.append("s");

    if (ui->radioButtonBT->isChecked()) {
        m_bt->BTwrite(data);
    } else {    //The communication with the ESP-01 module is always terminated by cr + nl
        //data.append('\r');
        //data.append('\n');
        //m_WiFiTcpSocket->write(data);
        m_ble->write(data);
    }

    m_timer->start(m_PlotTimeout);

}


void MainWindow::on_actionStop_triggered()
{
    QByteArray data;
    data.append("S");

    if (ui->radioButtonBT->isChecked()) {
        m_bt->BTwrite(data);
    } else {    //The communication with the ESP-01 module is always terminated by cr + nl
        //data.append('\r');
        //data.append('\n');
        //m_WiFiTcpSocket->write(data);
        m_ble->write(data);
    }

    m_timer->stop();
}


void MainWindow::on_radioButtonBLE_toggled(bool checked)
{
    if (checked) {

        ui->pushButtonBLEConnect->setEnabled(true);
        ui->pushButtonBLEDiscover->setEnabled(true);
        ui->pushButtonBLEDisconnect->setEnabled(false);

        ui->pushButtonBTconnect->setEnabled(false);
        ui->pushButtonBTdiscoverDevices->setEnabled(false);
        ui->pushButtonBTdisconnect->setEnabled(false);
    }
}


void MainWindow::BLEdeviceFound(QString device)
{
    ui->comboBoxBLE->addItem(device);

}

void MainWindow::BLErxData(const QByteArray &data)
{
    QString aux;
    aux = QString::fromStdString(data.toStdString());
    //ui->labelBLEStatus->setText(aux);
    qDebug()<< aux;
    BTrxData(data);
}

void MainWindow::BLEupdatestatus(QString &status)
{
    ui->labelBLEStatus->setText(status);

    if (status == "Connected") {
        ui->pushButtonBLEDisconnect->setEnabled(true);
    }

    if (status == "Disconnected") {
        ui->pushButtonBLEDisconnect->setEnabled(false);
    }
}


void MainWindow::on_pushButtonBLEDiscover_clicked()
{
    ui->comboBoxBLE->clear();
    m_ble->discover();
}


void MainWindow::on_pushButtonBLEConnect_clicked()
{
    int index = ui->comboBoxBLE->currentIndex();
    m_ble->BLEconnect(index);
}


void MainWindow::on_pushButtonBLEDisconnect_clicked()
{
    m_ble->BLEdisconnect();
}

void MainWindow::on_comboBoxHorizontalScale_currentTextChanged(const QString &arg1)
{

    if (m_chart == nullptr)
        return;


    m_MaxDataPlot = arg1.toInt();
    qDebug()<< m_MaxDataPlot;


    m_chart->setXMinXax(0,m_MaxDataPlot);

    m_MaxNumSamples = m_MaxDataPlot*4;

}


void MainWindow::on_pushButtonSendSPI_clicked()
{
    QString SPIaddress = ui->lineEditSPIAddr->text();
    QString SPIval = ui->lineEditSPIVal->text();


    uint32_t SPIaddress_num = SPIaddress.toInt();

    bool ok;
    uint32_t SPIval_num = SPIval.toUInt(&ok, 16);

    if(!ok) {
        qDebug()<<"error parsing SPI hexadecimal register value";
        return;
    }

    QByteArray data;
    data.clear();

    // Send identifier for command
    data.append('w');

    data.append((uint8_t)SPIaddress_num);

    data.append((uint8_t)(SPIval_num & 0xff));
    data.append((uint8_t)((SPIval_num >> 8) & 0xff));
    data.append((uint8_t)((SPIval_num >> 16) & 0xff));
    data.append((uint8_t)((SPIval_num >> 24) & 0xff));

    if (ui->radioButtonBT->isChecked()) {
        m_bt->BTwrite(data);
    } else {
        m_ble->write(data);
    }

}


void MainWindow::on_actionOut1_triggered()
{
    QByteArray data;
    data.clear();

    if (ui->actionOut1->isChecked()) {
        qDebug()<<"Out1 checked";
        data.append('o');

    } else {
        qDebug()<<"Out1 unchecked";
        data.append('O');
    }

    if (ui->radioButtonBT->isChecked()) {
        m_bt->BTwrite(data);
    } else {
        m_ble->write(data);
    }

}


void MainWindow::on_actionOut2_triggered()
{
    QByteArray data;
    data.clear();

    if (ui->actionOut2->isChecked()) {
        qDebug()<<"Out2 checked";
        data.append('p');

    } else {
        qDebug()<<"Out2 unchecked";
        data.append('P');
    }

    if (ui->radioButtonBT->isChecked()) {
        m_bt->BTwrite(data);
    } else {
        m_ble->write(data);
    }
}


void MainWindow::on_actionCLK_triggered()
{
    QByteArray data;
    data.clear();

    if (ui->actionCLK->isChecked()) {
        qDebug()<<"Clk checked";
        data.append('c');

        QString aux = ui->lineEditClkFreq->text();
        uint8_t aux_num = (uint8_t)aux.toUInt();

        qDebug()<<"Clk freq: "<<aux_num;

        data.append(aux_num);

    } else {
        qDebug()<<"Clk unchecked";
        data.append('C');
    }

    if (ui->radioButtonBT->isChecked()) {
        m_bt->BTwrite(data);
    } else {
        m_ble->write(data);
    }
}



void MainWindow::on_checkBoxPlotText_stateChanged(int arg1)
{
    if (ui->checkBoxPlotText->isChecked()) {
        m_chart->setTextInvisible(true);
    } else {
        m_chart->setTextInvisible(false);
    }
}

