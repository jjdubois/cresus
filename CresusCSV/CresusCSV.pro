#-------------------------------------------------
#
# Project created by QtCreator 2016-02-19T22:19:03
#
#-------------------------------------------------

QT       -= gui

TARGET = CresusCSV
TEMPLATE = lib

DEFINES += CRESUSCSV_LIBRARY

SOURCES += CresusCSV.cpp

HEADERS += CresusCSV.h\
        cresuscsv_global.h

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

INCLUDEPATH += $$PWD/../CresusCore
DEPENDPATH += $$PWD/../CresusCore
