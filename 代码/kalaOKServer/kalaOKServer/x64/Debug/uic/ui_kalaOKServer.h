/********************************************************************************
** Form generated from reading UI file 'kalaOKServer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KALAOKSERVER_H
#define UI_KALAOKSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_kalaOKServerClass
{
public:
    QLabel *label_title;
    QTextBrowser *serverInfo;

    void setupUi(QWidget *kalaOKServerClass)
    {
        if (kalaOKServerClass->objectName().isEmpty())
            kalaOKServerClass->setObjectName(QStringLiteral("kalaOKServerClass"));
        kalaOKServerClass->resize(885, 666);
        label_title = new QLabel(kalaOKServerClass);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(190, 60, 411, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\217\244\351\243\216\351\232\266\344\271\246\345\255\227\344\275\223"));
        font.setPointSize(28);
        label_title->setFont(font);
        label_title->setAlignment(Qt::AlignCenter);
        serverInfo = new QTextBrowser(kalaOKServerClass);
        serverInfo->setObjectName(QStringLiteral("serverInfo"));
        serverInfo->setGeometry(QRect(195, 121, 391, 301));

        retranslateUi(kalaOKServerClass);

        QMetaObject::connectSlotsByName(kalaOKServerClass);
    } // setupUi

    void retranslateUi(QWidget *kalaOKServerClass)
    {
        kalaOKServerClass->setWindowTitle(QApplication::translate("kalaOKServerClass", "kalaOKServer", Q_NULLPTR));
        label_title->setText(QApplication::translate("kalaOKServerClass", "\345\216\232\351\207\214\350\237\271\345\215\241\346\213\211OK\347\202\271\346\255\214\347\263\273\347\273\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class kalaOKServerClass: public Ui_kalaOKServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KALAOKSERVER_H
