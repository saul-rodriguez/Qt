/****************************************************************************
** Meta object code from reading C++ file 'nmessearch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../nems/nmessearch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nmessearch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NMESsearch_t {
    QByteArrayData data[10];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NMESsearch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NMESsearch_t qt_meta_stringdata_NMESsearch = {
    {
QT_MOC_LITERAL(0, 0, 10), // "NMESsearch"
QT_MOC_LITERAL(1, 11, 4), // "send"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 4), // "data"
QT_MOC_LITERAL(4, 22, 16), // "updateSearchText"
QT_MOC_LITERAL(5, 39, 4), // "text"
QT_MOC_LITERAL(6, 44, 18), // "CopyResetMaxEnergy"
QT_MOC_LITERAL(7, 63, 8), // "scanDone"
QT_MOC_LITERAL(8, 72, 13), // "SearchTimeout"
QT_MOC_LITERAL(9, 86, 12) // "ErrorTimeout"

    },
    "NMESsearch\0send\0\0data\0updateSearchText\0"
    "text\0CopyResetMaxEnergy\0scanDone\0"
    "SearchTimeout\0ErrorTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NMESsearch[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    0,   50,    2, 0x06 /* Public */,
       7,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   52,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NMESsearch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NMESsearch *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->updateSearchText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->CopyResetMaxEnergy(); break;
        case 3: _t->scanDone(); break;
        case 4: _t->SearchTimeout(); break;
        case 5: _t->ErrorTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NMESsearch::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NMESsearch::send)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NMESsearch::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NMESsearch::updateSearchText)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NMESsearch::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NMESsearch::CopyResetMaxEnergy)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NMESsearch::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NMESsearch::scanDone)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NMESsearch::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NMESsearch.data,
    qt_meta_data_NMESsearch,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NMESsearch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NMESsearch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NMESsearch.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NMESsearch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void NMESsearch::send(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NMESsearch::updateSearchText(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NMESsearch::CopyResetMaxEnergy()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void NMESsearch::scanDone()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
