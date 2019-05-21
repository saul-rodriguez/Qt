#include "bioimpedance.h"
#include <QDebug>
#include <qmath.h>

bioimpedance::bioimpedance(QObject *parent) : QObject(parent)
{

    frequencies[0] = 1e6; // freq in Hz

    for (int i = 1; i<11; i++)
        frequencies[i] = frequencies[i-1]/2.0;

    staticGains[7] = 0.0015; //

    for (int i = 6; i >= 0; i--)
        staticGains[i] = staticGains[i+1]/3.0;


    m_valid = 0; //invalid data at construction

    m_mag = 0;
    m_pha = 0;
    m_I = 0;
    m_Q = 0;
    m_freq_ind = 0;
    m_gain_ind = 0;
}

bool bioimpedance::setData(QByteArray rawdata)
{
    m_rawdata = rawdata;

    //First check that the packet has the right size
    int N = m_rawdata.size();
    if (N != 7) return false;

    //Check that the checksum byte is correct
    const char* read_pt = m_rawdata.constData();
    quint8 check = calculateChecksum((quint8*)read_pt,7);
    if (check) {
        qDebug()<<"Error checksum!";
        m_valid = 0;
        return false;
    }

    //Proceed to extract I,Q, gain, frequency, and impedance
    calculateIQ(); //extract I and Q (V)
    bool ret = extractGainFreq();
    if (!ret) return false; //failed to extract valid gain or frequency index
    calculateImpedance();

    return true;
}

double bioimpedance::getMagnitude()
{
    return m_mag;
}

double bioimpedance::getPhase()
{
    return m_pha;
}

double bioimpedance::getFrequency()
{
    return m_freq;
}

int bioimpedance::getFrequencyIndex(freqIndexType ftype)
{
    if (ftype == REVERSE) {
        return (10 - m_freq_ind); //reverse the order of the
    } else {
        return m_freq_ind;
    }
}

void bioimpedance::calibrateMagnitude(double gainFactor)
{
    m_mag *= gainFactor;
}

void bioimpedance::calibratePhase(double phaseCorrection)
{
    m_pha -= phaseCorrection;
}

void bioimpedance::setMagnitude(double mag)
{
    m_mag = mag;
}

void bioimpedance::setPhase(double pha)
{
    m_pha = pha;
}

void bioimpedance::setFrequency(double freq)
{
    m_freq = freq;
}

void bioimpedance::setFrequencyIndex(quint8 freq_ind)
{
    m_freq_ind = freq_ind;
}

void bioimpedance::calculateIQ()
{
    const char* read_pt = m_rawdata.constData();

    qint16 Is,Qs;

    //Extract I
    Is= 0;
    Is |= (quint16)(read_pt[2] << 8) ;
    Is |= (quint16)(read_pt[1] & 0xff);

    m_I = Is/ADC_RES*VREF; //result in V

    //Extract Q/
    Qs= 0;
    Qs |= (quint16)(read_pt[4] << 8) ;
    Qs |= (quint16)(read_pt[3] & 0xff);

    m_Q = Qs/ADC_RES*VREF; //result in V

}

bool bioimpedance::extractGainFreq()
{
    const char* read_pt = m_rawdata.constData();
    m_freq_ind = (quint8)((read_pt[5] >> 4) & 0x0f);
    m_gain_ind = (quint8)(read_pt[5] & 0x0f);

    //Check that index is not outside boundaries
    if (m_gain_ind > 7 || m_freq_ind > 10) {
       qDebug()<<"gain or frequency index out of limits!";
       return false;
    }

    m_freq = frequencies[m_freq_ind]; // frequency in Hz
    m_gain = staticGains[m_gain_ind]; // all front-end's gain

    //adjust gain considering mixing (0.56) and DIFF-SE buffer (2.0)
    m_gain *= 0.5667049*2.0;

    return true;
}

void bioimpedance::calculateImpedance()
{
    double V_mag;
    V_mag = qSqrt(qPow(m_I,2)+qPow(m_Q,2));
    m_mag = V_mag/m_gain; //result in Ohm

    double phase_rad;
    phase_rad = qAtan2(m_Q,-m_I); //Note that the output of the ASIC is inverted!
    m_pha = qRadiansToDegrees(phase_rad);

}

quint8 bioimpedance::calculateChecksum(const quint8 *data, quint8 num)
{
    quint8 check, i;

        check = 0;
        for (i = 0; i < num; i++) {
                check ^= data[i];
        }

    return check;
}
