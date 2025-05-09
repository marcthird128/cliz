// CLIZ: C LIb Z
// c helpers
// vector.h

#ifndef __CLIZ_VECTOR_H__
#define __CLIZ_VECTOR_H__

#include <stdlib.h>

typedef struct Vector {
    void** buffer;
    size_t length; // current length in use
    size_t size; // buffer size
} Vector;

// returns 0 if success, 1 if fail
int v_init(Vector* v, size_t length); // init a new Vector
int v_destroy(Vector* v); // free a Vector
int v_resize(Vector* v); // makes sure the vector is resized
int v_push(Vector* v, void* val); // push a value

// returns the item
void* v_get(Vector* v, size_t index); // get a value by index
void* v_top(Vector* v); // get the top value
void* v_pop(Vector* v); // pop a value

#endif