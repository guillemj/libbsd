# Copyright © 2021 Guillem Jover <guillem@hadrons.org>

# LIBBSD_CHECK_COMPILER_FLAG
# -------------------------
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
