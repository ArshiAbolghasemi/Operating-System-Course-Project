#ifndef _RESTAURANT_H_
#define _RESTAURANT_H_

#include "user.h"

char cmd[BUFFER_SIZE];
char msg[BUFFER_SIZE];

#define OPENED 1
#define CLOSED 0

struct {
    struct user user;
    int is_opened;
} restaurant;

void open_restaurant();

void close_restaurant();

int command();

void run();

#endif