#include "append.h"
#include <QCoreApplication>
#include <QDebug>
#include <QDir>

append::append()
{

}

void append::process()
{
    QDir directory(measDirectory);
    xmlfileNames = directory.entryList(QStringList()<< "*.xml", QDir::Files);

    int N = xmlfileNames.size();

    if (N == 0) {
        qDebug()<<"no xml files found in directory";
        return;
    }

    //Filter the list and save only the filenames of interest
    for (int i=0; i < N; i++) {
        QString auxfilename = xmlfileNames[i];
        //qDebug()<< auxfilename;
        QStringList auxfilenamesplit = auxfilename.split("_");
        if (!auxfilenamesplit[0].compare(subject)) {
            xmlfiltered << auxfilename;
        }
    }

    //Create the output file and append the data
    int M = xmlfiltered.size();

    QFile file(outputPath);
    file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    QTextStream stream(&file);
    stream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << "\n";
    stream << "<" << subject << ">" << "\n";

    //Create the header

    //Append data from all files
    for (int i = 0; i < M; i++) {
        QString selFile = measDirectory + "/" + xmlfiltered[i];
        QFile auxfile(selFile);
        auxfile.open(QIODevice::ReadOnly);

        QTextStream in(&auxfile);
        QStringList xmltext;

        while(!in.atEnd()) {
            xmltext << in.readLine();
        }
        auxfile.close();

        qDebug()<<"Appending: "<<selFile;

        for (int j = 0; j < xmltext.size(); j++) {
            if ( j==0 || j==1 || j==(xmltext.size()-1) ) continue;

            stream << xmltext[j] << "\n";

        }

    }

    //Close the file
    stream << "</" << subject << ">" << "\n";
    file.close();
}

void append::setpaths(int argc, char *argv[])
{

    if (argc != 4) {
        qDebug()<<"Usage: ";
        qDebug()<<"nanoappend [subject] [directory] [output filename] ";
        exit(0);

    }

    subject = QString::fromLocal8Bit(argv[1]);
    measDirectory = QString::fromLocal8Bit(argv[2]);
    outputPath = QString::fromLocal8Bit(argv[3]);
}
