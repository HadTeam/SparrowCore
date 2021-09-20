#ifndef SPARROWCORE_GLOBAL_H
#define SPARROWCORE_GLOBAL_H

#include <QtCore/qglobal.h>
#include "utils.h"

#ifdef SPARROWCORE_LIBRARY
#  define SPARROWCORE_EXPORT Q_DECL_EXPORT
#else
#  define SPARROWCORE_EXPORT Q_DECL_IMPORT
#endif

#endif // SPARROWCORE_GLOBAL_H