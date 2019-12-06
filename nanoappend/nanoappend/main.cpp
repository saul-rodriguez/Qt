#include <QCoreApplication>
#include <QDebug>
#include "append.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"Argument list:";
    for(int i = 0; i<argc; i++) {
        qDebug()<<"arg "<<i <<":" << argv[i];
    }

    append m_append;
    m_append.setpaths(argc,argv);
    m_append.process();

    return a.exec();
}
