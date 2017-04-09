#include "calibration.h"
#include "cbio2016.h"

Calibration::Calibration(QObject *parent) : QObject(parent)
{
    CBIO2016 aux;


    for (int i=0; i < 11; i++) {
        m_magcal[i] = 1;
        m_phacal[i] = 0;
        m_freq[i] = aux.getFreqValue(10-i); //from FREQ10 (1kHz) to FREQ0 (1MHz)
    }

    usecap = false;

    m_measMag = 0;
    m_measPha = 0;
    m_freqIndex = 0;

    m_cap = 0;

}

void Calibration::setCalParam(double *magcal, double *magpha)
{
    for (int i = 0; i < 11; i++) {
        m_magcal[i] = magcal[i];
        m_phacal[i] = magpha[i];
    }
}

void Calibration::setCableCap(double cap)
{
    m_cap = cap;
}

void Calibration::setCalibrateCableCap(bool param)
{
    usecap = param;
}

void Calibration::setMeasImpedance(double mag, double pha, quint8 freqIndex)
{
    m_measMag = mag;
    m_measPha = pha;
    m_freqIndex = freqIndex;

}

void Calibration::getCalImpedance(double *mag, double *pha)
{
    double magnitude;
    double phase;

   magnitude = m_measMag*m_magcal[m_freqIndex];
   phase = m_measPha + m_phacal[m_freqIndex];

   if (usecap) {
       double PI = 3.14159265359;

       double phase_rad = phase*PI/180.0;

       std::complex<double> Zm = std::polar(magnitude,phase_rad);
    //   std::complex<double> Zm = std::polar(magnitude,phase);
       std::complex<double> Gm = pow(Zm,-1);

       double C_adm = 2*PI*m_freq[m_freqIndex]*m_cap;
       std::complex<double> Gcap(0,C_adm);

       std::complex<double> Gcal =Gm - Gcap;
       std::complex<double> Zcal = pow(Gcal,-1);

       magnitude = std::abs(Zcal);
       phase = std::arg(Zcal)/PI*180;
   }

   *mag = magnitude;
   *pha = phase;
}
