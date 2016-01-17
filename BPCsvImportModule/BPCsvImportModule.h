#ifndef BPCSVIMPORTMODULE_H
#define BPCSVIMPORTMODULE_H

#include "bpcsvimportmodule_global.h"

#include <ImportModule.h>

#include <QString>

class BPCSVIMPORTMODULESHARED_EXPORT BPCsvImportModule : public ImportModule
{

    QString m_fileName;
public:
    BPCsvImportModule();

    QString fileName()const;
    void setFileName( const QString& fileName );

    virtual bool importOperations(OperationManager *manager);
};

#endif // BPCSVIMPORTMODULE_H
