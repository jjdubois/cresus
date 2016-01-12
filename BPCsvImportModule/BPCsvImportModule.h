#ifndef BPCSVIMPORTMODULE_H
#define BPCSVIMPORTMODULE_H

#include "bpcsvimportmodule_global.h"
#include <ImportModule.h>

class BPCSVIMPORTMODULESHARED_EXPORT BPCsvImportModule : public ImportModule
{

public:
    BPCsvImportModule();

    virtual bool importOperations(OperationManager *manager);
};

#endif // BPCSVIMPORTMODULE_H
