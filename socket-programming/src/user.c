#include "../include/user.h"

char buffer[BUFFER_SIZE];

char* get_user_name()
{
    echo("Please enter youre %s : ", color("username", YELLOW));
    memset(buffer, 0, BUFFER_SIZE);
    read(STDIN_FILENO, buffer, BUFFER_SIZE);

    return buffer;
}

void say_wellcome(char* username, char* role)
{
    memset(buffer, 0, BUFFER_SIZE);
    trim_white_space_left(username);
    sprintf(buffer, "welcome %s as %s!!\n", color(username, YELLOW), role);
    write(STDIN_FILENO, buffer, strlen(buffer));
    new_command_line();
}