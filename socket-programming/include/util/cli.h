#ifndef _CLI_H_
#define _CLI_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

#define FIRST_LINE_SIGN ">>"

char buffer[BUFFER_SIZE];

void echo(char* format, ...);

void new_command_line();

#endif