#ifndef BPCSVIMPORTMODULE_GLOBAL_H
#define BPCSVIMPORTMODULE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BPCSVIMPORTMODULE_LIBRARY)
#  define BPCSVIMPORTMODULESHARED_EXPORT Q_DECL_EXPORT
#else
#  define BPCSVIMPORTMODULESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BPCSVIMPORTMODULE_GLOBAL_H
