/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../nems/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[68];
    char stringdata0[1543];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "updateSearchText"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "text"
QT_MOC_LITERAL(4, 34, 11), // "BTgetDevice"
QT_MOC_LITERAL(5, 46, 4), // "name"
QT_MOC_LITERAL(6, 51, 11), // "BTConnected"
QT_MOC_LITERAL(7, 63, 8), // "BTrxData"
QT_MOC_LITERAL(8, 72, 4), // "data"
QT_MOC_LITERAL(9, 77, 11), // "deviceFound"
QT_MOC_LITERAL(10, 89, 6), // "device"
QT_MOC_LITERAL(11, 96, 6), // "rxData"
QT_MOC_LITERAL(12, 103, 15), // "updateBLEstatus"
QT_MOC_LITERAL(13, 119, 8), // "QString&"
QT_MOC_LITERAL(14, 128, 6), // "status"
QT_MOC_LITERAL(15, 135, 6), // "PlotRx"
QT_MOC_LITERAL(16, 142, 11), // "PlotTimeout"
QT_MOC_LITERAL(17, 154, 14), // "SilenceTimeout"
QT_MOC_LITERAL(18, 169, 16), // "UpdateSensorData"
QT_MOC_LITERAL(19, 186, 10), // "SearchDone"
QT_MOC_LITERAL(20, 197, 4), // "send"
QT_MOC_LITERAL(21, 202, 12), // "parseProgram"
QT_MOC_LITERAL(22, 215, 38), // "on_pushButtonBTdiscoverDevice..."
QT_MOC_LITERAL(23, 254, 30), // "on_pushButtonBTconnect_clicked"
QT_MOC_LITERAL(24, 285, 27), // "on_pushButtonATSend_clicked"
QT_MOC_LITERAL(25, 313, 26), // "on_radioButtonWiFi_toggled"
QT_MOC_LITERAL(26, 340, 7), // "checked"
QT_MOC_LITERAL(27, 348, 24), // "on_radioButtonBT_toggled"
QT_MOC_LITERAL(28, 373, 34), // "on_checkBoxConfigAntialias_to..."
QT_MOC_LITERAL(29, 408, 33), // "on_pushButtonBTdisconnect_cli..."
QT_MOC_LITERAL(30, 442, 11), // "resizeEvent"
QT_MOC_LITERAL(31, 454, 13), // "QResizeEvent*"
QT_MOC_LITERAL(32, 468, 5), // "event"
QT_MOC_LITERAL(33, 474, 23), // "on_action_Run_triggered"
QT_MOC_LITERAL(34, 498, 25), // "on_action_Clean_triggered"
QT_MOC_LITERAL(35, 524, 32), // "on_action_Delete_sweep_triggered"
QT_MOC_LITERAL(36, 557, 24), // "on_action_Save_triggered"
QT_MOC_LITERAL(37, 582, 30), // "on_pushButtonAmplitude_clicked"
QT_MOC_LITERAL(38, 613, 30), // "on_pushButtonFrequency_clicked"
QT_MOC_LITERAL(39, 644, 26), // "on_pushButtonPhase_clicked"
QT_MOC_LITERAL(40, 671, 28), // "on_pushButtonSymetry_clicked"
QT_MOC_LITERAL(41, 700, 27), // "on_pushButtonOnTime_clicked"
QT_MOC_LITERAL(42, 728, 24), // "on_pushButtonOFF_clicked"
QT_MOC_LITERAL(43, 753, 27), // "on_pushButtonRampUp_clicked"
QT_MOC_LITERAL(44, 781, 29), // "on_pushButtonRampDown_clicked"
QT_MOC_LITERAL(45, 811, 33), // "on_pushButtonContractions_cli..."
QT_MOC_LITERAL(46, 845, 29), // "on_pushButtonChannel1_clicked"
QT_MOC_LITERAL(47, 875, 29), // "on_pushButtonChannel2_clicked"
QT_MOC_LITERAL(48, 905, 23), // "on_actionStop_triggered"
QT_MOC_LITERAL(49, 929, 24), // "on_action_Open_triggered"
QT_MOC_LITERAL(50, 954, 35), // "on_action_Display_program_tri..."
QT_MOC_LITERAL(51, 990, 29), // "on_pushButtonChannel3_clicked"
QT_MOC_LITERAL(52, 1020, 29), // "on_pushButtonChannel4_clicked"
QT_MOC_LITERAL(53, 1050, 31), // "on_pushButtonAmplitude2_clicked"
QT_MOC_LITERAL(54, 1082, 26), // "on_actionSensors_triggered"
QT_MOC_LITERAL(55, 1109, 39), // "on_verticalSliderEnergyMax_va..."
QT_MOC_LITERAL(56, 1149, 5), // "value"
QT_MOC_LITERAL(57, 1155, 45), // "on_verticalSliderEnergyThresh..."
QT_MOC_LITERAL(58, 1201, 35), // "on_pushButtonResetMaxEnergy_c..."
QT_MOC_LITERAL(59, 1237, 25), // "on_actionSearch_triggered"
QT_MOC_LITERAL(60, 1263, 40), // "on_pushButtonUpdateCh1MotorPo..."
QT_MOC_LITERAL(61, 1304, 34), // "on_pushButtonStartDualStim_cl..."
QT_MOC_LITERAL(62, 1339, 40), // "on_pushButtonUpdateCh2MotorPo..."
QT_MOC_LITERAL(63, 1380, 30), // "on_actionStop_Search_triggered"
QT_MOC_LITERAL(64, 1411, 31), // "on_actionShow_pin_map_triggered"
QT_MOC_LITERAL(65, 1443, 32), // "on_pushButtonBLEdiscover_clicked"
QT_MOC_LITERAL(66, 1476, 31), // "on_pushButtonBLEconnect_clicked"
QT_MOC_LITERAL(67, 1508, 34) // "on_pushButtonBLEdisconnect_cl..."

    },
    "MainWindow\0updateSearchText\0\0text\0"
    "BTgetDevice\0name\0BTConnected\0BTrxData\0"
    "data\0deviceFound\0device\0rxData\0"
    "updateBLEstatus\0QString&\0status\0PlotRx\0"
    "PlotTimeout\0SilenceTimeout\0UpdateSensorData\0"
    "SearchDone\0send\0parseProgram\0"
    "on_pushButtonBTdiscoverDevices_clicked\0"
    "on_pushButtonBTconnect_clicked\0"
    "on_pushButtonATSend_clicked\0"
    "on_radioButtonWiFi_toggled\0checked\0"
    "on_radioButtonBT_toggled\0"
    "on_checkBoxConfigAntialias_toggled\0"
    "on_pushButtonBTdisconnect_clicked\0"
    "resizeEvent\0QResizeEvent*\0event\0"
    "on_action_Run_triggered\0"
    "on_action_Clean_triggered\0"
    "on_action_Delete_sweep_triggered\0"
    "on_action_Save_triggered\0"
    "on_pushButtonAmplitude_clicked\0"
    "on_pushButtonFrequency_clicked\0"
    "on_pushButtonPhase_clicked\0"
    "on_pushButtonSymetry_clicked\0"
    "on_pushButtonOnTime_clicked\0"
    "on_pushButtonOFF_clicked\0"
    "on_pushButtonRampUp_clicked\0"
    "on_pushButtonRampDown_clicked\0"
    "on_pushButtonContractions_clicked\0"
    "on_pushButtonChannel1_clicked\0"
    "on_pushButtonChannel2_clicked\0"
    "on_actionStop_triggered\0"
    "on_action_Open_triggered\0"
    "on_action_Display_program_triggered\0"
    "on_pushButtonChannel3_clicked\0"
    "on_pushButtonChannel4_clicked\0"
    "on_pushButtonAmplitude2_clicked\0"
    "on_actionSensors_triggered\0"
    "on_verticalSliderEnergyMax_valueChanged\0"
    "value\0on_verticalSliderEnergyThreshold_valueChanged\0"
    "on_pushButtonResetMaxEnergy_clicked\0"
    "on_actionSearch_triggered\0"
    "on_pushButtonUpdateCh1MotorPoint_clicked\0"
    "on_pushButtonStartDualStim_clicked\0"
    "on_pushButtonUpdateCh2MotorPoint_clicked\0"
    "on_actionStop_Search_triggered\0"
    "on_actionShow_pin_map_triggered\0"
    "on_pushButtonBLEdiscover_clicked\0"
    "on_pushButtonBLEconnect_clicked\0"
    "on_pushButtonBLEdisconnect_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      56,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  294,    2, 0x0a /* Public */,
       4,    1,  297,    2, 0x08 /* Private */,
       6,    1,  300,    2, 0x08 /* Private */,
       7,    1,  303,    2, 0x08 /* Private */,
       9,    1,  306,    2, 0x08 /* Private */,
      11,    1,  309,    2, 0x08 /* Private */,
      12,    1,  312,    2, 0x08 /* Private */,
      15,    1,  315,    2, 0x08 /* Private */,
      16,    0,  318,    2, 0x08 /* Private */,
      17,    0,  319,    2, 0x08 /* Private */,
      18,    0,  320,    2, 0x08 /* Private */,
      19,    0,  321,    2, 0x08 /* Private */,
      20,    1,  322,    2, 0x08 /* Private */,
      21,    1,  325,    2, 0x08 /* Private */,
      22,    0,  328,    2, 0x08 /* Private */,
      23,    0,  329,    2, 0x08 /* Private */,
      24,    0,  330,    2, 0x08 /* Private */,
      25,    1,  331,    2, 0x08 /* Private */,
      27,    1,  334,    2, 0x08 /* Private */,
      28,    1,  337,    2, 0x08 /* Private */,
      29,    0,  340,    2, 0x08 /* Private */,
      30,    1,  341,    2, 0x08 /* Private */,
      33,    0,  344,    2, 0x08 /* Private */,
      34,    0,  345,    2, 0x08 /* Private */,
      35,    0,  346,    2, 0x08 /* Private */,
      36,    0,  347,    2, 0x08 /* Private */,
      37,    0,  348,    2, 0x08 /* Private */,
      38,    0,  349,    2, 0x08 /* Private */,
      39,    0,  350,    2, 0x08 /* Private */,
      40,    0,  351,    2, 0x08 /* Private */,
      41,    0,  352,    2, 0x08 /* Private */,
      42,    0,  353,    2, 0x08 /* Private */,
      43,    0,  354,    2, 0x08 /* Private */,
      44,    0,  355,    2, 0x08 /* Private */,
      45,    0,  356,    2, 0x08 /* Private */,
      46,    0,  357,    2, 0x08 /* Private */,
      47,    0,  358,    2, 0x08 /* Private */,
      48,    0,  359,    2, 0x08 /* Private */,
      49,    0,  360,    2, 0x08 /* Private */,
      50,    0,  361,    2, 0x08 /* Private */,
      51,    0,  362,    2, 0x08 /* Private */,
      52,    0,  363,    2, 0x08 /* Private */,
      53,    0,  364,    2, 0x08 /* Private */,
      54,    1,  365,    2, 0x08 /* Private */,
      55,    1,  368,    2, 0x08 /* Private */,
      57,    1,  371,    2, 0x08 /* Private */,
      58,    0,  374,    2, 0x08 /* Private */,
      59,    0,  375,    2, 0x08 /* Private */,
      60,    0,  376,    2, 0x08 /* Private */,
      61,    0,  377,    2, 0x08 /* Private */,
      62,    0,  378,    2, 0x08 /* Private */,
      63,    0,  379,    2, 0x08 /* Private */,
      64,    0,  380,    2, 0x08 /* Private */,
      65,    0,  381,    2, 0x08 /* Private */,
      66,    0,  382,    2, 0x08 /* Private */,
      67,    0,  383,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 31,   32,
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
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Int,   56,
    QMetaType::Void, QMetaType::Int,   56,
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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateSearchText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->BTgetDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->BTConnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->BTrxData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->deviceFound((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->rxData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 6: _t->updateBLEstatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->PlotRx((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 8: _t->PlotTimeout(); break;
        case 9: _t->SilenceTimeout(); break;
        case 10: _t->UpdateSensorData(); break;
        case 11: _t->SearchDone(); break;
        case 12: _t->send((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 13: _t->parseProgram((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 14: _t->on_pushButtonBTdiscoverDevices_clicked(); break;
        case 15: _t->on_pushButtonBTconnect_clicked(); break;
        case 16: _t->on_pushButtonATSend_clicked(); break;
        case 17: _t->on_radioButtonWiFi_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_radioButtonBT_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->on_checkBoxConfigAntialias_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->on_pushButtonBTdisconnect_clicked(); break;
        case 21: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 22: _t->on_action_Run_triggered(); break;
        case 23: _t->on_action_Clean_triggered(); break;
        case 24: _t->on_action_Delete_sweep_triggered(); break;
        case 25: _t->on_action_Save_triggered(); break;
        case 26: _t->on_pushButtonAmplitude_clicked(); break;
        case 27: _t->on_pushButtonFrequency_clicked(); break;
        case 28: _t->on_pushButtonPhase_clicked(); break;
        case 29: _t->on_pushButtonSymetry_clicked(); break;
        case 30: _t->on_pushButtonOnTime_clicked(); break;
        case 31: _t->on_pushButtonOFF_clicked(); break;
        case 32: _t->on_pushButtonRampUp_clicked(); break;
        case 33: _t->on_pushButtonRampDown_clicked(); break;
        case 34: _t->on_pushButtonContractions_clicked(); break;
        case 35: _t->on_pushButtonChannel1_clicked(); break;
        case 36: _t->on_pushButtonChannel2_clicked(); break;
        case 37: _t->on_actionStop_triggered(); break;
        case 38: _t->on_action_Open_triggered(); break;
        case 39: _t->on_action_Display_program_triggered(); break;
        case 40: _t->on_pushButtonChannel3_clicked(); break;
        case 41: _t->on_pushButtonChannel4_clicked(); break;
        case 42: _t->on_pushButtonAmplitude2_clicked(); break;
        case 43: _t->on_actionSensors_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: _t->on_verticalSliderEnergyMax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->on_verticalSliderEnergyThreshold_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 46: _t->on_pushButtonResetMaxEnergy_clicked(); break;
        case 47: _t->on_actionSearch_triggered(); break;
        case 48: _t->on_pushButtonUpdateCh1MotorPoint_clicked(); break;
        case 49: _t->on_pushButtonStartDualStim_clicked(); break;
        case 50: _t->on_pushButtonUpdateCh2MotorPoint_clicked(); break;
        case 51: _t->on_actionStop_Search_triggered(); break;
        case 52: _t->on_actionShow_pin_map_triggered(); break;
        case 53: _t->on_pushButtonBLEdiscover_clicked(); break;
        case 54: _t->on_pushButtonBLEconnect_clicked(); break;
        case 55: _t->on_pushButtonBLEdisconnect_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 56)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 56;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 56)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 56;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
