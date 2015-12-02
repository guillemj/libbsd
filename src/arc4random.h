#ifndef LIBBSD_ARC4RANDOM_H
#define LIBBSD_ARC4RANDOM_H

#include <sys/param.h>

int
getentropy(void *buf, size_t len);

#if defined(__OpenBSD__)
#include "arc4random_openbsd.h"
#else
#include "arc4random_unix.h"
#endif

#endif
