#ifndef CVARGEN_H
#define CVARGEN_H

#include <QObject>

#include "verilated.h"
#include "Vvargen.h"
#include "cinternalreg.h"

#define RAM_SIZE 256
#define ROM_SIZE 512

class CVargen : public QObject
{
    Q_OBJECT
public:
    Vvargen *top;
    uint64_t time;

    //picorv32
    CInternalReg reg[32];


    CInternalReg ram[RAM_SIZE];
    CInternalReg rom[ROM_SIZE];
    CInternalReg pc;

    //vargen ports
    CInternalReg porta;
    CInternalReg portb;

    QStringList regNames;

public:
    explicit CVargen(QObject *parent = nullptr);
    void initVargen();
    void resetn();
    void advanceClk();
    void updateState();

signals:

};

#endif // CVARGEN_H
