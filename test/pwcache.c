/*
 * Copyright © 2021, 2023 Guillem Jover <guillem@hadrons.org>
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
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>

#define TEST_SKIP	77

int
main(int argc, char **argv)
{
	struct group *gr;
	struct passwd *pw;
	char *uname;
	char *gname;
	uid_t uid;
	gid_t gid;

	/* Do not hardcode user or group names. */
	pw = getpwuid(0);
	if (pw == NULL)
		return TEST_SKIP;
	uname = strdup(pw->pw_name);
	assert(uname != NULL);

	gr = getgrgid(0);
	if (gr == NULL) {
		free(uname);
		return TEST_SKIP;
	}
	gname = strdup(gr->gr_name);
	assert(gname != NULL);

	/* Test the functions. */
	assert(uid_from_user(uname, &uid) == 0);
	assert(uid == 0);

	assert(strcmp(user_from_uid(0, 0), uname) == 0);

	assert(gid_from_group(gname, &gid) == 0);
	assert(gid == 0);

	assert(strcmp(group_from_gid(0, 0), gname) == 0);

	free(uname);
	free(gname);

	return 0;
}
