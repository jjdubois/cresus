#ifndef NEWOPERATIONSMODEL_H
#define NEWOPERATIONSMODEL_H

#include <QSortFilterProxyModel>

class NewOperationsModel : public QSortFilterProxyModel
{
public:
    NewOperationsModel(QObject *parent = NULL);

protected:
    virtual bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

};

#endif // NEWOPERATIONSMODEL_H
