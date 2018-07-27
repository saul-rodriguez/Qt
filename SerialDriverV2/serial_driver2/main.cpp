#include <QCoreApplication>
#include "cserialdriver.h"
#include <QTime>

void delay( int millisecondsToWait );

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data("test");

    CSerialDriver m_serial_port;
    QStringList ports = m_serial_port.getAvailableSerialPorts();

    QString pname = ports[0];
    int ret = m_serial_port.openSerialPort(pname,QSerialPort::Baud9600);
    if (ret) {
        for (int i=0; i < 10; i++){
            m_serial_port.write(data);
            delay(200);
        }
    }

    m_serial_port.closeSerialPort();

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

