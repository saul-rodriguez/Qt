#include "crom.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>


CRom::CRom()
{
    program.clear();

    ram_size_words = 256; // Default value
}

void CRom::setRamSize(uint32_t size)
{
    ram_size_words = size;
}

void CRom::readFile(QString filename)
{
    QFile auxfile(filename);
    int ret = auxfile.open(QIODevice::ReadOnly);
    QTextStream in(&auxfile);

    program.clear();

    QString temp;
    bool ok;
    while(!in.atEnd()) {
             temp = in.readLine();
             uint32_t address = temp.toUInt(&ok,16);
             if (ok == true) {
                 program << address;
             }
    }

    auxfile.close();

}

void CRom::update()
{
    if (pico->v_mem_valid && !pico->v_mem_ready &&
        pico->v_mem_addr >= 4*ram_size_words &&
        pico->v_mem_addr < 0x00100000) {

        pico->v_mem_ready = 1;
    } else {
        pico->v_mem_ready = 0;
    }

    uint32_t address = pico->v_mem_addr & 0x0000ffff; //address in bytes
    address = address >> 2; //address in words

    if (address < program.size()) {
        pico->v_mem_rdata = program[address];
    } else {
        pico->v_mem_rdata = 0;
    }

}

void CRom::setPico(Vvargen *var)
{
    pico = var;
}
