#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    m_bt = new BTClient(this);
    connect(m_bt, SIGNAL(BTnewDeviceDiscovered(QString)),
            this, SLOT(getBTdevice(QString)));
    connect(m_bt, SIGNAL(BTnewDeviceConnected(QString)),
            this, SLOT(bluetoothConnected(QString)));
    connect(m_bt, SIGNAL(BTrxData(QByteArray)),
            this, SLOT(rxData(const QByteArray)));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getBTdevice(QString name)
{
    qDebug()<< name;
    ui->comboBox->addItem(name);
}

void MainWindow::bluetoothConnected(QString name)
{
    qDebug()<< "Connected to: " + name;
}

void MainWindow::rxData(const QByteArray &data)
{
    ui->plainTextEdit->appendPlainText(QString::fromStdString(data.toStdString()));
}

void MainWindow::on_pushButtonDiscoverBT_clicked()
{
    m_bt->BTfindDevices();
}

void MainWindow::on_pushButtonConnect_clicked()
{
    QString name;
    name = ui->comboBox->currentText();

    m_bt->BTconnect(name);
}

void MainWindow::on_pushButtonSend_clicked()
{
    QString aux = ui->lineEdit->text();

    QByteArray data;
    data.append(aux);
    //data.append('\r');
    //data.append('\n');

    m_bt->BTwrite(data);

}
