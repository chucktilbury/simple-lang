#ifndef _TOKENS_H
#define _TOKENS_H

#include "scanner.h"
#include "token_types.h"

typedef struct _token_queue_elem_t_ {
    Token* tok;
    struct _token_queue_elem_t_* next;
} token_queue_elem_t;

typedef struct {
    struct _token_queue_elem_t_* first;
    struct _token_queue_elem_t_* last;
} token_queue_t;

token_queue_t* create_token_queue();
void add_token_queue(token_queue_t* queue, Token* tok);

const char* tok_to_str(TokenType type);
TokenType search_keyword(const char* str);


#endif /* _TOKENS_H */

