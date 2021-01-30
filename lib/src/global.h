#ifndef MERE_RPC_LIB_GLOBAL_H
#define MERE_RPC_LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MERE_RPC_LIB)
#  define MERE_RPC_LIB_SPEC Q_DECL_EXPORT
#else
#  define MERE_RPC_LIB_SPEC Q_DECL_IMPORT
#endif

#endif // MERE_RPC_LIB_GLOBAL_H
