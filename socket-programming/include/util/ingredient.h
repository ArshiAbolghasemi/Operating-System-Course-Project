#ifndef _INGREDIENT_H_
#define _INGREDIENT_H_

#define MAX_LENGTH_INGREDIENT_NAME 256

struct ingredient {
    char name[MAX_LENGTH_INGREDIENT_NAME];
    int amount;
};

typedef struct ingredient ingredient;

#endif