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

    m_ADC_diff = 0;
    m_ADC_se = 0;
    m_offset_diff = 0;
    m_offset_se = 0;
    m_I_diff = 0;
    m_I_se = 0;
    m_Q_diff = 0;
    m_Q_se = 0;
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
    const char* read_pt = Data.constData();

    /*
    if(read_pt[0] == 'm') {
        readADC(Data);
        qDebug()<<"Measure ADCs RX";
    }    
    */

    /*******************
     * MESSAGE HANDLER *
     *******************/

    switch (read_pt[0]) {
        case 'm':
                readADC(Data);
                qDebug()<<"Measure ADCs RX";
                break;
        case 'z':
                receiveImpedance(Data);
                qDebug()<<"Impedance Measurement RX";
                break;
        default:
                break;
    }

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

void MainWindow::on_pushButtonTestADC_clicked()
{
    //Prepare byte array for serial communications
    QByteArray writedata;
    writedata.append("m",1);
    myserial->write(writedata);

}

void MainWindow::readADC(const QByteArray &Data)
{
    quint16 vop,von,vse;

    const char* read_pt = Data.constData();

    vop = 0;
    vop |= (quint16)(read_pt[2] << 8) ;
    vop |= (quint16)(read_pt[1] & 0xff);

    von = 0;
    von |= (quint16)(read_pt[4] << 8) ;
    von |= (quint16)(read_pt[3] & 0xff);

    vse = 0;
    vse |= (quint16)(read_pt[6] << 8) ;
    vse |= (quint16)(read_pt[5] & 0xff);

    m_bioASIC.setADCvalues(vop,von,vse);

    double voutp,voutn,voutse;
    m_bioASIC.getADCVoltages(&voutp,&voutn,&voutse);

    //Save ADC voltage values
    m_ADC_diff = voutp-voutn;
    m_ADC_se = voutse;

    QString aux;

    aux = "VOP (CH1): " + QString::number(vop) + " " + QString("%1").arg(voutp,5,'g',4);
    ui->label_CH2->setText(aux);

    aux = "VON (CH3): " + QString::number(von) + " " +QString("%1").arg(voutn,5,'g',4);
    ui->label_CH3->setText(aux);

    aux = "VSE (CH5): " + QString::number(vse) + " " + QString("%1").arg(voutse,5,'g',4);
    ui->label_CH5->setText(aux);

}

void MainWindow::on_pushButtonAllTest_clicked()
{
    /*
    QByteArray aux;
    aux.append('m');
    aux.append(0xc1);
    aux.append(0x02);
    aux.append(0xc1);
    aux.append(0x02);
    aux.append(0xc1);
    aux.append(0x02);

    readADC(aux);;
    */

    QByteArray aux;
    aux.append('z');
    aux.append(0x99);
    aux.append(0x02);
    aux.append(0xA3);
    aux.append(0x02);
    aux.append(0x47);
    aux.append(0x02);
    aux.append(0xf3);
    aux.append(0x02);
    aux.append(0x91);
    aux.append(0x02);
    aux.append(0xab);
    aux.append(0x02);

    receiveImpedance(aux);

    //int aux = m_bioASIC.getGainIndex();
//    double mag,pha;

//    m_bioASIC.getImpedance(&mag,&pha,0,0.685864);
}

void MainWindow::on_pushButtonSaveOffset_clicked()
{
    m_offset_diff = m_ADC_diff;
    m_offset_se = m_ADC_se;

    //ui->lineEditOffsetDiff->setText(QString("%1").arg(m_offset_diff,5,'g',4));
    QString aux;
    aux.sprintf("%5.4f",m_offset_diff);
    ui->lineEditOffsetDiff->setText(aux);

    aux.sprintf("%5.4f",m_offset_se);
    ui->lineEditOffsetSE->setText(aux);
}

void MainWindow::on_pushButtonSaveI_clicked()
{        
    m_I_diff = m_ADC_diff;
    m_I_se = m_ADC_se;

    QString aux;

    aux.sprintf("%5.4f",m_I_diff);
    ui->lineEditIDiff->setText(aux);

    aux.sprintf("%5.4f",m_I_se);
    ui->lineEditISE->setText(aux);
}

void MainWindow::on_pushButtonSaveQ_clicked()
{
    m_Q_diff = m_ADC_diff;
    m_Q_se = m_ADC_se;

    QString aux;

    aux.sprintf("%5.4f",m_Q_diff);
    ui->lineEditQDiff->setText(aux);
    aux.sprintf("%5.4f",m_Q_se);
    ui->lineEditQSE->setText(aux);
}

void MainWindow::on_pushButtonCalcZ_clicked()
{
    double mag, pha, I, Q;

    I = m_I_diff - m_offset_diff;
    Q = m_Q_diff - m_offset_diff;

    m_bioASIC.setMixerGainFactor(0.5667049);
    m_bioASIC.getImpedance(&mag,&pha,I,Q);

    QString aux;
    aux.sprintf("%5.2f",mag);
    ui->lineEditMag->setText(aux);

    aux.sprintf("%5.2f",pha);
    ui->lineEditPhase->setText(aux);

}

void MainWindow::on_pushButtonMeasureZ_clicked()
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
    writedata.append("z",1);
    writedata.append(m_bioASIC.getByte(0));
    writedata.append(m_bioASIC.getByte(1));


    //Prepare log information
    QString command = "<tx> z ";
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

void MainWindow::receiveImpedance(const QByteArray &Data)
{
    quint16 vop,von,vse;
    double voutp,voutn,voutse;
    double Offset_diff, I_diff, Q_diff;

    const char* read_pt = Data.constData();

    //OFFSET
    vop = 0;
    vop |= (quint16)(read_pt[2] << 8) ;
    vop |= (quint16)(read_pt[1] & 0xff);

    von = 0;
    von |= (quint16)(read_pt[4] << 8) ;
    von |= (quint16)(read_pt[3] & 0xff);

    vse = 0;

    m_bioASIC.setADCvalues(vop,von,vse);
    m_bioASIC.getADCVoltages(&voutp,&voutn,&voutse);

    Offset_diff = voutp - voutn;

    //I

    vop = 0;
    vop |= (quint16)(read_pt[6] << 8) ;
    vop |= (quint16)(read_pt[5] & 0xff);

    von = 0;
    von |= (quint16)(read_pt[8] << 8) ;
    von |= (quint16)(read_pt[7] & 0xff);

    m_bioASIC.setADCvalues(vop,von,vse);
    m_bioASIC.getADCVoltages(&voutp,&voutn,&voutse);

    I_diff = (voutp - voutn) - Offset_diff;

    //Q
    vop = 0;
    vop |= (quint16)(read_pt[10] << 8) ;
    vop |= (quint16)(read_pt[9] & 0xff);

    von = 0;
    von |= (quint16)(read_pt[12] << 8) ;
    von |= (quint16)(read_pt[11] & 0xff);

    m_bioASIC.setADCvalues(vop,von,vse);
    m_bioASIC.getADCVoltages(&voutp,&voutn,&voutse);

    Q_diff = (voutp - voutn) - Offset_diff;

    double mag, pha;

    m_bioASIC.setMixerGainFactor(0.5667049);
    m_bioASIC.getImpedance(&mag,&pha,I_diff,Q_diff);

    QString aux;
    aux.sprintf("%5.2f",mag);
    ui->lineEditMeasuredMag->setText(aux);

    aux.sprintf("%5.2f",pha);
    ui->lineEditMeasuredPhase->setText(aux);

}
