/********************************************************************************
** Form generated from reading UI file 'logonscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGONSCREEN_H
#define UI_LOGONSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LogonScreen
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_pic;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QFrame *frame_1;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_password;
    QLabel *label_1;
    QLineEdit *lineEdit_account;
    QLabel *label_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_login;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_close;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *LogonScreen)
    {
        if (LogonScreen->objectName().isEmpty())
            LogonScreen->setObjectName(QStringLiteral("LogonScreen"));
        LogonScreen->resize(325, 225);
        verticalLayout = new QVBoxLayout(LogonScreen);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 9);
        label_pic = new QLabel(LogonScreen);
        label_pic->setObjectName(QStringLiteral("label_pic"));

        verticalLayout->addWidget(label_pic);

        frame = new QFrame(LogonScreen);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frame_1 = new QFrame(frame);
        frame_1->setObjectName(QStringLiteral("frame_1"));
        frame_1->setFrameShape(QFrame::StyledPanel);
        frame_1->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_password = new QLineEdit(frame_1);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));

        gridLayout->addWidget(lineEdit_password, 1, 1, 1, 1);

        label_1 = new QLabel(frame_1);
        label_1->setObjectName(QStringLiteral("label_1"));

        gridLayout->addWidget(label_1, 0, 0, 1, 1);

        lineEdit_account = new QLineEdit(frame_1);
        lineEdit_account->setObjectName(QStringLiteral("lineEdit_account"));

        gridLayout->addWidget(lineEdit_account, 0, 1, 1, 1);

        label_2 = new QLabel(frame_1);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        gridLayout_2->addWidget(frame_1, 0, 0, 1, 1);


        verticalLayout->addWidget(frame);

        frame_2 = new QFrame(LogonScreen);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_login = new QPushButton(frame_2);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));

        horizontalLayout->addWidget(pushButton_login);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_close = new QPushButton(frame_2);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));

        horizontalLayout->addWidget(pushButton_close);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(frame_2);

        QWidget::setTabOrder(lineEdit_account, lineEdit_password);
        QWidget::setTabOrder(lineEdit_password, pushButton_login);
        QWidget::setTabOrder(pushButton_login, pushButton_close);

        retranslateUi(LogonScreen);

        QMetaObject::connectSlotsByName(LogonScreen);
    } // setupUi

    void retranslateUi(QDialog *LogonScreen)
    {
        LogonScreen->setWindowTitle(QApplication::translate("LogonScreen", "Dialog", 0));
        label_pic->setText(QApplication::translate("LogonScreen", "picture", 0));
        label_1->setText(QApplication::translate("LogonScreen", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("LogonScreen", "\345\257\206  \347\240\201\357\274\232", 0));
        pushButton_login->setText(QApplication::translate("LogonScreen", "\347\231\273\345\275\225", 0));
        pushButton_close->setText(QApplication::translate("LogonScreen", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class LogonScreen: public Ui_LogonScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGONSCREEN_H
