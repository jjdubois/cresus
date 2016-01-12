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
