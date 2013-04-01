/****************************************************************************
** Meta object code from reading C++ file 'mainapp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../customIrcServer/mainapp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mainApp_t {
    QByteArrayData data[25];
    char stringdata[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_mainApp_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_mainApp_t qt_meta_stringdata_mainApp = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 12),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 7),
QT_MOC_LITERAL(4, 30, 13),
QT_MOC_LITERAL(5, 44, 4),
QT_MOC_LITERAL(6, 49, 7),
QT_MOC_LITERAL(7, 57, 10),
QT_MOC_LITERAL(8, 68, 4),
QT_MOC_LITERAL(9, 73, 5),
QT_MOC_LITERAL(10, 79, 11),
QT_MOC_LITERAL(11, 91, 2),
QT_MOC_LITERAL(12, 94, 14),
QT_MOC_LITERAL(13, 109, 11),
QT_MOC_LITERAL(14, 121, 11),
QT_MOC_LITERAL(15, 133, 16),
QT_MOC_LITERAL(16, 150, 7),
QT_MOC_LITERAL(17, 158, 7),
QT_MOC_LITERAL(18, 166, 10),
QT_MOC_LITERAL(19, 177, 11),
QT_MOC_LITERAL(20, 189, 9),
QT_MOC_LITERAL(21, 199, 6),
QT_MOC_LITERAL(22, 206, 12),
QT_MOC_LITERAL(23, 219, 19),
QT_MOC_LITERAL(24, 239, 9)
    },
    "mainApp\0chatReceived\0\0channel\0"
    "nickAndStatus\0user\0message\0userOnline\0"
    "nick\0ircId\0userOffline\0id\0userChangeNick\0"
    "oldNickName\0newNickName\0userChangeStatus\0"
    "oldNick\0newNick\0uiSendChat\0doUserQuery\0"
    "uiClient*\0client\0doSendEvents\0"
    "ownUserChangeStatus\0newStatus\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainApp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x0a,
       7,    3,   66,    2, 0x0a,
      10,    3,   73,    2, 0x0a,
      12,    3,   80,    2, 0x0a,
      15,    3,   87,    2, 0x0a,
      18,    1,   94,    2, 0x0a,
      19,    1,   97,    2, 0x0a,
      22,    1,  100,    2, 0x0a,
      23,    1,  103,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, QMetaType::QString,    3,    5,    6,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString, QMetaType::QString,    8,    9,    3,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString, QMetaType::QString,    8,   11,    3,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, QMetaType::QString,   13,   14,   11,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, QMetaType::QString,   16,   17,   11,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, QMetaType::QString,   24,

       0        // eod
};

void mainApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mainApp *_t = static_cast<mainApp *>(_o);
        switch (_id) {
        case 0: _t->chatReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const nickAndStatus(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->userOnline((*reinterpret_cast< const nickAndStatus(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->userOffline((*reinterpret_cast< const nickAndStatus(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 3: _t->userChangeNick((*reinterpret_cast< const nickAndStatus(*)>(_a[1])),(*reinterpret_cast< const nickAndStatus(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: _t->userChangeStatus((*reinterpret_cast< const nickAndStatus(*)>(_a[1])),(*reinterpret_cast< const nickAndStatus(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 5: _t->uiSendChat((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->doUserQuery((*reinterpret_cast< uiClient*(*)>(_a[1]))); break;
        case 7: _t->doSendEvents((*reinterpret_cast< uiClient*(*)>(_a[1]))); break;
        case 8: _t->ownUserChangeStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
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
        }
    }
}

const QMetaObject mainApp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_mainApp.data,
      qt_meta_data_mainApp,  qt_static_metacall, 0, 0}
};


const QMetaObject *mainApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainApp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mainApp.stringdata))
        return static_cast<void*>(const_cast< mainApp*>(this));
    return QObject::qt_metacast(_clname);
}

int mainApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
