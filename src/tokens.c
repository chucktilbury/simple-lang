
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "token_struct.h"

static TokenType search(token_list_t* lst, const char* str, int start, int end) {

    if(start >= end)
        return SYMBOL;
    else {
        int mid = (start + end) / 2;
        int val = strcmp(str, lst[mid].str);
        if(val == 0)
            return lst[mid].type;
        else if(val > 0)
            return search(lst, str, mid + 1, end);
        else
            return search(lst, str, start, end - 1);
    }
}

TokenType search_keyword(const char* str) {
    return search(token_list, str, 0, NUM_KEYWORDS);
}

const char* tok_to_str(TokenType type) {
    return TOK_TO_STR(type);
}

