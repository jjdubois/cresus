#include "operationsdata.h"

#include <QStandardPaths>
#include <QFile>
#include <QMimeDatabase>
#include <QFileInfo>
#include <QDir>

#include <jsonimport.h>
#include <BPCsvImportModule.h>
#include <ImportModule.h>

#include <QDebug>
OperationsData::OperationsData(QObject *parent) : QObject(parent)
{

    importModules();
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    dataPath += QString("/data.json");
    qDebug()<<dataPath;

    QFile file( dataPath );
    if( file.open( QIODevice::ReadOnly ) )
    {
        JSonImport import;
        if( !import.importOperations( file, m_operations ) )
        {
            qWarning() << "Cannot import operations " << dataPath;
        }
    }
    else
    {
        qWarning() << "Cannot open file " << dataPath;
    }
}

void OperationsData::searchNewOperations()
{
    QStringList dataPath = QStandardPaths::standardLocations(QStandardPaths::DownloadLocation);

    dataPath<<"C:/Documents and Settings/An'so/Mes documents";
    dataPath<<"I:/Data";

    qDebug()<<dataPath;
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

void OperationsData::importFile(const QFileInfo& fileInfo)
{
    QMimeDatabase database;
    QMimeType fileType = database.mimeTypeForFile(fileInfo.filePath());
    QList<ImportModule*> modules;
    // Perfect match
    Q_FOREACH(ImportModule* module, m_importModules)
    {
        Q_FOREACH(const QString& mimeName, module->supportedMimeTypes() )
        {
            QMimeType type = database.mimeTypeForName( mimeName );            
            if( fileType.name() == type.name() || fileType.aliases().contains( type.name() ) )
            {
                modules.append( module );
            }
        }
    }
    // Inherits
    if( modules.isEmpty() )
    {
    Q_FOREACH(ImportModule* module, m_importModules)
    {
        Q_FOREACH(const QString& mimeName, module->supportedMimeTypes() )
        {
            QMimeType type = database.mimeTypeForName( mimeName );            
            if( fileType.inherits(type.name()) )
            {
                modules.append( module );
            }
        }
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
}

void OperationsData::addImportModules(ImportModule* module)
{
    m_importModules.append( module );
}

void OperationsData::saveOperations()
{

}
