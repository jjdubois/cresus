#-------------------------------------------------
#
# Project created by QtCreator 2016-01-10T11:42:20
#
#-------------------------------------------------

QT       -= gui

TARGET = CresusCore
TEMPLATE = lib

DEFINES += CRESUSCORE_LIBRARY

SOURCES += \
    Operation.cpp \
    OperationData.cpp \
    OperationManager.cpp

HEADERS +=\
        cresuscore_global.h \
    Operation.h \
    OperationData.h \
    OperationManager.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
