#include "bleclient.h"

BLEClient::BLEClient(QObject *parent)
    : QObject{parent}
{
    m_deviceDiscoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    m_deviceDiscoveryAgent->setLowEnergyDiscoveryTimeout(1500);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &BLEClient::addDevice);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::errorOccurred,
            this, &BLEClient::scanError);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &BLEClient::scanFinished);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::canceled,
            this, &BLEClient::scanFinished);

    //Set up BLE
    m_currentDevice = new DeviceInfo(QBluetoothDeviceInfo());
    m_control = 0;
    m_service = 0;
    m_state = Idle;
}

BLEClient::~BLEClient()
{
    m_control->disconnectFromDevice();
    delete m_service;
    m_service = 0;
}

void BLEClient::discover()
{

   // ui->comboBoxDevices->clear();

    //Start Scan
    qDeleteAll(m_qlDevices);
    m_qlDevices.clear();

    m_qlFoundDevices.clear();

    m_deviceDiscoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
    qDebug()<<"Searching for low energy devices...";

    m_state = Scanning;
}

void BLEClient::BLEconnect(int index)
{
    //int i = ui->comboBoxDevices->currentIndex();
    DeviceInfo *aux = (DeviceInfo*)m_qlDevices.at(index);
    qDebug()<<"Selected device: "<<aux->getName();

    m_currentDevice->setDevice(aux->getDevice());

    qDebug()<<"pass";

    //Release controller if already started
    if (m_control) {
            m_control->disconnectFromDevice();
            delete m_control;
            m_control = 0;
    }

    //Create a BLE controller

    m_control = QLowEnergyController::createCentral(m_currentDevice->getDevice(), this);
    //m_control ->setRemoteAddressType(QLowEnergyController::RandomAddress);

    connect(m_control, &QLowEnergyController::serviceDiscovered,
            this, &BLEClient::serviceDiscovered);
    connect(m_control, &QLowEnergyController::discoveryFinished,
            this, &BLEClient::serviceScanDone);

    connect(m_control, &QLowEnergyController::errorOccurred,
            this, &BLEClient::controllerError);

    connect(m_control, &QLowEnergyController::connected,
            this, &BLEClient::deviceConnected);

    connect(m_control, &QLowEnergyController::disconnected,
            this, &BLEClient::deviceDisconnected);

    //Connect to device
    m_control->connectToDevice();

    m_state = Connecting;
    qDebug() << "Connecting";

    QString stat = "Connecting";
    emit BLEupdateStatus(stat);

}

void BLEClient::BLEdisconnect()
{
    m_control->disconnectFromDevice();
    delete m_service;
    m_service = 0;

    QString stat = "Disconnecting";
    emit BLEupdateStatus(stat);
}

void BLEClient::write(const QByteArray &data)
{
    //QString aux;
    //aux = ui->lineEditMessage->text();

    //QByteArray Data;
    //Data.append(aux.toUtf8());

    const QLowEnergyCharacteristic  RxChar = m_service->characteristic(QBluetoothUuid(QUuid(RXUUID)));
    m_service->writeCharacteristic(RxChar, data,QLowEnergyService::WriteWithoutResponse);

}

void BLEClient::addDevice(const QBluetoothDeviceInfo &device)
{
    if (device.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration) {
        qDebug()<<"BLE device: "<<device.name()<<" address: "<<device.address().toString();
        DeviceInfo *dev = new DeviceInfo(device);
        m_qlDevices.append(dev);

        //TODO: Send a signal with new device name
        //ui->comboBoxDevices->addItem(dev->getName());
        emit deviceFound(dev->getName());

    } else {
        qDebug()<<"Other found";
    }

}

void BLEClient::scanError(QBluetoothDeviceDiscoveryAgent::Error error)
{
    if (error == QBluetoothDeviceDiscoveryAgent::PoweredOffError)
           qDebug() << "The Bluetooth adaptor is powered off, power it on before doing discovery.";
       else if (error == QBluetoothDeviceDiscoveryAgent::InputOutputError)
           qDebug() << "Writing or reading from the device resulted in an error.";
       else
           qDebug() << "An unknown error has occurred.";
}

void BLEClient::scanFinished()
{
    if (m_qlDevices.size() == 0)
       {
           qDebug() << "No Low Energy devices found";
       }
       else
       {
           for (int i = 0; i < m_qlDevices.size(); i++) {
              m_qlFoundDevices.append(((DeviceInfo*) m_qlDevices.at(i))->getName());
           }

    }
    qDebug()<<"Scan finished";
    m_state = ScanFinished;
}

void BLEClient::serviceDiscovered(const QBluetoothUuid &gatt)
{
    if(gatt==QBluetoothUuid(QUuid(UARTSERVICEUUID))){
          //m_bFoundUARTService =true;
          qDebug() << "UART service found!";
          m_state = ServiceFound;
      }
}

void BLEClient::serviceScanDone()
{
    qDebug()<<"Service scan done";

    delete m_service;
    m_service=0;

    if (m_state == ServiceFound) {
        qDebug() << "Connecting to UART service";

        m_service = m_control->createServiceObject(QBluetoothUuid(QUuid(UARTSERVICEUUID)),this);
    }

    if(!m_service){
        qDebug() <<"UART service not found";
        return;
    }

    connect(m_service, &QLowEnergyService::stateChanged,
            this, &BLEClient::serviceStateChanged);
    connect(m_service, &QLowEnergyService::characteristicChanged,
            this, &BLEClient::updateData);
    connect(m_service, &QLowEnergyService::descriptorWritten,
            this, &BLEClient::confirmedDescriptorWrite);

    m_service->discoverDetails();
    m_state = ServiceFound;


}

void BLEClient::controllerError(QLowEnergyController::Error newError)
{
    qDebug()<<"Controller error";

    QString stat = "Controller Error";
    emit BLEupdateStatus(stat);
}

void BLEClient::deviceConnected()
{
    qDebug()<<"Device connected";

    QString stat = "Connected";
    emit BLEupdateStatus(stat);

    //Discover services
    m_control->discoverServices();

}

void BLEClient::deviceDisconnected()
{
    qDebug()<<"Device disconnected";

    QString stat = "Disconnected";
    emit BLEupdateStatus(stat);
}

void BLEClient::serviceStateChanged(QLowEnergyService::ServiceState s)
{
    switch (s) {
        case QLowEnergyService::RemoteServiceDiscovered:
        {
            qDebug()<<"Discovered service";

            //looking for the TX characteristic
            const QLowEnergyCharacteristic TxChar = m_service->characteristic(QBluetoothUuid(QUuid(TXUUID)));
            if (!TxChar.isValid()){
                qDebug() << "Tx characteristic not found";
                break;
            }

             //looking for the RX characteristic
            const QLowEnergyCharacteristic  RxChar = m_service->characteristic(QBluetoothUuid(QUuid(RXUUID)));
            if (!RxChar.isValid()) {
               qDebug() << "Rx characteristic not found";
                break;
            }

           // Looking for Tx characteristic descriptor and use it to enable notifications on the client
           m_notificationDescTx = TxChar.descriptor(
                       QBluetoothUuid::DescriptorType::ClientCharacteristicConfiguration);
            if (m_notificationDescTx.isValid()) {
                // enable notification
                m_service->writeDescriptor(m_notificationDescTx, QByteArray::fromHex("0100"));
                //setState(AcquireData);
                m_state = AcquireData;
                qDebug()<<"Tx Descriptor write, notification enabled, acquiring data";
            }

            break;
        }
        default:
            //nothing for now
            break;
        }
}

void BLEClient::updateData(const QLowEnergyCharacteristic &c, const QByteArray &value)
{
    if (c.uuid() != QBluetoothUuid(QUuid(TXUUID)))
              return;
    //TODO: send a signal with received data

    //ui->labelReceived->setText(aux);

    QString aux;
    aux = QString::fromStdString(value.toStdString());
    qDebug()<<"Tx message: "<< aux;

    emit rxData(value);
}

void BLEClient::confirmedDescriptorWrite(const QLowEnergyDescriptor &d, const QByteArray &value)
{
    if (d.isValid() && d == m_notificationDescTx && value == QByteArray("0000")) {
           //disabled notifications -> assume disconnect intent
           m_control->disconnectFromDevice();
           delete m_service;
           m_service = 0;
       }
    qDebug()<<"Tx Descriptor written";
}

