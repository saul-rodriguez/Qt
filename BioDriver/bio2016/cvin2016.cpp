#include "cvin2016.h"

CVIN2016::CVIN2016(QObject *parent) : QObject(parent)
{
    clearbits();
}

void CVIN2016::clearbits()
{
    m_vin.data[0] = 0x0000;
    m_vin.data[1] = 0x0000;
    m_vin.data[2] = 0x0000;
}

void CVIN2016::setbitsRadio(bool F3, bool F2, bool F1, bool F0, bool IQ, bool GS3, bool GS2, bool GS1,
                            bool GS0, bool CE, bool NS, bool GD2, bool GD1, bool GD0, bool FS, bool RE)
{
    m_vin.data_bits.F3 = F3;
    m_vin.data_bits.F2 = F2;
    m_vin.data_bits.F1 = F1;
    m_vin.data_bits.F0 = F0;
    m_vin.data_bits.IQ = IQ;
    m_vin.data_bits.GS3 = GS3;
    m_vin.data_bits.GS2 = GS2;
    m_vin.data_bits.GS1 = GS1;

    m_vin.data_bits.GS0 = GS0;
    m_vin.data_bits.CE = CE;
    m_vin.data_bits.NS = NS;
    m_vin.data_bits.GD2 = GD2;
    m_vin.data_bits.GD1 = GD1;
    m_vin.data_bits.GD0 = GD0;
    m_vin.data_bits.FS = FS;
    m_vin.data_bits.RE = RE;
}

void CVIN2016::setbitsFilter(bool EnLF, bool EnMF, bool EnHF, bool DN1, bool DN0, bool DP2, bool DP1, bool DP0, bool EnRdeg,
                   bool EnRdegHF1, bool EnRdegHF0, bool CcompSel1, bool CcompSel0, bool CapSel3, bool CapSel2, bool CapSel1, bool CapSel0)
{
    m_vin.data_bits.EnLF = EnLF;

    m_vin.data_bits.EnMF = EnMF;
    m_vin.data_bits.EnHF = EnHF;
    m_vin.data_bits.DN1 = DN1;
    m_vin.data_bits.DN0 = DN0;
    m_vin.data_bits.DP2 = DP2;
    m_vin.data_bits.DP1 = DP1;
    m_vin.data_bits.DP0 = DP0;
    m_vin.data_bits.EnRdeg = EnRdeg;

    m_vin.data_bits.EnRdegHF1 = EnRdegHF1;
    m_vin.data_bits.EnRdegHF0 = EnRdegHF0;
    m_vin.data_bits.CcompSel1 = CcompSel1;
    m_vin.data_bits.CcompSel0 = CcompSel0;
    m_vin.data_bits.CapSel3 = CapSel3;
    m_vin.data_bits.CapSel2 = CapSel2;
    m_vin.data_bits.CapSel1 = CapSel1;
    m_vin.data_bits.CapSel0 = CapSel0;

}

quint8 CVIN2016::getByte(int index)
{
    quint8 aux;
    switch (index) {
        case 0:
            aux = (quint8)(m_vin.data[0] & 0xff);
            break;
        case 1:
            aux = (quint8)((m_vin.data[0] >> 8) & 0xff);
            break;
        case 2:
            aux = (quint8)(m_vin.data[1]  & 0xff);
            break;
        case 3:
            aux = (quint8)((m_vin.data[1] >> 8) & 0xff);
            break;
        case 4:
            aux = (quint8)(m_vin.data[2]  & 0xff);
            break;
        default:
            aux = 0;
            break;
    }


    return aux;
}
