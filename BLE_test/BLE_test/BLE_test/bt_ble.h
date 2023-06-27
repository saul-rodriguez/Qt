#ifndef BT_BLE_H
#define BT_BLE_H

#include <QObject>
#include <qbluetoothlocaldevice.h>
#include <QBluetoothServiceDiscoveryAgent>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QLowEnergyController>
#include <QBluetoothServiceInfo>

class BT_BLE : public QObject
{
    Q_OBJECT
public:
    explicit BT_BLE(QObject *parent = nullptr);

    void discover();
    void addDevice(const QBluetoothDeviceInfo &info);
    void deviceScanError(QBluetoothDeviceDiscoveryAgent::Error error);
    void deviceScanFinished();
    //void error

signals:


private:
   QBluetoothDeviceDiscoveryAgent *discoveryAgent;
  // DeviceInfo currentDevice;
};

#endif // BT_BLE_H
