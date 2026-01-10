#include "realloc.h"

void *realloc(void *block, size_t size) {
    header_t *header;
    void *return_val;

    if (!block || !size) return malloc(size);

    header = (header_t*)block - 1;

    if (header->s.size >= size) return block;

    return_val = malloc(size);

    if (return_val) {

        memcpy(return_val,  block, header->s.size);
        free(block);
    }

    return return_val;
}
