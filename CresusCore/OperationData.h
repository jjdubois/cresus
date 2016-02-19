#ifndef OPERATIONDATA_H
#define OPERATIONDATA_H

#include <cresuscore_global.h>
#include <QDate>
#include <QVariantMap>
#include <QMetaType>
#include <QHash>
#include <QString>

class CRESUSCORESHARED_EXPORT OperationData
{
public:
    OperationData();
    OperationData( QDate date, const QString& label, int value, const QString& account );

    bool isNew() const;
    void setIsNew(bool value);

    int value() const;

    const QDate& date() const;

    const QString& label() const;

    OperationData& operator<<(const QVariantMap& arg);
    QVariantMap& operator>>(QVariantMap& arg);

    QString account() const;

    bool operator==(const OperationData& other)const;

private:
    bool m_isNew;
    int m_value;
    QDate m_date;
    QString m_label;
    QString m_account;
};

CRESUSCORESHARED_EXPORT QDebug& operator<<( QDebug& debug, const OperationData& data );

inline uint qHash(const OperationData &key, uint seed)
{
    return qHash(key.label(), seed) ^ key.date().day();
}

Q_DECLARE_METATYPE(OperationData)

#endif // OPERATIONDATA_H
