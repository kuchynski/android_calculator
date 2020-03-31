/****************************************************************************
** Meta object code from reading C++ file 'CAllWindows.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CAllWindows.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CAllWindows.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CAllWindows_t {
    QByteArrayData data[15];
    char stringdata[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CAllWindows_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CAllWindows_t qt_meta_stringdata_CAllWindows = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 9),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 1),
QT_MOC_LITERAL(4, 25, 9),
QT_MOC_LITERAL(5, 35, 13),
QT_MOC_LITERAL(6, 49, 1),
QT_MOC_LITERAL(7, 51, 18),
QT_MOC_LITERAL(8, 70, 18),
QT_MOC_LITERAL(9, 89, 14),
QT_MOC_LITERAL(10, 104, 13),
QT_MOC_LITERAL(11, 118, 17),
QT_MOC_LITERAL(12, 136, 17),
QT_MOC_LITERAL(13, 154, 22),
QT_MOC_LITERAL(14, 177, 22)
    },
    "CAllWindows\0NewWindow\0\0n\0IAmReSize\0"
    "DragImageTare\0s\0CompressXImageTare\0"
    "CompressYImageTare\0OnButtonsClick\0"
    "OnPressButton\0IAmReSizeFromTare\0"
    "DragImageFromTare\0CompressXImageFromTare\0"
    "CompressYImageFromTare\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAllWindows[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06,
       4,    0,   77,    2, 0x06,
       5,    1,   78,    2, 0x06,
       7,    1,   81,    2, 0x06,
       8,    1,   84,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       9,    2,   87,    2, 0x08,
       9,    1,   92,    2, 0x28,
      10,    1,   95,    2, 0x0a,
      11,    0,   98,    2, 0x0a,
      12,    1,   99,    2, 0x0a,
      13,    1,  102,    2, 0x0a,
      14,    1,  105,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    3,    6,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void CAllWindows::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CAllWindows *_t = static_cast<CAllWindows *>(_o);
        switch (_id) {
        case 0: _t->NewWindow((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->IAmReSize(); break;
        case 2: _t->DragImageTare((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->CompressXImageTare((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->CompressYImageTare((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->OnButtonsClick((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->OnButtonsClick((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 7: _t->OnPressButton((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 8: _t->IAmReSizeFromTare(); break;
        case 9: _t->DragImageFromTare((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->CompressXImageFromTare((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->CompressYImageFromTare((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CAllWindows::*_t)(unsigned  );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAllWindows::NewWindow)) {
                *result = 0;
            }
        }
        {
            typedef void (CAllWindows::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAllWindows::IAmReSize)) {
                *result = 1;
            }
        }
        {
            typedef void (CAllWindows::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAllWindows::DragImageTare)) {
                *result = 2;
            }
        }
        {
            typedef void (CAllWindows::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAllWindows::CompressXImageTare)) {
                *result = 3;
            }
        }
        {
            typedef void (CAllWindows::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CAllWindows::CompressYImageTare)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject CAllWindows::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CAllWindows.data,
      qt_meta_data_CAllWindows,  qt_static_metacall, 0, 0}
};


const QMetaObject *CAllWindows::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAllWindows::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CAllWindows.stringdata))
        return static_cast<void*>(const_cast< CAllWindows*>(this));
    return QWidget::qt_metacast(_clname);
}

int CAllWindows::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void CAllWindows::NewWindow(unsigned  _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CAllWindows::IAmReSize()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void CAllWindows::DragImageTare(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CAllWindows::CompressXImageTare(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CAllWindows::CompressYImageTare(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
