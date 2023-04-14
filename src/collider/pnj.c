/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_png_collider(var_t *var)
{
    sfRectangleShape_setPosition(COLLIDER[62], (sfVector2f){1100.0f, 1150.0f});
    sfRectangleShape_setPosition(COLLIDER[63], (sfVector2f){1000, 800.0f});
    sfRectangleShape_setPosition(COLLIDER[64], (sfVector2f){530, 1120.0f});
    sfRectangleShape_setPosition(COLLIDER[65], (sfVector2f){0.0f, 1799.0f});
    sfRectangleShape_setPosition(COLLIDER[66], (sfVector2f){574.0f, 1799.0f});
    sfRectangleShape_setSize(COLLIDER[62], (sfVector2f){33.0f, 60.0f});
    sfRectangleShape_setSize(COLLIDER[63], (sfVector2f){33.0f, 60});
    sfRectangleShape_setSize(COLLIDER[64], (sfVector2f){33.0f, 60.0f});
    sfRectangleShape_setSize(COLLIDER[65], (sfVector2f){506, 35.0f});
    sfRectangleShape_setSize(COLLIDER[66], (sfVector2f){1296.0f, 35.0f});
}
