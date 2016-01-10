#ifndef OPERATION_H
#define OPERATION_H

#include <cresuscore_global.h>
#include <QUuid>

class OperationData;
class OperationManager;
class CRESUSCORESHARED_EXPORT Operation
{
public:
    Operation();

    bool isNull();

private:
    QUuid m_uuid;
    OperationManager* m_manager;
    OperationData* m_data;
};

#endif // OPERATION_H
