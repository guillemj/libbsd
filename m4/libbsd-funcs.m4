# Copyright © 2011-2024 Guillem Jover <guillem@hadrons.org>

# LIBBSD_CHECK_PROGNAME
# ---------------------
AC_DEFUN([LIBBSD_CHECK_PROGNAME], [
  AC_MSG_CHECKING([for program_invocation_short_name])
  AC_LINK_IFELSE([
    AC_LANG_PROGRAM([[
#include <errno.h>
    ]], [[
const char *p = program_invocation_short_name;
    ]])
  ], [
    AC_DEFINE([HAVE_PROGRAM_INVOCATION_SHORT_NAME], [1],
      [Define to 1 if you have program_invocation_short_name])
    AC_MSG_RESULT([yes])
  ], [
    AC_MSG_RESULT([no])
  ])

  AC_MSG_CHECKING([for __progname])
  AC_LINK_IFELSE([
    AC_LANG_PROGRAM([[
#include <stdio.h>
extern char *__progname;
    ]], [[
printf("%s", __progname);
    ]])
  ], [
    AC_DEFINE([HAVE___PROGNAME], [1], [Define to 1 if you have __progname])
    AC_MSG_RESULT([yes])
  ], [
    AC_MSG_RESULT([no])
  ])
])

# LIBBSD_CHECK_REGISTER_ATFORK
# ----------------------------
AC_DEFUN([LIBBSD_CHECK_REGISTER_ATFORK], [
  AC_MSG_CHECKING([for __register_atfork])
  AC_LINK_IFELSE([
    AC_LANG_PROGRAM([[
#include <stddef.h>
extern void *__dso_handle;
extern int __register_atfork(void (*)(void), void(*)(void), void (*)(void), void *);
    ]], [[
__register_atfork(NULL, NULL, NULL, __dso_handle);
    ]])
  ], [
    AC_DEFINE([HAVE___REGISTER_ATFORK], [1],
      [Define to 1 if you have __register_atfork])
    AC_MSG_RESULT([yes])
  ], [
    LIBBSD_LIBS="$LIBBSD_LIBS -pthread"
    AC_MSG_RESULT([no])
  ])
])
