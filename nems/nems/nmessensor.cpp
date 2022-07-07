#include "nmessensor.h"
#include "qdebug.h"
#include <QtMath>

NmesSensor::NmesSensor(QObject *parent) : QObject(parent)
{

    for (int i = 0; i < DATA_POINTS; i++) {
        data_points[i] = 0;
    }

    for (int i = 0; i < AVERAGE_POINTS; i++) {
        average_points[i] = 0;
    }

    average = 0;
    data_valid = true;
}

void NmesSensor::test()
{
    double aux;

    for (int i = 0; i < 100; i++) {
        add_point(100);
    }

    for (int i = 0; i < DATA_POINTS; i++) {
        aux = 100 + 10*qSin(2*3.1416*i/DATA_POINTS);
        add_point(aux);
    }

    for (int i = 0; i < 100; i++) {
        add_point(100);
    }
}

void NmesSensor::add_point(double value)
{
    double aux[DATA_POINTS];
    double aux2[AVERAGE_POINTS];

    //Check if data is valid
    //if (value > 4095) {
    if (value > 3095) { // Only to test manually
      data_valid = false;
      qDebug()<<"sensor data error";
      //return;
    }

    // data_valid needs to be externally reset in order
    // to continue processing data
    //if (data_valid == false) {
    //    return;
   // }


    //insert new data value and discard the last point
    for (int i=1; i < DATA_POINTS; i++) {
        aux[i] = data_points[i-1];
    }
    aux[0] = value;

    for (int i=0; i < DATA_POINTS; i++) {
        data_points[i] = aux[i];
    }


    for (int i=1; i < AVERAGE_POINTS; i++) {
        aux2[i] = average_points[i-1];
    }
    aux2[0] = value;

    for (int i=0; i < AVERAGE_POINTS; i++) {
        average_points[i] = aux2[i];
    }

    //recalculate average and energy
    calculateAverage();
    calculateEnergy();
}

void NmesSensor::clear_datavalid()
{
    data_valid = true;
}

bool NmesSensor::getDataValid()
{
    return data_valid;
}

void NmesSensor::calculateAverage()
{
    double aux;

    aux = 0;
    for (int i=0; i < AVERAGE_POINTS; i++) {
        aux += average_points[i];
    }

    aux /= AVERAGE_POINTS;

    average = aux;
}

double NmesSensor::calculateEnergy()
{
    double ac_signal[DATA_POINTS];
    double ac_energy;

    for (int i = 0; i < DATA_POINTS; i++) {
        ac_signal[i] = data_points[i] - average;
    }

    ac_energy = 0;
    for (int i = 0; i < DATA_POINTS; i++) {
        ac_energy += ac_signal[i]*ac_signal[i];
    }

    energy = ac_energy;

    return energy;

}

double NmesSensor::getAverage()
{
    return average;
}

double NmesSensor::getEnergy()
{
    return energy;
}

