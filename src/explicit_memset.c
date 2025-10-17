/* $NetBSD: explicit_memset.c,v 1.5 2024/11/02 02:43:48 riastradh Exp $ */

/*
 * Written by Matthias Drochner <drochner@NetBSD.org>.
 * Public domain.
 */

#include <string.h>

/*
 * The use of a volatile pointer guarantees that the compiler
 * will not optimise the call away.
 */
void *(* volatile explicit_memset_impl)(void *, int, size_t) = memset;

void *
explicit_memset(void *b, int c, size_t len)
{
	return (*explicit_memset_impl)(b, c, len);
}
