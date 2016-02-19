#ifndef OPERATIONMANAGER_H
#define OPERATIONMANAGER_H

#include <cresuscore_global.h>
#include <OperationsList.h>
#include <Operation.h>
#include <OperationData.h>
#include <QSet>

#include <OperationsList.h>
#include <Operation.h>
#include <QMap>

class CRESUSCORESHARED_EXPORT OperationManager : public OperationsList
{
public:
    OperationManager();

    void addOperation( const OperationData& data );

    // OperationsList interface
    virtual int operationCount() const;
    virtual Operation operation(int index) const;

    QString label() const;
    QString icon() const;

private:
    QSet< OperationData > m_data;
    QList< Operation > m_operations;

};

#endif // OPERATIONMANAGER_H
