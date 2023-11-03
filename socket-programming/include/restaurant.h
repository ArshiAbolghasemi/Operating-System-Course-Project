#ifndef _RESTAURANT_H_
#define _RESTAURANT_H_

#include "user.h"

char cmd[BUFFER_SIZE];
char msg[BUFFER_SIZE];

struct {
    struct user user;
    int is_opened;
} restaurant;

void open_restaurant();

int command();

void run();

#endif