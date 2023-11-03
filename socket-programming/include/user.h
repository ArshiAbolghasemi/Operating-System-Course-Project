#ifndef _USER_H_
#define _USER_H_

#include "./util/cli.h"
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

#define BROADCAST_ADDR "255.255.255.255"

struct user {
    char username[MAX_USERNAME_LENGTH];
    int udp_port;
    int broadcast_fd;
    struct sockaddr_in bc_address;
};

char* get_user_name(void);

void say_wellcome(char* username, char* role);

int validate_port(char* port);

void set_user_info(int argc, char const *argv[], struct  user* _user);

int setup_broadcast_fd();

void bind_socket_to_port(int port, int socket_fd, char* host_address, struct user* _user);

void free_resources(struct user* _user);

void setup_user(int argc, char const *argv[], struct user* _user, char* role);

#endif