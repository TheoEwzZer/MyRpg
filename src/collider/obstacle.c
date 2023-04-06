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
    sfRectangleShape_setPosition(var->collider[1], (sfVector2f){1730, 1260});
    sfRectangleShape_setPosition(var->collider[33], (sfVector2f){180, 756});
    sfRectangleShape_setPosition(var->collider[36], (sfVector2f){936, 754});
    sfRectangleShape_setPosition(var->collider[37], (sfVector2f){936, 790});
    sfRectangleShape_setPosition(var->collider[38], (sfVector2f){1008, 790});
    sfRectangleShape_setPosition(var->collider[39], (sfVector2f){1116, 430});
    sfRectangleShape_setPosition(var->collider[40], (sfVector2f){900, 362});
    sfRectangleShape_setPosition(var->collider[41], (sfVector2f){36, 826});
    sfRectangleShape_setPosition(var->collider[9], (sfVector2f){0, 1799});
    sfRectangleShape_setSize(var->collider[1], (sfVector2f){70, 70});
    sfRectangleShape_setSize(var->collider[33], (sfVector2f){36, 70});
    sfRectangleShape_setSize(var->collider[36], (sfVector2f){108, 36});
    sfRectangleShape_setSize(var->collider[37], (sfVector2f){36, 34});
    sfRectangleShape_setSize(var->collider[38], (sfVector2f){36, 34});
    sfRectangleShape_setSize(var->collider[39], (sfVector2f){36, 108});
    sfRectangleShape_setSize(var->collider[40], (sfVector2f){180, 30});
    sfRectangleShape_setSize(var->collider[41], (sfVector2f){34, 34});
    sfRectangleShape_setSize(var->collider[9], (sfVector2f){1920, 35});
}
