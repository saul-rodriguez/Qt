#ifndef BTCLIENT_H
#define BTCLIENT_H

#include <QObject>


#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothSocket>
#include <QDataStream>
#include <QTimer>

typedef enum  {
    BT_IDLE,
    BT_RX,
    BT_READY
} btRxState;

#define RX_TIMEOUT 25

class BTClient : public QObject
{
    Q_OBJECT
public:
    explicit BTClient(QObject *parent = nullptr);
    ~BTClient();

signals:
    void BTnewDeviceDiscovered(QString name); //emitted when new device is discovered
    void BTnewDeviceConnected(QString name); //emitted after a device was connected
    void BTrxData(const QByteArray &data); //emitted when new data is received

private slots:
    void BTdeviceDiscovered(const QBluetoothDeviceInfo &device);
    void BTconnected();
    void BTread();
    void BTrxTimeOut();

public:
    void BTfindDevices(); //Discover active devices in the vecinity
    void BTconnect(QString name); //Connect to one device
    void BTdisconnect(); //Disconnect

    void BTstopClient();
    void BTwrite(const QByteArray &data); //write to the connected BT device
    void BTsetRxTimeout(int timeout);

private:
    QBluetoothDeviceDiscoveryAgent *agent;
    QBluetoothSocket *socket;
    QString BtDevice;

    quint32 m_RX_state;
    int m_RX_timeout;
    QTimer *m_timer;
    QByteArray m_rxData;

};

#endif // BTCLIENT_H
