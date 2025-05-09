// CLIZ: C LIb Z
// c helpers
// buffer.c

#include "buffer.h"

int bb_init(ByteBuffer* bb, size_t length) {
    // initial size & length
    bb->length = 0;
    bb->size = 16;

    // make sure size is big enough
    while (bb->size <= length) bb->size *= 2;

    // allocate
    bb->buffer = malloc(bb->size);
    if (bb->buffer == NULL) return 1;

    // success
    return 0;
}

int bb_destroy(ByteBuffer* bb) {
    // handle freed buffer
    if (bb->buffer == NULL) return 0;

    // free
    free(bb->buffer);

    // set to NULL
    bb->buffer = NULL;
    bb->length = 0;
    bb->size = 0;

    // success
    return 0;
}

int bb_resize(ByteBuffer* bb) {
    // handle freed buffer
    if (bb->buffer == NULL) return 1;

    // if bb->size is 0, error
    if (bb->size == 0) return 1;
    
    // if its big enough, just return
    if (bb->size > bb->length) return 0;

    // calculate new needed size
    size_t new_size = bb->size;
    while (new_size <= bb->length) new_size *= 2;

    // realloc
    bb->buffer = realloc(bb->buffer, new_size);
    if (bb->buffer == NULL) return 1;

    // update size value
    bb->size = new_size;

    // success
    return 0;
}

int bb_appendb(ByteBuffer* bb, const BYTE* append, size_t sz) {
    // handle freed buffer
    if (bb->buffer == NULL) return 1;

    // cache bb->length so we know where to append from
    int old_length = bb->length;

    // resize buffer if needed
    bb->length += sz;
    if (bb_resize(bb)) {
        return 1;
    }

    // append to buffer
    memcpy(bb->buffer + old_length, append, sz);

    // success
    return 0;
}

int bb_appendbb(ByteBuffer* bb, const ByteBuffer* append) {
    // simplifies to a bb_appendb call
    return bb_appendb(bb, append->buffer, append->length);
}

int bb_appends(ByteBuffer* bb, const char* append) {
    // simplifies to a bb_appendb call
    return bb_appendb(bb, (const BYTE*)append, strlen(append));
}

int bb_null(ByteBuffer *bb) {
    // add a null terminator
    // since there's always bb->length+1 bytes in the buffer
    bb->buffer[bb->length] = '\0';

    // success
    return 0;
}

/*

// debug main
// for testing functions
int main() {
    ByteBuffer bb;
    bb_init(&bb, 10);
    bb_appends(&bb, "Hello");
    printf("%d %d\n", bb.length, bb.size);
    for (int i=0; i<10; i++) {bb_appends(&bb, " World!");}
    bb_null(&bb);
    printf("%s\n%d %d\n", bb.buffer, bb.length, bb.size);
    bb_destroy(&bb);
    return 0;
}

//*/