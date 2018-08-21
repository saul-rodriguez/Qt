#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set default values for server IP address and listening port
    ui->lineEdit_IPaddress->setText("192.168.0.16");
    ui->lineEdit_port->setText("80");

    //Connect tcp socket signals to slots
    tcpSocket = new QTcpSocket(this);

    //Attach a datastream to the socket
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_5_11);

    connect(tcpSocket, SIGNAL(readyRead()),this, SLOT(readSocket()));
    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
               this, &MainWindow::displayError);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_connect_clicked()
{
    QString address = ui->lineEdit_IPaddress->text();
    QString port = ui->lineEdit_port->text();

    ui->plainTextEdit_log->appendPlainText("Connecting...");


    tcpSocket->connectToHost(address,port.toInt());


    if(!tcpSocket->waitForConnected(5000)) {
           QString aux = "Error connecting: " + tcpSocket->errorString();
           ui->plainTextEdit_log->appendPlainText(aux);
           return;
    }

    ui->plainTextEdit_log->appendPlainText("Connected");

}

void MainWindow::on_pushButton_disconnect_clicked()
{
    ui->plainTextEdit_log->appendPlainText("Disconnecting...");
    tcpSocket->disconnectFromHost();;
}

void MainWindow::on_pushButton_send_clicked()
{
    QString aux = ui->lineEdit_message->text();
    QByteArray data;
    data.append(aux);
    data.append('\r');
    data.append('\n');

    tcpSocket->write(data);
}

void MainWindow::readSocket()
{
    in.startTransaction();

    QByteArray aux_byte = tcpSocket->readAll();

    if(!in.commitTransaction()) {
        return;
    }

    //Data is valid
    ui->plainTextEdit_log->appendPlainText(QString::fromStdString(aux_byte.toStdString()));

}

void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
       case QAbstractSocket::RemoteHostClosedError:
           break;
       case QAbstractSocket::HostNotFoundError:
           QMessageBox::information(this, tr("TCP client"),
                                    tr("The host was not found. Please check the "
                                       "host name and port settings."));
           break;
       case QAbstractSocket::ConnectionRefusedError:
           QMessageBox::information(this, tr("TCP client"),
                                    tr("The connection was refused by the peer. "
                                       "Make sure the fortune server is running, "
                                       "and check that the host name and port "
                                       "settings are correct."));
           break;
       default:
           QMessageBox::information(this, tr("TCP client"),
                                    tr("The following error occurred: %1.")
                                    .arg(tcpSocket->errorString()));
       }
}
