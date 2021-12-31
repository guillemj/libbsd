## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
	-I$(top_builddir) \
	-isystem $(top_srcdir)/include/bsd/ \
	-include $(top_builddir)/config.h \
	-DLIBBSD_OVERLAY -DLIBBSD_DISABLE_DEPRECATED \
	-D__REENTRANT

if OS_WINDOWS
AM_CPPFLAGS += \
	-D_CRT_SECURE_NO_WARNINGS \
	-D_CRT_NONSTDC_NO_WARNINGS \
	$(nil)
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
	$(nil)

CLEANFILES =
EXTRA_DIST = \
	libbsd.map \
	libbsd.pc.in \
	libbsd-ctor.pc.in \
	libbsd-overlay.pc.in \
	$(libbsd_la_included_sources) \
	$(nil)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = \
	libbsd.pc \
	libbsd-overlay.pc \
	$(nil)

lib_LTLIBRARIES = libbsd.la
lib_LIBRARIES =

if BUILD_LIBBSD_CTOR
pkgconfig_DATA += libbsd-ctor.pc

lib_LIBRARIES += libbsd-ctor.a
endif

libbsd_la_DEPENDENCIES = \
	$(libbsd_la_included_sources) \
	libbsd.map
libbsd_la_LIBADD = \
	$(MD5_LIBS) \
	$(LIBBSD_LIBS) \
	$(nil)
libbsd_la_LDFLAGS = \
	-version-number $(LIBBSD_ABI)
if HAVE_LINKER_VERSION_SCRIPT
libbsd_la_LDFLAGS += \
	-Wl,--version-script=$(srcdir)/libbsd.map
endif
libbsd_la_SOURCES = \
	arc4random.c \
	arc4random.h \
	arc4random_linux.h \
	arc4random_uniform.c \
	arc4random_unix.h \
	arc4random_win.h \
	bsd_getopt.c \
	chacha_private.h \
	closefrom.c \
	dehumanize_number.c \
	err.c \
	expand_number.c \
	explicit_bzero.c \
	fgetln.c \
	freezero.c \
	fgetwln.c \
	flopen.c \
	fmtcheck.c \
	fparseln.c \
	fpurge.c \
	funopen.c \
	getbsize.c \
	getpeereid.c \
	heapsort.c \
	humanize_number.c \
	inet_net_pton.c \
	local-elf.h \
	local-link.h \
	md5.c \
	merge.c \
	nlist.c \
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
	strlcat.c \
	strlcpy.c \
	stringlist.c \
	strmode.c \
	strnstr.c \
	strtoi.c \
	strtonum.c \
	strtou.c \
	timeconv.c \
	unvis.c \
	vis.c \
	wcslcat.c \
	wcslcpy.c \
	$(nil)

if !HAVE_GETENTROPY
libbsd_la_SOURCES += \
	getentropy.c \
	$(nil)
endif

if NEED_TRANSPARENT_LIBMD
CLEANFILES += \
	format.ld \
	# EOL
endif

libbsd_ctor_a_SOURCES = \
	setproctitle_ctor.c \
	$(nil)

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
