#include <QApplication>
#include <QtQml>
#include <QQmlApplicationEngine>
#include <operationsdata.h>
#include <operationsmodel.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<OperationsData>("cresus", 1, 0, "OperationsData");
    qmlRegisterType<OperationsModel>("cresus", 1, 0, "OperationsModel");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
