## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
	-I$(top_builddir) \
	-isystem $(top_srcdir)/include/bsd/ \
	-include $(top_builddir)/config.h \
	-DLIBBSD_OVERLAY -DLIBBSD_DISABLE_DEPRECATED \
	-D__REENTRANT

LDADD = $(top_builddir)/src/libbsd.la

check_PROGRAMS = \
	headers \
	overlay \
	closefrom \
	endian \
	humanize \
	fgetln \
	funopen \
	fpurge \
	proctitle-init \
	$(nil)

if BUILD_LIBBSD_CTOR
check_PROGRAMS += proctitle
endif

proctitle_init_SOURCES = proctitle.c
proctitle_init_CPPFLAGS = $(AM_CPPFLAGS) -DTEST_USE_SETPROCTITLE_INIT=1

proctitle_LDFLAGS = \
	-Wl,-u,libbsd_init_func \
	$(top_builddir)/src/libbsd-ctor.a \
	$(top_builddir)/src/libbsd.la \
	$(nil)

TESTS = $(check_PROGRAMS)
