/****************************************************************************
** Meta object code from reading C++ file 'chatinput.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../customIrcClient/chatinput.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatinput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_chatInput_t {
    QByteArrayData data[8];
    char stringdata[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_chatInput_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_chatInput_t qt_meta_stringdata_chatInput = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 8),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 7),
QT_MOC_LITERAL(4, 28, 12),
QT_MOC_LITERAL(5, 41, 7),
QT_MOC_LITERAL(6, 49, 14),
QT_MOC_LITERAL(7, 64, 4)
    },
    "chatInput\0sendChat\0\0message\0commandGiven\0"
    "command\0QList<QString>\0args\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_chatInput[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x05,
       4,    2,   27,    2, 0x05,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6,    5,    7,

       0        // eod
};

void chatInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        chatInput *_t = static_cast<chatInput *>(_o);
        switch (_id) {
        case 0: _t->sendChat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->commandGiven((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (chatInput::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chatInput::sendChat)) {
                *result = 0;
            }
        }
        {
            typedef void (chatInput::*_t)(QString , QList<QString> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&chatInput::commandGiven)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject chatInput::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_chatInput.data,
      qt_meta_data_chatInput,  qt_static_metacall, 0, 0}
};


const QMetaObject *chatInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *chatInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_chatInput.stringdata))
        return static_cast<void*>(const_cast< chatInput*>(this));
    return QPlainTextEdit::qt_metacast(_clname);
}

int chatInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void chatInput::sendChat(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void chatInput::commandGiven(QString _t1, QList<QString> _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
