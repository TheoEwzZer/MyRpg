/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_barrier_collider(var_t *var)
{
    sfRectangleShape_setPosition(COLLIDER[21], (sfVector2f){1058.0f, 808.0f});
    sfRectangleShape_setPosition(COLLIDER[22], (sfVector2f){1094.0f, 844.0f});
    sfRectangleShape_setPosition(COLLIDER[23], (sfVector2f){1130.0f, 970.0f});
    sfRectangleShape_setPosition(COLLIDER[24], (sfVector2f){1166.0f, 1006.0f});
    sfRectangleShape_setPosition(COLLIDER[25], (sfVector2f){1166.0f, 1042.0f});
    sfRectangleShape_setSize(COLLIDER[21], (sfVector2f){260.0f, 126.0f});
    sfRectangleShape_setSize(COLLIDER[22], (sfVector2f){260.0f, 126.0f});
    sfRectangleShape_setSize(COLLIDER[23], (sfVector2f){224.0f, 36.0f});
    sfRectangleShape_setSize(COLLIDER[24], (sfVector2f){188.0f, 36.0f});
    sfRectangleShape_setSize(COLLIDER[25], (sfVector2f){152.0f, 36.0f});
}

void create_tree_collider(var_t *var)
{
    sfRectangleShape_setPosition(COLLIDER[1], (sfVector2f){1730.0f, 1260.0f});
    sfRectangleShape_setPosition(COLLIDER[33], (sfVector2f){180.0f, 756.0f});
    sfRectangleShape_setPosition(COLLIDER[36], (sfVector2f){936.0f, 754.0f});
    sfRectangleShape_setPosition(COLLIDER[37], (sfVector2f){936.0f, 790.0f});
    sfRectangleShape_setPosition(COLLIDER[38], (sfVector2f){1008.0f, 790.0f});
    sfRectangleShape_setPosition(COLLIDER[39], (sfVector2f){1116.0f, 430.0f});
    sfRectangleShape_setPosition(COLLIDER[40], (sfVector2f){900.0f, 362.0f});
    sfRectangleShape_setPosition(COLLIDER[41], (sfVector2f){36.0f, 826.0f});
    sfRectangleShape_setPosition(COLLIDER[9], (sfVector2f){506.0f, 1799.0f});
    sfRectangleShape_setSize(COLLIDER[1], (sfVector2f){70.0f, 70.0f});
    sfRectangleShape_setSize(COLLIDER[33], (sfVector2f){36.0f, 70.0f});
    sfRectangleShape_setSize(COLLIDER[36], (sfVector2f){108.0f, 36.0f});
    sfRectangleShape_setSize(COLLIDER[37], (sfVector2f){36.0f, 34.0f});
    sfRectangleShape_setSize(COLLIDER[38], (sfVector2f){36.0f, 34.0f});
    sfRectangleShape_setSize(COLLIDER[39], (sfVector2f){36.0f, 108.0f});
    sfRectangleShape_setSize(COLLIDER[40], (sfVector2f){180.0f, 30.0f});
    sfRectangleShape_setSize(COLLIDER[41], (sfVector2f){34.0f, 34.0f});
    sfRectangleShape_setSize(COLLIDER[9], (sfVector2f){68.0f, 35.0f});
}
