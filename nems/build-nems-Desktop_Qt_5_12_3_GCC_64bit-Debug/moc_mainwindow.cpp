/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nems/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[55];
    char stringdata0[1267];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "BTgetDevice"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "name"
QT_MOC_LITERAL(4, 29, 11), // "BTConnected"
QT_MOC_LITERAL(5, 41, 8), // "BTrxData"
QT_MOC_LITERAL(6, 50, 4), // "data"
QT_MOC_LITERAL(7, 55, 8), // "WiFiRead"
QT_MOC_LITERAL(8, 64, 16), // "WiFiDisplayError"
QT_MOC_LITERAL(9, 81, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(10, 110, 11), // "socketError"
QT_MOC_LITERAL(11, 122, 6), // "PlotRx"
QT_MOC_LITERAL(12, 129, 11), // "PlotTimeout"
QT_MOC_LITERAL(13, 141, 16), // "UpdateSensorData"
QT_MOC_LITERAL(14, 158, 4), // "send"
QT_MOC_LITERAL(15, 163, 12), // "parseProgram"
QT_MOC_LITERAL(16, 176, 38), // "on_pushButtonBTdiscoverDevice..."
QT_MOC_LITERAL(17, 215, 30), // "on_pushButtonBTconnect_clicked"
QT_MOC_LITERAL(18, 246, 27), // "on_pushButtonATSend_clicked"
QT_MOC_LITERAL(19, 274, 26), // "on_radioButtonWiFi_toggled"
QT_MOC_LITERAL(20, 301, 7), // "checked"
QT_MOC_LITERAL(21, 309, 24), // "on_radioButtonBT_toggled"
QT_MOC_LITERAL(22, 334, 32), // "on_pushButtonWiFiConnect_clicked"
QT_MOC_LITERAL(23, 367, 35), // "on_pushButtonWiFiDisconnect_c..."
QT_MOC_LITERAL(24, 403, 34), // "on_checkBoxConfigAntialias_to..."
QT_MOC_LITERAL(25, 438, 33), // "on_pushButtonBTdisconnect_cli..."
QT_MOC_LITERAL(26, 472, 11), // "resizeEvent"
QT_MOC_LITERAL(27, 484, 13), // "QResizeEvent*"
QT_MOC_LITERAL(28, 498, 5), // "event"
QT_MOC_LITERAL(29, 504, 23), // "on_action_Run_triggered"
QT_MOC_LITERAL(30, 528, 25), // "on_action_Clean_triggered"
QT_MOC_LITERAL(31, 554, 32), // "on_action_Delete_sweep_triggered"
QT_MOC_LITERAL(32, 587, 24), // "on_action_Save_triggered"
QT_MOC_LITERAL(33, 612, 30), // "on_pushButtonAmplitude_clicked"
QT_MOC_LITERAL(34, 643, 30), // "on_pushButtonFrequency_clicked"
QT_MOC_LITERAL(35, 674, 26), // "on_pushButtonPhase_clicked"
QT_MOC_LITERAL(36, 701, 28), // "on_pushButtonSymetry_clicked"
QT_MOC_LITERAL(37, 730, 27), // "on_pushButtonOnTime_clicked"
QT_MOC_LITERAL(38, 758, 24), // "on_pushButtonOFF_clicked"
QT_MOC_LITERAL(39, 783, 27), // "on_pushButtonRampUp_clicked"
QT_MOC_LITERAL(40, 811, 29), // "on_pushButtonRampDown_clicked"
QT_MOC_LITERAL(41, 841, 33), // "on_pushButtonContractions_cli..."
QT_MOC_LITERAL(42, 875, 29), // "on_pushButtonChannel1_clicked"
QT_MOC_LITERAL(43, 905, 29), // "on_pushButtonChannel2_clicked"
QT_MOC_LITERAL(44, 935, 23), // "on_actionStop_triggered"
QT_MOC_LITERAL(45, 959, 24), // "on_action_Open_triggered"
QT_MOC_LITERAL(46, 984, 35), // "on_action_Display_program_tri..."
QT_MOC_LITERAL(47, 1020, 29), // "on_pushButtonChannel3_clicked"
QT_MOC_LITERAL(48, 1050, 29), // "on_pushButtonChannel4_clicked"
QT_MOC_LITERAL(49, 1080, 31), // "on_pushButtonAmplitude2_clicked"
QT_MOC_LITERAL(50, 1112, 26), // "on_actionSensors_triggered"
QT_MOC_LITERAL(51, 1139, 39), // "on_verticalSliderEnergyMax_va..."
QT_MOC_LITERAL(52, 1179, 5), // "value"
QT_MOC_LITERAL(53, 1185, 45), // "on_verticalSliderEnergyThresh..."
QT_MOC_LITERAL(54, 1231, 35) // "on_pushButtonResetMaxEnergy_c..."

    },
    "MainWindow\0BTgetDevice\0\0name\0BTConnected\0"
    "BTrxData\0data\0WiFiRead\0WiFiDisplayError\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "PlotRx\0PlotTimeout\0UpdateSensorData\0"
    "send\0parseProgram\0"
    "on_pushButtonBTdiscoverDevices_clicked\0"
    "on_pushButtonBTconnect_clicked\0"
    "on_pushButtonATSend_clicked\0"
    "on_radioButtonWiFi_toggled\0checked\0"
    "on_radioButtonBT_toggled\0"
    "on_pushButtonWiFiConnect_clicked\0"
    "on_pushButtonWiFiDisconnect_clicked\0"
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
    "on_pushButtonResetMaxEnergy_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      45,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  239,    2, 0x08 /* Private */,
       4,    1,  242,    2, 0x08 /* Private */,
       5,    1,  245,    2, 0x08 /* Private */,
       7,    0,  248,    2, 0x08 /* Private */,
       8,    1,  249,    2, 0x08 /* Private */,
      11,    1,  252,    2, 0x08 /* Private */,
      12,    0,  255,    2, 0x08 /* Private */,
      13,    0,  256,    2, 0x08 /* Private */,
      14,    1,  257,    2, 0x08 /* Private */,
      15,    1,  260,    2, 0x08 /* Private */,
      16,    0,  263,    2, 0x08 /* Private */,
      17,    0,  264,    2, 0x08 /* Private */,
      18,    0,  265,    2, 0x08 /* Private */,
      19,    1,  266,    2, 0x08 /* Private */,
      21,    1,  269,    2, 0x08 /* Private */,
      22,    0,  272,    2, 0x08 /* Private */,
      23,    0,  273,    2, 0x08 /* Private */,
      24,    1,  274,    2, 0x08 /* Private */,
      25,    0,  277,    2, 0x08 /* Private */,
      26,    1,  278,    2, 0x08 /* Private */,
      29,    0,  281,    2, 0x08 /* Private */,
      30,    0,  282,    2, 0x08 /* Private */,
      31,    0,  283,    2, 0x08 /* Private */,
      32,    0,  284,    2, 0x08 /* Private */,
      33,    0,  285,    2, 0x08 /* Private */,
      34,    0,  286,    2, 0x08 /* Private */,
      35,    0,  287,    2, 0x08 /* Private */,
      36,    0,  288,    2, 0x08 /* Private */,
      37,    0,  289,    2, 0x08 /* Private */,
      38,    0,  290,    2, 0x08 /* Private */,
      39,    0,  291,    2, 0x08 /* Private */,
      40,    0,  292,    2, 0x08 /* Private */,
      41,    0,  293,    2, 0x08 /* Private */,
      42,    0,  294,    2, 0x08 /* Private */,
      43,    0,  295,    2, 0x08 /* Private */,
      44,    0,  296,    2, 0x08 /* Private */,
      45,    0,  297,    2, 0x08 /* Private */,
      46,    0,  298,    2, 0x08 /* Private */,
      47,    0,  299,    2, 0x08 /* Private */,
      48,    0,  300,    2, 0x08 /* Private */,
      49,    0,  301,    2, 0x08 /* Private */,
      50,    1,  302,    2, 0x08 /* Private */,
      51,    1,  305,    2, 0x08 /* Private */,
      53,    1,  308,    2, 0x08 /* Private */,
      54,    0,  311,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27,   28,
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
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void, QMetaType::Int,   52,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->BTgetDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->BTConnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->BTrxData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 3: _t->WiFiRead(); break;
        case 4: _t->WiFiDisplayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: _t->PlotRx((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 6: _t->PlotTimeout(); break;
        case 7: _t->UpdateSensorData(); break;
        case 8: _t->send((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: _t->parseProgram((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 10: _t->on_pushButtonBTdiscoverDevices_clicked(); break;
        case 11: _t->on_pushButtonBTconnect_clicked(); break;
        case 12: _t->on_pushButtonATSend_clicked(); break;
        case 13: _t->on_radioButtonWiFi_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_radioButtonBT_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_pushButtonWiFiConnect_clicked(); break;
        case 16: _t->on_pushButtonWiFiDisconnect_clicked(); break;
        case 17: _t->on_checkBoxConfigAntialias_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_pushButtonBTdisconnect_clicked(); break;
        case 19: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 20: _t->on_action_Run_triggered(); break;
        case 21: _t->on_action_Clean_triggered(); break;
        case 22: _t->on_action_Delete_sweep_triggered(); break;
        case 23: _t->on_action_Save_triggered(); break;
        case 24: _t->on_pushButtonAmplitude_clicked(); break;
        case 25: _t->on_pushButtonFrequency_clicked(); break;
        case 26: _t->on_pushButtonPhase_clicked(); break;
        case 27: _t->on_pushButtonSymetry_clicked(); break;
        case 28: _t->on_pushButtonOnTime_clicked(); break;
        case 29: _t->on_pushButtonOFF_clicked(); break;
        case 30: _t->on_pushButtonRampUp_clicked(); break;
        case 31: _t->on_pushButtonRampDown_clicked(); break;
        case 32: _t->on_pushButtonContractions_clicked(); break;
        case 33: _t->on_pushButtonChannel1_clicked(); break;
        case 34: _t->on_pushButtonChannel2_clicked(); break;
        case 35: _t->on_actionStop_triggered(); break;
        case 36: _t->on_action_Open_triggered(); break;
        case 37: _t->on_action_Display_program_triggered(); break;
        case 38: _t->on_pushButtonChannel3_clicked(); break;
        case 39: _t->on_pushButtonChannel4_clicked(); break;
        case 40: _t->on_pushButtonAmplitude2_clicked(); break;
        case 41: _t->on_actionSensors_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->on_verticalSliderEnergyMax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->on_verticalSliderEnergyThreshold_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->on_pushButtonResetMaxEnergy_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
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
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 45)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 45;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
