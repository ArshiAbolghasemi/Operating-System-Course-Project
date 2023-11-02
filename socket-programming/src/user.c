#include "../include/user.h"

char buffer[BUFFER_SIZE];

char* get_user_name(void)
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

void set_user_info(int argc, char const *argv[], struct  user* _user)
{
    char* username = get_user_name();
    strcpy(_user->username, username);
    _user->udp_port = atoi(argv[1]);
}

void setup_user(int argc, char const *argv[], struct user* _user, char* role)
{
    if (argc != 2) {
        echo("%s", color("invalid input!\n", RED));
        exit(EXIT_FAILURE);
    }
    
    set_user_info(argc, argv, _user);

    say_wellcome(_user->username, "restaurant");
}