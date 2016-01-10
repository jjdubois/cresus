#include "Operation.h"

#include <OperationData.h>

Operation::Operation()
{

}

bool Operation::isNull()
{
    return m_uuid.isNull();
}
