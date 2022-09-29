/*
 * shortnum.h: Shortened numerical types for convenience
 * This is free and unencumbered software released into the public domain
 */

#ifndef SHORTNUM_H
#define SHORTNUM_H

#ifdef __cplusplus 
extern "C" {
#endif

#include <stdint.h>

/* Support for custom prefixes */
#ifndef SHORTNUM_SIGNED_PREFIX
#define SHORTNUM_SIGNED_PREFIX s
#endif
#ifndef SHORTNUM_UNSIGNED_PREFIX
#define SHORTNUM_UNSIGNED_PREFIX u
#endif
#ifndef SHORTNUM_FLOAT_PREFIX
#define SHORTNUM_FLOAT_PREFIX f
#endif

/* Internal macros required for custom prefix support*/
#define __SHORTNUM_EVAL(__prefix, __bitsize)    __prefix##__bitsize
#define __SHORTNUM_COMBINE(__prefix, __bitsize) __SHORTNUM_EVAL(__prefix, __bitsize)
#define __SHORTNUM_PREPEND_SIGNED(__bitsize)    __SHORTNUM_COMBINE(SHORTNUM_SIGNED_PREFIX, __bitsize)
#define __SHORTNUM_PREPEND_UNSIGNED(__bitsize)  __SHORTNUM_COMBINE(SHORTNUM_UNSIGNED_PREFIX, __bitsize)
#define __SHORTNUM_PREPEND_FLOAT(__bitsize)     __SHORTNUM_COMBINE(SHORTNUM_FLOAT_PREFIX, __bitsize)

typedef int8_t      __SHORTNUM_PREPEND_SIGNED(8);
typedef int16_t     __SHORTNUM_PREPEND_SIGNED(16);
typedef int32_t     __SHORTNUM_PREPEND_SIGNED(32);
typedef int64_t     __SHORTNUM_PREPEND_SIGNED(64);

typedef uint8_t     __SHORTNUM_PREPEND_UNSIGNED(8);
typedef uint16_t    __SHORTNUM_PREPEND_UNSIGNED(16);
typedef uint32_t    __SHORTNUM_PREPEND_UNSIGNED(32);
typedef uint64_t    __SHORTNUM_PREPEND_UNSIGNED(64);

/* Allow user to define their own floating point types */
#ifndef SHORTNUM_CUSTOM_FLOAT
typedef float   __SHORTNUM_PREPEND_FLOAT(32);
typedef double  __SHORTNUM_PREPEND_FLOAT(64);
#endif

/* Might be useful to keep internal macros if user wishes to define their own types */
#ifndef SHORTNUM_KEEP_INTERNAL_MACROS
#undef __SHORTNUM_EVAL
#undef __SHORTNUM_COMBINE
#undef __SHORTNUM_PREPEND_SIGNED
#undef __SHORTNUM_PREPEND_UNSIGNED
#undef __SHORTNUM_PREPEND_FLOAT
#endif

#ifdef __cplusplus
}
#endif

#endif /* SHORTNUM_H */
