#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_deviceDiscoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    m_deviceDiscoveryAgent->setLowEnergyDiscoveryTimeout(1500);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &MainWindow::addDevice);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::errorOccurred,
            this, &MainWindow::scanError);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &MainWindow::scanFinished);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::canceled,
            this, &MainWindow::scanFinished);

    //Set up BLE
    m_currentDevice = new DeviceInfo(QBluetoothDeviceInfo());
    m_control = 0;
    m_service = 0;
    m_state = Idle;


}

MainWindow::~MainWindow()
{
    m_control->disconnectFromDevice();
    delete m_service;
    m_service = 0;

    delete ui;
}

void MainWindow::addDevice(const QBluetoothDeviceInfo &device)
{
    if (device.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration) {
        qDebug()<<"BLE device: "<<device.name()<<" address: "<<device.address().toString();
        DeviceInfo *dev = new DeviceInfo(device);
        m_qlDevices.append(dev);

        ui->comboBoxDevices->addItem(dev->getName());

    } else {
        qDebug()<<"Other found";
    }

}

void MainWindow::scanError(QBluetoothDeviceDiscoveryAgent::Error error)
{
    if (error == QBluetoothDeviceDiscoveryAgent::PoweredOffError)
           qDebug() << "The Bluetooth adaptor is powered off, power it on before doing discovery.";
       else if (error == QBluetoothDeviceDiscoveryAgent::InputOutputError)
           qDebug() << "Writing or reading from the device resulted in an error.";
       else
           qDebug() << "An unknown error has occurred.";
}

void MainWindow::scanFinished()
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

void MainWindow::serviceDiscovered(const QBluetoothUuid &gatt)
{
    if(gatt==QBluetoothUuid(QUuid(UARTSERVICEUUID))){
          //m_bFoundUARTService =true;
          qDebug() << "UART service found!";
          m_state = ServiceFound;
      }
}

void MainWindow::serviceScanDone()
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
            this, &MainWindow::serviceStateChanged);
    connect(m_service, &QLowEnergyService::characteristicChanged,
            this, &MainWindow::updateData);
    connect(m_service, &QLowEnergyService::descriptorWritten,
            this, &MainWindow::confirmedDescriptorWrite);

    m_service->discoverDetails();
    m_state = ServiceFound;


}

void MainWindow::controllerError(QLowEnergyController::Error newError)
{
    qDebug()<<"Controller error";
}

void MainWindow::deviceConnected()
{
    qDebug()<<"Device connected";

    //Discover services
    m_control->discoverServices();
}

void MainWindow::deviceDisconnected()
{
    qDebug()<<"Device disconnected";
}

void MainWindow::serviceStateChanged(QLowEnergyService::ServiceState s)
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

void MainWindow::updateData(const QLowEnergyCharacteristic &c, const QByteArray &value)
{
    if (c.uuid() != QBluetoothUuid(QUuid(TXUUID)))
              return;

    QString aux;
    aux = QString::fromStdString(value.toStdString());
    ui->labelReceived->setText(aux);
    qDebug()<<"Tx message: "<< aux;
}

void MainWindow::confirmedDescriptorWrite(const QLowEnergyDescriptor &d, const QByteArray &value)
{
    if (d.isValid() && d == m_notificationDescTx && value == QByteArray("0000")) {
           //disabled notifications -> assume disconnect intent
           m_control->disconnectFromDevice();
           delete m_service;
           m_service = 0;
       }
    qDebug()<<"Tx Descriptor written";
}


void MainWindow::on_pushButtonDiscover_clicked()
{

    ui->comboBoxDevices->clear();

    //Start Scan
    qDeleteAll(m_qlDevices);
    m_qlDevices.clear();

    m_qlFoundDevices.clear();

    m_deviceDiscoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
    qDebug()<<"Searching for low energy devices...";

    m_state = Scanning;
}


void MainWindow::on_pushButtonConnect_clicked()
{
    int i = ui->comboBoxDevices->currentIndex();
    DeviceInfo *aux = (DeviceInfo*)m_qlDevices.at(i);
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
            this, &MainWindow::serviceDiscovered);
    connect(m_control, &QLowEnergyController::discoveryFinished,
            this, &MainWindow::serviceScanDone);

    connect(m_control, &QLowEnergyController::errorOccurred,
            this, &MainWindow::controllerError);

    connect(m_control, &QLowEnergyController::connected,
            this, &MainWindow::deviceConnected);

    connect(m_control, &QLowEnergyController::disconnected,
            this, &MainWindow::deviceDisconnected);

    //Connect to device
    m_control->connectToDevice();

    m_state = Connecting;
    qDebug() << "Connecting";

}


void MainWindow::on_pushButtonSend_clicked()
{
    QString aux;
    aux = ui->lineEditMessage->text();

    QByteArray Data;
    Data.append(aux.toUtf8());

    const QLowEnergyCharacteristic  RxChar = m_service->characteristic(QBluetoothUuid(QUuid(RXUUID)));
    m_service->writeCharacteristic(RxChar, Data,QLowEnergyService::WriteWithoutResponse);

}


void MainWindow::on_pushButtonDisconnect_clicked()
{
    m_control->disconnectFromDevice();
    delete m_service;
    m_service = 0;
}

