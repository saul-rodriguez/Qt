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

void MainWindow::on_pushButtonRefresh_clicked()
{
    readPorts();
}

void MainWindow::on_pushButtonTx_clicked()
{
    QString aux;
    aux = ui->lineEdit->text();

    QByteArray writedata(aux.toUtf8());

    myserial->write(writedata);

}

void MainWindow::SerialRx(const QByteArray &Data)
{
    QString aux;
    aux = QString::fromUtf8(Data.constData());

    ui->plainTextEditRx->appendPlainText(aux);

}

void MainWindow::on_pushButtonConnect_clicked()
{
    QString aux;
    aux = ui->comboBoxPorts->currentText();

    //serialPort.setPortName(serialPortInfos[1].portName());
    serialPort.setPortName(aux);
    serialPort.setBaudRate(QSerialPort::Baud9600);

    serialPort.open(QIODevice::ReadWrite);

    //myserial = new CSerialDriver(&serialPort);
}
