## Process this file with automake to produce Makefile.in

EXTRA_DIST = \
	mdX.3 \
	$(nil)

CLEANFILES = \
	md5.3bsd \
	$(nil)

SED_MD5_SUBST = -e 's/mdX/md5/g' -e 's/mdY/md4/g' -e 's/MDX/MD5/g'

md5.3bsd: $(srcdir)/mdX.3
	$(AM_V_GEN) sed $(SED_MD5_SUBST) $< > $@

dist_man_MANS = \
	arc4random.3 \
	arc4random_addrandom.3 \
	arc4random_buf.3 \
	arc4random_stir.3 \
	arc4random_uniform.3 \
	dehumanize_number.3 \
	fgetln.3 \
	flopen.3 \
	fmtcheck.3 \
	getmode.3 \
	getpeereid.3 \
	heapsort.3 \
	humanize_number.3 \
	md5.3bsd \
	mergesort.3 \
	nlist.3 \
	pidfile.3 \
	radixsort.3 \
	readpassphrase.3 \
	reallocf.3 \
	setmode.3 \
	sradixsort.3 \
	strlcat.3 \
	strlcpy.3 \
	strmode.3 \
	strtonum.3 \
	unvis.3 \
	vis.3 \
	$(nil)