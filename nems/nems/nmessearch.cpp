#include "nmessearch.h"
#include <QThread>

#include <QtMath>
#include <QFile>
#include <QTextStream>
#include <QDebug>

NMESsearch::NMESsearch(QObject *parent) : QObject(parent)
{

    m_search_index = 0;

    //Scan all cathodes method initialization;
    m_ch1 = 1;
    m_ch2 = 2;
    m_go = 0;
    m_amplitude = 0;
    m_anode = 1;
    m_start_cathodes = 2;
    m_stop_cathodes = NUM_CATHODES;
    m_super_electrode = 0;

    m_maxEnergy = 0;
    m_maxEnergy2 = 0;

    cleanChannels();

    // Each search takes m_timeout ms
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()),this,SLOT(SearchTimeout()));
    m_timeout = 2500;

    m_motorPoint.ch1 = 0;
    m_motorPoint.ch2 = 0;
}

void NMESsearch::scan(int anode, int start_electrodes, int stop_electrodes, int amplitude, int super_electrode, int period)
{
    //Initialize
    m_anode = anode;
    m_start_cathodes = start_electrodes;
    m_stop_cathodes = stop_electrodes;
    m_amplitude = amplitude;
    m_super_electrode = super_electrode;

    m_ch1 = m_anode; // set initial anode
    //m_ch2 = m_anode + 1; // set initial cathode
    m_ch2 = m_start_cathodes; // set initial cathode
    m_go = 1; // activate
    cleanChannels();
    CopyResetMaxEnergy();
    m_search_index = 0;

    //programNEMS(); // set channels and start NEMS
    programNEMSbin(); // set channels and start NEMS

    m_timeout = period;
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
    m_search_index = 0;
    m_go = 0;
    programNEMSbin();

}

bool NMESsearch::isActive()
{
    return m_timer->isActive();
}

void NMESsearch::updateMaxEnergy(int maxEnergy, int maxEnergy2)
{
    m_maxEnergy = maxEnergy;
    m_maxEnergy2 = maxEnergy2;

   // m_totEnergy = qSqrt((m_maxEnergy*m_maxEnergy )+ (m_maxEnergy2*m_maxEnergy2));
    m_totEnergy = maxEnergy + maxEnergy2;
}

channel NMESsearch::getMotorPoint()
{
    channel aux;
    aux.maxEnergy = 0;
    aux.maxEnergy2 = 0;
    aux.totEnergy = 0;

    int stop_count;

    if(m_super_electrode) {
        stop_count = m_stop_cathodes - m_start_cathodes - 4;
         stop_count = (m_stop_cathodes - m_start_cathodes+1)/4;
    } else {
        stop_count = m_stop_cathodes - m_start_cathodes;
    }

    //for (int i=0; i < (m_stop_cathodes - m_anode); i++) {
    for (int i=0; i < (stop_count+1); i++) {
        //if (m_channel[i].maxEnergy > aux.maxEnergy) {
        if (m_channel[i].totEnergy > aux.totEnergy) {
            aux = m_channel[i];
        }
    }

    m_motorPoint = aux;

    return aux;
}

void NMESsearch::cleanChannels()
{

    /*
    int stop_count;

    if(m_super_electrode) {
        //stop_count = m_stop_cathodes - m_start_cathodes - 4;
        stop_count = (m_stop_cathodes - m_start_cathodes+1)/4;
    } else {
        stop_count = m_stop_cathodes - m_start_cathodes;
    }
    */

    for (int i = 0; i < (NUM_CATHODES); i++) {
        m_channel->ch1 = 0;
        m_channel->ch2 = 0;
        m_channel->maxEnergy = 0;
        m_channel->maxEnergy2 = 0;
        m_channel->totEnergy = 0;
    }
}


void NMESsearch::programNEMSbin()
{
    QByteArray data;

    data.append('e');
    data.append((unsigned char)m_amplitude);
    data.append((unsigned char)m_ch1);
    data.append((unsigned char)m_ch2);
    data.append((unsigned char)m_go);
    data.append((unsigned char)m_super_electrode);

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

    for (int i = 0; i < (m_stop_cathodes - m_anode); i++) {
        stream << QString::number(i) << " "
               << QString::number(m_channel[i].maxEnergy) << " " <<
                  QString::number(m_channel[i].maxEnergy2) << " " <<
                  QString::number(m_channel[i].totEnergy) << " " <<
                  "\n";
    }
    outfile.close();
}

void NMESsearch::SearchTimeout()
{
    //Update MaxEnergy and clears it in the gui for the next iteration
    CopyResetMaxEnergy();
    qDebug()<<"reset energy";

    //Store channel information
    m_channel[m_search_index].ch1 = m_ch1;
    m_channel[m_search_index].ch2 = m_ch2;
    m_channel[m_search_index].maxEnergy = m_maxEnergy;
    m_channel[m_search_index].maxEnergy2 = m_maxEnergy2;
    m_channel[m_search_index].totEnergy = m_totEnergy;

    //Update text in GUI
    QString aux;
    aux =  QString::number(m_search_index);
    aux += " (" + QString::number(m_ch1) +",";
    aux += QString::number(m_ch2) + ") S1: ";
    aux += QString::number(m_maxEnergy) + " ";

    double dB = 10*qLn(m_maxEnergy)/qLn(10);
    aux += QString::number((int)dB) + " dB,  S2: ";

    aux += QString::number(m_maxEnergy2) + " ";
    double dB2 = 10*qLn(m_maxEnergy2)/qLn(10);
    aux += QString::number((int)dB2) + " dB,  Tot: ";

    aux += QString::number(m_totEnergy) + " ";
    double tot = 10*qLn(m_totEnergy)/qLn(10);
    aux += QString::number((int)tot) + " dB";

    m_channel[m_search_index].maxEnergydB = dB;
    m_channel[m_search_index].maxEnergy2dB = dB2;
    m_channel[m_search_index].totEnergydB = dB2;

    //aux += "\n";
    updateSearchText(aux);

    m_maxEnergy = 0;
    m_maxEnergy2 = 0;

    /*Search algorithm here*/

    int stop_count;

    if(m_super_electrode) {
        stop_count = (m_stop_cathodes - m_start_cathodes+1)/4;
    } else {
        stop_count = m_stop_cathodes - m_start_cathodes;
    }




     if (m_search_index < stop_count) {
        if (m_super_electrode) {
            //m_search_index+=4;
            m_search_index++;
            m_ch2+=4;
        } else {
            m_search_index++;
            m_ch2++;
        }

        programNEMSbin(); // advance to next iteration

        m_timer->start(m_timeout);
    } else { // Finish search
        saveMeasTxtFile();
        m_search_index = 0;
        stopScan();
        //m_timer->stop();
        updateSearchText("** Scan search finished **");
        scanDone();

    }

}

