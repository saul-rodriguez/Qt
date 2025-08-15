#include "nmespinmap.h"

#include <QStandardPaths>
#include <QDebug>
#include <QFile>

NMESPinMap::NMESPinMap(QObject *parent)
    : QObject{parent}
{
    //All pins initialize to 0
    for (int i=0; i < 33; i++) {
        pins[i] = 0;
    }
}

void NMESPinMap::loadMapping()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    qDebug() << "Download path: " << path;

    QString filename = path.append("/pins.txt");

    QFile auxfile(filename);
    int ret = auxfile.open(QIODevice::ReadOnly);

    //if file unavalilable,create it initialize
    //it to standard pin config
    if (!ret) {
        qDebug()<<"pins.txt does not exist";
        writeStandardMappingFile(filename);

        //Standard configuration original NMES
        for (int i=0; i < 33; i++) {
            pins[i] = i;
        }
        return;
    }

    QTextStream in(&auxfile);
    QStringList lines;
    QString line;
    QStringList line_split;

    while(!in.atEnd()) {
        lines << in.readLine();
    }
    auxfile.close();

    int N = lines.length();

    if (N < 33) {
        qDebug() << "Wrong file size";
        return;
    }

    int ind,val;
    pins[0] =0; //pin 0 means not connected and must always be 0!
    for (int i=1; i<33; i++) {
        line = lines[i];
        line_split = line.split(" ");
        ind = line_split[0].toInt();
        val = line_split[1].toInt();

        if (ind > 32 || val > 32) {
            qDebug() << "Wrong pin value";
            return;
        }

        pins[ind] = val;
    }
}

void NMESPinMap::writeStandardMappingFile(QString filename)
{
    QFile outfile(filename);
        outfile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
        QTextStream stream(&outfile);

        QString aux;
        for (int i = 0; i < 33; i++) {
               aux = QString::number(i);
               stream << aux << " " << aux << "\n";
        }

        outfile.close();

}

unsigned char NMESPinMap::getPin(unsigned char ind)
{
    return pins[ind];
}

QString NMESPinMap::getPinString(QString pin)
{
    QString aux_pin;
    aux_pin = "0";
    int aux = pin.toInt();

    if (aux > 32) {
        qDebug() << "Wrong pin value! pin > 33";
        return aux_pin;
    }

    int mapped = pins[aux];
    aux_pin = QString::number(mapped);
    return aux_pin;
}

QString NMESPinMap::getIndString(QString pin)
{
    QString inds;
    inds = "0";

    int ind = pin.toInt();

    for (int i=1; i < 33; i++) {
        if (pins[i] == ind) {
            inds = QString::number(i);
            return inds;
        }
    }

    return inds;
}











