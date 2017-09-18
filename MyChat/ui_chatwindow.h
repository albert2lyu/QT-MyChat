/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QWidget *widget;
    QPushButton *pushButton_send;
    QPushButton *pushButton_close;
    QPushButton *pushButton_chatdata;
    QTextEdit *textEdit;
    QListWidget *listWidget;
    QLabel *label_name;
    QTextEdit *textEdit_2;

    void setupUi(QDialog *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName(QStringLiteral("ChatWindow"));
        ChatWindow->resize(668, 410);
        widget = new QWidget(ChatWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 401, 472));
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(16777215, 16777215));
        pushButton_send = new QPushButton(widget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setGeometry(QRect(320, 370, 71, 23));
        pushButton_close = new QPushButton(widget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setGeometry(QRect(230, 370, 71, 23));
        pushButton_chatdata = new QPushButton(widget);
        pushButton_chatdata->setObjectName(QStringLiteral("pushButton_chatdata"));
        pushButton_chatdata->setGeometry(QRect(320, 260, 71, 23));
        pushButton_chatdata->setCheckable(true);
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 290, 381, 71));
        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 30, 381, 221));
        label_name = new QLabel(widget);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(13, 10, 191, 20));
        textEdit_2 = new QTextEdit(ChatWindow);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(400, 30, 261, 331));

        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QDialog *ChatWindow)
    {
        ChatWindow->setWindowTitle(QApplication::translate("ChatWindow", "Dialog", 0));
        pushButton_send->setText(QApplication::translate("ChatWindow", "\345\217\221\351\200\201(&s)", 0));
        pushButton_close->setText(QApplication::translate("ChatWindow", "\345\205\263\351\227\255(&c)", 0));
        pushButton_chatdata->setText(QApplication::translate("ChatWindow", "\350\201\212\345\244\251\350\256\260\345\275\225", 0));
        label_name->setText(QApplication::translate("ChatWindow", "label_name", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
