#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QStandardPaths>
#include <QDebug>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);

    qDebug() << path; // '/storage/emulated/0/Download'
    qDebug() << "Exists? " << QFile::exists(path + "/401891.png"); // This is an existing image in the folder, returns true

    QFile testFile(path.append("/Testing.txt"));
    testFile.open(QFile::WriteOnly);

    QTextStream out(&testFile);
    out << "Hello";

    testFile.close();

}

