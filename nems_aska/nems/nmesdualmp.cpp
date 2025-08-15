#include "nmesdualmp.h"

NMESDualMP::NMESDualMP(QObject *parent) : QObject(parent)
{
    //m_amp1 = 0;
    //m_amp2 = 0;

    //m_ch1_1 = 0;
    //m_ch1_2 = 0;

    //m_ch2_1 = 0;
    //m_ch2_2 = 0;

    m_delay = 0;

    m_state = IDLE;

    m_timer_dualStim = new QTimer(this);
    m_timer_dualStim->setSingleShot(true);
    connect(m_timer_dualStim, SIGNAL(timeout()), this, SLOT(DualStimulationTimeout()));

}

void NMESDualMP::start(dual_motorPoint *config)
{
    m_dualMP = *config;
    unsigned char go = 1;
    unsigned char super_electrode = 0;

    //int delay;

    m_delay = m_dualMP.delay +
            m_dualMP.rampUp +
            m_dualMP.rampDown +
            m_dualMP.ON;


    //m_timer_dualStim->start(m_delay);
    m_timer_dualStim->start(2000);

    m_state = MP1;


}

void NMESDualMP::setPinMap(NMESPinMap *pinmap)
{
    m_pinmap = pinmap;
}

void NMESDualMP::DualStimulationTimeout()
{
    QByteArray data;
    unsigned char go;
    unsigned char super_electrode;

    unsigned char aux;

    super_electrode = 0;

    switch(m_state) {
        case IDLE:
            m_timer_dualStim->stop();
            break;
        case MP1:
            // Start Channel 1
            go = 1;
            data.append('e');
            data.append((unsigned char)m_dualMP.amp1);
            //data.append((unsigned char)m_dualMP.ch1_1);
            //data.append((unsigned char)m_dualMP.ch1_2);

            aux = m_pinmap->getPin(m_dualMP.ch1_1);
            data.append((unsigned char)aux);

            aux = m_pinmap->getPin(m_dualMP.ch1_2);
            data.append((unsigned char)aux);

            data.append((unsigned char)go);
            data.append((unsigned char)super_electrode);
            send(data);
            m_state = MP2;
            m_timer_dualStim->start(m_delay);
            break;

        case MP2:
            // Start Channel 2
            go = 1;
            data.append('e');
            data.append((unsigned char)m_dualMP.amp2);
            //data.append((unsigned char)m_dualMP.ch2_1);
            //data.append((unsigned char)m_dualMP.ch2_2);

            aux = m_pinmap->getPin(m_dualMP.ch2_1);
            data.append((unsigned char)aux);

            aux = m_pinmap->getPin(m_dualMP.ch2_2);
            data.append((unsigned char)aux);

            data.append((unsigned char)go);
            data.append((unsigned char)super_electrode);
            send(data);
            m_state = STOP;
            m_timer_dualStim->start(m_delay);
            break;

        case STOP:
            // Stop Stimulation
            go = 0;
            data.append('e');
            data.append((unsigned char)m_dualMP.amp2);
            //data.append((unsigned char)m_dualMP.ch2_1);
            //data.append((unsigned char)m_dualMP.ch2_2);

            aux = m_pinmap->getPin(m_dualMP.ch2_1);
            data.append((unsigned char)aux);

            aux = m_pinmap->getPin(m_dualMP.ch2_2);
            data.append((unsigned char)aux);

            data.append((unsigned char)go);
            data.append((unsigned char)super_electrode);
            send(data);
            m_state = IDLE;
            break;

        default:
            m_state = IDLE;

    }

}
