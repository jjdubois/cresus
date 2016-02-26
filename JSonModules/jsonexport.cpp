#include "jsonexport.h"

#include <QJson/Serializer>
#include <QVariant>
#include <OperationManager.h>

JSonExport::JSonExport()
{

}

bool JSonExport::exportOperations(QIODevice& device, const OperationManager& manager)
{
    QJson::Serializer serializer;
    serializer.setIndentMode(QJson::IndentMedium);

    QVariantList operationsList;

    for( int i = 0 ; i < manager.operationCount() ; ++i )
    {
        Operation op = manager.operation( i );
        QVariantMap map;
        op >> map;
        operationsList.append( map );
    }
    bool ok;
    serializer.serialize( QVariant(operationsList), &device,&ok);
    return ok;
}

QString JSonExport::fileExtension() const
{
    return QString("json");
}
