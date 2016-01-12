#ifndef OPERATIONSDATA_H
#define OPERATIONSDATA_H

#include <QObject>
#include <OperationManager.h>
class OperationsData : public QObject
{
    Q_OBJECT
public:
    OperationsData( QObject* parent = NULL );
};

#endif // OPERATIONSDATA_H
