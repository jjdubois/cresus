#include "BPCsvImportModule.h"

#include <OperationManager.h>
#include <QFile>
#include <QDebug>
BPCsvImportModule::BPCsvImportModule()
{
}

QString BPCsvImportModule::fileName() const
{
    return m_fileName;
}

void BPCsvImportModule::setFileName(const QString &fileName)
{
    m_fileName = fileName;
}

bool BPCsvImportModule::importOperations(OperationManager *manager)
{
    QFile file( m_fileName );
    if( file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        while (!file.atEnd())
        {
               QString line = file.readLine().trimmed();
               if( !line.startsWith("#") )
               {
                    QStringList lines = line.split(";");
                    qDebug()<<"Here "<<lines.size();
               }
        }
        return true;
    }
    else
    {
        return false;
    }
}
