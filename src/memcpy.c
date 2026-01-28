#include "yalloc.h"

void *memcpy(void *restrict destination, const void *restrict source, size_t size) {
    unsigned char *d = destination;
    const unsigned char *s = source;

    while (size-- > 0) *d++ = *s++;

    return destination;
}
