/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BLE_nus_test/mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_pushButtonDiscover_clicked",
    "",
    "addDevice",
    "QBluetoothDeviceInfo",
    "device",
    "scanError",
    "QBluetoothDeviceDiscoveryAgent::Error",
    "error",
    "scanFinished",
    "serviceDiscovered",
    "QBluetoothUuid",
    "gatt",
    "serviceScanDone",
    "controllerError",
    "QLowEnergyController::Error",
    "newError",
    "deviceConnected",
    "deviceDisconnected",
    "serviceStateChanged",
    "QLowEnergyService::ServiceState",
    "s",
    "updateData",
    "QLowEnergyCharacteristic",
    "c",
    "value",
    "confirmedDescriptorWrite",
    "QLowEnergyDescriptor",
    "d",
    "on_pushButtonConnect_clicked",
    "on_pushButtonSend_clicked",
    "on_pushButtonDisconnect_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[64];
    char stringdata0[11];
    char stringdata1[30];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[21];
    char stringdata5[7];
    char stringdata6[10];
    char stringdata7[38];
    char stringdata8[6];
    char stringdata9[13];
    char stringdata10[18];
    char stringdata11[15];
    char stringdata12[5];
    char stringdata13[16];
    char stringdata14[16];
    char stringdata15[28];
    char stringdata16[9];
    char stringdata17[16];
    char stringdata18[19];
    char stringdata19[20];
    char stringdata20[32];
    char stringdata21[2];
    char stringdata22[11];
    char stringdata23[25];
    char stringdata24[2];
    char stringdata25[6];
    char stringdata26[25];
    char stringdata27[21];
    char stringdata28[2];
    char stringdata29[29];
    char stringdata30[26];
    char stringdata31[32];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 29),  // "on_pushButtonDiscover_clicked"
        QT_MOC_LITERAL(41, 0),  // ""
        QT_MOC_LITERAL(42, 9),  // "addDevice"
        QT_MOC_LITERAL(52, 20),  // "QBluetoothDeviceInfo"
        QT_MOC_LITERAL(73, 6),  // "device"
        QT_MOC_LITERAL(80, 9),  // "scanError"
        QT_MOC_LITERAL(90, 37),  // "QBluetoothDeviceDiscoveryAgen..."
        QT_MOC_LITERAL(128, 5),  // "error"
        QT_MOC_LITERAL(134, 12),  // "scanFinished"
        QT_MOC_LITERAL(147, 17),  // "serviceDiscovered"
        QT_MOC_LITERAL(165, 14),  // "QBluetoothUuid"
        QT_MOC_LITERAL(180, 4),  // "gatt"
        QT_MOC_LITERAL(185, 15),  // "serviceScanDone"
        QT_MOC_LITERAL(201, 15),  // "controllerError"
        QT_MOC_LITERAL(217, 27),  // "QLowEnergyController::Error"
        QT_MOC_LITERAL(245, 8),  // "newError"
        QT_MOC_LITERAL(254, 15),  // "deviceConnected"
        QT_MOC_LITERAL(270, 18),  // "deviceDisconnected"
        QT_MOC_LITERAL(289, 19),  // "serviceStateChanged"
        QT_MOC_LITERAL(309, 31),  // "QLowEnergyService::ServiceState"
        QT_MOC_LITERAL(341, 1),  // "s"
        QT_MOC_LITERAL(343, 10),  // "updateData"
        QT_MOC_LITERAL(354, 24),  // "QLowEnergyCharacteristic"
        QT_MOC_LITERAL(379, 1),  // "c"
        QT_MOC_LITERAL(381, 5),  // "value"
        QT_MOC_LITERAL(387, 24),  // "confirmedDescriptorWrite"
        QT_MOC_LITERAL(412, 20),  // "QLowEnergyDescriptor"
        QT_MOC_LITERAL(433, 1),  // "d"
        QT_MOC_LITERAL(435, 28),  // "on_pushButtonConnect_clicked"
        QT_MOC_LITERAL(464, 25),  // "on_pushButtonSend_clicked"
        QT_MOC_LITERAL(490, 31)   // "on_pushButtonDisconnect_clicked"
    },
    "MainWindow",
    "on_pushButtonDiscover_clicked",
    "",
    "addDevice",
    "QBluetoothDeviceInfo",
    "device",
    "scanError",
    "QBluetoothDeviceDiscoveryAgent::Error",
    "error",
    "scanFinished",
    "serviceDiscovered",
    "QBluetoothUuid",
    "gatt",
    "serviceScanDone",
    "controllerError",
    "QLowEnergyController::Error",
    "newError",
    "deviceConnected",
    "deviceDisconnected",
    "serviceStateChanged",
    "QLowEnergyService::ServiceState",
    "s",
    "updateData",
    "QLowEnergyCharacteristic",
    "c",
    "value",
    "confirmedDescriptorWrite",
    "QLowEnergyDescriptor",
    "d",
    "on_pushButtonConnect_clicked",
    "on_pushButtonSend_clicked",
    "on_pushButtonDisconnect_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x08,    1 /* Private */,
       3,    1,  105,    2, 0x08,    2 /* Private */,
       6,    1,  108,    2, 0x08,    4 /* Private */,
       9,    0,  111,    2, 0x08,    6 /* Private */,
      10,    1,  112,    2, 0x08,    7 /* Private */,
      13,    0,  115,    2, 0x08,    9 /* Private */,
      14,    1,  116,    2, 0x08,   10 /* Private */,
      17,    0,  119,    2, 0x08,   12 /* Private */,
      18,    0,  120,    2, 0x08,   13 /* Private */,
      19,    1,  121,    2, 0x08,   14 /* Private */,
      22,    2,  124,    2, 0x08,   16 /* Private */,
      26,    2,  129,    2, 0x08,   19 /* Private */,
      29,    0,  134,    2, 0x08,   22 /* Private */,
      30,    0,  135,    2, 0x08,   23 /* Private */,
      31,    0,  136,    2, 0x08,   24 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 23, QMetaType::QByteArray,   24,   25,
    QMetaType::Void, 0x80000000 | 27, QMetaType::QByteArray,   28,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_pushButtonDiscover_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QBluetoothDeviceInfo &, std::false_type>,
        // method 'scanError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QBluetoothDeviceDiscoveryAgent::Error, std::false_type>,
        // method 'scanFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'serviceDiscovered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QBluetoothUuid &, std::false_type>,
        // method 'serviceScanDone'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'controllerError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QLowEnergyController::Error, std::false_type>,
        // method 'deviceConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deviceDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'serviceStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QLowEnergyService::ServiceState, std::false_type>,
        // method 'updateData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QLowEnergyCharacteristic &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'confirmedDescriptorWrite'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QLowEnergyDescriptor &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'on_pushButtonConnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonSend_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonDisconnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButtonDiscover_clicked(); break;
        case 1: _t->addDevice((*reinterpret_cast< std::add_pointer_t<QBluetoothDeviceInfo>>(_a[1]))); break;
        case 2: _t->scanError((*reinterpret_cast< std::add_pointer_t<QBluetoothDeviceDiscoveryAgent::Error>>(_a[1]))); break;
        case 3: _t->scanFinished(); break;
        case 4: _t->serviceDiscovered((*reinterpret_cast< std::add_pointer_t<QBluetoothUuid>>(_a[1]))); break;
        case 5: _t->serviceScanDone(); break;
        case 6: _t->controllerError((*reinterpret_cast< std::add_pointer_t<QLowEnergyController::Error>>(_a[1]))); break;
        case 7: _t->deviceConnected(); break;
        case 8: _t->deviceDisconnected(); break;
        case 9: _t->serviceStateChanged((*reinterpret_cast< std::add_pointer_t<QLowEnergyService::ServiceState>>(_a[1]))); break;
        case 10: _t->updateData((*reinterpret_cast< std::add_pointer_t<QLowEnergyCharacteristic>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 11: _t->confirmedDescriptorWrite((*reinterpret_cast< std::add_pointer_t<QLowEnergyDescriptor>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 12: _t->on_pushButtonConnect_clicked(); break;
        case 13: _t->on_pushButtonSend_clicked(); break;
        case 14: _t->on_pushButtonDisconnect_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QBluetoothUuid >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLowEnergyController::Error >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLowEnergyCharacteristic >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLowEnergyDescriptor >(); break;
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
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
