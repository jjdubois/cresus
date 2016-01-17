#-------------------------------------------------
#
# Project created by QtCreator 2016-01-10T22:15:03
#
#-------------------------------------------------

QT       -= gui

TARGET = BPCsvImportModule
TEMPLATE = lib

DEFINES += BPCSVIMPORTMODULE_LIBRARY

SOURCES += BPCsvImportModule.cpp

HEADERS += BPCsvImportModule.h\
        bpcsvimportmodule_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../CresusCore/release/ -lCresusCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../CresusCore/debug/ -lCresusCore
else:unix: LIBS += -L$$OUT_PWD/../CresusCore/ -lCresusCore

Debug:target.path = $$OUT_PWD/../CresusGui/debug
Release:target.path = $$OUT_PWD/../CresusGui/release
INSTALLS += target

message($$OUT_PWD)

INCLUDEPATH += $$PWD/../CresusCore
DEPENDPATH += $$PWD/../CresusCore
