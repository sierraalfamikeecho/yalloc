#include "yalloc.h"

void *calloc(size_t num, size_t nsize) {
    size_t size;
    void *block;

    if (!num || !nsize) return NULL;

    size = num * nsize;

    if (nsize != size / num) return NULL;

    block = malloc(size);

    if (!block) return NULL;

    memset_y(size, block, 0);

    return block;
}
