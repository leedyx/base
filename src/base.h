#ifndef _BASE_BASE_H
#define _BASE_BASE_H

#include<cstdlib>
#include<cstring>

#define BASE_DO_STRINGIFY(x) #x
#define BASE_STRINGIFY(x)  BASE_DO_STRINGIFY(x)

#define BASE_DO_JOIN2(x,y)    x ## y
#define BASE_DO_JOIN1(x,y)    BASE_DO_JOIN2(x,y)
#define BASE_JOIN(x,y)        BASE_DO_JOIN1(x,y)

#ifndef BASE_NAMESPACE
#define BASE_NAMESPACE  base
#endif // !BASE_NAMESPACE

#ifndef BASE_NAMESPACE_BEGIN 
#define BASE_NAMESPACE_BEGIN namespace BASE_NAMESPACE {
#endif

#ifndef BASE_NAMESPACE_END
#define BASE_NAMESPACE_END }
#endif

#endif // !_BASE_BASE_H
