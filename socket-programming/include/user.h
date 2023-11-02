#ifndef _USER_H_
#define _USER_H_

#include "./util/cli.h"
#include "./util/util.h"

#define MAX_USERNAME_LENGTH 1024

struct user {
    char username[MAX_USERNAME_LENGTH];
};

char* get_user_name();

void say_wellcome(char* username, char* role);

#endif