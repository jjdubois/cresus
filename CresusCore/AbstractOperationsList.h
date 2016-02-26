#ifndef ABSTRACTOPERATIONSLIST_H
#define ABSTRACTOPERATIONSLIST_H

#include <OperationsList.h>
#include <QString>

template< class T >
class AbstractOperationsList : public OperationsList
{
    QString m_label;
    QString m_icon;
public:
    AbstractOperationsList( OperationsList* parent );

    QString label() const;
    void setLabel(const QString& label);
    QString icon() const;
    void setIcon(const QString& iconPath);

    virtual int operationCount() const;
    virtual Operation operation(int index) const;

    OperationsList* parent()const;
    int childrenCount() const;
    OperationsList *child(int index) const;

    virtual bool contains( const Operation& operation ) const;
    virtual int index( const Operation& operation ) const;


protected:
    void addOperation( const QList<Operation>& operation );
    void removeOperation( const QList<Operation>& operation );


    void addOperationList( T& operationsList );
    void removeOperationList( T& operation );

    QList<Operation> m_operations;
    QList<T*> m_operationsLists;
    OperationsList* m_parent;


};


template< class T >
AbstractOperationsList<T>::AbstractOperationsList( OperationsList* parent ):OperationsList(parent), m_parent( parent )
{

}

template< class T >
QString AbstractOperationsList<T>::label() const{
    return m_label;
}

template< class T >
QString AbstractOperationsList<T>::icon() const{
    return m_icon;
}

template< class T >
OperationsList* AbstractOperationsList<T>::parent() const
{
    return m_parent;
}

template< class T >
int AbstractOperationsList<T>::operationCount() const
{
    return m_operations.size();
}

template< class T >
Operation AbstractOperationsList<T>::operation(int index) const
{
    if( index < operationCount() && index > -1 )
    {
        return m_operations[index];
    }
    else
    {
        return Operation();
    }
}

template< class T >
int AbstractOperationsList<T>::childrenCount() const
{
    return m_operationsLists.count();
}

template< class T >
OperationsList *AbstractOperationsList<T>::child(int index) const
{
    if( index < childrenCount() && index > -1 )
    {
        return m_operationsLists[index];
    }
    else
    {
        return NULL;
    }
}

template< class T >
void AbstractOperationsList<T>::addOperation(const QList<Operation>& operations)
{
    emit beforeAddOperations();
    m_operations.append( operations );
    emit afterAddOperations( operations );
}

template< class T >
void AbstractOperationsList<T>::removeOperation(const QList<Operation>& operations )
{
    emit beforeRemoveOperations( operations );
    Q_FOREACH( const Operation& op , operations )
    {
        m_operations.removeAll( op );
    }

    emit afterRemoveOperations();
}

template< class T >
void AbstractOperationsList<T>::addOperationList( T& operationsList ){
    beforeAddCategory();
    m_operationsLists.append( &operationsList );
    afterAddCategory( &operationsList );
}

template< class T >
void AbstractOperationsList<T>::removeOperationList( T& operationsList ){
    beforeRemoveCategory( &operationsList );
    m_operationsLists.removeAll( &operationsList );
    afterRemoveCategory();
}

template< class T >
void AbstractOperationsList<T>::setLabel(const QString& label)
{
    if( m_label != label )
    {
        m_label = label;
        emit labelChanged( m_label );
    }
}

template< class T >
void AbstractOperationsList<T>::setIcon(const QString& iconPath)
{
    if( iconPath != m_icon)
    {
        m_icon = iconPath;
        emit iconChanged( m_icon );
    }

}

template< class T >
bool AbstractOperationsList<T>::contains( const Operation& operation ) const
{
    return m_operations.contains( operation );
}

template< class T >
int AbstractOperationsList<T>::index( const Operation& operation ) const
{
    return m_operations.indexOf( operation );
}

#endif // ABSTRACTOPERATIONSLIST_H
