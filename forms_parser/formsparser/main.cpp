#include <QCoreApplication>

#include "cformsparser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cformsparser parser;

    parser.readArgument(argc, argv);
    parser.readFile();
    parser.saveFile();
    parser.saveFileOrdered();
    parser.saveFileOrderedProgram();

    return 1;
    //return a.exec();
}
