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
	proctitle-init \
	pwcache \
	setmode \
	strnstr \
	strtonum \
	vis \
	vis-openbsd \
	# EOL

if NEED_ARC4RANDOM
if HAVE_LIBTESTU01
check_PROGRAMS += arc4random

arc4random_LDADD = $(LDADD) $(TESTU01_LIBS)
endif
endif

fgetln_SOURCES = \
	test-stream.c \
	test-stream.h \
	fgetln.c \
	# EOL

fgetln_CFLAGS = -Wno-deprecated-declarations

fparseln_SOURCES = \
	test-stream.c \
	test-stream.h \
	fparseln.c \
	# EOL

if NEED_FPURGE
check_PROGRAMS += fpurge
endif

if NEED_FUNOPEN
check_PROGRAMS += funopen
endif

if NEED_MD5
check_PROGRAMS += md5

if NEED_TRANSPARENT_LIBMD
# On the installed system this is handled via the ld script.
md5_LDADD = $(LDADD) $(MD5_LIBS)
endif
endif

if NEED_NLIST
check_PROGRAMS += nlist
endif

proctitle_init_SOURCES = \
	proctitle.c \
	# EOL

proctitle_init_CPPFLAGS = $(AM_CPPFLAGS) -DTEST_USE_SETPROCTITLE_INIT=1

if BUILD_LIBBSD_CTOR
check_PROGRAMS += proctitle

proctitle_LDFLAGS = \
	-Wl,-u,libbsd_init_func \
	$(top_builddir)/src/libbsd-ctor.a \
	$(top_builddir)/src/libbsd.la \
	# EOL
endif

if NEED_PROGNAME
check_PROGRAMS += progname
endif

if NEED_STRL
check_PROGRAMS += strl
endif

if NEED_STRMODE
check_PROGRAMS += strmode
endif

TESTS = $(check_SCRIPTS) $(check_PROGRAMS)
