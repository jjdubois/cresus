#-------------------------------------------------
#
# Project created by QtCreator 2016-01-07T13:57:44
#
#-------------------------------------------------

QT       -= gui

TARGET = qjson
TEMPLATE = lib

DEFINES += QJSON_LIBRARY QJSON_MAKEDLL

SOURCES += \
    src/json_parser.cc \
    src/json_scanner.cpp \
    src/parser.cpp \
    src/parserrunnable.cpp \
    src/qobjecthelper.cpp \
    src/serializer.cpp \
    src/serializerrunnable.cpp

HEADERS +=\
    qjson_global.h \
    src/json_parser.hh \
    src/json_parser.yy \
    src/json_scanner.h \
    src/location.hh \
    src/parser.h \
    src/parser_p.h \
    src/parserrunnable.h \
    src/position.hh \
    src/qjson_debug.h \
    src/qjson_export.h \
    src/qobjecthelper.h \
    src/serializer.h \
    src/serializerrunnable.h \
    src/stack.hh \
    include/QJson/Parser \
    include/QJson/QObjectHelper \
    include/QJson/Serializer

unix {
    target.path = /usr/lib
    INSTALLS += target
}
