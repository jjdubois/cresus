#ifndef IMPORTMODULE_H
#define IMPORTMODULE_H

#include <cresuscore_global.h>

class OperationManager;

class CRESUSCORESHARED_EXPORT ImportModule
{
public:
    ImportModule();
    virtual ~ImportModule();
    virtual bool importOperations( OperationManager& manager ) = 0;
};

#endif // IMPORTMODULE_H
