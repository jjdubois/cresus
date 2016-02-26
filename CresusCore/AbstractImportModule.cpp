#include "AbstractImportModule.h"
#include <QFileInfo>
#include <QDebug>
AbstractImportModule::AbstractImportModule( const QRegExp& regExp ) : m_rexExp( regExp )
{

}

bool AbstractImportModule::acceptFile( const QFileInfo& file )
{
    qDebug()<<m_rexExp.pattern()<<file.fileName()<<m_rexExp.exactMatch( file.fileName() );
    return m_rexExp.exactMatch( file.fileName() );
}
