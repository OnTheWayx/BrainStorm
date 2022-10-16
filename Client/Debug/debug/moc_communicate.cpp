/****************************************************************************
** Meta object code from reading C++ file 'communicate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../communicate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'communicate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Communicate_t {
    QByteArrayData data[18];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Communicate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Communicate_t qt_meta_stringdata_Communicate = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Communicate"
QT_MOC_LITERAL(1, 12, 9), // "rstResult"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "json"
QT_MOC_LITERAL(4, 28, 11), // "loginResult"
QT_MOC_LITERAL(5, 40, 17), // "singleGetQuestion"
QT_MOC_LITERAL(6, 58, 4), // "rank"
QT_MOC_LITERAL(7, 63, 10), // "recvAnswer"
QT_MOC_LITERAL(8, 74, 13), // "setRankResult"
QT_MOC_LITERAL(9, 88, 15), // "DownloadADError"
QT_MOC_LITERAL(10, 104, 17), // "DownloadADSuccess"
QT_MOC_LITERAL(11, 122, 12), // "recvRankSort"
QT_MOC_LITERAL(12, 135, 10), // "ExitClient"
QT_MOC_LITERAL(13, 146, 10), // "bufferData"
QT_MOC_LITERAL(14, 157, 8), // "readData"
QT_MOC_LITERAL(15, 166, 16), // "readDataFromFile"
QT_MOC_LITERAL(16, 183, 4), // "Exit"
QT_MOC_LITERAL(17, 188, 13) // "sendHeartBeat"

    },
    "Communicate\0rstResult\0\0json\0loginResult\0"
    "singleGetQuestion\0rank\0recvAnswer\0"
    "setRankResult\0DownloadADError\0"
    "DownloadADSuccess\0recvRankSort\0"
    "ExitClient\0bufferData\0readData\0"
    "readDataFromFile\0Exit\0sendHeartBeat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Communicate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       5,    1,   95,    2, 0x06 /* Public */,
       6,    1,   98,    2, 0x06 /* Public */,
       7,    1,  101,    2, 0x06 /* Public */,
       8,    1,  104,    2, 0x06 /* Public */,
       9,    0,  107,    2, 0x06 /* Public */,
      10,    0,  108,    2, 0x06 /* Public */,
      11,    1,  109,    2, 0x06 /* Public */,
      12,    0,  112,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  113,    2, 0x0a /* Public */,
      14,    0,  114,    2, 0x0a /* Public */,
      15,    0,  115,    2, 0x0a /* Public */,
      16,    0,  116,    2, 0x0a /* Public */,
      17,    0,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Communicate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Communicate *_t = static_cast<Communicate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rstResult((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 1: _t->loginResult((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 2: _t->singleGetQuestion((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 3: _t->rank((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 4: _t->recvAnswer((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 5: _t->setRankResult((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 6: _t->DownloadADError(); break;
        case 7: _t->DownloadADSuccess(); break;
        case 8: _t->recvRankSort((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 9: _t->ExitClient(); break;
        case 10: _t->bufferData(); break;
        case 11: _t->readData(); break;
        case 12: _t->readDataFromFile(); break;
        case 13: _t->Exit(); break;
        case 14: _t->sendHeartBeat(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Communicate::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communicate::rstResult)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Communicate::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communicate::loginResult)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Communicate::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communicate::singleGetQuestion)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Communicate::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communicate::rank)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Communicate::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communicate::recvAnswer)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Communicate::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communicate::setRankResult)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Communicate::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communicate::DownloadADError)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Communicate::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communicate::DownloadADSuccess)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Communicate::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communicate::recvRankSort)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (Communicate::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Communicate::ExitClient)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject Communicate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Communicate.data,
      qt_meta_data_Communicate,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Communicate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Communicate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Communicate.stringdata0))
        return static_cast<void*>(const_cast< Communicate*>(this));
    return QObject::qt_metacast(_clname);
}

int Communicate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Communicate::rstResult(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Communicate::loginResult(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Communicate::singleGetQuestion(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Communicate::rank(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Communicate::recvAnswer(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Communicate::setRankResult(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Communicate::DownloadADError()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Communicate::DownloadADSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Communicate::recvRankSort(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Communicate::ExitClient()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
