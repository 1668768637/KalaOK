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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_kalaOKServerClass
{
public:
    QLabel *label_title;
    QTextBrowser *serverInfo;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *sqlString;
    QPushButton *btn_exec;

    void setupUi(QWidget *kalaOKServerClass)
    {
        if (kalaOKServerClass->objectName().isEmpty())
            kalaOKServerClass->setObjectName(QStringLiteral("kalaOKServerClass"));
        kalaOKServerClass->resize(815, 457);
        label_title = new QLabel(kalaOKServerClass);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(200, 30, 431, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\217\244\351\243\216\351\232\266\344\271\246\345\255\227\344\275\223"));
        font.setPointSize(28);
        label_title->setFont(font);
        label_title->setAlignment(Qt::AlignCenter);
        serverInfo = new QTextBrowser(kalaOKServerClass);
        serverInfo->setObjectName(QStringLiteral("serverInfo"));
        serverInfo->setGeometry(QRect(10, 190, 391, 261));
        QFont font1;
        font1.setPointSize(14);
        serverInfo->setFont(font1);
        label = new QLabel(kalaOKServerClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 120, 391, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\217\244\351\243\216\351\232\266\344\271\246\345\255\227\344\275\223"));
        font2.setPointSize(25);
        label->setFont(font2);
        widget = new QWidget(kalaOKServerClass);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(400, 190, 371, 261));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sqlString = new QLineEdit(widget);
        sqlString->setObjectName(QStringLiteral("sqlString"));

        horizontalLayout->addWidget(sqlString);

        btn_exec = new QPushButton(widget);
        btn_exec->setObjectName(QStringLiteral("btn_exec"));

        horizontalLayout->addWidget(btn_exec);


        retranslateUi(kalaOKServerClass);

        QMetaObject::connectSlotsByName(kalaOKServerClass);
    } // setupUi

    void retranslateUi(QWidget *kalaOKServerClass)
    {
        kalaOKServerClass->setWindowTitle(QApplication::translate("kalaOKServerClass", "kalaOKServer", Q_NULLPTR));
        label_title->setText(QApplication::translate("kalaOKServerClass", "\345\216\232\351\207\214\350\237\271\345\215\241\346\213\211OK\347\202\271\346\255\214\347\263\273\347\273\237", Q_NULLPTR));
        serverInfo->setHtml(QApplication::translate("kalaOKServerClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("kalaOKServerClass", "\346\234\215\345\212\241\345\231\250\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        btn_exec->setText(QApplication::translate("kalaOKServerClass", "\346\211\247\350\241\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class kalaOKServerClass: public Ui_kalaOKServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KALAOKSERVER_H
