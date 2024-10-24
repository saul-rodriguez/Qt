#ifndef CFORMSPARSER_H
#define CFORMSPARSER_H

#include <QObject>


class Cformsparser : public QObject
{
    Q_OBJECT
public:
    explicit Cformsparser(QObject *parent = nullptr);

    QString filenameIn;
    QString filenameOut;
    QString identifier;
    QString filenameProgramPlan;

    QStringList keys;
    QList <int> key_blooms_level;

    QStringList parsed;

    void readFile();
    void saveFile();
    void saveFileOrdered();
    void saveFileOrderedProgram();
    void readArgument(int arg, char *argv[]);


signals:

};

#endif // CFORMSPARSER_H
