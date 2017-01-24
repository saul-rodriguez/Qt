#include "cbio2016.h"

CBIO2016::CBIO2016(QObject *parent) : QObject(parent)
{
    m_bio3.data = 0x0000;
}

void CBIO2016::setbits(bool F3, bool F2, bool F1, bool F0, bool IQ, bool GS3, bool GS2, bool GS1, bool GS0,
             bool CE, bool NS, bool GD2, bool GD1, bool GD0, bool FS, bool RE)
{
    m_bio3.data_bits.F3 = F3;
    m_bio3.data_bits.F2 = F2;
    m_bio3.data_bits.F1 = F1;
    m_bio3.data_bits.F0 = F0;
    m_bio3.data_bits.IQ = IQ;
    m_bio3.data_bits.GS3 = GS3;
    m_bio3.data_bits.GS2 = GS2;
    m_bio3.data_bits.GS1 = GS1;

    m_bio3.data_bits.GS0 = GS0;
    m_bio3.data_bits.CE = CE;
    m_bio3.data_bits.NS = NS;
    m_bio3.data_bits.GD2 = GD2;
    m_bio3.data_bits.GD1 = GD1;
    m_bio3.data_bits.GD0 = GD0;
    m_bio3.data_bits.FS = FS;
    m_bio3.data_bits.RE = RE;

}

quint8 CBIO2016::getByte0()
{
    return (quint8)(m_bio3.data & 0xff);
}

quint8 CBIO2016::getByte1()
{
    return (quint8)((m_bio3.data >> 8) & 0xff);
}
