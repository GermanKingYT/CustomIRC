/****************************************************************************
** Meta object code from reading C++ file 'ircclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../customIrcServer/ircclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ircclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ircClient_t {
    QByteArrayData data[21];
    char stringdata[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ircClient_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ircClient_t qt_meta_stringdata_ircClient = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 15),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 12),
QT_MOC_LITERAL(4, 40, 7),
QT_MOC_LITERAL(5, 48, 13),
QT_MOC_LITERAL(6, 62, 4),
QT_MOC_LITERAL(7, 67, 7),
QT_MOC_LITERAL(8, 75, 10),
QT_MOC_LITERAL(9, 86, 8),
QT_MOC_LITERAL(10, 95, 2),
QT_MOC_LITERAL(11, 98, 11),
QT_MOC_LITERAL(12, 110, 14),
QT_MOC_LITERAL(13, 125, 11),
QT_MOC_LITERAL(14, 137, 11),
QT_MOC_LITERAL(15, 149, 16),
QT_MOC_LITERAL(16, 166, 7),
QT_MOC_LITERAL(17, 174, 7),
QT_MOC_LITERAL(18, 182, 12),
QT_MOC_LITERAL(19, 195, 9),
QT_MOC_LITERAL(20, 205, 8)
    },
    "ircClient\0startupComplete\0\0chatReceived\0"
    "channel\0nickAndStatus\0user\0message\0"
    "userOnline\0nickName\0id\0userOffline\0"
    "userChangeNick\0oldNickName\0newNickName\0"
    "userChangeStatus\0oldNick\0newNick\0"
    "disconnected\0connected\0readData\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ircClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x05,
       3,    3,   60,    2, 0x05,
       8,    3,   67,    2, 0x05,
      11,    3,   74,    2, 0x05,
      12,    3,   81,    2, 0x05,
      15,    3,   88,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      18,    0,   95,    2, 0x0a,
      19,    0,   96,    2, 0x0a,
      20,    0,   97,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, QMetaType::QString,    4,    6,    7,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString, QMetaType::QString,    9,   10,    4,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString, QMetaType::QString,    9,   10,    4,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, QMetaType::QString,   13,   14,   10,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5, QMetaType::QString,   16,   17,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ircClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ircClient *_t = static_cast<ircClient *>(_o);
        switch (_id) {
        case 0: _t->startupComplete(); break;
        case 1: _t->chatReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const nickAndStatus(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->userOnline((*reinterpret_cast< const nickAndStatus(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->userOffline((*reinterpret_cast< const nickAndStatus(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->userChangeNick((*reinterpret_cast< const nickAndStatus(*)>(_a[1])),(*reinterpret_cast< const nickAndStatus(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 5: _t->userChangeStatus((*reinterpret_cast< const nickAndStatus(*)>(_a[1])),(*reinterpret_cast< const nickAndStatus(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 6: _t->disconnected(); break;
        case 7: _t->connected(); break;
        case 8: _t->readData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ircClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ircClient::startupComplete)) {
                *result = 0;
            }
        }
        {
            typedef void (ircClient::*_t)(const QString , const nickAndStatus , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ircClient::chatReceived)) {
                *result = 1;
            }
        }
        {
            typedef void (ircClient::*_t)(const nickAndStatus , const QString , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ircClient::userOnline)) {
                *result = 2;
            }
        }
        {
            typedef void (ircClient::*_t)(const nickAndStatus , const QString , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ircClient::userOffline)) {
                *result = 3;
            }
        }
        {
            typedef void (ircClient::*_t)(const nickAndStatus , const nickAndStatus , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ircClient::userChangeNick)) {
                *result = 4;
            }
        }
        {
            typedef void (ircClient::*_t)(const nickAndStatus , const nickAndStatus , const QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ircClient::userChangeStatus)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject ircClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ircClient.data,
      qt_meta_data_ircClient,  qt_static_metacall, 0, 0}
};


const QMetaObject *ircClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ircClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ircClient.stringdata))
        return static_cast<void*>(const_cast< ircClient*>(this));
    return QObject::qt_metacast(_clname);
}

int ircClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ircClient::startupComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ircClient::chatReceived(const QString _t1, const nickAndStatus _t2, const QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ircClient::userOnline(const nickAndStatus _t1, const QString _t2, const QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ircClient::userOffline(const nickAndStatus _t1, const QString _t2, const QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ircClient::userChangeNick(const nickAndStatus _t1, const nickAndStatus _t2, const QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ircClient::userChangeStatus(const nickAndStatus _t1, const nickAndStatus _t2, const QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
