#include "bt_ble.h"
#include <QDebug>

BT_BLE::BT_BLE(QObject *parent)
    : QObject{parent}
{

}

void BT_BLE::discover()
{
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
    discoveryAgent->setLowEnergyDiscoveryTimeout(25000);

    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &BT_BLE::addDevice);

    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::errorOccurred,
            this, &BT_BLE::deviceScanError);

    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &BT_BLE::deviceScanFinished);

    discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);

}

void BT_BLE::addDevice(const QBluetoothDeviceInfo &info)
{
    qDebug()<<"add Device";
}

void BT_BLE::deviceScanError(QBluetoothDeviceDiscoveryAgent::Error error)
{
    qDebug()<<"scan error";
}

void BT_BLE::deviceScanFinished()
{
    qDebug()<<"scan finished";
}


