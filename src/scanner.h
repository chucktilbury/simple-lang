#ifndef _SCANNER_H
#define _SCANNER_H

#include <stdint.h>
#include "tokens.h"
#include "str.h"

typedef struct {
    token_type_t type;
    String str;
    union {
        const char* str;
        double fnum;
        uint64_t unum;
        int64_t inum;
        token_type_t symbol;
    } value;
    const char* fname;
    int line;
    int col;
} Token;

void init_scanner(const char* fname);
Token* crnt_token();
void consume_token();

#endif /* _SCANNER_H */
