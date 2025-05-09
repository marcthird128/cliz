// CLIZ: C LIb Z
// c helpers
// vector.c

#include "vector.h"

int v_init(Vector* v, size_t size) {
    // initial size & length
    v->length = 0;
    v->size = 16;

    // make sure its big enough
    while (v->size <= size) v->size *= 2;

    // allocate
    v->buffer = malloc(v->size * sizeof(void*));
    if (v->buffer == NULL) return 1;

    // success
    return 0;
}

int v_destroy(Vector* v) {
    // handle null buffer
    if (v->buffer == NULL) return 0;

    // free
    free(v->buffer);

    // set to NULL/0
    v->buffer = NULL;
    v->length = 0;
    v->size = 0;

    // success
    return 0;
}

int v_resize(Vector* v) {
    // handle null buffer
    if (v->buffer == NULL) return 1;

    // error if size is 0
    if (v->size == 0) return 1;

    // if its big enough, return
    if (v->length < v->size) return 0;

    // calculate new size
    size_t new_size = v->size;
    while (new_size <= v->length) new_size *= 2;

    // realloc
    v->buffer = realloc(v->buffer, new_size * sizeof(void*));
    if (v->buffer == NULL) return 1;

    // update size
    v->size = new_size;

    // success
    return 0;
}

int v_push(Vector* v, void* item) {
    // handle null buffer
    if (v->buffer == NULL) return 1;

    // insert the item
    // at current length
    // since theres always v->length+1 slots
    v->buffer[v->length++] = item;

    // resize if needed
    if (v_resize(v)) return 1;

    // success
    return 0;
}

void* v_get(Vector* v, size_t index) {
    // handle null buffer
    if (v->buffer == NULL) return NULL;

    // handle out of bounds
    if (index >= v->length) return NULL;

    // return the item
    return v->buffer[index];
}

void* v_top(Vector* v) {
    // return top
    return v_get(v, v->length - 1);
}

void* v_pop(Vector* v) {
    // handle null buffer
    if (v->buffer == NULL) return NULL;

    // handle empty
    if (v->length == 0) return NULL;

    // return item
    return v->buffer[--v->length];
}