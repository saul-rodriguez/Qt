#include "nmessearch.h"
#include <QThread>

#include <QtMath>

NMESsearch::NMESsearch(QObject *parent) : QObject(parent)
{

    m_search_index = 0;

    //Scan all cathodes method initialization;
    m_ch1 = 1;
    m_ch2 = 2;
    m_go = 0;
    m_num_cathodes = NUM_CATHODES;
    m_maxEnergy = 0;

    cleanChannels();

    // Each search takes m_timeout ms
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()),this,SLOT(SearchTimeout()));
    m_timeout = 2500;

    m_prog_state = IDLE;
    m_conf_timer = new QTimer(this);
    m_conf_timer->setSingleShot(true);
    connect(m_conf_timer, SIGNAL(timeout()),this,SLOT(programTimeout()));

    m_prog_CH_state = IDLE;
    m_conf_CH_timer = new QTimer(this);
    m_conf_CH_timer->setSingleShot(true);
    connect(m_conf_CH_timer, SIGNAL(timeout()),this,SLOT(programChTimeout()));


    m_motorPoint.ch1 = 0;
    m_motorPoint.ch2 = 0;
}

void NMESsearch::scan(int num_electrodes)
{
    //Initialize
    m_num_cathodes = num_electrodes - 1; // Electrode 1 is set as anode

    m_ch1 = 1; // set initial anode
    m_ch2 = 2; // set initial cathode
    m_go = 1; // activate
    cleanChannels();
    CopyResetMaxEnergy();
    m_search_index = 0;

    //programNEMS(); // set channels and start NEMS
    programNEMSbin(); // set channels and start NEMS

    m_timer->start(m_timeout); //wait 2S
    updateSearchText("** Scan search started **");
}

void NMESsearch::stopScan()
{
     QByteArray data;

    m_timer->stop();
    data.append("N");
    send(data);

}

bool NMESsearch::isActive()
{
    return m_timer->isActive();
}

void NMESsearch::updateMaxEnergy(int maxEnergy)
{
    m_maxEnergy = maxEnergy;
}

channel NMESsearch::getMotorPoint()
{
    channel aux;
    aux.maxEnergy = 0;

    for (int i=0; i < m_num_cathodes; i++) {
        if (m_channel[i].maxEnergy > aux.maxEnergy) {
            aux = m_channel[i];
        }
    }

    m_motorPoint = aux;

    return aux;
}

void NMESsearch::cleanChannels()
{
    for (int i = 0; i < m_num_cathodes; i++) {
        m_channel->ch1 = 0;
        m_channel->ch2 = 0;
        m_channel->maxEnergy = 0;
    }
}

void NMESsearch::programNEMS()
{
    QByteArray data;

    switch (m_prog_state) {
        case (IDLE):
            m_prog_state = CH1;
            if (m_ch1 < 10) {
                data.append("M0");
            } else {
                data.append("M");
            }

            data.append(QString::number(m_ch1));
            send(data);

            m_conf_timer->start(150);
            break;

        case (CH1):
            m_prog_state = CH2;
            if (m_ch2 < 10) {
                data.append("m0");
            } else {
                data.append("m");
            }

            data.append(QString::number(m_ch2));
            send(data);
            m_conf_timer->start(150);
            break;

        case (CH2):
            m_prog_state = GO;

            data.append("n");
            send(data);
            //m_conf_timer->start(150);
            break;

        case (GO):
            m_prog_state = IDLE;
            data.append("N");
            send(data);
            m_conf_timer->start(150);
            break;

        default:
            m_conf_timer->stop();
            m_prog_state = IDLE;
            break;
    }

}

void NMESsearch::programNEMSbin()
{
    QByteArray data;

    data.append('e');
    data.append((unsigned char)m_ch1);
    data.append((unsigned char)m_ch2);
    data.append((unsigned char)m_go);

    send(data);

}

void NMESsearch::programCH()
{
    QByteArray data;

    switch (m_prog_CH_state) {
        case (IDLE):
            m_prog_CH_state = CH1;
            if (m_motorPoint.ch1 < 10) {
                data.append("M0");
            } else {
                data.append("M");
            }

            data.append(QString::number(m_motorPoint.ch1));
            send(data);

            m_conf_CH_timer->start(150);
            break;

        case (CH1):
            m_prog_CH_state = IDLE;
            if (m_motorPoint.ch2 < 10) {
                data.append("m0");
            } else {
                data.append("m");
            }

            data.append(QString::number(m_motorPoint.ch2));
            send(data);
            //m_conf_CH_timer->start(150);
            m_conf_CH_timer->stop();
            break;

        default:
            m_conf_CH_timer->stop();
            m_prog_CH_state = IDLE;
            break;
    }



}

void NMESsearch::scanArray()
{

}

void NMESsearch::SearchTimeout()
{
    QString aux;

    //Update MaxEnergy and clears it in the gui for the next iteration
    CopyResetMaxEnergy();

    //Store channel information
    m_channel[m_search_index].ch1 = m_ch1;
    m_channel[m_search_index].ch2 = m_ch2;
    m_channel[m_search_index].maxEnergy = m_maxEnergy;

    aux = "iteration " + QString::number(m_search_index);
    aux += " " + QString::number(m_ch1) +",";
    aux += QString::number(m_ch2) + ": ";
    aux += QString::number(m_maxEnergy) + " ";

    double dB = 10*qLn(m_maxEnergy)/qLn(10);
    aux += QString::number((int)dB) + " dB";


    //aux += "\n";
    updateSearchText(aux);

    m_maxEnergy = 0;

    /*Search algorithm here*/
    if (m_search_index < (m_num_cathodes-1)) {
        m_search_index++;
        m_ch2 = 2 + m_search_index;
        //programNEMS(); // advance to next iteration
        programNEMSbin(); // advance to next iteration

        m_timer->start(m_timeout);
    } else { // Finish search
        m_search_index = 0;

        stopScan();
        //m_timer->stop();
        updateSearchText("** Scan search finished **");
        scanDone();
    }

}

void NMESsearch::programTimeout()
{
    programNEMS();
}

void NMESsearch::programChTimeout()
{
    programCH();
}
