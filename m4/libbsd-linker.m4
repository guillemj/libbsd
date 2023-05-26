# Copyright © 2019, 2022 Guillem Jover <guillem@hadrons.org>

# LIBBSD_LINKER_VERSION_SCRIPT
# ----------------------------
AC_DEFUN([LIBBSD_LINKER_VERSION_SCRIPT], [
  AC_CACHE_CHECK([if ld supports --version-script flag],
    [libbsd_cv_version_script], [
    echo "{ global: symbol; local: *; };" >conftest.map
    save_LDFLAGS=$LDFLAGS
    LDFLAGS="$LDFLAGS -Wl,--version-script=conftest.map"
    AC_LINK_IFELSE([
      AC_LANG_PROGRAM([[
extern int symbol(void);
int symbol(void) { return 0; }
]], [[
]])
    ], [
      libbsd_cv_version_script=yes
    ], [
      libbsd_cv_version_script=no
    ])
    LDFLAGS="$save_LDFLAGS"
    rm -f conftest.map
  ])
  AM_CONDITIONAL([HAVE_LINKER_VERSION_SCRIPT],
    [test "x$libbsd_cv_version_script" = "xyes"])
])
