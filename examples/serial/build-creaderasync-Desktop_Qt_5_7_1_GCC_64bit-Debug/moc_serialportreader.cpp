/****************************************************************************
** Meta object code from reading C++ file 'serialportreader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../creaderasync/serialportreader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialportreader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SerialPortReader_t {
    QByteArrayData data[7];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortReader_t qt_meta_stringdata_SerialPortReader = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SerialPortReader"
QT_MOC_LITERAL(1, 17, 15), // "handleReadyRead"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 13), // "handleTimeout"
QT_MOC_LITERAL(4, 48, 11), // "handleError"
QT_MOC_LITERAL(5, 60, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(6, 89, 5) // "error"

    },
    "SerialPortReader\0handleReadyRead\0\0"
    "handleTimeout\0handleError\0"
    "QSerialPort::SerialPortError\0error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortReader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    1,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void SerialPortReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialPortReader *_t = static_cast<SerialPortReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleReadyRead(); break;
        case 1: _t->handleTimeout(); break;
        case 2: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SerialPortReader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SerialPortReader.data,
      qt_meta_data_SerialPortReader,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SerialPortReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortReader::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPortReader.stringdata0))
        return static_cast<void*>(const_cast< SerialPortReader*>(this));
    return QObject::qt_metacast(_clname);
}

int SerialPortReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
