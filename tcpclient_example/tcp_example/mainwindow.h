#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDataStream>
#include <QTcpSocket>
#include <QNetworkSession>

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
    void on_pushButton_connect_clicked();

    void on_pushButton_disconnect_clicked();

    void on_pushButton_send_clicked();

    void readSocket();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    Ui::MainWindow *ui;

    QTcpSocket *tcpSocket = nullptr;
    QNetworkSession *networkSession = nullptr;
    QDataStream in;


};

#endif // MAINWINDOW_H
