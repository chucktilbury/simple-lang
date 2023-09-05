
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "mem.h"
#include "errors.h"
#include "scanner.h"
#include "filebuf.h"
#include "token_types.h"

// The current token
static Token crnt_tok;

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
        else if(get_crnt_char() == EOF) {
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
 * @brief Scan the token list with a binary search. If the string is found,
 * then return the token value. Otherwise, return the TOK_SYMBOL token value.
 *
 * @return TokenType
 */
static token_type_t check_keyword(const char* str) {

    return search_keyword(str);
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
                crnt_tok.type = NEQU;
            }
            else
                crnt_tok.type = ERROR;
            break;
        case '+':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = ADD_ASSIGN;
            }
            else
                crnt_tok.type = ADD;
            break;
        case '-':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = SUB_ASSIGN;
            }
            else
                crnt_tok.type = SUB;
            break;
        case '*':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = MUL_ASSIGN;
            }
            else
                crnt_tok.type = MUL;
            break;
        case '/':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = DIV_ASSIGN;
            }
            else
                crnt_tok.type = DIV;
            break;
        case '%':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = MOD_ASSIGN;
            }
            else
                crnt_tok.type = MOD;
            break;
        case '=':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = EQU; // "=="
            }
            else
                crnt_tok.type = ASSIGN; // assignment
            break;
        case '<':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = LORE;
            }
            else
                crnt_tok.type = LESS;
            break;
        case '>':
            save_char();
            if(get_crnt_char() == '=') {
                save_char();
                crnt_tok.type = GORE;
            }
            else
                crnt_tok.type = MORE;
            break;

        case '(':
            save_char();
            crnt_tok.type = OPAREN;
            break;
        case ')':
            save_char();
            crnt_tok.type = CPAREN;
            break;
        case '[':
            save_char();
            crnt_tok.type = OBRACE;
            break;
        case ']':
            save_char();
            crnt_tok.type = CBRACE;
            break;
        case '{':
            save_char();
            crnt_tok.type = OBLOCK;
            break;
        case '}':
            save_char();
            crnt_tok.type = CBLOCK;
            break;
        case ',':
            save_char();
            crnt_tok.type = COMMA;
            break;
        case '.':
            save_char();
            crnt_tok.type = DOT;
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
        crnt_tok.type = ERROR;
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
                crnt_tok.type = ERROR;
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
    crnt_tok.type = END_OF_INPUT;
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
    //int state = 0;
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
            crnt_tok.type = END_OF_INPUT;
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
                crnt_tok.type = ERROR;
            }
            // if the next char is a 'x' or 'X', then its unsigned
            else if(ch == 'x' || ch == 'X') {
                save_char();
                get_xdigits();
                crnt_tok.type = UNSIGNED_CONST;

                ch = get_crnt_char();
                if(!isstopper(ch)) {
                    syntax("Malformed number. Expected space or operator but got '%c'", ch);
                    crnt_tok.type = ERROR;
                }
            }
            // if the next char is a '.', then it's a float
            else if(ch == '.') {
                save_char(); // save the dot. The next char should be a digit.
                get_float_tail();
                crnt_tok.type = FLOAT_CONST;
            }
            // if the next character is not a digit then it's just a 0 by itself
            else {
                crnt_tok.type = INT_CONST;
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
                crnt_tok.type = FLOAT_CONST;
            }
            else {
                crnt_tok.type = INT_CONST;
            }
            // numbers must be followed by space or operator
            int ch = get_crnt_char();
            if(!isstopper(ch)) {
                syntax("Malformed number. Expected space or operator but got '%c'", ch);
                crnt_tok.type = ERROR;
            }
            finished++;
        }
        // read a single quote string
        else if(ch == '\'') {
            get_squote();
            crnt_tok.type = STRG_CONST;
            finished++;
        }
        // read a double quote string
        else if(ch == '\"') {
            get_dquote();
            crnt_tok.type = STRG_CONST;
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

