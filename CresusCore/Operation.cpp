#include "Operation.h"

#include <OperationData.h>
#include <QVariantMap>

Operation::Operation()
    : m_manager( NULL )
    , m_data( NULL )
{

}

Operation::Operation(OperationManager& manager, OperationData& data)
    : m_manager(&manager)
    , m_data(&data)
{    
}

bool Operation::isNew() const
{
    return m_data != NULL ? m_data->isNew() : false;
}

int Operation::value() const
{
    return m_data != NULL ? m_data->value() : 0;
}

QDate Operation::date() const
{
    return m_data != NULL ? m_data->date() : QDate();
}

QString Operation::label() const
{
    return m_data != NULL ? m_data->label() : QString();
}

QString Operation::account() const
{
    return m_data != NULL ? m_data->account() : QString();
}

bool Operation::isNull() const
{
    return m_data == NULL || m_manager == NULL;
}

bool Operation::operator==(const Operation& other) const
{
    return ((this->isNull() || other.isNull()) ? false : this->m_manager == other.m_manager && this->m_data == other.m_data);
}

QVariantMap& Operation::operator>>(QVariantMap& arg)
{
    if( m_data )
        *m_data >> arg;
    return arg;
}
