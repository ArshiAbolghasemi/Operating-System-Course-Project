#ifndef _RECIPE_H_
#define _RECIPE_H_ 

#include "ingredient.h"

#define MAX_INGREDIENTS_PER_RECIPE 50
#define MAX_LENGTH_RECIPE_NAME 256

struct recipe {
    char name[MAX_LENGTH_RECIPE_NAME];
    ingredient ingredients[MAX_INGREDIENTS_PER_RECIPE];    
};

#endif