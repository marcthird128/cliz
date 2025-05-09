// CLIZ: C LIb Z
// c helpers
// buffer.h

#ifndef __CLIZ_BUFFER_H__
#define __CLIZ_BUFFER_H__

#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

typedef struct ByteBuffer {
    BYTE* buffer;
    size_t size; // size of actual buffer
    size_t length; // length of used bytes
} ByteBuffer;

// 0 if success, 1 if fail
int bb_init(ByteBuffer* bb, size_t length); // initialze a new ByteBuffer
int bb_destroy(ByteBuffer* bb); // free ByteBuffer
int bb_resize(ByteBuffer* bb); // resize so bb->size > bb->length
int bb_appendb(ByteBuffer* bb, const BYTE* append, size_t sz); // appends an array of bytes
int bb_appendbb(ByteBuffer* bb, const ByteBuffer* append); // appends a ByteBuffer
int bb_appends(ByteBuffer* bb, const char* append); // appends a null-terminated string
int bb_null(ByteBuffer *bb); // null-terminate the buffer

#endif