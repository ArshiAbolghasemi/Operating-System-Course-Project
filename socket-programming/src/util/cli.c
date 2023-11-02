#include "../../include/util/cli.h"

extern char buffer[BUFFER_SIZE];

void echo(char* format, ...)
{
    memset(buffer, 0, BUFFER_SIZE);

    va_list args;
    va_start(args, format);

    vsnprintf(buffer, BUFFER_SIZE, format, args);
    write(STDOUT_FILENO, buffer, strlen(buffer));

    va_end(args);
}

void error(char* format, ...)
{
    memset(buffer, 0, BUFFER_SIZE);

    va_list args;
    va_start(args, format);
    char* new_format = (char*)malloc(BUFFER_SIZE);
    sprintf(new_format, "%s %s", color("Error:", RED), format);
    echo(new_format, args);
    free(new_format);
}

void new_command_line()
{
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "%s ", FIRST_LINE_SIGN);
    write(STDOUT_FILENO, buffer, strlen(buffer));
}
