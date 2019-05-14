/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nanosense2/mainwindow.h"
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
    QByteArrayData data[26];
    char stringdata0[498];
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
QT_MOC_LITERAL(13, 141, 18), // "MeasurementTimeout"
QT_MOC_LITERAL(14, 160, 15), // "PlotMeasurement"
QT_MOC_LITERAL(15, 176, 38), // "on_pushButtonBTdiscoverDevice..."
QT_MOC_LITERAL(16, 215, 30), // "on_pushButtonBTconnect_clicked"
QT_MOC_LITERAL(17, 246, 27), // "on_pushButtonATSend_clicked"
QT_MOC_LITERAL(18, 274, 26), // "on_radioButtonWiFi_toggled"
QT_MOC_LITERAL(19, 301, 7), // "checked"
QT_MOC_LITERAL(20, 309, 24), // "on_radioButtonBT_toggled"
QT_MOC_LITERAL(21, 334, 32), // "on_pushButtonWiFiConnect_clicked"
QT_MOC_LITERAL(22, 367, 35), // "on_pushButtonWiFiDisconnect_c..."
QT_MOC_LITERAL(23, 403, 34), // "on_checkBoxConfigAntialias_to..."
QT_MOC_LITERAL(24, 438, 33), // "on_pushButtonBTdisconnect_cli..."
QT_MOC_LITERAL(25, 472, 25) // "on_pushButtonMeas_clicked"

    },
    "MainWindow\0BTgetDevice\0\0name\0BTConnected\0"
    "BTrxData\0data\0WiFiRead\0WiFiDisplayError\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "PlotRx\0PlotTimeout\0MeasurementTimeout\0"
    "PlotMeasurement\0on_pushButtonBTdiscoverDevices_clicked\0"
    "on_pushButtonBTconnect_clicked\0"
    "on_pushButtonATSend_clicked\0"
    "on_radioButtonWiFi_toggled\0checked\0"
    "on_radioButtonBT_toggled\0"
    "on_pushButtonWiFiConnect_clicked\0"
    "on_pushButtonWiFiDisconnect_clicked\0"
    "on_checkBoxConfigAntialias_toggled\0"
    "on_pushButtonBTdisconnect_clicked\0"
    "on_pushButtonMeas_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x08 /* Private */,
       4,    1,  112,    2, 0x08 /* Private */,
       5,    1,  115,    2, 0x08 /* Private */,
       7,    0,  118,    2, 0x08 /* Private */,
       8,    1,  119,    2, 0x08 /* Private */,
      11,    1,  122,    2, 0x08 /* Private */,
      12,    0,  125,    2, 0x08 /* Private */,
      13,    0,  126,    2, 0x08 /* Private */,
      14,    0,  127,    2, 0x08 /* Private */,
      15,    0,  128,    2, 0x08 /* Private */,
      16,    0,  129,    2, 0x08 /* Private */,
      17,    0,  130,    2, 0x08 /* Private */,
      18,    1,  131,    2, 0x08 /* Private */,
      20,    1,  134,    2, 0x08 /* Private */,
      21,    0,  137,    2, 0x08 /* Private */,
      22,    0,  138,    2, 0x08 /* Private */,
      23,    1,  139,    2, 0x08 /* Private */,
      24,    0,  142,    2, 0x08 /* Private */,
      25,    0,  143,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   19,
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
        case 7: _t->MeasurementTimeout(); break;
        case 8: _t->PlotMeasurement(); break;
        case 9: _t->on_pushButtonBTdiscoverDevices_clicked(); break;
        case 10: _t->on_pushButtonBTconnect_clicked(); break;
        case 11: _t->on_pushButtonATSend_clicked(); break;
        case 12: _t->on_radioButtonWiFi_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_radioButtonBT_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_pushButtonWiFiConnect_clicked(); break;
        case 15: _t->on_pushButtonWiFiDisconnect_clicked(); break;
        case 16: _t->on_checkBoxConfigAntialias_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->on_pushButtonBTdisconnect_clicked(); break;
        case 18: _t->on_pushButtonMeas_clicked(); break;
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
