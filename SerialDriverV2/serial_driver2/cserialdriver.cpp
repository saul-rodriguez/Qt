#include "cserialdriver.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QtDebug>

#define IDLE 0
#define RECEIVING 1

CSerialDriver::CSerialDriver(QObject *parent) : QObject(parent)
{
    //m_serialPort = serialPort;
    m_bytesWritten = 0;

    m_readState = IDLE;
    m_timeout = 45; //ms

    m_timer.setSingleShot(true);
    //signal emitted when a payload data has been written
    connect(&m_serialPort, &QSerialPort::bytesWritten, this, &CSerialDriver::handleBytesWritten);

    // Handle errors
    connect(&m_serialPort,&QSerialPort::errorOccurred,this, &CSerialDriver::handleError);

    //signal emitted when data arrived
    connect(&m_serialPort, &QSerialPort::readyRead, this, &CSerialDriver::handleReadyRead);

    //Timeout for Rx
    connect(&m_timer, &QTimer::timeout, this, &CSerialDriver::handleTimeout);
}


void CSerialDriver::handleBytesWritten(qint64 bytes)
{
    m_bytesWritten += bytes;
    if (m_bytesWritten == m_writeData.size()) {
        m_bytesWritten = 0;

        qDebug()<<"Data successfully transmitted to port: " << m_serialPort.portName();

    }
}

void CSerialDriver::handleTimeout()
{
    QString data = QString::fromUtf8(m_readData.constData());
    qDebug()<<"read data: "<<data;

    //TODO: Here a signal should be send with the received data
    RxAvailable(m_readData); //signal

    m_readData.clear();
    m_readState = IDLE;
}

void CSerialDriver::handleError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::NoError)
        return;

    qDebug()<<"serial port error # "<<serialPortError;

    /*
    if (serialPortError == QSerialPort::WriteError) {
        qDebug() << "An I/O error occurred while writing the data to port: " << m_serialPort.portName();
        //QCoreApplication::exit(1);
    }*/
}

void CSerialDriver::handleReadyRead()
{
    if (m_readState == IDLE) { //Change the state to receiving
        m_readState = RECEIVING;
    }

    m_readData.append(m_serialPort.readAll());

    m_timer.start(m_timeout);      
}


void CSerialDriver::write(const QByteArray &writeData)
{
    m_writeData = writeData;

    qint64 bytesWritten = m_serialPort.write(writeData);

    qDebug()<< "entering transmission";

    if (bytesWritten == -1) {
        //m_standardOutput << QObject::tr("Failed to write the data to port %1, error: %2").arg(m_serialPort->portName()).arg(m_serialPort->errorString()) << endl;       
        qDebug() << "Failed to write data to port: " << m_serialPort.portName() << " error: " << m_serialPort.errorString();
    } else if (bytesWritten != m_writeData.size()) {
        //m_standardOutput << QObject::tr("Failed to write all the data to port %1, error: %2").arg(m_serialPort->portName()).arg(m_serialPort->errorString()) << endl;
        qDebug() << "Failed to write data to port: " << m_serialPort.portName() << " error: " << m_serialPort.errorString();
    }

}

QStringList CSerialDriver::getAvailableSerialPorts()
{

    QList<QSerialPortInfo> serialports = QSerialPortInfo::availablePorts();
    int n = serialports.count();

    QStringList ports;
    for (int i = 0; i<n; i++)
        ports.append(serialports[i].portName());

    return ports;

}

int CSerialDriver::openSerialPort(QString name, qint32 baudrate)
{
    m_serialPort.setPortName(name);
    m_serialPort.setBaudRate(baudrate);
    if (m_serialPort.open(QIODevice::ReadWrite)) {
        qDebug()<<"serial port successfully opened";
        return 1;
    } else {
        qDebug()<<"serial port failed to open";
        return 0;
    }

}

void CSerialDriver::closeSerialPort()
{
    if (m_serialPort.isOpen())
        m_serialPort.close();
}

