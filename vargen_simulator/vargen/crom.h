#ifndef CROM_H
#define CROM_H

#include <QObject>
#include "Vvargen.h"

class CRom
{
    //Q_OBJECT
public:
    QList<uint32_t> program;

private:
    uint32_t ram_size_words;
    Vvargen *pico;

public:
    CRom();



    void setRamSize(uint32_t size);
    void readFile(QString filename);
    void update();
    void setPico(Vvargen *var);

};

#endif // CROM_H
