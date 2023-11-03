#include "../include/restaurant.h"

void open_restaurant()
{
    if (restaurant.is_opened == OPENED) {
        warn("restaurant was opened!\n");
        return;
    }
    
    restaurant.is_opened = OPENED;
    info("restaurant is opened\n");
    
    memset(msg, 0, BUFFER_SIZE);
    sprintf(msg, "%s Restaurant %s!\n", 
        color((char*)restaurant.user.username, YELLOW), color("opened", GREEN));   
    broadcast_msg(msg, restaurant.user.broadcast_fd, restaurant.user.bc_address);
}

void close_restaurant()
{
    if (restaurant.is_opened == CLOSED) {
        error("restaurant is not opened yet!\n");
        return;
    }
    
    restaurant.is_opened = CLOSED;
    info("restaurant is closed\n");

    memset(msg, 0, BUFFER_SIZE);
    sprintf(msg, "%s Restaurant %s!\n",
        color((char*)restaurant.user.username, YELLOW), color("closed", RED));
    broadcast_msg(msg, restaurant.user.broadcast_fd, restaurant.user.bc_address);
}

int command()
{
    memset(cmd, 0, BUFFER_SIZE);
    read(STDIN_FILENO, cmd, BUFFER_SIZE);
    trim_white_space_left(cmd);
    
    if (strcmp(cmd, "start working") == 0) {
        open_restaurant();
    } else if (strcmp(cmd, "break") == 0) {
        close_restaurant();
    } else if (cmd == '\0') {
        return EXIT;
    }
    
    return 1;
}

void run()
{
    open_restaurant();
    fd_set master_set, working_set;
    FD_ZERO(&master_set);
    FD_ZERO(&working_set);
    FD_SET(STDIN_FILENO, &master_set);
    FD_SET(restaurant.user.broadcast_fd, &master_set);
    int max_fd = restaurant.user.broadcast_fd;
    while (1) {
        working_set = master_set;

        if (select(max_fd + 1, &working_set, NULL, NULL, NULL) < 0) {
            error("failed in select process");
            return;
        }

        if (FD_ISSET(restaurant.user.broadcast_fd, &working_set)) {
            propmt();
            if (command() == EXIT) {
                break;
            }
        }
    }
}

int main(int argc, char const *argv[])
{   
    setup_user(argc, argv, &restaurant.user, "restaurant");
    run();
    free_resources(&restaurant.user);

    return 0;
}