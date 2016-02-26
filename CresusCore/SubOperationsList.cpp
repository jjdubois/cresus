#include "SubOperationsList.h"
#include <OperationManager.h>

SubOperationsList::SubOperationsList( OperationManager& manager ,OperationsList& parent )
    : AbstractOperationsList( &parent )
    , m_manager(manager)
{

}

void SubOperationsList::addOperation(const Operation& operation)
{
    if( !m_parent->contains(operation) )
    {
        SubOperationsList* p = static_cast<SubOperationsList*>(m_parent);
        p->addOperationInternal( operation );
    }else
    {
        for( int i = 0 ; i < m_parent->childrenCount() ; ++i )
        {
            SubOperationsList* subCluster = static_cast<SubOperationsList*>(m_parent->child(i));
            subCluster->removeOperationInternal( operation );
        }
    }
}

void SubOperationsList::removeOperation( int index )
{
    Operation op = operation( index );

    removeOperationInternal( op );
}

OperationsList*SubOperationsList::createChild()
{
    SubOperationsList* category = new SubOperationsList( m_manager, *this );
    addOperationList( *category );
    return category;
}

void SubOperationsList::removeChild(int index)
{
    SubOperationsList* category = m_operationsLists.at(index);
    if( category )
    {
        removeOperationList( *category );
        category->deleteLater();
    }
}

void SubOperationsList::removeOperationInternal(const Operation& operation)
{
    // Remove in children
    Q_FOREACH(SubOperationsList* subCluster, m_operationsLists )
    {
        subCluster->removeOperationInternal( operation );
    }

    // Remove data
    if( m_operations.contains(operation) )
    {
        m_manager.removeOperationFromCluster( operation, this );
    }
}

void SubOperationsList::addOperationInternal(const Operation& operation)
{

}
