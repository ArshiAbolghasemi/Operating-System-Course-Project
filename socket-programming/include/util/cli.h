#ifndef _CLI_H_
#define _CLI_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "util.h"

#define BUFFER_SIZE 1024

#define PROMPT ">>"

extern char buffer[BUFFER_SIZE];

#define EXIT -1

void clear(char* buffer);

void echo_args(char* format, va_list args);

void echo(char* format, ...);

void error(char* format, ...);

void warn(char* format, ...);

void propmt();

#endif