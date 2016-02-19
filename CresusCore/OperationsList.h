#ifndef OPERATIONSLIST_H
#define OPERATIONSLIST_H

#include <cresuscore_global.h>
#include <Operation.h>
#include <QObject>

class CRESUSCORESHARED_EXPORT OperationsList : public QObject
{
    Q_OBJECT
public:
    OperationsList();
    virtual ~OperationsList();

    virtual int operationCount() const = 0;
    virtual Operation operation( int index ) const = 0;

    virtual QString label()const = 0;
    virtual QString icon()const=0;

signals:

    void beforeAddOperations( const QList<Operation>& operations );
    void afterAddOpertaions();

    void beforeRemoveOperations( const QList<Operation>& operations );
    void afterRemoveOperations();
};

#endif // OPERATIONSLIST_H
