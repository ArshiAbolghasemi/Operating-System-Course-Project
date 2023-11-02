#ifndef _CLI_H_
#define _CLI_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "util.h"

#define BUFFER_SIZE 1024

char buffer[BUFFER_SIZE];

void echo(char* format, ...);

#endif