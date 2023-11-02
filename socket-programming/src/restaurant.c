#include "../include/restaurant.h"

void run()
{
    fd_set workingSet;
    FD_ZERO(&masterSet);
    FD_ZERO(&workingSet);
    FD_SET(STDIN_FILENO, &masterSet);
    FD_SET(restaurant.user.broadcast_fd, &masterSet);
    maxFd = restaurant.user.broadcast_fd;
    logInfo("Looking for advertisements...");
    while (1) {
        workingSet = masterSet;
        propmt();
        if (select(maxFd + 1, &workingSet, NULL, NULL, NULL) < 0) 
            error("failed in select process");
        else if (!handleEvent(&workingSet))
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