#include "ihex2all.h"
#include <QCoreApplication>
#include <QDebug>
#include <QFile>

ihex2all::ihex2all(QObject *parent) : QObject(parent)
{
    //filenameIn = "/home/saul/projects/tinyfpga/gcc_tests/assembler_test/test.hex";
    //filenameOut = "/home/saul/projects/tinyfpga/gcc_tests/assembler_test/test.hex4";
}

void ihex2all::readFile()
{
    QFile auxfile(filenameIn);
    int ret = auxfile.open(QIODevice::ReadOnly);

    QTextStream in(&auxfile);

    QStringList lines;

    //read all lines from intel hex
    while(!in.atEnd()) {
         lines << in.readLine();
    }
    auxfile.close();

    int num_lines = lines.size();

    QString aux[4];
    int ind_start = 9; //the first 9 characters are not data
    int end_line;
    QByteArray ba;
    QString hex4line;
    HEXdata4.clear();


    for (int i = 0; i < num_lines; i++) {

        end_line = lines[i].count()-2; //the last 2 characters are checksum
        ba = lines[i].toLocal8Bit();
        const char *bas = ba.data();

        for (int j = ind_start; j < end_line; j+=8) {
           aux[0] = aux[1] = aux[2] = aux[3] = "";

           aux[0] += bas[j];
           aux[0] += bas[j+1];
           aux[1] += bas[j+2];
           aux[1] += bas[j+3];

           if (j+4 < end_line) {
           aux[2] += bas[j+4];
           aux[2] += bas[j+5];
           aux[3] += bas[j+6];
           aux[3] += bas[j+7];
           } else {
               aux[2] = aux[3] = "00";
           }

           hex4line = aux[3] + aux[2] + aux[1] + aux[0];

           HEXdata4 << hex4line;
           qDebug()<< hex4line;

        }
    }

}

void ihex2all::readArgument(int arg, char *argv[])
{
    if (arg < 2) {
        qDebug()<<"wrong number of arguments";
    }

    filenameIn = QString::fromLocal8Bit(argv[1]);
    filenameOut = QString::fromLocal8Bit(argv[2]);


}

void ihex2all::savehex4()
{
    QFile outfile(filenameOut);
    outfile.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream stream(&outfile);
  //  stream.setCodec("UTF-8");
    int size = HEXdata4.size();

    for (int i = 0; i < size; i++) {
        stream << HEXdata4[i] << "\n";
    }

    outfile.close();
}
