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
    
    while (length > 0 && isspace((unsigned char)str[length - 1])) {
        str[length - 1] = '\0';
        length--;
    }
}

void implode(char *result, const char **array, int array_size, const char *separator) 
{
    strcpy(result, "");

    for (int i = 0; i < array_size; i++) {
        strcat(result, array[i]);
        if (i < array_size - 1) {
            strcat(result, separator);
        }
    }
}

char* convert_int_to_char(int _value)
{
    char* _ch = (char*)malloc(5);
    sprintf(_ch, "%d", _value);
    return _ch;
}