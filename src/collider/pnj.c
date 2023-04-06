/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_png_collider(var_t *var)
{
    sfRectangleShape_setPosition(var->collider[62], (sfVector2f){1100, 1150});
    sfRectangleShape_setSize(var->collider[62], (sfVector2f){33, 60});

    sfRectangleShape_setPosition(var->collider[63], (sfVector2f){1000, 800});
    sfRectangleShape_setSize(var->collider[63], (sfVector2f){33, 60});

    sfRectangleShape_setPosition(var->collider[64], (sfVector2f){530, 1120});
    sfRectangleShape_setSize(var->collider[64], (sfVector2f){33, 60});
}
