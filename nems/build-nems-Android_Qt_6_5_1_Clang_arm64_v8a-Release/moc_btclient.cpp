/****************************************************************************
** Meta object code from reading C++ file 'btclient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nems/btclient.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'btclient.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSBTClientENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSBTClientENDCLASS = QtMocHelpers::stringData(
    "BTClient",
    "BTnewDeviceDiscovered",
    "",
    "name",
    "BTnewDeviceConnected",
    "BTrxData",
    "data",
    "BTdeviceDiscovered",
    "QBluetoothDeviceInfo",
    "device",
    "BTconnected",
    "BTread",
    "BTrxTimeOut"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSBTClientENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[9];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[21];
    char stringdata5[9];
    char stringdata6[5];
    char stringdata7[19];
    char stringdata8[21];
    char stringdata9[7];
    char stringdata10[12];
    char stringdata11[7];
    char stringdata12[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSBTClientENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSBTClientENDCLASS_t qt_meta_stringdata_CLASSBTClientENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "BTClient"
        QT_MOC_LITERAL(9, 21),  // "BTnewDeviceDiscovered"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 4),  // "name"
        QT_MOC_LITERAL(37, 20),  // "BTnewDeviceConnected"
        QT_MOC_LITERAL(58, 8),  // "BTrxData"
        QT_MOC_LITERAL(67, 4),  // "data"
        QT_MOC_LITERAL(72, 18),  // "BTdeviceDiscovered"
        QT_MOC_LITERAL(91, 20),  // "QBluetoothDeviceInfo"
        QT_MOC_LITERAL(112, 6),  // "device"
        QT_MOC_LITERAL(119, 11),  // "BTconnected"
        QT_MOC_LITERAL(131, 6),  // "BTread"
        QT_MOC_LITERAL(138, 11)   // "BTrxTimeOut"
    },
    "BTClient",
    "BTnewDeviceDiscovered",
    "",
    "name",
    "BTnewDeviceConnected",
    "BTrxData",
    "data",
    "BTdeviceDiscovered",
    "QBluetoothDeviceInfo",
    "device",
    "BTconnected",
    "BTread",
    "BTrxTimeOut"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBTClientENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       4,    1,   59,    2, 0x06,    3 /* Public */,
       5,    1,   62,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,   65,    2, 0x08,    7 /* Private */,
      10,    0,   68,    2, 0x08,    9 /* Private */,
      11,    0,   69,    2, 0x08,   10 /* Private */,
      12,    0,   70,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QByteArray,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject BTClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSBTClientENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBTClientENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBTClientENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BTClient, std::true_type>,
        // method 'BTnewDeviceDiscovered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'BTnewDeviceConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'BTrxData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'BTdeviceDiscovered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QBluetoothDeviceInfo &, std::false_type>,
        // method 'BTconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'BTread'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'BTrxTimeOut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void BTClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BTClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->BTnewDeviceDiscovered((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->BTnewDeviceConnected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->BTrxData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 3: _t->BTdeviceDiscovered((*reinterpret_cast< std::add_pointer_t<QBluetoothDeviceInfo>>(_a[1]))); break;
        case 4: _t->BTconnected(); break;
        case 5: _t->BTread(); break;
        case 6: _t->BTrxTimeOut(); break;
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
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BTClient::*)(QString );
            if (_t _q_method = &BTClient::BTnewDeviceDiscovered; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BTClient::*)(QString );
            if (_t _q_method = &BTClient::BTnewDeviceConnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BTClient::*)(const QByteArray & );
            if (_t _q_method = &BTClient::BTrxData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *BTClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BTClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBTClientENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BTClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void BTClient::BTnewDeviceDiscovered(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BTClient::BTnewDeviceConnected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BTClient::BTrxData(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
