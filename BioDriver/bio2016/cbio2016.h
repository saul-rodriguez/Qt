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

//Radio gain states
#define GAIN0 0b00000100
#define GAIN1 0b00100100
#define GAIN2 0b01100100
#define GAIN3 0b01101100
#define GAIN4 0b01111100
#define GAIN5 0b01111101
#define GAIN6 0b01111111
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

class CBIO2016 : public QObject
{
    Q_OBJECT
public:
    explicit CBIO2016(QObject *parent = 0);

    void clearbits();
    void setbits(bool F3, bool F2, bool F1, bool F0, bool IQ, bool GS3, bool GS2, bool GS1, bool GS0,
                 bool CE, bool NS, bool GD2, bool GD1, bool GD0, bool FS, bool RE);

    void setADCvalues(quint16 vp, quint16 vn, quint16 vse);
    void getADCVoltages(double* vp, double* vn, double* vse);
    void getImpedance(double* mag, double* pha, double v_I, double v_Q);
    void setMixerGainFactor(double factor);
    int getGainIndex();

    quint8 getByte0();
    quint8 getByte1();
    quint8 getByte(int index);

signals:

public slots:

private:
    BIO3 m_bio3;
    RADIO_gain m_gain;
    quint8 gains[8];
    double static_gain[8];
    double mixer_gain_factor;

    quint16 m_vp,m_vn,m_vse;

};

#endif // CBIO2016_H
