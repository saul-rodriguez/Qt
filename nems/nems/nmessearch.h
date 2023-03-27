#ifndef NMESSEARCH_H
#define NMESSEARCH_H

#include "nmespinmap.h"
#include <QObject>
#include <QTimer>

//Electrode Matrix order
#define NUM_CATHODES 31

#define REFERENCE_ALG 0
#define PERMUTATION_ALG 1

typedef struct channel_struct {
    int ch1;
    int ch2;
    int maxEnergy;
    int maxEnergy2;
    int totEnergy;
    double maxEnergydB;
    double maxEnergy2dB;
    double totEnergydB;
} channel;

class NMESsearch : public QObject
{
    Q_OBJECT
public:
    explicit NMESsearch(QObject *parent = nullptr);

    int m_search_index;
    int m_maxEnergy;
    int m_maxEnergy2;
    int m_totEnergy;

    bool m_data_valid1;
    bool m_data_valid2;

    //Scan method with 1 anode in ch1 and M cathodes
    channel m_channel[NUM_CATHODES];
    unsigned int m_ch1;
    unsigned int m_ch2;
    unsigned int m_go;
    int m_anode;
    int m_start_cathodes;
    int m_stop_cathodes;
    int m_amplitude;
    int m_super_electrode;

    int m_algorithm;

    int m_timeout;
    QTimer *m_timer;
    QTimer *m_timer_error;

    channel m_motorPoint;

    //Pin mapping
    NMESPinMap *m_pinmap;

    void scan(int anode, int start_electrodes, int stop_electrodes, int amplitude, int super_electrode, int period);
    void stopScan();
    bool isActive();

    void updateMaxEnergy(int maxEnergy, int maxEnergy2);
    void updateDataValid(bool dv1, bool dv2);

    channel getMotorPoint();
    void cleanChannels();

    void programNEMSbin();

    void scanArray();
    void saveMeasTxtFile();

    void referenceAlgorithmSearch();
    void allPermutationSearch();

    void setAlgorithm(int alg);

    void setMappingPins(NMESPinMap *pinmap);

signals:
    void send(QByteArray data);
    void updateSearchText(QString text);
    void CopyResetMaxEnergy();
    void scanDone();


private slots:
    void SearchTimeout();
    void ErrorTimeout();


};

#endif // NMESSEARCH_H
