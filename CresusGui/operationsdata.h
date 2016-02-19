#ifndef OPERATIONSDATA_H
#define OPERATIONSDATA_H

#include <QObject>
#include <OperationManager.h>
#include <QMimeType>


class ImportModule;
class QFileInfo;
class OperationsData : public QObject
{
    Q_OBJECT
public:
    OperationsData( QObject* parent = NULL );

    Q_INVOKABLE void searchNewOperations();
private:

    void importFile( const QFileInfo& fileInfo );
    void importModules();
    void addImportModules( ImportModule* module );

    void saveOperations();


    OperationManager m_operations;
    QList<ImportModule*> m_importModules;
    //QMap< QString, QSet<ImportModule*> >m_importModulesMimeTypes;

};

#endif // OPERATIONSDATA_H
