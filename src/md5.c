/*
 * Copyright © 2021 Guillem Jover <guillem@hadrons.org>
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

#include <md5.h>
#include "local-link.h"

void
bsd_MD5Init(MD5_CTX *context)
{
	MD5Init(context);
}
libbsd_symver_variant(MD5Init, bsd_MD5Init, LIBBSD_0.0);

void
bsd_MD5Update(MD5_CTX *context, const uint8_t *data, size_t len)
{
	MD5Update(context, data, len);
}
libbsd_symver_variant(MD5Update, bsd_MD5Update, LIBBSD_0.0);

void
bsd_MD5Pad(MD5_CTX *context)
{
	MD5Pad(context);
}
libbsd_symver_variant(MD5Pad, bsd_MD5Pad, LIBBSD_0.0);

void
bsd_MD5Final(uint8_t digest[MD5_DIGEST_LENGTH], MD5_CTX *context)
{
	MD5Final(digest, context);
}
libbsd_symver_variant(MD5Final, bsd_MD5Final, LIBBSD_0.0);

void
bsd_MD5Transform(uint32_t state[4], const uint8_t block[MD5_BLOCK_LENGTH])
{
	MD5Transform(state, block);
}
libbsd_symver_variant(MD5Transform, bsd_MD5Transform, LIBBSD_0.0);

char *
bsd_MD5End(MD5_CTX *context, char *buf)
{
	return MD5End(context, buf);
}
libbsd_symver_variant(MD5End, bsd_MD5End, LIBBSD_0.0);

char *
bsd_MD5File(const char *filename, char *buf)
{
	return MD5File(filename, buf);
}
libbsd_symver_variant(MD5File, bsd_MD5File, LIBBSD_0.0);

char *
bsd_MD5FileChunk(const char *filename, char *buf, off_t offset, off_t length)
{
	return MD5FileChunk(filename, buf, offset, length);
}
libbsd_symver_variant(MD5FileChunk, bsd_MD5FileChunk, LIBBSD_0.0);

char *
bsd_MD5Data(const uint8_t *data, size_t len, char *buf)
{
	return MD5Data(data, len, buf);
}
libbsd_symver_variant(MD5Data, bsd_MD5Data, LIBBSD_0.0);
