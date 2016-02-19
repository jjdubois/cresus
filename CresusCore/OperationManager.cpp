#include "OperationManager.h"

OperationManager::OperationManager()
{

}

int OperationManager::operationCount() const
{
    return m_operations.size();
}

Operation OperationManager::operation(int index) const
{
    if( index < operationCount() && index > -1 )
    {
        return m_operations[index];
    }
    else
    {
        return Operation();
    }
}

QString OperationManager::label() const
{
    return QString("Toutes opérations");
}

QString OperationManager::icon() const
{
    return QString();
}

void OperationManager::addOperation( const OperationData& data )
{
    if( m_data.contains( data ))
    {
        return;
    }
    m_operations<< Operation( *this, const_cast<OperationData&>(*m_data.insert(data)) );
}
