#include <QCoreApplication>

#include "xml2cv.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    XML2CV parser;
    parser.readArgument(argc,argv);
    parser.readFile();
    parser.saveFile();

    return 1;
    return a.exec();
}
