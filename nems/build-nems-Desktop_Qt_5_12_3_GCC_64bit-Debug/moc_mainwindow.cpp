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
    QByteArrayData data[48];
    char stringdata0[1082];
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
QT_MOC_LITERAL(13, 141, 4), // "send"
QT_MOC_LITERAL(14, 146, 38), // "on_pushButtonBTdiscoverDevice..."
QT_MOC_LITERAL(15, 185, 30), // "on_pushButtonBTconnect_clicked"
QT_MOC_LITERAL(16, 216, 27), // "on_pushButtonATSend_clicked"
QT_MOC_LITERAL(17, 244, 26), // "on_radioButtonWiFi_toggled"
QT_MOC_LITERAL(18, 271, 7), // "checked"
QT_MOC_LITERAL(19, 279, 24), // "on_radioButtonBT_toggled"
QT_MOC_LITERAL(20, 304, 32), // "on_pushButtonWiFiConnect_clicked"
QT_MOC_LITERAL(21, 337, 35), // "on_pushButtonWiFiDisconnect_c..."
QT_MOC_LITERAL(22, 373, 34), // "on_checkBoxConfigAntialias_to..."
QT_MOC_LITERAL(23, 408, 33), // "on_pushButtonBTdisconnect_cli..."
QT_MOC_LITERAL(24, 442, 11), // "resizeEvent"
QT_MOC_LITERAL(25, 454, 13), // "QResizeEvent*"
QT_MOC_LITERAL(26, 468, 5), // "event"
QT_MOC_LITERAL(27, 474, 23), // "on_action_Run_triggered"
QT_MOC_LITERAL(28, 498, 25), // "on_action_Clean_triggered"
QT_MOC_LITERAL(29, 524, 32), // "on_action_Delete_sweep_triggered"
QT_MOC_LITERAL(30, 557, 24), // "on_action_Save_triggered"
QT_MOC_LITERAL(31, 582, 30), // "on_pushButtonAmplitude_clicked"
QT_MOC_LITERAL(32, 613, 30), // "on_pushButtonFrequency_clicked"
QT_MOC_LITERAL(33, 644, 26), // "on_pushButtonPhase_clicked"
QT_MOC_LITERAL(34, 671, 28), // "on_pushButtonSymetry_clicked"
QT_MOC_LITERAL(35, 700, 27), // "on_pushButtonOnTime_clicked"
QT_MOC_LITERAL(36, 728, 24), // "on_pushButtonOFF_clicked"
QT_MOC_LITERAL(37, 753, 27), // "on_pushButtonRampUp_clicked"
QT_MOC_LITERAL(38, 781, 29), // "on_pushButtonRampDown_clicked"
QT_MOC_LITERAL(39, 811, 33), // "on_pushButtonContractions_cli..."
QT_MOC_LITERAL(40, 845, 29), // "on_pushButtonChannel1_clicked"
QT_MOC_LITERAL(41, 875, 29), // "on_pushButtonChannel2_clicked"
QT_MOC_LITERAL(42, 905, 23), // "on_actionStop_triggered"
QT_MOC_LITERAL(43, 929, 24), // "on_action_Open_triggered"
QT_MOC_LITERAL(44, 954, 35), // "on_action_Display_program_tri..."
QT_MOC_LITERAL(45, 990, 29), // "on_pushButtonChannel3_clicked"
QT_MOC_LITERAL(46, 1020, 29), // "on_pushButtonChannel4_clicked"
QT_MOC_LITERAL(47, 1050, 31) // "on_pushButtonAmplitude2_clicked"

    },
    "MainWindow\0BTgetDevice\0\0name\0BTConnected\0"
    "BTrxData\0data\0WiFiRead\0WiFiDisplayError\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "PlotRx\0PlotTimeout\0send\0"
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
    "on_pushButtonAmplitude2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  209,    2, 0x08 /* Private */,
       4,    1,  212,    2, 0x08 /* Private */,
       5,    1,  215,    2, 0x08 /* Private */,
       7,    0,  218,    2, 0x08 /* Private */,
       8,    1,  219,    2, 0x08 /* Private */,
      11,    1,  222,    2, 0x08 /* Private */,
      12,    0,  225,    2, 0x08 /* Private */,
      13,    1,  226,    2, 0x08 /* Private */,
      14,    0,  229,    2, 0x08 /* Private */,
      15,    0,  230,    2, 0x08 /* Private */,
      16,    0,  231,    2, 0x08 /* Private */,
      17,    1,  232,    2, 0x08 /* Private */,
      19,    1,  235,    2, 0x08 /* Private */,
      20,    0,  238,    2, 0x08 /* Private */,
      21,    0,  239,    2, 0x08 /* Private */,
      22,    1,  240,    2, 0x08 /* Private */,
      23,    0,  243,    2, 0x08 /* Private */,
      24,    1,  244,    2, 0x08 /* Private */,
      27,    0,  247,    2, 0x08 /* Private */,
      28,    0,  248,    2, 0x08 /* Private */,
      29,    0,  249,    2, 0x08 /* Private */,
      30,    0,  250,    2, 0x08 /* Private */,
      31,    0,  251,    2, 0x08 /* Private */,
      32,    0,  252,    2, 0x08 /* Private */,
      33,    0,  253,    2, 0x08 /* Private */,
      34,    0,  254,    2, 0x08 /* Private */,
      35,    0,  255,    2, 0x08 /* Private */,
      36,    0,  256,    2, 0x08 /* Private */,
      37,    0,  257,    2, 0x08 /* Private */,
      38,    0,  258,    2, 0x08 /* Private */,
      39,    0,  259,    2, 0x08 /* Private */,
      40,    0,  260,    2, 0x08 /* Private */,
      41,    0,  261,    2, 0x08 /* Private */,
      42,    0,  262,    2, 0x08 /* Private */,
      43,    0,  263,    2, 0x08 /* Private */,
      44,    0,  264,    2, 0x08 /* Private */,
      45,    0,  265,    2, 0x08 /* Private */,
      46,    0,  266,    2, 0x08 /* Private */,
      47,    0,  267,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,
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
        case 7: _t->send((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->on_pushButtonBTdiscoverDevices_clicked(); break;
        case 9: _t->on_pushButtonBTconnect_clicked(); break;
        case 10: _t->on_pushButtonATSend_clicked(); break;
        case 11: _t->on_radioButtonWiFi_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_radioButtonBT_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_pushButtonWiFiConnect_clicked(); break;
        case 14: _t->on_pushButtonWiFiDisconnect_clicked(); break;
        case 15: _t->on_checkBoxConfigAntialias_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->on_pushButtonBTdisconnect_clicked(); break;
        case 17: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 18: _t->on_action_Run_triggered(); break;
        case 19: _t->on_action_Clean_triggered(); break;
        case 20: _t->on_action_Delete_sweep_triggered(); break;
        case 21: _t->on_action_Save_triggered(); break;
        case 22: _t->on_pushButtonAmplitude_clicked(); break;
        case 23: _t->on_pushButtonFrequency_clicked(); break;
        case 24: _t->on_pushButtonPhase_clicked(); break;
        case 25: _t->on_pushButtonSymetry_clicked(); break;
        case 26: _t->on_pushButtonOnTime_clicked(); break;
        case 27: _t->on_pushButtonOFF_clicked(); break;
        case 28: _t->on_pushButtonRampUp_clicked(); break;
        case 29: _t->on_pushButtonRampDown_clicked(); break;
        case 30: _t->on_pushButtonContractions_clicked(); break;
        case 31: _t->on_pushButtonChannel1_clicked(); break;
        case 32: _t->on_pushButtonChannel2_clicked(); break;
        case 33: _t->on_actionStop_triggered(); break;
        case 34: _t->on_action_Open_triggered(); break;
        case 35: _t->on_action_Display_program_triggered(); break;
        case 36: _t->on_pushButtonChannel3_clicked(); break;
        case 37: _t->on_pushButtonChannel4_clicked(); break;
        case 38: _t->on_pushButtonAmplitude2_clicked(); break;
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
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
