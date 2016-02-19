#ifndef OPERATION_H
#define OPERATION_H

#include <cresuscore_global.h>

class OperationData;
class OperationManager;
class CRESUSCORESHARED_EXPORT Operation
{
public:
    Operation();
    Operation( OperationManager&, OperationData& data );

    bool isNull();

private:
    OperationManager* m_manager;
    OperationData* m_data;
};

#endif // OPERATION_H
