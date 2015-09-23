#ifndef LIBBSD_ARC4RANDOM_H
#define LIBBSD_ARC4RANDOM_H

#include <sys/param.h>

int
getentropy(void *buf, size_t len);

#if defined(__linux__)
#include "arc4random_linux.h"
#elif defined(__FreeBSD__)
#include "arc4random_bsd.h"
#elif defined(__NetBSD__)
#include "arc4random_bsd.h"
#elif defined(__OpenBSD__)
#include "arc4random_openbsd.h"
#elif defined(__sun)
#include "arc4random_unix.h"
#elif defined(__APPLE__)
#include "arc4random_unix.h"
#elif defined(_AIX)
#include "arc4random_unix.h"
#elif defined(__hpux)
#include "arc4random_unix.h"
#else
#error "No arc4random hooks defined for this platform."
#endif

#endif
