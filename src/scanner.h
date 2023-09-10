#ifndef _SCANNER_H
#define _SCANNER_H

#include <stdint.h>
#include "token_types.h"
#include "str.h"

typedef struct {
    TokenType type;
    String* str;
    union {
        const char* str;
        double fnum;
        uint64_t unum;
        int64_t inum;
        TokenType symbol;
    } value;
    const char* fname;
    int line;
    int col;
} Token;

void init_scanner(const char* fname);
Token* crnt_token();
void consume_token();

#endif /* _SCANNER_H */
