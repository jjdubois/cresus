#ifndef EXPORTMODULE_H
#define EXPORTMODULE_H

#include <cresuscore_global.h>

#include <QString>

class OperationManager;
class QIODevice;
class QFileInfo;

class CRESUSCORESHARED_EXPORT ExportModule
{
public:
    ExportModule();
    virtual ~ExportModule();
    virtual bool exportOperations( QIODevice& device, const OperationManager& manager ) = 0;
    virtual QString fileExtension() const = 0;
};

#endif // EXPORTMODULE_H

