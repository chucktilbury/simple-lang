
/* a little bit stubby */

#include <stddef.h>
#include <string.h>
#include "mem.h"
#include "str.h"

static void append(String* ptr, void* buf, int size) {

    if(ptr->len+size > ptr->cap) {
        while(ptr->len+size > ptr->cap)
            ptr->cap <<= 1;
        ptr->buf = _realloc_ds_array(ptr->buf, char, ptr->cap);
    }

    memcpy(&ptr->buf[ptr->len], buf, size);
    ptr->len += size;
}

String* create_string(const char* str) {

    String* ptr = _alloc_ds(String);
    ptr->len = 0;
    ptr->cap = 1 << 3;
    ptr->buf = _alloc_ds_array(char, ptr->cap);

    if(str != NULL)
        append(ptr, (void*)str, strlen(str));

    return ptr;
}

void append_string_str(String* ptr, const char* str) {

    append(ptr, (void*)str, strlen(str));
}

void append_string_char(String* ptr, int ch) {

    append(ptr, &ch, 1);
}

const char* get_string_ptr(String* ptr) {

    ptr->buf[ptr->len] = 0;
    return ptr->buf;
}

int get_string_len(String* ptr) {

    return ptr->len;
}

void clear_string(String* ptr) {

    ptr->len = 0;
}

