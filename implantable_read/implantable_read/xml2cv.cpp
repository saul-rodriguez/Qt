#include "xml2cv.h"
#include <QDebug>
#include <QFile>
#include <QRegularExpression>

XML2CV::XML2CV(QObject *parent)
    : QObject{parent}
{

    //m_filenameIn = "ebba.xml";
    //m_filenameOut = "ebba.cvs";

    m_meas_size = 0;

}

void XML2CV::readFile()
{

    // Read XML file
    QFile auxfile(m_filenameIn);
    int ret = auxfile.open(QIODevice::ReadOnly);

    QTextStream in(&auxfile);
    QStringList lines;

    while(!in.atEnd()) {
        lines << in.readLine();
    }
    auxfile.close();

    // Parse XML File

    int num_lines = lines.size();


    QString line;
    QStringList line_split;

    int meas_index = 0;
    int amp_index = 0;
    int pha_index = 0;

    QRegularExpression separator("<|>");

    for (int i=0; i < num_lines; i++) {
            line = lines[i];

            //Search for time stamp
            if(line.contains("<TS>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].time = line_split[2].toInt();
            }

            //Save amplitudes
            if(line.contains("<a0>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].amplitude[0] = line_split[2].toDouble();
            }
            if(line.contains("<a1>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].amplitude[1] = line_split[2].toDouble();
            }
            if(line.contains("<a2>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].amplitude[2] = line_split[2].toDouble();
            }
            if(line.contains("<a3>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].amplitude[3] = line_split[2].toDouble();
            }
            if(line.contains("<a4>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].amplitude[4] = line_split[2].toDouble();
            }
            if(line.contains("<a5>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].amplitude[5] = line_split[2].toDouble();
            }
            if(line.contains("<a6>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].amplitude[6] = line_split[2].toDouble();
            }
            if(line.contains("<a7>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].amplitude[7] = line_split[2].toDouble();
            }
            if(line.contains("<a8>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].amplitude[8] = line_split[2].toDouble();
            }
            if(line.contains("<a9>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].amplitude[9] = line_split[2].toDouble();
            }
            if(line.contains("<a10>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].amplitude[10] = line_split[2].toDouble();
            }

            //Save phases
            if(line.contains("<p0>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].phase[0] = line_split[2].toDouble();
            }
            if(line.contains("<p1>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].phase[1] = line_split[2].toDouble();
            }
            if(line.contains("<p2>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].phase[2] = line_split[2].toDouble();
            }
            if(line.contains("<p3>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].phase[3] = line_split[2].toDouble();
            }
            if(line.contains("<p4>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].phase[4] = line_split[2].toDouble();
            }
            if(line.contains("<p5>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].phase[5] = line_split[2].toDouble();
            }
            if(line.contains("<p6>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].phase[6] = line_split[2].toDouble();
            }
            if(line.contains("<p7>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].phase[7] = line_split[2].toDouble();
            }
            if(line.contains("<p8>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].phase[8] = line_split[2].toDouble();
            }
            if(line.contains("<p9>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].phase[9] = line_split[2].toDouble();
            }
            if(line.contains("<p10>")) {
                line_split = line.split(separator);
                m_measurements[meas_index].phase[10] = line_split[2].toDouble();
                meas_index++;
            }
    }

    m_meas_size = meas_index;
}

void XML2CV::saveFile()
{
    QFile outfile(m_filenameOut);
    outfile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
        QTextStream stream(&outfile);

        for (int i = 0; i < m_meas_size; i++) {
               //stream << parsed[i] << "\n";
            stream << QString::number(m_measurements[i].time) << " ";

            for (int j = 0; j < 11; j++) {
                stream << QString::number(m_measurements[i].amplitude[j]) << " ";
            }

            for (int j = 0; j < 11; j++) {
                stream << QString::number(m_measurements[i].phase[j]) << " ";
            }

            stream << "\n";

        }

        outfile.close();

        //   qDebug()<< "formparser: "<< size<< " lines written to: " <<filenameOut ;

}

void XML2CV::readArgument(int arg, char *argv[])
{
    qDebug()<<"arg:" << arg;

    if (arg < 2) {
                qDebug()<<"wrong number of arguments";
                qDebug()<<"Usage: implantable_read input.xml output.csv";
                exit(0);
        }

        m_filenameIn = QString::fromLocal8Bit(argv[1]);
        m_filenameOut = QString::fromLocal8Bit(argv[2]);


}
