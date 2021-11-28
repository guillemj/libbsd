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

#pragma GCC diagnostic ignored "-Wmissing-prototypes"

void
libbsd_MD5Init(MD5_CTX *context)
{
	MD5Init(context);
}
libbsd_link_warning(MD5Init,
                    "The MD5Init() function in libbsd is a deprecated wrapper, "
                    "use libmd instead.");
libbsd_symver_weak(MD5Init, libbsd_MD5Init, LIBBSD_0.0);

void
libbsd_MD5Update(MD5_CTX *context, const uint8_t *data, size_t len)
{
	MD5Update(context, data, len);
}
libbsd_link_warning(MD5Update,
                    "The MD5Update() function in libbsd is a deprecated wrapper, "
                    "use libmd instead.");
libbsd_symver_weak(MD5Update, libbsd_MD5Update, LIBBSD_0.0);

void
libbsd_MD5Pad(MD5_CTX *context)
{
	MD5Pad(context);
}
libbsd_link_warning(MD5Pad,
                    "The MD5Pad() function in libbsd is a deprecated wrapper, "
                    "use libmd instead.");
libbsd_symver_weak(MD5Pad, libbsd_MD5Pad, LIBBSD_0.0);

void
libbsd_MD5Final(uint8_t digest[MD5_DIGEST_LENGTH], MD5_CTX *context)
{
	MD5Final(digest, context);
}
libbsd_link_warning(MD5Final,
                    "The MD5Final() function in libbsd is a deprecated wrapper, "
                    "use libmd instead.");
libbsd_symver_weak(MD5Final, libbsd_MD5Final, LIBBSD_0.0);

void
libbsd_MD5Transform(uint32_t state[4], const uint8_t block[MD5_BLOCK_LENGTH])
{
	MD5Transform(state, block);
}
libbsd_link_warning(MD5Transform,
                    "The MD5Transform() function in libbsd is a deprecated wrapper, "
                    "use libmd instead.");
libbsd_symver_weak(MD5Transform, libbsd_MD5Transform, LIBBSD_0.0);

char *
libbsd_MD5End(MD5_CTX *context, char *buf)
{
	return MD5End(context, buf);
}
libbsd_link_warning(MD5End,
                    "The MD5End() function in libbsd is a deprecated wrapper, "
                    "use libmd instead.");
libbsd_symver_weak(MD5End, libbsd_MD5End, LIBBSD_0.0);

char *
libbsd_MD5File(const char *filename, char *buf)
{
	return MD5File(filename, buf);
}
libbsd_link_warning(MD5File,
                    "The MD5File() function in libbsd is a deprecated wrapper, "
                    "use libmd instead.");
libbsd_symver_weak(MD5File, libbsd_MD5File, LIBBSD_0.0);

char *
libbsd_MD5FileChunk(const char *filename, char *buf, off_t offset, off_t length)
{
	return MD5FileChunk(filename, buf, offset, length);
}
libbsd_link_warning(MD5FileChunk,
                    "The MD5FileChunk() function in libbsd is a deprecated wrapper, "
                    "use libmd instead.");
libbsd_symver_weak(MD5FileChunk, libbsd_MD5FileChunk, LIBBSD_0.0);

char *
libbsd_MD5Data(const uint8_t *data, size_t len, char *buf)
{
	return MD5Data(data, len, buf);
}
libbsd_link_warning(MD5Data,
                    "The MD5Data() function in libbsd is a deprecated wrapper, "
                    "use libmd instead.");
libbsd_symver_weak(MD5Data, libbsd_MD5Data, LIBBSD_0.0);
