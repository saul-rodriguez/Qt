#include "cvargen.h"
#include <QDebug>

CVargen::CVargen(QObject *parent) : QObject(parent)
{
    top = new Vvargen;

    regNames.clear();
    regNames << "zero"
             << "ra"
             << "sp"
             << "gp"
             << "tp"
             << "t0"
             << "t1"
             << "t2"
             << "s0"
             << "s1"
             << "a0"
             << "a1"
             << "a2"
             << "a3"
             << "a4"
             << "a5"
             << "a6"
             << "a7"
             << "s2"
             << "s3"
             << "s4"
             << "s5"
             << "s6"
             << "s7"
             << "s8"
             << "s9"
             << "s10"
             << "s11"
             << "t3"
             << "t4"
             << "t5"
             << "t6";

    ram_size = RAM_SIZE;

}

void CVargen::initVargen()
{
    time = 0;

    top->resetn = 1;
    top->clk = 0;
    top->irq_5 = 0;
    top->irq_6 = 0;
    top->irq_7 = 0;
    top->portb_in = 0;
}

void CVargen::resetn()
{
    advanceClk();
    top->resetn = 0;
    advanceClk();
    advanceClk();
    top->resetn = 1;
    advanceClk();
    updateState();

    time = 0;

}

void CVargen::advanceClk()
{

    top->clk = 0;
    top->eval();
    top->clk = 1;
    top->eval();

    time++;
    qDebug()<<"time: "<<time;

}

void CVargen::updateState()
{
    /* picorv32 */

    //program counter
    pc.update(top->vargen__DOT__cpu__DOT__reg_pc);

    //registers
    for (int i = 0; i < 32; i++) {
        reg[i].update(top->vargen__DOT__cpu__DOT__cpuregs__DOT__regs[i]);
    }

    if (top->vargen__DOT__cpu__DOT__cpuregs__DOT__regs[0] != 0) {
        qDebug()<<"zero reg mismatch!";
    }
    //ram memory
    for (int i = 0; i < RAM_SIZE; i++) {
        ram[i].update(top->vargen__DOT__memory__DOT__mem[i]);
        if (ram[i].flag) {
            qDebug()<<"RAM changed: "<<i;
        }
    }

    //rom memory
    /*
    for (int i = 0; i < ROM_SIZE; i++) {
        rom[i].update(top->vargen__DOT__pico_rom__DOT__mem[i]);
    }
*/
    /* memory mapped ports */

    porta.update(top->porta_out);    

}

void CVargen::writePortB(uint32_t word)
{
    uint8_t aux;
    aux = (uint8_t)word;

    top->portb_in = aux;

}

void CVargen::changeIRQ5(bool value)
{
    uint8_t aux;
    aux = value;

    top->irq_5 = aux;

}

void CVargen::changeIRQ6(bool value)
{
    uint8_t aux;
    aux = value;

    top->irq_6 = aux;

}

void CVargen::changeIRQ7(bool value)
{
    uint8_t aux;
    aux = value;

    top->irq_7 = aux;
}

uint32_t CVargen::getRAMSize()
{
    return ram_size;
}

Vvargen *CVargen::getPico()
{
    return top;
}
