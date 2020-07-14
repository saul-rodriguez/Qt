#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->splitter->setSizes(QList<int>() << 200 << 50);

    pico.initVargen();

    updateSim();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_Go_triggered()
{

}

void MainWindow::on_action_Reset_triggered()
{
    pico.resetn();
    updateSim();
    qDebug()<<"vargen has been reset";
}

void MainWindow::updateSim()
{
    //Updatre register list
    ui->ReglistWidget->clear();
    QString aux;

    for (int i = 0; i < 32; i++) {
        //aux = "\t" + QString("0x%1").arg(pico.reg[i].current,0,16);
        aux = "\t 0x" + QString::number(pico.reg[i].current,16).rightJustified(8,'0');
        ui->ReglistWidget->addItem(pico.regNames[i]+aux);
    }
    aux = "\t 0x" + QString::number(pico.pc.current,16).rightJustified(8,'0');
    ui->ReglistWidget->addItem("pc" + aux);

    for (int i = 0; i < ui->ReglistWidget->count(); i++) {
        QListWidgetItem* item = ui->ReglistWidget->item(i);
        if (i%2) {
            item->setBackgroundColor(Qt::lightGray);
        }
    }

    //Update program code
    if (ui->ProgramlistWidget->count() == 0) //no program loaded
        return;

    uint32_t pc = pico.pc.current;

    QStringList line;
    for (int i = 0; i < src_code.count(); i++) {
        aux = src_code[i];
        line = aux.split(QRegExp("\\W+"));
        if (line.count() > 4) {
            bool ok;
            uint32_t address = line[1].toUInt(&ok,16);
            if (ok == true) {
                if (address == pc) {
                    ui->ProgramlistWidget->setCurrentRow(i);
                    qDebug()<<"pc line: "<< i;
                }
            }
        }

    }
}

void MainWindow::on_actionS_tep_triggered()
{
    pico.advanceClk();
    pico.updateState();
    updateSim();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open assembly/source file from gcc"),tr("~") ,tr("*.*"));

    QFile auxfile(fileName);
    int ret = auxfile.open(QIODevice::ReadOnly);
    QTextStream in(&auxfile);

    src_code.clear();

    while(!in.atEnd()) {
             src_code << in.readLine();
    }

    auxfile.close();

    ui->ProgramlistWidget->clear();

    for (int i = 0; i < src_code.count(); i++ ) {
       ui->ProgramlistWidget->addItem(src_code[i]);
    }

}
