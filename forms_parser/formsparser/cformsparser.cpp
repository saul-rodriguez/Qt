#include "cformsparser.h"
#include <QCoreApplication>
#include <QDebug>
#include <QFile>

Cformsparser::Cformsparser(QObject *parent) : QObject(parent)
{
    filenameIn = "TIEDB_TEST.csv";
    filenameOut = "out.csv";

    keys.clear();
    key_blooms_level.clear();

    for (int j = 1; j <= 6; j++) {
        for (int i = 1; i <= 12; i++) {
            QString aux;
            aux = "11." + QString::number(j) + "." + QString::number(i);
            keys << aux;
            key_blooms_level << j;
        }
    }
}

void Cformsparser::readFile()
{
    QFile auxfile(filenameIn);
    int ret = auxfile.open(QIODevice::ReadOnly);

    QTextStream in(&auxfile);
    QStringList lines;

    while(!in.atEnd()) {
             lines << in.readLine();
    }
    auxfile.close();

    int num_lines = lines.size();

    int keys_size = keys.size();

    QString line;

    parsed.clear();

    for (int i=0; i < num_lines; i++) {
        //process each line
        line = lines[i];

        QString aux;
        int temp_bloom;
        temp_bloom = 0;

        for (int j = 0; j < keys_size; j++) {
            if (line.contains(keys[j])) {
                aux += keys[j] + ", ";
                if (key_blooms_level[j] > temp_bloom) {
                    temp_bloom = key_blooms_level[j];
                }
            }
        }

        //Store complete line + new content
        line += ",\"" + aux + "\"" + ",\"" + QString::number(temp_bloom) + "\"";

        parsed << line;


    }

}

void Cformsparser::saveFile()
{
    QFile outfile(filenameOut);
    outfile.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream stream(&outfile);

    int size = parsed.size();

    for (int i = 0; i < size; i++) {
           stream << parsed[i] << "\n";
    }

    outfile.close();

       qDebug()<< "formparser: "<< size<< " lines written to: " <<filenameOut ;



}

void Cformsparser::readArgument(int arg, char *argv[])
{
    if (arg < 2) {
            qDebug()<<"wrong number of arguments";
    }

    filenameIn = QString::fromLocal8Bit(argv[1]);
    filenameOut = QString::fromLocal8Bit(argv[2]);

}
