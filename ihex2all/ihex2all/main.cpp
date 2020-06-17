#include <QCoreApplication>
#include "ihex2all.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ihex2all m_hex;

    m_hex.readArgument(argc,argv);
    m_hex.readFile();
    m_hex.savehex4();
    return 0;

   // return a.exec();
}
