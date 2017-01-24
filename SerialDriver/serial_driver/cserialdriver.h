#ifndef CSERIALDRIVER_H
#define CSERIALDRIVER_H

#include <QObject>

#include <QtSerialPort/QSerialPort>
#include <QTimer>
#include <QByteArray>

class CSerialDriver : public QObject
{
    Q_OBJECT
public:
    explicit CSerialDriver(QSerialPort *serialPort, QObject *parent = 0);

    void write(const QByteArray &writeData);

signals:

    void RxAvailable(const QByteArray &Data);

public slots:

private slots:
    void handleBytesWritten(qint64 bytes);
    void handleTimeout();
    void handleError(QSerialPort::SerialPortError error);

    void handleReadyRead();

private:
    QSerialPort     *m_serialPort;
    QByteArray      m_writeData;
    //QTextStream     m_standardOutput;
    qint64          m_bytesWritten;
    QTimer          m_timer;

    QByteArray      m_readData;
    qint8           m_readState;
    int             m_timeout;

};

#endif // CSERIALDRIVER_H
