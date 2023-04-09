/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_west_collider(var_t *var)
{
    sfRectangleShape_setPosition(COLLIDER[14], (sfVector2f){1404.0f, 754.0f});
    sfRectangleShape_setPosition(COLLIDER[15], (sfVector2f){1404.0f, 1042.0f});
    sfRectangleShape_setPosition(COLLIDER[16], (sfVector2f){1548.0f, 682.0f});
    sfRectangleShape_setPosition(COLLIDER[17], (sfVector2f){1440.0f, 1078.0f});
    sfRectangleShape_setPosition(COLLIDER[18], (sfVector2f){1800.0f, 610.0f});
    sfRectangleShape_setSize(COLLIDER[14], (sfVector2f){466.0f, 288.0f});
    sfRectangleShape_setSize(COLLIDER[15], (sfVector2f){288.0f, 36.0f});
    sfRectangleShape_setSize(COLLIDER[16], (sfVector2f){322.0f, 72.0f});
    sfRectangleShape_setSize(COLLIDER[17], (sfVector2f){216.0f, 36.0f});
    sfRectangleShape_setSize(COLLIDER[18], (sfVector2f){72.0f, 72.0f});
}
