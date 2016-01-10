#include "OperationData.h"

OperationData::OperationData()
{

}

OperationData::OperationData(int value, QDate date, QString label)
    : m_isNew(true)
    , m_value(value)
    , m_date(date)
    , m_label(label)
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

void OperationData::setValue(int value)
{
    m_value = value;
}

QDate OperationData::date() const
{
    return m_date;
}

void OperationData::setDate(const QDate& date)
{
    m_date = date;
}

QString OperationData::label() const
{
    return m_label;
}

void OperationData::setLabel(const QString& label)
{
    m_label = label;
}

OperationData& OperationData::operator<<(const QVariantMap& arg)
{
    m_isNew = arg.value("isNew",false).toBool();
    m_value = arg.value("value",0).toInt();
    m_date = arg.value("date",QDate()).toDate();
    m_label = arg.value("label",QString()).toString();

    return *this;
}

QVariantMap&OperationData::operator>>(QVariantMap& arg)
{
    arg["isNew"] = m_isNew;
    arg["value"] = m_value;
    arg["date"] = m_date;
    arg["label"] = m_label;

    return arg;
}
