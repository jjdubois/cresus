#include "jsonimport.h"

#include <QJSon/Parser>
#include <QVariant>
#include <OperationData.h>
#include <OperationManager.h>
#include <QDebug>
#include <QStandardPaths>

JSonImport::JSonImport():AbstractImportModule( QRegExp( ".*\\.json" ) )
{
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
