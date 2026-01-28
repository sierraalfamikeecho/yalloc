#include "yalloc.h"

void free(void *block) {
    header_t *header, *temp;
    void *programbreak;

    if (!block) return;

    pthread_mutex_lock(&global_malloc_lock);
    header = (header_t*)block - 1;

    programbreak = sbrk(0);
    if ((char*)block + header->s.size == programbreak) {
        if (head == tail) {
            head = tail = NULL;
        } else {
            temporary = head;
            while (temporary) {
                if(temporary->s.next == tail) {
                    temporary->s.next = NULL;
                    tail = temporary;
                }
                temporary = temporary->s.next;
            }
        }
        sbrk(0 - sizeof(header_t) - header->s.size);
        pthread_mutex_unlock(&global_malloc_lock);

        return;
    }
    header->s.is_free = 1;
    pthread_mutex_unlock(&global_malloc_lock);
}
