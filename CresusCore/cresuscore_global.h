#ifndef CRESUSCORE_GLOBAL_H
#define CRESUSCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CRESUSCORE_LIBRARY)
#  define CRESUSCORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define CRESUSCORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CRESUSCORE_GLOBAL_H
