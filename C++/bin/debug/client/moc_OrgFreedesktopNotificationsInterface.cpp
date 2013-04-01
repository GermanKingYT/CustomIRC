/****************************************************************************
** Meta object code from reading C++ file 'OrgFreedesktopNotificationsInterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../customIrcClient/OrgFreedesktopNotificationsInterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OrgFreedesktopNotificationsInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OrgFreedesktopNotificationsInterface_t {
    QByteArrayData data[19];
    char stringdata[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_OrgFreedesktopNotificationsInterface_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_OrgFreedesktopNotificationsInterface_t qt_meta_stringdata_OrgFreedesktopNotificationsInterface = {
    {
QT_MOC_LITERAL(0, 0, 36),
QT_MOC_LITERAL(1, 37, 15),
QT_MOC_LITERAL(2, 53, 30),
QT_MOC_LITERAL(3, 84, 0),
QT_MOC_LITERAL(4, 85, 6),
QT_MOC_LITERAL(5, 92, 26),
QT_MOC_LITERAL(6, 119, 7),
QT_MOC_LITERAL(7, 127, 10),
QT_MOC_LITERAL(8, 138, 7),
QT_MOC_LITERAL(9, 146, 7),
QT_MOC_LITERAL(10, 154, 4),
QT_MOC_LITERAL(11, 159, 7),
QT_MOC_LITERAL(12, 167, 5),
QT_MOC_LITERAL(13, 173, 7),
QT_MOC_LITERAL(14, 181, 17),
QT_MOC_LITERAL(15, 199, 19),
QT_MOC_LITERAL(16, 219, 2),
QT_MOC_LITERAL(17, 222, 20),
QT_MOC_LITERAL(18, 243, 42)
    },
    "OrgFreedesktopNotificationsInterface\0"
    "getCapabilities\0QDBusPendingReply<QStringList>\0"
    "\0notify\0QDBusPendingReply<quint32>\0"
    "appName\0replacesId\0appIcon\0summary\0"
    "body\0actions\0hints\0timeout\0closeNotification\0"
    "QDBusPendingReply<>\0id\0getServerInformation\0"
    "QDBusPendingReply<QString,QString,QString>\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OrgFreedesktopNotificationsInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    3, 0x0a,
       4,    8,   35,    3, 0x0a,
      14,    1,   52,    3, 0x0a,
      17,    0,   55,    3, 0x0a,

 // slots: parameters
    0x80000000 | 2,
    0x80000000 | 5, QMetaType::QString, QMetaType::UInt, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QStringList, QMetaType::QVariantMap, QMetaType::Int,    6,    7,    8,    9,   10,   11,   12,   13,
    0x80000000 | 15, QMetaType::UInt,   16,
    0x80000000 | 18,

       0        // eod
};

void OrgFreedesktopNotificationsInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OrgFreedesktopNotificationsInterface *_t = static_cast<OrgFreedesktopNotificationsInterface *>(_o);
        switch (_id) {
        case 0: { QDBusPendingReply<QStringList> _r = _t->getCapabilities();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QStringList>*>(_a[0]) = _r; }  break;
        case 1: { QDBusPendingReply<quint32> _r = _t->notify((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QStringList(*)>(_a[6])),(*reinterpret_cast< const QVariantMap(*)>(_a[7])),(*reinterpret_cast< qint32(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<quint32>*>(_a[0]) = _r; }  break;
        case 2: { QDBusPendingReply<> _r = _t->closeNotification((*reinterpret_cast< quint32(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = _r; }  break;
        case 3: { QDBusPendingReply<QString,QString,QString> _r = _t->getServerInformation();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QString,QString,QString>*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject OrgFreedesktopNotificationsInterface::staticMetaObject = {
    { &QDBusAbstractInterface::staticMetaObject, qt_meta_stringdata_OrgFreedesktopNotificationsInterface.data,
      qt_meta_data_OrgFreedesktopNotificationsInterface,  qt_static_metacall, 0, 0}
};


const QMetaObject *OrgFreedesktopNotificationsInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrgFreedesktopNotificationsInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OrgFreedesktopNotificationsInterface.stringdata))
        return static_cast<void*>(const_cast< OrgFreedesktopNotificationsInterface*>(this));
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int OrgFreedesktopNotificationsInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
