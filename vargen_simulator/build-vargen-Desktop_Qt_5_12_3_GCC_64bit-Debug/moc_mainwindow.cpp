/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../vargen/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[355];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "clkTimeout"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 9), // "openCfile"
QT_MOC_LITERAL(4, 33, 8), // "filename"
QT_MOC_LITERAL(5, 42, 11), // "openAsmFile"
QT_MOC_LITERAL(6, 54, 11), // "openHexFile"
QT_MOC_LITERAL(7, 66, 12), // "setArguments"
QT_MOC_LITERAL(8, 79, 4), // "argc"
QT_MOC_LITERAL(9, 84, 7), // "char*[]"
QT_MOC_LITERAL(10, 92, 4), // "argv"
QT_MOC_LITERAL(11, 97, 22), // "on_action_Go_triggered"
QT_MOC_LITERAL(12, 120, 25), // "on_action_Reset_triggered"
QT_MOC_LITERAL(13, 146, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(14, 170, 28), // "on_action_Clk_step_triggered"
QT_MOC_LITERAL(15, 199, 29), // "on_action_Next_inst_triggered"
QT_MOC_LITERAL(16, 229, 24), // "on_action_Stop_triggered"
QT_MOC_LITERAL(17, 254, 32), // "on_actionOpen_C_source_triggered"
QT_MOC_LITERAL(18, 287, 27), // "on_actionOpen_Hex_triggered"
QT_MOC_LITERAL(19, 315, 39) // "on_action_Clear_Color_Markers..."

    },
    "MainWindow\0clkTimeout\0\0openCfile\0"
    "filename\0openAsmFile\0openHexFile\0"
    "setArguments\0argc\0char*[]\0argv\0"
    "on_action_Go_triggered\0on_action_Reset_triggered\0"
    "on_actionOpen_triggered\0"
    "on_action_Clk_step_triggered\0"
    "on_action_Next_inst_triggered\0"
    "on_action_Stop_triggered\0"
    "on_actionOpen_C_source_triggered\0"
    "on_actionOpen_Hex_triggered\0"
    "on_action_Clear_Color_Markers_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    1,   85,    2, 0x0a /* Public */,
       5,    1,   88,    2, 0x0a /* Public */,
       6,    1,   91,    2, 0x0a /* Public */,
       7,    2,   94,    2, 0x0a /* Public */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,
      18,    0,  106,    2, 0x08 /* Private */,
      19,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 9,    8,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clkTimeout(); break;
        case 1: _t->openCfile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->openAsmFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->openHexFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setArguments((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char*(*)[]>(_a[2]))); break;
        case 5: _t->on_action_Go_triggered(); break;
        case 6: _t->on_action_Reset_triggered(); break;
        case 7: _t->on_actionOpen_triggered(); break;
        case 8: _t->on_action_Clk_step_triggered(); break;
        case 9: _t->on_action_Next_inst_triggered(); break;
        case 10: _t->on_action_Stop_triggered(); break;
        case 11: _t->on_actionOpen_C_source_triggered(); break;
        case 12: _t->on_actionOpen_Hex_triggered(); break;
        case 13: _t->on_action_Clear_Color_Markers_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
