#ifndef OPERATIONSMODEL_H
#define OPERATIONSMODEL_H

#include <QAbstractListModel>
#include <OperationsList.h>

class OperationsModel : public QAbstractListModel
{
    Q_OBJECT

    OperationsList* m_operationsList;

public:
    explicit OperationsModel(QObject *parent = 0);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    OperationsList *operationsList() const;
    Q_INVOKABLE void setOperationsList(OperationsList *operationsList);
};

#endif // OPERATIONSMODEL_H
