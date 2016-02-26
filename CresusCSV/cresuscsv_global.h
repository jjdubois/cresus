#ifndef CRESUSCSV_GLOBAL_H
#define CRESUSCSV_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CRESUSCSV_LIBRARY)
#  define CRESUSCSVSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CRESUSCSVSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CRESUSCSV_GLOBAL_H
