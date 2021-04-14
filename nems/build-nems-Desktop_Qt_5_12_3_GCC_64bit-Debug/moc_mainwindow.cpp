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
    QByteArrayData data[60];
    char stringdata0[1341];
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
QT_MOC_LITERAL(9, 77, 8), // "WiFiRead"
QT_MOC_LITERAL(10, 86, 16), // "WiFiDisplayError"
QT_MOC_LITERAL(11, 103, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(12, 132, 11), // "socketError"
QT_MOC_LITERAL(13, 144, 6), // "PlotRx"
QT_MOC_LITERAL(14, 151, 11), // "PlotTimeout"
QT_MOC_LITERAL(15, 163, 14), // "SilenceTimeout"
QT_MOC_LITERAL(16, 178, 16), // "UpdateSensorData"
QT_MOC_LITERAL(17, 195, 10), // "SearchDone"
QT_MOC_LITERAL(18, 206, 4), // "send"
QT_MOC_LITERAL(19, 211, 12), // "parseProgram"
QT_MOC_LITERAL(20, 224, 38), // "on_pushButtonBTdiscoverDevice..."
QT_MOC_LITERAL(21, 263, 30), // "on_pushButtonBTconnect_clicked"
QT_MOC_LITERAL(22, 294, 27), // "on_pushButtonATSend_clicked"
QT_MOC_LITERAL(23, 322, 26), // "on_radioButtonWiFi_toggled"
QT_MOC_LITERAL(24, 349, 7), // "checked"
QT_MOC_LITERAL(25, 357, 24), // "on_radioButtonBT_toggled"
QT_MOC_LITERAL(26, 382, 32), // "on_pushButtonWiFiConnect_clicked"
QT_MOC_LITERAL(27, 415, 35), // "on_pushButtonWiFiDisconnect_c..."
QT_MOC_LITERAL(28, 451, 34), // "on_checkBoxConfigAntialias_to..."
QT_MOC_LITERAL(29, 486, 33), // "on_pushButtonBTdisconnect_cli..."
QT_MOC_LITERAL(30, 520, 11), // "resizeEvent"
QT_MOC_LITERAL(31, 532, 13), // "QResizeEvent*"
QT_MOC_LITERAL(32, 546, 5), // "event"
QT_MOC_LITERAL(33, 552, 23), // "on_action_Run_triggered"
QT_MOC_LITERAL(34, 576, 25), // "on_action_Clean_triggered"
QT_MOC_LITERAL(35, 602, 32), // "on_action_Delete_sweep_triggered"
QT_MOC_LITERAL(36, 635, 24), // "on_action_Save_triggered"
QT_MOC_LITERAL(37, 660, 30), // "on_pushButtonAmplitude_clicked"
QT_MOC_LITERAL(38, 691, 30), // "on_pushButtonFrequency_clicked"
QT_MOC_LITERAL(39, 722, 26), // "on_pushButtonPhase_clicked"
QT_MOC_LITERAL(40, 749, 28), // "on_pushButtonSymetry_clicked"
QT_MOC_LITERAL(41, 778, 27), // "on_pushButtonOnTime_clicked"
QT_MOC_LITERAL(42, 806, 24), // "on_pushButtonOFF_clicked"
QT_MOC_LITERAL(43, 831, 27), // "on_pushButtonRampUp_clicked"
QT_MOC_LITERAL(44, 859, 29), // "on_pushButtonRampDown_clicked"
QT_MOC_LITERAL(45, 889, 33), // "on_pushButtonContractions_cli..."
QT_MOC_LITERAL(46, 923, 29), // "on_pushButtonChannel1_clicked"
QT_MOC_LITERAL(47, 953, 29), // "on_pushButtonChannel2_clicked"
QT_MOC_LITERAL(48, 983, 23), // "on_actionStop_triggered"
QT_MOC_LITERAL(49, 1007, 24), // "on_action_Open_triggered"
QT_MOC_LITERAL(50, 1032, 35), // "on_action_Display_program_tri..."
QT_MOC_LITERAL(51, 1068, 29), // "on_pushButtonChannel3_clicked"
QT_MOC_LITERAL(52, 1098, 29), // "on_pushButtonChannel4_clicked"
QT_MOC_LITERAL(53, 1128, 31), // "on_pushButtonAmplitude2_clicked"
QT_MOC_LITERAL(54, 1160, 26), // "on_actionSensors_triggered"
QT_MOC_LITERAL(55, 1187, 39), // "on_verticalSliderEnergyMax_va..."
QT_MOC_LITERAL(56, 1227, 5), // "value"
QT_MOC_LITERAL(57, 1233, 45), // "on_verticalSliderEnergyThresh..."
QT_MOC_LITERAL(58, 1279, 35), // "on_pushButtonResetMaxEnergy_c..."
QT_MOC_LITERAL(59, 1315, 25) // "on_actionSearch_triggered"

    },
    "MainWindow\0updateSearchText\0\0text\0"
    "BTgetDevice\0name\0BTConnected\0BTrxData\0"
    "data\0WiFiRead\0WiFiDisplayError\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "PlotRx\0PlotTimeout\0SilenceTimeout\0"
    "UpdateSensorData\0SearchDone\0send\0"
    "parseProgram\0on_pushButtonBTdiscoverDevices_clicked\0"
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
    "on_pushButtonResetMaxEnergy_clicked\0"
    "on_actionSearch_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      49,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  259,    2, 0x0a /* Public */,
       4,    1,  262,    2, 0x08 /* Private */,
       6,    1,  265,    2, 0x08 /* Private */,
       7,    1,  268,    2, 0x08 /* Private */,
       9,    0,  271,    2, 0x08 /* Private */,
      10,    1,  272,    2, 0x08 /* Private */,
      13,    1,  275,    2, 0x08 /* Private */,
      14,    0,  278,    2, 0x08 /* Private */,
      15,    0,  279,    2, 0x08 /* Private */,
      16,    0,  280,    2, 0x08 /* Private */,
      17,    0,  281,    2, 0x08 /* Private */,
      18,    1,  282,    2, 0x08 /* Private */,
      19,    1,  285,    2, 0x08 /* Private */,
      20,    0,  288,    2, 0x08 /* Private */,
      21,    0,  289,    2, 0x08 /* Private */,
      22,    0,  290,    2, 0x08 /* Private */,
      23,    1,  291,    2, 0x08 /* Private */,
      25,    1,  294,    2, 0x08 /* Private */,
      26,    0,  297,    2, 0x08 /* Private */,
      27,    0,  298,    2, 0x08 /* Private */,
      28,    1,  299,    2, 0x08 /* Private */,
      29,    0,  302,    2, 0x08 /* Private */,
      30,    1,  303,    2, 0x08 /* Private */,
      33,    0,  306,    2, 0x08 /* Private */,
      34,    0,  307,    2, 0x08 /* Private */,
      35,    0,  308,    2, 0x08 /* Private */,
      36,    0,  309,    2, 0x08 /* Private */,
      37,    0,  310,    2, 0x08 /* Private */,
      38,    0,  311,    2, 0x08 /* Private */,
      39,    0,  312,    2, 0x08 /* Private */,
      40,    0,  313,    2, 0x08 /* Private */,
      41,    0,  314,    2, 0x08 /* Private */,
      42,    0,  315,    2, 0x08 /* Private */,
      43,    0,  316,    2, 0x08 /* Private */,
      44,    0,  317,    2, 0x08 /* Private */,
      45,    0,  318,    2, 0x08 /* Private */,
      46,    0,  319,    2, 0x08 /* Private */,
      47,    0,  320,    2, 0x08 /* Private */,
      48,    0,  321,    2, 0x08 /* Private */,
      49,    0,  322,    2, 0x08 /* Private */,
      50,    0,  323,    2, 0x08 /* Private */,
      51,    0,  324,    2, 0x08 /* Private */,
      52,    0,  325,    2, 0x08 /* Private */,
      53,    0,  326,    2, 0x08 /* Private */,
      54,    1,  327,    2, 0x08 /* Private */,
      55,    1,  330,    2, 0x08 /* Private */,
      57,    1,  333,    2, 0x08 /* Private */,
      58,    0,  336,    2, 0x08 /* Private */,
      59,    0,  337,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
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
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Int,   56,
    QMetaType::Void, QMetaType::Int,   56,
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
        case 4: _t->WiFiRead(); break;
        case 5: _t->WiFiDisplayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 6: _t->PlotRx((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 7: _t->PlotTimeout(); break;
        case 8: _t->SilenceTimeout(); break;
        case 9: _t->UpdateSensorData(); break;
        case 10: _t->SearchDone(); break;
        case 11: _t->send((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 12: _t->parseProgram((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
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
        case 44: _t->on_actionSensors_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 45: _t->on_verticalSliderEnergyMax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 46: _t->on_verticalSliderEnergyThreshold_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->on_pushButtonResetMaxEnergy_clicked(); break;
        case 48: _t->on_actionSearch_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
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
        if (_id < 49)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 49;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 49)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 49;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
