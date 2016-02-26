#include "OperationsList.h"

OperationsList::OperationsList(QObject* parent): QObject( parent )
{

}

OperationsList::~OperationsList()
{

}

void OperationsList::removeOperation( const Operation& operation )
{
    int operationIndex = index(operation);
    if( operationIndex != -1 )
        removeOperation( operationIndex );
}

OperationsList*OperationsList::findCluster(const QString& label) const
{
    QList<OperationsList*> res = findClusters( label );
    return res.isEmpty()?NULL:res.front();
}

QList<OperationsList*> OperationsList::findClusters(const QString& label) const
{
    QList<OperationsList*> result;
    for( int i = 0 ; i < childrenCount() ; ++i )
    {
        OperationsList* list = child( i );
        if( list->label() == label )
        {
            result.append( list );
        }
    }
    return result;
}
