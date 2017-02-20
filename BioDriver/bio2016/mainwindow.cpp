#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myserial = new CSerialDriver(&serialPort);

    connect(myserial, &CSerialDriver::RxAvailable,this,&MainWindow::SerialRx);

    readPorts();
    setComboFreq();
    setComboGain();
    m_current_gain_counter = 0;

    m_ADC_diff = 0;
    m_ADC_se = 0;
    m_offset_diff = 0;
    m_offset_se = 0;
    m_I_diff = 0;
    m_I_se = 0;
    m_Q_diff = 0;
    m_Q_se = 0;


    ui->lineEditMinY->setText("0");
    ui->lineEditMaxY->setText("10000");
    ui->lineEditMinYLog->setText("10");
    ui->lineEditNumDec->setText("5");

    //Setup plots
    m_light_theme = 0; //black theme (default)
    m_semilog = 0; // default for magnitude is log

    //Magnitude plot
    m_minY = 0;
    m_maxY = 1e6;

    ui->widgetMagnitude->SetXAxisName(QString("Freq (Hz)"));
    ui->widgetMagnitude->SetYAxisName(QString("Mag"));
    ui->widgetMagnitude->setYMin(m_minY);
    ui->widgetMagnitude->setYMax(m_maxY);
    ui->widgetMagnitude->setXMinLog(1e3);
    ui->widgetMagnitude->setYMinLog(10);
    ui->widgetMagnitude->setXNumDec(3);
    ui->widgetMagnitude->setYNumDec(5);
    ui->widgetMagnitude->enableLogPlot();
    //ui->widgetMagnitude->setYMin(1);
    //ui->widgetMagnitude->setYMax(10);


    //Phase plot;
    ui->widgetPhase->setYMin(0);
    ui->widgetPhase->setYMax(90);
    ui->widgetPhase->setYTicksNum(9);
    ui->widgetPhase->setXMinLog(1e3);
    ui->widgetPhase->setXNumDec(3);
    ui->widgetPhase->enableSemiLogPlot();
    ui->widgetPhase->SetXAxisName(QString("Freq (Hz)"));
    ui->widgetPhase->SetYAxisName(QString("Phase"));

    m_currentFreq = STAT_FREQ0;
    m_currentFreqIndex = 0;

    m_sweep_state = IDLE;
    m_append = false;
    m_append_curve_num = 0;

    //DataTable
    setTables();
    ui->lineEditStatisticSamples->setText("5");

    //Calibration
    ui->lineEditCalRes->setText("1000");



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

void MainWindow::setComboFreq()
{
    //Setup combo frequencies
    ui->comboBoxFreqs->clear();
    QString aux;

    aux.sprintf("%5.1f",STAT_FREQ0);
    ui->comboBoxFreqs->addItem(aux);
    aux.sprintf("%5.1f",STAT_FREQ1);
    ui->comboBoxFreqs->addItem(aux);
    aux.sprintf("%5.1f",STAT_FREQ2);
    ui->comboBoxFreqs->addItem(aux);
    aux.sprintf("%5.1f",STAT_FREQ3);
    ui->comboBoxFreqs->addItem(aux);
    aux.sprintf("%5.1f",STAT_FREQ4);
    ui->comboBoxFreqs->addItem(aux);
    aux.sprintf("%5.1f",STAT_FREQ5);
    ui->comboBoxFreqs->addItem(aux);
    aux.sprintf("%5.1f",STAT_FREQ6);
    ui->comboBoxFreqs->addItem(aux);
    aux.sprintf("%5.1f",STAT_FREQ7);
    ui->comboBoxFreqs->addItem(aux);
    aux.sprintf("%5.1f",STAT_FREQ8);
    ui->comboBoxFreqs->addItem(aux);
    aux.sprintf("%5.1f",STAT_FREQ9);
    ui->comboBoxFreqs->addItem(aux);
    aux.sprintf("%5.1f",STAT_FREQ10);
    ui->comboBoxFreqs->addItem(aux);

    on_comboBoxFreqs_currentIndexChanged(0);

}

void MainWindow::setComboGain()
{
    //Setup combo gain
    ui->comboBoxGain->clear();

    ui->comboBoxGain->addItem("GAIN0");
    ui->comboBoxGain->addItem("GAIN1");
    ui->comboBoxGain->addItem("GAIN2");
    ui->comboBoxGain->addItem("GAIN3");
    ui->comboBoxGain->addItem("GAIN4");
    ui->comboBoxGain->addItem("GAIN5");
    ui->comboBoxGain->addItem("GAIN6");
    ui->comboBoxGain->addItem("GAIN7");

    on_comboBoxGain_currentIndexChanged(0);


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

    /*
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
    */
    //int aux = m_bioASIC.getGainIndex();
//    double mag,pha;

//    m_bioASIC.getImpedance(&mag,&pha,0,0.685864);

    processSweep(1005.2,-5.5);
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
    measureImpedance();
}

void MainWindow::receiveImpedance(const QByteArray &Data)
{
    quint16 vop,von,vse;
    double voutp,voutn,voutse;
    double Offset_diff, I_diff, Q_diff;

    const char* read_pt = Data.constData();

    //OFFSET EXTRACTION
    vop = 0;
    vop |= (quint16)(read_pt[2] << 8) ;
    vop |= (quint16)(read_pt[1] & 0xff);

    von = 0;
    von |= (quint16)(read_pt[4] << 8) ;
    von |= (quint16)(read_pt[3] & 0xff);

    vse = 0;

    m_bioASIC.setADCvalues(vop,von,vse);
    m_bioASIC.getADCVoltages(&voutp,&voutn,&voutse);

    Offset_diff = voutp - voutn; //differential offset

    //I EXTRACTION
    vop = 0;
    vop |= (quint16)(read_pt[6] << 8) ;
    vop |= (quint16)(read_pt[5] & 0xff);

    von = 0;
    von |= (quint16)(read_pt[8] << 8) ;
    von |= (quint16)(read_pt[7] & 0xff);

    m_bioASIC.setADCvalues(vop,von,vse);
    m_bioASIC.getADCVoltages(&voutp,&voutn,&voutse);

    I_diff = (voutp - voutn) - Offset_diff; //differential I without offset

    qDebug()<<"Ip = " << voutp << " In = " << voutn;

    //Q EXTRACTION
    vop = 0;
    vop |= (quint16)(read_pt[10] << 8) ;
    vop |= (quint16)(read_pt[9] & 0xff);

    von = 0;
    von |= (quint16)(read_pt[12] << 8) ;
    von |= (quint16)(read_pt[11] & 0xff);

    m_bioASIC.setADCvalues(vop,von,vse);
    m_bioASIC.getADCVoltages(&voutp,&voutn,&voutse);

    Q_diff = (voutp - voutn) - Offset_diff; //differential Q without offet


    qDebug()<<"Qp = " << voutp << " Qn = " << voutn;
    qDebug()<<"I = " << I_diff << " Q = " << Q_diff;

    //Automatic Gain Check if values are in range
    double aux_vol;

    if (fabs(I_diff) > fabs(Q_diff)) {
        aux_vol = fabs(I_diff);
    } else {
        aux_vol = fabs(Q_diff);
    }

    qDebug()<< "aux_vol = " << aux_vol;


    if (aux_vol > 0.7) { //reduce the gain
        if (m_current_gain > 0) {
            m_current_gain--;
            qDebug() << "Reducing gain to: GAIN" << m_current_gain;
            m_current_gain_counter++;
            on_comboBoxGain_currentIndexChanged(m_current_gain);
            measureImpedance();
            return;
        }

    } else if (aux_vol < 0.2 && !m_current_gain_counter) { //Increase the gain
        if (m_current_gain < 7) {
            m_current_gain ++;
            qDebug() << "Increasing gain to: GAIN" << m_current_gain;
            on_comboBoxGain_currentIndexChanged(m_current_gain);
            measureImpedance();
            return;
        }
    }

    //Value is in range
    m_current_gain_counter = 0;

    //Calculate Impedance Magnitude and Phase
    double mag, pha;

    m_bioASIC.setMixerGainFactor(0.5667049);
    m_bioASIC.getImpedance(&mag,&pha,I_diff,Q_diff);

    QString aux;
    aux.sprintf("%5.2f",mag);
    ui->lineEditMeasuredMag->setText(aux);

    aux.sprintf("%5.2f",pha);
    ui->lineEditMeasuredPhase->setText(aux);

    //Check if the measurement comes from a sweep
    if (m_sweep_state == RUN) {
        processSweep(mag,pha);
    }

}

void MainWindow::measureImpedance()
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

void MainWindow::processSweep(double mag, double phase)
{
    int num_curve;


    if (m_append) {
        num_curve = m_append_curve_num;
    } else {
        num_curve = 0;
    }

    //Check if phase calibration is enabled
    bool calphase = ui->checkBoxCalibratePhase->isChecked();

    if (calphase) {
        qDebug() << "Calibration Enabled!";
        phase += m_PhaseCalibration[FREQ10 - m_currentFreqIndex]; //
        mag *= m_MagCalibration[FREQ10 - m_currentFreqIndex];
    }


    qDebug() << "Entering process sweep: freq: " << m_currentFreq << " mag = " << mag << " phase = " << phase;
    ui->widgetMagnitude->appendPoint(m_currentFreq,mag,num_curve);
    ui->widgetPhase->appendPoint(m_currentFreq,-phase,num_curve); //Phase changed sign here!!

    ui->widgetMagnitude->update();
    ui->widgetPhase->update();

    updateTable(mag,-phase);

    if (m_currentFreqIndex > 0) { //Change frequency and make a new measurement
        m_currentFreqIndex--;
        on_comboBoxFreqs_currentIndexChanged(m_currentFreqIndex);
        measureImpedance();

    } else {    //The Sweep has finished
        m_sweep_state = IDLE;
        qDebug() << "Sweep finished, changing state to IDLE";
        m_append_curve_num++;
/*        if (m_append_curve_num == 10) {//All colors have been used
            m_append_curve_num = 0;

            for (int i = 0; i < 10; i++) { //clears the curves
                ui->widgetMagnitude->clearCurve(i);
                ui->widgetPhase->clearCurve(i);
            }
        }*/
    }

}

void MainWindow::setTables()
{
    modelMag = new QStandardItemModel(10,11,this);
    modelPha = new QStandardItemModel(10,11,this);

    ui->tableViewMag->setModel(modelMag);
    ui->tableViewPhase->setModel(modelPha);

    int widthTable = ui->tableViewMag->width();

    for (int i = 0; i < 10; i++)
        ui->tableViewMag->setColumnWidth(i,widthTable/12);

    widthTable = ui->tableViewPhase->width();
    for (int i = 0; i < 10; i++)
        ui->tableViewPhase->setColumnWidth(i,widthTable/12);


    m_current_table_row = 0;
    m_current_table_column = 0;

    modelAveragePha = new QStandardItemModel(2,11,this);
    ui->tableViewAveragePhase->setModel(modelAveragePha);

    modelAverageMag = new QStandardItemModel(2,11,this);
    ui->tableViewAverageMag->setModel(modelAverageMag);

    modelCalibration = new QStandardItemModel(2,11,this);
    ui->tableViewCalibration->setModel(modelCalibration);

    for (int i = 0; i < 10; i++) {
        ui->tableViewAveragePhase->setColumnWidth(i,widthTable/12);
        ui->tableViewAverageMag->setColumnWidth(i,widthTable/12);
        ui->tableViewCalibration->setColumnWidth(i,widthTable/12);
    }

    for (int i = 0; i < 11; i++) {
        m_PhaseCalibration[i] = 0;
        m_MagCalibration[i] = 0;
    }

    clearTable();

}

void MainWindow::clearTable()
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 11; j++) {
            QModelIndex index = modelMag->index(i,j,QModelIndex());
            modelMag->setData(index,(double)(0.0));

            QModelIndex indexpha = modelPha->index(i,j,QModelIndex());
            modelPha->setData(indexpha,(double)(0.0));
        }
    m_current_table_column = 0;
    m_current_table_row = 0;
    ui->tableViewMag->selectRow(0);
    ui->tableViewPhase->selectRow(0);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 11; j++) {
            QModelIndex index = modelAverageMag->index(i,j,QModelIndex());
            modelAverageMag->setData(index,(double)(0.0));

            QModelIndex indexpha = modelAveragePha->index(i,j,QModelIndex());
            modelAveragePha->setData(indexpha,(double)(0.0));
        }


}

void MainWindow::updateTable(double mag, double phase)
{
    if (m_current_table_row >= 10) { //restart the circular buffer
        m_current_table_row = 0;
        ui->tableViewMag->selectRow(0);
        ui->tableViewPhase->selectRow(0);

    }

    //Update field
    QModelIndex index = modelMag->index(m_current_table_row,m_current_table_column,QModelIndex());
    modelMag->setData(index,mag);

    QModelIndex indexpha = modelPha->index(m_current_table_row,m_current_table_column,QModelIndex());
    modelPha->setData(indexpha,phase);

    m_current_table_column++;

    if (m_current_table_column == 11) {
            m_current_table_column = 0;
            m_current_table_row++;
            ui->tableViewMag->selectRow(m_current_table_row);
            ui->tableViewPhase->selectRow(m_current_table_row);

            updateStatistics();
    }
}

void MainWindow::updateStatistics()
{

    double average[11], rms[11], aux, num_samples;

    num_samples = ui->lineEditStatisticSamples->text().toDouble();


    for (int i = 0; i < 11; i++) {
        average[i] = 0;
        rms[i] = 0;
    }

    // Calculate phase Average Values
    for (int j = 0; j < 11; j++) {
        for (int i = 0; i < num_samples; i++) {
            QModelIndex indexpha = modelPha->index(i,j,QModelIndex());
            aux = modelPha->data(indexpha).toDouble();
            average[j] += (aux);
        }
    }

    for (int i = 0; i < 11; i++) {
        average[i] /= num_samples;
        //m_PhaseCalibration[i] = average[i];
    }

    for (int i = 0; i < 11; i++) {
        QModelIndex index = modelAveragePha->index(0,i,QModelIndex());
        modelAveragePha->setData(index,average[i]);
    }

    // Calculate phase RMS values
    double diff;
    for (int j = 0; j < 11; j++) {
        for (int i = 0; i < num_samples; i++) {
            QModelIndex indexpha = modelPha->index(i,j,QModelIndex());
            aux = modelPha->data(indexpha).toDouble();
            diff = aux - average[j];
            rms[j] += diff*diff;
        }
    }

    for (int i = 0; i < 11; i++) {
        rms[i] /= num_samples;
        rms[i] = sqrt(rms[i]);
    }


    for (int i = 0; i < 11; i++) {
        QModelIndex index = modelAveragePha->index(1,i,QModelIndex());
        modelAveragePha->setData(index,rms[i]);
    }

    // Calculate mag Average Values
    for (int i = 0; i < 11; i++)
        average[i] = 0;

    for (int j = 0; j < 11; j++) {
        for (int i = 0; i < num_samples; i++) {
            QModelIndex indexmag = modelMag->index(i,j,QModelIndex());
            aux = modelMag->data(indexmag).toDouble();
            average[j] += (aux);
        }
    }

    for (int i = 0; i < 11; i++) {
        average[i] /= num_samples;
   //     m_MagCalibration[i] = average[i];
    }

    for (int i = 0; i < 11; i++) {
        QModelIndex index = modelAverageMag->index(0,i,QModelIndex());
        modelAverageMag->setData(index,average[i]);
    }

    // Calculate mag rms values
    for (int j = 0; j < 11; j++) {
        for (int i = 0; i < num_samples; i++) {
            QModelIndex indexmag = modelMag->index(i,j,QModelIndex());
            aux = modelMag->data(indexmag).toDouble();
            diff = aux - average[j];
            rms[j] += diff*diff;
        }
    }

    for (int i = 0; i < 11; i++) {
        rms[i] /= num_samples;
        rms[i] = sqrt(rms[i]);
    }


    for (int i = 0; i < 11; i++) {
        QModelIndex index = modelAverageMag->index(1,i,QModelIndex());
        modelAverageMag->setData(index,rms[i]);
    }

}

void MainWindow::on_checkBoxLightTheme_toggled(bool checked)
{
    if(checked) {
        ui->widgetMagnitude->setTheme(1);
        ui->widgetPhase->setTheme(1);
    } else {
        ui->widgetMagnitude->setTheme(0);
        ui->widgetPhase->setTheme(0);
    }

    ui->widgetMagnitude->update();
    ui->widgetPhase->update();
}

void MainWindow::on_checkBoxSemilog_toggled(bool checked)
{
    if (checked) {
        double min_y = ui->lineEditMinY->text().toDouble();
        double max_y = ui->lineEditMaxY->text().toDouble();

        ui->widgetMagnitude->setYMin(min_y);
        ui->widgetMagnitude->setYMax(max_y);

        ui->widgetMagnitude->enableSemiLogPlot();

    } else {

        int numdec = ui->lineEditNumDec->text().toInt();
        double min_y_log = ui->lineEditMinYLog->text().toDouble();

        ui->widgetMagnitude->setYMinLog(min_y_log);
        ui->widgetMagnitude->setYNumDec(numdec);
        ui->widgetMagnitude->enableLogPlot();
    }

    ui->widgetMagnitude->update();
}

void MainWindow::on_comboBoxFreqs_currentIndexChanged(int index)
{
    RADIO_freq aux;
    aux.data = (quint8)index;

    ui->checkBoxF3->setChecked(aux.data_bits.F3);
    ui->checkBoxF2->setChecked(aux.data_bits.F2);
    ui->checkBoxF1->setChecked(aux.data_bits.F1);
    ui->checkBoxF0->setChecked(aux.data_bits.F0);

    m_currentFreqIndex = index;

    switch(aux.data) {
        case FREQ0:
                    m_currentFreq = STAT_FREQ0;
                    break;
        case FREQ1:
                    m_currentFreq = STAT_FREQ1;
                    break;
        case FREQ2:
                    m_currentFreq = STAT_FREQ2;
                    break;
        case FREQ3:
                    m_currentFreq = STAT_FREQ3;
                    break;
        case FREQ4:
                    m_currentFreq = STAT_FREQ4;
                    break;
        case FREQ5:
                    m_currentFreq = STAT_FREQ5;
                    break;
        case FREQ6:
                    m_currentFreq = STAT_FREQ6;
                    break;
        case FREQ7:
                    m_currentFreq = STAT_FREQ7;
                    break;
        case FREQ8:
                    m_currentFreq = STAT_FREQ8;
                    break;
        case FREQ9:
                    m_currentFreq = STAT_FREQ9;
                    break;
        case FREQ10:
                    m_currentFreq = STAT_FREQ10;
                    break;
        default:    m_currentFreq = STAT_FREQ0;
    }
}

void MainWindow::on_pushButtonSweep_clicked()
{

    //if (m_sweep_state == RUN) { //Already running!
    //    return;
   // }
    //ui->widgetMagnitude->appendPoint(10,20,1);
    m_sweep_state = RUN;
    qDebug()<<"Sweeping started, changing state to RUN";

    if (m_append == false) { // Single sweep
        ui->widgetMagnitude->setNumUsedCurves(1);
        ui->widgetMagnitude->clearCurve(0);
        ui->widgetMagnitude->update();
        ui->widgetPhase->setNumUsedCurves(1);
        ui->widgetPhase->clearCurve(0);
        ui->widgetPhase->update();
    } else { //Append sweep activated, check
        if (m_append_curve_num == 10) {//All colors have been used
            m_append_curve_num = 0;

            for (int i = 0; i < 10; i++) { //clears the curves
                ui->widgetMagnitude->clearCurve(i);
                ui->widgetPhase->clearCurve(i);
            }
        }
    }
    on_comboBoxGain_currentIndexChanged(0); //Always start from Gain 0!

    on_comboBoxFreqs_currentIndexChanged(FREQ10); //Start from low frequency
    measureImpedance();

}

void MainWindow::on_checkBoxAppend_stateChanged(int arg1)
{
    m_append = ui->checkBoxAppend->isChecked();

    for (int i = 0; i < 10; i++) { //The checkbox also clears the curves
        ui->widgetMagnitude->clearCurve(i);
        ui->widgetPhase->clearCurve(i);
    }

    ui->widgetMagnitude->update();
    ui->widgetPhase->update();

    if (m_append == true) { //reset append counter
        m_append_curve_num = 0;
        ui->widgetMagnitude->setNumUsedCurves(10);
        ui->widgetPhase->setNumUsedCurves(10);
    }
}

void MainWindow::on_comboBoxGain_currentIndexChanged(int index)
{
    RADIO_gain gain;
    gain.data = m_bioASIC.getGainBits(index);

    ui->checkBoxGD0->setChecked(gain.data_bits.GD0);
    ui->checkBoxGD1->setChecked(gain.data_bits.GD1);
    ui->checkBoxGD2->setChecked(gain.data_bits.GD2);

    ui->checkBoxGS0->setChecked(gain.data_bits.GS0);
    ui->checkBoxGS1->setChecked(gain.data_bits.GS1);
    ui->checkBoxGS2->setChecked(gain.data_bits.GS2);
    ui->checkBoxGS3->setChecked(gain.data_bits.GS3);

    m_current_gain = index;

}

void MainWindow::on_lineEditStatisticSamples_editingFinished()
{
    updateStatistics();
}

void MainWindow::on_pushButtonClearTables_clicked()
{
    clearTable();
}

void MainWindow::on_pushButtonUpdateCalibration_clicked()
{
    double aux;

    //Get phase values from statistic table and update calibration table
    for (int i = 0; i < 11; i++) {
        QModelIndex index = modelAveragePha->index(0,i,QModelIndex());
        aux = modelAveragePha->data(index).toDouble();

        QModelIndex indexCalPha = modelCalibration->index(0,i,QModelIndex());
        modelCalibration->setData(indexCalPha,aux);
        m_PhaseCalibration[i] = aux;
    }

    //Get mag values from statistics table, get calibration factor, and update calibration table

    double ref_res;

    ref_res = ui->lineEditCalRes->text().toDouble();

    for (int i = 0; i < 11; i++) {
        QModelIndex index = modelAverageMag->index(0,i,QModelIndex());
        aux = modelAverageMag->data(index).toDouble();

        aux =ref_res/aux;
        QModelIndex indexCalPha = modelCalibration->index(1,i,QModelIndex());
        modelCalibration->setData(indexCalPha,aux);
        m_MagCalibration[i] = aux;
    }


}

void MainWindow::on_pushButtonSaveCal_clicked()
{
    QString filename = "calibration.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);

        for (int i = 0; i < 11; i++) {
            stream << m_PhaseCalibration[i] << " ";
        }

        stream << "\n";

        for (int i = 0; i < 11; i++) {
            stream << m_MagCalibration[i] << " ";
        }

        stream << "\n";

    }
}

void MainWindow::on_pushButtonLoadCal_clicked()
{
    QString filename = "calibration.txt";
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<< "error opening Calibration file";
        return;
    }

    QTextStream in(&file);

    QString line = in.readLine();
    QStringList phase = line.split(" ");

    line = in.readLine();
    QStringList mag = line.split(" ");

    QString aux;
    //Get phase values from statistic table and update calibration table
    for (int i = 0; i < 11; i++) {
        //QModelIndex index = modelAveragePha->index(0,i,QModelIndex());
        //aux = modelAveragePha->data(index).toDouble();

        aux = phase.at(i);

        QModelIndex indexCalPha = modelCalibration->index(0,i,QModelIndex());
        modelCalibration->setData(indexCalPha,aux);
        m_PhaseCalibration[i] = aux.toDouble();
    }

    //Get mag values from statistics table, get calibration factor, and update calibration table

    double ref_res;
    ref_res = ui->lineEditCalRes->text().toDouble();

    for (int i = 0; i < 11; i++) {
      //  QModelIndex index = modelAverageMag->index(0,i,QModelIndex());
      //  aux = modelAverageMag->data(index).toDouble();

        aux =mag.at(i);
        QModelIndex indexCalPha = modelCalibration->index(1,i,QModelIndex());
        modelCalibration->setData(indexCalPha,aux);
        m_MagCalibration[i] = aux.toDouble();
    }

}
