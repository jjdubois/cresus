#-------------------------------------------------
#
# Project created by QtCreator 2016-01-10T12:05:18
#
#-------------------------------------------------

QT       -= gui

TARGET = SimpleCrypt
TEMPLATE = lib

DEFINES += SIMPLECRYPT_LIBRARY

SOURCES += simplecrypt.cpp

HEADERS += simplecrypt.h\
        simplecrypt_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
