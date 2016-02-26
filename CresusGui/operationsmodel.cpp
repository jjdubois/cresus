#include "operationsmodel.h"
#include <OperationsUtils.h>
#include <QDebug>
OperationsList *OperationsModel::operationsList() const
{
    return m_operationsList;
}

void OperationsModel::setOperationsList(OperationsList *operationsList)
{
    beginResetModel();
    if( m_operationsList != NULL )
    {
        disconnect( m_operationsList );
    }
    m_operationsList = operationsList;
    if( m_operationsList != NULL )
    {
        connect( m_operationsList, &OperationsList::beforeAddOperations, this , &OperationsModel::beforeAddOperations );
        connect( m_operationsList, &OperationsList::afterAddOperations, this , &OperationsModel::afterAddOperations );

        connect( m_operationsList, &OperationsList::beforeRemoveOperations, this , &OperationsModel::beforeRemoveOperations );
        connect( m_operationsList, &OperationsList::afterRemoveOperations, this , &OperationsModel::afterRemoveOperations );
    }
    endResetModel();
}

QHash<int, QByteArray> OperationsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IsNew] = "operation_isNew";
    roles[Value] = "operation_value";
    roles[Date] = "operation_date";
    roles[Label] = "operation_label";
    roles[Account] = "operation_account";
    return roles;
}

void OperationsModel::beforeAddOperations()
{
    beginResetModel();
}

void OperationsModel::afterAddOperations(const QList<Operation>& operations)
{
    endResetModel();
}

void OperationsModel::beforeRemoveOperations(const QList<Operation>& operations)
{
    beginResetModel();
}

void OperationsModel::afterRemoveOperations()
{
    endResetModel();
}

OperationsModel::OperationsModel(QObject *parent)
    : QAbstractListModel(parent),
      m_operationsList( NULL )
{
}

int OperationsModel::rowCount(const QModelIndex &parent) const
{
    if ( m_operationsList == NULL )
        return 0;

    return m_operationsList->operationCount();
}

QVariant OperationsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || m_operationsList == NULL)
        return QVariant();

    Operation op = m_operationsList->operation( index.row() );
    switch ( role ) {
    case IsNew:
        return op.isNew();
    break;
    case Value:
        return Cresus::doubleFromAmount(op.value());
    break;
    case Date:
        return op.date().toString("dd/MM/yyyy");
    break;
    case Account:
        return op.account();
    break;
    case Qt::DisplayRole:
    case Label:
        return op.label();
    break;
    default:
        return QVariant();
    }
}
