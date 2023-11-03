#include "../../include/util/cli.h"

void clear(char* buffer)
{
    write(STDOUT_FILENO, "\r", 1);
    for (int i = 0; i < BUFFER_SIZE && buffer[i] != '\0'; ++i)
        write(STDOUT_FILENO, " ", 1);
    write(STDOUT_FILENO, "\r", 1);
}

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
    va_list args;
    va_start(args, format);
    char* new_format = (char*)malloc(BUFFER_SIZE);
    sprintf(new_format, "%s %s", color("[ERROR]", RED), format);
    echo_args(new_format, args);
    va_end(args);
    free(new_format);
}

void warn(char* format, ...)
{
    va_list args;
    va_start(args, format);
    char* new_format = (char*)malloc(BUFFER_SIZE);
    sprintf(new_format, "%s %s", color("[WARNING]", YELLOW), format);
    echo_args(new_format, args);
    va_end(args);
    free(new_format);
}

void info(char* format, ...)
{
    va_list args;
    va_start(args, format);
    char* new_format = (char*)malloc(BUFFER_SIZE);
    sprintf(new_format, "%s %s", color("[INFO]", GREEN), format);
    echo_args(new_format, args);
    va_end(args);
    free(new_format);
}

void newline()
{
    echo("\r\n");
}

void space()
{
    echo(" ");
}

void propmt()
{
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "%s ", PROMPT);
    write(STDOUT_FILENO, buffer, strlen(buffer));
}
