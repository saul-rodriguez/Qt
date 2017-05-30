#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <QObject>
#include <complex>

class Calibration : public QObject
{
    Q_OBJECT
public:
    explicit Calibration(QObject *parent = 0);

    void setCalParam(double *magcal, double *magpha);
    void setCableCap(double cap);
    void setCalibrateCableCap(bool param);
    void setMeasImpedance(double mag, double pha, quint8 freqIndex);
    void getCalImpedance(double *mag, double *pha);
    void setAddedRes(double res);
    void setCalibrateAddedRes(bool param);

private:

    bool usecap;
    bool useAddedRes;

    double m_measMag;
    double m_measPha;
    quint8 m_freqIndex;

    // Calibration parameters
    double m_magcal[11];
    double m_phacal[11];
    double m_freq[11];

    double m_cap; // Cables capacitance

    double m_res; // Added Parallel Resistor

signals:

public slots:
};

#endif // CALIBRATION_H
