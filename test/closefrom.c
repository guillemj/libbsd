/*
 * Copyright © 2015 Guillem Jover <guillem@hadrons.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
	int i;
	int fd;
	int fd_max;

	fd = open("/dev/null", O_RDONLY);

	fd_max = 1024;

	/* First make sure we have a clean fd list. */
	for (i = 4; i < fd_max; i++)
		close(i);

	/* Then initialize each even fd. */
	for (i = 4; i < fd_max; i *= 2) {
		int fd_new = dup2(fd, i);

		if (fd_new < 0 && (errno == EMFILE || errno == EBADF)) {
			fd_max = i - 1;
			break;
		}
		assert(fd_new == i);
	}

	if (fd < 4)
		close(fd);
	closefrom(4);

	for (i = 4; i < fd_max; i++) {
		int rc;

		errno = 0;
		rc = fcntl(i, F_GETFD);
#ifdef __APPLE__
		/* On macOS we only set close-on-exec. */
		if ((i & (i - 1)) == 0)
			assert(rc == FD_CLOEXEC);
		else
			assert(rc == -1 && errno == EBADF);
#else
		assert(rc == -1 && errno == EBADF);
#endif
	}
	assert(fcntl(fd, F_GETFL) == -1 && errno == EBADF);

	return 0;
}
