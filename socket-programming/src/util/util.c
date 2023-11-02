#include "../../include/util/util.h"

char* color(char* text, AnsiColor color)
{
    char* temp = (char*)malloc(256);
    sprintf(temp, "\x1B[%dm%s\x1B[%dm\n", color, text, DEFAULT);
    return temp;
}