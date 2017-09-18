/********************************************************************************
** Form generated from reading UI file 'userwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWIDGET_H
#define UI_USERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userwidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_pic;
    QVBoxLayout *verticalLayout;
    QLabel *label_name;
    QLabel *label_diy;

    void setupUi(QWidget *userwidget)
    {
        if (userwidget->objectName().isEmpty())
            userwidget->setObjectName(QStringLiteral("userwidget"));
        userwidget->resize(220, 110);
        userwidget->setMinimumSize(QSize(220, 110));
        userwidget->setMaximumSize(QSize(16777215, 110));
        horizontalLayout = new QHBoxLayout(userwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        label_pic = new QLabel(userwidget);
        label_pic->setObjectName(QStringLiteral("label_pic"));
        label_pic->setMinimumSize(QSize(100, 100));
        label_pic->setMaximumSize(QSize(100, 100));

        horizontalLayout->addWidget(label_pic);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_name = new QLabel(userwidget);
        label_name->setObjectName(QStringLiteral("label_name"));

        verticalLayout->addWidget(label_name);

        label_diy = new QLabel(userwidget);
        label_diy->setObjectName(QStringLiteral("label_diy"));

        verticalLayout->addWidget(label_diy);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(userwidget);

        QMetaObject::connectSlotsByName(userwidget);
    } // setupUi

    void retranslateUi(QWidget *userwidget)
    {
        userwidget->setWindowTitle(QApplication::translate("userwidget", "Form", 0));
        label_pic->setText(QApplication::translate("userwidget", "pic", 0));
        label_name->setText(QApplication::translate("userwidget", "TextLabel", 0));
        label_diy->setText(QApplication::translate("userwidget", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class userwidget: public Ui_userwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWIDGET_H
