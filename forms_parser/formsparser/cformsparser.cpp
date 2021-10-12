#include "cformsparser.h"
#include <QCoreApplication>
#include <QDebug>
#include <QFile>

Cformsparser::Cformsparser(QObject *parent) : QObject(parent)
{
    // This initialization is only for testing purposes

    filenameIn = "test.csv";
    filenameOut = "out.csv";

    identifier = "1";

    filenameProgramPlan = "TIEDB_plan.txt";

    //Create keys
    keys.clear();
    key_blooms_level.clear();

    for (int i = 1; i < 11; i++) {
        QString aux;
        aux = QString::number(i) + ":";
        keys << aux;
    }

    for (int j = 1; j <= 6; j++) {
        key_blooms_level << j;
    }


    /*
    for (int j = 1; j <= 6; j++) {
        for (int i = 1; i <= 12; i++) {
            QString aux;
            aux = identifier +"." + QString::number(j) + "." + QString::number(i);
            //qDebug()<<aux;
            keys << aux;
            key_blooms_level << j;
        }
    }*/


    /*
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
    */

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
    QStringList line_split;

    parsed.clear();

    parsed << lines[0];

    for (int i=1; i < num_lines; i++) { //Starts after header line
        //process each line
        line = lines[i];
        line_split = line.split(",\"");


        QString aux;
        int bloom_level;

        int temp_bloom;
        temp_bloom = 0;

        for (int j = 3; j < 9; j++) { //Parse every Blooms column
            bloom_level = j-2;
            for (int k = 0; k < keys_size; k++) {
                if (line_split.size() <= k) continue;

                if (line_split.size() <= j) continue;

                if (line_split[j].contains(keys[k])) {
                    aux += identifier + "." + QString::number(bloom_level) + "." + QString::number((k+1));
                    aux += + ", ";
                    if (temp_bloom < bloom_level) {
                        temp_bloom = bloom_level;
                    }

                }
            }
        }

        /*
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
        */

        //Store complete line + new content
        line += ",\"" + aux + "\"" + ",\"" + QString::number(temp_bloom) + "\"";

        parsed << line;


    }

}

void Cformsparser::saveFile()
{
    QFile outfile(filenameOut);
    outfile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
    QTextStream stream(&outfile);

    int size = parsed.size();

    for (int i = 0; i < size; i++) {
           stream << parsed[i] << "\n";
    }

    outfile.close();

       qDebug()<< "formparser: "<< size<< " lines written to: " <<filenameOut ;


}

void Cformsparser::saveFileOrdered()
{
    //Load program text file
    QFile auxfile(filenameProgramPlan);
    int ret = auxfile.open(QIODevice::ReadOnly);

    QTextStream in(&auxfile);
    QStringList program_lines;

    QString aux_line;
    while(!in.atEnd()) {
             aux_line = in.readLine();

             if (aux_line.compare(""))
                 //program_lines << in.readLine();
                 program_lines << aux_line;
    }
    auxfile.close();

    // reorder the parsed text file
    QStringList aux;

    int parsed_size = parsed.count();
    int program_size = program_lines.count();

    aux << parsed[0];
    for (int j = 0; j < program_size; j++) {
        for (int i = 0; i < parsed_size; i ++) {
            if (parsed[i].contains(program_lines[j])) {
                    aux << parsed[i];
                    break;
            }
        }
    }

    //Save reordered file
    QString auxFilename;
    auxFilename = "ordered_" + filenameOut;

    QFile outfile(auxFilename);
    outfile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
    QTextStream stream(&outfile);

    int size = aux.size();

    for (int i = 0; i < size; i++) {
           stream << aux[i] << "\n";
    }

    outfile.close();

    qDebug()<< "formparser: "<< size<< " lines written to: " <<auxFilename ;

}

void Cformsparser::saveFileOrderedProgram()
{

    //Load program text file
    QFile auxfile(filenameProgramPlan);
    int ret = auxfile.open(QIODevice::ReadOnly);

    QTextStream in(&auxfile);
    QStringList program_lines;

    QString aux_line;
    while(!in.atEnd()) {
             aux_line = in.readLine();

             if (aux_line.compare(""))
                 //program_lines << in.readLine();
                 program_lines << aux_line;
    }
    auxfile.close();

    // reorder the parsed text file
    QStringList aux;

    int parsed_size = parsed.count();
    int program_size = program_lines.count();

    /*
    aux << parsed[0];
    for (int j = 0; j < program_size; j++) {
        for (int i = 0; i < parsed_size; i ++) {
            if (parsed[i].contains(program_lines[j])) {
                    aux << parsed[i];
                    break;
            }
        }
    }
    */
    QString a_line;
    for (int i=0; i < program_size; i++ ) {

        // add all courses in the first column
        a_line =  "\"" + program_lines[i] + "\"";


        //Search for course answers and append
        for (int j = 0; j < parsed_size; j++) {
            if(parsed[j].contains(program_lines[i])) {
                a_line += ",";
                a_line += parsed[j];
                break;
            }
        }

        aux << a_line;
    }

    //Save reordered file
    QString auxFilename;
    auxFilename = "ordered_program_" + identifier + "\_" + filenameOut;

    QFile outfile(auxFilename);
    outfile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
    QTextStream stream(&outfile);

    int size = aux.size();

    for (int i = 0; i < size; i++) {
           stream << aux[i] << "\n";
    }

    outfile.close();

    qDebug()<< "formparser: "<< size<< " lines written to: " <<auxFilename ;

}

void Cformsparser::readArgument(int arg, char *argv[])
{
    qDebug()<<"arg:" << arg;

    if (arg < 5) {
            qDebug()<<"wrong number of arguments";
            qDebug()<<"Usage: formparser input.csv output.csv objective_indentifier(1-99) program_plan.txt";
            exit(0);
    }

    filenameIn = QString::fromLocal8Bit(argv[1]);
    filenameOut = QString::fromLocal8Bit(argv[2]);
    identifier = QString::fromLocal8Bit(argv[3]);
    filenameProgramPlan = QString::fromLocal8Bit(argv[4]);



    //Create keys
    keys.clear();
    key_blooms_level.clear();

    for (int i = 1; i < 11; i++) {
        QString aux;
        aux = QString::number(i) + ":";
        keys << aux;
    }

    for (int j = 1; j <= 6; j++) {
        key_blooms_level << j;
    }


/*

    //Create keys
    keys.clear();
    key_blooms_level.clear();

    for (int j = 1; j <= 6; j++) {
        for (int i = 1; i <= 12; i++) {
            QString aux;
            aux = identifier +"." + QString::number(j) + "." + QString::number(i);
            //qDebug()<<aux;
            keys << aux;
            key_blooms_level << j;
        }
    }
*/

}
