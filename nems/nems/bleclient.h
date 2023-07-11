#ifndef BLECLIENT_H
#define BLECLIENT_H

#include <QObject>

#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>
#include <QLowEnergyController>
#include <QLowEnergyService>

#include "deviceinfo.h"

//Bluetooth UUID
#define UARTSERVICEUUID "6e400001-b5a3-f393-e0a9-e50e24dcca9e"
#define RXUUID "6e400002-b5a3-f393-e0a9-e50e24dcca9e"
#define TXUUID "6e400003-b5a3-f393-e0a9-e50e24dcca9e"

enum bluetoothleState {
        Idle = 0,
        Scanning,
        ScanFinished,
        Connecting,
        Connected,
        ServiceFound,
        AcquireData
};

class BLEClient : public QObject
{
    Q_OBJECT
public:
    explicit BLEClient(QObject *parent = nullptr);
    ~BLEClient();

    void discover();
    void BLEconnect(int index);
    void BLEdisconnect();
    void write(const QByteArray &data);

private slots:

    // Slots for QBluetothDeviceDiscoveryAgent
    void addDevice(const QBluetoothDeviceInfo &device);
    void scanError(QBluetoothDeviceDiscoveryAgent::Error error);
    void scanFinished();

    /* Slots for QLowEnergyController */
    void serviceDiscovered(const QBluetoothUuid &gatt);
    void serviceScanDone();
    void controllerError(QLowEnergyController::Error newError);
    void deviceConnected();
    void deviceDisconnected();

    /* Slots for QlowEnergyService*/
    void serviceStateChanged(QLowEnergyService::ServiceState s);
    void updateData(const QLowEnergyCharacteristic &c, const QByteArray &value);
    void confirmedDescriptorWrite(const QLowEnergyDescriptor &d, const QByteArray &value);

signals:
    void deviceFound(QString device);
    void rxData(const QByteArray &data);    
    void BLEupdateStatus(QString &status);

private:

    DeviceInfo *m_currentDevice;
    QBluetoothDeviceDiscoveryAgent *m_deviceDiscoveryAgent;

    QList<QObject*> m_qlDevices;
    QList<QString> m_qlFoundDevices;

    QLowEnergyController *m_control;
    QLowEnergyService *m_service;
    QLowEnergyDescriptor m_notificationDescTx;
    QLowEnergyService *m_UARTService;

    bluetoothleState m_state;

};

#endif // BLECLIENT_H
