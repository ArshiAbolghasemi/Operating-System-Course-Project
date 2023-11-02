#include "../include/restaurant.h"

void signup()
{
    char* username = get_user_name();
    strcpy(resturant.user.username, username);
    say_wellcome(resturant.user.username, "restaurant");
}

int main(int argc, char const *argv[])
{
    signup();
}