#ifndef OPERATIONDATA_H
#define OPERATIONDATA_H

#include <cresuscore_global.h>
#include <QDate>
#include <QVariantMap>

class CRESUSCORESHARED_EXPORT OperationData
{
public:
    OperationData();
    OperationData( int value, QDate date, QString label );

    bool isNew() const;
    void setIsNew(bool value);

    int value() const;
    void setValue(int value);

    QDate date() const;
    void setDate(const QDate& date);

    QString label() const;
    void setLabel(const QString& label);

    OperationData& operator<<(const QVariantMap& arg);
    QVariantMap& operator>>(QVariantMap& arg);

private:
    bool m_isNew;
    int m_value;
    QDate m_date;
    QString m_label;
};

#endif // OPERATIONDATA_H
