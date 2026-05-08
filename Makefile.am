## Process this file with automake to produce Makefile.in

SUBDIRS = \
	include \
	man \
	src \
	test \
	# EOL

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = \
	autogen \
	get-version \
	# EOL

TAR_OPTIONS = --owner=0 --group=0
export TAR_OPTIONS

dist-hook:
	echo $(VERSION) >$(distdir)/.dist-version
	if [ -d .git ]; then \
	  XDG_CONFIG_HOME= HOME= git log --stat -C >$(distdir)/ChangeLog; \
	fi
