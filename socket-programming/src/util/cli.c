#include "../../include/util/cli.h"

void echo(char* format, ...)
{
    memset(buffer, 0, BUFFER_SIZE);

    va_list args;
    va_start(args, format);

    vsnprintf(buffer, BUFFER_SIZE, format, args);
    write(STDOUT_FILENO, buffer, strlen(buffer));

    va_end(args);
}
