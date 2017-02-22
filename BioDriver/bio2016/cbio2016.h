#ifndef CBIO2016_H
#define CBIO2016_H

#include <QObject>

//Implantable structure
typedef struct BIO3_bits_stuct {
    unsigned RE     :1;
    unsigned FS     :1;
    unsigned GD0    :1;
    unsigned GD1    :1;
    unsigned GD2    :1;
    unsigned NS     :1;
    unsigned CE     :1;
    unsigned GS0    :1;
    unsigned GS1    :1;
    unsigned GS2    :1;
    unsigned GS3    :1;
    unsigned IQ     :1;
    unsigned F0     :1;
    unsigned F1     :1;
    unsigned F2     :1;
    unsigned F3     :1;
} BIO3_bits;

typedef union {
    //unsigned short data;
    quint16 data;
    BIO3_bits data_bits;
} BIO3;

#define BIO3_LENGTH 16

typedef struct RADIO_gain_bits_struct {
    unsigned GD0     :1;
    unsigned GD1     :1;
    unsigned GD2     :1;
    unsigned GS0     :1;
    unsigned GS1     :1;
    unsigned GS2     :1;
    unsigned GS3     :1;
    unsigned NOTUSED :1;

} RADIO_gain_bits;

typedef union {
    quint8 data;
    RADIO_gain_bits data_bits;
} RADIO_gain;

typedef struct RADIO_freq_bits_struct {
    unsigned F0     :1;
    unsigned F1     :1;
    unsigned F2     :1;
    unsigned F3     :1;
} RADIO_freq_bits;

typedef union {
    quint8 data;
    RADIO_freq_bits data_bits;
} RADIO_freq;

//Radio gain bit states

/*
#define GAIN0 0b00000100
#define GAIN1 0b00100100
#define GAIN2 0b01100100
#define GAIN3 0b01101100
#define GAIN4 0b01111100
#define GAIN5 0b01111101
#define GAIN6 0b01111111
#define GAIN7 0b01111011
*/


#define GAIN0 0b00000100
#define GAIN1 0b00000101
#define GAIN2 0b00000111
#define GAIN3 0b00000011
#define GAIN4 0b00100011
#define GAIN5 0b01100011
#define GAIN6 0b01101011
#define GAIN7 0b01111011


//Radio gain configuration
#define STAT_GAIN0 6.85864197530865E-07
#define STAT_GAIN1 2.05759259259259E-06
#define STAT_GAIN2 6.17277777777777E-06
#define STAT_GAIN3 1.85183333333333E-05
#define STAT_GAIN4 5.55555555555557E-05
#define STAT_GAIN5 0.0001666667
#define STAT_GAIN6 0.0005
#define STAT_GAIN7 0.0015

//Radio frequency bit states
#define FREQ0  0b00000000
#define FREQ1  0b00000001
#define FREQ2  0b00000010
#define FREQ3  0b00000011
#define FREQ4  0b00000100
#define FREQ5  0b00000101
#define FREQ6  0b00000110
#define FREQ7  0b00000111
#define FREQ8  0b00001000
#define FREQ9  0b00001001
#define FREQ10 0b00001010

//Radio Frequencies NS = 0
#define STAT_FREQ0   1.0e6
#define STAT_FREQ1   500.0e3
#define STAT_FREQ2   250.0e3
#define STAT_FREQ3   125.0e3
#define STAT_FREQ4   62500.0
#define STAT_FREQ5   31250.0
#define STAT_FREQ6   15625.0
#define STAT_FREQ7   7812.5
#define STAT_FREQ8   3906.25
#define STAT_FREQ9   1953.125
#define STAT_FREQ10   976.5625

#define FILT_FREQ0  0b00100000011000111
#define FILT_FREQ1  0b00100000011001111
#define FILT_FREQ2  0b00100000001101111
#define FILT_FREQ3  0b00100000000111111
#define FILT_FREQ4  0b01000100100001111
#define FILT_FREQ5  0b01000100000001111
#define FILT_FREQ6  0b01010010000001111
//#define FILT_FREQ7  0b01011001000001111
#define FILT_FREQ7  0b10000100100001111
#define FILT_FREQ8  0b10000100000001111
#define FILT_FREQ9  0b10010010000001111
#define FILT_FREQ10 0b10011001000001111

typedef struct VINfilt_bits_struct {
    unsigned CapSel0    :1;
    unsigned CapSel1    :1;
    unsigned CapSel2    :1;
    unsigned CapSel3    :1;
    unsigned CcompSel0  :1;
    unsigned CcompSel1  :1;
    unsigned EnRdegHF0  :1;
    unsigned EnRdegHF1  :1;

    unsigned EnRdeg     :1;
    unsigned DP0        :1;
    unsigned DP1        :1;
    unsigned DP2        :1;
    unsigned DN0        :1;
    unsigned DN1        :1;
    unsigned EnHF       :1;
    unsigned EnMF       :1;

    unsigned EnLF       :1;
} VINfilt_bits;

typedef union {
    quint32 data;
    VINfilt_bits data_bits;
} VINfilt;

class CBIO2016 : public QObject
{
    Q_OBJECT
public:
    explicit CBIO2016(QObject *parent = 0);

    void clearbits();
    void setbits(bool F3, bool F2, bool F1, bool F0, bool IQ, bool GS3, bool GS2, bool GS1, bool GS0,
                 bool CE, bool NS, bool GD2, bool GD1, bool GD0, bool FS, bool RE);
    //void setFreqbits(RADIO_freq &freq);

    void setADCvalues(quint16 vp, quint16 vn, quint16 vse);
    void getADCVoltages(double* vp, double* vn, double* vse);


    void getImpedance(double* mag, double* pha, double v_I, double v_Q);
    void setMixerGainFactor(double factor);
    int getGainIndex();
    quint8 getGainBits(int i);

    double getFreqValue(int index);

    quint8 getByte0();
    quint8 getByte1();
    quint8 getByte(int index);



    //filter
    void setbitsFilter(bool EnLF, bool EnMF, bool EnHF, bool DN1, bool DN0, bool DP2, bool DP1, bool DP0, bool EnRdeg,
                       bool EnRdegHF1, bool EnRdegHF0, bool CcompSel1, bool CcompSel0, bool CapSel3, bool CapSel2, bool CapSel1, bool CapSel0);
    void setbitFilterbyFreq(int index);
    VINfilt getFilter();
    quint8 getFilterByte(int index);



signals:

public slots:

private:
    BIO3 m_bio3;
    RADIO_gain m_gain;
    RADIO_freq m_freq;
    quint8 gains[8];
    double static_gain[8];
    double mixer_gain_factor;

    double freqs[11];

    quint16 m_vp,m_vn,m_vse;

    //Vinnova filter
    VINfilt m_filt;
    quint32 filter_conf[11];

};

#endif // CBIO2016_H
