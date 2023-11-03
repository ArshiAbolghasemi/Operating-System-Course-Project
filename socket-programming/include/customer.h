#ifndef _CUSTOMER_H
#define _CUSTOMER_H_

#include "user.h"

char cmd[BUFFER_SIZE];
char msg[BUFFER_SIZE];

int handle_event(fd_set* _working_set);

void run();

struct {
    struct user user;
} customer;

#endif