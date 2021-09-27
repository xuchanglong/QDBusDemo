#-------------------------------------------------
#
# Project created by QtCreator 2018-01-19T14:43:48
#
#-------------------------------------------------

QT       += core dbus

TARGET = Server
TEMPLATE = app

INCLUDEPATH += ../


SOURCES += main.cpp\
        serverInterface.cpp \
        ../__interfaces/interfaceTypeDefine.cpp


HEADERS  += serverInterface.h \
        ../__interfaces/interfaceTypeDefine.h