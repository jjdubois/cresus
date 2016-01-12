#include "operationsdata.h"
#include <QStandardPaths>
#include <QDebug>
OperationsData::OperationsData(QObject *parent) : QObject(parent)
{
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);qDebug()<<dataPath;
}
