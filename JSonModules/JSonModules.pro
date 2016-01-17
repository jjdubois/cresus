#-------------------------------------------------
#
# Project created by QtCreator 2016-01-13T13:18:04
#
#-------------------------------------------------

QT       -= gui

TARGET = JSonModules
TEMPLATE = lib

DEFINES += JSONMODULES_LIBRARY

SOURCES += \
    jsonimport.cpp \
    jsonexport.cpp

HEADERS +=\
        jsonmodules_global.h \
    jsonimport.h \
    jsonexport.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../CresusCore/release/ -lCresusCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../CresusCore/debug/ -lCresusCore
else:unix: LIBS += -L$$OUT_PWD/../CresusCore/ -lCresusCore

CONFIG(release, debug|release):libraryFiles.path = $$OUT_PWD/../CresusGui/debug
else:CONFIG(debug, debug|release):libraryFiles.path = $$OUT_PWD/../CresusGui/release
Debug:libraryFiles.files = $$OUT_PWD/debug/*.a $$OUT_PWD/debug/*.prl
Release:libraryFiles.files = $$OUT_PWD/release/*.a $$OUT_PWD/release/*.prl
INSTALLS += libraryFiles

INCLUDEPATH += $$PWD/../CresusCore
DEPENDPATH += $$PWD/../CresusCore

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../qjson/release/ -lqjson
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../qjson/debug/ -lqjson
else:unix: LIBS += -L$$OUT_PWD/../qjson/ -lqjson

INCLUDEPATH += $$PWD/../qjson/include
DEPENDPATH += $$PWD/../qjson

Debug:target.path = $$OUT_PWD/../CresusGui/debug
Release:target.path = $$OUT_PWD/../CresusGui/release
INSTALLS += target
