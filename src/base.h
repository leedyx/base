#ifndef _BASE_BASE_H
#define _BASE_BASE_H

#include <cstdlib>
#include <cstring>

#define BASE_DO_STRINGIFY(x) #x
#define BASE_STRINGIFY(x) BASE_DO_STRINGIFY(x)

#define BASE_DO_JOIN2(x, y) x##y
#define BASE_DO_JOIN1(x, y) BASE_DO_JOIN2(x, y)
#define BASE_JOIN(x, y) BASE_DO_JOIN1(x, y)

#ifndef BASE_NAMESPACE
#define BASE_NAMESPACE base
#endif // !BASE_NAMESPACE

#ifndef BASE_NAMESPACE_BEGIN
#define BASE_NAMESPACE_BEGIN namespace BASE_NAMESPACE {
#endif

#ifndef BASE_NAMESPACE_END
#define BASE_NAMESPACE_END }
#endif

#ifndef BASE_ASSERT
#include <cassert>
#define BASE_ASSERT(x) assert(x)
#endif // !BASE_ASSERT

#define BASE_VERSION_CODE(x, y, z) (((x)*100000) + ((y)*100) + (z))

#if defined(__GNUC__)
#define COMPILER_GCC
#define BASE_GCC                                                               \
  BASE_VERSION_CODE(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#endif

#ifndef BASE_FORCEINLINE
#if defined(COMPILER_GCC) && !defined(NDEBUG)
#define BASE_FORCEINLINE __attribute__((always_inline))
#endif
#endif

#if (__clang__) ||                                                             \
    (defined(COMPILER_GCC) && BASE_GCC >= BASE_VERSION_CODE(4, 6, 0))
#define BASE_PRAGMA(x) _Pragma(BASE_STRINGIFY(x))
#define BASE_MESSAGE(x) BASE_PRAGMA(message(BASE_DO_STRINGIFY(x)))
#define BASE_TODO(x) BASE_MESSAGE(TODO-- x)
#define BASE_DIAG_PRAGMA(x) BASE_PRAGMA(GCC diagnostic x)
#define BASE_DIAG_OFF(x)                                                       \
  BASE_DIAG_PRAGMA(ignored BASE_STRINGIFY(BASE_JOIN(-W, x)))

#define BASE_DIAG_PUSH BASE_DIAG_PRAGMA(push)
#define BASE_DIAG_POP BASE_DIAG_PRAGME(pop)
#endif

#endif // !_BASE_BASE_H
