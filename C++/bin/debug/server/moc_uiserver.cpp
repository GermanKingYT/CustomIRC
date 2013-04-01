/****************************************************************************
** Meta object code from reading C++ file 'uiserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../customIrcServer/uiserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uiserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_uiServer_t {
    QByteArrayData data[18];
    char stringdata[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_uiServer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_uiServer_t qt_meta_stringdata_uiServer = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 15),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 7),
QT_MOC_LITERAL(4, 34, 12),
QT_MOC_LITERAL(5, 47, 9),
QT_MOC_LITERAL(6, 57, 6),
QT_MOC_LITERAL(7, 64, 13),
QT_MOC_LITERAL(8, 78, 22),
QT_MOC_LITERAL(9, 101, 9),
QT_MOC_LITERAL(10, 111, 16),
QT_MOC_LITERAL(11, 128, 14),
QT_MOC_LITERAL(12, 143, 12),
QT_MOC_LITERAL(13, 156, 11),
QT_MOC_LITERAL(14, 168, 12),
QT_MOC_LITERAL(15, 181, 13),
QT_MOC_LITERAL(16, 195, 12),
QT_MOC_LITERAL(17, 208, 4)
    },
    "uiServer\0sgnChatReceived\0\0message\0"
    "sgnUserQuery\0uiClient*\0client\0"
    "sgnSendEvents\0sgnChangeOwnUserStatus\0"
    "newStatus\0acceptConnection\0lostConnection\0"
    "chatReceived\0doUserQuery\0doSendEvents\0"
    "changeOwnUser\0jsonCommand&\0comm\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_uiServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x05,
       4,    1,   67,    2, 0x05,
       7,    1,   70,    2, 0x05,
       8,    1,   73,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      10,    0,   76,    2, 0x08,
      11,    1,   77,    2, 0x08,
      12,    1,   80,    2, 0x08,
      13,    1,   83,    2, 0x08,
      14,    1,   86,    2, 0x08,
      15,    1,   89,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

void uiServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        uiServer *_t = static_cast<uiServer *>(_o);
        switch (_id) {
        case 0: _t->sgnChatReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sgnUserQuery((*reinterpret_cast< uiClient*(*)>(_a[1]))); break;
        case 2: _t->sgnSendEvents((*reinterpret_cast< uiClient*(*)>(_a[1]))); break;
        case 3: _t->sgnChangeOwnUserStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->acceptConnection(); break;
        case 5: _t->lostConnection((*reinterpret_cast< uiClient*(*)>(_a[1]))); break;
        case 6: _t->chatReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->doUserQuery((*reinterpret_cast< uiClient*(*)>(_a[1]))); break;
        case 8: _t->doSendEvents((*reinterpret_cast< uiClient*(*)>(_a[1]))); break;
        case 9: _t->changeOwnUser((*reinterpret_cast< jsonCommand(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< uiClient* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< uiClient* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< uiClient* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< uiClient* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< uiClient* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (uiServer::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiServer::sgnChatReceived)) {
                *result = 0;
            }
        }
        {
            typedef void (uiServer::*_t)(uiClient * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiServer::sgnUserQuery)) {
                *result = 1;
            }
        }
        {
            typedef void (uiServer::*_t)(uiClient * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiServer::sgnSendEvents)) {
                *result = 2;
            }
        }
        {
            typedef void (uiServer::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiServer::sgnChangeOwnUserStatus)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject uiServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_uiServer.data,
      qt_meta_data_uiServer,  qt_static_metacall, 0, 0}
};


const QMetaObject *uiServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *uiServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_uiServer.stringdata))
        return static_cast<void*>(const_cast< uiServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int uiServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void uiServer::sgnChatReceived(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void uiServer::sgnUserQuery(uiClient * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void uiServer::sgnSendEvents(uiClient * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void uiServer::sgnChangeOwnUserStatus(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
