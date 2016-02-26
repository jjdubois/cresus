#include "operationsdata.h"

#include <QStandardPaths>
#include <QFile>
#include <QMimeDatabase>
#include <QFileInfo>
#include <QDir>

#include <jsonimport.h>
#include <jsonexport.h>
#include <BPCsvImportModule.h>
#include <ImportModule.h>
#include <CresusCSV.h>
#include <QDebug>

OperationsData::OperationsData(QObject *parent) : QObject(parent)
{

    importModules();
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    dataPath += QString("/data.json");

    QFile file( dataPath );
    if( file.open( QIODevice::ReadOnly ) )
    {
        JSonImport import;
        if( !import.importOperations( file, m_operations ) )
        {
            qWarning() << "Error importing operations " << dataPath;
        }
        file.close();
    }
    else
    {
        qWarning() << " Read : cannot open file " << dataPath;
    }

    m_model.setOperationsList( &m_operations );

    searchNewOperations();
}

void OperationsData::searchNewOperations()
{
    QStringList dataPath = QStandardPaths::standardLocations(QStandardPaths::DownloadLocation);

    dataPath<<"C:/Documents and Settings/An'so/Mes documents";
    dataPath<<"I:/Data";

    QList<Operation> oldNewOperations;

    for( int i = 0 ; i < m_operations.operationCount() ; ++i )
    {
        oldNewOperations<<m_operations.operation( i );
    }

    Q_FOREACH( QString path, dataPath )
    {
        QDir curDir( path );
        Q_FOREACH(QFileInfo fileName, curDir.entryInfoList())
        {
            importFile( fileName );
        }
    }

    saveOperations();
}

OperationsModel*OperationsData::currentModel()
{
    return &m_model;
}

void OperationsData::importFile(const QFileInfo& fileInfo)
{
    QList<ImportModule*> modules;
    // Perfect match
    Q_FOREACH(ImportModule* module, m_importModules)
    {
        if( module->acceptFile( fileInfo ) )
        {
            modules.append( module );
        }
    }
    if(modules.size() == 1)
    {
        QFile f(fileInfo.filePath());
        if( f.open(QIODevice::ReadOnly))
        {
            modules.first()->importOperations(f,m_operations);
        }else
        {
            //error
        }
    }
    else
    {
        //Error
    }
}

void OperationsData::importModules()
{
    addImportModules( new BPCsvImportModule() );
    addImportModules( new JSonImport );
    addImportModules( new ImportCresusCSV );
}

void OperationsData::addImportModules(ImportModule* module)
{
    m_importModules.append( module );
}

void OperationsData::saveOperations()
{

    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    dataPath += QString("/data.json");
    QFile file( dataPath );
    QFileInfo fileInfo( dataPath );
    QDir dir( fileInfo.path() );
    dir.mkpath( fileInfo.path() );
    if( file.open( QIODevice::WriteOnly ) )
    {
        JSonExport exp;
        if( !exp.exportOperations( file, m_operations ) )
            qWarning() << "Error exporting operations " << dataPath;

        file.close();
    }  else
    {
        qWarning() << "Cannot open file " << dataPath;
    }
}
