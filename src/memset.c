#include "yalloc.h"

void *memset_y(size_t num, void s[num], int constant) {
    size_t i;
    
    while (i = num, i >= 0, i--) s[i] = constant;

    return *s;
}
