#include <stdio.h>
#include <string.h> // For strlen, and for test data
#include <stdlib.h> // For exit()

// Use a path that your compiler can resolve.
// Forward slashes are generally more portable even on Windows.
#include "src/buffer.h"
#include "src/vector.h"

int main() {
    Vector v;
    v_init(&v, 10);
    v_push(&v, (void*) "Hello");
    for (int i=0; i<100; i++) {v_push(&v, (void*) "World");}
    printf("%d %d\n", v.length, v.size);
    printf((const char*) v_top(&v));
    v_destroy(&v);
    return 0;
}