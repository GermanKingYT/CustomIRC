/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../customIrcClient/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[29];
    char stringdata[310];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 12),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 10),
QT_MOC_LITERAL(4, 36, 9),
QT_MOC_LITERAL(5, 46, 8),
QT_MOC_LITERAL(6, 55, 7),
QT_MOC_LITERAL(7, 63, 12),
QT_MOC_LITERAL(8, 76, 7),
QT_MOC_LITERAL(9, 84, 14),
QT_MOC_LITERAL(10, 99, 4),
QT_MOC_LITERAL(11, 104, 21),
QT_MOC_LITERAL(12, 126, 3),
QT_MOC_LITERAL(13, 130, 3),
QT_MOC_LITERAL(14, 134, 15),
QT_MOC_LITERAL(15, 150, 18),
QT_MOC_LITERAL(16, 169, 18),
QT_MOC_LITERAL(17, 188, 17),
QT_MOC_LITERAL(18, 206, 5),
QT_MOC_LITERAL(19, 212, 16),
QT_MOC_LITERAL(20, 229, 2),
QT_MOC_LITERAL(21, 232, 9),
QT_MOC_LITERAL(22, 242, 14),
QT_MOC_LITERAL(23, 257, 7),
QT_MOC_LITERAL(24, 265, 9),
QT_MOC_LITERAL(25, 275, 6),
QT_MOC_LITERAL(26, 282, 9),
QT_MOC_LITERAL(27, 292, 8),
QT_MOC_LITERAL(28, 301, 7)
    },
    "MainWindow\0chatReceived\0\0eventChat*\0"
    "chatEvent\0sendChat\0message\0commandGiven\0"
    "command\0QList<QString>\0args\0"
    "moveScrollBarToBottom\0min\0max\0"
    "serverConnected\0serverDisconnected\0"
    "userQueryCompleted\0QVector<ircUser*>\0"
    "users\0userStatusChange\0id\0newStatus\0"
    "userChangeNick\0newNick\0userLeave\0"
    "userId\0userEnter\0ircUser*\0newUser\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08,
       5,    1,   72,    2, 0x08,
       7,    2,   75,    2, 0x08,
      11,    2,   80,    2, 0x08,
      14,    0,   85,    2, 0x08,
      15,    0,   86,    2, 0x08,
      16,    1,   87,    2, 0x08,
      19,    2,   90,    2, 0x08,
      22,    2,   95,    2, 0x08,
      24,    1,  100,    2, 0x08,
      26,    1,  103,    2, 0x08,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 9,    8,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   20,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   20,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, 0x80000000 | 27,   28,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->chatReceived((*reinterpret_cast< eventChat*(*)>(_a[1]))); break;
        case 1: _t->sendChat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->commandGiven((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        case 3: _t->moveScrollBarToBottom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->serverConnected(); break;
        case 5: _t->serverDisconnected(); break;
        case 6: _t->userQueryCompleted((*reinterpret_cast< QVector<ircUser*>(*)>(_a[1]))); break;
        case 7: _t->userStatusChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->userChangeNick((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->userLeave((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->userEnter((*reinterpret_cast< ircUser*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<ircUser*> >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ircUser* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
