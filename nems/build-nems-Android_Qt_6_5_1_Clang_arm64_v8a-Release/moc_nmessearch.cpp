/****************************************************************************
** Meta object code from reading C++ file 'nmessearch.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../nems/nmessearch.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nmessearch.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSNMESsearchENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSNMESsearchENDCLASS = QtMocHelpers::stringData(
    "NMESsearch",
    "send",
    "",
    "data",
    "updateSearchText",
    "text",
    "CopyResetMaxEnergy",
    "scanDone",
    "SearchTimeout",
    "ErrorTimeout"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSNMESsearchENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[11];
    char stringdata1[5];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[17];
    char stringdata5[5];
    char stringdata6[19];
    char stringdata7[9];
    char stringdata8[14];
    char stringdata9[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSNMESsearchENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSNMESsearchENDCLASS_t qt_meta_stringdata_CLASSNMESsearchENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "NMESsearch"
        QT_MOC_LITERAL(11, 4),  // "send"
        QT_MOC_LITERAL(16, 0),  // ""
        QT_MOC_LITERAL(17, 4),  // "data"
        QT_MOC_LITERAL(22, 16),  // "updateSearchText"
        QT_MOC_LITERAL(39, 4),  // "text"
        QT_MOC_LITERAL(44, 18),  // "CopyResetMaxEnergy"
        QT_MOC_LITERAL(63, 8),  // "scanDone"
        QT_MOC_LITERAL(72, 13),  // "SearchTimeout"
        QT_MOC_LITERAL(86, 12)   // "ErrorTimeout"
    },
    "NMESsearch",
    "send",
    "",
    "data",
    "updateSearchText",
    "text",
    "CopyResetMaxEnergy",
    "scanDone",
    "SearchTimeout",
    "ErrorTimeout"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSNMESsearchENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       4,    1,   53,    2, 0x06,    3 /* Public */,
       6,    0,   56,    2, 0x06,    5 /* Public */,
       7,    0,   57,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   58,    2, 0x08,    7 /* Private */,
       9,    0,   59,    2, 0x08,    8 /* Private */,

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

Q_CONSTINIT const QMetaObject NMESsearch::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSNMESsearchENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSNMESsearchENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSNMESsearchENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<NMESsearch, std::true_type>,
        // method 'send'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'updateSearchText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'CopyResetMaxEnergy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'scanDone'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SearchTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ErrorTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void NMESsearch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NMESsearch *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->send((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 1: _t->updateSearchText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
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
            if (_t _q_method = &NMESsearch::send; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NMESsearch::*)(QString );
            if (_t _q_method = &NMESsearch::updateSearchText; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NMESsearch::*)();
            if (_t _q_method = &NMESsearch::CopyResetMaxEnergy; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NMESsearch::*)();
            if (_t _q_method = &NMESsearch::scanDone; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *NMESsearch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NMESsearch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSNMESsearchENDCLASS.stringdata0))
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
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
