#include "Operation.h"

#include <OperationData.h>

Operation::Operation():m_data(NULL), m_manager(NULL)
{

}

Operation::Operation(OperationManager& manager, OperationData& data):m_manager(&manager),m_data(&data)
{    
}

bool Operation::isNull()
{
    return m_data == NULL || m_manager == NULL;
}
