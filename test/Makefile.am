## Process this file with automake to produce Makefile.in

HEADERS_CPPFLAGS = \
	-I$(top_builddir) \
	-include $(top_builddir)/config.h \
	-DLIBBSD_DISABLE_DEPRECATED \
	-D__REENTRANT \
	# EOL

AM_CPPFLAGS = \
	-isystem $(top_srcdir)/include/bsd/ \
	$(HEADERS_CPPFLAGS) \
	-DLIBBSD_OVERLAY \
	# EOL

AM_TESTS_ENVIRONMENT = \
	export CC="$(CC)"; \
	export CPPFLAGS="$(HEADERS_CPPFLAGS)"; \
	export top_srcdir="$(top_srcdir)"; \
	# EOL

LDADD = $(top_builddir)/src/libbsd.la

EXTRA_DIST = \
	headers-overlay.sh \
	headers-system.sh \
	# EOL

check_SCRIPTS = \
	headers-overlay.sh \
	headers-system.sh \
	# EOL

check_PROGRAMS = \
	overlay \
	bzero \
	closefrom \
	endian \
	explicit_bzero \
	humanize \
	fgetln \
	fparseln \
	fpurge \
	md5 \
	nlist \
	proctitle-init \
	progname \
	pwcache \
	setmode \
	strl \
	strmode \
	strnstr \
	strtonum \
	vis \
	vis-openbsd \
	# EOL

if HAVE_FOPENCOOKIE
check_PROGRAMS += funopen
endif

if HAVE_LIBTESTU01
arc4random_LDADD = $(LDADD) $(TESTU01_LIBS)

check_PROGRAMS += arc4random
endif

if BUILD_LIBBSD_CTOR
proctitle_LDFLAGS = \
	-Wl,-u,libbsd_init_func \
	$(top_builddir)/src/libbsd-ctor.a \
	$(top_builddir)/src/libbsd.la \
	# EOL

check_PROGRAMS += proctitle
endif

if NEED_TRANSPARENT_LIBMD
# On the installed system this is handled via the ld script.
md5_LDADD = $(LDADD) $(MD5_LIBS)
endif

fgetln_SOURCES = test-stream.c test-stream.h fgetln.c
fgetln_CFLAGS = -Wno-deprecated-declarations
fparseln_SOURCES = test-stream.c test-stream.h fparseln.c

proctitle_init_SOURCES = proctitle.c
proctitle_init_CPPFLAGS = $(AM_CPPFLAGS) -DTEST_USE_SETPROCTITLE_INIT=1

TESTS = $(check_SCRIPTS) $(check_PROGRAMS)
