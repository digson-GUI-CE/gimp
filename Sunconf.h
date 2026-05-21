#ifndef GIMP_COMPAT_SOLARIS_H
#define GIMP_COMPAT_SOLARIS_H

#include <err.h>
#include <string.h>

/* Solaris 同样缺少 error.h */
#define error(status, errnum, fmt, ...) \
    do { \
        if (errnum) \
            err(status, fmt ": %s", ##__VA_ARGS__, strerror(errnum)); \
        else \
            errx(status, fmt, ##__VA_ARGS__); \
    } while(0)

/* Solaris 特有的额外修复（如果有） */
#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L  /* 启用 XPG7 特性 */
#endif

#endif
