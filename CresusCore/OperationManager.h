#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H

#include <cresuscore_global.h>
#include <OperationsList.h>
#include <Operation.h>
#include <OperationData.h>
#include <QSet>

#include <OperationsList.h>
#include <AbstractOperationsList.h>
#include <SubOperationsList.h>
#include <Operation.h>
#include <QMap>

class CRESUSCORESHARED_EXPORT OperationManager : public AbstractOperationsList<SubOperationsList>
{
public:
    OperationManager();
    Operation addOperation( const OperationData& data );

    void addOperationInCluster( const Operation& operation, SubOperationsList* cluster );
    void removeOperationFromCluster( const Operation& operation, SubOperationsList* cluster );

    virtual void addOperation(const Operation& operation);
    virtual void removeOperation(int index);

    virtual OperationsList*createChild();
    virtual void removeChild(int index);

    OperationsList* findCluster(const QStringList& path, bool createIfMissing = false );
private:
    QSet< OperationData > m_data;

};

#endif // OPERATIONMANAGER_H
