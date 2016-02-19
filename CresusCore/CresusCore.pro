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
    OperationManager.cpp \
    OperationsList.cpp \
    ImportModule.cpp \
    AbstractImportModule.cpp \
    OperationsUtils.cpp

HEADERS +=\
    cresuscore_global.h \
    Operation.h \
    OperationData.h \
    OperationManager.h \
    OperationsList.h \
    ImportModule.h \
    AbstractImportModule.h \
    OperationsUtils.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

Debug:target.path = $$OUT_PWD/../CresusGui/debug
Release:target.path = $$OUT_PWD/../CresusGui/release
INSTALLS += target
