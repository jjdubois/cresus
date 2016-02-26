#ifndef ABSTRACTIMPORTMODULE_H
#define ABSTRACTIMPORTMODULE_H

#include <ImportModule.h>
#include <QSet>
#include <QString>
#include <QRegExp>

class CRESUSCORESHARED_EXPORT AbstractImportModule : public ImportModule
{    
    QRegExp m_rexExp;
public:
    AbstractImportModule( const QRegExp& regExp );
    bool acceptFile( const QFileInfo& file );
};

#endif // ABSTRACTIMPORTMODULE_H
