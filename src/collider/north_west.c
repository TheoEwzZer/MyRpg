/*
** EPITECH PROJECT.0f, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_north_west_position(var_t *var)
{
    sfRectangleShape_setPosition(COLLIDER[13], (sfVector2f){0.0f, 0.0f});
    sfRectangleShape_setPosition(COLLIDER[19], (sfVector2f){0.0f, 0.0f});
    sfRectangleShape_setPosition(COLLIDER[49], (sfVector2f){0.0f, 753.0f});
    sfRectangleShape_setPosition(COLLIDER[50], (sfVector2f){144.0f, 710.0f});
    sfRectangleShape_setPosition(COLLIDER[51], (sfVector2f){216.0f, 675.0f});
    sfRectangleShape_setPosition(COLLIDER[52], (sfVector2f){252.0f, 646.0f});
    sfRectangleShape_setPosition(COLLIDER[53], (sfVector2f){324.0f, 610.0f});
    sfRectangleShape_setPosition(COLLIDER[54], (sfVector2f){360.0f, 575.0f});
    sfRectangleShape_setPosition(COLLIDER[55], (sfVector2f){396.0f, 538.0f});
    sfRectangleShape_setPosition(COLLIDER[56], (sfVector2f){612.0f, 466.0f});
    sfRectangleShape_setPosition(COLLIDER[57], (sfVector2f){684.0f, 430.0f});
    sfRectangleShape_setPosition(COLLIDER[58], (sfVector2f){720.0f, 394.0f});
    sfRectangleShape_setPosition(COLLIDER[59], (sfVector2f){756.0f, 358.0f});
    sfRectangleShape_setPosition(COLLIDER[60], (sfVector2f){828.0f, 322.0f});
    sfRectangleShape_setPosition(COLLIDER[61], (sfVector2f){936.0f, 214.0f});
}

void create_north_west_size(var_t *var)
{
    sfRectangleShape_setSize(COLLIDER[13], (sfVector2f){33.0f, WIDTH});
    sfRectangleShape_setSize(COLLIDER[19], (sfVector2f){1869.0f, 211.0f});
    sfRectangleShape_setSize(COLLIDER[49], (sfVector2f){144.0f, 73.0f});
    sfRectangleShape_setSize(COLLIDER[50], (sfVector2f){72.0f, 80.0f});
    sfRectangleShape_setSize(COLLIDER[51], (sfVector2f){36.0f, 80.0f});
    sfRectangleShape_setSize(COLLIDER[52], (sfVector2f){72.0f, 72.0f});
    sfRectangleShape_setSize(COLLIDER[53], (sfVector2f){36.0f, 36.0f});
    sfRectangleShape_setSize(COLLIDER[54], (sfVector2f){36.0f, 36.0f});
    sfRectangleShape_setSize(COLLIDER[55], (sfVector2f){216.0f, 36.0f});
    sfRectangleShape_setSize(COLLIDER[56], (sfVector2f){72.0f, 72.0f});
    sfRectangleShape_setSize(COLLIDER[57], (sfVector2f){36.0f, 36.0f});
    sfRectangleShape_setSize(COLLIDER[58], (sfVector2f){36.0f, 36.0f});
    sfRectangleShape_setSize(COLLIDER[59], (sfVector2f){72.0f, 36.0f});
    sfRectangleShape_setSize(COLLIDER[60], (sfVector2f){108.0f, 36.0f});
    sfRectangleShape_setSize(COLLIDER[61], (sfVector2f){72.0f, 108.0f});
}
