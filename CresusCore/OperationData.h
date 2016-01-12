#ifndef OPERATIONDATA_H
#define OPERATIONDATA_H

#include <cresuscore_global.h>
#include <QDate>
#include <QVariantMap>

class CRESUSCORESHARED_EXPORT OperationData
{
public:
    OperationData();
    OperationData( QDate date, const QString& label, int value, const QString& account );

    bool isNew() const;
    void setIsNew(bool value);

    int value() const;

    QDate date() const;

    QString label() const;

    OperationData& operator<<(const QVariantMap& arg);
    QVariantMap& operator>>(QVariantMap& arg);

    QString account() const;

private:
    bool m_isNew;
    int m_value;
    QDate m_date;
    QString m_label;
    QString m_account;
};

#endif // OPERATIONDATA_H
