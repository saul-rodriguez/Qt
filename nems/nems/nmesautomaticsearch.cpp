#include "nmesautomaticsearch.h"
#include <QDebug>
#include <QMessageBox>

NMESAutomaticSearch::NMESAutomaticSearch(QObject *parent) : QObject(parent)
{
    //Default values
    m_current = 6;
    m_stopCurrent = 10;
    m_numElectrodes = 4;

    m_channel_index = 0;
}

void NMESAutomaticSearch::start(int startCurrent, int stopCurrent, int numElectrodes)
{
    m_current = startCurrent;
    m_stopCurrent = stopCurrent;
    m_numElectrodes = numElectrodes;

    m_channel_index = 0;

    QMessageBox msgBox;

    QString aux = "Automatic Search: " + QString::number(m_current) + "mA";
    msgBox.setText(aux);
    msgBox.setInformativeText("Press Yes to start");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if (ret == QMessageBox::No) return;


    m_search->scan(m_numElectrodes,m_current);
}

void NMESAutomaticSearch::setSearch(NMESsearch *search)
{
    m_search = search;
}

int NMESAutomaticSearch::addMotorPoint(channel* motorpoint)
{
    m_motorpoints[m_channel_index] = *motorpoint;

    //Compare 3 previous motorpoints

    if (m_channel_index >= 2) {
        if (compareChannels(m_motorpoints[m_channel_index],m_motorpoints[m_channel_index-1]) &&
            compareChannels(m_motorpoints[m_channel_index],m_motorpoints[m_channel_index-2]))
        {
            // Motor point found

            qDebug()<< "Motor point found at " << m_current;
            qDebug()<< m_motorpoints[m_channel_index].ch1 << ":" <<
                       m_motorpoints[m_channel_index].ch2;
            return 1;
        }
    }

    if (m_current >= m_stopCurrent) {
        //Search finished without finding a motor point

        qDebug()<< "Max current reached without finding motorpoint";
        return 2;
    }

    //Increase current and search again
    m_channel_index++;
    m_current++;

    QString aux = "Automatic Search: " + QString::number(m_current) + "mA";

    QMessageBox msgBox;

    msgBox.setText(aux);
    msgBox.setInformativeText("Press Yes to start");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if (ret == QMessageBox::No) return 3; // Cancel search

    m_search->scan(m_numElectrodes,m_current);
    return 0;
}

int NMESAutomaticSearch::compareChannels(channel a, channel b)
{
    if ((a.ch1 == b.ch1) && (a.ch2 == b.ch2) ) {
        return 1;
    } else {
        return 0;
    }
}



