#include <QCoreApplication>

#include "cformsparser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cformsparser parser;

    parser.readArgument(argc, argv);
    parser.readFile();
    parser.saveFile();

    return 0;
    //return a.exec();
}
