#include "cinternalreg.h"

CInternalReg::CInternalReg()
{
    current = 0;
    flag = 0;
}

void CInternalReg::update(uint32_t value)
{
    if (value != current) {
        flag = 1;
    } else {
        flag = 0;
    }

    current = value;
}
