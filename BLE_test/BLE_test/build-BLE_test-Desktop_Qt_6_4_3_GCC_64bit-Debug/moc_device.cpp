/****************************************************************************
** Meta object code from reading C++ file 'device.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../BLE_test/device.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'device.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_Device_t {
    uint offsetsAndSizes[74];
    char stringdata0[7];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[23];
    char stringdata5[14];
    char stringdata6[13];
    char stringdata7[13];
    char stringdata8[21];
    char stringdata9[21];
    char stringdata10[13];
    char stringdata11[8];
    char stringdata12[17];
    char stringdata13[5];
    char stringdata14[21];
    char stringdata15[10];
    char stringdata16[21];
    char stringdata17[19];
    char stringdata18[16];
    char stringdata19[38];
    char stringdata20[20];
    char stringdata21[15];
    char stringdata22[16];
    char stringdata23[14];
    char stringdata24[28];
    char stringdata25[16];
    char stringdata26[19];
    char stringdata27[25];
    char stringdata28[32];
    char stringdata29[9];
    char stringdata30[12];
    char stringdata31[13];
    char stringdata32[19];
    char stringdata33[7];
    char stringdata34[17];
    char stringdata35[6];
    char stringdata36[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Device_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Device_t qt_meta_stringdata_Device = {
    {
        QT_MOC_LITERAL(0, 6),  // "Device"
        QT_MOC_LITERAL(7, 14),  // "devicesUpdated"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 15),  // "servicesUpdated"
        QT_MOC_LITERAL(39, 22),  // "characteristicsUpdated"
        QT_MOC_LITERAL(62, 13),  // "updateChanged"
        QT_MOC_LITERAL(76, 12),  // "stateChanged"
        QT_MOC_LITERAL(89, 12),  // "disconnected"
        QT_MOC_LITERAL(102, 20),  // "randomAddressChanged"
        QT_MOC_LITERAL(123, 20),  // "startDeviceDiscovery"
        QT_MOC_LITERAL(144, 12),  // "scanServices"
        QT_MOC_LITERAL(157, 7),  // "address"
        QT_MOC_LITERAL(165, 16),  // "connectToService"
        QT_MOC_LITERAL(182, 4),  // "uuid"
        QT_MOC_LITERAL(187, 20),  // "disconnectFromDevice"
        QT_MOC_LITERAL(208, 9),  // "addDevice"
        QT_MOC_LITERAL(218, 20),  // "QBluetoothDeviceInfo"
        QT_MOC_LITERAL(239, 18),  // "deviceScanFinished"
        QT_MOC_LITERAL(258, 15),  // "deviceScanError"
        QT_MOC_LITERAL(274, 37),  // "QBluetoothDeviceDiscoveryAgen..."
        QT_MOC_LITERAL(312, 19),  // "addLowEnergyService"
        QT_MOC_LITERAL(332, 14),  // "QBluetoothUuid"
        QT_MOC_LITERAL(347, 15),  // "deviceConnected"
        QT_MOC_LITERAL(363, 13),  // "errorReceived"
        QT_MOC_LITERAL(377, 27),  // "QLowEnergyController::Error"
        QT_MOC_LITERAL(405, 15),  // "serviceScanDone"
        QT_MOC_LITERAL(421, 18),  // "deviceDisconnected"
        QT_MOC_LITERAL(440, 24),  // "serviceDetailsDiscovered"
        QT_MOC_LITERAL(465, 31),  // "QLowEnergyService::ServiceState"
        QT_MOC_LITERAL(497, 8),  // "newState"
        QT_MOC_LITERAL(506, 11),  // "devicesList"
        QT_MOC_LITERAL(518, 12),  // "servicesList"
        QT_MOC_LITERAL(531, 18),  // "characteristicList"
        QT_MOC_LITERAL(550, 6),  // "update"
        QT_MOC_LITERAL(557, 16),  // "useRandomAddress"
        QT_MOC_LITERAL(574, 5),  // "state"
        QT_MOC_LITERAL(580, 15)   // "controllerError"
    },
    "Device",
    "devicesUpdated",
    "",
    "servicesUpdated",
    "characteristicsUpdated",
    "updateChanged",
    "stateChanged",
    "disconnected",
    "randomAddressChanged",
    "startDeviceDiscovery",
    "scanServices",
    "address",
    "connectToService",
    "uuid",
    "disconnectFromDevice",
    "addDevice",
    "QBluetoothDeviceInfo",
    "deviceScanFinished",
    "deviceScanError",
    "QBluetoothDeviceDiscoveryAgent::Error",
    "addLowEnergyService",
    "QBluetoothUuid",
    "deviceConnected",
    "errorReceived",
    "QLowEnergyController::Error",
    "serviceScanDone",
    "deviceDisconnected",
    "serviceDetailsDiscovered",
    "QLowEnergyService::ServiceState",
    "newState",
    "devicesList",
    "servicesList",
    "characteristicList",
    "update",
    "useRandomAddress",
    "state",
    "controllerError"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Device[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       7,  168, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  134,    2, 0x06,    8 /* Public */,
       3,    0,  135,    2, 0x06,    9 /* Public */,
       4,    0,  136,    2, 0x06,   10 /* Public */,
       5,    0,  137,    2, 0x06,   11 /* Public */,
       6,    0,  138,    2, 0x06,   12 /* Public */,
       7,    0,  139,    2, 0x06,   13 /* Public */,
       8,    0,  140,    2, 0x06,   14 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,  141,    2, 0x0a,   15 /* Public */,
      10,    1,  142,    2, 0x0a,   16 /* Public */,
      12,    1,  145,    2, 0x0a,   18 /* Public */,
      14,    0,  148,    2, 0x0a,   20 /* Public */,
      15,    1,  149,    2, 0x08,   21 /* Private */,
      17,    0,  152,    2, 0x08,   23 /* Private */,
      18,    1,  153,    2, 0x08,   24 /* Private */,
      20,    1,  156,    2, 0x08,   26 /* Private */,
      22,    0,  159,    2, 0x08,   28 /* Private */,
      23,    1,  160,    2, 0x08,   29 /* Private */,
      25,    0,  163,    2, 0x08,   31 /* Private */,
      26,    0,  164,    2, 0x08,   32 /* Private */,
      27,    1,  165,    2, 0x08,   33 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void, 0x80000000 | 21,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 28,   29,

 // properties: name, type, flags
      30, QMetaType::QVariant, 0x00015001, uint(0), 0,
      31, QMetaType::QVariant, 0x00015001, uint(1), 0,
      32, QMetaType::QVariant, 0x00015001, uint(2), 0,
      33, QMetaType::QString, 0x00015103, uint(3), 0,
      34, QMetaType::Bool, 0x00015003, uint(6), 0,
      35, QMetaType::Bool, 0x00015001, uint(4), 0,
      36, QMetaType::Bool, 0x00015001, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Device::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Device.offsetsAndSizes,
    qt_meta_data_Device,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Device_t,
        // property 'devicesList'
        QtPrivate::TypeAndForceComplete<QVariant, std::true_type>,
        // property 'servicesList'
        QtPrivate::TypeAndForceComplete<QVariant, std::true_type>,
        // property 'characteristicList'
        QtPrivate::TypeAndForceComplete<QVariant, std::true_type>,
        // property 'update'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'useRandomAddress'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'state'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'controllerError'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Device, std::true_type>,
        // method 'devicesUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'servicesUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'characteristicsUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'disconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'randomAddressChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startDeviceDiscovery'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'scanServices'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'connectToService'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'disconnectFromDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addDevice'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QBluetoothDeviceInfo &, std::false_type>,
        // method 'deviceScanFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deviceScanError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QBluetoothDeviceDiscoveryAgent::Error, std::false_type>,
        // method 'addLowEnergyService'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QBluetoothUuid &, std::false_type>,
        // method 'deviceConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'errorReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QLowEnergyController::Error, std::false_type>,
        // method 'serviceScanDone'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deviceDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'serviceDetailsDiscovered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QLowEnergyService::ServiceState, std::false_type>
    >,
    nullptr
} };

void Device::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Device *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->devicesUpdated(); break;
        case 1: _t->servicesUpdated(); break;
        case 2: _t->characteristicsUpdated(); break;
        case 3: _t->updateChanged(); break;
        case 4: _t->stateChanged(); break;
        case 5: _t->disconnected(); break;
        case 6: _t->randomAddressChanged(); break;
        case 7: _t->startDeviceDiscovery(); break;
        case 8: _t->scanServices((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->connectToService((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->disconnectFromDevice(); break;
        case 11: _t->addDevice((*reinterpret_cast< std::add_pointer_t<QBluetoothDeviceInfo>>(_a[1]))); break;
        case 12: _t->deviceScanFinished(); break;
        case 13: _t->deviceScanError((*reinterpret_cast< std::add_pointer_t<QBluetoothDeviceDiscoveryAgent::Error>>(_a[1]))); break;
        case 14: _t->addLowEnergyService((*reinterpret_cast< std::add_pointer_t<QBluetoothUuid>>(_a[1]))); break;
        case 15: _t->deviceConnected(); break;
        case 16: _t->errorReceived((*reinterpret_cast< std::add_pointer_t<QLowEnergyController::Error>>(_a[1]))); break;
        case 17: _t->serviceScanDone(); break;
        case 18: _t->deviceDisconnected(); break;
        case 19: _t->serviceDetailsDiscovered((*reinterpret_cast< std::add_pointer_t<QLowEnergyService::ServiceState>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QBluetoothUuid >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLowEnergyController::Error >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Device::*)();
            if (_t _q_method = &Device::devicesUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (_t _q_method = &Device::servicesUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (_t _q_method = &Device::characteristicsUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (_t _q_method = &Device::updateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (_t _q_method = &Device::stateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (_t _q_method = &Device::disconnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (_t _q_method = &Device::randomAddressChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Device *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariant*>(_v) = _t->getDevices(); break;
        case 1: *reinterpret_cast< QVariant*>(_v) = _t->getServices(); break;
        case 2: *reinterpret_cast< QVariant*>(_v) = _t->getCharacteristics(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getUpdate(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->isRandomAddress(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->state(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->hasControllerError(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Device *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 3: _t->setUpdate(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setRandomAddress(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Device::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Device::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Device.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Device::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Device::devicesUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Device::servicesUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Device::characteristicsUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Device::updateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Device::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Device::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Device::randomAddressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
