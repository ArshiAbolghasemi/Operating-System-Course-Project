#ifndef _USER_H_
#define _USER_H_

#include "./util/cli.h"
#include "./util/util.h"

#define MAX_USERNAME_LENGTH 1024

struct user {
    char username[MAX_USERNAME_LENGTH];
    int udp_port;
};

char* get_user_name(void);

void say_wellcome(char* username, char* role);

void set_user_info(int argc, char const *argv[], struct  user* _user);

void setup_user(int argc, char const *argv[], struct user* _user, char* role);

#endif