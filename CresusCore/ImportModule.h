#ifndef IMPORTMODULE_H
#define IMPORTMODULE_H

#include <cresuscore_global.h>

#include <QString>

class OperationManager;
class QIODevice;

class CRESUSCORESHARED_EXPORT ImportModule
{
public:
    ImportModule();
    virtual ~ImportModule();
    virtual bool importOperations( QIODevice& device, OperationManager& manager ) = 0;
    virtual QList<QString> supportedMimeTypes() =0;
};

#endif // IMPORTMODULE_H
