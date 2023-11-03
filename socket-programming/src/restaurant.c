#include "../include/restaurant.h"

void open_restaurant()
{
    restaurant.is_opened = 1;
    
    memset(msg, 0, BUFFER_SIZE);
    sprintf(msg, "%s Restaurant %s!\n", 
        color((char* )restaurant.user.username, YELLOW), color("opened", GREEN));   
    if (sendto(restaurant.user.broadcast_fd, msg, strlen(msg), 0,
            (struct sockaddr *)&restaurant.user.bc_address, 
            sizeof(restaurant.user.bc_address)) < 0) {
        error("failed to send opern message\n");        
    }
}

int command()
{
    memset(cmd, 0, BUFFER_SIZE);
    read(STDIN_FILENO, cmd, BUFFER_SIZE);
    trim_white_space_left(cmd);
    
    if (strcmp(cmd, "start working")) {
        open_restaurant();
    } else if (cmd == '\0') {
        return EXIT_FAILURE;
    }
    
    return EXIT_FAILURE;
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
        propmt();

        if (select(max_fd + 1, &working_set, NULL, NULL, NULL) < 0) {
            error("failed in select process");
            return;
        }

        if (FD_ISSET(STDIN_FILENO, &working_set)) {
            int result = command();
            if (result == EXIT_FAILURE) {
                break;
            }
        }
        break;
    }
}

int main(int argc, char const *argv[])
{   
    setup_user(argc, argv, &restaurant.user, "restaurant");
    run();
    free_resources(&restaurant.user);

    return 0;
}