#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H

#include <cresuscore_global.h>
#include <OperationsList.h>
#include <Operation.h>
#include <OperationData.h>
#include <QSet>

#include <OperationList.h>
#include <Operation.h>
#include <QMap>
#include <QUuid>

class CRESUSCORESHARED_EXPORT OperationManager : public OperationList
{
public:
    OperationManager();

    //void addNewOperations( const QList<Operation>& opertions );
    void addOperation( const QDate& date, const QString& label, int value, const QString& account);

    // OperationsList interface
    virtual int operationCount() const;
    virtual Operation operation(int index) const;

private:
    QSet< OperationData > m_data;
    QList< Operation > m_operations;
};

#endif // OPERATIONMANAGER_H
