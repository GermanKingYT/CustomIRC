/****************************************************************************
** Meta object code from reading C++ file 'uiclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../customIrcServer/uiclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uiclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_uiClient_t {
    QByteArrayData data[14];
    char stringdata[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_uiClient_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_uiClient_t qt_meta_stringdata_uiClient = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 12),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 9),
QT_MOC_LITERAL(4, 33, 6),
QT_MOC_LITERAL(5, 40, 12),
QT_MOC_LITERAL(6, 53, 7),
QT_MOC_LITERAL(7, 61, 9),
QT_MOC_LITERAL(8, 71, 9),
QT_MOC_LITERAL(9, 81, 13),
QT_MOC_LITERAL(10, 95, 12),
QT_MOC_LITERAL(11, 108, 4),
QT_MOC_LITERAL(12, 113, 16),
QT_MOC_LITERAL(13, 130, 14)
    },
    "uiClient\0disconnected\0\0uiClient*\0"
    "client\0chatReceived\0message\0userQuery\0"
    "getEvents\0changeOwnUser\0jsonCommand&\0"
    "comm\0removeConnection\0receiveMessage\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_uiClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x05,
       5,    1,   52,    2, 0x05,
       7,    1,   55,    2, 0x05,
       8,    1,   58,    2, 0x05,
       9,    1,   61,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      12,    0,   64,    2, 0x0a,
      13,    0,   65,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 10,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void uiClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        uiClient *_t = static_cast<uiClient *>(_o);
        switch (_id) {
        case 0: _t->disconnected((*reinterpret_cast< uiClient*(*)>(_a[1]))); break;
        case 1: _t->chatReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->userQuery((*reinterpret_cast< uiClient*(*)>(_a[1]))); break;
        case 3: _t->getEvents((*reinterpret_cast< uiClient*(*)>(_a[1]))); break;
        case 4: _t->changeOwnUser((*reinterpret_cast< jsonCommand(*)>(_a[1]))); break;
        case 5: _t->removeConnection(); break;
        case 6: _t->receiveMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
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
        case 3:
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
            typedef void (uiClient::*_t)(uiClient * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiClient::disconnected)) {
                *result = 0;
            }
        }
        {
            typedef void (uiClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiClient::chatReceived)) {
                *result = 1;
            }
        }
        {
            typedef void (uiClient::*_t)(uiClient * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiClient::userQuery)) {
                *result = 2;
            }
        }
        {
            typedef void (uiClient::*_t)(uiClient * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiClient::getEvents)) {
                *result = 3;
            }
        }
        {
            typedef void (uiClient::*_t)(jsonCommand & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&uiClient::changeOwnUser)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject uiClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_uiClient.data,
      qt_meta_data_uiClient,  qt_static_metacall, 0, 0}
};


const QMetaObject *uiClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *uiClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_uiClient.stringdata))
        return static_cast<void*>(const_cast< uiClient*>(this));
    return QObject::qt_metacast(_clname);
}

int uiClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    }
    return _id;
}

// SIGNAL 0
void uiClient::disconnected(uiClient * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void uiClient::chatReceived(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void uiClient::userQuery(uiClient * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void uiClient::getEvents(uiClient * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void uiClient::changeOwnUser(jsonCommand & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
