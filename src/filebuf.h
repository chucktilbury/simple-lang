#ifndef _FILEBUF_H
#define _FILEBUF_H
/**
 * @file scanner.h
 *
 * @brief Scanner header.
 *
 */

#include "str.h"

// This value is returned when there are no more characters to scan.
#define EOI -1

void init_charbuffer(const char* fname);
void open_file(const char* fname);
void close_file();
const char* get_file_name();
int get_line_no();
int get_col_no();
int consume_char();
int get_crnt_char();


#endif /* _FILEBUF_H */
