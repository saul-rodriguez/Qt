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
    QByteArrayData data[48];
    char stringdata0[971];
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
QT_MOC_LITERAL(15, 176, 11), // "setUpTables"
QT_MOC_LITERAL(16, 188, 11), // "clearTables"
QT_MOC_LITERAL(17, 200, 12), // "updateTables"
QT_MOC_LITERAL(18, 213, 16), // "updateStatistics"
QT_MOC_LITERAL(19, 230, 38), // "on_pushButtonBTdiscoverDevice..."
QT_MOC_LITERAL(20, 269, 30), // "on_pushButtonBTconnect_clicked"
QT_MOC_LITERAL(21, 300, 27), // "on_pushButtonATSend_clicked"
QT_MOC_LITERAL(22, 328, 26), // "on_radioButtonWiFi_toggled"
QT_MOC_LITERAL(23, 355, 7), // "checked"
QT_MOC_LITERAL(24, 363, 24), // "on_radioButtonBT_toggled"
QT_MOC_LITERAL(25, 388, 32), // "on_pushButtonWiFiConnect_clicked"
QT_MOC_LITERAL(26, 421, 35), // "on_pushButtonWiFiDisconnect_c..."
QT_MOC_LITERAL(27, 457, 34), // "on_checkBoxConfigAntialias_to..."
QT_MOC_LITERAL(28, 492, 33), // "on_pushButtonBTdisconnect_cli..."
QT_MOC_LITERAL(29, 526, 11), // "resizeEvent"
QT_MOC_LITERAL(30, 538, 13), // "QResizeEvent*"
QT_MOC_LITERAL(31, 552, 5), // "event"
QT_MOC_LITERAL(32, 558, 40), // "on_pushButtonGenerateCalibrat..."
QT_MOC_LITERAL(33, 599, 32), // "on_pushButtonOpenCalFile_clicked"
QT_MOC_LITERAL(34, 632, 32), // "on_pushButtonSaveCalFile_clicked"
QT_MOC_LITERAL(35, 665, 23), // "on_action_Run_triggered"
QT_MOC_LITERAL(36, 689, 25), // "on_action_Clean_triggered"
QT_MOC_LITERAL(37, 715, 23), // "on_tableViewMag_clicked"
QT_MOC_LITERAL(38, 739, 11), // "QModelIndex"
QT_MOC_LITERAL(39, 751, 5), // "index"
QT_MOC_LITERAL(40, 757, 23), // "on_tableViewPha_clicked"
QT_MOC_LITERAL(41, 781, 32), // "on_action_Delete_sweep_triggered"
QT_MOC_LITERAL(42, 814, 27), // "on_pushButtonAddTag_clicked"
QT_MOC_LITERAL(43, 842, 40), // "on_comboBoxTagSelect_currentI..."
QT_MOC_LITERAL(44, 883, 4), // "arg1"
QT_MOC_LITERAL(45, 888, 28), // "on_pushButtonSaveTag_clicked"
QT_MOC_LITERAL(46, 917, 28), // "on_pushButtonLoadTag_clicked"
QT_MOC_LITERAL(47, 946, 24) // "on_action_Save_triggered"

    },
    "MainWindow\0BTgetDevice\0\0name\0BTConnected\0"
    "BTrxData\0data\0WiFiRead\0WiFiDisplayError\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "PlotRx\0PlotTimeout\0MeasurementTimeout\0"
    "PlotMeasurement\0setUpTables\0clearTables\0"
    "updateTables\0updateStatistics\0"
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
    "on_pushButtonGenerateCalibration_clicked\0"
    "on_pushButtonOpenCalFile_clicked\0"
    "on_pushButtonSaveCalFile_clicked\0"
    "on_action_Run_triggered\0"
    "on_action_Clean_triggered\0"
    "on_tableViewMag_clicked\0QModelIndex\0"
    "index\0on_tableViewPha_clicked\0"
    "on_action_Delete_sweep_triggered\0"
    "on_pushButtonAddTag_clicked\0"
    "on_comboBoxTagSelect_currentIndexChanged\0"
    "arg1\0on_pushButtonSaveTag_clicked\0"
    "on_pushButtonLoadTag_clicked\0"
    "on_action_Save_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  194,    2, 0x08 /* Private */,
       4,    1,  197,    2, 0x08 /* Private */,
       5,    1,  200,    2, 0x08 /* Private */,
       7,    0,  203,    2, 0x08 /* Private */,
       8,    1,  204,    2, 0x08 /* Private */,
      11,    1,  207,    2, 0x08 /* Private */,
      12,    0,  210,    2, 0x08 /* Private */,
      13,    0,  211,    2, 0x08 /* Private */,
      14,    0,  212,    2, 0x08 /* Private */,
      15,    0,  213,    2, 0x08 /* Private */,
      16,    0,  214,    2, 0x08 /* Private */,
      17,    0,  215,    2, 0x08 /* Private */,
      18,    0,  216,    2, 0x08 /* Private */,
      19,    0,  217,    2, 0x08 /* Private */,
      20,    0,  218,    2, 0x08 /* Private */,
      21,    0,  219,    2, 0x08 /* Private */,
      22,    1,  220,    2, 0x08 /* Private */,
      24,    1,  223,    2, 0x08 /* Private */,
      25,    0,  226,    2, 0x08 /* Private */,
      26,    0,  227,    2, 0x08 /* Private */,
      27,    1,  228,    2, 0x08 /* Private */,
      28,    0,  231,    2, 0x08 /* Private */,
      29,    1,  232,    2, 0x08 /* Private */,
      32,    0,  235,    2, 0x08 /* Private */,
      33,    0,  236,    2, 0x08 /* Private */,
      34,    0,  237,    2, 0x08 /* Private */,
      35,    0,  238,    2, 0x08 /* Private */,
      36,    0,  239,    2, 0x08 /* Private */,
      37,    1,  240,    2, 0x08 /* Private */,
      40,    1,  243,    2, 0x08 /* Private */,
      41,    0,  246,    2, 0x08 /* Private */,
      42,    0,  247,    2, 0x08 /* Private */,
      43,    1,  248,    2, 0x08 /* Private */,
      45,    0,  251,    2, 0x08 /* Private */,
      46,    0,  252,    2, 0x08 /* Private */,
      47,    0,  253,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 38,   39,
    QMetaType::Void, 0x80000000 | 38,   39,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   44,
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
        case 7: _t->MeasurementTimeout(); break;
        case 8: _t->PlotMeasurement(); break;
        case 9: _t->setUpTables(); break;
        case 10: _t->clearTables(); break;
        case 11: _t->updateTables(); break;
        case 12: _t->updateStatistics(); break;
        case 13: _t->on_pushButtonBTdiscoverDevices_clicked(); break;
        case 14: _t->on_pushButtonBTconnect_clicked(); break;
        case 15: _t->on_pushButtonATSend_clicked(); break;
        case 16: _t->on_radioButtonWiFi_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->on_radioButtonBT_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_pushButtonWiFiConnect_clicked(); break;
        case 19: _t->on_pushButtonWiFiDisconnect_clicked(); break;
        case 20: _t->on_checkBoxConfigAntialias_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->on_pushButtonBTdisconnect_clicked(); break;
        case 22: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 23: _t->on_pushButtonGenerateCalibration_clicked(); break;
        case 24: _t->on_pushButtonOpenCalFile_clicked(); break;
        case 25: _t->on_pushButtonSaveCalFile_clicked(); break;
        case 26: _t->on_action_Run_triggered(); break;
        case 27: _t->on_action_Clean_triggered(); break;
        case 28: _t->on_tableViewMag_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 29: _t->on_tableViewPha_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 30: _t->on_action_Delete_sweep_triggered(); break;
        case 31: _t->on_pushButtonAddTag_clicked(); break;
        case 32: _t->on_comboBoxTagSelect_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 33: _t->on_pushButtonSaveTag_clicked(); break;
        case 34: _t->on_pushButtonLoadTag_clicked(); break;
        case 35: _t->on_action_Save_triggered(); break;
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
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
