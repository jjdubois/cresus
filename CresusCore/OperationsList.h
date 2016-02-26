#ifndef OPERATIONSLIST_H
#define OPERATIONSLIST_H

#include <cresuscore_global.h>
#include <Operation.h>
#include <QObject>

class CRESUSCORESHARED_EXPORT OperationsList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)
public:

    OperationsList( QObject* parent = NULL );
    virtual ~OperationsList();

    virtual int operationCount() const = 0;
    virtual Operation operation( int index ) const = 0;
    virtual void addOperation( const Operation& operation ) = 0;
    virtual void removeOperation( int index ) = 0;
    void removeOperation( const Operation& operation );

    virtual QString label()const = 0;
    virtual void setLabel( const QString & label ) = 0;
    virtual QString icon()const=0;
    virtual void setIcon( const QString & iconPath ) = 0;

    virtual OperationsList* parent() const= 0;

    virtual int childrenCount() const = 0;
    virtual OperationsList* child( int index ) const = 0;

    virtual bool contains( const Operation& operation ) const = 0;
    virtual int index( const Operation& operation ) const = 0;

    virtual OperationsList* createChild( ) = 0;
    virtual void removeChild( int index ) = 0;

    QList<OperationsList*> findClusters( const QString& label ) const;
    OperationsList* findCluster( const QString& label ) const;

signals:

    void beforeAddOperations();
    void afterAddOperations( const QList<Operation>& operations );

    void beforeRemoveOperations( const QList<Operation>& operations );
    void afterRemoveOperations();

    void beforeAddCategory();
    void afterAddCategory( OperationsList* category );

    void beforeRemoveCategory( OperationsList* category );
    void afterRemoveCategory();    

    void labelChanged( const QString& label );
    void iconChanged( const QString& icon );
};

#endif // OPERATIONSLIST_H
