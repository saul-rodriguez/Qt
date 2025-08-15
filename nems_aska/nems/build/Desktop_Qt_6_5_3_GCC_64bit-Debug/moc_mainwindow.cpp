/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "updateSearchText",
    "",
    "text",
    "BTgetDevice",
    "name",
    "BTConnected",
    "BTrxData",
    "data",
    "deviceFound",
    "device",
    "rxData",
    "updateBLEstatus",
    "QString&",
    "status",
    "PlotRx",
    "PlotTimeout",
    "SilenceTimeout",
    "UpdateSensorData",
    "SearchDone",
    "getASKAValues",
    "send",
    "parseProgram",
    "on_pushButtonBTdiscoverDevices_clicked",
    "on_pushButtonBTconnect_clicked",
    "on_pushButtonATSend_clicked",
    "on_radioButtonWiFi_toggled",
    "checked",
    "on_radioButtonBT_toggled",
    "on_checkBoxConfigAntialias_toggled",
    "on_pushButtonBTdisconnect_clicked",
    "resizeEvent",
    "QResizeEvent*",
    "event",
    "on_action_Run_triggered",
    "on_action_Clean_triggered",
    "on_action_Delete_sweep_triggered",
    "on_action_Save_triggered",
    "on_pushButtonAmplitude_clicked",
    "on_pushButtonFrequency_clicked",
    "on_pushButtonPhase_clicked",
    "on_pushButtonSymetry_clicked",
    "on_pushButtonOnTime_clicked",
    "on_pushButtonOFF_clicked",
    "on_pushButtonRampUp_clicked",
    "on_pushButtonRampDown_clicked",
    "on_pushButtonContractions_clicked",
    "on_pushButtonChannel1_clicked",
    "on_pushButtonChannel2_clicked",
    "on_actionStop_triggered",
    "on_action_Open_triggered",
    "on_action_Display_program_triggered",
    "on_pushButtonChannel3_clicked",
    "on_pushButtonChannel4_clicked",
    "on_pushButtonAmplitude2_clicked",
    "on_actionSensors_triggered",
    "on_verticalSliderEnergyMax_valueChanged",
    "value",
    "on_verticalSliderEnergyThreshold_valueChanged",
    "on_pushButtonResetMaxEnergy_clicked",
    "on_actionSearch_triggered",
    "on_pushButtonUpdateCh1MotorPoint_clicked",
    "on_pushButtonStartDualStim_clicked",
    "on_pushButtonUpdateCh2MotorPoint_clicked",
    "on_actionStop_Search_triggered",
    "on_actionShow_pin_map_triggered",
    "on_pushButtonBLEdiscover_clicked",
    "on_pushButtonBLEconnect_clicked",
    "on_pushButtonBLEdisconnect_clicked",
    "on_pushButtonAskaProgram_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[140];
    char stringdata0[11];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[12];
    char stringdata5[5];
    char stringdata6[12];
    char stringdata7[9];
    char stringdata8[5];
    char stringdata9[12];
    char stringdata10[7];
    char stringdata11[7];
    char stringdata12[16];
    char stringdata13[9];
    char stringdata14[7];
    char stringdata15[7];
    char stringdata16[12];
    char stringdata17[15];
    char stringdata18[17];
    char stringdata19[11];
    char stringdata20[14];
    char stringdata21[5];
    char stringdata22[13];
    char stringdata23[39];
    char stringdata24[31];
    char stringdata25[28];
    char stringdata26[27];
    char stringdata27[8];
    char stringdata28[25];
    char stringdata29[35];
    char stringdata30[34];
    char stringdata31[12];
    char stringdata32[14];
    char stringdata33[6];
    char stringdata34[24];
    char stringdata35[26];
    char stringdata36[33];
    char stringdata37[25];
    char stringdata38[31];
    char stringdata39[31];
    char stringdata40[27];
    char stringdata41[29];
    char stringdata42[28];
    char stringdata43[25];
    char stringdata44[28];
    char stringdata45[30];
    char stringdata46[34];
    char stringdata47[30];
    char stringdata48[30];
    char stringdata49[24];
    char stringdata50[25];
    char stringdata51[36];
    char stringdata52[30];
    char stringdata53[30];
    char stringdata54[32];
    char stringdata55[27];
    char stringdata56[40];
    char stringdata57[6];
    char stringdata58[46];
    char stringdata59[36];
    char stringdata60[26];
    char stringdata61[41];
    char stringdata62[35];
    char stringdata63[41];
    char stringdata64[31];
    char stringdata65[32];
    char stringdata66[33];
    char stringdata67[32];
    char stringdata68[35];
    char stringdata69[33];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 16),  // "updateSearchText"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 4),  // "text"
        QT_MOC_LITERAL(34, 11),  // "BTgetDevice"
        QT_MOC_LITERAL(46, 4),  // "name"
        QT_MOC_LITERAL(51, 11),  // "BTConnected"
        QT_MOC_LITERAL(63, 8),  // "BTrxData"
        QT_MOC_LITERAL(72, 4),  // "data"
        QT_MOC_LITERAL(77, 11),  // "deviceFound"
        QT_MOC_LITERAL(89, 6),  // "device"
        QT_MOC_LITERAL(96, 6),  // "rxData"
        QT_MOC_LITERAL(103, 15),  // "updateBLEstatus"
        QT_MOC_LITERAL(119, 8),  // "QString&"
        QT_MOC_LITERAL(128, 6),  // "status"
        QT_MOC_LITERAL(135, 6),  // "PlotRx"
        QT_MOC_LITERAL(142, 11),  // "PlotTimeout"
        QT_MOC_LITERAL(154, 14),  // "SilenceTimeout"
        QT_MOC_LITERAL(169, 16),  // "UpdateSensorData"
        QT_MOC_LITERAL(186, 10),  // "SearchDone"
        QT_MOC_LITERAL(197, 13),  // "getASKAValues"
        QT_MOC_LITERAL(211, 4),  // "send"
        QT_MOC_LITERAL(216, 12),  // "parseProgram"
        QT_MOC_LITERAL(229, 38),  // "on_pushButtonBTdiscoverDevice..."
        QT_MOC_LITERAL(268, 30),  // "on_pushButtonBTconnect_clicked"
        QT_MOC_LITERAL(299, 27),  // "on_pushButtonATSend_clicked"
        QT_MOC_LITERAL(327, 26),  // "on_radioButtonWiFi_toggled"
        QT_MOC_LITERAL(354, 7),  // "checked"
        QT_MOC_LITERAL(362, 24),  // "on_radioButtonBT_toggled"
        QT_MOC_LITERAL(387, 34),  // "on_checkBoxConfigAntialias_to..."
        QT_MOC_LITERAL(422, 33),  // "on_pushButtonBTdisconnect_cli..."
        QT_MOC_LITERAL(456, 11),  // "resizeEvent"
        QT_MOC_LITERAL(468, 13),  // "QResizeEvent*"
        QT_MOC_LITERAL(482, 5),  // "event"
        QT_MOC_LITERAL(488, 23),  // "on_action_Run_triggered"
        QT_MOC_LITERAL(512, 25),  // "on_action_Clean_triggered"
        QT_MOC_LITERAL(538, 32),  // "on_action_Delete_sweep_triggered"
        QT_MOC_LITERAL(571, 24),  // "on_action_Save_triggered"
        QT_MOC_LITERAL(596, 30),  // "on_pushButtonAmplitude_clicked"
        QT_MOC_LITERAL(627, 30),  // "on_pushButtonFrequency_clicked"
        QT_MOC_LITERAL(658, 26),  // "on_pushButtonPhase_clicked"
        QT_MOC_LITERAL(685, 28),  // "on_pushButtonSymetry_clicked"
        QT_MOC_LITERAL(714, 27),  // "on_pushButtonOnTime_clicked"
        QT_MOC_LITERAL(742, 24),  // "on_pushButtonOFF_clicked"
        QT_MOC_LITERAL(767, 27),  // "on_pushButtonRampUp_clicked"
        QT_MOC_LITERAL(795, 29),  // "on_pushButtonRampDown_clicked"
        QT_MOC_LITERAL(825, 33),  // "on_pushButtonContractions_cli..."
        QT_MOC_LITERAL(859, 29),  // "on_pushButtonChannel1_clicked"
        QT_MOC_LITERAL(889, 29),  // "on_pushButtonChannel2_clicked"
        QT_MOC_LITERAL(919, 23),  // "on_actionStop_triggered"
        QT_MOC_LITERAL(943, 24),  // "on_action_Open_triggered"
        QT_MOC_LITERAL(968, 35),  // "on_action_Display_program_tri..."
        QT_MOC_LITERAL(1004, 29),  // "on_pushButtonChannel3_clicked"
        QT_MOC_LITERAL(1034, 29),  // "on_pushButtonChannel4_clicked"
        QT_MOC_LITERAL(1064, 31),  // "on_pushButtonAmplitude2_clicked"
        QT_MOC_LITERAL(1096, 26),  // "on_actionSensors_triggered"
        QT_MOC_LITERAL(1123, 39),  // "on_verticalSliderEnergyMax_va..."
        QT_MOC_LITERAL(1163, 5),  // "value"
        QT_MOC_LITERAL(1169, 45),  // "on_verticalSliderEnergyThresh..."
        QT_MOC_LITERAL(1215, 35),  // "on_pushButtonResetMaxEnergy_c..."
        QT_MOC_LITERAL(1251, 25),  // "on_actionSearch_triggered"
        QT_MOC_LITERAL(1277, 40),  // "on_pushButtonUpdateCh1MotorPo..."
        QT_MOC_LITERAL(1318, 34),  // "on_pushButtonStartDualStim_cl..."
        QT_MOC_LITERAL(1353, 40),  // "on_pushButtonUpdateCh2MotorPo..."
        QT_MOC_LITERAL(1394, 30),  // "on_actionStop_Search_triggered"
        QT_MOC_LITERAL(1425, 31),  // "on_actionShow_pin_map_triggered"
        QT_MOC_LITERAL(1457, 32),  // "on_pushButtonBLEdiscover_clicked"
        QT_MOC_LITERAL(1490, 31),  // "on_pushButtonBLEconnect_clicked"
        QT_MOC_LITERAL(1522, 34),  // "on_pushButtonBLEdisconnect_cl..."
        QT_MOC_LITERAL(1557, 32)   // "on_pushButtonAskaProgram_clicked"
    },
    "MainWindow",
    "updateSearchText",
    "",
    "text",
    "BTgetDevice",
    "name",
    "BTConnected",
    "BTrxData",
    "data",
    "deviceFound",
    "device",
    "rxData",
    "updateBLEstatus",
    "QString&",
    "status",
    "PlotRx",
    "PlotTimeout",
    "SilenceTimeout",
    "UpdateSensorData",
    "SearchDone",
    "getASKAValues",
    "send",
    "parseProgram",
    "on_pushButtonBTdiscoverDevices_clicked",
    "on_pushButtonBTconnect_clicked",
    "on_pushButtonATSend_clicked",
    "on_radioButtonWiFi_toggled",
    "checked",
    "on_radioButtonBT_toggled",
    "on_checkBoxConfigAntialias_toggled",
    "on_pushButtonBTdisconnect_clicked",
    "resizeEvent",
    "QResizeEvent*",
    "event",
    "on_action_Run_triggered",
    "on_action_Clean_triggered",
    "on_action_Delete_sweep_triggered",
    "on_action_Save_triggered",
    "on_pushButtonAmplitude_clicked",
    "on_pushButtonFrequency_clicked",
    "on_pushButtonPhase_clicked",
    "on_pushButtonSymetry_clicked",
    "on_pushButtonOnTime_clicked",
    "on_pushButtonOFF_clicked",
    "on_pushButtonRampUp_clicked",
    "on_pushButtonRampDown_clicked",
    "on_pushButtonContractions_clicked",
    "on_pushButtonChannel1_clicked",
    "on_pushButtonChannel2_clicked",
    "on_actionStop_triggered",
    "on_action_Open_triggered",
    "on_action_Display_program_triggered",
    "on_pushButtonChannel3_clicked",
    "on_pushButtonChannel4_clicked",
    "on_pushButtonAmplitude2_clicked",
    "on_actionSensors_triggered",
    "on_verticalSliderEnergyMax_valueChanged",
    "value",
    "on_verticalSliderEnergyThreshold_valueChanged",
    "on_pushButtonResetMaxEnergy_clicked",
    "on_actionSearch_triggered",
    "on_pushButtonUpdateCh1MotorPoint_clicked",
    "on_pushButtonStartDualStim_clicked",
    "on_pushButtonUpdateCh2MotorPoint_clicked",
    "on_actionStop_Search_triggered",
    "on_actionShow_pin_map_triggered",
    "on_pushButtonBLEdiscover_clicked",
    "on_pushButtonBLEconnect_clicked",
    "on_pushButtonBLEdisconnect_clicked",
    "on_pushButtonAskaProgram_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      58,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  362,    2, 0x0a,    1 /* Public */,
       4,    1,  365,    2, 0x08,    3 /* Private */,
       6,    1,  368,    2, 0x08,    5 /* Private */,
       7,    1,  371,    2, 0x08,    7 /* Private */,
       9,    1,  374,    2, 0x08,    9 /* Private */,
      11,    1,  377,    2, 0x08,   11 /* Private */,
      12,    1,  380,    2, 0x08,   13 /* Private */,
      15,    1,  383,    2, 0x08,   15 /* Private */,
      16,    0,  386,    2, 0x08,   17 /* Private */,
      17,    0,  387,    2, 0x08,   18 /* Private */,
      18,    0,  388,    2, 0x08,   19 /* Private */,
      19,    0,  389,    2, 0x08,   20 /* Private */,
      20,    0,  390,    2, 0x08,   21 /* Private */,
      21,    1,  391,    2, 0x08,   22 /* Private */,
      22,    1,  394,    2, 0x08,   24 /* Private */,
      23,    0,  397,    2, 0x08,   26 /* Private */,
      24,    0,  398,    2, 0x08,   27 /* Private */,
      25,    0,  399,    2, 0x08,   28 /* Private */,
      26,    1,  400,    2, 0x08,   29 /* Private */,
      28,    1,  403,    2, 0x08,   31 /* Private */,
      29,    1,  406,    2, 0x08,   33 /* Private */,
      30,    0,  409,    2, 0x08,   35 /* Private */,
      31,    1,  410,    2, 0x08,   36 /* Private */,
      34,    0,  413,    2, 0x08,   38 /* Private */,
      35,    0,  414,    2, 0x08,   39 /* Private */,
      36,    0,  415,    2, 0x08,   40 /* Private */,
      37,    0,  416,    2, 0x08,   41 /* Private */,
      38,    0,  417,    2, 0x08,   42 /* Private */,
      39,    0,  418,    2, 0x08,   43 /* Private */,
      40,    0,  419,    2, 0x08,   44 /* Private */,
      41,    0,  420,    2, 0x08,   45 /* Private */,
      42,    0,  421,    2, 0x08,   46 /* Private */,
      43,    0,  422,    2, 0x08,   47 /* Private */,
      44,    0,  423,    2, 0x08,   48 /* Private */,
      45,    0,  424,    2, 0x08,   49 /* Private */,
      46,    0,  425,    2, 0x08,   50 /* Private */,
      47,    0,  426,    2, 0x08,   51 /* Private */,
      48,    0,  427,    2, 0x08,   52 /* Private */,
      49,    0,  428,    2, 0x08,   53 /* Private */,
      50,    0,  429,    2, 0x08,   54 /* Private */,
      51,    0,  430,    2, 0x08,   55 /* Private */,
      52,    0,  431,    2, 0x08,   56 /* Private */,
      53,    0,  432,    2, 0x08,   57 /* Private */,
      54,    0,  433,    2, 0x08,   58 /* Private */,
      55,    1,  434,    2, 0x08,   59 /* Private */,
      56,    1,  437,    2, 0x08,   61 /* Private */,
      58,    1,  440,    2, 0x08,   63 /* Private */,
      59,    0,  443,    2, 0x08,   65 /* Private */,
      60,    0,  444,    2, 0x08,   66 /* Private */,
      61,    0,  445,    2, 0x08,   67 /* Private */,
      62,    0,  446,    2, 0x08,   68 /* Private */,
      63,    0,  447,    2, 0x08,   69 /* Private */,
      64,    0,  448,    2, 0x08,   70 /* Private */,
      65,    0,  449,    2, 0x08,   71 /* Private */,
      66,    0,  450,    2, 0x08,   72 /* Private */,
      67,    0,  451,    2, 0x08,   73 /* Private */,
      68,    0,  452,    2, 0x08,   74 /* Private */,
      69,    0,  453,    2, 0x08,   75 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::Int,   57,
    QMetaType::Void, QMetaType::Int,   57,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'updateSearchText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'BTgetDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'BTConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'BTrxData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'deviceFound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'rxData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'updateBLEstatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString &, std::false_type>,
        // method 'PlotRx'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'PlotTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SilenceTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'UpdateSensorData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SearchDone'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getASKAValues'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'send'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'parseProgram'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'on_pushButtonBTdiscoverDevices_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonBTconnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonATSend_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_radioButtonWiFi_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_radioButtonBT_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_checkBoxConfigAntialias_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_pushButtonBTdisconnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resizeEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>,
        // method 'on_action_Run_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_Clean_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_Delete_sweep_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_Save_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonAmplitude_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonFrequency_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonPhase_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSymetry_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonOnTime_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonOFF_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonRampUp_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonRampDown_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonContractions_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonChannel1_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonChannel2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionStop_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_Open_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_Display_program_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonChannel3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonChannel4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonAmplitude2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSensors_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_verticalSliderEnergyMax_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_verticalSliderEnergyThreshold_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButtonResetMaxEnergy_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionSearch_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonUpdateCh1MotorPoint_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonStartDualStim_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonUpdateCh2MotorPoint_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionStop_Search_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionShow_pin_map_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonBLEdiscover_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonBLEconnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonBLEdisconnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonAskaProgram_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateSearchText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->BTgetDevice((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->BTConnected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->BTrxData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 4: _t->deviceFound((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->rxData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 6: _t->updateBLEstatus((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1]))); break;
        case 7: _t->PlotRx((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 8: _t->PlotTimeout(); break;
        case 9: _t->SilenceTimeout(); break;
        case 10: _t->UpdateSensorData(); break;
        case 11: _t->SearchDone(); break;
        case 12: { int _r = _t->getASKAValues();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->send((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 14: _t->parseProgram((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 15: _t->on_pushButtonBTdiscoverDevices_clicked(); break;
        case 16: _t->on_pushButtonBTconnect_clicked(); break;
        case 17: _t->on_pushButtonATSend_clicked(); break;
        case 18: _t->on_radioButtonWiFi_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 19: _t->on_radioButtonBT_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->on_checkBoxConfigAntialias_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 21: _t->on_pushButtonBTdisconnect_clicked(); break;
        case 22: _t->resizeEvent((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        case 23: _t->on_action_Run_triggered(); break;
        case 24: _t->on_action_Clean_triggered(); break;
        case 25: _t->on_action_Delete_sweep_triggered(); break;
        case 26: _t->on_action_Save_triggered(); break;
        case 27: _t->on_pushButtonAmplitude_clicked(); break;
        case 28: _t->on_pushButtonFrequency_clicked(); break;
        case 29: _t->on_pushButtonPhase_clicked(); break;
        case 30: _t->on_pushButtonSymetry_clicked(); break;
        case 31: _t->on_pushButtonOnTime_clicked(); break;
        case 32: _t->on_pushButtonOFF_clicked(); break;
        case 33: _t->on_pushButtonRampUp_clicked(); break;
        case 34: _t->on_pushButtonRampDown_clicked(); break;
        case 35: _t->on_pushButtonContractions_clicked(); break;
        case 36: _t->on_pushButtonChannel1_clicked(); break;
        case 37: _t->on_pushButtonChannel2_clicked(); break;
        case 38: _t->on_actionStop_triggered(); break;
        case 39: _t->on_action_Open_triggered(); break;
        case 40: _t->on_action_Display_program_triggered(); break;
        case 41: _t->on_pushButtonChannel3_clicked(); break;
        case 42: _t->on_pushButtonChannel4_clicked(); break;
        case 43: _t->on_pushButtonAmplitude2_clicked(); break;
        case 44: _t->on_actionSensors_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 45: _t->on_verticalSliderEnergyMax_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 46: _t->on_verticalSliderEnergyThreshold_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 47: _t->on_pushButtonResetMaxEnergy_clicked(); break;
        case 48: _t->on_actionSearch_triggered(); break;
        case 49: _t->on_pushButtonUpdateCh1MotorPoint_clicked(); break;
        case 50: _t->on_pushButtonStartDualStim_clicked(); break;
        case 51: _t->on_pushButtonUpdateCh2MotorPoint_clicked(); break;
        case 52: _t->on_actionStop_Search_triggered(); break;
        case 53: _t->on_actionShow_pin_map_triggered(); break;
        case 54: _t->on_pushButtonBLEdiscover_clicked(); break;
        case 55: _t->on_pushButtonBLEconnect_clicked(); break;
        case 56: _t->on_pushButtonBLEdisconnect_clicked(); break;
        case 57: _t->on_pushButtonAskaProgram_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 58)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 58;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 58)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 58;
    }
    return _id;
}
QT_WARNING_POP
