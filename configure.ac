# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.67])
AC_INIT([libbsd], m4_esyscmd([./get-version]), [libbsd@lists.freedesktop.org])
AC_CONFIG_SRCDIR([src/fgetln.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([1.8 foreign nostdinc])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])],
                            [AC_SUBST([AM_DEFAULT_VERBOSITY], [1])])

# Check and store if we got user supplied variables
user_CFLAGS=${CFLAGS-unset}

# Checks for operating system services and capabilities.
AC_USE_SYSTEM_EXTENSIONS
AC_SYS_LARGEFILE

LT_INIT

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S

# Set default compiler variables
if test "$user_CFLAGS" = unset && test "$GCC" = yes; then
  CFLAGS="$CFLAGS -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter"
fi

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([sys/ndir.h sys/dir.h dir.h dirent.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UID_T
AC_C_INLINE
AC_TYPE_INT64_T
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

AC_CHECK_DECL([F_CLOSEM],
              [AC_DEFINE([HAVE_FCNTL_CLOSEM], [1],
                         [Define to 1 if you have fcntl(F_CLOSEM)])],
              [],
              [#include <limits.h>
               #include <fcntl.h>])

# Checks for library functions.
AC_MSG_CHECKING([for program_invocation_short_name])
AC_LINK_IFELSE(
	[AC_LANG_PROGRAM([[#include <errno.h>]],
	                 [[const char *p = program_invocation_short_name;]])],
	[AC_DEFINE([HAVE_PROGRAM_INVOCATION_SHORT_NAME], [1],
	           [Define to 1 if you have program_invocation_short_name])
	 AC_MSG_RESULT([yes])],
	[AC_MSG_RESULT([no])])

AC_MSG_CHECKING([for __progname])
AC_LINK_IFELSE(
	[AC_LANG_PROGRAM([[]],
	                 [[extern char *__progname;
	                   const char *p = __progname;]])],
	[AC_DEFINE([HAVE___PROGNAME], [1], [Define to 1 if you have __progname])
	 AC_MSG_RESULT([yes])],
	[AC_MSG_RESULT([no])])

AC_CHECK_FUNCS([dirfd __fpurge getexecname getline sysconf])

AC_CONFIG_FILES([
	Makefile
	include/Makefile
	man/Makefile
	src/Makefile
	src/libbsd.pc
	src/libbsd-overlay.pc
	test/Makefile
])
AC_CONFIG_HEADERS([config.h])
AC_OUTPUT
