/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tester/mainwindow.h"
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
    QByteArrayData data[47];
    char stringdata0[974];
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
QT_MOC_LITERAL(7, 55, 6), // "PlotRx"
QT_MOC_LITERAL(8, 62, 11), // "PlotTimeout"
QT_MOC_LITERAL(9, 74, 18), // "MeasurementTimeout"
QT_MOC_LITERAL(10, 93, 16), // "parseRxSweepData"
QT_MOC_LITERAL(11, 110, 15), // "PlotMeasurement"
QT_MOC_LITERAL(12, 126, 11), // "setUpTables"
QT_MOC_LITERAL(13, 138, 11), // "clearTables"
QT_MOC_LITERAL(14, 150, 12), // "updateTables"
QT_MOC_LITERAL(15, 163, 16), // "updateStatistics"
QT_MOC_LITERAL(16, 180, 25), // "MeasurementDelayedTimeout"
QT_MOC_LITERAL(17, 206, 38), // "on_pushButtonBTdiscoverDevice..."
QT_MOC_LITERAL(18, 245, 30), // "on_pushButtonBTconnect_clicked"
QT_MOC_LITERAL(19, 276, 27), // "on_pushButtonATSend_clicked"
QT_MOC_LITERAL(20, 304, 24), // "on_radioButtonBT_toggled"
QT_MOC_LITERAL(21, 329, 7), // "checked"
QT_MOC_LITERAL(22, 337, 34), // "on_checkBoxConfigAntialias_to..."
QT_MOC_LITERAL(23, 372, 33), // "on_pushButtonBTdisconnect_cli..."
QT_MOC_LITERAL(24, 406, 11), // "resizeEvent"
QT_MOC_LITERAL(25, 418, 13), // "QResizeEvent*"
QT_MOC_LITERAL(26, 432, 5), // "event"
QT_MOC_LITERAL(27, 438, 40), // "on_pushButtonGenerateCalibrat..."
QT_MOC_LITERAL(28, 479, 32), // "on_pushButtonOpenCalFile_clicked"
QT_MOC_LITERAL(29, 512, 32), // "on_pushButtonSaveCalFile_clicked"
QT_MOC_LITERAL(30, 545, 23), // "on_action_Run_triggered"
QT_MOC_LITERAL(31, 569, 25), // "on_action_Clean_triggered"
QT_MOC_LITERAL(32, 595, 23), // "on_tableViewMag_clicked"
QT_MOC_LITERAL(33, 619, 11), // "QModelIndex"
QT_MOC_LITERAL(34, 631, 5), // "index"
QT_MOC_LITERAL(35, 637, 23), // "on_tableViewPha_clicked"
QT_MOC_LITERAL(36, 661, 32), // "on_action_Delete_sweep_triggered"
QT_MOC_LITERAL(37, 694, 27), // "on_pushButtonAddTag_clicked"
QT_MOC_LITERAL(38, 722, 40), // "on_comboBoxTagSelect_currentI..."
QT_MOC_LITERAL(39, 763, 4), // "arg1"
QT_MOC_LITERAL(40, 768, 28), // "on_pushButtonSaveTag_clicked"
QT_MOC_LITERAL(41, 797, 28), // "on_pushButtonLoadTag_clicked"
QT_MOC_LITERAL(42, 826, 24), // "on_action_Save_triggered"
QT_MOC_LITERAL(43, 851, 40), // "on_comboBoxPA_config_currentI..."
QT_MOC_LITERAL(44, 892, 30), // "on_pushButtonPA_Config_clicked"
QT_MOC_LITERAL(45, 923, 28), // "on_actionRun_Timer_triggered"
QT_MOC_LITERAL(46, 952, 21) // "on_actionAM_triggered"

    },
    "MainWindow\0BTgetDevice\0\0name\0BTConnected\0"
    "BTrxData\0data\0PlotRx\0PlotTimeout\0"
    "MeasurementTimeout\0parseRxSweepData\0"
    "PlotMeasurement\0setUpTables\0clearTables\0"
    "updateTables\0updateStatistics\0"
    "MeasurementDelayedTimeout\0"
    "on_pushButtonBTdiscoverDevices_clicked\0"
    "on_pushButtonBTconnect_clicked\0"
    "on_pushButtonATSend_clicked\0"
    "on_radioButtonBT_toggled\0checked\0"
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
    "on_pushButtonPA_Config_clicked\0"
    "on_actionRun_Timer_triggered\0"
    "on_actionAM_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  199,    2, 0x08 /* Private */,
       4,    1,  202,    2, 0x08 /* Private */,
       5,    1,  205,    2, 0x08 /* Private */,
       7,    1,  208,    2, 0x08 /* Private */,
       8,    0,  211,    2, 0x08 /* Private */,
       9,    0,  212,    2, 0x08 /* Private */,
      10,    0,  213,    2, 0x08 /* Private */,
      11,    0,  214,    2, 0x08 /* Private */,
      12,    0,  215,    2, 0x08 /* Private */,
      13,    0,  216,    2, 0x08 /* Private */,
      14,    0,  217,    2, 0x08 /* Private */,
      15,    0,  218,    2, 0x08 /* Private */,
      16,    0,  219,    2, 0x08 /* Private */,
      17,    0,  220,    2, 0x08 /* Private */,
      18,    0,  221,    2, 0x08 /* Private */,
      19,    0,  222,    2, 0x08 /* Private */,
      20,    1,  223,    2, 0x08 /* Private */,
      22,    1,  226,    2, 0x08 /* Private */,
      23,    0,  229,    2, 0x08 /* Private */,
      24,    1,  230,    2, 0x08 /* Private */,
      27,    0,  233,    2, 0x08 /* Private */,
      28,    0,  234,    2, 0x08 /* Private */,
      29,    0,  235,    2, 0x08 /* Private */,
      30,    0,  236,    2, 0x08 /* Private */,
      31,    0,  237,    2, 0x08 /* Private */,
      32,    1,  238,    2, 0x08 /* Private */,
      35,    1,  241,    2, 0x08 /* Private */,
      36,    0,  244,    2, 0x08 /* Private */,
      37,    0,  245,    2, 0x08 /* Private */,
      38,    1,  246,    2, 0x08 /* Private */,
      40,    0,  249,    2, 0x08 /* Private */,
      41,    0,  250,    2, 0x08 /* Private */,
      42,    0,  251,    2, 0x08 /* Private */,
      43,    1,  252,    2, 0x08 /* Private */,
      44,    0,  255,    2, 0x08 /* Private */,
      45,    0,  256,    2, 0x08 /* Private */,
      46,    0,  257,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QByteArray,    6,
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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 33,   34,
    QMetaType::Void, 0x80000000 | 33,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::Void,
    QMetaType::Void,
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
        case 3: _t->PlotRx((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->PlotTimeout(); break;
        case 5: _t->MeasurementTimeout(); break;
        case 6: _t->parseRxSweepData(); break;
        case 7: _t->PlotMeasurement(); break;
        case 8: _t->setUpTables(); break;
        case 9: _t->clearTables(); break;
        case 10: _t->updateTables(); break;
        case 11: _t->updateStatistics(); break;
        case 12: _t->MeasurementDelayedTimeout(); break;
        case 13: _t->on_pushButtonBTdiscoverDevices_clicked(); break;
        case 14: _t->on_pushButtonBTconnect_clicked(); break;
        case 15: _t->on_pushButtonATSend_clicked(); break;
        case 16: _t->on_radioButtonBT_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->on_checkBoxConfigAntialias_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_pushButtonBTdisconnect_clicked(); break;
        case 19: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 20: _t->on_pushButtonGenerateCalibration_clicked(); break;
        case 21: _t->on_pushButtonOpenCalFile_clicked(); break;
        case 22: _t->on_pushButtonSaveCalFile_clicked(); break;
        case 23: _t->on_action_Run_triggered(); break;
        case 24: _t->on_action_Clean_triggered(); break;
        case 25: _t->on_tableViewMag_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 26: _t->on_tableViewPha_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 27: _t->on_action_Delete_sweep_triggered(); break;
        case 28: _t->on_pushButtonAddTag_clicked(); break;
        case 29: _t->on_comboBoxTagSelect_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 30: _t->on_pushButtonSaveTag_clicked(); break;
        case 31: _t->on_pushButtonLoadTag_clicked(); break;
        case 32: _t->on_action_Save_triggered(); break;
        case 33: _t->on_comboBoxPA_config_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->on_pushButtonPA_Config_clicked(); break;
        case 35: _t->on_actionRun_Timer_triggered(); break;
        case 36: _t->on_actionAM_triggered(); break;
        default: ;
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
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 37;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
