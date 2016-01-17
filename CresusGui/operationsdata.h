#ifndef OPERATIONSDATA_H
#define OPERATIONSDATA_H

#include <QObject>
#include <OperationManager.h>
class OperationsData : public QObject
{
    Q_OBJECT
public:
    OperationsData( QObject* parent = NULL );

    Q_INVOKABLE void searchNewOperations();
private:

    OperationManager m_operations;
};

#endif // OPERATIONSDATA_H
