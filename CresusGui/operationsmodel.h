#ifndef OPERATIONSMODEL_H
#define OPERATIONSMODEL_H

#include <QAbstractListModel>
#include <OperationsList.h>

class OperationsModel : public QAbstractListModel
{
    Q_OBJECT

    OperationsList* m_operationsList;

public:

    enum OperationRole{
        IsNew = Qt::UserRole + 1,
        Value,
        Date,
        Label,
        Account
    };

    explicit OperationsModel(QObject *parent = 0);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    OperationsList *operationsList() const;
    Q_INVOKABLE void setOperationsList(OperationsList *operationsList);

    virtual QHash<int, QByteArray>	roleNames() const;
private slots:

    void beforeAddOperations();
    void afterAddOperations( const QList<Operation>& operations );

    void beforeRemoveOperations( const QList<Operation>& operations );
    void afterRemoveOperations();
};

#endif // OPERATIONSMODEL_H
