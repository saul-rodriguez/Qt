/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bio2016/mainwindow.h"
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
    QByteArrayData data[46];
    char stringdata0[1147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 33), // "on_pushButtonRefreshPorts_cli..."
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 28), // "on_pushButtonConnect_clicked"
QT_MOC_LITERAL(4, 75, 25), // "on_pushButtonTest_clicked"
QT_MOC_LITERAL(5, 101, 8), // "SerialRx"
QT_MOC_LITERAL(6, 110, 4), // "Data"
QT_MOC_LITERAL(7, 115, 30), // "on_pushButtonConfigure_clicked"
QT_MOC_LITERAL(8, 146, 30), // "on_pushButtonConfigAll_clicked"
QT_MOC_LITERAL(9, 177, 28), // "on_pushButtonTestADC_clicked"
QT_MOC_LITERAL(10, 206, 28), // "on_pushButtonAllTest_clicked"
QT_MOC_LITERAL(11, 235, 31), // "on_pushButtonSaveOffset_clicked"
QT_MOC_LITERAL(12, 267, 26), // "on_pushButtonSaveI_clicked"
QT_MOC_LITERAL(13, 294, 26), // "on_pushButtonSaveQ_clicked"
QT_MOC_LITERAL(14, 321, 26), // "on_pushButtonCalcZ_clicked"
QT_MOC_LITERAL(15, 348, 29), // "on_pushButtonMeasureZ_clicked"
QT_MOC_LITERAL(16, 378, 29), // "on_checkBoxLightTheme_toggled"
QT_MOC_LITERAL(17, 408, 7), // "checked"
QT_MOC_LITERAL(18, 416, 26), // "on_checkBoxSemilog_toggled"
QT_MOC_LITERAL(19, 443, 36), // "on_comboBoxFreqs_currentIndex..."
QT_MOC_LITERAL(20, 480, 5), // "index"
QT_MOC_LITERAL(21, 486, 26), // "on_pushButtonSweep_clicked"
QT_MOC_LITERAL(22, 513, 30), // "on_checkBoxAppend_stateChanged"
QT_MOC_LITERAL(23, 544, 4), // "arg1"
QT_MOC_LITERAL(24, 549, 35), // "on_comboBoxGain_currentIndexC..."
QT_MOC_LITERAL(25, 585, 43), // "on_lineEditStatisticSamples_e..."
QT_MOC_LITERAL(26, 629, 32), // "on_pushButtonClearTables_clicked"
QT_MOC_LITERAL(27, 662, 38), // "on_pushButtonUpdateCalibratio..."
QT_MOC_LITERAL(28, 701, 28), // "on_pushButtonSaveCal_clicked"
QT_MOC_LITERAL(29, 730, 28), // "on_pushButtonLoadCal_clicked"
QT_MOC_LITERAL(30, 759, 24), // "on_actionSweep_triggered"
QT_MOC_LITERAL(31, 784, 35), // "on_actionSave_Measurement_tri..."
QT_MOC_LITERAL(32, 820, 34), // "on_checkBoxRMSasPercentage_cl..."
QT_MOC_LITERAL(33, 855, 31), // "on_actionClean_Tables_triggered"
QT_MOC_LITERAL(34, 887, 30), // "on_actionSave_Tables_triggered"
QT_MOC_LITERAL(35, 918, 34), // "on_pushButtonMeasureOffset_cl..."
QT_MOC_LITERAL(36, 953, 19), // "measurement_timeout"
QT_MOC_LITERAL(37, 973, 30), // "on_actionDelete_icon_triggered"
QT_MOC_LITERAL(38, 1004, 25), // "on_tableViewPhase_clicked"
QT_MOC_LITERAL(39, 1030, 11), // "QModelIndex"
QT_MOC_LITERAL(40, 1042, 23), // "on_tableViewMag_clicked"
QT_MOC_LITERAL(41, 1066, 12), // "tableChanged"
QT_MOC_LITERAL(42, 1079, 6), // "index1"
QT_MOC_LITERAL(43, 1086, 6), // "index2"
QT_MOC_LITERAL(44, 1093, 29), // "on_actionPlay_Delay_triggered"
QT_MOC_LITERAL(45, 1123, 23) // "delayed_trigger_timeout"

    },
    "MainWindow\0on_pushButtonRefreshPorts_clicked\0"
    "\0on_pushButtonConnect_clicked\0"
    "on_pushButtonTest_clicked\0SerialRx\0"
    "Data\0on_pushButtonConfigure_clicked\0"
    "on_pushButtonConfigAll_clicked\0"
    "on_pushButtonTestADC_clicked\0"
    "on_pushButtonAllTest_clicked\0"
    "on_pushButtonSaveOffset_clicked\0"
    "on_pushButtonSaveI_clicked\0"
    "on_pushButtonSaveQ_clicked\0"
    "on_pushButtonCalcZ_clicked\0"
    "on_pushButtonMeasureZ_clicked\0"
    "on_checkBoxLightTheme_toggled\0checked\0"
    "on_checkBoxSemilog_toggled\0"
    "on_comboBoxFreqs_currentIndexChanged\0"
    "index\0on_pushButtonSweep_clicked\0"
    "on_checkBoxAppend_stateChanged\0arg1\0"
    "on_comboBoxGain_currentIndexChanged\0"
    "on_lineEditStatisticSamples_editingFinished\0"
    "on_pushButtonClearTables_clicked\0"
    "on_pushButtonUpdateCalibration_clicked\0"
    "on_pushButtonSaveCal_clicked\0"
    "on_pushButtonLoadCal_clicked\0"
    "on_actionSweep_triggered\0"
    "on_actionSave_Measurement_triggered\0"
    "on_checkBoxRMSasPercentage_clicked\0"
    "on_actionClean_Tables_triggered\0"
    "on_actionSave_Tables_triggered\0"
    "on_pushButtonMeasureOffset_clicked\0"
    "measurement_timeout\0on_actionDelete_icon_triggered\0"
    "on_tableViewPhase_clicked\0QModelIndex\0"
    "on_tableViewMag_clicked\0tableChanged\0"
    "index1\0index2\0on_actionPlay_Delay_triggered\0"
    "delayed_trigger_timeout"
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
       1,    0,  199,    2, 0x08 /* Private */,
       3,    0,  200,    2, 0x08 /* Private */,
       4,    0,  201,    2, 0x08 /* Private */,
       5,    1,  202,    2, 0x08 /* Private */,
       7,    0,  205,    2, 0x08 /* Private */,
       8,    0,  206,    2, 0x08 /* Private */,
       9,    0,  207,    2, 0x08 /* Private */,
      10,    0,  208,    2, 0x08 /* Private */,
      11,    0,  209,    2, 0x08 /* Private */,
      12,    0,  210,    2, 0x08 /* Private */,
      13,    0,  211,    2, 0x08 /* Private */,
      14,    0,  212,    2, 0x08 /* Private */,
      15,    0,  213,    2, 0x08 /* Private */,
      16,    1,  214,    2, 0x08 /* Private */,
      18,    1,  217,    2, 0x08 /* Private */,
      19,    1,  220,    2, 0x08 /* Private */,
      21,    0,  223,    2, 0x08 /* Private */,
      22,    1,  224,    2, 0x08 /* Private */,
      24,    1,  227,    2, 0x08 /* Private */,
      25,    0,  230,    2, 0x08 /* Private */,
      26,    0,  231,    2, 0x08 /* Private */,
      27,    0,  232,    2, 0x08 /* Private */,
      28,    0,  233,    2, 0x08 /* Private */,
      29,    0,  234,    2, 0x08 /* Private */,
      30,    0,  235,    2, 0x08 /* Private */,
      31,    0,  236,    2, 0x08 /* Private */,
      32,    0,  237,    2, 0x08 /* Private */,
      33,    0,  238,    2, 0x08 /* Private */,
      34,    0,  239,    2, 0x08 /* Private */,
      35,    0,  240,    2, 0x08 /* Private */,
      36,    0,  241,    2, 0x08 /* Private */,
      37,    0,  242,    2, 0x08 /* Private */,
      38,    1,  243,    2, 0x08 /* Private */,
      40,    1,  246,    2, 0x08 /* Private */,
      41,    2,  249,    2, 0x08 /* Private */,
      44,    0,  254,    2, 0x08 /* Private */,
      45,    0,  255,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   20,
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
    QMetaType::Void, 0x80000000 | 39,   20,
    QMetaType::Void, 0x80000000 | 39,   20,
    QMetaType::Void, 0x80000000 | 39, 0x80000000 | 39,   42,   43,
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
        case 0: _t->on_pushButtonRefreshPorts_clicked(); break;
        case 1: _t->on_pushButtonConnect_clicked(); break;
        case 2: _t->on_pushButtonTest_clicked(); break;
        case 3: _t->SerialRx((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->on_pushButtonConfigure_clicked(); break;
        case 5: _t->on_pushButtonConfigAll_clicked(); break;
        case 6: _t->on_pushButtonTestADC_clicked(); break;
        case 7: _t->on_pushButtonAllTest_clicked(); break;
        case 8: _t->on_pushButtonSaveOffset_clicked(); break;
        case 9: _t->on_pushButtonSaveI_clicked(); break;
        case 10: _t->on_pushButtonSaveQ_clicked(); break;
        case 11: _t->on_pushButtonCalcZ_clicked(); break;
        case 12: _t->on_pushButtonMeasureZ_clicked(); break;
        case 13: _t->on_checkBoxLightTheme_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_checkBoxSemilog_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_comboBoxFreqs_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_pushButtonSweep_clicked(); break;
        case 17: _t->on_checkBoxAppend_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_comboBoxGain_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_lineEditStatisticSamples_editingFinished(); break;
        case 20: _t->on_pushButtonClearTables_clicked(); break;
        case 21: _t->on_pushButtonUpdateCalibration_clicked(); break;
        case 22: _t->on_pushButtonSaveCal_clicked(); break;
        case 23: _t->on_pushButtonLoadCal_clicked(); break;
        case 24: _t->on_actionSweep_triggered(); break;
        case 25: _t->on_actionSave_Measurement_triggered(); break;
        case 26: _t->on_checkBoxRMSasPercentage_clicked(); break;
        case 27: _t->on_actionClean_Tables_triggered(); break;
        case 28: _t->on_actionSave_Tables_triggered(); break;
        case 29: _t->on_pushButtonMeasureOffset_clicked(); break;
        case 30: _t->measurement_timeout(); break;
        case 31: _t->on_actionDelete_icon_triggered(); break;
        case 32: _t->on_tableViewPhase_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 33: _t->on_tableViewMag_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 34: _t->tableChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 35: _t->on_actionPlay_Delay_triggered(); break;
        case 36: _t->delayed_trigger_timeout(); break;
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
