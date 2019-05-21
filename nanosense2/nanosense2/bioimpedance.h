#ifndef BIOIMPEDANCE_H
#define BIOIMPEDANCE_H

#include <QObject>

//Radio frequency bit states (FREQ0 = 1 MHz, FREQ10 = 1 kHZ))
/*
enum frequencies {
    FREQ0 = 0b00000000,
    FREQ1 = 0b00000001,
    FREQ2 = 0b00000010,
    FREQ3 = 0b00000011,
    FREQ4 = 0b00000100,
    FREQ5 = 0b00000101,
    FREQ6 = 0b00000110,
    FREQ7 = 0b00000111,
    FREQ8 = 0b00001000,
    FREQ9 = 0b00001001,
    FREQ10 = 0b00001010
};
typedef enum frequencies frequencies;

enum gains {
    GAIN0 = 0b00000100,
    GAIN1 = 0b00000101,
    GAIN2 = 0b00000111,
    GAIN3 = 0b00000011,
    GAIN4 = 0b00100011,
    GAIN5 = 0b01100011,
    GAIN6 = 0b01101011,
    GAIN7 = 0b01111011
};
typedef enum gains gains;
*/

enum freqIndexType {
    ASIC,
    REVERSE
};
typedef enum freqIndexType freqIndexType;

//Uncomment one of the following lines depending on the ADC resolution
//#define ADC_10_BITS
#define ADC_12_BITS

#ifdef ADC_10_BITS
    #define ADC_RES 1024.0
#else
    #define ADC_RES 4096.0
#endif

//ADC full scale voltage
#define VREF 1.8

class bioimpedance : public QObject
{
    Q_OBJECT
public:
    explicit bioimpedance(QObject *parent = nullptr);
    bool setData(QByteArray rawdata);
    double getMagnitude();
    double getPhase();
    double getFrequency();
    int getFrequencyIndex(freqIndexType ftype);
    void calibrateMagnitude(double gainFactor);
    void calibratePhase(double phaseCorrection);

    void setMagnitude(double mag);
    void setPhase(double pha);
    void setFrequency(double freq);
    void setFrequencyIndex(quint8 freq_ind);

signals:

public slots:


private:
    double frequencies[11];
    double staticGains[8];

    QByteArray m_rawdata;
    bool m_valid;
    double m_mag;
    double m_pha;
    double m_I;
    double m_Q;
    double m_freq;
    double m_gain;
    quint8 m_freq_ind;
    quint8 m_gain_ind;

    quint8 calculateChecksum(const quint8 *data, quint8 num);
    void calculateIQ();
    bool extractGainFreq();
    void calculateImpedance();


};

#endif // BIOIMPEDANCE_H
