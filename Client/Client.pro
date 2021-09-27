#-------------------------------------------------
#
# Project created by QtCreator 2018-01-19T14:42:02
#
#-------------------------------------------------

QT       += core gui dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app
INCLUDEPATH += ../

SOURCES += main.cpp\
        mainwindow.cpp \
        clientInterface.cpp \
        ../__interfaces/msgInterface.cpp \
        ../__interfaces/interfaceTypeDefine.cpp

HEADERS  += mainwindow.h \
        clientInterface.h \
        ../__interfaces/msgInterface.h \
        ../__interfaces/interfaceTypeDefine.h