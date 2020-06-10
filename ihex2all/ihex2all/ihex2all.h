#ifndef IHEX2ALL_H
#define IHEX2ALL_H

#include <QObject>

class ihex2all : public QObject
{
    Q_OBJECT
public:
    explicit ihex2all(QObject *parent = nullptr);

    QString filenameIn;
    QString filenameOut;

    QStringList HEXdata4;
    void readFile();
    void readArgument(int arg, char *argv[]);
    void savehex4();
signals:

};

#endif // IHEX2ALL_H
