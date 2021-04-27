#include "nmessearch.h"
#include <QThread>

#include <QtMath>
#include <QFile>
#include <QTextStream>

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

    m_motorPoint.ch1 = 0;
    m_motorPoint.ch2 = 0;
}

void NMESsearch::scan(int num_electrodes, int amplitude)
{
    //Initialize
    m_num_cathodes = num_electrodes - 1; // Electrode 1 is set as anode
    m_amplitude = amplitude;

    m_ch1 = 1; // set initial anode
    m_ch2 = 2; // set initial cathode
    m_go = 1; // activate
    cleanChannels();
    CopyResetMaxEnergy();
    m_search_index = 0;

    //programNEMS(); // set channels and start NEMS
    programNEMSbin(); // set channels and start NEMS

    m_timer->start(m_timeout); //wait 2S

    QString aux = "** Scan search started "
                  + QString::number(m_amplitude)
                  + " mA **";
    updateSearchText(aux);
}

void NMESsearch::stopScan()
{
    // QByteArray data;

    m_timer->stop();
    m_go = 0;
    programNEMSbin();

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


void NMESsearch::programNEMSbin()
{
    QByteArray data;

    data.append('e');
    data.append((unsigned char)m_ch1);
    data.append((unsigned char)m_ch2);
    data.append((unsigned char)m_go);

    send(data);
}



void NMESsearch::scanArray()
{

}

void NMESsearch::saveMeasTxtFile()
{
    QString filename;
    filename = QString::number(m_amplitude) + "mA.csv";

    QFile outfile(filename);
    outfile.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream stream(&outfile);

    for (int i = 0; i < m_num_cathodes; i++) {
        stream << QString::number(i) << " "
               << QString::number(m_channel[i].maxEnergy) << "\n";
    }
    outfile.close();
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

    m_channel[m_search_index].maxEnergydB = dB;
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
        saveMeasTxtFile();
    }

}
