## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
	-I$(top_builddir) \
	-isystem $(top_srcdir)/include/bsd/ \
	-include $(top_builddir)/config.h \
	-DLIBBSD_OVERLAY -DLIBBSD_DISABLE_DEPRECATED \
	-D__REENTRANT

check_PROGRAMS = \
	headers \
	overlay \
	endian \
	humanize \
	fgetln \
	proctitle \
	$(nil)

humanize_LDFLAGS = $(top_builddir)/src/libbsd.la
fgetln_LDFLAGS = $(top_builddir)/src/libbsd.la
proctitle_LDFLAGS = $(top_builddir)/src/libbsd.la

TESTS = $(check_PROGRAMS)
