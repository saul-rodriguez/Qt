#ifndef XML2CV_H
#define XML2CV_H

#include <QObject>
#include <QList>

typedef struct meas_struc {
    quint32 time;
    double amplitude[11];
    double phase[11];
} meas;

class XML2CV : public QObject
{
    Q_OBJECT
public:
    explicit XML2CV(QObject *parent = nullptr);

    QString m_filenameIn;
    QString m_filenameOut;

    quint32 m_meas_size;

    //QList<meas> m_measurements;
    meas m_measurements[100];

    void readFile();
    void saveFile();
    void readArgument(int arg, char *argv[]);

signals:

};

#endif // XML2CV_H
