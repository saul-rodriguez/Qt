#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include "/home/saul/projects/Qt/SerialDriver/serial_driver/cserialdriver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonRefresh_clicked();

    void on_pushButtonTx_clicked();

    void SerialRx(const QByteArray &Data);

    void on_pushButtonConnect_clicked();

private:
    Ui::MainWindow *ui;

    QSerialPort serialPort;
    //serialPort.setPortName(serialPortInfos[1].portName());
    //serialPort.setBaudRate(QSerialPort::Baud9600);

    //serialPort.open(QIODevice::ReadWrite);


    CSerialDriver *myserial;

private:
    void readPorts();
};

#endif // MAINWINDOW_H
