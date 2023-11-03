#include "../include/customer.h"

int handle_event(fd_set* _working_set)
{
    if (FD_ISSET(customer.user.broadcast_fd, _working_set)) {
        memset(msg, 0, BUFFER_SIZE);
        int recv_bytes = recv(customer.user.broadcast_fd, msg, BUFFER_SIZE, 0);
        clear(cmd);     
        echo("%s\n", msg);
    }
    return 1;
}

void run()
{
    fd_set master_set, working_set;
    FD_ZERO(&master_set);
    FD_ZERO(&working_set);
    FD_SET(STDIN_FILENO, &master_set);
    FD_SET(customer.user.broadcast_fd, &master_set);
    int max_fd = customer.user.broadcast_fd;

    while (1) {
        working_set = master_set;
        propmt();

        if (select(max_fd + 1, &working_set, NULL, NULL, NULL) < 0) error("faile in select");
        else if (handle_event(&working_set) == EXIT_FAILURE) break;
    }
}

int main(int argc, char const *argv[])
{
    setup_user(argc, argv, &customer.user, "customer");
    run();
    free_resources(&customer.user);

    return 0;
}