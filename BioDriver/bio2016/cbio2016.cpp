#include "cbio2016.h"
#include <qmath.h>

CBIO2016::CBIO2016(QObject *parent) : QObject(parent)
{
    //m_bio3.data = 0x0000;
    clearbits();

    m_vp = 0;
    m_vn = 0;
    m_vse = 0;

    m_gain.data = 0;

    gains[0] = GAIN0;
    gains[1] = GAIN1;
    gains[2] = GAIN2;
    gains[3] = GAIN3;
    gains[4] = GAIN4;
    gains[5] = GAIN5;
    gains[6] = GAIN6;
    gains[7] = GAIN7;

    static_gain[0] = STAT_GAIN0;
    static_gain[1] = STAT_GAIN1;
    static_gain[2] = STAT_GAIN2;
    static_gain[3] = STAT_GAIN3;
    static_gain[4] = STAT_GAIN4;
    static_gain[5] = STAT_GAIN5;
    static_gain[6] = STAT_GAIN6;
    static_gain[7] = STAT_GAIN7;

    freqs[0] = STAT_FREQ0;
    freqs[1] = STAT_FREQ1;
    freqs[2] = STAT_FREQ2;
    freqs[3] = STAT_FREQ3;
    freqs[4] = STAT_FREQ4;
    freqs[5] = STAT_FREQ5;
    freqs[6] = STAT_FREQ6;
    freqs[7] = STAT_FREQ7;
    freqs[8] = STAT_FREQ8;
    freqs[9] = STAT_FREQ9;
    freqs[10] = STAT_FREQ10;

    mixer_gain_factor = 1; // mixer gain is around 2/PI. It must be set after calibration!!!

    m_freq.data = 0;

    filter_conf[0] = FILT_FREQ0;
    filter_conf[1] = FILT_FREQ1;
    filter_conf[2] = FILT_FREQ2;
    filter_conf[3] = FILT_FREQ3;
    filter_conf[4] = FILT_FREQ4;
    filter_conf[5] = FILT_FREQ5;
    filter_conf[6] = FILT_FREQ6;
    filter_conf[7] = FILT_FREQ7;
    filter_conf[8] = FILT_FREQ8;
    filter_conf[9] = FILT_FREQ9;
    filter_conf[10] = FILT_FREQ10;



}


void CBIO2016::clearbits()
{
    m_bio3.data = 0x0000;
    m_filt.data = 0x00000000;
}

void CBIO2016::setbits(bool F3, bool F2, bool F1, bool F0, bool IQ, bool GS3, bool GS2, bool GS1, bool GS0,
             bool CE, bool NS, bool GD2, bool GD1, bool GD0, bool FS, bool RE)
{
    //Set configuration bits
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

    //save current radio gain configuration
    m_gain.data_bits.NOTUSED = 0;
    m_gain.data_bits.GS3 = GS3;
    m_gain.data_bits.GS2 = GS2;
    m_gain.data_bits.GS1 = GS1;
    m_gain.data_bits.GS0 = GS0;
    m_gain.data_bits.GD2 = GD2;
    m_gain.data_bits.GD1 = GD1;
    m_gain.data_bits.GD0 = GD0;

    //save current radio frequency configuration
    m_freq.data_bits.F3 = F3;
    m_freq.data_bits.F2 = F2;
    m_freq.data_bits.F1 = F1;
    m_freq.data_bits.F0 = F0;

}

/*
void CBIO2016::setFreqbits(RADIO_freq &freq)
{
    //Update configuration bits
    m_bio3.data_bits.F3 = freq.data_bits.F3;
    m_bio3.data_bits.F2 = freq.data_bits.F2;
    m_bio3.data_bits.F1 = freq.data_bits.F1;
    m_bio3.data_bits.F0 = freq.data_bits.F0;

    //save current radio frequency configuation in local structure
    m_freq.data_bits.F3 = freq.data_bits.F3;
    m_freq.data_bits.F2 = freq.data_bits.F2;
    m_freq.data_bits.F1 = freq.data_bits.F1;
    m_freq.data_bits.F0 = freq.data_bits.F0;

}
*/

quint8 CBIO2016::getByte0()
{
    return (quint8)(m_bio3.data & 0xff);
}

quint8 CBIO2016::getByte1()
{
    return (quint8)((m_bio3.data >> 8) & 0xff);
}

quint8 CBIO2016::getByte(int index)
{
    return (quint8)(m_bio3.data >> (8*index) & 0xff);
}

quint8 CBIO2016::getFilterByte(int index)
{
    return (quint8)(m_filt.data >> (8*index) & 0xff);
}

void CBIO2016::setbitsFilter(bool EnLF, bool EnMF, bool EnHF, bool DN1, bool DN0, bool DP2, bool DP1, bool DP0, bool EnRdeg, bool EnRdegHF1, bool EnRdegHF0, bool CcompSel1, bool CcompSel0, bool CapSel3, bool CapSel2, bool CapSel1, bool CapSel0)
{
    m_filt.data_bits.EnLF = EnLF;

    m_filt.data_bits.EnMF = EnMF;
    m_filt.data_bits.EnHF = EnHF;
    m_filt.data_bits.DN1 = DN1;
    m_filt.data_bits.DN0 = DN0;
    m_filt.data_bits.DP2 = DP2;
    m_filt.data_bits.DP1 = DP1;
    m_filt.data_bits.DP0 = DP0;
    m_filt.data_bits.EnRdeg = EnRdeg;

    m_filt.data_bits.EnRdegHF1 = EnRdegHF1;
    m_filt.data_bits.EnRdegHF0 = EnRdegHF0;
    m_filt.data_bits.CcompSel1 = CcompSel1;
    m_filt.data_bits.CcompSel0 = CcompSel0;
    m_filt.data_bits.CapSel3 = CapSel3;
    m_filt.data_bits.CapSel2 = CapSel2;
    m_filt.data_bits.CapSel1 = CapSel1;
    m_filt.data_bits.CapSel0 = CapSel0;
}

void CBIO2016::setbitFilterbyFreq(int index)
{
    m_filt.data = filter_conf[index];
}

VINfilt CBIO2016::getFilter()
{
    return m_filt;
}

void CBIO2016::setADCvalues(quint16 vp, quint16 vn, quint16 vse)
{
    m_vp = vp;
    m_vn = vn;
    m_vse = vse;
}

void CBIO2016::getADCVoltages(double* vp, double* vn, double* vse)
{
    *vp = (double)(m_vp)/1024.*1.8;
    *vn = (double)(m_vn)/1024.*1.8;
    *vse = (double)(m_vse)/1024.*1.8;
}

void CBIO2016::getImpedance(double* mag, double* pha, double v_I, double v_Q)
{
    int gain_index;

    gain_index = getGainIndex();
    if (gain_index == -1) { //Error index!
        mag = 0;
        pha = 0;
        return;
    }

    double V_magnitude, Z_magnitude;
    V_magnitude = qSqrt(qPow(v_I,2)+qPow(v_Q,2));
    Z_magnitude = V_magnitude/(static_gain[gain_index]*mixer_gain_factor);

    *mag = Z_magnitude;

    double phase_rad, phase;

    phase_rad = qAtan2(v_Q,-v_I); //Note that the output of the ASIC is inverted!
    phase = qRadiansToDegrees(phase_rad);
    *pha = phase;

}

int CBIO2016::getGainIndex()
{
    int ind;
    switch (m_gain.data) {
        case GAIN0: ind = 0;
                    break;
        case GAIN1: ind = 1;
                    break;
        case GAIN2: ind = 2;
                    break;
        case GAIN3: ind = 3;
                    break;
        case GAIN4: ind = 4;
                    break;
        case GAIN5: ind = 5;
                    break;
        case GAIN6: ind = 6;
                    break;
        case GAIN7: ind = 7;
                    break;
        default:    ind = -1; //NOT VALID GAIN CONFIG!
    }

    return ind;
}

quint8 CBIO2016::getGainBits(int i)
{
    return gains[i];
}

double CBIO2016::getFreqValue(int index)
{
    return freqs[index];
}

void CBIO2016::setMixerGainFactor(double factor)
{
    mixer_gain_factor = factor;
}


