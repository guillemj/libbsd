/*
 * Copyright (c) 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 * (c) UNIX System Laboratories, Inc.
 * All or some portions of this file are derived from material licensed
 * to the University of California by American Telephone and Telegraph
 * Co. or Unix System Laboratories, Inc. and are reproduced herein with
 * the permission of UNIX System Laboratories, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)time.h	8.3 (Berkeley) 1/21/94
 */

/*
 * $FreeBSD$
 */

#ifndef LIBBSD_TIMECONV_H
#define LIBBSD_TIMECONV_H

#ifdef LIBBSD_OVERLAY
#include <sys/cdefs.h>
#else
#include <bsd/sys/cdefs.h>
#endif
#include <stdint.h>
#include <time.h>

time_t _time32_to_time(int32_t t32);
int32_t _time_to_time32(time_t t);
time_t _time64_to_time(int64_t t64);
int64_t _time_to_time64(time_t t);
long _time_to_long(time_t t);
time_t _long_to_time(long tlong);
int _time_to_int(time_t t);
time_t _int_to_time(int tint);

#if LIBBSD_SYS_TIME_BITS == 32 && LIBBSD_SYS_HAS_TIME64
#if defined _TIME_BITS &&  _TIME_BITS == 64
time_t LIBBSD_REDIRECT(_time32_to_time, (int32_t t32), _time32_to_time_time64);
int32_t LIBBSD_REDIRECT(_time_to_time32, (time_t t), _time_to_time32_time64);
time_t LIBBSD_REDIRECT(_time64_to_time, (int64_t t64), _time64_to_time_time64);
int64_t LIBBSD_REDIRECT(_time_to_time64, (time_t t), _time_to_time64_time64);
long LIBBSD_REDIRECT(_time_to_long, (time_t t), _time_to_long_time64);
time_t LIBBSD_REDIRECT(_long_to_time, (long tlong), _long_to_time_time64);
int LIBBSD_REDIRECT(_time_to_int, (time_t t), _time_to_int_time64);
time_t LIBBSD_REDIRECT(_int_to_time, (int tint), _int_to_time_time64);
#endif
#endif

#endif /* LIBBSD_TIMECONV_H */
