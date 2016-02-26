#ifndef BPCSVIMPORTMODULE_H
#define BPCSVIMPORTMODULE_H

#include "bpcsvimportmodule_global.h"

#include <AbstractImportModule.h>

#include <QString>

class BPCSVIMPORTMODULESHARED_EXPORT BPCsvImportModule : public AbstractImportModule
{
public:
    BPCsvImportModule();
    virtual bool importOperations( QIODevice& device, OperationManager& manager );
};

#endif // BPCSVIMPORTMODULE_H
