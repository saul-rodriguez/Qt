#include "cserialdriver.h"

#include <QtDebug>

#define IDLE 0
#define RECEIVING 1

CSerialDriver::CSerialDriver(QSerialPort *serialPort, QObject *parent) : QObject(parent)
{
    m_serialPort = serialPort;
    m_bytesWritten = 0;

    m_readState = IDLE;
    m_timeout = 45; //ms

    m_timer.setSingleShot(true);
    connect(m_serialPort, &QSerialPort::bytesWritten, this, &CSerialDriver::handleBytesWritten);
    connect(m_serialPort, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &CSerialDriver::handleError);
    connect(m_serialPort, &QSerialPort::readyRead, this, &CSerialDriver::handleReadyRead);
    connect(&m_timer, &QTimer::timeout, this, &CSerialDriver::handleTimeout);
}


void CSerialDriver::handleBytesWritten(qint64 bytes)
{
    m_bytesWritten += bytes;
    if (m_bytesWritten == m_writeData.size()) {
        m_bytesWritten = 0;
        //m_standardOutput << QObject::tr("Data successfully sent to port %1").arg(m_serialPort->portName()) << endl;
        //QCoreApplication::quit();
        qDebug()<<"Data successfully transmitted to port: " << m_serialPort->portName();

    }
}

void CSerialDriver::handleTimeout()
{
    //m_standardOutput << QObject::tr("Operation timed out for port %1, error: %2").arg(m_serialPort->portName()).arg(m_serialPort->errorString()) << endl;
    //qDebug() << "Serial transmission has time out for port: " << m_serialPort->portName();
    //QCoreApplication::exit(1);

    QString data = QString::fromUtf8(m_readData.constData());
    qDebug()<<"read: "<<data;

    //TODO: Here a signal should be send with the received data
    RxAvailable(m_readData); //signal

    m_readData.clear();
    m_readState = IDLE;
}

void CSerialDriver::handleError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::WriteError) {
        qDebug() << "An I/O error occurred while writing the data to port: " << m_serialPort->portName();
        //QCoreApplication::exit(1);
    }
}

void CSerialDriver::handleReadyRead()
{
    if (m_readState == IDLE) {
        m_readState = RECEIVING;
    }

    m_readData.append(m_serialPort->readAll());

    m_timer.start(m_timeout);
      // if (!m_timer.isActive())
      //     m_timer.start(5000);
}


void CSerialDriver::write(const QByteArray &writeData)
{
    m_writeData = writeData;

    qint64 bytesWritten = m_serialPort->write(writeData);

    qDebug()<< "entering transmission";

    if (bytesWritten == -1) {
        //m_standardOutput << QObject::tr("Failed to write the data to port %1, error: %2").arg(m_serialPort->portName()).arg(m_serialPort->errorString()) << endl;
        //QCoreApplication::exit(1);
        qDebug() << "Failed to write data to port: " << m_serialPort->portName() << " error: " << m_serialPort->errorString();
    } else if (bytesWritten != m_writeData.size()) {
        //m_standardOutput << QObject::tr("Failed to write all the data to port %1, error: %2").arg(m_serialPort->portName()).arg(m_serialPort->errorString()) << endl;
        qDebug() << "Failed to write data to port: " << m_serialPort->portName() << " error: " << m_serialPort->errorString();
        //QCoreApplication::exit(1);
    }

    //m_timer.start(5000);
}

