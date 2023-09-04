/* generated file. DO NOT EDIT */
#ifndef _TOKEN_TYPES_H
#define _TOKEN_TYPES_H

typedef enum {
    /* keywords */
    NAMESPACE = 1000,
    CLASS,
    CREATE,
    DESTROY,
    IF,
    ELSE,
    WHILE,
    DO,
    FOR,
    IN,
    TO,
    AS,
    TRY,
    EXCEPT,
    RAISE,
    RETURN,
    EXIT,
    SWITCH,
    CASE,
    YIELD,
    TRACE,
    PRINT,
    IMPORT,
    TRUE,
    FALSE,
    BREAK,
    CONTINUE,
    IBEGIN,
    IEND,
    ENTRY,
    MODULE,
    DEFAULT,
    PUBLIC,
    PRIVATE,
    PROTECTED,
    INTEGER,
    UNSIGNED,
    FLOAT,
    STRING,
    DICT,
    LIST,
    BOOLEAN,
    NOTHING,
    EXEC,
    STATIC,
    DYNAMIC,
    OR,
    AND,
    NOT,
    /* operators */
    DOT,
    COMMA,
    COLON,
    CPAREN,
    OPAREN,
    OBLOCK,
    CBLOCK,
    OBRACE,
    CBRACE,
    ASSIGN,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    POW,
    NOT,
    EQU,
    NEQU,
    LORE,
    GORE,
    ADD_ASSIGN,
    SUB_ASSIGN,
    MUL_ASSIGN,
    DIV_ASSIGN,
    MOD_ASSIGN,
    LESS,
    MORE,
    /* constructs */
    SYMBOL,
    STRG_CONST,
    FLOAT_CONST,
    INT_CONST,
    UNSIGNED_CONST,
} token_t;

typedef struct {
    token_t type;
    const char* str;
    const char* name;
} token_value_t = {
    /* keywords */
    {NAMESPACE,  "namespace",  "namespace keyword"},
    {CLASS,  "class",  "class keyword"},
    {CREATE,  "create",  "create keyword"},
    {DESTROY,  "destroy",  "destroy keyword"},
    {IF,  "if",  "if keyword"},
    {ELSE,  "else",  "else keyword"},
    {WHILE,  "while",  "while keyword"},
    {DO,  "do",  "do keyword"},
    {FOR,  "for",  "for keyword"},
    {IN,  "in",  "in keyword"},
    {TO,  "to",  "to keyword"},
    {AS,  "as",  "as keyword"},
    {TRY,  "try",  "try keyword"},
    {EXCEPT,  "except",  "except keyword"},
    {RAISE,  "raise",  "raise keyword"},
    {RETURN,  "return",  "return keyword"},
    {EXIT,  "exit",  "exit keyword"},
    {SWITCH,  "switch",  "switch keyword"},
    {CASE,  "case",  "case keyword"},
    {YIELD,  "yield",  "yield keyword"},
    {TRACE,  "trace",  "trace keyword"},
    {PRINT,  "print",  "print keyword"},
    {IMPORT,  "import",  "import keyword"},
    {TRUE,  "true",  "true boolean literal"},
    {FALSE,  "false",  "false boolean literal"},
    {BREAK,  "break",  "break keyword"},
    {CONTINUE,  "continue",  "continue keyword"},
    {IBEGIN,  "inline_begin",  "inline_begin keyword"},
    {IEND,  "inline_end",  "inline_end keyword"},
    {ENTRY,  "entry",  "entry keyword"},
    {MODULE,  "module",  "module keyword"},
    {DEFAULT,  "default",  "default keyword"},
    {PUBLIC,  "public",  "public keyword"},
    {PRIVATE,  "private",  "private keyword"},
    {PROTECTED,  "protected",  "protected  keyword"},
    {INTEGER,  "int",  "integer  keyword"},
    {UNSIGNED,  "unsigned",  "unsigned keyword"},
    {FLOAT,  "float",  "float keyword"},
    {STRING,  "string",  "string keyword"},
    {DICT,  "dict",  "dict keyword"},
    {LIST,  "list",  "list keyword"},
    {BOOLEAN,  "bool",  "bool keyword"},
    {NOTHING,  "nothing",  "nothing keyword"},
    {EXEC,  "exec",  "exec keyword"},
    {STATIC,  "static",  "static keyword"},
    {DYNAMIC,  "dynamic",  "dynamic keyword"},
    {OR,  "or",  "or operator"},
    {AND,  "and",  "and operator"},
    {NOT,  "not",  "not operator"},
    /* operators */
    {DOT,  ".",  "."},
    {COMMA,  ", "},
    {COLON,  ":",  ":"},
    {CPAREN,  ")",  ")"},
    {OPAREN,  "(",  "("},
    {OBLOCK,  "{",  "{"},
    {CBLOCK,  "}",  "}"},
    {OBRACE,  "[",  "["},
    {CBRACE,  "]",  "]"},
    {ASSIGN,  "=",  "="},
    {ADD,  "+",  "+"},
    {SUB,  "-",  "-"},
    {MUL,  "*",  "*"},
    {DIV,  "/",  "/"},
    {MOD,  "%",  "%"},
    {POW,  "^",  "^"},
    {NOT,  "!",  "!"},
    {EQU,  "==",  "=="},
    {NEQU,  "!=",  "!="},
    {LORE,  "<=",  "<="},
    {GORE,  ">=",  ">="},
    {ADD_ASSIGN,  "+=",  "+="},
    {SUB_ASSIGN,  "-=",  "-="},
    {MUL_ASSIGN,  "*=",  "*="},
    {DIV_ASSIGN,  "/=",  "/="},
    {MOD_ASSIGN,  "%=",  "%="},
    {LESS,  "<",  "<"},
    {MORE,  ">",  ">"},
    /* constructs */
    {SYMBOL,  "",  "Identifier name"},
    {STRG_CONST,  "",  "String constant"},
    {FLOAT_CONST,  "",  "Float constant"},
    {INT_CONST,  "",  "Integer constant"},
    {UNSIGNED_CONST,  "",  "Unsigned constant"},
};

#endif /* _TOKEN_TYPES_H */
