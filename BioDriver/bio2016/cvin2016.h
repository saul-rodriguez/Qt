#ifndef CVIN2016_H
#define CVIN2016_H

#include <QObject>

//Vinnova structure
typedef struct VIN_bits_stuct {
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
} VIN_bits;

typedef union {
    //unsigned short data[3];
    quint64 data64;
    quint16 data[3];
    VIN_bits data_bits;
} VIN;

#define VIN_LENGTH 33

class CVIN2016 : public QObject
{
    Q_OBJECT
public:
    explicit CVIN2016(QObject *parent = 0);

    void clearbits();

    void setbitsRadio(bool F3, bool F2, bool F1, bool F0, bool IQ, bool GS3, bool GS2, bool GS1, bool GS0,
                 bool CE, bool NS, bool GD2, bool GD1, bool GD0, bool FS, bool RE);

    void setbitsFilter(bool EnLF, bool EnMF, bool EnHF, bool DN1, bool DN0, bool DP2, bool DP1, bool DP0, bool EnRdeg,
                       bool EnRdegHF1, bool EnRdegHF0, bool CcompSel1, bool CcompSel0, bool CapSel3, bool CapSel2, bool CapSel1, bool CapSel0);

    quint8 getByte(int index);
signals:

public slots:

private:
    VIN m_vin;
};

#endif // CVIN2016_H
