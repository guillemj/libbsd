# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.67])
AC_INIT([libbsd], m4_esyscmd([./get-version]), [libbsd@lists.freedesktop.org])
AC_CONFIG_SRCDIR([src/strlcpy.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE(
  [1.11]
  [-Wall]
  [foreign]
  [nostdinc]
  [subdir-objects]
  [no-dist-gzip dist-xz]
)
AM_SILENT_RULES([yes])

SOVERSION_MAJOR=0
SOVERSION_MINOR=11
SOVERSION_PATCH=8

SOVERSION="$SOVERSION_MAJOR:$SOVERSION_MINOR:$SOVERSION_PATCH"
AC_SUBST([SOVERSION])

# Check and store if we got user supplied variables
user_CFLAGS=${CFLAGS-unset}

# Checks for operating system services and capabilities.
AC_USE_SYSTEM_EXTENSIONS
AC_SYS_LARGEFILE

AM_PROG_AR
LT_INIT
LIBBSD_LINKER_VERSION_SCRIPT

is_windows=no
AS_CASE([$host_os],
  [mingw*], [
    is_windows=yes
  ],
)
AM_CONDITIONAL([OS_WINDOWS], [test "x$is_windows" = "xyes"])

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

  AC_ARG_ENABLE([sanitize],
    [AS_HELP_STRING([--enable-sanitize], [enable compiler sanitizer support])],
  [
    LIBBSD_COMPILER_FLAGS=''
    LIBBSD_CHECK_COMPILER_FLAG([-fsanitize=address])
    LIBBSD_CHECK_COMPILER_FLAG([-fsanitize=leak])
    LIBBSD_CHECK_COMPILER_FLAG([-fsanitize=undefined])

    CFLAGS="$CFLAGS $LIBBSD_COMPILER_FLAGS"
    LDFLAGS="$LDFLAGS $LIBBSD_COMPILER_FLAGS"
  ])
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
  [aix*], [
    saved_LIBS="$LIBS"
    AC_SEARCH_LIBS([perfstat_cpu_total], [perfstat], [
      AS_IF([test "x$ac_cv_search_perfstat_cpu_total" != "xnone required"], [
        LIBBSD_LIBS="$LIBBSD_LIBS $ac_cv_search_perfstat_cpu_total"
      ])
    ])
    LIBS="$saved_LIBS"
  ],
)

# Checks for header files.
AC_CHECK_HEADERS([\
  sys/ndir.h \
  sys/dir.h \
  ndir.h \
  dirent.h \
  pwd.h \
  grp.h \
  stdio_ext.h \
  procinfo.h \
])

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

AC_CHECK_DECL([F_CLOSEM], [
  AC_DEFINE([HAVE_FCNTL_CLOSEM], [1],
    [Define to 1 if you have fcntl(F_CLOSEM)])
], [], [[
#include <limits.h>
#include <fcntl.h>
]])

AC_CHECK_DECLS([environ], [], [], [[
#include <unistd.h>
]])

LIBBSD_HAS_GNU_INIT_ARRAY

# Checks for library functions.
LIBBSD_CHECK_PROGNAME
LIBBSD_CHECK_REGISTER_ATFORK

AC_CHECK_FUNCS([\
  clearenv \
  dirfd \
  flock \
  fopencookie \
  __fpurge \
  funopen \
  getauxval \
  getentropy \
  getexecname \
  getline \
  open_memstream \
  pstat_getproc \
  sysconf \
  uid_from_user \
  gid_from_group \
  user_from_uid \
  group_from_gid \
])

need_arc4random=yes
need_bsd_getopt=yes
need_err=yes
need_errc=yes
need_progname=yes
need_md5=yes
need_nlist=yes
need_strl=yes
need_wcsl=yes
need_strmode=yes
need_name_from_id=yes
need_fpurge=yes
need_funopen=yes
AS_CASE([$host_os],
  [*-gnu*], [
    # On glibc >= 2.38, strlcpy() and strlcat() got added,
    # so these could then be dropped on the next SOVERSION bump.
    #need_strl=no
    need_err=no
  ],
  [*-musl*], [
    # On musl >= 0.5.0, strlcpy() and strlcat() were already implemented,
    # so these can then be dropped on the next SOVERSION bump.
    #need_strl=no
    # On musl >= 0.9.7, optreset got implemented, so bsd_getopt() can then
    # be dropped on the next SOVERSION bump.
    #need_bsd_getopt=no
    need_err=no
    # On musl >= 1.1.19, fopencookie() got implemented, and because we were
    # checking for its presence to decide whether to build funopen(), it got
    # included in builds even when previously it had not been included, which
    # is partially an ABI issue, but given that disabling it now would be
    # worse, we'll ignore this as this is only a problem with downgrades. And
    # enable it explicitly
    need_funopen=yes
  ],
  [darwin*], [
    # On macOS these are provided by the system, and libbsd has never built
    # there, so we can avoid providing these with no ABI breakage.
    need_arc4random=no
    need_bsd_getopt=no
    need_err=no
    need_errc=no
    need_progname=no
    need_transparent_libmd=no
    need_md5=no
    need_nlist=no
    need_strl=no
    need_wcsl=no
    need_strmode=no
    need_name_from_id=no
    need_fpurge=no
    # On macOS we do not have fopencookie(), and cannot implement it.
    need_funopen=no
  ],
)

AM_CONDITIONAL([HAVE_GETENTROPY], [test "x$ac_cv_func_getentropy" = "xyes"])

AM_CONDITIONAL([NEED_ARC4RANDOM], [test "x$need_arc4random" = "xyes"])
AM_CONDITIONAL([NEED_BSD_GETOPT], [test "x$need_bsd_getopt" = "xyes"])
AM_CONDITIONAL([NEED_ERR], [test "x$need_err" = "xyes"])
AM_CONDITIONAL([NEED_ERRC], [test "x$need_errc" = "xyes"])
AM_CONDITIONAL([NEED_PROGNAME], [test "x$need_progname" = "xyes"])
AM_CONDITIONAL([NEED_TRANSPARENT_LIBMD], [test "x$need_transparent_libmd" = "xyes"])
AM_CONDITIONAL([NEED_MD5], [test "x$need_md5" = "xyes"])
AM_CONDITIONAL([NEED_NLIST], [test "x$need_nlist" = "xyes"])
AM_CONDITIONAL([NEED_STRL], [test "x$need_strl" = "xyes"])
AM_CONDITIONAL([NEED_WCSL], [test "x$need_wcsl" = "xyes"])
AM_CONDITIONAL([NEED_STRMODE], [test "x$need_strmode" = "xyes"])
AM_CONDITIONAL([NEED_NAME_FROM_ID], [test "x$need_name_from_id" = "xyes"])
AM_CONDITIONAL([NEED_FPURGE], [test "x$need_fpurge" = "xyes"])
AM_CONDITIONAL([NEED_FUNOPEN], [test "x$need_funopen" = "xyes"])
AS_IF([test "x$need_funopen" = "xno" && \
       test "x$ac_cv_func_funopen" != "xyes" && \
       test "x$ac_cv_func_fopencookie" = "xyes"], [
  AC_MSG_WARN([[can implement funopen() now based on newly added fopencooke(), report upstream]])
])

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
