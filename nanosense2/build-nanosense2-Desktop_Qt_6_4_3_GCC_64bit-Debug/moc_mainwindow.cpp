/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../nanosense2/mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[108];
    char stringdata0[11];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[12];
    char stringdata5[9];
    char stringdata6[5];
    char stringdata7[9];
    char stringdata8[17];
    char stringdata9[29];
    char stringdata10[12];
    char stringdata11[7];
    char stringdata12[12];
    char stringdata13[19];
    char stringdata14[17];
    char stringdata15[16];
    char stringdata16[12];
    char stringdata17[12];
    char stringdata18[13];
    char stringdata19[17];
    char stringdata20[26];
    char stringdata21[39];
    char stringdata22[31];
    char stringdata23[28];
    char stringdata24[27];
    char stringdata25[8];
    char stringdata26[25];
    char stringdata27[33];
    char stringdata28[36];
    char stringdata29[35];
    char stringdata30[34];
    char stringdata31[12];
    char stringdata32[14];
    char stringdata33[6];
    char stringdata34[41];
    char stringdata35[33];
    char stringdata36[33];
    char stringdata37[24];
    char stringdata38[26];
    char stringdata39[24];
    char stringdata40[12];
    char stringdata41[6];
    char stringdata42[24];
    char stringdata43[33];
    char stringdata44[28];
    char stringdata45[41];
    char stringdata46[5];
    char stringdata47[29];
    char stringdata48[29];
    char stringdata49[25];
    char stringdata50[41];
    char stringdata51[31];
    char stringdata52[29];
    char stringdata53[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 11),  // "BTgetDevice"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 4),  // "name"
        QT_MOC_LITERAL(29, 11),  // "BTConnected"
        QT_MOC_LITERAL(41, 8),  // "BTrxData"
        QT_MOC_LITERAL(50, 4),  // "data"
        QT_MOC_LITERAL(55, 8),  // "WiFiRead"
        QT_MOC_LITERAL(64, 16),  // "WiFiDisplayError"
        QT_MOC_LITERAL(81, 28),  // "QAbstractSocket::SocketError"
        QT_MOC_LITERAL(110, 11),  // "socketError"
        QT_MOC_LITERAL(122, 6),  // "PlotRx"
        QT_MOC_LITERAL(129, 11),  // "PlotTimeout"
        QT_MOC_LITERAL(141, 18),  // "MeasurementTimeout"
        QT_MOC_LITERAL(160, 16),  // "parseRxSweepData"
        QT_MOC_LITERAL(177, 15),  // "PlotMeasurement"
        QT_MOC_LITERAL(193, 11),  // "setUpTables"
        QT_MOC_LITERAL(205, 11),  // "clearTables"
        QT_MOC_LITERAL(217, 12),  // "updateTables"
        QT_MOC_LITERAL(230, 16),  // "updateStatistics"
        QT_MOC_LITERAL(247, 25),  // "MeasurementDelayedTimeout"
        QT_MOC_LITERAL(273, 38),  // "on_pushButtonBTdiscoverDevice..."
        QT_MOC_LITERAL(312, 30),  // "on_pushButtonBTconnect_clicked"
        QT_MOC_LITERAL(343, 27),  // "on_pushButtonATSend_clicked"
        QT_MOC_LITERAL(371, 26),  // "on_radioButtonWiFi_toggled"
        QT_MOC_LITERAL(398, 7),  // "checked"
        QT_MOC_LITERAL(406, 24),  // "on_radioButtonBT_toggled"
        QT_MOC_LITERAL(431, 32),  // "on_pushButtonWiFiConnect_clicked"
        QT_MOC_LITERAL(464, 35),  // "on_pushButtonWiFiDisconnect_c..."
        QT_MOC_LITERAL(500, 34),  // "on_checkBoxConfigAntialias_to..."
        QT_MOC_LITERAL(535, 33),  // "on_pushButtonBTdisconnect_cli..."
        QT_MOC_LITERAL(569, 11),  // "resizeEvent"
        QT_MOC_LITERAL(581, 13),  // "QResizeEvent*"
        QT_MOC_LITERAL(595, 5),  // "event"
        QT_MOC_LITERAL(601, 40),  // "on_pushButtonGenerateCalibrat..."
        QT_MOC_LITERAL(642, 32),  // "on_pushButtonOpenCalFile_clicked"
        QT_MOC_LITERAL(675, 32),  // "on_pushButtonSaveCalFile_clicked"
        QT_MOC_LITERAL(708, 23),  // "on_action_Run_triggered"
        QT_MOC_LITERAL(732, 25),  // "on_action_Clean_triggered"
        QT_MOC_LITERAL(758, 23),  // "on_tableViewMag_clicked"
        QT_MOC_LITERAL(782, 11),  // "QModelIndex"
        QT_MOC_LITERAL(794, 5),  // "index"
        QT_MOC_LITERAL(800, 23),  // "on_tableViewPha_clicked"
        QT_MOC_LITERAL(824, 32),  // "on_action_Delete_sweep_triggered"
        QT_MOC_LITERAL(857, 27),  // "on_pushButtonAddTag_clicked"
        QT_MOC_LITERAL(885, 40),  // "on_comboBoxTagSelect_currentI..."
        QT_MOC_LITERAL(926, 4),  // "arg1"
        QT_MOC_LITERAL(931, 28),  // "on_pushButtonSaveTag_clicked"
        QT_MOC_LITERAL(960, 28),  // "on_pushButtonLoadTag_clicked"
        QT_MOC_LITERAL(989, 24),  // "on_action_Save_triggered"
        QT_MOC_LITERAL(1014, 40),  // "on_comboBoxPA_config_currentI..."
        QT_MOC_LITERAL(1055, 30),  // "on_pushButtonPA_Config_clicked"
        QT_MOC_LITERAL(1086, 28),  // "on_actionRun_Timer_triggered"
        QT_MOC_LITERAL(1115, 19)   // "on_actionAM_toggled"
    },
    "MainWindow",
    "BTgetDevice",
    "",
    "name",
    "BTConnected",
    "BTrxData",
    "data",
    "WiFiRead",
    "WiFiDisplayError",
    "QAbstractSocket::SocketError",
    "socketError",
    "PlotRx",
    "PlotTimeout",
    "MeasurementTimeout",
    "parseRxSweepData",
    "PlotMeasurement",
    "setUpTables",
    "clearTables",
    "updateTables",
    "updateStatistics",
    "MeasurementDelayedTimeout",
    "on_pushButtonBTdiscoverDevices_clicked",
    "on_pushButtonBTconnect_clicked",
    "on_pushButtonATSend_clicked",
    "on_radioButtonWiFi_toggled",
    "checked",
    "on_radioButtonBT_toggled",
    "on_pushButtonWiFiConnect_clicked",
    "on_pushButtonWiFiDisconnect_clicked",
    "on_checkBoxConfigAntialias_toggled",
    "on_pushButtonBTdisconnect_clicked",
    "resizeEvent",
    "QResizeEvent*",
    "event",
    "on_pushButtonGenerateCalibration_clicked",
    "on_pushButtonOpenCalFile_clicked",
    "on_pushButtonSaveCalFile_clicked",
    "on_action_Run_triggered",
    "on_action_Clean_triggered",
    "on_tableViewMag_clicked",
    "QModelIndex",
    "index",
    "on_tableViewPha_clicked",
    "on_action_Delete_sweep_triggered",
    "on_pushButtonAddTag_clicked",
    "on_comboBoxTagSelect_currentIndexChanged",
    "arg1",
    "on_pushButtonSaveTag_clicked",
    "on_pushButtonLoadTag_clicked",
    "on_action_Save_triggered",
    "on_comboBoxPA_config_currentIndexChanged",
    "on_pushButtonPA_Config_clicked",
    "on_actionRun_Timer_triggered",
    "on_actionAM_toggled"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  266,    2, 0x08,    1 /* Private */,
       4,    1,  269,    2, 0x08,    3 /* Private */,
       5,    1,  272,    2, 0x08,    5 /* Private */,
       7,    0,  275,    2, 0x08,    7 /* Private */,
       8,    1,  276,    2, 0x08,    8 /* Private */,
      11,    1,  279,    2, 0x08,   10 /* Private */,
      12,    0,  282,    2, 0x08,   12 /* Private */,
      13,    0,  283,    2, 0x08,   13 /* Private */,
      14,    0,  284,    2, 0x08,   14 /* Private */,
      15,    0,  285,    2, 0x08,   15 /* Private */,
      16,    0,  286,    2, 0x08,   16 /* Private */,
      17,    0,  287,    2, 0x08,   17 /* Private */,
      18,    0,  288,    2, 0x08,   18 /* Private */,
      19,    0,  289,    2, 0x08,   19 /* Private */,
      20,    0,  290,    2, 0x08,   20 /* Private */,
      21,    0,  291,    2, 0x08,   21 /* Private */,
      22,    0,  292,    2, 0x08,   22 /* Private */,
      23,    0,  293,    2, 0x08,   23 /* Private */,
      24,    1,  294,    2, 0x08,   24 /* Private */,
      26,    1,  297,    2, 0x08,   26 /* Private */,
      27,    0,  300,    2, 0x08,   28 /* Private */,
      28,    0,  301,    2, 0x08,   29 /* Private */,
      29,    1,  302,    2, 0x08,   30 /* Private */,
      30,    0,  305,    2, 0x08,   32 /* Private */,
      31,    1,  306,    2, 0x08,   33 /* Private */,
      34,    0,  309,    2, 0x08,   35 /* Private */,
      35,    0,  310,    2, 0x08,   36 /* Private */,
      36,    0,  311,    2, 0x08,   37 /* Private */,
      37,    0,  312,    2, 0x08,   38 /* Private */,
      38,    0,  313,    2, 0x08,   39 /* Private */,
      39,    1,  314,    2, 0x08,   40 /* Private */,
      42,    1,  317,    2, 0x08,   42 /* Private */,
      43,    0,  320,    2, 0x08,   44 /* Private */,
      44,    0,  321,    2, 0x08,   45 /* Private */,
      45,    1,  322,    2, 0x08,   46 /* Private */,
      47,    0,  325,    2, 0x08,   48 /* Private */,
      48,    0,  326,    2, 0x08,   49 /* Private */,
      49,    0,  327,    2, 0x08,   50 /* Private */,
      50,    1,  328,    2, 0x08,   51 /* Private */,
      51,    0,  331,    2, 0x08,   53 /* Private */,
      52,    0,  332,    2, 0x08,   54 /* Private */,
      53,    1,  333,    2, 0x08,   55 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   46,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   46,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   46,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'BTgetDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'BTConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'BTrxData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'WiFiRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'WiFiDisplayError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'PlotRx'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'PlotTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'MeasurementTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'parseRxSweepData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'PlotMeasurement'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setUpTables'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearTables'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateTables'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateStatistics'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'MeasurementDelayedTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        // method 'on_pushButtonWiFiConnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonWiFiDisconnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkBoxConfigAntialias_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_pushButtonBTdisconnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resizeEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>,
        // method 'on_pushButtonGenerateCalibration_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonOpenCalFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSaveCalFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_Run_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_Clean_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableViewMag_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_tableViewPha_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_action_Delete_sweep_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonAddTag_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBoxTagSelect_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButtonSaveTag_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonLoadTag_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_action_Save_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comboBoxPA_config_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButtonPA_Config_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionRun_Timer_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actionAM_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->BTgetDevice((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->BTConnected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->BTrxData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 3: _t->WiFiRead(); break;
        case 4: _t->WiFiDisplayError((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 5: _t->PlotRx((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 6: _t->PlotTimeout(); break;
        case 7: _t->MeasurementTimeout(); break;
        case 8: _t->parseRxSweepData(); break;
        case 9: _t->PlotMeasurement(); break;
        case 10: _t->setUpTables(); break;
        case 11: _t->clearTables(); break;
        case 12: _t->updateTables(); break;
        case 13: _t->updateStatistics(); break;
        case 14: _t->MeasurementDelayedTimeout(); break;
        case 15: _t->on_pushButtonBTdiscoverDevices_clicked(); break;
        case 16: _t->on_pushButtonBTconnect_clicked(); break;
        case 17: _t->on_pushButtonATSend_clicked(); break;
        case 18: _t->on_radioButtonWiFi_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 19: _t->on_radioButtonBT_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->on_pushButtonWiFiConnect_clicked(); break;
        case 21: _t->on_pushButtonWiFiDisconnect_clicked(); break;
        case 22: _t->on_checkBoxConfigAntialias_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 23: _t->on_pushButtonBTdisconnect_clicked(); break;
        case 24: _t->resizeEvent((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        case 25: _t->on_pushButtonGenerateCalibration_clicked(); break;
        case 26: _t->on_pushButtonOpenCalFile_clicked(); break;
        case 27: _t->on_pushButtonSaveCalFile_clicked(); break;
        case 28: _t->on_action_Run_triggered(); break;
        case 29: _t->on_action_Clean_triggered(); break;
        case 30: _t->on_tableViewMag_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 31: _t->on_tableViewPha_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 32: _t->on_action_Delete_sweep_triggered(); break;
        case 33: _t->on_pushButtonAddTag_clicked(); break;
        case 34: _t->on_comboBoxTagSelect_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 35: _t->on_pushButtonSaveTag_clicked(); break;
        case 36: _t->on_pushButtonLoadTag_clicked(); break;
        case 37: _t->on_action_Save_triggered(); break;
        case 38: _t->on_comboBoxPA_config_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 39: _t->on_pushButtonPA_Config_clicked(); break;
        case 40: _t->on_actionRun_Timer_triggered(); break;
        case 41: _t->on_actionAM_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
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
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
