#include "../include/supplier.h"

int main(int argc, char const *argv[])
{
    setup_user(argc, argv, &supplier.user, "supplier");
    free_resources(&supplier.user);
    
    return 0;
}