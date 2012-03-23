## Process this file with automake to produce Makefile.in

# Set default values for user variables
CFLAGS = -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter

AM_CPPFLAGS = \
	-I$(top_builddir) \
	-isystem $(top_srcdir)/include/bsd/ \
	-include $(top_builddir)/config.h \
	-DLIBBSD_OVERLAY -DLIBBSD_DISABLE_DEPRECATED \
	-D__REENTRANT

check_PROGRAMS = \
	$(nil)

TESTS = $(check_PROGRAMS)
