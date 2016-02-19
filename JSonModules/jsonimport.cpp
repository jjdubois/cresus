#include "jsonimport.h"

#include <QJSon/Parser>
#include <QVariant>
#include <OperationData.h>
#include <OperationManager.h>
#include <QDebug>
#include <QStandardPaths>

JSonImport::JSonImport():AbstractImportModule( QList<QString>()<<"text/plain" )
{
    qDebug()<<QStandardPaths::locateAll(QStandardPaths::GenericDataLocation, QLatin1String("mime/packages"),
                              QStandardPaths::LocateDirectory);
}

bool JSonImport::importOperations(QIODevice& device, OperationManager& manager )
{
    QJson::Parser parser;
    bool parseOk;
    QVariant variant = parser.parse(&device, &parseOk);
    if( !parseOk )
        return false;

    QList<OperationData> operations = variant.value< QList<OperationData> >();

    foreach( const OperationData& data , operations )
    {
        manager.addOperation( data );
    }

    return true;
}

