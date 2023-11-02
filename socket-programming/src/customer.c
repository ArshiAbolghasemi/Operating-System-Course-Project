#include "../include/customer.h"

int main(int argc, char const *argv[])
{
    setup_user(argc, argv, &customer.user, "customer");
    free_resources(&customer.user);

    return 0;
}