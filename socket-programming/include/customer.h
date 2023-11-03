#ifndef _CUSTOMER_H
#define _CUSTOMER_H_

#include "user.h"

char cmd[BUFFER_SIZE];
char msg[BUFFER_SIZE];

void show_menu();

int command();

int handle_socket(int socket_fd, fd_set* _working_set, fd_set* _master_set);

void run();

struct {
    struct user user;
} customer;

#endif