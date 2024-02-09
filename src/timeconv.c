/*-
 * Copyright (c) 2001 FreeBSD Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * These routines are for converting time_t to fixed-bit representations
 * for use in protocols or storage.  When converting time to a larger
 * representation of time_t these routines are expected to assume temporal
 * locality and use the 50-year rule to properly set the msb bits.  XXX
 *
 */

#include <sys/cdefs.h>
#include <sys/types.h>

#include "local-link.h"

#if LIBBSD_SYS_TIME_BITS == 64
/*
 * - enable time64 functions
 * - symver libbsd<func>_time64 -> <func> 0.7
 */
#define time32_symbol(name)
#define time64_symbol(name) \
	libbsd_strong_alias(libbsd ## name ## _time64, name)
#elif LIBBSD_SYS_TIME_BITS == 32 && LIBBSD_SYS_HAS_TIME64
/*
 * - enable time32 functions
 * - enable time64 functions
 * - symver libbsd<func>_time32 -> <func> 0.7
 * - map libbsd<func>_time64 <func>_time64 0.12
 */
#define time32_symbol(name) \
	libbsd_strong_alias(libbsd ## name ## _time32, name)
#define time64_symbol(name) \
	libbsd_strong_alias(libbsd ## name ## _time64, name ## _time64)
#elif LIBBSD_SYS_TIME_BITS == 32 && !LIBBSD_SYS_HAS_TIME64
/*
 * - enable time32 functions
 * - symver libbsd<func>_time32 -> <func>
 */
#define time32_symbol(name) \
	libbsd_strong_alias(libbsd ## name ## _time32, name)
#define time64_symbol(name)
#else
#error "Unknown time_t support"
#endif

#if LIBBSD_SYS_HAS_TIME64
typedef int64_t libbsd_time64_t;

/*
 * Convert a 32 bit representation of time_t into time_t.  XXX needs to
 * implement the 50-year rule to handle post-2038 conversions.
 */
libbsd_time64_t
libbsd_time32_to_time_time64(int32_t t32);
libbsd_time64_t
libbsd_time32_to_time_time64(int32_t t32)
{
    return((libbsd_time64_t)t32);
}
time64_symbol(_time32_to_time);

/*
 * Convert time_t to a 32 bit representation.  If time_t is 64 bits we can
 * simply chop it down.   The resulting 32 bit representation can be
 * converted back to a temporally local 64 bit time_t using time32_to_time.
 */
int32_t
libbsd_time_to_time32_time64(libbsd_time64_t t);
int32_t
libbsd_time_to_time32_time64(libbsd_time64_t t)
{
    return((int32_t)t);
}
time64_symbol(_time_to_time32);

/*
 * Convert a 64 bit representation of time_t into time_t.  If time_t is
 * represented as 32 bits we can simply chop it and not support times
 * past 2038.
 */
libbsd_time64_t
libbsd_time64_to_time_time64(int64_t t64);
libbsd_time64_t
libbsd_time64_to_time_time64(int64_t t64)
{
    return((libbsd_time64_t)t64);
}
time64_symbol(_time64_to_time);

/*
 * Convert time_t to a 64 bit representation.  If time_t is represented
 * as 32 bits we simply sign-extend and do not support times past 2038.
 */
int64_t
libbsd_time_to_time64_time64(libbsd_time64_t t);
int64_t
libbsd_time_to_time64_time64(libbsd_time64_t t)
{
    return((int64_t)t);
}
time64_symbol(_time_to_time64);

/*
 * Convert to/from 'long'.  Depending on the sizeof(long) this may or
 * may not require using the 50-year rule.
 */
long
libbsd_time_to_long_time64(libbsd_time64_t t);
long
libbsd_time_to_long_time64(libbsd_time64_t t)
{
    if (sizeof(long) == sizeof(int64_t))
	return(libbsd_time_to_time64_time64(t));
    return((long)t);
}
time64_symbol(_time_to_long);

libbsd_time64_t
libbsd_long_to_time_time64(long tlong);
libbsd_time64_t
libbsd_long_to_time_time64(long tlong)
{
    if (sizeof(long) == sizeof(int32_t))
	return(libbsd_time32_to_time_time64(tlong));
    return((libbsd_time64_t)tlong);
}
time64_symbol(_long_to_time);

/*
 * Convert to/from 'int'.  Depending on the sizeof(int) this may or
 * may not require using the 50-year rule.
 */
int
libbsd_time_to_int_time64(time_t t);
int
libbsd_time_to_int_time64(time_t t)
{
    if (sizeof(int) == sizeof(int64_t))
	return(libbsd_time_to_time64_time64(t));
    return((int)t);
}
time64_symbol(_time_to_int);

libbsd_time64_t
libbsd_int_to_time_time64(int tint);
libbsd_time64_t
libbsd_int_to_time_time64(int tint)
{
    if (sizeof(int) == sizeof(int32_t))
	return(libbsd_time32_to_time_time64(tint));
    return((libbsd_time64_t)tint);
}
time64_symbol(_int_to_time);
#endif

#if LIBBSD_SYS_TIME_BITS == 32
typedef int32_t libbsd_time32_t;

libbsd_time32_t
libbsd_time32_to_time_time32(int32_t t32);
libbsd_time32_t
libbsd_time32_to_time_time32(int32_t t32)
{
    return((libbsd_time32_t)t32);
}
time32_symbol(_time32_to_time);

/*
 * Convert time_t to a 32 bit representation.  If time_t is 64 bits we can
 * simply chop it down.   The resulting 32 bit representation can be
 * converted back to a temporally local 64 bit time_t using time32_to_time.
 */
int32_t
libbsd_time_to_time32_time32(libbsd_time32_t t);
int32_t
libbsd_time_to_time32_time32(libbsd_time32_t t)
{
    return((int32_t)t);
}
time32_symbol(_time_to_time32);

/*
 * Convert a 64 bit representation of time_t into time_t.  If time_t is
 * represented as 32 bits we can simply chop it and not support times
 * past 2038.
 */
libbsd_time32_t
libbsd_time64_to_time_time32(int64_t t64);
libbsd_time32_t
libbsd_time64_to_time_time32(int64_t t64)
{
    return((libbsd_time32_t)t64);
}
time32_symbol(_time64_to_time);

/*
 * Convert time_t to a 64 bit representation.  If time_t is represented
 * as 32 bits we simply sign-extend and do not support times past 2038.
 */
int64_t
libbsd_time_to_time64_time32(libbsd_time32_t t);
int64_t
libbsd_time_to_time64_time32(libbsd_time32_t t)
{
    return((int64_t)t);
}
time32_symbol(_time_to_time64);

/*
 * Convert to/from 'long'.  Depending on the sizeof(long) this may or
 * may not require using the 50-year rule.
 */
long
libbsd_time_to_long_time32(libbsd_time32_t t);
long
libbsd_time_to_long_time32(libbsd_time32_t t)
{
    if (sizeof(long) == sizeof(int64_t))
	return(libbsd_time_to_time64_time32(t));
    return((long)t);
}
time32_symbol(_time_to_long);

libbsd_time32_t
libbsd_long_to_time_time32(long tlong);
libbsd_time32_t
libbsd_long_to_time_time32(long tlong)
{
    if (sizeof(long) == sizeof(int32_t))
	return(libbsd_time32_to_time_time32(tlong));
    return((libbsd_time32_t)tlong);
}
time32_symbol(_long_to_time);

/*
 * Convert to/from 'int'.  Depending on the sizeof(int) this may or
 * may not require using the 50-year rule.
 */
int
libbsd_time_to_int_time32(libbsd_time32_t t);
int
libbsd_time_to_int_time32(libbsd_time32_t t)
{
    if (sizeof(int) == sizeof(int64_t))
	return(libbsd_time_to_time64_time32(t));
    return((int)t);
}
time32_symbol(_time_to_int);

libbsd_time32_t
libbsd_int_to_time_time32(int tint);
libbsd_time32_t
libbsd_int_to_time_time32(int tint)
{
    if (sizeof(int) == sizeof(int32_t))
	return(libbsd_time32_to_time_time32(tint));
    return((libbsd_time32_t)tint);
}
time32_symbol(_int_to_time);
#endif
