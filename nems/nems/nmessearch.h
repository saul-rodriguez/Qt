#ifndef NMESSEARCH_H
#define NMESSEARCH_H

#include <QObject>
#include <QTimer>

//Electrode Matrix order
#define N 16
#define NUM_CATHODES 14

typedef enum {
    IDLE,
    CH1,
    CH2,
    GO,
    END
} NMES_prog_state;

typedef struct channel_struct {
    int ch1;
    int ch2;
    int maxEnergy;
} channel;

class NMESsearch : public QObject
{
    Q_OBJECT
public:
    explicit NMESsearch(QObject *parent = nullptr);

    int m_search_index;
    int m_maxEnergy;

    //Scan method with 1 anode in ch1 and M cathodes
    channel m_channel[NUM_CATHODES];
    unsigned int m_ch1;
    unsigned int m_ch2;
    int m_num_cathodes;

    int m_timeout;
    QTimer *m_timer;

    QTimer *m_conf_timer;
    NMES_prog_state m_prog_state;

    QTimer *m_conf_CH_timer;
    NMES_prog_state m_prog_CH_state;
    channel m_motorPoint;

    void scan();
    void stopScan();
    bool isActive();
    void updateMaxEnergy(int maxEnergy);
    channel getMotorPoint();
    void cleanChannels();

    void programNEMS();
    void programCH();

    void scanArray();

signals:
    void send(QByteArray data);
    void updateSearchText(QString text);
    void CopyResetMaxEnergy();
    void scanDone();


private slots:
    void SearchTimeout();
    void programTimeout();
    void programChTimeout();

};

#endif // NMESSEARCH_H
