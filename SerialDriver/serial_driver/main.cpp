#include <QCoreApplication>
#include <QtDebug>
#include <QtSerialPort/QSerialPortInfo>
#include <QTime>

#include "cserialdriver.h"

void delay( int millisecondsToWait );

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    //Obtain information about the available serial ports:
    QList<QSerialPortInfo> serialPortInfos = QSerialPortInfo::availablePorts();
    int num = serialPortInfos.count(); //Number of available serial ports
    qDebug("number of items = %d",num);
    for (int i = 0; i < num; i++)
        qDebug() << serialPortInfos[i].portName(); // Name of each serial port

    //Create a QSerial port object and open it
    QSerialPort serialPort;
    serialPort.setPortName(serialPortInfos[1].portName());
    serialPort.setBaudRate(QSerialPort::Baud9600);

    serialPort.open(QIODevice::ReadWrite);

    //Create a CSerial driver object and pass the opened serial port
    CSerialDriver myserial(&serialPort);

    //send and receive

    QByteArray writeData("this is a test");

    int count = 10;

    while(count--){
        myserial.write(writeData);
        delay(200);
    }


    return a.exec();
}

void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
