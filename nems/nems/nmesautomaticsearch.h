#ifndef NMESAUTOMATICSEARCH_H
#define NMESAUTOMATICSEARCH_H

#include "nmessearch.h"

#include <QObject>


#define MAX_CHANNELS 32

class NMESAutomaticSearch : public QObject
{
    Q_OBJECT

public:
    int m_current;
    int m_stopCurrent;

    int m_anode;
    int m_stopElectrodes;
    int m_startElectrodes;

    int m_SuperElectrode;

    channel m_motorpoints[MAX_CHANNELS];
    int m_channel_index;

    NMESsearch *m_search;

public:
    explicit NMESAutomaticSearch(QObject *parent = nullptr);

    void start(int startCurrent, int stopCurrent, int anode, int stopElectrodes, int startElectrodes, int SuperElectrode);
    void setSearch(NMESsearch *search);
    int addMotorPoint(channel *motorpoint);
    int  compareChannels(channel a, channel b);


signals:

};

#endif // NMESAUTOMATICSEARCH_H
