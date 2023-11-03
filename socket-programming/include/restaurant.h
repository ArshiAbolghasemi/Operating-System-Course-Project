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

void open_restaurant(void);

void close_restaurant(void);

void show_ingredients(void);

int handle_socket(int socket_fd, fd_set* _working_set, fd_set* _master_set, int max_fd);

void connect_new_user(int max_fd, fd_set* _working_set, fd_set* _master_set);

void run();

#endif