#pragma once

#include <QtGlobal>

#if defined(DBGUILIB_LIBRARY)
#  define DBGUILIB_EXPORT Q_DECL_EXPORT
#else
#  define DBGUILIB_EXPORT Q_DECL_IMPORT
#endif
