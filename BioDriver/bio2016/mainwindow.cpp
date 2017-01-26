#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myserial = new CSerialDriver(&serialPort);

    connect(myserial, &CSerialDriver::RxAvailable,this,&MainWindow::SerialRx);

    readPorts();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readPorts()
{
    //Obtain information about the available serial ports:
    QList<QSerialPortInfo> serialPortInfos = QSerialPortInfo::availablePorts();
    int num = serialPortInfos.count(); //Number of available serial ports

    //qDebug("number of items = %d",num);

    ui->comboBoxPorts->clear();

    for (int i = 0; i < num; i++) {
        //qDebug() << serialPortInfos[i].portName(); // Name of each serial port
        ui->comboBoxPorts->addItem(serialPortInfos[i].portName());
    }
}

void MainWindow::on_pushButtonRefreshPorts_clicked()
{
    readPorts();

}

void MainWindow::on_pushButtonConnect_clicked()
{
    QString aux;
    aux = ui->comboBoxPorts->currentText();

    //serialPort.setPortName(serialPortInfos[1].portName());
    serialPort.setPortName(aux);
    serialPort.setBaudRate(QSerialPort::Baud9600);

    serialPort.open(QIODevice::ReadWrite);
}

void MainWindow::on_pushButtonTest_clicked()
{
    //Send a test word
    QString test = "tes";

    QByteArray writedata(test.toUtf8());

    myserial->write(writedata);

    //Update log
    test = "<tx> tes (test word)";
    ui->plainTextEditLog->appendPlainText(test);

}

void MainWindow::SerialRx(const QByteArray &Data)
{
    //Update log
    QString aux;

    aux = "<rx> " + QString::fromUtf8(Data.constData());
    ui->plainTextEditLog->appendPlainText(aux);

    //Process received data
}

void MainWindow::on_pushButtonConfigure_clicked()
{
   bool F3 = ui->checkBoxF3->isChecked();
   bool F2 = ui->checkBoxF2->isChecked();
   bool F1 = ui->checkBoxF1->isChecked();
   bool F0 = ui->checkBoxF0->isChecked();
   bool IQ = ui->checkBoxIQ->isChecked();
   bool GS3 = ui->checkBoxGS3->isChecked();
   bool GS2 = ui->checkBoxGS2->isChecked();
   bool GS1 = ui->checkBoxGS1->isChecked();
   bool GS0 = ui->checkBoxGS0->isChecked();
   bool CE = ui->checkBoxCE->isChecked();
   bool NS = ui->checkBoxNS->isChecked();
   bool GD2 = ui->checkBoxGD2->isChecked();
   bool GD1 = ui->checkBoxGD1->isChecked();
   bool GD0 = ui->checkBoxGD0->isChecked();
   bool FS = ui->checkBoxFS->isChecked();
   bool RE = ui->checkBoxRE->isChecked();

   m_bioASIC.setbits(F3,F2,F1,F0,IQ,GS3,GS2,GS1,GS0,CE,NS,GD2,GD1,GD0,FS,RE);

   //Prepare byte array for serial communications
   QByteArray writedata;
   writedata.append("c",1);
//   writedata.append(m_bioASIC.getByte0());
//   writedata.append(m_bioASIC.getByte1());
   writedata.append(m_bioASIC.getByte(0));
   writedata.append(m_bioASIC.getByte(1));


   //Prepare log information
   QString command = "<tx> c ";
   if (F3) command += "1"; else command += "0";
   if (F2) command += "1"; else command += "0";
   if (F1) command += "1"; else command += "0";
   if (F0) command += "1_"; else command += "0_";

   if (IQ) command += "1"; else command += "0";
   if (GS3) command += "1"; else command += "0";
   if (GS2) command += "1"; else command += "0";
   if (GS1) command += "1_"; else command += "0_";

   if (GS0) command += "1"; else command += "0";
   if (CE) command += "1"; else command += "0";
   if (NS) command += "1"; else command += "0";
   if (GD2) command += "1_"; else command += "0_";

   if (GD1) command += "1"; else command += "0";
   if (GD0) command += "1"; else command += "0";
   if (FS) command += "1"; else command += "0";
   if (RE) command += "1"; else command += "0";

   //Transmit serial data
   myserial->write(writedata);

   //Append log
   ui->plainTextEditLog->appendPlainText(command);
}

void MainWindow::on_pushButtonConfigAll_clicked()
{
    //Filter bits
    bool EnLF = ui->checkBoxEnLF->isChecked();

    bool EnMF = ui->checkBoxEnMF->isChecked();
    bool EnHF = ui->checkBoxEnHF->isChecked();
    bool DN1 = ui->checkBoxDN1->isChecked();
    bool DN0 = ui->checkBoxDN0->isChecked();
    bool DP2 = ui->checkBoxDP2->isChecked();
    bool DP1 = ui->checkBoxDP1->isChecked();
    bool DP0 = ui->checkBoxDP0->isChecked();
    bool EnRdeg = ui->checkBoxEnRdeg->isChecked();

    bool EnRdegHF1 = ui->checkBoxEnRdegHF1->isChecked();
    bool EnRdegHF0 = ui->checkBoxEnRdegHF0->isChecked();
    bool CcompSel1 = ui->checkBoxCcompSel1->isChecked();
    bool CcompSel0 = ui->checkBoxCcompSel0->isChecked();
    bool CapSel3 = ui->checkBoxCapSel3->isChecked();
    bool CapSel2 = ui->checkBoxCapSel2->isChecked();
    bool CapSel1 = ui->checkBoxCapSel1->isChecked();
    bool CapSel0 = ui->checkBoxCapSel0->isChecked();

    //Radio bits
    bool F3 = ui->checkBoxF3->isChecked();
    bool F2 = ui->checkBoxF2->isChecked();
    bool F1 = ui->checkBoxF1->isChecked();
    bool F0 = ui->checkBoxF0->isChecked();
    bool IQ = ui->checkBoxIQ->isChecked();
    bool GS3 = ui->checkBoxGS3->isChecked();
    bool GS2 = ui->checkBoxGS2->isChecked();
    bool GS1 = ui->checkBoxGS1->isChecked();

    bool GS0 = ui->checkBoxGS0->isChecked();
    bool CE = ui->checkBoxCE->isChecked();
    bool NS = ui->checkBoxNS->isChecked();
    bool GD2 = ui->checkBoxGD2->isChecked();
    bool GD1 = ui->checkBoxGD1->isChecked();
    bool GD0 = ui->checkBoxGD0->isChecked();
    bool FS = ui->checkBoxFS->isChecked();
    bool RE = ui->checkBoxRE->isChecked();

    //Set configuration bits
    m_vinASIC.setbitsFilter(EnLF,EnMF,EnHF,DN1,DN0,DP2,DP1,DP0,EnRdeg,EnRdegHF1,
                            EnRdegHF0,CcompSel1,CcompSel0,CapSel3,CapSel2,CapSel1,CapSel0);
    m_vinASIC.setbitsRadio(F3,F2,F1,F0,IQ,GS3,GS2,GS1,GS0,CE,NS,GD2,GD1,GD0,FS,RE);

    //Prepare byte array for serial communications
    QByteArray writedata;
    writedata.append("f",1);
    writedata.append(m_vinASIC.getByte(0));
    writedata.append(m_vinASIC.getByte(1));
    writedata.append(m_vinASIC.getByte(2));
    writedata.append(m_vinASIC.getByte(3));
    writedata.append(m_vinASIC.getByte(4));

    //Prepare log information
    QString command = "<tx> f ";
    if (EnLF) command += "1_"; else command += "0_";

    if (EnMF) command += "1"; else command += "0";
    if (EnHF) command += "1"; else command += "0";
    if (DN1) command += "1"; else command += "0";
    if (DN0) command += "1_"; else command += "0_";
    if (DP2) command += "1"; else command += "0";
    if (DP1) command += "1"; else command += "0";
    if (DP0) command += "1"; else command += "0";
    if (EnRdeg) command += "1_"; else command += "0_";

    if (EnRdegHF1) command += "1"; else command += "0";
    if (EnRdegHF0) command += "1"; else command += "0";
    if (CcompSel1) command += "1"; else command += "0";
    if (CcompSel0) command += "1_"; else command += "0_";
    if (CapSel3) command += "1"; else command += "0";
    if (CapSel2) command += "1"; else command += "0";
    if (CapSel1) command += "1"; else command += "0";
    if (CapSel0) command += "1_"; else command += "0_";

    if (F3) command += "1"; else command += "0";
    if (F2) command += "1"; else command += "0";
    if (F1) command += "1"; else command += "0";
    if (F0) command += "1_"; else command += "0_";

    if (IQ) command += "1"; else command += "0";
    if (GS3) command += "1"; else command += "0";
    if (GS2) command += "1"; else command += "0";
    if (GS1) command += "1_"; else command += "0_";

    if (GS0) command += "1"; else command += "0";
    if (CE) command += "1"; else command += "0";
    if (NS) command += "1"; else command += "0";
    if (GD2) command += "1_"; else command += "0_";

    if (GD1) command += "1"; else command += "0";
    if (GD0) command += "1"; else command += "0";
    if (FS) command += "1"; else command += "0";
    if (RE) command += "1"; else command += "0";

    //Transmit serial data
    myserial->write(writedata);

    //Append log
    ui->plainTextEditLog->appendPlainText(command);

}
