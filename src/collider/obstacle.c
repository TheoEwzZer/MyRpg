/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_barrer_collider(var_t *var)
{
    sfRectangleShape_setPosition(var->collider[21], (sfVector2f){1058, 808});
    sfRectangleShape_setPosition(var->collider[22], (sfVector2f){1094, 844});
    sfRectangleShape_setPosition(var->collider[23], (sfVector2f){1130, 970});
    sfRectangleShape_setPosition(var->collider[24], (sfVector2f){1166, 1006});
    sfRectangleShape_setPosition(var->collider[25], (sfVector2f){1166, 1042});
    sfRectangleShape_setSize(var->collider[21], (sfVector2f){260, 126});
    sfRectangleShape_setSize(var->collider[22], (sfVector2f){260, 126});
    sfRectangleShape_setSize(var->collider[23], (sfVector2f){224, 36});
    sfRectangleShape_setSize(var->collider[24], (sfVector2f){188, 36});
    sfRectangleShape_setSize(var->collider[25], (sfVector2f){152, 36});
}

void create_tree_collider(var_t *var)
{
GET_BOUNDS
}
