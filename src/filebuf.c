/**
 * @file scanner.c
 *
 * @brief Read exactly one character from the input stream and make it the
 * current character. Also handle opening and automatically closing files.
 * Perform book keeping for file names and line numbers and such.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#include "filebuf.h"
#include "mem.h"
#include "errors.h"

typedef struct _file_stack_ {
    FILE* fp;
    const char* fname;
    int line;
    int col;
    struct _file_stack_* next;
} FileStack;

static FileStack* file_stack = NULL;
static int crnt_char;

// This is a hack that fixes the issue where trying to get the file name and
// line number after all of the files have been closed returns an unhelpful
// value. This simply stores whatever the last values were before the file
// was closed to return those instead.
static const char* fn;
static int ln;
static int cn;

/**
 * @brief Create the scanner and open the initial file.
 *
 * @param fname
 */
void init_charbuffer(const char* fname) {

    // open the file
    open_file(fname);

    // prime the pump
    consume_char();
    //crnt_char = fgetc(file_stack->fp);
}

/**
 * @brief Open a new file and push it on the file stack. This switches the
 * input stream to the new file. The file will be closed and the current file
 * resumes input when the scanner runs out of characters to scan.
 *
 * @param fname
 */
void open_file(const char* fname) {

    FileStack* fs = _alloc_ds(FileStack);
    fs->fname = _copy_str(fname);
    fs->line = 1;
    fs->col = 1;

    fs->fp = fopen(fname, "r");
    if(fs->fp == NULL)
        fatal("cannot open input file: \"%s\": %s", fname, strerror(errno));

    if(file_stack != NULL)
        fs->next = file_stack;
    file_stack = fs;
}

/**
 * @brief Close the current file and switch the input stream back to the one
 * that previously was active, unless there are no more files in the file
 * stack.
 *
 */
void close_file() {

    if(file_stack != NULL) {
        FileStack* tmp = file_stack;
        file_stack = file_stack->next;

        fclose(tmp->fp);

        // note that we are using GC here...
        fn = tmp->fname;
        ln = tmp->line;
        cn = tmp->col;
    }
}

/**
 * @brief Return the name of the current file.
 *
 * @return const char*
 */
const char* get_file_name() {

    if(file_stack != NULL)
        return file_stack->fname;
    else
        return fn;
}

/**
 * @brief Return the line number of the current file.
 *
 * @return int
 */
int get_line_no() {

    if(file_stack != NULL)
        return file_stack->line;
    else
        return ln;
}

/**
 * @brief Return the column number of the current file.
 *
 * @return int
 */
int get_col_no() {

    if(file_stack != NULL)
        return file_stack->col;
    else
        return cn;
}

/**
 * @brief Read the next character from the input stream and make it the
 * current character. Returns all characters, including spaces and makes
 * no attempt to do any adjustments such as filtering comments.
 *
 * @return int
 */
int consume_char() {

    int ch;
    if(file_stack != NULL) {

        if(crnt_char == EOI)
            return EOI;
        else if(crnt_char == '\n') {
            file_stack->line++;
            file_stack->col = 1;
        }
        else
            file_stack->col++;

        ch = fgetc(file_stack->fp);

        if(ch == EOF) {
            close_file();
            return consume_char();
        }
    }
    else
        ch = EOI;

    crnt_char = ch;
    return ch;
}

/**
 * @brief Return the current character.
 *
 * @return int
 */
int get_crnt_char() {

    return crnt_char;
}


