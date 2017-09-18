#-------------------------------------------------
#
# Project created by QtCreator 2017-05-17T21:23:03
#
#-------------------------------------------------

QT       += core sql
QT       += network

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyChat
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logonscreen.cpp \
    chatwindow.cpp \
    userwidget.cpp

HEADERS  += mainwindow.h \
    logonscreen.h \
    chatwindow.h \
    userwidget.h

FORMS    += mainwindow.ui \
    logonscreen.ui \
    chatwindow.ui \
    userwidget.ui

RESOURCES += \
    pic.qrc
