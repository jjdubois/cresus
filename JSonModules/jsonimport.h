#ifndef JSONIMPORT_H
#define JSONIMPORT_H

#include <jsonmodules_global.h>
#include <AbstractImportModule.h>

#include <QIODevice>

class JSONMODULESSHARED_EXPORT JSonImport : public AbstractImportModule
{

public:
    JSonImport();

    virtual bool importOperations(QIODevice& device, OperationManager& manager );
};

#endif // JSONIMPORT_H
