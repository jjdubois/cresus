#include "operationsdata.h"

#include <QStandardPaths>
#include <QFile>

#include <jsonimport.h>

#include <QDebug>
OperationsData::OperationsData(QObject *parent) : QObject(parent)
{
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    dataPath += QString("/data.json");
    qDebug()<<dataPath;

    QFile file( dataPath );
    if( file.open( QIODevice::ReadOnly ) )
    {
        JSonImport import;
        import.setIo( &file );
        if( !import.importOperations( m_operations ) )
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
    qDebug()<<dataPath;
}
