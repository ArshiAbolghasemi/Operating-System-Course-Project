#include "../../include/util/util.h"

char* color(char* text, AnsiColor color)
{
    char* temp = (char*)malloc(256);
    sprintf(temp, "\x1B[%dm%s\x1B[%dm", color, text, DEFAULT);
    return temp;
}

void trim_white_space_left(char *str)
{
    int length = strlen(str);
    
    // Start from the end of the string and move backwards
    while (length > 0 && isspace((unsigned char)str[length - 1])) {
        str[length - 1] = '\0';
        length--;
    }
}