#ifndef NMESDUALMP_H
#define NMESDUALMP_H

#include <QObject>
#include <QTimer>

typedef struct dual_motorPoint_struct {
    int amp1;
    int amp2;
    int ch1_1;
    int ch1_2;
    int ch2_1;
    int ch2_2;
    int delay;
    int ON;
    int rampUp;
    int rampDown;
} dual_motorPoint;

typedef enum {
    IDLE,
    MP1,
    MP2,
} dual_state_t;

class NMESDualMP : public QObject
{
    Q_OBJECT

    QTimer *m_timer_dualStim;

    //int m_amp1;
    //int m_amp2;
    //int m_ch1_1;
    //int m_ch1_2;
    //int m_ch2_1;
    //int m_ch2_2;
    int m_delay;

    dual_motorPoint m_dualMP;
    dual_state_t m_state;

public:
    explicit NMESDualMP(QObject *parent = nullptr);

    void start(dual_motorPoint *config);


signals:
    void send(QByteArray data);

public slots:
    void DualStimulationTimeout();
};

#endif // NMESDUALMP_H
