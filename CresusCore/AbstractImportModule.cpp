#include "AbstractImportModule.h"

AbstractImportModule::AbstractImportModule(const QList<QString>& extensions  ) : m_mimeTypes( extensions )
{

}

QList<QString> AbstractImportModule::supportedMimeTypes()
{
    return m_mimeTypes;
}
