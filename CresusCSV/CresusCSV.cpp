#include "CresusCSV.h"
#include <QIODevice>
#include <QDate>
#include <OperationsUtils.h>
#include <OperationData.h>
#include <Operation.h>
#include <OperationManager.h>
#include <QDebug>

ImportCresusCSV::ImportCresusCSV():AbstractImportModule( QRegExp(".*\\.cresus") )
{
}

bool ImportCresusCSV::importOperations(QIODevice &device, OperationManager &manager)
{
    //ignore first line
    device.readLine();
    while (!device.atEnd())
    {
        QString line = device.readLine().trimmed();
        if( !line.startsWith("#") )
        {
            QStringList lines = line.split(";");
            if( lines.size() >= 10 )
            {
                QString account = lines[0];
                qDebug()<<lines[2];
                QDate dateLabel = QDate::fromString( lines[2], "yyyy-MM-dd" );
                QString label = lines[5];
                bool convertionWork;
                int amount = Cresus::amountFromDouble( lines[6].replace(",",".").toDouble( &convertionWork) );
                QString categories = lines[9];
                qDebug()<<"Here "<< convertionWork << dateLabel.isValid() << !account.isEmpty();
                if( convertionWork && dateLabel.isValid() && !account.isEmpty())
                {
                    QStringList categoriesList = categories.split("/");
                    qDebug()<<"Here "<<categories<<categoriesList;
                    OperationData operationData( dateLabel, label, amount, account );
                    Operation operation = manager.addOperation( operationData );
                    OperationsList* cluster = manager.findCluster( categoriesList, true );
                    cluster->addOperation( operation );
                }
            }
        }
    }
    return true;
}
