/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../kalaOK/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[14];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 21), // "on_btnHistory_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 22), // "on_btnHotMusic_clicked"
QT_MOC_LITERAL(4, 53, 24), // "on_btnOrderMusic_clicked"
QT_MOC_LITERAL(5, 78, 20), // "on_btnSearch_clicked"
QT_MOC_LITERAL(6, 99, 27), // "on_btn_hotMusicBack_clicked"
QT_MOC_LITERAL(7, 127, 25), // "on_btn_musHisBack_clicked"
QT_MOC_LITERAL(8, 153, 24), // "on_btn_orderBack_clicked"
QT_MOC_LITERAL(9, 178, 17), // "on_btnSet_clicked"
QT_MOC_LITERAL(10, 196, 23), // "on_btn_setClose_clicked"
QT_MOC_LITERAL(11, 220, 28), // "on_btnRefreshNetwork_clicked"
QT_MOC_LITERAL(12, 249, 10), // "orderMusic"
QT_MOC_LITERAL(13, 260, 14) // "ClientRecvData"

    },
    "Widget\0on_btnHistory_clicked\0\0"
    "on_btnHotMusic_clicked\0on_btnOrderMusic_clicked\0"
    "on_btnSearch_clicked\0on_btn_hotMusicBack_clicked\0"
    "on_btn_musHisBack_clicked\0"
    "on_btn_orderBack_clicked\0on_btnSet_clicked\0"
    "on_btn_setClose_clicked\0"
    "on_btnRefreshNetwork_clicked\0orderMusic\0"
    "ClientRecvData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnHistory_clicked(); break;
        case 1: _t->on_btnHotMusic_clicked(); break;
        case 2: _t->on_btnOrderMusic_clicked(); break;
        case 3: _t->on_btnSearch_clicked(); break;
        case 4: _t->on_btn_hotMusicBack_clicked(); break;
        case 5: _t->on_btn_musHisBack_clicked(); break;
        case 6: _t->on_btn_orderBack_clicked(); break;
        case 7: _t->on_btnSet_clicked(); break;
        case 8: _t->on_btn_setClose_clicked(); break;
        case 9: _t->on_btnRefreshNetwork_clicked(); break;
        case 10: _t->orderMusic(); break;
        case 11: _t->ClientRecvData(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
