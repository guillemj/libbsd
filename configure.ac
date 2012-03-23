# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.67])
AC_INIT([libbsd], m4_esyscmd([./get-version]), [libbsd@lists.freedesktop.org])
AC_CONFIG_SRCDIR([src/fgetln.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([1.8 foreign nostdinc])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])],
                            [AC_SUBST([AM_DEFAULT_VERBOSITY], [1])])

# Checks for operating system services and capabilities.
AC_USE_SYSTEM_EXTENSIONS
AC_SYS_LARGEFILE

LT_INIT

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UID_T
AC_C_INLINE
AC_TYPE_INT64_T
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Checks for library functions.

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
