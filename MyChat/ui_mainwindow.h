/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_title;
    QPushButton *pushButton_min;
    QPushButton *pushButton_quit;
    QToolBox *toolBox;
    QWidget *page_friend;
    QWidget *page_unknow;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(250, 500);
        MainWindow->setMinimumSize(QSize(250, 500));
        verticalLayout = new QVBoxLayout(MainWindow);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(MainWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_title = new QLabel(widget);
        label_title->setObjectName(QStringLiteral("label_title"));

        horizontalLayout->addWidget(label_title);

        pushButton_min = new QPushButton(widget);
        pushButton_min->setObjectName(QStringLiteral("pushButton_min"));
        pushButton_min->setMinimumSize(QSize(0, 0));
        pushButton_min->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pushButton_min);

        pushButton_quit = new QPushButton(widget);
        pushButton_quit->setObjectName(QStringLiteral("pushButton_quit"));
        pushButton_quit->setMaximumSize(QSize(50, 16777215));
        pushButton_quit->setToolTipDuration(-1);

        horizontalLayout->addWidget(pushButton_quit);


        verticalLayout->addWidget(widget);

        toolBox = new QToolBox(MainWindow);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        page_friend = new QWidget();
        page_friend->setObjectName(QStringLiteral("page_friend"));
        page_friend->setGeometry(QRect(0, 0, 250, 419));
        toolBox->addItem(page_friend, QString::fromUtf8("\346\210\221\347\232\204\345\245\275\345\217\213"));
        page_unknow = new QWidget();
        page_unknow->setObjectName(QStringLiteral("page_unknow"));
        page_unknow->setGeometry(QRect(0, 0, 342, 508));
        toolBox->addItem(page_unknow, QString::fromUtf8("\351\231\214\347\224\237\344\272\272"));

        verticalLayout->addWidget(toolBox);


        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_title->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pushButton_min->setText(QApplication::translate("MainWindow", "-", 0));
        pushButton_quit->setText(QApplication::translate("MainWindow", "X", 0));
        toolBox->setItemText(toolBox->indexOf(page_friend), QApplication::translate("MainWindow", "\346\210\221\347\232\204\345\245\275\345\217\213", 0));
        toolBox->setItemText(toolBox->indexOf(page_unknow), QApplication::translate("MainWindow", "\351\231\214\347\224\237\344\272\272", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
