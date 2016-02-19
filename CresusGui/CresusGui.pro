TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += main.cpp \
    operationsdata.cpp \
    operationsmodel.cpp

HEADERS += \
    operationsdata.h \
    operationsmodel.h

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../CresusCore/release/ -lCresusCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../CresusCore/debug/ -lCresusCore
else:unix: LIBS += -L$$OUT_PWD/../CresusCore/ -lCresusCore

INCLUDEPATH += $$PWD/../CresusCore
DEPENDPATH += $$PWD/../CresusCore

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../JSonModules/release/ -lJSonModules
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../JSonModules/debug/ -lJSonModules
else:unix: LIBS += -L$$OUT_PWD/../JSonModules/ -lJSonModules

INCLUDEPATH += $$PWD/../JSonModules
DEPENDPATH += $$PWD/../JSonModules

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../BPCsvImportModule/release/ -lBPCsvImportModule
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../BPCsvImportModule/debug/ -lBPCsvImportModule
else:unix: LIBS += -L$$OUT_PWD/../BPCsvImportModule/ -lBPCsvImportModule

INCLUDEPATH += $$PWD/../BPCsvImportModule
DEPENDPATH += $$PWD/../BPCsvImportModule
