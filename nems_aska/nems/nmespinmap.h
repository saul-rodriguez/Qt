#ifndef NMESPINMAP_H
#define NMESPINMAP_H

#include <QObject>


class NMESPinMap : public QObject
{
    Q_OBJECT

    unsigned char pins[33];

public:
    explicit NMESPinMap(QObject *parent = nullptr);

    void loadMapping();
    void writeStandardMappingFile(QString filename);
    unsigned char getPin(unsigned char ind); //get physical pin
    QString getPinString(QString pin); //get physical pin String
    QString getIndString(QString pin); //get logical pin index

signals:

};

#endif // NMESPINMAP_H
