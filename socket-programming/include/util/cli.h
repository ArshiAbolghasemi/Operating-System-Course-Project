#ifndef _CLI_H_
#define _CLI_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

char buffer[BUFFER_SIZE];

typedef enum {
    DEFAULT = 0,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    MAGENTA = 35,
    CYAN = 36,
} AnsiColor;

char* color(char* text, AnsiColor color);

void print_cli(char* format, ...);

#endif