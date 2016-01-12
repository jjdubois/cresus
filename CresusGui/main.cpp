#include <QApplication>
#include <QtQml>
#include <QQmlApplicationEngine>
#include <operationsdata.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<OperationsData>("cresus", 1, 0, "OperationsData");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
