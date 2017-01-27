#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include "/home/saul/projects/Qt/SerialDriver/serial_driver/cserialdriver.h"
#include "cbio2016.h"
#include "cvin2016.h"

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
    void on_pushButtonRefreshPorts_clicked();

    void on_pushButtonConnect_clicked();

    void on_pushButtonTest_clicked();

    void SerialRx(const QByteArray &Data);



    void on_pushButtonConfigure_clicked();

    void on_pushButtonConfigAll_clicked();

    void on_pushButtonTestADC_clicked();

    void on_pushButtonAllTest_clicked();

private:
    Ui::MainWindow *ui;

    QSerialPort serialPort;
    CSerialDriver *myserial;

    CBIO2016 m_bioASIC;
    CVIN2016 m_vinASIC;

private:
    void readPorts();
    void readADC(const QByteArray &Data);

};

#endif // MAINWINDOW_H
