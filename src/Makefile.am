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
	libbsd.map \
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
	# EOL
libbsd_la_LIBADD = \
	$(MD5_LIBS) \
	$(LIBBSD_LIBS) \
	# EOL
libbsd_la_LDFLAGS = \
	-no-undefined \
	-version-number $(LIBBSD_ABI) \
	# EOL
if HAVE_LINKER_VERSION_SCRIPT
libbsd_la_LDFLAGS += \
	-Wl,--version-script=$(srcdir)/libbsd.map \
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
	closefrom.c \
	dehumanize_number.c \
	err.c \
	expand_number.c \
	explicit_bzero.c \
	fgetln.c \
	fgetwln.c \
	flopen.c \
	fmtcheck.c \
	fparseln.c \
	freezero.c \
	getbsize.c \
	getpeereid.c \
	heapsort.c \
	humanize_number.c \
	inet_net_pton.c \
	local-elf.h \
	local-link.h \
	merge.c \
	pidfile.c \
	progname.c \
	pwcache.c \
	radixsort.c \
	readpassphrase.c \
	reallocarray.c \
	reallocf.c \
	recallocarray.c \
	setmode.c \
	setproctitle.c \
	stringlist.c \
	strnstr.c \
	strtoi.c \
	strtonum.c \
	strtou.c \
	timeconv.c \
	unvis.c \
	vis.c \
	# EOL

if NEED_BSD_GETOPT
libbsd_la_SOURCES += \
	bsd_getopt.c \
	# EOL
endif

if NEED_ARC4RANDOM
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

if NEED_MD5
libbsd_la_SOURCES += \
	md5.c \
	# EOL
endif

if NEED_NLIST
libbsd_la_SOURCES += \
	nlist.c \
	# EOL
endif

if NEED_STRL
libbsd_la_SOURCES += \
	strlcat.c \
	strlcpy.c \
	# EOL
endif

if NEED_WCSL
libbsd_la_SOURCES += \
	wcslcat.c \
	wcslcpy.c \
	# EOL
endif

if NEED_STRMODE
libbsd_la_SOURCES += \
	strmode.c \
	# EOL
endif

if NEED_FPURGE
libbsd_la_SOURCES += \
	fpurge.c \
	# EOL
endif

if NEED_FUNOPEN
libbsd_la_SOURCES += \
	funopen.c \
	# EOL
endif

if NEED_TRANSPARENT_LIBMD
CLEANFILES += \
	format.ld \
	# EOL
endif

DISTCLEANFILES = \
	libbsd.sym \
	# EOL

libbsd_ctor_a_SOURCES = \
	setproctitle_ctor.c \
	# EOL

# Generate a simple libtool symbol export list to be used as a fallback if
# there is no version script support.
libbsd.sym: libbsd.map
	$(AM_V_GEN) $(SED) -ne 's/^[[:space:]]\{1,\}\([A-Za-z0-9_]\{1,\}\);/\1/p' libbsd.map > $@

if NEED_TRANSPARENT_LIBMD
TRANSPARENT_LIBMD_DEPENDS = format.ld

format.ld:
	$(CC) -shared -nostdlib -nostartfiles -x assembler /dev/null -o $@.so
	$(OBJDUMP) -f $@.so | sed -n 's/.*file format \(.*\)/OUTPUT_FORMAT(\1)/;T;p' > $@
	rm -f $@.so
endif

runtimelibdir = $(libdir)

install-exec-hook: $(TRANSPARENT_LIBMD_DEPENDS)
	if [ "$(libdir)" != "$(runtimelibdir)" ]; then \
		$(MKDIR_P) $(DESTDIR)$(runtimelibdir); \
		mv $(DESTDIR)$(libdir)/libbsd*.so.* \
		   $(DESTDIR)$(runtimelibdir)/; \
	fi
if NEED_TRANSPARENT_LIBMD
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
