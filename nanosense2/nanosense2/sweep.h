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
    int getCount();
    DataTrace getTraceMag();
    DataTrace getTracePha();

signals:

public slots:


private:
    //bioimpedance* pbioimpedance;
    QList<bioimpedance*> m_measurement;
};

#endif // SWEEP_H
