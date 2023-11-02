#include "../../include/util/cli.h"

char* color(char* text, AnsiColor color)
{
    char* result = NULL;
    asprintf(&result, '\x1B[%dm%s\x1B[%dm', color, DEFAULT);
    return result;
}

void print_cli(char* format, ...)
{
    memset(buffer, 0, BUFFER_SIZE);

    va_list args;
    va_start(args, format);

    sprintf(buffer, format, args);
    write(STDIN_FILENO, buffer, strlen(buffer));

    va_end(args);
}
