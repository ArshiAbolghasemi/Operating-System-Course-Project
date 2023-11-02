#ifndef _USER_H_
#define _USER_H_

#include "./util/cli.h"
#include "./util/util.h"
#include <unistd.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/time.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <stdio.h>

#define MAX_USERNAME_LENGTH 1024

struct user {
    char username[MAX_USERNAME_LENGTH];
    int udp_port;
    int broadcast_fd;
};

char* get_user_name(void);

void say_wellcome(char* username, char* role);

int validate_port(char* port);

void set_user_info(int argc, char const *argv[], struct  user* _user);

void set_up_broadcast_fd();

void setup_user(int argc, char const *argv[], struct user* _user, char* role);

#endif