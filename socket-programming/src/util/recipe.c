#include "../../include/util/recipe.h"

void show_all_recipes(void)
{
    //TODO: read it form recipes.json file
    newline();

    for (int i = 0; i < MAX_TABLE_LENGHT; i++) {
        echo("-");
    }
    newline();

    echo("1- %s:\n\r\t%s : %s\n\r\t%s : %s\n\r\t%s : %s\n\r",
        color("Fessenjan", CYAN),
        color("Onion", YELLOW), color("100", GREEN),
        color("sugar", YELLOW), color("70", GREEN),
        color("Turmeric", YELLOW), color("200", GREEN));
    
    echo("2- %s:\n\r\t%s : %s\n\r\t%s : %s\n\r",
        color("Tahchin", CYAN),
        color("Saffron", YELLOW), color("10", GREEN),
        color("Eggs", YELLOW), color("2", GREEN));
    
    echo("3- %s:\n\r\t%s : %s\n\r\t%s : %s\n\r\t%s : %s\n\r",
        color("Baghali Polo", CYAN),
        color("Dill", YELLOW), color("50", GREEN),
        color("Saffron", YELLOW), color("5", GREEN),
        color("Turmeric", YELLOW), color("500", GREEN));

    for (int i = 0; i < MAX_TABLE_LENGHT; i++) {
        echo("-");
    }
    newline();
    newline();
}
