#include "BPCsvImportModule.h"

#include <OperationsUtils.h>
#include <OperationManager.h>
#include <QFile>
#include <QDebug>
#include <QIODevice>
BPCsvImportModule::BPCsvImportModule(): AbstractImportModule( QList<QString>()<<"text/csv" )
{
}

bool BPCsvImportModule::importOperations(QIODevice& device, OperationManager& manager)
{    
    //ignore first line
    device.readLine();
        while (!device.atEnd())
        {
               QString line = device.readLine().trimmed();
               if( !line.startsWith("#") )
               {
                    QStringList lines = line.split(";");
                    qDebug()<<"Here "<<lines.size();
                    if( lines.size() >= 7 )
                    {
                        QString account = lines[0];
                        QDate dateLabel = QDate::fromString( lines[1], "dd/MM/yyyy" );
                        QString label = lines[3];
                        bool convertionWork;
                        int amount = Cresus::amountFromDouble( lines[6].replace(",",".").toDouble( &convertionWork) );
                        if( convertionWork && dateLabel.isValid() && !account.isEmpty())
                        {
                            OperationData operation( dateLabel, label, amount, account );
                            manager.addOperation( operation );
                        }
                    }
               }
        }
        return true;
}
