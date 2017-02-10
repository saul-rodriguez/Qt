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

    mixer_gain_factor = 1; // mixer gain is around 2/PI. It must be set after calibration!!!

    m_freq.data = 0;

}


void CBIO2016::clearbits()
{
    m_bio3.data = 0x0000;
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

void CBIO2016::setMixerGainFactor(double factor)
{
    mixer_gain_factor = factor;
}


