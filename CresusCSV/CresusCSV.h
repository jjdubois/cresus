#ifndef CRESUSCSV_H
#define CRESUSCSV_H

#include "cresuscsv_global.h"
#include <AbstractImportModule.h>

class CRESUSCSVSHARED_EXPORT ImportCresusCSV : public AbstractImportModule
{

public:
    ImportCresusCSV();
    bool importOperations(QIODevice &device, OperationManager &manager);
};

#endif // CRESUSCSV_H
