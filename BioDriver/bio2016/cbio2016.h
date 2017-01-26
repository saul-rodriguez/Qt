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

class CBIO2016 : public QObject
{
    Q_OBJECT
public:
    explicit CBIO2016(QObject *parent = 0);

    void clearbits();
    void setbits(bool F3, bool F2, bool F1, bool F0, bool IQ, bool GS3, bool GS2, bool GS1, bool GS0,
                 bool CE, bool NS, bool GD2, bool GD1, bool GD0, bool FS, bool RE);

    quint8 getByte0();
    quint8 getByte1();
    quint8 getByte(int index);

signals:

public slots:

private:
    BIO3 m_bio3;

};

#endif // CBIO2016_H
