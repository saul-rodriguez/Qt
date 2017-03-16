#include <QCoreApplication>
#include <QDebug>

quint16 crc16(quint8* data_p, quint8 length);

#define N 10

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    quint8 mess[N];

    for (int i = 0; i < N; i++) {
        mess[i] = 0x00;
    }

    mess[0] = 'z';
    mess[1] = 0xaa;
    mess[2] = 0xf0;

    quint16 crc = crc16(mess,3);

    qDebug()<<"crc = " << crc;

    mess[0] ^= 0x01;

    crc = crc16(mess,3);

    qDebug()<<"crc = " << crc;







    return a.exec();
}

quint16 crc16(quint8* data_p, quint8 length){
    quint8 x;
    quint16 crc = 0xFFFF;

    while (length--){
        x = crc >> 8 ^ *data_p++;
        x ^= x>>4;
        crc = (crc << 8) ^ ((unsigned short)(x << 12)) ^ ((unsigned short)(x <<5)) ^ ((unsigned short)x);
    }
    return crc;
}


