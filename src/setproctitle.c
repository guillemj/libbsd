/*
 * Copyright © 2010 William Ahern
 * Copyright © 2012-2013 Guillem Jover <guillem@hadrons.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <errno.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

static struct {
	/* Original value. */
	const char *arg0;

	/* Title space available. */
	char *base, *end;

	 /* Pointer to original nul character within base. */
	char *nul;

	bool reset;
	int error;
} SPT;


static inline size_t
spt_min(size_t a, size_t b)
{
	return a < b ? a : b;
}

/*
 * For discussion on the portability of the various methods, see
 * http://lists.freebsd.org/pipermail/freebsd-stable/2008-June/043136.html
 */
static int
spt_clearenv(void)
{
#ifdef HAVE_CLEARENV
	return clearenv();
#else
	char **tmp;

	tmp = malloc(sizeof(*tmp));
	if (tmp == NULL)
		return errno;

	tmp[0] = NULL;
	environ = tmp;

	return 0;
#endif
}

static int
spt_copyenv(char *oldenv[])
{
	char *eq;
	int i, error;

	if (environ != oldenv)
		return 0;

	error = spt_clearenv();
	if (error) {
		environ = oldenv;
		return error;
	}

	for (i = 0; oldenv[i]; i++) {
		eq = strchr(oldenv[i], '=');
		if (eq == NULL)
			continue;

		*eq = '\0';
		if (setenv(oldenv[i], eq + 1, 1) < 0)
			error = errno;
		*eq = '=';

		if (error) {
			environ = oldenv;
			return error;
		}
	}

	return 0;
}

static int
spt_copyargs(int argc, char *argv[])
{
	char *tmp;
	int i;

	for (i = 1; i < argc || (i >= argc && argv[i]); i++) {
		if (argv[i] == NULL)
			continue;

		tmp = strdup(argv[i]);
		if (tmp == NULL)
			return errno;

		argv[i] = tmp;
	}

	return 0;
}

static void
spt_init(int argc, char *argv[], char *envp[])
{
	char *base, *end, *nul, *tmp;
	int i, error;

	/* Try to make sure we got called with main() arguments. */
	if (argc < 0)
		return;

	base = argv[0];
	if (base == NULL)
		return;

	nul = &base[strlen(base)];
	end = nul + 1;

	for (i = 0; i < argc || (i >= argc && argv[i]); i++) {
		if (argv[i] == NULL || argv[i] < end)
			continue;

		end = argv[i] + strlen(argv[i]) + 1;
	}

	for (i = 0; envp[i]; i++) {
		if (envp[i] < end)
			continue;

		end = envp[i] + strlen(envp[i]) + 1;
	}

	SPT.arg0 = strdup(argv[0]);
	if (SPT.arg0 == NULL) {
		SPT.error = errno;
		return;
	}

	tmp = strdup(getprogname());
	if (tmp == NULL) {
		SPT.error = errno;
		return;
	}
	setprogname(tmp);

	error = spt_copyenv(envp);
	if (error) {
		SPT.error = error;
		return;
	}

	error = spt_copyargs(argc, argv);
	if (error) {
		SPT.error = error;
		return;
	}

	SPT.nul  = nul;
	SPT.base = base;
	SPT.end  = end;
}

/*
 * Force spt_init() function into the .init_array section instead of expecting
 * either the compiler to place constructors there or the linker to move them
 * from .ctors to .init_array.
 */
void (*spt_init_func)(int argc, char *argv[], char *envp[])
	__attribute__((section(".init_array"))) = spt_init;

#ifndef SPT_MAXTITLE
#define SPT_MAXTITLE 255
#endif

void
setproctitle_impl(const char *fmt, ...)
{
	/* Use buffer in case argv[0] is passed. */
	char buf[SPT_MAXTITLE + 1];
	va_list ap;
	char *nul;
	int len;

	if (SPT.base == NULL)
		return;

	if (fmt) {
		if (fmt[0] == '-') {
			/* Skip program name prefix. */
			fmt++;
			len = 0;
		} else {
			/* Print program name heading for grep. */
			snprintf(buf, sizeof(buf), "%s: ", getprogname());
			len = strlen(buf);
		}

		va_start(ap, fmt);
		len += vsnprintf(buf + len, sizeof(buf) - len, fmt, ap);
		va_end(ap);
	} else {
		len = snprintf(buf, sizeof(buf), "%s", SPT.arg0);
	}

	if (len <= 0) {
		SPT.error = errno;
		return;
	}

	if (!SPT.reset) {
		memset(SPT.base, 0, SPT.end - SPT.base);
		SPT.reset = true;
	} else {
		memset(SPT.base, 0, spt_min(sizeof(buf), SPT.end - SPT.base));
	}

	len = spt_min(len, spt_min(sizeof(buf), SPT.end - SPT.base) - 1);
	memcpy(SPT.base, buf, len);
	nul = &SPT.base[len];

	if (nul < SPT.nul) {
		*SPT.nul = '.';
	} else if (nul == SPT.nul && &nul[1] < SPT.end) {
		*SPT.nul = ' ';
		*++nul = '\0';
	}
}
__asm__(".symver setproctitle_impl,setproctitle@@LIBBSD_0.5");

#ifdef HAVE_TYPEOF
/* The original function introduced in 0.2 was a stub, it only got implemented
 * in 0.5, make the implementation available in the old version as an alias
 * for code linking against that version, and change the default to use the
 * new version, so that new code depends on the implemented version. */
extern typeof(setproctitle_impl) setproctitle_stub __attribute__((alias("setproctitle_impl")));
__asm__(".symver setproctitle_stub,setproctitle@LIBBSD_0.2");
#endif
