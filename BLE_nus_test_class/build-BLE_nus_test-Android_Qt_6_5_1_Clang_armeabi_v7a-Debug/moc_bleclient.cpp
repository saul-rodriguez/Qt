/****************************************************************************
** Meta object code from reading C++ file 'bleclient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BLE_nus_test/bleclient.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bleclient.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSBLEClientENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSBLEClientENDCLASS = QtMocHelpers::stringData(
    "BLEClient",
    "deviceFound",
    "",
    "device",
    "rxData",
    "data",
    "BLEupdateStatus",
    "QString&",
    "status",
    "addDevice",
    "QBluetoothDeviceInfo",
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
    "d"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSBLEClientENDCLASS_t {
    uint offsetsAndSizes[68];
    char stringdata0[10];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[7];
    char stringdata5[5];
    char stringdata6[16];
    char stringdata7[9];
    char stringdata8[7];
    char stringdata9[10];
    char stringdata10[21];
    char stringdata11[10];
    char stringdata12[38];
    char stringdata13[6];
    char stringdata14[13];
    char stringdata15[18];
    char stringdata16[15];
    char stringdata17[5];
    char stringdata18[16];
    char stringdata19[16];
    char stringdata20[28];
    char stringdata21[9];
    char stringdata22[16];
    char stringdata23[19];
    char stringdata24[20];
    char stringdata25[32];
    char stringdata26[2];
    char stringdata27[11];
    char stringdata28[25];
    char stringdata29[2];
    char stringdata30[6];
    char stringdata31[25];
    char stringdata32[21];
    char stringdata33[2];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSBLEClientENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSBLEClientENDCLASS_t qt_meta_stringdata_CLASSBLEClientENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "BLEClient"
        QT_MOC_LITERAL(10, 11),  // "deviceFound"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 6),  // "device"
        QT_MOC_LITERAL(30, 6),  // "rxData"
        QT_MOC_LITERAL(37, 4),  // "data"
        QT_MOC_LITERAL(42, 15),  // "BLEupdateStatus"
        QT_MOC_LITERAL(58, 8),  // "QString&"
        QT_MOC_LITERAL(67, 6),  // "status"
        QT_MOC_LITERAL(74, 9),  // "addDevice"
        QT_MOC_LITERAL(84, 20),  // "QBluetoothDeviceInfo"
        QT_MOC_LITERAL(105, 9),  // "scanError"
        QT_MOC_LITERAL(115, 37),  // "QBluetoothDeviceDiscoveryAgen..."
        QT_MOC_LITERAL(153, 5),  // "error"
        QT_MOC_LITERAL(159, 12),  // "scanFinished"
        QT_MOC_LITERAL(172, 17),  // "serviceDiscovered"
        QT_MOC_LITERAL(190, 14),  // "QBluetoothUuid"
        QT_MOC_LITERAL(205, 4),  // "gatt"
        QT_MOC_LITERAL(210, 15),  // "serviceScanDone"
        QT_MOC_LITERAL(226, 15),  // "controllerError"
        QT_MOC_LITERAL(242, 27),  // "QLowEnergyController::Error"
        QT_MOC_LITERAL(270, 8),  // "newError"
        QT_MOC_LITERAL(279, 15),  // "deviceConnected"
        QT_MOC_LITERAL(295, 18),  // "deviceDisconnected"
        QT_MOC_LITERAL(314, 19),  // "serviceStateChanged"
        QT_MOC_LITERAL(334, 31),  // "QLowEnergyService::ServiceState"
        QT_MOC_LITERAL(366, 1),  // "s"
        QT_MOC_LITERAL(368, 10),  // "updateData"
        QT_MOC_LITERAL(379, 24),  // "QLowEnergyCharacteristic"
        QT_MOC_LITERAL(404, 1),  // "c"
        QT_MOC_LITERAL(406, 5),  // "value"
        QT_MOC_LITERAL(412, 24),  // "confirmedDescriptorWrite"
        QT_MOC_LITERAL(437, 20),  // "QLowEnergyDescriptor"
        QT_MOC_LITERAL(458, 1)   // "d"
    },
    "BLEClient",
    "deviceFound",
    "",
    "device",
    "rxData",
    "data",
    "BLEupdateStatus",
    "QString&",
    "status",
    "addDevice",
    "QBluetoothDeviceInfo",
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
    "d"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBLEClientENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x06,    1 /* Public */,
       4,    1,  101,    2, 0x06,    3 /* Public */,
       6,    1,  104,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,  107,    2, 0x08,    7 /* Private */,
      11,    1,  110,    2, 0x08,    9 /* Private */,
      14,    0,  113,    2, 0x08,   11 /* Private */,
      15,    1,  114,    2, 0x08,   12 /* Private */,
      18,    0,  117,    2, 0x08,   14 /* Private */,
      19,    1,  118,    2, 0x08,   15 /* Private */,
      22,    0,  121,    2, 0x08,   17 /* Private */,
      23,    0,  122,    2, 0x08,   18 /* Private */,
      24,    1,  123,    2, 0x08,   19 /* Private */,
      27,    2,  126,    2, 0x08,   21 /* Private */,
      31,    2,  131,    2, 0x08,   24 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,    3,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, 0x80000000 | 28, QMetaType::QByteArray,   29,   30,
    QMetaType::Void, 0x80000000 | 32, QMetaType::QByteArray,   33,   30,

       0        // eod
};

Q_CONSTINIT const QMetaObject BLEClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSBLEClientENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBLEClientENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBLEClientENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BLEClient, std::true_type>,
        // method 'deviceFound'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'rxData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'BLEupdateStatus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString &, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>
    >,
    nullptr
} };

void BLEClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BLEClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->deviceFound((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->rxData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 2: _t->BLEupdateStatus((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1]))); break;
        case 3: _t->addDevice((*reinterpret_cast< std::add_pointer_t<QBluetoothDeviceInfo>>(_a[1]))); break;
        case 4: _t->scanError((*reinterpret_cast< std::add_pointer_t<QBluetoothDeviceDiscoveryAgent::Error>>(_a[1]))); break;
        case 5: _t->scanFinished(); break;
        case 6: _t->serviceDiscovered((*reinterpret_cast< std::add_pointer_t<QBluetoothUuid>>(_a[1]))); break;
        case 7: _t->serviceScanDone(); break;
        case 8: _t->controllerError((*reinterpret_cast< std::add_pointer_t<QLowEnergyController::Error>>(_a[1]))); break;
        case 9: _t->deviceConnected(); break;
        case 10: _t->deviceDisconnected(); break;
        case 11: _t->serviceStateChanged((*reinterpret_cast< std::add_pointer_t<QLowEnergyService::ServiceState>>(_a[1]))); break;
        case 12: _t->updateData((*reinterpret_cast< std::add_pointer_t<QLowEnergyCharacteristic>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 13: _t->confirmedDescriptorWrite((*reinterpret_cast< std::add_pointer_t<QLowEnergyDescriptor>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QBluetoothUuid >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLowEnergyController::Error >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLowEnergyCharacteristic >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLowEnergyDescriptor >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BLEClient::*)(QString );
            if (_t _q_method = &BLEClient::deviceFound; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BLEClient::*)(const QByteArray & );
            if (_t _q_method = &BLEClient::rxData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BLEClient::*)(QString & );
            if (_t _q_method = &BLEClient::BLEupdateStatus; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *BLEClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BLEClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBLEClientENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BLEClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void BLEClient::deviceFound(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BLEClient::rxData(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BLEClient::BLEupdateStatus(QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
