#include "btclient.h"

BTClient::BTClient(QObject *parent) : QObject(parent)
{
    agent = new QBluetoothDeviceDiscoveryAgent; // create an object in ctors
    connect(agent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(BTdeviceDiscovered(QBluetoothDeviceInfo)));
    agent->start();

    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(BTrxTimeOut()));
    m_RX_timeout = RX_TIMEOUT;
    m_RX_state = btRxState::BT_IDLE;

}

BTClient::~BTClient()
{
    BTstopClient();
}

void BTClient::BTdeviceDiscovered(const QBluetoothDeviceInfo &device)
{
    QString aux;
    aux = device.address().toString()+ " " + device.name();

    emit BTnewDeviceDiscovered(aux); //Send Signal
}

void BTClient::BTfindDevices()
{
    agent->stop();
    agent->start();
}

void BTClient::BTconnect(QString name)
{
    BtDevice = name;
    QString BTaddress;
    BTaddress = BtDevice.split(" ").at(0);
    static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));

    /*if (socket) { //There is a socket already opened!
        return;
    }*/

    socket->connectToService(QBluetoothAddress(BTaddress), QBluetoothUuid(serviceUuid));

    connect(socket, SIGNAL(readyRead()), this, SLOT(BTread()));
    connect(socket, SIGNAL(connected()), this, SLOT(BTconnected()));
   // connect(socket, SIGNAL(disconnected()), this, SIGNAL(disconnected()));

}

void BTClient::BTconnected()
{
    emit BTnewDeviceConnected(BtDevice);
}

void BTClient::BTstopClient()
{
    delete socket;
    socket = 0;
}

void BTClient::BTwrite(const QByteArray &data)
{
    socket->write(data);
}

void BTClient::BTsetRxTimeout(int timeout)
{
    m_RX_timeout = timeout;
}

void BTClient::BTread()
{
    m_timer->stop();

    QByteArray data;
    data = socket->readAll();

    qDebug()<<"received :" + QString::number(data.count());

    switch (m_RX_state) {
        case btRxState::BT_IDLE :
            m_rxData.clear();
            m_rxData.append(data);
            m_RX_state = btRxState::BT_RX;
            m_timer->start(m_RX_timeout);
            break;

        case btRxState::BT_RX :
            m_rxData.append(data);
            m_timer->start(m_RX_timeout);
            break;
        default:
            break;
    }
}

void BTClient::BTrxTimeOut()
{
    m_timer->stop();
    m_RX_state = btRxState::BT_IDLE;

    qDebug()<<"Rx timeout!";


    emit BTrxData(m_rxData);
}
