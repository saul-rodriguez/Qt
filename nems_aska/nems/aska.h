#ifndef ASKA_H
#define ASKA_H

#include <QObject>

#define ASKA_CONF0 0x00
#define ASKA_CONF1 0x01
#define ASKA_ELE1  0x02
#define ASKA_ELE2  0x03

#define BASE_FREQ 20000

typedef enum {
    IC_ADDRESS_0 = 0x00,
    IC_ADDRESS_1 = 0x40,
    IC_ADDRESS_2 = 0x80,
    IC_ADDRESS_3 = 0xc0
} ic_address_t;

typedef struct ASKA_CONF_struct {
    uint32_t conf0;
    uint32_t conf1;
    uint32_t ele1;
    uint32_t ele2;
} ASKA_CONF;

typedef struct ASKA_NMES_struct {
    uint32_t freq; //12 bits
    uint32_t amplitude; // 6 bits
    uint32_t ramp; // 6 bits
    uint32_t ON_time; // 8 bits

    uint32_t ramp_factor; //10 bits
    uint32_t OFF_time; //10 bits
    uint32_t enable; //1 bit
    uint32_t phaseDuration; //3bits

    uint32_t ele1; //32 bits
    uint32_t ele2; //32 bits

} ASKA_NMES;


class aska : public QObject
{
    Q_OBJECT

public:
    explicit aska(QObject *parent = nullptr);

    void setProgram(
    uint8_t ic_add, // 0x00,0x40,0x80,0xc0 (0-3)
    uint32_t freq, // [Hz] 5 - 50 Hz
    uint32_t amplitude, // [mA] 0 - 50 mA
    uint32_t ON_time, // [ds] 0 - 40 ds
    uint32_t OFF_time, //[ds] 0 - 120 ds
    uint32_t ramp_time, // ramptime in [ds]
    uint32_t enable,  // 1 or 0
    uint32_t phaseDuration, // 50 us (1) - 350 us (7)
    uint32_t ele1,
    uint32_t ele2);

    void setCommand(uint32_t ic_add);
    QByteArray getCommand();
    uint8_t getASKA_ICaddress(uint32_t address);

signals:

private:
    ASKA_CONF m_ASIC;
    ASKA_NMES m_NMES;
    QByteArray m_command;
};

#endif // ASKA_H
