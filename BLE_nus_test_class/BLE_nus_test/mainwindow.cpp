#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_ble = new BLEClient(this);
    connect(m_ble, &BLEClient::deviceFound, this, &MainWindow::deviceFound);
    connect(m_ble, &BLEClient::rxData, this, &MainWindow::rxData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::deviceFound(QString device)
{
    ui->comboBoxDevices->addItem(device);
}

void MainWindow::rxData(const QByteArray &data)
{
    QString aux;
    aux = QString::fromStdString(data.toStdString());
    ui->labelReceived->setText(aux);
}


void MainWindow::on_pushButtonDiscover_clicked()
{

    ui->comboBoxDevices->clear();
    m_ble->discover();
}


void MainWindow::on_pushButtonConnect_clicked()
{
    int index = ui->comboBoxDevices->currentIndex();
    m_ble->BLEconnect(index);
}


void MainWindow::on_pushButtonSend_clicked()
{
    QString aux;
    aux = ui->lineEditMessage->text();

    QByteArray Data;
    Data.append(aux.toUtf8());

    m_ble->write(Data);
}


void MainWindow::on_pushButtonDisconnect_clicked()
{
    m_ble->BLEdisconnect();
}

