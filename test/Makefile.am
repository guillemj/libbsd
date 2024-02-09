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
	endian \
	# EOL

if ABI_ACCMODE
check_PROGRAMS += \
	setmode \
	# EOL
endif

if ABI_ARC4RANDOM
if HAVE_LIBTESTU01
check_PROGRAMS += arc4random

arc4random_LDADD = $(LDADD) $(TESTU01_LIBS)
endif
endif

if ABI_CLOSEFROM
check_PROGRAMS += \
	closefrom \
	# EOL
endif

if ABI_EXPLICIT_BZERO
check_PROGRAMS += \
	bzero \
	explicit_bzero \
	# EOL
endif

if ABI_FGETLN
check_PROGRAMS += \
	fgetln \
	fparseln \
	# EOL

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
endif

if ABI_FPURGE
check_PROGRAMS += fpurge
endif

if ABI_FUNOPEN
check_PROGRAMS += funopen
endif

if ABI_HUMANIZE_NUMBER
check_PROGRAMS += \
	humanize \
	# EOL
endif

if ABI_FPURGE
check_PROGRAMS += fpurge
endif

if ABI_FUNOPEN
check_PROGRAMS += funopen
endif

if ABI_MD5
check_PROGRAMS += md5

if ABI_TRANSPARENT_LIBMD
# On the installed system this is handled via the ld script.
md5_LDADD = $(LDADD) $(MD5_LIBS)
endif
endif

if ABI_NLIST
check_PROGRAMS += nlist
endif

if ABI_PROGNAME
check_PROGRAMS += progname
endif

if ABI_PROCTITLE
check_PROGRAMS += \
	proctitle-init \
	# EOL

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
endif

if ABI_PWCACHE
check_PROGRAMS += \
	pwcache \
	# EOL
endif

if ABI_PROGNAME
check_PROGRAMS += progname
endif

if ABI_STRL
check_PROGRAMS += strl
endif

if ABI_STRMODE
check_PROGRAMS += strmode
endif

if ABI_STRNSTR
check_PROGRAMS += \
	strnstr \
	# EOL
endif

if ABI_STRTONUM
check_PROGRAMS += \
	strtonum \
	# EOL
endif

if ABI_VIS
check_PROGRAMS += \
	vis \
	vis-openbsd \
	# EOL
endif

if LIBBSD_SYS_IS_TIME32
check_PROGRAMS += timeconv32
endif

if LIBBSD_SYS_HAS_TIME64
check_PROGRAMS += timeconv64
endif

TESTS = $(check_SCRIPTS) $(check_PROGRAMS)
