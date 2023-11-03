#include "../include/user.h"

char buffer[BUFFER_SIZE];

char* get_user_name(void)
{
    echo("Please enter you're %s : ", color("username", YELLOW));
    memset(buffer, 0, BUFFER_SIZE);
    read(STDIN_FILENO, buffer, BUFFER_SIZE);

    return buffer;
}

void say_wellcome(char* username, char* role)
{
    trim_white_space_left(username);
    echo("welcome %s as %s!!\n", color(username, YELLOW), role);
}

int validate_port(char* _port)
{
    char* endPtr;
    long port = strtol(_port, &endPtr, 10);
    if (port < 1024 || port > 65535 || *endPtr != '\0') {
        error("Invalid port | port: %d\n", port);
        exit(EXIT_FAILURE);
    }

    return (int)port;
}

void set_user_info(int argc, char const *argv[], struct  user* _user)
{
    _user->udp_port = validate_port((char*)argv[1]);
    char* username = get_user_name();
    strcpy(_user->username, username);
}

int setup_broadcast_fd(void)
{
    int broadcast = 1, opt = 1, sock_fd = socket(PF_INET, SOCK_DGRAM, 0);

    if (sock_fd < 1) {
        error("failed to create new socket!\n");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sock_fd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) < 0) {
        error("failed to setup broadcast option!\n");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        error("failed to setup reuse port option!\n");
        exit(EXIT_FAILURE);
    }

    return sock_fd;
}

void bind_socket_to_port(int port, int socket_fd, char* host_address, struct user* _user)
{
    _user->bc_address.sin_family = AF_INET;
    _user->bc_address.sin_port = htons(port);
    _user->bc_address.sin_addr.s_addr = inet_addr(host_address);
    if (bind(socket_fd, (struct sockaddr*)&_user->bc_address, sizeof(_user->bc_address)) < 0)
    {
        error("failed to bind socket %d to port %d\n", socket_fd, port);
        exit(EXIT_FAILURE);
    }
}

void setup_user(int argc, char const *argv[], struct user* _user, char* role)
{
    if (argc != 2) {
        error("invalid input!\n");
        exit(EXIT_FAILURE);
    }
    
    set_user_info(argc, argv, _user);
    int broadcast_fd = setup_broadcast_fd();
    _user->broadcast_fd = broadcast_fd;
    bind_socket_to_port(_user->udp_port, broadcast_fd, BROADCAST_ADDR, _user);

    say_wellcome(_user->username, role);
}

void free_resources(struct user* _user)
{
    close(_user->broadcast_fd);
}

void broadcast_msg(char* msg, int broadcast_fd, struct sockaddr_in bc_sockaddr)
{
    if (sendto(broadcast_fd, msg, strlen(msg), 0,
            (struct sockaddr *)&bc_sockaddr, sizeof(bc_sockaddr)) < 0) {
        error("failed to send %s message\n", msg);        
    }
}

int accept_client(int server_fd)
{
    int client_fd;
    struct sockaddr_in client_address;
    int address_len = sizeof(client_address);
    if(client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*) &address_len) < 0) {
        error("failed to accept new client");
        return FAILED_ACCEPT_CLIENT_CODE;
    }

    return client_fd;
}