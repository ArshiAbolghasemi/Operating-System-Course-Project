#ifndef _UTIL_H_
#define _UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    DEFAULT = 0,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    MAGENTA = 35,
    CYAN = 36,
} AnsiColor;

char* color(char* text, AnsiColor color);

void trim_white_space_left(char *str);

void implode(char *result, const char **array, int array_size, const char *separator);

char* convert_int_to_char(int _value);

#endif