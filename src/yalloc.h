#include <pthread.h>

#ifndef MALLOC_H
#define MALLOC_H

typedef unsigned long size_t;

union header {
    struct {
        size_t size;
        bool is_free;
        union header *next;
    } s;
    ALIGN stub;
};

typedef union header header_t;

void *malloc(size_t);
void *realloc(void*, size_t);
void *calloc(size_t, size_t);
void free(void*);

void *memcpy(void *, const void *, size_t);
void *memset_y(size_t, void [], int);


header_t *get_free_block(size_t);
#endif /* MALLOC_H */
