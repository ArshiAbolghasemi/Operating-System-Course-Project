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

void show_ingredients()
{
    if (restaurant.ingredients_cnt == 0) {
        warn("You don't have any ingredients\n");
        return;
    }

    newline();
    for (int i = 0; i < MAX_TABLE_LENGHT; i++) {
        echo("-");
    }
    newline();

    const char* header[] = {"ingredient", "amount"};
    memset(cmd, 0, BUFFER_SIZE);
    implode(cmd, header, 2, (const char*)" / ");
    echo("%s", color(cmd, YELLOW));
    newline();

    for (int i = 0; i < restaurant.ingredients_cnt; i++){
        echo("%s", color((char*)restaurant.ingredients[i].name, GREEN)); 
        space();
        echo("/");
        space();
        char amount_char[5];
        sprintf(amount_char, "%d", restaurant.ingredients[i].amount);
        echo("%s", color(convert_int_to_char(restaurant.ingredients[i].amount), GREEN));
        newline();
    }
    
    for (int i = 0; i < MAX_TABLE_LENGHT; i++) {
        echo("-");
    }
    newline();
    newline();
}

int command()
{
    memset(cmd, 0, BUFFER_SIZE);
    read(STDIN_FILENO, cmd, BUFFER_SIZE);
    trim_white_space_left(cmd);
    
    if (strcmp(cmd, "start working") == 0) open_restaurant();
    else if (strcmp(cmd, "break") == 0)close_restaurant();
    else if (strcmp(cmd, "show ingredients") == 0) show_ingredients();
    else if (strcmp(cmd, "show recipes") == 0) show_all_recipes();
    else if (cmd == '\0' || strcmp(cmd, "exit") == 0) return EXIT;
    else error("Invalid command!\n");

    return 1;
}

int handle_socket(int socket_fd, fd_set* _working_set, fd_set* _master_Ser)
{
    if (FD_ISSET(STDIN_FILENO, _working_set)) {
        return command();
    }
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

        int exit;
        for (int socket_fd = 0; socket_fd <= max_fd; socket_fd++) 
            if (FD_ISSET(socket_fd, &working_set))
                exit = handle_socket(socket_fd, &working_set, &master_set);

        if (exit == EXIT) break;
    }
}

int main(int argc, char const *argv[])
{   
    setup_user(argc, argv, &restaurant.user, "restaurant");
    run();
    free_resources(&restaurant.user);

    return 0;
}