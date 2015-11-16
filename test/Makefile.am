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
	bzero \
	closefrom \
	endian \
	humanize \
	fgetln \
	funopen \
	fparseln \
	fpurge \
	proctitle-init \
	$(nil)

if HAVE_LIBTESTU01
arc4random_LDADD = $(LDADD) $(TESTU01_LIBS)

check_PROGRAMS += arc4random
endif

if BUILD_LIBBSD_CTOR
proctitle_LDFLAGS = \
	-Wl,-u,libbsd_init_func \
	$(top_builddir)/src/libbsd-ctor.a \
	$(top_builddir)/src/libbsd.la \
	$(nil)

check_PROGRAMS += proctitle
endif

fgetln_SOURCES = test-stream.c test-stream.h fgetln.c
fgetln_CFLAGS = -Wno-deprecated-declarations
fparseln_SOURCES = test-stream.c test-stream.h fparseln.c

proctitle_init_SOURCES = proctitle.c
proctitle_init_CPPFLAGS = $(AM_CPPFLAGS) -DTEST_USE_SETPROCTITLE_INIT=1

TESTS = $(check_PROGRAMS)
