/****************************************************************************
** Meta object code from reading C++ file 'mainpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainpage_t {
    QByteArrayData data[8];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainpage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainpage_t qt_meta_stringdata_mainpage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "mainpage"
QT_MOC_LITERAL(1, 9, 24), // "on_refreshButton_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 19), // "userOnlineInfoSlots"
QT_MOC_LITERAL(4, 55, 4), // "json"
QT_MOC_LITERAL(5, 60, 25), // "on_uploadADButton_clicked"
QT_MOC_LITERAL(6, 86, 20), // "allowToSendFileSlots"
QT_MOC_LITERAL(7, 107, 19) // "finishSendFileSlots"

    },
    "mainpage\0on_refreshButton_clicked\0\0"
    "userOnlineInfoSlots\0json\0"
    "on_uploadADButton_clicked\0"
    "allowToSendFileSlots\0finishSendFileSlots"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainpage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    1,   40,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mainpage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mainpage *_t = static_cast<mainpage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_refreshButton_clicked(); break;
        case 1: _t->userOnlineInfoSlots((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 2: _t->on_uploadADButton_clicked(); break;
        case 3: _t->allowToSendFileSlots(); break;
        case 4: _t->finishSendFileSlots(); break;
        default: ;
        }
    }
}

const QMetaObject mainpage::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_mainpage.data,
      qt_meta_data_mainpage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *mainpage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainpage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainpage.stringdata0))
        return static_cast<void*>(const_cast< mainpage*>(this));
    return QDialog::qt_metacast(_clname);
}

int mainpage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
