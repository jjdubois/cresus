#include "NewOperationsModel.h"
#include <operationsmodel.h>
NewOperationsModel::NewOperationsModel(QObject *parent):QSortFilterProxyModel(parent)
{
    setDynamicSortFilter( true );
}

bool NewOperationsModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex ind = sourceModel()->index( source_row, 0, source_parent );
    return ind.data( OperationsModel::IsNew ).toBool();
}
