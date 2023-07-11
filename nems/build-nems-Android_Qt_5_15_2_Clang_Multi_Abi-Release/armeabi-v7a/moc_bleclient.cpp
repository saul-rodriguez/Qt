/****************************************************************************
** Meta object code from reading C++ file 'bleclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../nems/bleclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bleclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BLEClient_t {
    QByteArrayData data[34];
    char stringdata0[460];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BLEClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BLEClient_t qt_meta_stringdata_BLEClient = {
    {
QT_MOC_LITERAL(0, 0, 9), // "BLEClient"
QT_MOC_LITERAL(1, 10, 11), // "deviceFound"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "device"
QT_MOC_LITERAL(4, 30, 6), // "rxData"
QT_MOC_LITERAL(5, 37, 4), // "data"
QT_MOC_LITERAL(6, 42, 15), // "BLEupdateStatus"
QT_MOC_LITERAL(7, 58, 8), // "QString&"
QT_MOC_LITERAL(8, 67, 6), // "status"
QT_MOC_LITERAL(9, 74, 9), // "addDevice"
QT_MOC_LITERAL(10, 84, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(11, 105, 9), // "scanError"
QT_MOC_LITERAL(12, 115, 37), // "QBluetoothDeviceDiscoveryAgen..."
QT_MOC_LITERAL(13, 153, 5), // "error"
QT_MOC_LITERAL(14, 159, 12), // "scanFinished"
QT_MOC_LITERAL(15, 172, 17), // "serviceDiscovered"
QT_MOC_LITERAL(16, 190, 14), // "QBluetoothUuid"
QT_MOC_LITERAL(17, 205, 4), // "gatt"
QT_MOC_LITERAL(18, 210, 15), // "serviceScanDone"
QT_MOC_LITERAL(19, 226, 15), // "controllerError"
QT_MOC_LITERAL(20, 242, 27), // "QLowEnergyController::Error"
QT_MOC_LITERAL(21, 270, 8), // "newError"
QT_MOC_LITERAL(22, 279, 15), // "deviceConnected"
QT_MOC_LITERAL(23, 295, 18), // "deviceDisconnected"
QT_MOC_LITERAL(24, 314, 19), // "serviceStateChanged"
QT_MOC_LITERAL(25, 334, 31), // "QLowEnergyService::ServiceState"
QT_MOC_LITERAL(26, 366, 1), // "s"
QT_MOC_LITERAL(27, 368, 10), // "updateData"
QT_MOC_LITERAL(28, 379, 24), // "QLowEnergyCharacteristic"
QT_MOC_LITERAL(29, 404, 1), // "c"
QT_MOC_LITERAL(30, 406, 5), // "value"
QT_MOC_LITERAL(31, 412, 24), // "confirmedDescriptorWrite"
QT_MOC_LITERAL(32, 437, 20), // "QLowEnergyDescriptor"
QT_MOC_LITERAL(33, 458, 1) // "d"

    },
    "BLEClient\0deviceFound\0\0device\0rxData\0"
    "data\0BLEupdateStatus\0QString&\0status\0"
    "addDevice\0QBluetoothDeviceInfo\0scanError\0"
    "QBluetoothDeviceDiscoveryAgent::Error\0"
    "error\0scanFinished\0serviceDiscovered\0"
    "QBluetoothUuid\0gatt\0serviceScanDone\0"
    "controllerError\0QLowEnergyController::Error\0"
    "newError\0deviceConnected\0deviceDisconnected\0"
    "serviceStateChanged\0QLowEnergyService::ServiceState\0"
    "s\0updateData\0QLowEnergyCharacteristic\0"
    "c\0value\0confirmedDescriptorWrite\0"
    "QLowEnergyDescriptor\0d"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BLEClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       6,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   93,    2, 0x08 /* Private */,
      11,    1,   96,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    1,  100,    2, 0x08 /* Private */,
      18,    0,  103,    2, 0x08 /* Private */,
      19,    1,  104,    2, 0x08 /* Private */,
      22,    0,  107,    2, 0x08 /* Private */,
      23,    0,  108,    2, 0x08 /* Private */,
      24,    1,  109,    2, 0x08 /* Private */,
      27,    2,  112,    2, 0x08 /* Private */,
      31,    2,  117,    2, 0x08 /* Private */,

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

void BLEClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BLEClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deviceFound((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->rxData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 2: _t->BLEupdateStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->addDevice((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 4: _t->scanError((*reinterpret_cast< QBluetoothDeviceDiscoveryAgent::Error(*)>(_a[1]))); break;
        case 5: _t->scanFinished(); break;
        case 6: _t->serviceDiscovered((*reinterpret_cast< const QBluetoothUuid(*)>(_a[1]))); break;
        case 7: _t->serviceScanDone(); break;
        case 8: _t->controllerError((*reinterpret_cast< QLowEnergyController::Error(*)>(_a[1]))); break;
        case 9: _t->deviceConnected(); break;
        case 10: _t->deviceDisconnected(); break;
        case 11: _t->serviceStateChanged((*reinterpret_cast< QLowEnergyService::ServiceState(*)>(_a[1]))); break;
        case 12: _t->updateData((*reinterpret_cast< const QLowEnergyCharacteristic(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 13: _t->confirmedDescriptorWrite((*reinterpret_cast< const QLowEnergyDescriptor(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothUuid >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyController::Error >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyCharacteristic >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyDescriptor >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BLEClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BLEClient::deviceFound)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BLEClient::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BLEClient::rxData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BLEClient::*)(QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BLEClient::BLEupdateStatus)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BLEClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_BLEClient.data,
    qt_meta_data_BLEClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BLEClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BLEClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BLEClient.stringdata0))
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
QT_END_MOC_NAMESPACE
