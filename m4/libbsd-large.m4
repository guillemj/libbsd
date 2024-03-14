# Copyright © 2024 Guillem Jover <guillem@hadrons.org>

# LIBBSD_SYS_TIME64
# -----------------
# Check for availability of time64 support.
AC_DEFUN([LIBBSD_SYS_TIME64], [
  # Check the default time_t size.
  AC_CHECK_SIZEOF([time_t], [], [[
#undef _TIME_BITS
#include <time.h>
]])
  AS_IF([test $ac_cv_sizeof_time_t -eq 8], [
    libbsd_sys_time_bits=64
  ], [
    libbsd_sys_time_bits=32
  ])
  AC_DEFINE_UNQUOTED([LIBBSD_SYS_TIME_BITS], [$libbsd_sys_time_bits],
    [The number of bits for the default system time_t ABI])
  AC_SUBST([LIBBSD_SYS_TIME_BITS], [$libbsd_sys_time_bits])
  AS_UNSET([ac_cv_sizeof_time_t])
  AM_CONDITIONAL([LIBBSD_SYS_IS_TIME32], [test "$libbsd_sys_time_bits" -eq 32])

  # Check the whether the system supports 64-bit time_t.
  AC_CHECK_SIZEOF([time_t], [], [[
#define _FILE_OFFSET_BITS 64
#define _TIME_BITS 64
#include <time.h>
]])
  AS_IF([test $ac_cv_sizeof_time_t -eq 8], [
    libbsd_sys_has_time64=1
  ], [
    libbsd_sys_has_time64=0
  ])
  AC_DEFINE_UNQUOTED([LIBBSD_SYS_HAS_TIME64], [$libbsd_sys_has_time64],
    [Enable if the system supports 64-bit time_t])
  AC_SUBST([LIBBSD_SYS_HAS_TIME64], [$libbsd_sys_has_time64])
  AM_CONDITIONAL([LIBBSD_SYS_HAS_TIME64], [test "$libbsd_sys_has_time64" -eq 1])
  AS_IF([test "$libbsd_sys_time_bits" -eq 32 && \
         test "$libbsd_sys_has_time64" -eq 1], [
    abi_time64=yes
  ], [
    abi_time64=no
  ])
  LIBBSD_SELECT_ABI([time64], [explicit time64 time_t support])

  AC_CHECK_SIZEOF([off_t], [], [[
#define _FILE_OFFSET_BITS 64
#include <sys/types.h>
]])
  AS_IF([test $ac_cv_sizeof_off_t = 8], [
    libbsd_sys_has_lfs=1
  ], [
    libbsd_sys_has_lfs=0
  ])

  AS_IF([test $libbsd_sys_has_lfs -eq 1 && \
         test $libbsd_sys_time_bits -eq 32 && \
         test $ac_cv_sizeof_time_t -eq 8], [
    AC_DEFINE([_TIME_BITS], [64], [Enable 64-bit time_t support])
  ])
])
