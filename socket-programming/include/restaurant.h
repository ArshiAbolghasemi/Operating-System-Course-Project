#ifndef _RESTAURANT_H_
#define _RESTAURANT_H_

#include "user.h"
#include "../include/util/recipe.h"

char cmd[BUFFER_SIZE];
char msg[BUFFER_SIZE];

#define OPENED 1
#define CLOSED 0

#define MAX_INGREDIENTS_CNT 30

struct {
    struct user user;
    int is_opened;
    ingredient ingredients[MAX_INGREDIENTS_CNT];
    int ingredients_cnt;
} restaurant;

void open_restaurant();

void close_restaurant();

void show_ingredients();

int handle_socket(int socket_fd, fd_set* _working_set, fd_set* _master_Ser);

void run();

#endif