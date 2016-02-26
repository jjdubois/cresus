#ifndef JSONEXPORT_H
#define JSONEXPORT_H

#include <jsonmodules_global.h>

#include <ExportModule.h>

class JSONMODULESSHARED_EXPORT JSonExport : public ExportModule
{
public:
    JSonExport();

    virtual bool exportOperations(QIODevice& device, const OperationManager& manager);
    virtual QString fileExtension() const;
};

#endif // JSONEXPORT_H
