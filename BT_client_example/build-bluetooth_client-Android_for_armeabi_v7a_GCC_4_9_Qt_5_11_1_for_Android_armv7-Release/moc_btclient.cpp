/****************************************************************************
** Meta object code from reading C++ file 'btclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../bluetooth_client/btclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'btclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BTClient_t {
    QByteArrayData data[19];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BTClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BTClient_t qt_meta_stringdata_BTClient = {
    {
QT_MOC_LITERAL(0, 0, 8), // "BTClient"
QT_MOC_LITERAL(1, 9, 21), // "BTnewDeviceDiscovered"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "name"
QT_MOC_LITERAL(4, 37, 20), // "BTnewDeviceConnected"
QT_MOC_LITERAL(5, 58, 8), // "BTrxData"
QT_MOC_LITERAL(6, 67, 4), // "data"
QT_MOC_LITERAL(7, 72, 18), // "BTdeviceDiscovered"
QT_MOC_LITERAL(8, 91, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(9, 112, 6), // "device"
QT_MOC_LITERAL(10, 119, 11), // "BTconnected"
QT_MOC_LITERAL(11, 131, 6), // "BTread"
QT_MOC_LITERAL(12, 138, 11), // "BTrxTimeOut"
QT_MOC_LITERAL(13, 150, 13), // "BTfindDevices"
QT_MOC_LITERAL(14, 164, 9), // "BTconnect"
QT_MOC_LITERAL(15, 174, 12), // "BTstopClient"
QT_MOC_LITERAL(16, 187, 7), // "BTwrite"
QT_MOC_LITERAL(17, 195, 14), // "BTsetRxTimeout"
QT_MOC_LITERAL(18, 210, 7) // "timeout"

    },
    "BTClient\0BTnewDeviceDiscovered\0\0name\0"
    "BTnewDeviceConnected\0BTrxData\0data\0"
    "BTdeviceDiscovered\0QBluetoothDeviceInfo\0"
    "device\0BTconnected\0BTread\0BTrxTimeOut\0"
    "BTfindDevices\0BTconnect\0BTstopClient\0"
    "BTwrite\0BTsetRxTimeout\0timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BTClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       5,    1,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   83,    2, 0x08 /* Private */,
      10,    0,   86,    2, 0x08 /* Private */,
      11,    0,   87,    2, 0x08 /* Private */,
      12,    0,   88,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x0a /* Public */,
      14,    1,   90,    2, 0x0a /* Public */,
      15,    0,   93,    2, 0x0a /* Public */,
      16,    1,   94,    2, 0x0a /* Public */,
      17,    1,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QByteArray,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void BTClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BTClient *_t = static_cast<BTClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->BTnewDeviceDiscovered((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->BTnewDeviceConnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->BTrxData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 3: _t->BTdeviceDiscovered((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 4: _t->BTconnected(); break;
        case 5: _t->BTread(); break;
        case 6: _t->BTrxTimeOut(); break;
        case 7: _t->BTfindDevices(); break;
        case 8: _t->BTconnect((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->BTstopClient(); break;
        case 10: _t->BTwrite((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 11: _t->BTsetRxTimeout((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BTClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BTClient::BTnewDeviceDiscovered)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BTClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BTClient::BTnewDeviceConnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BTClient::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BTClient::BTrxData)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BTClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BTClient.data,
      qt_meta_data_BTClient,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BTClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BTClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BTClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BTClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void BTClient::BTnewDeviceDiscovered(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BTClient::BTnewDeviceConnected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BTClient::BTrxData(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
