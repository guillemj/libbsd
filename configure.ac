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
SOVERSION_MINOR=12
SOVERSION_PATCH=2

SOVERSION="$SOVERSION_MAJOR:$SOVERSION_MINOR:$SOVERSION_PATCH"
AC_SUBST([SOVERSION])

# Check and store if we got user supplied variables
user_CFLAGS=${CFLAGS-unset}

# Checks for operating system services and capabilities.
AC_USE_SYSTEM_EXTENSIONS
AC_SYS_LARGEFILE
LIBBSD_SYS_TIME64

AM_PROG_AR
LT_INIT
LIBBSD_LINKER_VERSION_SCRIPT

## Select library ABI to expose.
#
# The systems have DROP comments for interfaces that could be dropped on
# the next SOVERSION bump.

is_windows=no

api_time_macros=unknown

abi_accmode=unknown
abi_arc4random=unknown
abi_arc4random_stir=unknown
abi_asprintf=unknown
abi_bsd_getopt=unknown
abi_closefrom=unknown
abi_err=unknown
abi_errc=unknown
abi_expand_number=unknown
abi_explicit_bzero=unknown
abi_fgetln=unknown
abi_flopen=unknown
abi_fmtcheck=unknown
abi_fpurge=unknown
abi_freezero=unknown
abi_funopen=unknown
abi_getbsize=unknown
abi_getpeereid=unknown
abi_humanize_number=unknown
abi_id_from_name=unknown
abi_inet_net_pton=unknown
abi_md5=unknown
abi_name_from_id=unknown
abi_nlist=unknown
abi_pidfile=unknown
abi_proctitle=unknown
abi_progname=unknown
abi_readpassphrase=unknown
abi_reallocarray=unknown
abi_reallocf=unknown
abi_recallocarray=unknown
abi_stringlist=unknown
abi_sort=unknown
abi_strl=unknown
abi_strmode=unknown
abi_strnstr=unknown
abi_strtonum=unknown
abi_strtox=unknown
abi_timeconv=unknown
abi_vis=unknown
abi_wcsl=unknown

AS_CASE([$host_os],
  [*-gnu* | gnu*], [
    api_time_macros=no

    abi_accmode=yes
    # DROP: On glibc >= 2.36.
    #abi_arc4random=no
    abi_arc4random=yes
    abi_arc4random_stir=yes
    abi_asprintf=no
    abi_bsd_getopt=yes
    # DROP: On glibc >= 2.34.
    #abi_closefrom=no
    abi_closefrom=yes
    abi_err=no
    abi_errc=yes
    abi_expand_number=yes
    # DROP: On glibc >= 2.25.
    #abi_explicit_bzero=no
    abi_explicit_bzero=yes
    abi_fgetln=yes
    abi_flopen=yes
    abi_fmtcheck=yes
    abi_fpurge=yes
    abi_freezero=yes
    abi_funopen=yes
    abi_getbsize=yes
    abi_getpeereid=yes
    abi_humanize_number=yes
    abi_id_from_name=yes
    # DROP: On glibc.
    #abi_inet_net_pton=no
    abi_inet_net_pton=yes
    # DROP: On libmd.
    #abi_md5=no
    abi_md5=yes
    abi_name_from_id=yes
    abi_nlist=yes
    abi_pidfile=yes
    abi_proctitle=yes
    abi_progname=yes
    abi_readpassphrase=yes
    # DROP: On glibc >= 2.26.
    #abi_reallocarray=no
    abi_reallocarray=yes
    abi_reallocf=yes
    abi_recallocarray=yes
    abi_stringlist=yes
    abi_sort=yes
    # DROP: On glibc >= 2.38.
    #abi_strl=no
    abi_strl=yes
    abi_strmode=yes
    abi_strnstr=yes
    abi_strtonum=yes
    abi_strtox=yes
    abi_timeconv=yes
    # DROP: On libmd.
    abi_transparent_libmd=yes
    abi_vis=yes
    abi_wcsl=yes
  ],
  [*-musl*], [
    api_time_macros=no

    abi_accmode=yes
    abi_arc4random=yes
    abi_arc4random_stir=yes
    abi_asprintf=no
    # DROP: On musl >= 0.9.7, optreset got implemented.
    #abi_bsd_getopt=no
    abi_bsd_getopt=yes
    abi_closefrom=yes
    abi_err=no
    abi_errc=yes
    abi_expand_number=yes
    # DROP: On musl >= 1.1.20.
    #abi_explicit_bzero=no
    abi_explicit_bzero=yes
    # DROP: On musl >= 0.9.4.
    #abi_fgetln=no
    abi_fgetln=yes
    abi_flopen=yes
    abi_fmtcheck=yes
    abi_fpurge=yes
    abi_freezero=yes
    # On musl >= 1.1.19, fopencookie() got implemented, and because we were
    # checking for its presence to decide whether to build funopen(), it got
    # included in builds even when previously it had not been included, which
    # is partially an ABI issue, but given that disabling it now would be
    # worse, we'll ignore this as this is only a problem with downgrades. And
    # enable it explicitly
    #abi_funopen=no
    abi_funopen=yes
    abi_getbsize=yes
    abi_getpeereid=yes
    abi_humanize_number=yes
    abi_id_from_name=yes
    abi_inet_net_pton=yes
    # DROP: On libmd.
    #abi_md5=no
    abi_md5=yes
    abi_name_from_id=yes
    abi_nlist=yes
    abi_pidfile=yes
    abi_proctitle=yes
    abi_progname=yes
    abi_readpassphrase=yes
    # DROP: On musl >= 1.2.2.
    #abi_reallocarray=no
    abi_reallocarray=yes
    abi_reallocf=ues
    abi_recallocarray=yes
    abi_stringlist=yes
    abi_sort=yes
    # DROP: On musl >= 0.5.0, strlcpy() and strlcat() were already implemented.
    #abi_strl=no
    abi_strl=yes
    abi_strmode=yes
    abi_strnstr=yes
    abi_strtonum=yes
    abi_strtox=yes
    abi_timeconv=yes
    # DROP: On libmd.
    abi_transparent_libmd=yes
    abi_vis=yes
    abi_wcsl=yes
  ],
  [darwin*], [
    api_time_macros=no

    abi_accmode=no
    abi_arc4random=no
    abi_arc4random_stir=no
    abi_asprintf=no
    abi_bsd_getopt=no
    abi_closefrom=yes
    abi_err=no
    abi_errc=no
    abi_expand_number=yes
    abi_explicit_bzero=yes
    abi_fgetln=no
    abi_flopen=yes
    abi_fmtcheck=no
    abi_fpurge=no
    abi_freezero=yes
    abi_funopen=no
    abi_getbsize=yes
    abi_getpeereid=no
    abi_humanize_number=yes
    abi_id_from_name=yes
    abi_inet_net_pton=no
    # On libmd.
    abi_md5=no
    abi_name_from_id=no
    abi_nlist=no
    abi_pidfile=yes
    abi_proctitle=yes
    abi_progname=no
    abi_readpassphrase=no
    abi_reallocarray=yes
    abi_reallocf=no
    abi_recallocarray=yes
    abi_stringlist=no
    abi_sort=no
    abi_strl=no
    abi_strmode=no
    abi_strnstr=no
    abi_strtonum=no
    abi_strtox=yes
    abi_timeconv=no
    # On libmd.
    abi_transparent_libmd=no
    abi_vis=no
    abi_wcsl=no
  ],
  [solaris2*], [
    api_time_macros=yes

    abi_accmode=yes
    abi_arc4random=no
    abi_arc4random_stir=no
    abi_asprintf=no
    abi_bsd_getopt=yes
    abi_closefrom=no
    abi_err=no
    abi_errc=yes
    abi_expand_number=yes
    abi_explicit_bzero=yes
    abi_fgetln=yes
    abi_flopen=yes
    abi_fmtcheck=no
    abi_fpurge=yes
    abi_freezero=yes
    abi_funopen=no
    abi_getbsize=yes
    abi_getpeereid=yes
    abi_humanize_number=yes
    abi_id_from_name=yes
    abi_inet_net_pton=yes
    # On libmd.
    abi_md5=no
    abi_name_from_id=yes
    abi_nlist=no
    abi_pidfile=yes
    abi_proctitle=yes
    abi_progname=no
    abi_readpassphrase=yes
    abi_reallocarray=yes
    abi_reallocf=no
    abi_recallocarray=yes
    abi_stringlist=yes
    abi_sort=yes
    abi_strl=no
    abi_strmode=yes
    abi_strnstr=no
    abi_strtonum=no
    abi_strtox=yes
    abi_timeconv=yes
    # On libmd.
    abi_transparent_libmd=no
    abi_vis=yes
    abi_wcsl=yes
  ],
  [aix*], [
    api_time_macros=yes

    abi_accmode=yes
    abi_arc4random=yes
    abi_arc4random_stir=yes
    abi_asprintf=yes
    abi_bsd_getopt=yes
    abi_closefrom=yes
    abi_err=yes
    abi_errc=yes
    abi_expand_number=yes
    abi_explicit_bzero=yes
    abi_fgetln=yes
    abi_flopen=yes
    abi_fmtcheck=yes
    abi_fpurge=no
    abi_freezero=yes
    abi_funopen=no
    abi_getbsize=yes
    abi_getpeereid=yes
    abi_humanize_number=yes
    abi_id_from_name=yes
    abi_inet_net_pton=no
    # On libmd.
    abi_md5=no
    abi_name_from_id=yes
    abi_nlist=no
    abi_pidfile=yes
    abi_proctitle=yes
    abi_progname=yes
    abi_readpassphrase=yes
    abi_reallocarray=yes
    abi_reallocf=yes
    abi_recallocarray=yes
    abi_stringlist=yes
    abi_sort=yes
    abi_strl=yes
    abi_strmode=yes
    abi_strnstr=yes
    abi_strtonum=yes
    abi_strtox=yes
    abi_timeconv=yes
    # On libmd.
    abi_transparent_libmd=no
    abi_vis=yes
    abi_wcsl=yes
  ],
  [mingw*], [
    is_windows=yes
  ],
)

# Handle artificial ABI selections that are combinations of others.
AS_IF([test "$abi_name_from_id" = "yes" || test "$abi_id_from_name" = "yes"], [
  abi_pwcache=yes
], [
  abi_pwcache=no
])
AS_IF([test "$abi_err" = "yes" || test "$abi_errc" = "yes"], [
  abi_err_h=yes
], [
  abi_err_h=no
])

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
AS_IF([test "$abi_md5" = "yes"], [
  AC_SEARCH_LIBS([MD5Update], [md], [
    AS_IF([test "x$ac_cv_search_MD5Update" != "xnone required"], [
      MD5_LIBS="$MD5_LIBS $ac_cv_search_MD5Update"
      abi_transparent_libmd=yes
    ])
  ], [
    AC_MSG_ERROR([cannot find required MD5 functions in libc or libmd])
  ])
])
AS_IF([test "$abi_arc4random" = "yes"], [
  AC_CHECK_FUNCS([getentropy])

  AS_IF([test "$ac_cv_func_getentropy" != "yes"], [
    AC_SEARCH_LIBS([SHA512Update], [md], [
      AS_IF([test "x$ac_cv_search_SHA512Update" != "xnone required"], [
        LIBBSD_LIBS="$SHA512_LIBS $ac_cv_search_SHA512Update"
      ])
    ], [
      AC_MSG_ERROR([cannot find required SHA-2 functions in libc or libmd])
    ])
  ])
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
  vasprintf \
  asprintf \
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

AM_CONDITIONAL([HAVE_GETENTROPY], [test "x$ac_cv_func_getentropy" = "xyes"])

# API selection
LIBBSD_SELECT_API([time_macros], [time struct conversion macros])

# ABI selection
LIBBSD_SELECT_ABI([accmode], [setmode()/getmode()])
LIBBSD_SELECT_ABI([arc4random], [arc4random() API])
LIBBSD_SELECT_ABI([arc4random_stir], [arc4random_stir()/arc4random_addrandom()])
LIBBSD_SELECT_ABI([asprintf], [vasprintf()/asprintf()])
LIBBSD_SELECT_ABI([bsd_getopt], [BSD getopt()])
LIBBSD_SELECT_ABI([closefrom], [closefrom()])
LIBBSD_SELECT_ABI([err_h], [err.h header])
LIBBSD_SELECT_ABI([err], [err API])
LIBBSD_SELECT_ABI([errc], [errc API])
LIBBSD_SELECT_ABI([expand_number], [expand_number()])
LIBBSD_SELECT_ABI([explicit_bzero], [explicit_bzero()])
LIBBSD_SELECT_ABI([fgetln], [fgetln/fgetwln()])
LIBBSD_SELECT_ABI([flopen], [flopen()/flopenat()])
LIBBSD_SELECT_ABI([fmtcheck], [fmtcheck()])
LIBBSD_SELECT_ABI([fpurge], [fpurge()])
LIBBSD_SELECT_ABI([freezero], [freezero()])
LIBBSD_SELECT_ABI([funopen], [funopen()])
LIBBSD_SELECT_ABI([getbsize], [getbsize()])
LIBBSD_SELECT_ABI([getpeereid], [getpeereid()])
LIBBSD_SELECT_ABI([humanize_number], [humanize_number()/dehumanize_number()])
LIBBSD_SELECT_ABI([id_from_name], [uid_from_user()/gid_from_user()])
LIBBSD_SELECT_ABI([inet_net_pton], [inet_net_pton()])
LIBBSD_SELECT_ABI([md5], [MD5 digest functions])
LIBBSD_SELECT_ABI([name_from_id], [user_from_uid()/group_from_gid()])
LIBBSD_SELECT_ABI([nlist], [nlist()])
LIBBSD_SELECT_ABI([pidfile], [pidfile API])
LIBBSD_SELECT_ABI([proctitle], [setproctitle() API])
LIBBSD_SELECT_ABI([progname], [setprogname()/getprogname()])
LIBBSD_SELECT_ABI([pwcache], [password cache API])
LIBBSD_SELECT_ABI([readpassphrase], [readpassphrase()])
LIBBSD_SELECT_ABI([reallocarray], [reallocarray()])
LIBBSD_SELECT_ABI([reallocf], [reallocf()])
LIBBSD_SELECT_ABI([recallocarray], [recallocarray()])
LIBBSD_SELECT_ABI([stringlist], [stringlist sl_*() API])
LIBBSD_SELECT_ABI([sort], [BSD sort functions])
LIBBSD_SELECT_ABI([strl], [strlcpy()/strlcat()])
LIBBSD_SELECT_ABI([strmode], [strmode()])
LIBBSD_SELECT_ABI([strnstr], [strnstr()])
LIBBSD_SELECT_ABI([strtonum], [strtonum()])
LIBBSD_SELECT_ABI([strtox], [strtoi()/strtou()])
LIBBSD_SELECT_ABI([timeconv], [timeconv.h API])
LIBBSD_SELECT_ABI([transparent_libmd], [transparent libmd support])
LIBBSD_SELECT_ABI([vis], [vis API])
LIBBSD_SELECT_ABI([wcsl], [wcslcpy()/wcslcat()])

AS_IF([test "x$abi_funopen" = "xno" && \
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
