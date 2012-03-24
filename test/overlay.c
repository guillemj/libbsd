/* Include system headers that are “known” to pull bits selectively from
 * other headers through magic macros, to check that the overlay is working
 * properly. */
#include <errno.h>
#include <grp.h>
#include <stdint.h>

/* Include libbsd overlayed headers that might get partially included. */
#include <sys/cdefs.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int
main()
{
	/* Test that we do not get partial definitions. */
	fflush(stdout);

	return 0;
}
