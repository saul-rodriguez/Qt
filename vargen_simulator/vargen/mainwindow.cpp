#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDockWidget>
#include <QFileDialog>
#include <QTableWidget>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //**** Initialize ROM *****
    ROM.setPico(pico.getPico());
    ROM.setRamSize(pico.getRAMSize());


    //***** Initialize vargen *****
    pico.initVargen();

    //***** Create dockable widgets *******
    QDockWidget *dock1 = new QDockWidget(tr("Registers"), this);
 //   dock1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    ReglistWidget = new QListWidget(dock1);

    QDockWidget *dock2 = new QDockWidget(tr("Assembly"), this);
    ProgramlistWidget = new QListWidget(dock2);

    QDockWidget *dock3 = new QDockWidget(tr("RAM"), this);
    RamTableWidget = new QTableWidget(dock3);

    int size = pico.getRAMSize();
    int columns = 1 + 8; // address + (8 x 4byte offset words)
    int rows = size/(8);

    RamTableWidget->setRowCount(rows);
    RamTableWidget->setColumnCount(columns);

    QStringList labels;
    labels << "Address" << "(+00)" <<"(+04)" <<"(+08)"<<"(+0c)"<<
              "(+10)"<<"(+14)"<<"(+18)"<<"(+1C)";
    RamTableWidget->setHorizontalHeaderLabels(labels);

    uint32_t addr = 0x00;
    QString aux2;

    for (int i = 0; i < rows; i++) {
        aux2 = "0x" + QString::number(addr,16).rightJustified(8,'0');
        RamTableWidget->setItem(i,0, new QTableWidgetItem(aux2));
        addr+=4*8;
        //RamTableWidget->item(0,0)->setText("hola");
        aux2 = "0x" +  QString::number(0xff,16).rightJustified(8,'0');

        for (int j = 1; j < 9; j++ ) {
            RamTableWidget->setItem(i,j, new QTableWidgetItem(aux2));
        }
    }

    updateSim();

    dock1->setWidget(ReglistWidget);
    addDockWidget(Qt::RightDockWidgetArea, dock1);

    dock2->setWidget(ProgramlistWidget);
    addDockWidget(Qt::LeftDockWidgetArea, dock2);

    dock3->setWidget(RamTableWidget);
    addDockWidget((Qt::BottomDockWidgetArea),dock3);

    //****** Create a timer ******
    clk = new QTimer(this);
    connect(clk,SIGNAL(timeout()),this,SLOT(clkTimeout()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clkTimeout()
{
    on_action_Next_inst_triggered();
}

void MainWindow::openCfile(QString filename)
{
    QFile auxfile(filename);
    int ret = auxfile.open(QIODevice::ReadOnly);
    QTextStream in(&auxfile);

    src_C_code.clear();

    while(!in.atEnd()) {
             src_C_code << in.readLine();
    }

    auxfile.close();

    //if (!CProgramlistWidget->count()) {
        QDockWidget *dock = new QDockWidget(tr("C/Assembly debug"), this);
        CProgramlistWidget = new QListWidget(dock);

        dock->setWidget(CProgramlistWidget);
        addDockWidget(Qt::TopDockWidgetArea, dock);

    //}

    CProgramlistWidget->clear();

    for (int i = 0; i < src_C_code.count(); i++ ) {
       CProgramlistWidget->addItem(src_C_code[i]);
       if (src_C_code[i].contains("**",Qt::CaseInsensitive)) {
           CProgramlistWidget->item(i)->setTextColor(Qt::blue);
       } else {
           CProgramlistWidget->item(i)->setTextColor(Qt::lightGray);
       }
    }
}

void MainWindow::openAsmFile(QString filename)
{
    QFile auxfile(filename);
    int ret = auxfile.open(QIODevice::ReadOnly);
    QTextStream in(&auxfile);

    src_code.clear();

    while(!in.atEnd()) {
             src_code << in.readLine();
    }

    auxfile.close();

    ProgramlistWidget->clear();

    for (int i = 0; i < src_code.count(); i++ ) {
       ProgramlistWidget->addItem(src_code[i]);
    }
}

void MainWindow::openHexFile(QString filename)
{
    ROM.readFile(filename);

    if (!ROM.program.count()) {
        qDebug()<<"Hex4 no loaded";
        return;
    }
}

void MainWindow::setArguments(int argc, char *argv[])
{
    if (argc == 4) {
        QString hex_file = QString::fromUtf8(argv[1]);
        QString asm_file = QString::fromUtf8(argv[2]);
        QString C_file = QString::fromUtf8(argv[3]);

        openHexFile(hex_file);
        openAsmFile(asm_file);
        openCfile(C_file);

    } else if (argc == 2) {
        QString aux = QString::fromUtf8(argv[1]);
        if (aux == "--help") {
            QTextStream(stdout) << "vargen filename.hex4 filename.dmp filename.lst\n";
            exit(1);
        }

    }
}

void MainWindow::on_action_Go_triggered()
{
    clk->start(100);
}

void MainWindow::on_action_Reset_triggered()
{
    pico.resetn();
    ROM.update();
    updateSim();
    //qDebug()<<"vargen has been reset";
}

void MainWindow::updateSim()
{
    //***** Update register list *****
    ReglistWidget->clear();
    QString aux;

    for (int i = 0; i < 32; i++) {
        //aux = "\t" + QString("0x%1").arg(pico.reg[i].current,0,16);
        aux = "\t 0x" + QString::number(pico.reg[i].current,16).rightJustified(8,'0');
        ReglistWidget->addItem(pico.regNames[i]+aux);
        if (pico.reg[i].flag) {
            ReglistWidget->item(i)->setTextColor(Qt::red);
        } else {
            ReglistWidget->item(i)->setTextColor(Qt::black);
        }
    }
    aux = "\t 0x" + QString::number(pico.pc.current,16).rightJustified(8,'0');
    ReglistWidget->addItem("pc" + aux);
    if (pico.pc.flag) {
        ReglistWidget->item(32)->setTextColor(Qt::red);
    } else {
        ReglistWidget->item(32)->setTextColor(Qt::black);
    }

    for (int i = 0; i < ReglistWidget->count(); i++) {
        QListWidgetItem* item = ReglistWidget->item(i);
        if (i%2) {
            item->setBackgroundColor(Qt::lightGray);
        }
    }

    // ***** Update program code *****
   // if (ProgramlistWidget->count() == 0) //no program loaded
   //     return;

    //Check if address matches program counter
    uint32_t pc = pico.pc.current;

    QStringList line;
    bool ok;

    for (int i = 0; i < src_code.count(); i++) {
        aux = src_code[i];

        line = aux.split(QRegExp("\\W+"));
        if (line.count() > 4) {            
            uint32_t address = line[1].toUInt(&ok,16);
            if (ok == true) {
                if (address == pc) {
                    ProgramlistWidget->setCurrentRow(i);
                    qDebug()<<"pc line: "<< i;

                    //If C debug code is available update also the focus
                    if (CProgramlistWidget != nullptr) {
                    //if (CProgramlistWidget->count()) {
                        updateCdebug();
                    }
                    break;
                }
            }
        }

        //Check if line is entry point to function
        if (aux.contains("<")) {
            line = aux.split(QRegExp("\\W+"));
            uint32_t address = line[0].toUInt(&ok,16);
            if (ok == true) {
                currentFunctionAddress = address;
                currentFunctionName = line[1];
                //qDebug()<<"Function name found: "<<currentFunctionName;
            }
        }
    }

    // ****** Update RAM *******

    QString aux2;

    int index = 0;
    for (int i = 0; i < pico.getRAMSize()/8; i++) {
        for (int j = 0; j < 8 ; j++) {
            aux2 = QString::number(pico.ram[index].current,16).rightJustified(8,'0');
            //aux2 = QString::number(i,16).rightJustified(8,'0');

            if (pico.ram[index].flag == true) {
               RamTableWidget->item(i,(j+1))->setTextColor(Qt::red);
            } else {
                //RamTableWidget->item(i,(j+1))->setBackground(Qt::white);
                //RamTableWidget->item(i,(j+1))->setText(aux2);
            }
            RamTableWidget->item(i,(j+1))->setText(aux2);

            index++;
        }
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open assembly/source file from gcc"),tr("~") ,tr("*.dmp"));

    if(fileName != "") {
        openAsmFile(fileName);
    }
}

void MainWindow::on_action_Clk_step_triggered()
{
    pico.advanceClk();
    ROM.update();
    pico.updateState();
    updateSim();
}

void MainWindow::on_action_Next_inst_triggered()
{
    int aux;

    aux = 20;
    do {
        pico.advanceClk();
        ROM.update();
        pico.updateState();
        updateSim();
        aux--;
        if (!aux) {
           // qDebug()<<"Next instruction not reached in "<<aux<<" clk cycles";
            break;
        }

    } while(!pico.pc.flag);
    //updateSim();

}

void MainWindow::on_action_Stop_triggered()
{
    clk->stop();
}

void MainWindow::on_actionOpen_C_source_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open C lst debug file from gcc"),tr("~") ,tr("*.lst"));

    if (fileName != "") {
        openCfile(fileName);
    }


}

void MainWindow::updateCdebug()
{
    //Search for function name
    QString aux;
    QStringList line;
    bool ok;
    uint32_t function_address;

    int state = 0;

    for (int i = 0; i < src_C_code.count(); i++) {
        aux = src_C_code[i];

        if (state == 0) {
            if (aux.contains("****")) { // c code line found
                //search function name
                if(aux.contains(currentFunctionName+"(") && (
                   aux.contains("void") || aux.contains("int") ) ) {
                    //qDebug()<<"C function name found: "<<currentFunctionName<<" found";

                    //Search for next address
                    state = 1;
                    continue;
                }
            }
         } else if (state == 1) {
            line = aux.split(QRegExp("\\W+"));
            uint32_t address = line[2].toUInt(&ok,16);
            if (ok == true) {
                //qDebug()<<"C address found: "<<address;
                function_address = address;

                if (pico.pc.current == currentFunctionAddress) {
                   CProgramlistWidget->setCurrentRow(i);
                   //qDebug()<<"C code matched assembly at origin";
                   break;
                }
                state = 2;
            }
         } else {

            line = aux.split(QRegExp("\\W+"));
            uint32_t address = line[2].toUInt(&ok,16);
            uint32_t C_address = pico.pc.current - currentFunctionAddress + function_address;
            if (ok == true) {
                if (C_address == address) {
                    CProgramlistWidget->setCurrentRow(i);
                    //qDebug()<<"C code matched assembly";
                    break;
                }
            }

         }
    }
}



void MainWindow::on_actionOpen_Hex_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open hex4 text file"),tr("~") ,tr("*.hex4"));

    if (filename != "") {
        openHexFile(filename);
    }


}

void MainWindow::on_action_Clear_Color_Markers_triggered()
{
    int index = 0;
    for (int i = 0; i < pico.getRAMSize()/8; i++) {
        for (int j = 0; j < 8 ; j++) {
            RamTableWidget->item(i,(j+1))->setTextColor(Qt::black);
            index++;
        }
    }
}


