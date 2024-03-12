## Process this file with automake to produce Makefile.in

EXTRA_DIST = \
	mdX.3bsd \
	# EOL

CLEANFILES = \
	md5.3bsd \
	# EOL

SED_MD5_SUBST = -e 's/mdX/md5/g' -e 's/mdY/md4/g' -e 's/MDX/MD5/g'

md5.3bsd: $(srcdir)/mdX.3bsd
	$(AM_V_GEN) $(SED) $(SED_MD5_SUBST) $< >$@

dist_man_MANS = \
	LIST_CLASS_ENTRY.3bsd \
	LIST_CLASS_HEAD.3bsd \
	LIST_EMPTY.3bsd \
	LIST_ENTRY.3bsd \
	LIST_FIRST.3bsd \
	LIST_FOREACH.3bsd \
	LIST_FOREACH_FROM.3bsd \
	LIST_FOREACH_FROM_SAFE.3bsd \
	LIST_FOREACH_SAFE.3bsd \
	LIST_HEAD.3bsd \
	LIST_HEAD_INITIALIZER.3bsd \
	LIST_INIT.3bsd \
	LIST_INSERT_AFTER.3bsd \
	LIST_INSERT_BEFORE.3bsd \
	LIST_INSERT_HEAD.3bsd \
	LIST_NEXT.3bsd \
	LIST_PREV.3bsd \
	LIST_REMOVE.3bsd \
	LIST_SWAP.3bsd \
	RB_EMPTY.3bsd \
	RB_ENTRY.3bsd \
	RB_FIND.3bsd \
	RB_FOREACH.3bsd \
	RB_FOREACH_REVERSE.3bsd \
	RB_GENERATE.3bsd \
	RB_GENERATE_STATIC.3bsd \
	RB_HEAD.3bsd \
	RB_INIT.3bsd \
	RB_INITIALIZER.3bsd \
	RB_INSERT.3bsd \
	RB_LEFT.3bsd \
	RB_MAX.3bsd \
	RB_MIN.3bsd \
	RB_NEXT.3bsd \
	RB_NFIND.3bsd \
	RB_PARENT.3bsd \
	RB_PREV.3bsd \
	RB_PROTOTYPE.3bsd \
	RB_PROTOTYPE_STATIC.3bsd \
	RB_REMOVE.3bsd \
	RB_RIGHT.3bsd \
	RB_ROOT.3bsd \
	SLIST_CLASS_ENTRY.3bsd \
	SLIST_CLASS_HEAD.3bsd \
	SLIST_EMPTY.3bsd \
	SLIST_ENTRY.3bsd \
	SLIST_FIRST.3bsd \
	SLIST_FOREACH.3bsd \
	SLIST_FOREACH_FROM.3bsd \
	SLIST_FOREACH_FROM_SAFE.3bsd \
	SLIST_FOREACH_SAFE.3bsd \
	SLIST_HEAD.3bsd \
	SLIST_HEAD_INITIALIZER.3bsd \
	SLIST_INIT.3bsd \
	SLIST_INSERT_AFTER.3bsd \
	SLIST_INSERT_HEAD.3bsd \
	SLIST_NEXT.3bsd \
	SLIST_REMOVE.3bsd \
	SLIST_REMOVE_AFTER.3bsd \
	SLIST_REMOVE_HEAD.3bsd \
	SLIST_REMOVE_PREVPTR.3bsd \
	SLIST_SWAP.3bsd \
	SPLAY_EMPTY.3bsd \
	SPLAY_ENTRY.3bsd \
	SPLAY_FIND.3bsd \
	SPLAY_FOREACH.3bsd \
	SPLAY_GENERATE.3bsd \
	SPLAY_HEAD.3bsd \
	SPLAY_INIT.3bsd \
	SPLAY_INITIALIZER.3bsd \
	SPLAY_INSERT.3bsd \
	SPLAY_LEFT.3bsd \
	SPLAY_MAX.3bsd \
	SPLAY_MIN.3bsd \
	SPLAY_NEXT.3bsd \
	SPLAY_PROTOTYPE.3bsd \
	SPLAY_REMOVE.3bsd \
	SPLAY_RIGHT.3bsd \
	SPLAY_ROOT.3bsd \
	STAILQ_CLASS_ENTRY.3bsd \
	STAILQ_CLASS_HEAD.3bsd \
	STAILQ_CONCAT.3bsd \
	STAILQ_EMPTY.3bsd \
	STAILQ_ENTRY.3bsd \
	STAILQ_FIRST.3bsd \
	STAILQ_FOREACH.3bsd \
	STAILQ_FOREACH_FROM.3bsd \
	STAILQ_FOREACH_FROM_SAFE.3bsd \
	STAILQ_FOREACH_SAFE.3bsd \
	STAILQ_HEAD.3bsd \
	STAILQ_HEAD_INITIALIZER.3bsd \
	STAILQ_INIT.3bsd \
	STAILQ_INSERT_AFTER.3bsd \
	STAILQ_INSERT_HEAD.3bsd \
	STAILQ_INSERT_TAIL.3bsd \
	STAILQ_LAST.3bsd \
	STAILQ_NEXT.3bsd \
	STAILQ_REMOVE.3bsd \
	STAILQ_REMOVE_AFTER.3bsd \
	STAILQ_REMOVE_HEAD.3bsd \
	STAILQ_SWAP.3bsd \
	TAILQ_CLASS_ENTRY.3bsd \
	TAILQ_CLASS_HEAD.3bsd \
	TAILQ_CONCAT.3bsd \
	TAILQ_EMPTY.3bsd \
	TAILQ_ENTRY.3bsd \
	TAILQ_FIRST.3bsd \
	TAILQ_FOREACH.3bsd \
	TAILQ_FOREACH_FROM.3bsd \
	TAILQ_FOREACH_FROM_SAFE.3bsd \
	TAILQ_FOREACH_REVERSE.3bsd \
	TAILQ_FOREACH_REVERSE_FROM.3bsd \
	TAILQ_FOREACH_REVERSE_FROM_SAFE.3bsd \
	TAILQ_FOREACH_REVERSE_SAFE.3bsd \
	TAILQ_FOREACH_SAFE.3bsd \
	TAILQ_HEAD.3bsd \
	TAILQ_HEAD_INITIALIZER.3bsd \
	TAILQ_INIT.3bsd \
	TAILQ_INSERT_AFTER.3bsd \
	TAILQ_INSERT_BEFORE.3bsd \
	TAILQ_INSERT_HEAD.3bsd \
	TAILQ_INSERT_TAIL.3bsd \
	TAILQ_LAST.3bsd \
	TAILQ_NEXT.3bsd \
	TAILQ_PREV.3bsd \
	TAILQ_REMOVE.3bsd \
	TAILQ_SWAP.3bsd \
	be16dec.3bsd \
	be16enc.3bsd \
	be32dec.3bsd \
	be32enc.3bsd \
	be64dec.3bsd \
	be64enc.3bsd \
	bit_alloc.3bsd \
	bit_clear.3bsd \
	bit_decl.3bsd \
	bit_ffc.3bsd \
	bit_ffs.3bsd \
	bit_nclear.3bsd \
	bit_nset.3bsd \
	bit_set.3bsd \
	bit_test.3bsd \
	bitstr_size.3bsd \
	bitstring.3bsd \
	byteorder.3bsd \
	le16dec.3bsd \
	le16enc.3bsd \
	le32dec.3bsd \
	le32enc.3bsd \
	le64dec.3bsd \
	le64enc.3bsd \
	libbsd.7 \
	queue.3bsd \
	timeradd.3bsd \
	timerclear.3bsd \
	timercmp.3bsd \
	timerisset.3bsd \
	timersub.3bsd \
	timespecadd.3bsd \
	timespecclear.3bsd \
	timespeccmp.3bsd \
	timespecisset.3bsd \
	timespecsub.3bsd \
	tree.3bsd \
	# EOL

if API_TIME_MACROS
dist_man_MANS += \
	TIMESPEC_TO_TIMEVAL.3bsd \
	TIMEVAL_TO_TIMESPEC.3bsd \
	# EOL
endif

if ABI_ACCMODE
dist_man_MANS += \
	getmode.3bsd \
	setmode.3bsd \
	# EOL
endif

if ABI_ARC4RANDOM
dist_man_MANS += \
	arc4random.3bsd \
	arc4random_addrandom.3bsd \
	arc4random_buf.3bsd \
	arc4random_stir.3bsd \
	arc4random_uniform.3bsd \
	# EOL
endif

if ABI_CLOSEFROM
dist_man_MANS += \
	closefrom.3bsd \
	# EOL
endif

if ABI_ERRC
dist_man_MANS += \
	errc.3bsd \
	verrc.3bsd \
	vwarnc.3bsd \
	warnc.3bsd \
	# EOL
endif

if ABI_EXPAND_NUMBER
dist_man_MANS += \
	expand_number.3bsd \
	# EOL
endif

if ABI_EXPLICIT_BZERO
dist_man_MANS += \
	explicit_bzero.3bsd \
	# EOL
endif

if ABI_FGETLN
dist_man_MANS += \
	fgetln.3bsd \
	fgetwln.3bsd \
	fparseln.3bsd \
	# EOL
endif

if ABI_FLOPEN
dist_man_MANS += \
	flopen.3bsd \
	# EOL
endif

if ABI_FMTCHECK
dist_man_MANS += \
	fmtcheck.3bsd \
	# EOL
endif

if ABI_FPURGE
dist_man_MANS += \
	fpurge.3bsd \
	# EOL
endif

if ABI_FREEZERO
dist_man_MANS += \
	freezero.3bsd \
	# EOL
endif

if ABI_FUNOPEN
dist_man_MANS += \
	funopen.3bsd \
	# EOL
endif

if ABI_GETBSIZE
dist_man_MANS += \
	getbsize.3bsd \
	# EOL
endif

if ABI_GETPEEREID
dist_man_MANS += \
	getpeereid.3bsd \
	# EOL
endif

if ABI_HUMANIZE_NUMBER
dist_man_MANS += \
	dehumanize_number.3bsd \
	humanize_number.3bsd \
	# EOL
endif

if ABI_MD5
dist_man_MANS += \
	md5.3bsd \
	# EOL
endif

if ABI_NLIST
dist_man_MANS += \
	nlist.3bsd \
	# EOL
endif

if ABI_PIDFILE
dist_man_MANS += \
	pidfile.3bsd \
	pidfile_close.3bsd \
	pidfile_open.3bsd \
	pidfile_remove.3bsd \
	pidfile_write.3bsd \
	# EOL
endif

if ABI_PROCTITLE
dist_man_MANS += \
	setproctitle.3bsd \
	setproctitle_init.3bsd \
	# EOL
endif

if ABI_PROGNAME
dist_man_MANS += \
	getprogname.3bsd \
	setprogname.3bsd \
	# EOL
endif

if ABI_PWCACHE
dist_man_MANS += \
	pwcache.3bsd \
	gid_from_group.3bsd \
	uid_from_user.3bsd \
	# EOL

if ABI_NAME_FROM_ID
dist_man_MANS += \
	group_from_gid.3bsd \
	user_from_uid.3bsd \
	# EOL
endif
endif

if ABI_READPASSPHRASE
dist_man_MANS += \
	readpassphrase.3bsd \
	# EOL
endif

if ABI_REALLOCARRAY
dist_man_MANS += \
	reallocarray.3bsd \
	# EOL
endif

if ABI_REALLOCF
dist_man_MANS += \
	reallocf.3bsd \
	# EOL
endif

if ABI_RECALLOCARRAY
dist_man_MANS += \
	recallocarray.3bsd \
	# EOL
endif

if ABI_SORT
dist_man_MANS += \
	heapsort.3bsd \
	mergesort.3bsd \
	radixsort.3bsd \
	sradixsort.3bsd \
	# EOL
endif

if ABI_STRINGLIST
dist_man_MANS += \
	sl_add.3bsd \
	sl_delete.3bsd \
	sl_find.3bsd \
	sl_free.3bsd \
	sl_init.3bsd \
	stringlist.3bsd \
	# EOL
endif

if ABI_STRL
dist_man_MANS += \
	strlcat.3bsd \
	strlcpy.3bsd \
	# EOL
endif

if ABI_STRMODE
dist_man_MANS += \
	strmode.3bsd \
	# EOL
endif

if ABI_STRNSTR
dist_man_MANS += \
	strnstr.3bsd \
	# EOL
endif

if ABI_STRTOX
dist_man_MANS += \
	strtoi.3bsd \
	strtou.3bsd \
	# EOL
endif

if ABI_STRTONUM
dist_man_MANS += \
	strtonum.3bsd \
	# EOL
endif

if ABI_VIS
dist_man_MANS += \
	strnunvis.3bsd \
	strnvis.3bsd \
	strunvis.3bsd \
	strvis.3bsd \
	strvisx.3bsd \
	unvis.3bsd \
	vis.3bsd \
	# EOL
endif

if ABI_WCSL
dist_man_MANS += \
	wcslcat.3bsd \
	wcslcpy.3bsd \
	# EOL
endif
