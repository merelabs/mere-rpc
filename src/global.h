#ifndef MERE_JSON_RPC_LIB_GLOBAL_H
#define MERE_JSON_RPC_LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MERE_JSON_RPC_LIB)
#  define MERE_JSON_RPC_LIB_SPEC Q_DECL_EXPORT
#else
#  define MERE_JSON_RPC_LIB_SPEC Q_DECL_IMPORT
#endif

#endif // MERE_JSON_RPC_LIB_GLOBAL_H
