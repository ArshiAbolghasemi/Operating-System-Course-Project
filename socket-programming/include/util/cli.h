#ifndef _CLI_H_
#define _CLI_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "util.h"

#define BUFFER_SIZE 1024

#define FIRST_LINE_SIGN ">>"

void echo_args(char* format, va_list args);

void echo(char* format, ...);

void error(char* format, ...);

void new_command_line();

#endif