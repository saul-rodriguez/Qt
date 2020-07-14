#include <QCoreApplication>
#include <QDebug>

#include "cvargen.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CVargen vargen;

    vargen.initVargen();
    vargen.resetn();

    while (vargen.time < 200) {
        vargen.advanceClk();
        vargen.updateState();
        qDebug("PC: %x, PORTA: %x",
               vargen.pc.current,
               vargen.porta.current);
    }


    return a.exec();
}
