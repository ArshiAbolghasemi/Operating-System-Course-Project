#include "../../include/util/cli.h"

char* color(char* text, AnsiColor color)
{
    char* temp = (char*)malloc(256);
    sprintf(temp, "\x1B[%dm%s\x1B[%dm\n", color, text, DEFAULT);
    return temp;
}

void print_cli(char* format, ...)
{
    memset(buffer, 0, BUFFER_SIZE);

    va_list args;
    va_start(args, format);

    vsnprintf(buffer, BUFFER_SIZE, format, args);
    write(STDIN_FILENO, buffer, strlen(buffer));

    va_end(args);
}
