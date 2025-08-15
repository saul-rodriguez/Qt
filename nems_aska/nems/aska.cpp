#include "aska.h"

/**********************************************/
/* Configuration words bit mapping            */
/*                                            */
/* conf0:                                     */
/*                                            */
/* bits 31-24: [7:0] ON_time                  */
/* bits 23-18: [5:0] ramp                     */
/* bits 17-12: [5:0] amplitude                */
/* bits 11-0:  [11:0] freq                    */
/*                                            */
/* conf1:                                     */
/*                                            */
/* bits 9-0: [9:0] ramp_factor                */
/* bits 19-10: [9:0] OFF_time                 */
/* bit 20: enable                             */
/* bits 23-21: [2:0] phaseDuration            */
/*                                            */
/**********************************************/

/*
    wire [5:0] amplitude; //0 - 50 mA
    wire [11:0] freq; // 4.88 Hz (4095) - 50 Hz (400)
    wire [2:0] phaseDuration; // 50 us (1) - 350 us (7)
    wire [5:0] ramp; // up to 1s (50 for 50 Hz)
    wire [9:0] ramp_factor; //[1 - 1024] (amplitude/ramp*2^4)
    wire [7:0] ON_time; // up to 4s (in pulses, 200 for 50 Hz)
    wire [9:0] OFF_time; // up to 12s (in pulses 600 for 50 Hz)

    assign amplitude = conf0[17:12];
    assign freq = conf0[11:0];
    assign phaseDuration = conf1[23:21];
    assign ramp = conf0[23:18];
    assign ramp_factor = conf1[9:0];
    assign ON_time = conf0[31:24];
    assign OFF_time = conf1[19:10];
    assign enable = conf1[20];


typedef struct ASKA_bits_struct {
    unsigned freq           :12;
    unsigned amplitude      :6;
    unsigned ramp           :6;
    unsigned ON_time        :8;

    unsigned ramp_factor    :10;
    unsigned OFF_time       :10;
    unsigned enable         :1;
    unsigned phaseDuration  :3;
    unsigned not_used       :8;

    unsigned ele1_bits      :32;

    unsigned ele2_bits      :32;

} ASKA_bits;

 */
const uint8_t ASKA_IC_add[4] = {
    IC_ADDRESS_0,
    IC_ADDRESS_1,
    IC_ADDRESS_2,
    IC_ADDRESS_3
};


aska::aska(QObject *parent)
    : QObject{parent}
{}

void aska::setProgram(uint8_t ic_add, uint32_t freq, uint32_t amplitude, uint32_t ON_time, uint32_t OFF_time, uint32_t ramp_time, uint32_t enable, uint32_t phaseDuration, uint32_t ele1, uint32_t ele2)
{
    // Number of 20 kHz cycles to generate freq
    m_NMES.freq = (uint16_t)(BASE_FREQ/freq);

    m_NMES.amplitude = amplitude;

    // number of ON/OFF pulses
    m_NMES.ON_time = (freq*ON_time)/10;

    m_NMES.OFF_time = (freq*OFF_time)/10;

    // number of pulses during ramp UP/DOWN
    m_NMES.ramp = (freq*ramp_time)/10;

    // ramp_factor
    if (m_NMES.ramp > 0) {
        m_NMES.ramp_factor = ((amplitude*16)/m_NMES.ramp);
    } else {
        m_NMES.ramp_factor = 0;
    }

    m_NMES.enable = enable;
    m_NMES.phaseDuration = phaseDuration;
    m_NMES.ele1 = ele1;
    m_NMES.ele2 = ele2;

    m_ASIC.conf0 = 0;
    m_ASIC.conf1 = 0;
    m_ASIC.ele1 = 0;
    m_ASIC.ele2 = 0;

    m_ASIC.conf0 |= (m_NMES.freq              & 0x00000fff);
    m_ASIC.conf0 |= ((m_NMES.amplitude << 12) & 0x0003f000);
    m_ASIC.conf0 |= ((m_NMES.ramp << 18)      & 0x00fc0000);
    m_ASIC.conf0 |= ((m_NMES.ON_time << 24)   & 0xff000000);

    m_ASIC.conf1 |= (m_NMES.ramp_factor             & 0x000003ff);
    m_ASIC.conf1 |= ((m_NMES.OFF_time << 10)        & 0x000ffc00);
    m_ASIC.conf1 |= ((m_NMES.enable << 20)          & 0x00100000);
    m_ASIC.conf1 |= ((m_NMES.phaseDuration << 21)   & 0x00e00000);

    if (m_NMES.ele1 == 0) {
        m_ASIC.ele1 = 0;
    } else {
        m_ASIC.ele1 = 1 << (m_NMES.ele1 -1);
    }

    if (m_NMES.ele2 == 0) {
        m_ASIC.ele2 = 0;
    } else {
        m_ASIC.ele2 = 1 << (m_NMES.ele2 -1);
    }

    //m_ASIC.ele1 = m_NMES.ele1;
    //m_ASIC.ele2 = m_NMES.ele2;

    setCommand(ic_add);


}

void aska::setCommand(uint32_t ic_add)
{
    m_command.clear();

    // Send identifier for command
    m_command.append('w');

    // IC address
    m_command.append((uint8_t)ic_add);

    // Conf0
    m_command.append((uint8_t)(m_ASIC.conf0 & 0xff));
    m_command.append((uint8_t)((m_ASIC.conf0 >> 8) & 0xff));
    m_command.append((uint8_t)((m_ASIC.conf0 >> 16) & 0xff));
    m_command.append((uint8_t)((m_ASIC.conf0 >> 24) & 0xff));

    // Conf1
    m_command.append((uint8_t)(m_ASIC.conf1 & 0xff));
    m_command.append((uint8_t)((m_ASIC.conf1 >> 8) & 0xff));
    m_command.append((uint8_t)((m_ASIC.conf1 >> 16) & 0xff));
    m_command.append((uint8_t)((m_ASIC.conf1 >> 24) & 0xff));

    // Ele1
    m_command.append((uint8_t)(m_ASIC.ele1 & 0xff));
    m_command.append((uint8_t)((m_ASIC.ele1 >> 8) & 0xff));
    m_command.append((uint8_t)((m_ASIC.ele1 >> 16) & 0xff));
    m_command.append((uint8_t)((m_ASIC.ele1 >> 24) & 0xff));

    // Ele2
    m_command.append((uint8_t)(m_ASIC.ele2 & 0xff));
    m_command.append((uint8_t)((m_ASIC.ele2 >> 8) & 0xff));
    m_command.append((uint8_t)((m_ASIC.ele2 >> 16) & 0xff));
    m_command.append((uint8_t)((m_ASIC.ele2 >> 24) & 0xff));


}

QByteArray aska::getCommand()
{
    return m_command;
}

uint8_t aska::getASKA_ICaddress(uint32_t address)
{
    if (address > 3) {
        return 0;
    } else {
        return ASKA_IC_add[address];
    }
}
