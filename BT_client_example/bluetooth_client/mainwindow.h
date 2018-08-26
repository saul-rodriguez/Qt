#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "btclient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void getBTdevice(QString name);
    void bluetoothConnected(QString name);
    void rxData(const QByteArray &data);

    void on_pushButtonDiscoverBT_clicked();

    void on_pushButtonConnect_clicked();


    void on_pushButtonSend_clicked();

private:
    Ui::MainWindow *ui;

    BTClient *m_bt;



};

#endif // MAINWINDOW_H
