/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nanosense2/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[51];
    char stringdata0[1060];
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
QT_MOC_LITERAL(14, 160, 16), // "parseRxSweepData"
QT_MOC_LITERAL(15, 177, 15), // "PlotMeasurement"
QT_MOC_LITERAL(16, 193, 11), // "setUpTables"
QT_MOC_LITERAL(17, 205, 11), // "clearTables"
QT_MOC_LITERAL(18, 217, 12), // "updateTables"
QT_MOC_LITERAL(19, 230, 16), // "updateStatistics"
QT_MOC_LITERAL(20, 247, 38), // "on_pushButtonBTdiscoverDevice..."
QT_MOC_LITERAL(21, 286, 30), // "on_pushButtonBTconnect_clicked"
QT_MOC_LITERAL(22, 317, 27), // "on_pushButtonATSend_clicked"
QT_MOC_LITERAL(23, 345, 26), // "on_radioButtonWiFi_toggled"
QT_MOC_LITERAL(24, 372, 7), // "checked"
QT_MOC_LITERAL(25, 380, 24), // "on_radioButtonBT_toggled"
QT_MOC_LITERAL(26, 405, 32), // "on_pushButtonWiFiConnect_clicked"
QT_MOC_LITERAL(27, 438, 35), // "on_pushButtonWiFiDisconnect_c..."
QT_MOC_LITERAL(28, 474, 34), // "on_checkBoxConfigAntialias_to..."
QT_MOC_LITERAL(29, 509, 33), // "on_pushButtonBTdisconnect_cli..."
QT_MOC_LITERAL(30, 543, 11), // "resizeEvent"
QT_MOC_LITERAL(31, 555, 13), // "QResizeEvent*"
QT_MOC_LITERAL(32, 569, 5), // "event"
QT_MOC_LITERAL(33, 575, 40), // "on_pushButtonGenerateCalibrat..."
QT_MOC_LITERAL(34, 616, 32), // "on_pushButtonOpenCalFile_clicked"
QT_MOC_LITERAL(35, 649, 32), // "on_pushButtonSaveCalFile_clicked"
QT_MOC_LITERAL(36, 682, 23), // "on_action_Run_triggered"
QT_MOC_LITERAL(37, 706, 25), // "on_action_Clean_triggered"
QT_MOC_LITERAL(38, 732, 23), // "on_tableViewMag_clicked"
QT_MOC_LITERAL(39, 756, 11), // "QModelIndex"
QT_MOC_LITERAL(40, 768, 5), // "index"
QT_MOC_LITERAL(41, 774, 23), // "on_tableViewPha_clicked"
QT_MOC_LITERAL(42, 798, 32), // "on_action_Delete_sweep_triggered"
QT_MOC_LITERAL(43, 831, 27), // "on_pushButtonAddTag_clicked"
QT_MOC_LITERAL(44, 859, 40), // "on_comboBoxTagSelect_currentI..."
QT_MOC_LITERAL(45, 900, 4), // "arg1"
QT_MOC_LITERAL(46, 905, 28), // "on_pushButtonSaveTag_clicked"
QT_MOC_LITERAL(47, 934, 28), // "on_pushButtonLoadTag_clicked"
QT_MOC_LITERAL(48, 963, 24), // "on_action_Save_triggered"
QT_MOC_LITERAL(49, 988, 40), // "on_comboBoxPA_config_currentI..."
QT_MOC_LITERAL(50, 1029, 30) // "on_pushButtonPA_Config_clicked"

    },
    "MainWindow\0BTgetDevice\0\0name\0BTConnected\0"
    "BTrxData\0data\0WiFiRead\0WiFiDisplayError\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "PlotRx\0PlotTimeout\0MeasurementTimeout\0"
    "parseRxSweepData\0PlotMeasurement\0"
    "setUpTables\0clearTables\0updateTables\0"
    "updateStatistics\0"
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
    "on_action_Save_triggered\0"
    "on_comboBoxPA_config_currentIndexChanged\0"
    "on_pushButtonPA_Config_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
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
      13,    0,  226,    2, 0x08 /* Private */,
      14,    0,  227,    2, 0x08 /* Private */,
      15,    0,  228,    2, 0x08 /* Private */,
      16,    0,  229,    2, 0x08 /* Private */,
      17,    0,  230,    2, 0x08 /* Private */,
      18,    0,  231,    2, 0x08 /* Private */,
      19,    0,  232,    2, 0x08 /* Private */,
      20,    0,  233,    2, 0x08 /* Private */,
      21,    0,  234,    2, 0x08 /* Private */,
      22,    0,  235,    2, 0x08 /* Private */,
      23,    1,  236,    2, 0x08 /* Private */,
      25,    1,  239,    2, 0x08 /* Private */,
      26,    0,  242,    2, 0x08 /* Private */,
      27,    0,  243,    2, 0x08 /* Private */,
      28,    1,  244,    2, 0x08 /* Private */,
      29,    0,  247,    2, 0x08 /* Private */,
      30,    1,  248,    2, 0x08 /* Private */,
      33,    0,  251,    2, 0x08 /* Private */,
      34,    0,  252,    2, 0x08 /* Private */,
      35,    0,  253,    2, 0x08 /* Private */,
      36,    0,  254,    2, 0x08 /* Private */,
      37,    0,  255,    2, 0x08 /* Private */,
      38,    1,  256,    2, 0x08 /* Private */,
      41,    1,  259,    2, 0x08 /* Private */,
      42,    0,  262,    2, 0x08 /* Private */,
      43,    0,  263,    2, 0x08 /* Private */,
      44,    1,  264,    2, 0x08 /* Private */,
      46,    0,  267,    2, 0x08 /* Private */,
      47,    0,  268,    2, 0x08 /* Private */,
      48,    0,  269,    2, 0x08 /* Private */,
      49,    1,  270,    2, 0x08 /* Private */,
      50,    0,  273,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 39,   40,
    QMetaType::Void, 0x80000000 | 39,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   45,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   45,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
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
        case 8: _t->parseRxSweepData(); break;
        case 9: _t->PlotMeasurement(); break;
        case 10: _t->setUpTables(); break;
        case 11: _t->clearTables(); break;
        case 12: _t->updateTables(); break;
        case 13: _t->updateStatistics(); break;
        case 14: _t->on_pushButtonBTdiscoverDevices_clicked(); break;
        case 15: _t->on_pushButtonBTconnect_clicked(); break;
        case 16: _t->on_pushButtonATSend_clicked(); break;
        case 17: _t->on_radioButtonWiFi_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_radioButtonBT_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->on_pushButtonWiFiConnect_clicked(); break;
        case 20: _t->on_pushButtonWiFiDisconnect_clicked(); break;
        case 21: _t->on_checkBoxConfigAntialias_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->on_pushButtonBTdisconnect_clicked(); break;
        case 23: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 24: _t->on_pushButtonGenerateCalibration_clicked(); break;
        case 25: _t->on_pushButtonOpenCalFile_clicked(); break;
        case 26: _t->on_pushButtonSaveCalFile_clicked(); break;
        case 27: _t->on_action_Run_triggered(); break;
        case 28: _t->on_action_Clean_triggered(); break;
        case 29: _t->on_tableViewMag_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 30: _t->on_tableViewPha_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 31: _t->on_action_Delete_sweep_triggered(); break;
        case 32: _t->on_pushButtonAddTag_clicked(); break;
        case 33: _t->on_comboBoxTagSelect_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->on_pushButtonSaveTag_clicked(); break;
        case 35: _t->on_pushButtonLoadTag_clicked(); break;
        case 36: _t->on_action_Save_triggered(); break;
        case 37: _t->on_comboBoxPA_config_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 38: _t->on_pushButtonPA_Config_clicked(); break;
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

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


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
