#ifndef NMESSENSOR_H
#define NMESSENSOR_H

#include <QObject>


#define DATA_POINTS 10
#define AVERAGE_POINTS 50

class NmesSensor : public QObject
{
    Q_OBJECT

private:
    double data_points[DATA_POINTS];
    double average_points[AVERAGE_POINTS];

    double average;
    double energy;
    bool data_valid;

    void calculateAverage();
    double calculateEnergy();

public:
    explicit NmesSensor(QObject *parent = nullptr);

    void test();
    void add_point(double value);
    void clear_datavalid();

    bool getDataValid();
    double getAverage();
    double getEnergy();


signals:

};

#endif // NMESSENSOR_H
