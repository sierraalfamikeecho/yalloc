#include <pthread.h>

#ifndef MALLOC_H
#define MALLOC_H

void *malloc(unsigned long);
header_t *get_free_block(size_t);

typedef struct size_t {
    unsigned long n;
} size_t;

union header {
    struct {
        size_t size;
        bool is_free;
        union header *next;
    } s;
    ALIGN stub;
};

typedef union header header_t;

#endif /* MALLOC_H */
