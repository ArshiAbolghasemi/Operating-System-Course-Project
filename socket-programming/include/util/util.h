#ifndef _UTIL_H_
#define _UTIL_H

#include <stdio.h>

typedef enum {
    DEFAULT = 0,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    MAGENTA = 35,
    CYAN = 36,
} AnsiColor;

char* color(char* text, AnsiColor color);

#endif