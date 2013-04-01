/****************************************************************************
** Meta object code from reading C++ file 'clsserverconn.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../customIrcClient/clsserverconn.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clsserverconn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_clsServerConn_t {
    QByteArrayData data[22];
    char stringdata[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_clsServerConn_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_clsServerConn_t qt_meta_stringdata_clsServerConn = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 12),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 10),
QT_MOC_LITERAL(4, 39, 5),
QT_MOC_LITERAL(5, 45, 9),
QT_MOC_LITERAL(6, 55, 12),
QT_MOC_LITERAL(7, 68, 18),
QT_MOC_LITERAL(8, 87, 17),
QT_MOC_LITERAL(9, 105, 5),
QT_MOC_LITERAL(10, 111, 16),
QT_MOC_LITERAL(11, 128, 6),
QT_MOC_LITERAL(12, 135, 9),
QT_MOC_LITERAL(13, 145, 14),
QT_MOC_LITERAL(14, 160, 7),
QT_MOC_LITERAL(15, 168, 9),
QT_MOC_LITERAL(16, 178, 9),
QT_MOC_LITERAL(17, 188, 8),
QT_MOC_LITERAL(18, 197, 7),
QT_MOC_LITERAL(19, 205, 15),
QT_MOC_LITERAL(20, 221, 12),
QT_MOC_LITERAL(21, 234, 8)
    },
    "clsServerConn\0chatReceived\0\0eventChat*\0"
    "event\0connected\0disconnected\0"
    "userQueryCompleted\0QVector<ircUser*>\0"
    "users\0userStatusChange\0userId\0newStatus\0"
    "userChangeNick\0newNick\0userLeave\0"
    "userEnter\0ircUser*\0newUser\0srvDisconnected\0"
    "srvConnected\0readData\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_clsServerConn[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x05,
       5,    0,   72,    2, 0x05,
       6,    0,   73,    2, 0x05,
       7,    1,   74,    2, 0x05,
      10,    2,   77,    2, 0x05,
      13,    2,   82,    2, 0x05,
      15,    1,   87,    2, 0x05,
      16,    1,   90,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      19,    0,   93,    2, 0x0a,
      20,    0,   94,    2, 0x0a,
      21,    0,   95,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   11,   14,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, 0x80000000 | 17,   18,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void clsServerConn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        clsServerConn *_t = static_cast<clsServerConn *>(_o);
        switch (_id) {
        case 0: _t->chatReceived((*reinterpret_cast< eventChat*(*)>(_a[1]))); break;
        case 1: _t->connected(); break;
        case 2: _t->disconnected(); break;
        case 3: _t->userQueryCompleted((*reinterpret_cast< QVector<ircUser*>(*)>(_a[1]))); break;
        case 4: _t->userStatusChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->userChangeNick((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->userLeave((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->userEnter((*reinterpret_cast< ircUser*(*)>(_a[1]))); break;
        case 8: _t->srvDisconnected(); break;
        case 9: _t->srvConnected(); break;
        case 10: _t->readData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<ircUser*> >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ircUser* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (clsServerConn::*_t)(eventChat * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clsServerConn::chatReceived)) {
                *result = 0;
            }
        }
        {
            typedef void (clsServerConn::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clsServerConn::connected)) {
                *result = 1;
            }
        }
        {
            typedef void (clsServerConn::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clsServerConn::disconnected)) {
                *result = 2;
            }
        }
        {
            typedef void (clsServerConn::*_t)(QVector<ircUser*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clsServerConn::userQueryCompleted)) {
                *result = 3;
            }
        }
        {
            typedef void (clsServerConn::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clsServerConn::userStatusChange)) {
                *result = 4;
            }
        }
        {
            typedef void (clsServerConn::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clsServerConn::userChangeNick)) {
                *result = 5;
            }
        }
        {
            typedef void (clsServerConn::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clsServerConn::userLeave)) {
                *result = 6;
            }
        }
        {
            typedef void (clsServerConn::*_t)(ircUser * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&clsServerConn::userEnter)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject clsServerConn::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_clsServerConn.data,
      qt_meta_data_clsServerConn,  qt_static_metacall, 0, 0}
};


const QMetaObject *clsServerConn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *clsServerConn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_clsServerConn.stringdata))
        return static_cast<void*>(const_cast< clsServerConn*>(this));
    return QObject::qt_metacast(_clname);
}

int clsServerConn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void clsServerConn::chatReceived(eventChat * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void clsServerConn::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void clsServerConn::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void clsServerConn::userQueryCompleted(QVector<ircUser*> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void clsServerConn::userStatusChange(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void clsServerConn::userChangeNick(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void clsServerConn::userLeave(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void clsServerConn::userEnter(ircUser * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
