/*
 *                         Vortex OpenSplice
 *
 *   This software and documentation are Copyright 2006 to  ADLINK
 *   Technology Limited, its affiliated companies and licensors. All rights
 *   reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */
#ifndef OS_LINUX_OS_OS_TYPES_H
#define OS_LINUX_OS_OS_TYPES_H

#include <sys/types.h>
#include <stdint.h>
#include <stddef.h>

#if defined (__cplusplus)
extern "C" {
#endif

typedef char               os_os_char;      /* 1 byte   signed integer*/
typedef uint8_t            os_os_uchar;     /* 1 byte unsigned integer*/
typedef int16_t            os_os_short;     /* 2 byte   signed integer */
typedef uint16_t           os_os_ushort;    /* 2 byte unsigned integer */
typedef int32_t            os_os_int32;     /* 4 byte   signed integer */
typedef uint32_t           os_os_uint32;    /* 4 byte unsigned integer */
typedef int64_t            os_os_int64;     /* 8 byte   signed integer */
typedef uint64_t           os_os_uint64;    /* 8 byte unsigned integer */
typedef float              os_os_float;     /* 4 byte float */
typedef double             os_os_double;    /* 8 byte float */
typedef uintptr_t          os_os_address;   /* word length of the platform */
typedef intptr_t           os_os_saddress;  /* signed version of os_os_address */

#include "os_formatspec_c99.h" /* common printf format specifiers */

typedef double os_os_timeReal;
typedef int os_os_timeSec;
typedef uid_t os_os_uid;
typedef gid_t os_os_gid;
typedef size_t os_os_size_t;
typedef mode_t os_os_mode_t;

/* Platform specific integers, 32-bit on most 32-bit and also 64-bit archs (LP64), but it could
 * be also 64-bit wide (ILP64 & SILP64). This type is required for systems calls relying on
 * 'int' parameters, such as setsockopt */
typedef unsigned int      os_os_uint;
typedef          int      os_os_int;
typedef unsigned long int os_os_ulong_int;

/* Specific pointer types as defined in stdint.h */
typedef uintptr_t os_os_uintptr;


#if defined (__cplusplus)
}
#endif

#endif
