## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
	-I$(top_builddir) \
	-isystem $(top_srcdir)/include/bsd/ \
	-include $(top_builddir)/config.h \
	-DLIBBSD_OVERLAY -DLIBBSD_DISABLE_DEPRECATED \
	-D__REENTRANT \
	# EOL

if OS_WINDOWS
AM_CPPFLAGS += \
	-D_CRT_SECURE_NO_WARNINGS \
	-D_CRT_NONSTDC_NO_WARNINGS \
	# EOL
endif

libbsd_la_included_sources = \
	getentropy_aix.c \
	getentropy_bsd.c \
	getentropy_hpux.c \
	getentropy_hurd.c \
	getentropy_linux.c \
	getentropy_osx.c \
	getentropy_solaris.c \
	getentropy_win.c \
	# EOL

CLEANFILES =
EXTRA_DIST = \
	libbsd.map.in \
	libbsd.pc.in \
	libbsd-ctor.pc.in \
	libbsd-overlay.pc.in \
	$(libbsd_la_included_sources) \
	# EOL

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = \
	libbsd.pc \
	libbsd-overlay.pc \
	# EOL

lib_LTLIBRARIES = libbsd.la
lib_LIBRARIES =

if BUILD_LIBBSD_CTOR
pkgconfig_DATA += libbsd-ctor.pc

lib_LIBRARIES += libbsd-ctor.a
endif

EXTRA_libbsd_la_DEPENDENCIES = \
	$(libbsd_la_included_sources) \
	libbsd.map \
	libbsd.map.in \
	# EOL
libbsd_la_LIBADD = \
	$(MD5_LIBS) \
	$(LIBBSD_LIBS) \
	# EOL
libbsd_la_LDFLAGS = \
	-no-undefined \
	-version-number $(SOVERSION) \
	# EOL
if HAVE_LINKER_VERSION_SCRIPT
libbsd_la_LDFLAGS += \
	-Wl,--version-script=libbsd.map \
	# EOL
else
libbsd_la_LDFLAGS += \
	-export-symbols libbsd.sym \
	# EOL
EXTRA_libbsd_la_DEPENDENCIES += \
	libbsd.sym \
	# EOL
endif
libbsd_la_SOURCES = \
	local-elf.h \
	local-link.h \
	# EOL

if ABI_ACCMODE
libbsd_la_SOURCES += \
	setmode.c \
	# EOL
endif

if ABI_ARC4RANDOM
if !HAVE_GETENTROPY
libbsd_la_SOURCES += \
	getentropy.c \
	# EOL
endif
libbsd_la_SOURCES += \
	arc4random.c \
	arc4random.h \
	arc4random_linux.h \
	arc4random_uniform.c \
	arc4random_unix.h \
	arc4random_win.h \
	chacha_private.h \
	# EOL
endif

if ABI_ASPRINTF
libbsd_la_SOURCES += \
	asprintf.c \
	vasprintf.c \
	# EOL
endif

if ABI_BSD_GETOPT
libbsd_la_SOURCES += \
	bsd_getopt.c \
	# EOL
endif

if ABI_CLOSEFROM
libbsd_la_SOURCES += \
	closefrom.c \
	# EOL
endif

if ABI_ERR
libbsd_la_SOURCES += \
	err.c \
	# EOL
endif

if ABI_ERRC
libbsd_la_SOURCES += \
	errc.c \
	# EOL
endif

if ABI_EXPAND_NUMBER
libbsd_la_SOURCES += \
	expand_number.c \
	# EOL
endif

if ABI_EXPLICIT_BZERO
libbsd_la_SOURCES += \
	explicit_bzero.c \
	# EOL
endif

if ABI_FGETLN
libbsd_la_SOURCES += \
	fgetln.c \
	fgetwln.c \
	fparseln.c \
	# EOL
endif

if ABI_FLOPEN
libbsd_la_SOURCES += \
	flopen.c \
	# EOL
endif

if ABI_FMTCHECK
libbsd_la_SOURCES += \
	fmtcheck.c \
	# EOL
endif

if ABI_FPURGE
libbsd_la_SOURCES += \
	fpurge.c \
	# EOL
endif

if ABI_FREEZERO
libbsd_la_SOURCES += \
	freezero.c \
	# EOL
endif

if ABI_FUNOPEN
libbsd_la_SOURCES += \
	funopen.c \
	# EOL
endif

if ABI_GETBSIZE
libbsd_la_SOURCES += \
	getbsize.c \
	# EOL
endif

if ABI_GETPEEREID
libbsd_la_SOURCES += \
	getpeereid.c \
	# EOL
endif

if ABI_HUMANIZE_NUMBER
libbsd_la_SOURCES += \
	dehumanize_number.c \
	humanize_number.c \
	# EOL
endif

if ABI_INET_NET_PTON
libbsd_la_SOURCES += \
	inet_net_pton.c \
	# EOL
endif

if ABI_MD5
libbsd_la_SOURCES += \
	md5.c \
	# EOL
endif

if ABI_NLIST
libbsd_la_SOURCES += \
	nlist.c \
	# EOL
endif

if ABI_PIDFILE
libbsd_la_SOURCES += \
	pidfile.c \
	# EOL
endif

if ABI_PROCTITLE
libbsd_la_SOURCES += \
	setproctitle.c \
	# EOL
endif

if ABI_PROGNAME
libbsd_la_SOURCES += \
	progname.c \
	# EOL
endif

if ABI_PWCACHE
libbsd_la_SOURCES += \
	pwcache.c \
	# EOL
endif

if ABI_READPASSPHRASE
libbsd_la_SOURCES += \
	readpassphrase.c \
	# EOL
endif

if ABI_REALLOCARRAY
libbsd_la_SOURCES += \
	reallocarray.c \
	# EOL
endif

if ABI_REALLOCF
libbsd_la_SOURCES += \
	reallocf.c \
	# EOL
endif

if ABI_RECALLOCARRAY
libbsd_la_SOURCES += \
	recallocarray.c \
	# EOL
endif

if ABI_SORT
libbsd_la_SOURCES += \
	heapsort.c \
	merge.c \
	radixsort.c \
	# EOL
endif

if ABI_STRINGLIST
libbsd_la_SOURCES += \
	stringlist.c \
	# EOL
endif

if ABI_STRL
libbsd_la_SOURCES += \
	strlcat.c \
	strlcpy.c \
	# EOL
endif

if ABI_STRMODE
libbsd_la_SOURCES += \
	strmode.c \
	# EOL
endif

if ABI_STRNSTR
libbsd_la_SOURCES += \
	strnstr.c \
	# EOL
endif

if ABI_STRTONUM
libbsd_la_SOURCES += \
	strtonum.c \
	# EOL
endif

if ABI_STRTOX
libbsd_la_SOURCES += \
	strtoi.c \
	strtou.c \
	# EOL
endif

if ABI_TIMECONV
libbsd_la_SOURCES += \
	timeconv.c \
	# EOL
endif

if ABI_VIS
libbsd_la_SOURCES += \
	unvis.c \
	vis.c \
	# EOL
endif

if ABI_WCSL
libbsd_la_SOURCES += \
	wcslcat.c \
	wcslcpy.c \
	# EOL
endif

if ABI_TRANSPARENT_LIBMD
CLEANFILES += \
	format.ld \
	# EOL
endif

DISTCLEANFILES = \
	libbsd.sym \
	libbsd.map \
	# EOL

libbsd_ctor_a_SOURCES = \
	setproctitle_ctor.c \
	# EOL

# Generate the library map file with the pre-processor to selectively include
# symbols depending on the host system, otherwise some linkers might fail.
libbsd.map: libbsd.map.in
	$(AM_V_GEN) $(CPP) $(AM_CPPFLAGS) $(CPPFLAGS) -P - <$(srcdir)/libbsd.map.in >$@

# Generate a simple libtool symbol export list to be used as a fallback if
# there is no version script support.
libbsd.sym: libbsd.map
	$(AM_V_GEN) $(SED) -ne 's/^[[:space:]]\{1,\}\([A-Za-z0-9_]\{1,\}\);/\1/p' libbsd.map >$@

if ABI_TRANSPARENT_LIBMD
TRANSPARENT_LIBMD_DEPENDS = format.ld

format.ld:
	$(CC) -shared -nostdlib -nostartfiles -x assembler /dev/null -o $@.so
	$(OBJDUMP) -f $@.so | sed -n 's/.*file format \(.*\)/OUTPUT_FORMAT(\1)/;T;p' >$@
	rm -f $@.so
endif

runtimelibdir = $(libdir)

install-exec-hook: $(TRANSPARENT_LIBMD_DEPENDS)
	if [ "$(libdir)" != "$(runtimelibdir)" ]; then \
		$(MKDIR_P) $(DESTDIR)$(runtimelibdir); \
		mv $(DESTDIR)$(libdir)/libbsd*.so.* \
		   $(DESTDIR)$(runtimelibdir)/; \
	fi
if ABI_TRANSPARENT_LIBMD
# The "GNU ld script" magic is required so that GNU ldconfig does not complain
# about an unknown format file.
	soname=`readlink $(DESTDIR)$(libdir)/libbsd.so`; \
	$(RM) $(DESTDIR)$(libdir)/libbsd.so; \
	(echo '/* GNU ld script'; \
	 echo ' * The MD5 functions are provided by the libmd library. */'; \
	 cat format.ld; \
	 echo "GROUP($(runtimelibdir)/$$soname AS_NEEDED($(MD5_LIBS)))"; \
	)>$(DESTDIR)$(libdir)/libbsd.so
else
	if [ "$(libdir)" != "$(runtimelibdir)" ]; then \
		soname=`readlink $(DESTDIR)$(libdir)/libbsd.so`; \
		sorelprefix=`echo $(libdir) | $(SED) -r -e 's:(^/)?[^/]+:..:g'`; \
		ln -sf $$sorelprefix$(runtimelibdir)/$$soname \
		       $(DESTDIR)$(libdir)/libbsd.so; \
	fi
endif

uninstall-hook:
	rm -f $(DESTDIR)$(runtimelibdir)/libbsd*.so*
