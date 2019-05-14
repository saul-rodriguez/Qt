#include "sweep.h"
#include <QDebug>

sweep::sweep(QObject *parent) : QObject(parent)
{
    m_measurement.clear();
}

void sweep::addImpedance(bioimpedance* impedance)
{
    //bioimpedance a;

   m_measurement << impedance;


   // m_measurement.append(a);
}

void sweep::cleanSweep()
{
    qDeleteAll(m_measurement.begin(),m_measurement.end());
    m_measurement.clear();
}

void sweep::printSweep()
{
    int N = m_measurement.size();

    for (int i = 0; i < N; i++) {
        qDebug()<<"Freq = "<<m_measurement[i]->getFrequency()<<", mag = "<<m_measurement[i]->getMagnitude()<<", pha = "<<m_measurement[i]->getPhase();
    }
}

int sweep::getCount()
{
    return m_measurement.size();
}

DataTrace sweep::getTrace()
{
    DataPoint aux_point;
    DataTrace aux_trace;

    int count = m_measurement.size();

    for (int i=0; i < count; i++) {
        aux_point.first.setX(m_measurement[i]->getFrequency());
        aux_point.first.setY(m_measurement[i]->getMagnitude());
        aux_point.second = QString::number(m_measurement[i]->getFrequency());

        aux_trace.append(aux_point);

    }

    return aux_trace;
}
