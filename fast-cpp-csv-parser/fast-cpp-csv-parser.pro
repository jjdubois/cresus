#-------------------------------------------------
#
# Project created by QtCreator 2016-01-12T21:38:31
#
#-------------------------------------------------

QT       -= core gui

TARGET = fast-cpp-csv-parser
TEMPLATE = lib

DEFINES += FASTCPPCSVPARSER_LIBRARY

HEADERS += csv.h \
    csv.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
