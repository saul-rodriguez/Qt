/****************************************************************************
** Meta object code from reading C++ file 'devicefinder.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../heartrate-game/devicefinder.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devicefinder.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_DeviceFinder_t {
    uint offsetsAndSizes[34];
    char stringdata0[13];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[16];
    char stringdata4[1];
    char stringdata5[15];
    char stringdata6[12];
    char stringdata7[17];
    char stringdata8[8];
    char stringdata9[10];
    char stringdata10[21];
    char stringdata11[10];
    char stringdata12[38];
    char stringdata13[6];
    char stringdata14[13];
    char stringdata15[9];
    char stringdata16[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_DeviceFinder_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_DeviceFinder_t qt_meta_stringdata_DeviceFinder = {
    {
        QT_MOC_LITERAL(0, 12),  // "DeviceFinder"
        QT_MOC_LITERAL(13, 11),  // "QML.Element"
        QT_MOC_LITERAL(25, 4),  // "auto"
        QT_MOC_LITERAL(30, 15),  // "scanningChanged"
        QT_MOC_LITERAL(46, 0),  // ""
        QT_MOC_LITERAL(47, 14),  // "devicesChanged"
        QT_MOC_LITERAL(62, 11),  // "startSearch"
        QT_MOC_LITERAL(74, 16),  // "connectToService"
        QT_MOC_LITERAL(91, 7),  // "address"
        QT_MOC_LITERAL(99, 9),  // "addDevice"
        QT_MOC_LITERAL(109, 20),  // "QBluetoothDeviceInfo"
        QT_MOC_LITERAL(130, 9),  // "scanError"
        QT_MOC_LITERAL(140, 37),  // "QBluetoothDeviceDiscoveryAgen..."
        QT_MOC_LITERAL(178, 5),  // "error"
        QT_MOC_LITERAL(184, 12),  // "scanFinished"
        QT_MOC_LITERAL(197, 8),  // "scanning"
        QT_MOC_LITERAL(206, 7)   // "devices"
    },
    "DeviceFinder",
    "QML.Element",
    "auto",
    "scanningChanged",
    "",
    "devicesChanged",
    "startSearch",
    "connectToService",
    "address",
    "addDevice",
    "QBluetoothDeviceInfo",
    "scanError",
    "QBluetoothDeviceDiscoveryAgent::Error",
    "error",
    "scanFinished",
    "scanning",
    "devices"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_DeviceFinder[] = {

 // content:
      10,       // revision
       0,       // classname
       1,   14, // classinfo
       7,   16, // methods
       2,   71, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   58,    4, 0x06,    3 /* Public */,
       5,    0,   59,    4, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   60,    4, 0x0a,    5 /* Public */,
       7,    1,   61,    4, 0x0a,    6 /* Public */,
       9,    1,   64,    4, 0x08,    8 /* Private */,
      11,    1,   67,    4, 0x08,   10 /* Private */,
      14,    0,   70,    4, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, 0x80000000 | 10,    4,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

 // properties: name, type, flags
      15, QMetaType::Bool, 0x00015001, uint(0), 0,
      16, QMetaType::QVariant, 0x00015001, uint(1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject DeviceFinder::staticMetaObject = { {
    QMetaObject::SuperData::link<BluetoothBaseClass::staticMetaObject>(),
    qt_meta_stringdata_DeviceFinder.offsetsAndSizes,
    qt_meta_data_DeviceFinder,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'scanning'
        bool,
        // property 'devices'
        QVariant,
        // Q_OBJECT / Q_GADGET
        DeviceFinder,
        // method 'scanningChanged'
        void,
        // method 'devicesChanged'
        void,
        // method 'startSearch'
        void,
        // method 'connectToService'
        void,
        const QString &,
        // method 'addDevice'
        void,
        const QBluetoothDeviceInfo &,
        // method 'scanError'
        void,
        QBluetoothDeviceDiscoveryAgent::Error,
        // method 'scanFinished'
        void
    >,
    nullptr
} };

void DeviceFinder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeviceFinder *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->scanningChanged(); break;
        case 1: _t->devicesChanged(); break;
        case 2: _t->startSearch(); break;
        case 3: _t->connectToService((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->addDevice((*reinterpret_cast< std::add_pointer_t<QBluetoothDeviceInfo>>(_a[1]))); break;
        case 5: _t->scanError((*reinterpret_cast< std::add_pointer_t<QBluetoothDeviceDiscoveryAgent::Error>>(_a[1]))); break;
        case 6: _t->scanFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
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
            using _t = void (DeviceFinder::*)();
            if (_t _q_method = &DeviceFinder::scanningChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DeviceFinder::*)();
            if (_t _q_method = &DeviceFinder::devicesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DeviceFinder *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->scanning(); break;
        case 1: *reinterpret_cast< QVariant*>(_v) = _t->devices(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *DeviceFinder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceFinder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceFinder.stringdata0))
        return static_cast<void*>(this);
    return BluetoothBaseClass::qt_metacast(_clname);
}

int DeviceFinder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BluetoothBaseClass::qt_metacall(_c, _id, _a);
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
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DeviceFinder::scanningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DeviceFinder::devicesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
