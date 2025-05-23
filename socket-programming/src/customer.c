#include "../include/customer.h"

void show_menu(void)
{
    newline();

    for (int i = 0; i < MAX_TABLE_LENGHT; i++) {
        echo("-");
    }
    newline();

    echo("1- %s\n\r2- %s\n\r3- %s\n\r",
        color("Fessenjan", CYAN),
        color("Tahchin", CYAN),
        color("Baghali Polo", CYAN));

    for (int i = 0; i < MAX_TABLE_LENGHT; i++) {
        echo("-");
    }
    newline();
    newline();
}

int command(void)
{
    memset(cmd, 0, BUFFER_SIZE);
    read(STDIN_FILENO, cmd, BUFFER_SIZE);
    trim_white_space_left(cmd);

    if (strcmp(cmd, "show menu") == 0) show_menu();
    else if (cmd == '\0' || strcmp(cmd, "exit") == 0) return EXIT;
    else error("Invalid command!\n");

    return 1;
}

int handle_socket(int socket_fd, fd_set* _working_set, fd_set* _master_set)
{
    if (FD_ISSET(STDIN_FILENO, _working_set)) {
        return command();
    }
    
    if (FD_ISSET(customer.user.broadcast_fd, _working_set)) {
        memset(msg, 0, BUFFER_SIZE);
        int recv_bytes = recv(customer.user.broadcast_fd, msg, BUFFER_SIZE, 0);
        clear(cmd);     
        echo("%s\n", msg);
    }
    
    return 1;
}

void run(void)
{
    fd_set master_set, working_set;
    FD_ZERO(&master_set);
    FD_ZERO(&working_set);
    FD_SET(STDIN_FILENO, &master_set);
    FD_SET(customer.user.broadcast_fd, &master_set);
    int max_fd = customer.user.broadcast_fd;

    while (1) {
        working_set = master_set;

        if (select(max_fd + 1, &working_set, NULL, NULL, NULL) < 0) error("faile in select");
        
        int exit;
        for (int socket_fd = 0; socket_fd <= max_fd; socket_fd++) 
            if (FD_ISSET(socket_fd, &working_set))
                exit = handle_socket(socket_fd, &working_set, &master_set);
        
        if (exit == EXIT) break;
    }
}

int main(int argc, char const *argv[])
{
    setup_user(argc, argv, &customer.user, "customer");
    run();
    free_resources(&customer.user);

    return 0;
}