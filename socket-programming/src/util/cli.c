#include "../../include/util/cli.h"

extern char buffer[BUFFER_SIZE];

void echo_args(char* format, va_list args)
{
    memset(buffer, 0, BUFFER_SIZE);


    vsnprintf(buffer, BUFFER_SIZE, format, args);
    write(STDOUT_FILENO, buffer, strlen(buffer));

}

void echo(char* format, ...)
{
    va_list args;
    va_start(args, format);

    echo_args(format, args);

    va_end(args);
}

void error(char* format, ...)
{
    memset(buffer, 0, BUFFER_SIZE);

    va_list args;
    va_start(args, format);
    char* new_format = (char*)malloc(BUFFER_SIZE);
    sprintf(new_format, "%s %s", color("Error:", RED), format);
    echo_args(new_format, args);
    va_end(args);
    free(new_format);
}

void new_command_line()
{
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "%s ", FIRST_LINE_SIGN);
    write(STDOUT_FILENO, buffer, strlen(buffer));
}
