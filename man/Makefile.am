## Process this file with automake to produce Makefile.in

EXTRA_DIST = \
	mdX.3bsd \
	$(nil)

CLEANFILES = \
	md5.3bsd \
	$(nil)

SED_MD5_SUBST = -e 's/mdX/md5/g' -e 's/mdY/md4/g' -e 's/MDX/MD5/g'

md5.3bsd: $(srcdir)/mdX.3bsd
	$(AM_V_GEN) sed $(SED_MD5_SUBST) $< > $@

dist_man_MANS = \
	arc4random.3bsd \
	arc4random_addrandom.3bsd \
	arc4random_buf.3bsd \
	arc4random_stir.3bsd \
	arc4random_uniform.3bsd \
	bitstring.3bsd \
	closefrom.3bsd \
	dehumanize_number.3bsd \
	expand_number.3bsd \
	explicit_bzero.3bsd \
	fgetln.3bsd \
	fgetwln.3bsd \
	flopen.3bsd \
	fmtcheck.3bsd \
	fparseln.3bsd \
	funopen.3bsd \
	getbsize.3bsd \
	getmode.3bsd \
	getpeereid.3bsd \
	getprogname.3bsd \
	heapsort.3bsd \
	humanize_number.3bsd \
	md5.3bsd \
	mergesort.3bsd \
	nlist.3bsd \
	pidfile.3bsd \
	queue.3bsd \
	radixsort.3bsd \
	readpassphrase.3bsd \
	reallocarray.3bsd \
	reallocf.3bsd \
	setmode.3bsd \
	setproctitle.3bsd \
	setprogname.3bsd \
	sradixsort.3bsd \
	stringlist.3bsd \
	strlcat.3bsd \
	strlcpy.3bsd \
	strnstr.3bsd \
	strmode.3bsd \
	strtonum.3bsd \
	tree.3bsd \
	unvis.3bsd \
	vis.3bsd \
	wcslcat.3bsd \
	wcslcpy.3bsd \
	$(nil)
