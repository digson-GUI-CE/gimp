#ifdef __MUSL__
#include <err.h>

/* 模拟 error() 函数的行为 */
#define error(status, errnum, fmt, ...) \
    do { \
        if (errnum) \
            err(status, fmt ": %s", ##__VA_ARGS__, strerror(errnum)); \
        else \
            errx(status, fmt, ##__VA_ARGS__); \
    } while(0)
#endif
