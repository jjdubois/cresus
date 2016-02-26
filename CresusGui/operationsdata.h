#ifndef OPERATIONSDATA_H
#define OPERATIONSDATA_H

#include <QObject>
#include <OperationManager.h>
#include <QMimeType>
#include <operationsmodel.h>


class ImportModule;
class QFileInfo;
class OperationsModel;
class OperationsData : public QObject
{
    Q_OBJECT
public:
    OperationsData( QObject* parent = NULL );

    Q_INVOKABLE void searchNewOperations();
    Q_INVOKABLE OperationsModel* currentModel();
private:

    void importFile( const QFileInfo& fileInfo );
    void importModules();
    void addImportModules( ImportModule* module );

    void saveOperations();


    OperationsModel m_model;
    OperationManager m_operations;
    QList<ImportModule*> m_importModules;


};

#endif // OPERATIONSDATA_H
