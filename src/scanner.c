
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "mem.h"
#include "errors.h"
#include "scanner.h"
#include "filebuf.h"

// The current token
static Token crnt_tok;
// This is used to translate a string to a token value using binary search.
static struct _token_list_ {
    TokenType type;
    const char* str;
} token_list[] = {
    // Note that this data structure **must** be in sorted order.
    {TOK_AND, "and"},
    {TOK_BOOLEAN, "bool"},
    {TOK_BOOLEAN, "boolean"},
    {TOK_BREAK, "break"},
    {TOK_CONST, "const"},
    {TOK_CONTINUE, "continue"},
    {TOK_DO, "do"},
    {TOK_ELSE, "else"},
    {TOK_EQU, "equ"},
    {TOK_EXIT, "exit"},
    {TOK_FALSE, "false"},
    {TOK_FLOAT, "float"},
    {TOK_IF, "if"},
    {TOK_IMPORT, "import"},
    {TOK_INT, "int"},
    {TOK_INT, "integer"},
    {TOK_NEQU, "neq"},
    {TOK_NOTHING, "noth"},
    {TOK_NOTHING, "nothing"},
    {TOK_NOT, "not"},
    {TOK_OR, "or"},
    {TOK_PRINT, "print"},
    {TOK_RETURN, "return"},
    {TOK_STRING, "strg"},
    {TOK_STRING, "string"},
    {TOK_STRUCT, "struct"},
    {TOK_TRACE, "trace"},
    {TOK_TRUE, "true"},
    {TOK_TYPE, "type"},
    {TOK_UINT, "uint"},
    {TOK_UINT, "unsigned"},
    {TOK_WHILE, "while"},
    {TOK_YIELD, "yield"},
};
// number of items in the data structure list.
#define NUM_TOK_LST (sizeof(token_list)/sizeof(struct _token_list_))

/**
 * @brief Return whether this character can be at the end of something like a
 * number.
 *
 * @param ch
 * @return true
 * @return false
 */
static bool isstopper(int ch) {

    return (isspace(ch) || ispunct(ch) || ch == '\n' || ch == '\r');
}

/**
 * @brief Consume the current char and save it to the token buffer.
 *
 */
static void save_char() {

    append_string_char(crnt_tok.str, get_crnt_char());
    consume_char();
}

/**
 * @brief Discard all characters up to and including the next '\n'.
 *
 */
static void eat_comment() {

    consume_char();    // discard the ';'
    while(true) {
        if(get_crnt_char() == '\n')
            break;
        else if(get_crnt_char() == END_OF_INPUT) {
            syntax("unexpected end of file in comment");
            exit(1);
        }
        else
            consume_char();
    }
}

/**
 * @brief Read alpha numeric characters and store them in the string.
 *
 */
static void get_name() {

    while(true) {
        int ch = get_crnt_char();
        if(isalnum(ch) || ch == '_')
            save_char();
        else
            break;
    }
}

/**
 * @brief Do a binary search on the array. It returns a pointer to the data
 * that was found or NULL if the string was not found.
 *
 * @param lst
 * @param str
 * @param start
 * @param end
 * @return struct _token_list_*
 */
static struct _token_list_* search(struct _token_list_* lst,
                                    const char* str, int start, int end) {
    if(start >= end)
        return NULL;
    else {
        int mid = (start + end) / 2;
        int val = strcmp(str, lst[mid].str);
        if(val == 0)
            return &lst[mid];
        else if(val > 0)
            return search(lst, str, mid + 1, end);
        else
            return search(lst, str, start, end - 1);
    }
}

/**
 * @brief Scan the token list with a binary search. If the string is found,
 * then return the token value. Otherwise, return the TOK_SYMBOL token value.
 *
 * @return TokenType
 */
static TokenType check_keyword(const char* str) {

    TokenType type = TOK_SYMBOL;
    struct _token_list_* tok = search(token_list, str, 0, NUM_TOK_LST);

    if(tok != NULL)
        type = tok->type;

    return type;
}

/**
 * @brief Read a single quoted string with no interpretations.
 *
 */
static void get_squote() {

    // discard the '\'' that was read before.
    consume_char();

    while(true) {
        int ch = get_crnt_char();
        if(ch != '\'')
            save_char();
        else if(ch == END_OF_INPUT) {
            syntax("end of file reached before end of string");
            return;
        }
        else {
            consume_char();
            return; // finished
        }
    }
}

/**
 * @brief Read a double quoted string with interpretations of escape
 * characters.
 *
 */
static void get_dquote() {

    // discard the '\"' that was read before.
    consume_char();

    while(true) {
        int ch = get_crnt_char();
        if(ch != '\"') {
            // perform the substitutions
            append_string_char(crnt_tok.str, ch);
            consume_char();
        }
        else if(ch == END_OF_INPUT) {
            syntax("end of file reached before end of string");
            return;
        }
        else {
            consume_char(); // consume the closing '\"'
            return; // finished
        }
    }
}

/**
 * @brief Get the operator and store the token.
 *
 */
static void get_operator() {

    // current character is the first character of the operator
    switch(get_crnt_char()) {
        case '!':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = TOK_NEQU;
            }
            else
                crnt_tok.type = TOK_ERROR;
            break;
        case '+':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = TOK_ADD_ASSIGN;
            }
            else
                crnt_tok.type = TOK_ADD;
            break;
        case '-':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = TOK_SUB_ASSIGN;
            }
            else
                crnt_tok.type = TOK_SUB;
            break;
        case '*':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = TOK_MUL_ASSIGN;
            }
            else
                crnt_tok.type = TOK_MUL;
            break;
        case '/':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = TOK_DIV_ASSIGN;
            }
            else
                crnt_tok.type = TOK_DIV;
            break;
        case '%':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = TOK_MOD_ASSIGN;
            }
            else
                crnt_tok.type = TOK_MOD;
            break;
        case '=':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = TOK_EQU; // "=="
            }
            else
                crnt_tok.type = TOK_EQUAL; // assignment
            break;
        case '<':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = TOK_ADD_ASSIGN;
            }
            else
                crnt_tok.type = TOK_OPBRACE;
            break;
        case '>':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = TOK_ADD_ASSIGN;
            }
            else
                crnt_tok.type = TOK_CPBRACE;
            break;

        case '(':
            save_char();
            crnt_tok.type = TOK_OPAREN;
            break;
        case ')':
            save_char();
            crnt_tok.type = TOK_CPAREN;
            break;
        case '[':
            save_char();
            crnt_tok.type = TOK_OSBRACE;
            break;
        case ']':
            save_char();
            crnt_tok.type = TOK_CSBRACE;
            break;
        case '{':
            save_char();
            crnt_tok.type = TOK_OCBRACE;
            break;
        case '}':
            save_char();
            crnt_tok.type = TOK_CCBRACE;
            break;
        case ',':
            save_char();
            crnt_tok.type = TOK_COMMA;
            break;
        case '.':
            save_char();
            crnt_tok.type = TOK_DOT;
            break;
    }
}

/**
 * @brief Read hex digits and return the char of the first thing that is
 * not a digit.
 *
 */
static void get_xdigits() {

    while(true) {
        if(isxdigit(get_crnt_char())) {
            append_string_char(crnt_tok.str, get_crnt_char());
            consume_char();
        }
        else
            break;
    }
}

/**
 * @brief Read digits and return the char of the first thing that is not
 * a digit.
 *
 */
static void get_digits() {

    while(true) {
        if(isdigit(get_crnt_char())) {
            append_string_char(crnt_tok.str, get_crnt_char());
            consume_char();
        }
        else
            break;
    }
}

/**
 * @brief Get the tail of a float. This gets the par of the
 * number after the '.' was read.
 *
 */
static void get_float_tail() {

    int ch = get_crnt_char();
    if(!isdigit(ch)) {
        crnt_tok.type = TOK_ERROR;
        syntax("expected a digit but got a '%c'", ch);
    }
    else
        get_digits();

    ch = get_crnt_char();
    // check for an exponent
    if(ch == 'e' || ch == 'E') {
        save_char();
        ch = get_crnt_char();
        if(ch == '+' || ch == '-') {
            // save the exponent sign
            save_char();
            ch = get_crnt_char();
            if(!isdigit(ch)) {
                crnt_tok.type = TOK_ERROR;
                syntax("expected a digit but got a '%c'", ch);
            }
            else
                get_digits();
        }
    }
}

/**
 * @brief Reset the token to be blank.
 *
 */
static void clear_token() {

    clear_string(crnt_tok.str);
    crnt_tok.type = TOK_END_INPUT;
}

/**
 * @brief Init the data structures used by tokens.
 *
 */
void init_scanner(const char* fname) {

    init_charbuffer(fname);
    crnt_tok.str = create_string(NULL);
    consume_token();
}

/**
 * @brief Scan the next token and return a const pointer to it.
 *
 */
void consume_token() {


    int ch;
    int state = 0;
    int finished = 0;

    clear_token();

    while(!finished) {
        ch = get_crnt_char();
        // getting a name
        // skip a comment
        if(ch == ';') {
            eat_comment();
        }
        // do nothing... skip some space
        else if(isspace(ch)) {
            consume_char();
        }
        else if(ch == END_OF_INPUT) {
            crnt_tok.type = TOK_END_INPUT;
            finished++;
        }
        else if(isalpha(ch)||ch == '_') {
            save_char();
            get_name();
            crnt_tok.type = check_keyword(get_string_ptr(crnt_tok.str));
            finished++;
        }
        // number that starts with 0
        else if(ch == '0') {
            save_char();
            int ch = get_crnt_char();
            // Octal numbers are not supported.
            if(isdigit(ch)) {
                syntax("Malformed number. Octal number syntax is not supported.");
                crnt_tok.type = TOK_ERROR;
            }
            // if the next char is a 'x' or 'X', then its unsigned
            else if(ch == 'x' || ch == 'X') {
                save_char();
                get_xdigits();
                crnt_tok.type = TOK_UNUM;

                ch = get_crnt_char();
                if(!isstopper(ch)) {
                    syntax("Malformed number. Expected space or operator but got '%c'", ch);
                    crnt_tok.type = TOK_ERROR;
                }
            }
            // if the next char is a '.', then it's a float
            else if(ch == '.') {
                save_char(); // save the dot. The next char should be a digit.
                get_float_tail();
                crnt_tok.type = TOK_FNUM;
            }
            // if the next character is not a digit then it's just a 0 by itself
            else {
                crnt_tok.type = TOK_INUM;
            }
            finished++;
        }
        // another digit
        else if(isdigit(ch)) {
            // the number could be a signed number or a float
            save_char();
            get_digits();
            // if the current char is a '.' then it's a float, otherwise
            // it's finished.
            if(get_crnt_char() == '.') {
                save_char(); // save the dot. The next char should be a digit.
                get_float_tail();
                crnt_tok.type = TOK_FNUM;
            }
            else {
                crnt_tok.type = TOK_INUM;
            }
            // numbers must be followed by space or operator
            int ch = get_crnt_char();
            if(!isstopper(ch)) {
                syntax("Malformed number. Expected space or operator but got '%c'", ch);
                crnt_tok.type = TOK_ERROR;
            }
            finished++;
        }
        // read a single quote string
        else if(ch == '\'') {
            get_squote();
            crnt_tok.type = TOK_QSTRG;
            finished++;
        }
        // read a double quote string
        else if(ch == '\"') {
            get_dquote();
            crnt_tok.type = TOK_QSTRG;
            finished++;
        }
        // read an operator. These a figured out in a switch/case elsewhere.
        else if(ispunct(ch)) {
            get_operator();
            finished++;
        }
        // Read a character that we don't know how to handle. Skip it,
        // issue a warning, and then continue scanning.
        else {
            warning("unknown character seen: 0x%02X", ch);
            consume_char();
        }
    }
}

/**
 * @brief Return a pointer to the current token.
 *
 * @return Token*
 */
Token* crnt_token() {

    return &crnt_tok;
}

/**
 * @brief Return a string that represents the token ID. For error handling.
 *
 * @param tt
 * @return const char*
 */
const char* tokToStr(TokenType tt) {

    return ( tt == TOK_BREAK)? "break":
        ( tt == TOK_CONTINUE)? "continue":
        ( tt == TOK_CONST)? "const":
        ( tt == TOK_IMPORT)? "import":
        ( tt == TOK_DO)? "do":
        ( tt == TOK_ELSE)? "else":
        ( tt == TOK_IF)? "if":
        ( tt == TOK_RETURN)? "return":
        ( tt == TOK_WHILE)? "while":
        ( tt == TOK_TRUE)? "true":
        ( tt == TOK_FALSE)? "false":
        ( tt == TOK_YIELD)? "yield":
        ( tt == TOK_EXIT)? "exit":
        ( tt == TOK_STRUCT)? "struct":
        ( tt == TOK_TRACE)? "trace":
        ( tt == TOK_PRINT)? "print":
        ( tt == TOK_TYPE)? "type":
        ( tt == TOK_INT)? "integer":
        ( tt == TOK_UINT)? "unsigned":
        ( tt == TOK_NOTHING)? "nothing":
        ( tt == TOK_STRING)? "string":
        ( tt == TOK_BOOLEAN)? "boolean":
        ( tt == TOK_FLOAT)? "float":
        ( tt == TOK_LORE)? "<=":
        ( tt == TOK_GORE)? ">=":
        ( tt == TOK_EQU)? "equ":
        ( tt == TOK_NEQU)? "neq":
        ( tt == TOK_OR)? "or":
        ( tt == TOK_AND)? "and":
        ( tt == TOK_ADD_ASSIGN)? "+=":
        ( tt == TOK_SUB_ASSIGN)? "-=":
        ( tt == TOK_MUL_ASSIGN)? "*=":
        ( tt == TOK_DIV_ASSIGN)? "/=":
        ( tt == TOK_MOD_ASSIGN)? "%=":
        ( tt == TOK_NOT)? "not":
        ( tt == TOK_ADD)? "+":
        ( tt == TOK_SUB)? "-":
        ( tt == TOK_MUL)? "*":
        ( tt == TOK_DIV)? "/":
        ( tt == TOK_MOD)? "%":
        ( tt == TOK_EQUAL)? "=":
        ( tt == TOK_OPAREN)? "(":
        ( tt == TOK_CPAREN)? ")":
        ( tt == TOK_OPBRACE)? "<":
        ( tt == TOK_CPBRACE)? ">":
        ( tt == TOK_OSBRACE)? "[":
        ( tt == TOK_CSBRACE)? "]":
        ( tt == TOK_OCBRACE)? "{":
        ( tt == TOK_CCBRACE)? "}":
        ( tt == TOK_COMMA)? ",":
        ( tt == TOK_DOT)? ".":
        ( tt == TOK_SYMBOL)? "SYMBOL":
        ( tt == TOK_INUM)? "INT":
        ( tt == TOK_FNUM)? "FLOAT":
        ( tt == TOK_UNUM)? "UNSIGNED":
        ( tt == TOK_QSTRG)? "QSTRING":
        ( tt == TOK_ERROR)? "ERROR":
        ( tt == TOK_END_INPUT)? "END OF INPUT": "UNKNOWN";
}

