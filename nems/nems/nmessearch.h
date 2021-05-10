#ifndef NMESSEARCH_H
#define NMESSEARCH_H

#include <QObject>
#include <QTimer>

//Electrode Matrix order
#define NUM_CATHODES 31

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

    int m_timeout;
    QTimer *m_timer;

    channel m_motorPoint;

    void scan(int anode, int start_electrodes, int stop_electrodes, int amplitude, int super_electrode);
    void stopScan();
    bool isActive();

    void updateMaxEnergy(int maxEnergy, int maxEnergy2);
    channel getMotorPoint();
    void cleanChannels();

    void programNEMSbin();

    void scanArray();
    void saveMeasTxtFile();

signals:
    void send(QByteArray data);
    void updateSearchText(QString text);
    void CopyResetMaxEnergy();
    void scanDone();

private slots:
    void SearchTimeout();  

};

#endif // NMESSEARCH_H
