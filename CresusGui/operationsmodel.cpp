#include "operationsmodel.h"

OperationsList *OperationsModel::operationsList() const
{
    return m_operationsList;
}

void OperationsModel::setOperationsList(OperationsList *operationsList)
{
    beginResetModel();
    m_operationsList = operationsList;
    endResetModel();
}

OperationsModel::OperationsModel(QObject *parent)
    : QAbstractListModel(parent),
      m_operationsList( NULL )
{
}

int OperationsModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid() || m_operationsList == NULL)
        return 0;

    return m_operationsList->operationCount();
}

QVariant OperationsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
