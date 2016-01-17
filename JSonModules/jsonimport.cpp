#include "jsonimport.h"

#include <QJSon/Parser>
#include <QVariant>
#include <OperationData.h>
#include <OperationManager.h>

JSonImport::JSonImport(): m_io(NULL)
{

}

bool JSonImport::importOperations( OperationManager& manager )
{
    QJson::Parser parser;
    bool parseOk;
    QVariant variant = parser.parse(m_io, &parseOk);
    if( !parseOk )
        return false;

    QList<OperationData> operations = variant.value< QList<OperationData> >();

    foreach( const OperationData& data , operations )
    {
        manager.addOperation( data );
    }

    return true;
}

QIODevice *JSonImport::io() const
{
    return m_io;
}

void JSonImport::setIo(QIODevice *io)
{
    m_io = io;
}
