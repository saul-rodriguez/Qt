#include "cvargen.h"


CVargen::CVargen(QObject *parent) : QObject(parent)
{
    top = new Vvargen;
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

    //ram memory
    for (int i = 0; i < RAM_SIZE; i++) {
        ram[i].update(top->vargen__DOT__memory__DOT__mem[i]);
    }

    //rom memory
    for (int i = 0; i < ROM_SIZE; i++) {
        rom[i].update(top->vargen__DOT__pico_rom__DOT__mem[i]);
    }

    /* memory mapped ports */

    porta.update(top->porta_out);

}
