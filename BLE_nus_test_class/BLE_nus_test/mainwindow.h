#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QBluetoothDeviceDiscoveryAgent>
//#include <QtBluetooth/qbluetoothdevicediscoveryagent.h>
#include <QBluetoothDeviceInfo>
#include <QLowEnergyController>
#include <QLowEnergyService>
#include "deviceinfo.h"

#include "bleclient.h"

//Bluetooth UUID
#define UARTSERVICEUUID "6e400001-b5a3-f393-e0a9-e50e24dcca9e"
#define RXUUID "6e400002-b5a3-f393-e0a9-e50e24dcca9e"
#define TXUUID "6e400003-b5a3-f393-e0a9-e50e24dcca9e"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    /* Slots for BLE */
    void deviceFound(QString device);
    void rxData(const QByteArray &data);
    void updateBLEstatus(QString &status);

    void on_pushButtonDiscover_clicked();

    void on_pushButtonConnect_clicked();

    void on_pushButtonSend_clicked();

    void on_pushButtonDisconnect_clicked();

private:
    Ui::MainWindow *ui;

    BLEClient *m_ble;
    bluetoothleState m_state;



};
#endif // MAINWINDOW_H
