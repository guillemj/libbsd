# Copyright © 2021 Guillem Jover <guillem@hadrons.org>

# LIBBSD_CHECK_COMPILER_FLAG
# --------------------------
AC_DEFUN([LIBBSD_CHECK_COMPILER_FLAG], [
  AS_VAR_PUSHDEF([libbsd_varname_cache], [libbsd_cv_cflags_$1])
  AC_CACHE_CHECK([whether $CC accepts $1], [libbsd_varname_cache], [
    m4_define([libbsd_check_flag], m4_bpatsubst([$1], [^-Wno-], [-W]))
    AS_VAR_COPY([libbsd_save_CFLAGS], [CFLAGS])
    AS_VAR_SET([CFLAGS], ["-Werror libbsd_check_flag"])
    AC_COMPILE_IFELSE([
      AC_LANG_SOURCE([[]])
    ], [
      AS_VAR_SET([libbsd_varname_cache], [yes])
    ], [
      AS_VAR_SET([libbsd_varname_cache], [no])
    ])
    AS_VAR_COPY([CFLAGS], [libbsd_save_CFLAGS])
  ])
  AS_VAR_IF([libbsd_varname_cache], [yes], [
    AS_VAR_APPEND([LIBBSD_COMPILER_FLAGS], [" $1"])
  ])
  AS_VAR_POPDEF([libbsd_varname_cache])
])

# LIBBSD_HAS_GNU_INIT_ARRAY
# -------------------------
AC_DEFUN([LIBBSD_HAS_GNU_INIT_ARRAY], [
  AC_CACHE_CHECK([for GNU .init_array section support],
    [libbsd_cv_gnu_init_array_support], [
    AC_RUN_IFELSE([
      AC_LANG_SOURCE([[
static int rc = 1;
static void init(int argc) { if (argc == 1) rc = 0; }
void (*init_func)(int argc) __attribute__((__section__(".init_array"), __used__)) = init;
int main() { return rc; }
      ]])
    ], [
      libbsd_cv_gnu_init_array_support=yes
    ], [
      libbsd_cv_gnu_init_array_support=no
    ], [
      AC_PREPROC_IFELSE([
        AC_LANG_SOURCE([[
/* Look for a known libc that supports .init_array with the GNU extension
 * to pass main() arguments to the init functions. */
#include <stdlib.h>
#if defined __GLIBC_PREREQ
#  if __GLIBC_PREREQ(2, 4)
/* glibc supports GNU .init_array since 2.4. */
#  else
#    error glibc does not support GNU .init_array
#  endif
#else
/*
 * Basic SysV ABI .init_array support, init functions do not get arguments:
 * - Bionic since its inception.
 * - uClibc since 0.9.29.
 */
#  error unknown whether libc supports GNU .init_array
#endif
        ]])
      ], [
        libbsd_cv_gnu_init_array_support=yes
      ], [
        libbsd_cv_gnu_init_array_support=no
      ])
    ])
  ])
  AM_CONDITIONAL([BUILD_LIBBSD_CTOR],
    [test "$libbsd_cv_gnu_init_array_support" = yes])
])

# LIBBSD_SELECT_API(name, desc)
# -----------------
AC_DEFUN([LIBBSD_SELECT_API], [
  AS_IF([test -z "$AS_TR_SH([api_$1])"], [
    AC_MSG_ERROR([missing API selection for $1])
  ], [test "$AS_TR_SH([api_$1])" = "unknown"], [
    AC_MSG_ERROR([unknown ABI selection for $1])
  ], [test "$AS_TR_SH([api_$1])" = "yes"], [
    AC_DEFINE(AS_TR_CPP([LIBBSD_API_$1]), [1], [Provide API for $2])
  ], [
    AC_DEFINE(AS_TR_CPP([LIBBSD_API_$1]), [0])
  ])
  AM_CONDITIONAL(AS_TR_CPP([API_$1]),
    [test "x$AS_TR_SH([api_$1])" = "xyes"])
])

# LIBBSD_SELECT_ABI(name, desc)
# -----------------
AC_DEFUN([LIBBSD_SELECT_ABI], [
  AS_IF([test -z "$AS_TR_SH([abi_$1])"], [
    AC_MSG_ERROR([missing ABI selection for $1])
  ], [test "$AS_TR_SH([abi_$1])" = "unknown"], [
    AC_MSG_ERROR([unknown ABI selection for $1])
  ], [test "$AS_TR_SH([abi_$1])" = "yes"], [
    AC_DEFINE(AS_TR_CPP([LIBBSD_ABI_$1]), [1], [Provide ABI for $2])
  ], [
    AC_DEFINE(AS_TR_CPP([LIBBSD_ABI_$1]), [0])
  ])
  AM_CONDITIONAL(AS_TR_CPP([ABI_$1]),
    [test "x$AS_TR_SH([abi_$1])" = "xyes"])
])
