#ifndef _SCANNER_H
#define _SCANNER_H

#include "token_types.h"
#include "str.h"

typedef struct {
    token_type_t type;
    String str;
} Token;

void init_scanner(const char* fname);
Token* crnt_token();
void consume_token();

#endif /* _SCANNER_H */
