#ifndef SIMPLECRYPT_GLOBAL_H
#define SIMPLECRYPT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIMPLECRYPT_LIBRARY)
#  define SIMPLECRYPTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SIMPLECRYPTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SIMPLECRYPT_GLOBAL_H
