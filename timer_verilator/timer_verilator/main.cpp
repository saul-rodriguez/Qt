#include <QCoreApplication>
#include <QDebug>

#include "Vtimer.h"
#include "verilated.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"Starting";

    Verilated::commandArgs(argc, argv);

    Vtimer* top = new Vtimer;

    //set initial state
    top->clk = 0;
    top->resetn = 1;
    top->timer_value = 0xfffffff0;
    top->en = 0;
    top->go = 0;
    top->auto_load = 0;

    quint64 main_time = 0;

    while (!Verilated::gotFinish()) {
        main_time++;

        //toggle clock
        top->clk = !top->clk;

        //Reset signal
        if (main_time > 2 && main_time < 10) {
            top->resetn = 0;
        } else {
            top->resetn = 1;
        }

        //enable
        if (main_time == 15) {
            top->en = 1;
        }

        //go timer
        if (main_time == 17) {
            top->go = 1;
        }

        top->eval();

        //log signals on rising edge
        if (top->clk) {
            //qDebug()<<"Time: " << main_time << top->timer__DOT__timer_count;
            qDebug("Time: %d, counter: %x, interrupt: %d",
                   main_time,
                   top->timer__DOT__timer_count,
                   top->tmr_int);
        }

        if (main_time == 100) {
            qDebug()<<"finishing simulation";
            break;
        }

    }

    delete top;

    return a.exec();
}
