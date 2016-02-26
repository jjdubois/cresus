#include "OperationManager.h"

OperationManager::OperationManager() : AbstractOperationsList<SubOperationsList>( NULL )
{
}

Operation OperationManager::addOperation( const OperationData& data )
{
    QSet<OperationData>::const_iterator it = m_data.find( data );
    if( it != m_data.end())
    {
        return Operation( *this, const_cast<OperationData&>(*it) );
    }
    Operation op( *this, const_cast<OperationData&>(*m_data.insert(data)) );
    QList<Operation> operations;
    operations << op;
    AbstractOperationsList::addOperation( operations);
    return op;
}

void OperationManager::addOperationInCluster(const Operation& operation, SubOperationsList* cluster)
{
}

void OperationManager::removeOperationFromCluster(const Operation& operation, SubOperationsList* cluster)
{


//    cluster->inte
}

void OperationManager::addOperation(const Operation& operation)
{
    Q_UNUSED(operation)
}

void OperationManager::removeOperation(int index)
{
    Q_UNUSED(index)
}

OperationsList*OperationManager::createChild()
{
    SubOperationsList* category = new SubOperationsList( *this, *this );
    addOperationList( *category );
    return category;
}

void OperationManager::removeChild(int index)
{
    SubOperationsList* category = m_operationsLists.at(index);
    if( category )
    {
        AbstractOperationsList::removeOperationList( *category );
        category->deleteLater();
    }
}

OperationsList*OperationManager::findCluster(const QStringList& path, bool createIfMissing)
{
    QStringList currentPath = path;
    OperationsList* currentCluster = this;

    while ( currentCluster != NULL && !currentPath.isEmpty()) {
        OperationsList* cluster = currentCluster->findCluster( currentPath.front() );
        if( cluster == NULL && createIfMissing )
        {
            cluster = currentCluster->createChild();
            cluster->setLabel( currentPath.front() );
        }

        currentPath.pop_front();
        currentCluster = cluster;
    }
    return currentCluster;
}
