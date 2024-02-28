## Process this file with automake to produce Makefile.in

nobase_include_HEADERS = \
	bsd/sys/bitstring.h \
	bsd/sys/cdefs.h \
	bsd/sys/endian.h \
	bsd/sys/param.h \
	bsd/sys/poll.h \
	bsd/sys/queue.h \
	bsd/sys/time.h \
	bsd/sys/tree.h \
	bsd/netinet/ip_icmp.h \
	bsd/bitstring.h \
	bsd/bsd.h \
	bsd/inttypes.h \
	bsd/libutil.h \
	bsd/stdio.h \
	bsd/stdlib.h \
	bsd/string.h \
	bsd/unistd.h \
	bsd/wchar.h \
	# EOL

if ABI_ERR_H
nobase_include_HEADERS += \
	bsd/err.h \
	# EOL
endif

if ABI_BSD_GETOPT
nobase_include_HEADERS += \
	bsd/getopt.h \
	# EOL
endif

if ABI_MD5
nobase_include_HEADERS += \
	bsd/md5.h \
	# EOL
endif

if ABI_NLIST
nobase_include_HEADERS += \
	bsd/nlist.h \
	# EOL
endif

if ABI_READPASSPHRASE
nobase_include_HEADERS += \
	bsd/readpassphrase.h \
	# EOL
endif

if ABI_PWCACHE
nobase_include_HEADERS += \
	bsd/grp.h \
	bsd/pwd.h \
	# EOL
endif

if ABI_STRINGLIST
nobase_include_HEADERS += \
	bsd/stringlist.h \
	# EOL
endif

if ABI_TIMECONV
nobase_include_HEADERS += \
	bsd/timeconv.h \
	# EOL
endif

if ABI_VIS
nobase_include_HEADERS += \
	bsd/vis.h \
	# EOL
endif

do_header_subst = $(AM_V_GEN) $(SED) \
	-e 's:^//\(.define LIBBSD_SYS_TIME_BITS\).*:\1 $(LIBBSD_SYS_TIME_BITS):' \
	-e 's:^//\(.define LIBBSD_SYS_HAS_TIME64\).*:\1 $(LIBBSD_SYS_HAS_TIME64):' \
	# EOL

install-data-hook:
	$(do_header_subst) <$(DESTDIR)$(includedir)/bsd/sys/cdefs.h \
	                   >$(DESTDIR)$(includedir)/bsd/sys/cdefs.h.new
	mv  $(DESTDIR)$(includedir)/bsd/sys/cdefs.h.new \
	    $(DESTDIR)$(includedir)/bsd/sys/cdefs.h
