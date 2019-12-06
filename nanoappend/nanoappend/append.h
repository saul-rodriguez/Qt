#ifndef APPEND_H
#define APPEND_H

#include <QObject>

class append
{
private:
    QString measDirectory;
    QString outputPath;
    QString subject;

    QStringList xmlfileNames;
    QStringList xmlfiltered;

public:
    append();
    void process();
    void setpaths(int argc, char *argv[]);


};

#endif // APPEND_H
