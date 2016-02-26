#ifndef OPERATION_H
#define OPERATION_H

#include <cresuscore_global.h>
#include <QDate>
#include <QString>
#include <QVariantMap>

class OperationData;
class OperationManager;

class CRESUSCORESHARED_EXPORT Operation
{
public:
    Operation();
    Operation( OperationManager&, OperationData& data );

    bool isNew() const;
    int value() const;
    QDate date() const;
    QString label() const;
    QString account() const;

    bool isNull()const;

    bool operator==(const Operation& other)const;

    QVariantMap& operator>>(QVariantMap& arg);

private:
    OperationManager* m_manager;
    OperationData* m_data;
};

#endif // OPERATION_H
