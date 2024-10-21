#ifndef SWEEP_H
#define SWEEP_H

#include <QObject>
#include "bioimpedance.h"
#include "cplotchart.h"

class sweep : public QObject
{
    Q_OBJECT
public:
    explicit sweep(QObject *parent = nullptr);
    void addImpedance(bioimpedance *impedance);
    void cleanSweep();
    void printSweep();
    QString getSweep();
    int getCount();
    DataTrace getTraceMag();
    DataTrace getTracePha();
    //void setSweep(QList<bioimpedance*> aux);
    QList<bioimpedance*> m_measurement;

signals:

public slots:


private:
    //bioimpedance* pbioimpedance;
    //QList<bioimpedance*> m_measurement;
};

#endif // SWEEP_H
