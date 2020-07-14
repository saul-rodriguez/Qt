#ifndef CINTERNALREG_H
#define CINTERNALREG_H

#include <QObject>

class CInternalReg
{
public:
    uint32_t current;
    uint8_t flag;

public:
    CInternalReg();

    void update(uint32_t value);

};

#endif // CINTERNALREG_H
