#ifndef ABSTRACTIMPORTMODULE_H
#define ABSTRACTIMPORTMODULE_H

#include <ImportModule.h>
#include <QSet>
#include <QString>

class CRESUSCORESHARED_EXPORT AbstractImportModule : public ImportModule
{    
    QList<QString> m_mimeTypes;
public:
    AbstractImportModule( const QList<QString>& extensions );
    virtual QList<QString> supportedMimeTypes();


};

#endif // ABSTRACTIMPORTMODULE_H
