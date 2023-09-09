/*
  this file is generated.
  --- DO NOT EDIT ---
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "tokens.h"

typedef struct {
    token_type_t type;
    const char* str;
    const char* name;
} token_value_t;

/* keywords */
static token_value_t keywords[] = {
    {AND, "and", "and operator"},
    {AS, "as", "as operator"},
    {BOOLEAN, "bool", "bool keyword"},
    {BREAK, "break", "break keyword"},
    {CASE, "case", "case keyword"},
    {CLASS, "class", "class keyword"},
    {CONST, "const", "const keyword"},
    {CONTINUE, "continue", "continue keyword"},
    {CREATE, "create", "create keyword"},
    {DEFAULT, "default", "default keyword"},
    {DESTROY, "destroy", "destroy keyword"},
    {DICT, "dict", "dict keyword"},
    {DO, "do", "do keyword"},
    {DYNAMIC, "dynamic", "dynamic keyword"},
    {ELSE, "else", "else keyword"},
    {ENTRY, "entry", "entry keyword"},
    {EXCEPT, "except", "except keyword"},
    {EXEC, "exec", "exec keyword"},
    {EXIT, "exit", "exit keyword"},
    {FALSE, "false", "false boolean literal"},
    {FLOAT, "float", "float keyword"},
    {FOR, "for", "for keyword"},
    {IBEGIN, "inline_begin", "inline_begin keyword"},
    {IEND, "inline_end", "inline_end keyword"},
    {IF, "if", "if keyword"},
    {IMPORT, "import", "import keyword"},
    {IN, "in", "in operator"},
    {INTEGER, "int", "integer  keyword"},
    {LIST, "list", "list keyword"},
    {MODULE, "module", "module keyword"},
    {NAMESPACE, "namespace", "namespace keyword"},
    {NOT, "not", "not operator"},
    {NOTHING, "nothing", "nothing keyword"},
    {OR, "or", "or operator"},
    {PRINT, "print", "print keyword"},
    {PRIVATE, "private", "private keyword"},
    {PROTECTED, "protected", "protected  keyword"},
    {PUBLIC, "public", "public keyword"},
    {RAISE, "raise", "raise keyword"},
    {RETURN, "return", "return keyword"},
    {STATIC, "static", "static keyword"},
    {STRING, "string", "string keyword"},
    {SWITCH, "switch", "switch keyword"},
    {TO, "to", "to operator"},
    {TRACE, "trace", "trace keyword"},
    {TRUE, "true", "true boolean literal"},
    {TRY, "try", "try keyword"},
    {UNSIGNED, "unsigned", "unsigned keyword"},
    {WHILE, "while", "while keyword"},
    {YIELD, "yield", "yield keyword"},
};

/* operators */
/* punctuation */
/* constructs */
/* overhead */

#define NUM_KEYWORDS (sizeof(keywords)/sizeof(token_value_t))

static token_type_t search(token_value_t* lst, const char* str, int start, int end) {

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

token_type_t search_keyword(const char* str) {
    return search(keywords, str, 0, NUM_KEYWORDS);
}

const char* tok_to_str(token_type_t type) {
    return
        (type == NAMESPACE)? "namespace keyword":
        (type == CLASS)? "class keyword":
        (type == CREATE)? "create keyword":
        (type == DESTROY)? "destroy keyword":
        (type == IF)? "if keyword":
        (type == ELSE)? "else keyword":
        (type == WHILE)? "while keyword":
        (type == DO)? "do keyword":
        (type == FOR)? "for keyword":
        (type == IN)? "in operator":
        (type == TO)? "to operator":
        (type == AS)? "as operator":
        (type == TRY)? "try keyword":
        (type == EXCEPT)? "except keyword":
        (type == RAISE)? "raise keyword":
        (type == RETURN)? "return keyword":
        (type == EXIT)? "exit keyword":
        (type == SWITCH)? "switch keyword":
        (type == CASE)? "case keyword":
        (type == YIELD)? "yield keyword":
        (type == TRACE)? "trace keyword":
        (type == PRINT)? "print keyword":
        (type == IMPORT)? "import keyword":
        (type == TRUE)? "true boolean literal":
        (type == FALSE)? "false boolean literal":
        (type == BREAK)? "break keyword":
        (type == CONTINUE)? "continue keyword":
        (type == IBEGIN)? "inline_begin keyword":
        (type == IEND)? "inline_end keyword":
        (type == ENTRY)? "entry keyword":
        (type == MODULE)? "module keyword":
        (type == DEFAULT)? "default keyword":
        (type == PUBLIC)? "public keyword":
        (type == PRIVATE)? "private keyword":
        (type == PROTECTED)? "protected  keyword":
        (type == INTEGER)? "integer  keyword":
        (type == UNSIGNED)? "unsigned keyword":
        (type == FLOAT)? "float keyword":
        (type == STRING)? "string keyword":
        (type == DICT)? "dict keyword":
        (type == LIST)? "list keyword":
        (type == BOOLEAN)? "bool keyword":
        (type == NOTHING)? "nothing keyword":
        (type == EXEC)? "exec keyword":
        (type == STATIC)? "static keyword":
        (type == DYNAMIC)? "dynamic keyword":
        (type == OR)? "or operator":
        (type == AND)? "and operator":
        (type == NOT)? "not operator":
        (type == CONST)? "const keyword":
        (type == ADD)? "+":
        (type == SUB)? "-":
        (type == MUL)? "*":
        (type == DIV)? "/":
        (type == MOD)? "%":
        (type == POW)? "^":
        (type == NOT)? "!":
        (type == EQU)? "==":
        (type == NEQU)? "!=":
        (type == LORE)? "<=":
        (type == GORE)? ">=":
        (type == ASSIGN)? "=":
        (type == ADD_ASSIGN)? "+=":
        (type == SUB_ASSIGN)? "-=":
        (type == MUL_ASSIGN)? "*=":
        (type == DIV_ASSIGN)? "/=":
        (type == MOD_ASSIGN)? "%=":
        (type == LESS)? "<":
        (type == MORE)? ">":
        (type == DOT)? ".":
        (type == COMMA)? "":
        (type == COLON)? ":":
        (type == CPAREN)? ")":
        (type == OPAREN)? "(":
        (type == OBLOCK)? "{":
        (type == CBLOCK)? "}":
        (type == OBRACE)? "[":
        (type == CBRACE)? "]":
        (type == SYMBOL)? "Identifier name":
        (type == STRG_CONST)? "String constant":
        (type == FLOAT_CONST)? "Float constant":
        (type == INT_CONST)? "Integer constant":
        (type == UNSIGNED_CONST)? "Unsigned constant":
        (type == END_OF_FILE)? "END OF FILE":
        (type == END_OF_INPUT)? "END OF INPUT":
        (type == ERROR)? "ERROR":
        "UNKNOWN";
}

