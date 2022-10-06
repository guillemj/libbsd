# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.67])
AC_INIT([libbsd], m4_esyscmd([./get-version]), [libbsd@lists.freedesktop.org])
AC_CONFIG_SRCDIR([src/strlcpy.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([1.9 foreign nostdinc subdir-objects no-dist-gzip dist-xz])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])],
                            [AC_SUBST([AM_DEFAULT_VERBOSITY], [1])])

LIBBSD_ABI_MAJOR=0
LIBBSD_ABI_MINOR=11
LIBBSD_ABI_PATCH=7

LIBBSD_ABI="$LIBBSD_ABI_MAJOR:$LIBBSD_ABI_MINOR:$LIBBSD_ABI_PATCH"
AC_SUBST([LIBBSD_ABI])

# Check and store if we got user supplied variables
user_CFLAGS=${CFLAGS-unset}

# Checks for operating system services and capabilities.
AC_USE_SYSTEM_EXTENSIONS
AC_SYS_LARGEFILE

LT_INIT

AC_CACHE_CHECK([if ld supports --version-script flag],
  [libbsd_cv_version_script], [
    echo "{ global: symbol; local: *; };" >conftest.map
    save_LDFLAGS=$LDFLAGS
    LDFLAGS="$LDFLAGS -Wl,--version-script=conftest.map"
    AC_LINK_IFELSE([
      AC_LANG_PROGRAM([], [])
    ], [
      libbsd_cv_version_script=yes
    ], [
      libbsd_cv_version_script=no
    ])
    LDFLAGS="$save_LDFLAGS"
    rm -f conftest.map
  ]
)
AM_CONDITIONAL([HAVE_LINKER_VERSION_SCRIPT],
  [test "x$libbsd_cv_version_script" = "xyes"])

# Checks for programs.
AC_CHECK_TOOL([OBJDUMP], [objdump])
AC_PROG_CC
AC_PROG_SED
AC_PROG_INSTALL
AC_PROG_LN_S

# Set default compiler variables
AS_IF([test "$user_CFLAGS" = unset], [
  LIBBSD_CHECK_COMPILER_FLAG([-Wall])
  LIBBSD_CHECK_COMPILER_FLAG([-Wextra])

  LIBBSD_CHECK_COMPILER_FLAG([-Wbad-function-cast])
  LIBBSD_CHECK_COMPILER_FLAG([-Wc99-c11-compat])
  LIBBSD_CHECK_COMPILER_FLAG([-Wcast-align])
  LIBBSD_CHECK_COMPILER_FLAG([-Wdeclaration-after-statement])
  LIBBSD_CHECK_COMPILER_FLAG([-Wdocumentation])
  LIBBSD_CHECK_COMPILER_FLAG([-Wduplicated-branches])
  LIBBSD_CHECK_COMPILER_FLAG([-Wduplicated-cond])
  LIBBSD_CHECK_COMPILER_FLAG([-Wformat -Wformat-security])
  LIBBSD_CHECK_COMPILER_FLAG([-Wformat=2])
  LIBBSD_CHECK_COMPILER_FLAG([-Winit-self])
  LIBBSD_CHECK_COMPILER_FLAG([-Wlogical-not-parentheses])
  LIBBSD_CHECK_COMPILER_FLAG([-Wlogical-op])
  LIBBSD_CHECK_COMPILER_FLAG([-Wmissing-declarations])
  LIBBSD_CHECK_COMPILER_FLAG([-Wmissing-format-attribute])
  LIBBSD_CHECK_COMPILER_FLAG([-Wmissing-prototypes])
  LIBBSD_CHECK_COMPILER_FLAG([-Wnested-externs])
  LIBBSD_CHECK_COMPILER_FLAG([-Wno-missing-field-initializers])
  LIBBSD_CHECK_COMPILER_FLAG([-Wno-nonnull-compare])
  LIBBSD_CHECK_COMPILER_FLAG([-Wno-tautological-constant-out-of-range-compare])
  LIBBSD_CHECK_COMPILER_FLAG([-Wno-unused-parameter])
  LIBBSD_CHECK_COMPILER_FLAG([-Wnull-dereference])
  LIBBSD_CHECK_COMPILER_FLAG([-Wold-style-definition])
  LIBBSD_CHECK_COMPILER_FLAG([-Wpointer-arith])
  LIBBSD_CHECK_COMPILER_FLAG([-Wregister])
  LIBBSD_CHECK_COMPILER_FLAG([-Wrestrict])
  LIBBSD_CHECK_COMPILER_FLAG([-Wshadow])
  LIBBSD_CHECK_COMPILER_FLAG([-Wshift-negative-value])
  LIBBSD_CHECK_COMPILER_FLAG([-Wsizeof-array-argument])
  LIBBSD_CHECK_COMPILER_FLAG([-Wstrict-prototypes])
  LIBBSD_CHECK_COMPILER_FLAG([-Wswitch-bool])
  LIBBSD_CHECK_COMPILER_FLAG([-Wvla])
  LIBBSD_CHECK_COMPILER_FLAG([-Wwrite-strings])

  CFLAGS="$CFLAGS $LIBBSD_COMPILER_FLAGS"
])

# Checks for libraries.
AC_CHECK_LIB([testu01], [unif01_CreateExternGenBits],
             [TESTU01_LIBS="-ltestu01"])
AC_SUBST([TESTU01_LIBS])
AM_CONDITIONAL([HAVE_LIBTESTU01],
               [test "x$ac_cv_lib_testu01_unif01_CreateExternGenBits" = "xyes"])

saved_LIBS="$LIBS"
AC_SEARCH_LIBS([MD5Update], [md], [
  AS_IF([test "x$ac_cv_search_MD5Update" != "xnone required"], [
    MD5_LIBS="$MD5_LIBS $ac_cv_search_MD5Update"
    need_transparent_libmd=yes
  ])
], [
  AC_MSG_ERROR([cannot find required MD5 functions in libc or libmd])
])
AC_SEARCH_LIBS([SHA512Update], [md], [
  AS_IF([test "x$ac_cv_search_SHA512Update" != "xnone required"], [
    LIBBSD_LIBS="$LIBBSD_LIBS $ac_cv_search_SHA512Update"
  ])
], [
  AC_MSG_ERROR([cannot find required SHA-2 functions in libc or libmd])
])
LIBS="$saved_LIBS"

AM_CONDITIONAL([NEED_TRANSPARENT_LIBMD],
               [test "x$need_transparent_libmd" = "xyes"])

is_windows=no
AS_CASE([$host_os],
  [*-gnu*], [
    # In old glibc versions (< 2.17) clock_gettime() is in librt.
    saved_LIBS="$LIBS"
    AC_SEARCH_LIBS([clock_gettime], [rt], [
      AS_IF([test "x$ac_cv_search_clock_gettime" != "xnone required"], [
        LIBBSD_LIBS="$LIBBSD_LIBS $ac_cv_search_clock_gettime"
      ])
    ])
    LIBS="$saved_LIBS"
  ],
  [*-musl*], [
    # Upstream refuses to define this, we will do it ourselves then.
    AC_DEFINE([__MUSL__], [1], [Define to 1 if we are building for musl])
  ],
  [mingw*], [
    is_windows=yes
  ],
)
AM_CONDITIONAL([OS_WINDOWS], [test "x$is_windows" = "xyes"])

# Checks for header files.
AC_CHECK_HEADERS([sys/ndir.h sys/dir.h ndir.h dirent.h pwd.h grp.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_C_TYPEOF
AC_TYPE_INT64_T
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_UID_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

AC_CHECK_DECL([F_CLOSEM],
              [AC_DEFINE([HAVE_FCNTL_CLOSEM], [1],
                         [Define to 1 if you have fcntl(F_CLOSEM)])],
              [],
              [#include <limits.h>
               #include <fcntl.h>])

AC_CACHE_CHECK(
	[for GNU .init_array section support],
	[libbsd_cv_gnu_init_array_support],
	[AC_RUN_IFELSE(
		[AC_LANG_SOURCE(
[[
static int rc = 1;
static void init(int argc) { if (argc == 1) rc = 0; }
void (*init_func)(int argc) __attribute__((__section__(".init_array"), __used__)) = init;
int main() { return rc; }
]]
		)],
		[libbsd_cv_gnu_init_array_support=yes],
		[libbsd_cv_gnu_init_array_support=no],
		[AC_PREPROC_IFELSE(
			[AC_LANG_SOURCE(
[[
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
]]
			)],
			[libbsd_cv_gnu_init_array_support=yes],
			[libbsd_cv_gnu_init_array_support=no])
		]
	)]
)
AM_CONDITIONAL([BUILD_LIBBSD_CTOR],
               [test "$libbsd_cv_gnu_init_array_support" = yes])

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
	[AC_LANG_PROGRAM([[extern char *__progname;]],
	                 [[printf("%s", __progname);]])],
	[AC_DEFINE([HAVE___PROGNAME], [1], [Define to 1 if you have __progname])
	 AC_MSG_RESULT([yes])],
	[AC_MSG_RESULT([no])])

AC_MSG_CHECKING([for __register_atfork])
AC_LINK_IFELSE(
	[AC_LANG_PROGRAM([[
		#include <stddef.h>
		extern void *__dso_handle;
		extern int __register_atfork(void (*)(void), void(*)(void), void (*)(void), void *);
	]], [[
		__register_atfork(NULL, NULL, NULL, __dso_handle);
	]])],
	[AC_DEFINE([HAVE___REGISTER_ATFORK], [1],
	           [Define to 1 if you have __register_atfork])
	 AC_MSG_RESULT([yes])],
	[LIBBSD_LIBS="$LIBBSD_LIBS -pthread"
	 AC_MSG_RESULT([no])
	])

AC_CHECK_FUNCS([clearenv dirfd fopencookie __fpurge \
                getauxval getentropy getexecname getline \
                pstat_getproc sysconf])
AM_CONDITIONAL([HAVE_GETENTROPY], [test "x$ac_cv_func_getentropy" = "xtrue"])

AC_SUBST([MD5_LIBS])
AC_SUBST([LIBBSD_LIBS])

AC_CONFIG_FILES([
	Makefile
	include/Makefile
	man/Makefile
	src/Makefile
	src/libbsd.pc
	src/libbsd-ctor.pc
	src/libbsd-overlay.pc
	test/Makefile
])
AC_CONFIG_HEADERS([config.h])
AC_OUTPUT
