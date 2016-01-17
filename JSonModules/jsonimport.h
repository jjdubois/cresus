#ifndef JSONIMPORT_H
#define JSONIMPORT_H

#include <jsonmodules_global.h>
#include <ImportModule.h>

#include <QIODevice>

class JSONMODULESSHARED_EXPORT JSonImport : public ImportModule
{

    QIODevice* m_io;

public:
    JSonImport();

    virtual bool importOperations( OperationManager& manager );
    QIODevice *io() const;
    void setIo(QIODevice *io);
};

#endif // JSONIMPORT_H
