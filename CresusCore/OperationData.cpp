#include "OperationData.h"

OperationData::OperationData()
{

}

OperationData::OperationData(QDate date, const QString& label, int value, const QString& account)
    : m_isNew(true)
    , m_value(value)
    , m_date(date)
    , m_label(label)
    , m_account(account)
{

}

bool OperationData::isNew() const
{
    return m_isNew;
}

void OperationData::setIsNew(bool value)
{
    m_isNew = value;
}

int OperationData::value() const
{
    return m_value;
}

QDate OperationData::date() const
{
    return m_date;
}

QString OperationData::label() const
{
    return m_label;
}

QString OperationData::account() const
{
    return m_account;
}

OperationData& OperationData::operator<<(const QVariantMap& arg)
{
    m_isNew = arg.value("isNew",false).toBool();
    m_value = arg.value("value",0).toInt();
    m_date = arg.value("date",QDate()).toDate();
    m_label = arg.value("label",QString()).toString();
    m_account = arg.value("account",QString()).toString();

    return *this;
}

QVariantMap&OperationData::operator>>(QVariantMap& arg)
{
    arg["isNew"] = m_isNew;
    arg["value"] = m_value;
    arg["date"] = m_date;
    arg["label"] = m_label;
    arg["account"] = m_account;

    return arg;
}
