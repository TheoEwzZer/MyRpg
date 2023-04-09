/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_sud_collider(var_t *var)
{
    sfRectangleShape_setPosition(COLLIDER[10], (sfVector2f){0.0f, 1763.0f});
    sfRectangleShape_setPosition(COLLIDER[11], (sfVector2f){0.0f, 1727.0f});
    sfRectangleShape_setPosition(COLLIDER[12], (sfVector2f){0.0f, 1691.0f});
    sfRectangleShape_setPosition(COLLIDER[2], (sfVector2f){1838.0f, 0.0f});
    sfRectangleShape_setPosition(COLLIDER[3], (sfVector2f){755.0f, 1474.0f});
    sfRectangleShape_setPosition(COLLIDER[4], (sfVector2f){1045.0f, 1367.0f});
    sfRectangleShape_setPosition(COLLIDER[5], (sfVector2f){1117.0f, 1330.0f});
    sfRectangleShape_setPosition(COLLIDER[6], (sfVector2f){1189.0f, 1295.0f});
    sfRectangleShape_setPosition(COLLIDER[7], (sfVector2f){937.0f, 1439.0f});
    sfRectangleShape_setPosition(COLLIDER[8], (sfVector2f){721.0f, 1655.0f});
    sfRectangleShape_setSize(COLLIDER[10], (sfVector2f){360.0f, 35.0f});
    sfRectangleShape_setSize(COLLIDER[11], (sfVector2f){179.0f, 35.0f});
    sfRectangleShape_setSize(COLLIDER[12], (sfVector2f){143.0f, 35.0f});
    sfRectangleShape_setSize(COLLIDER[2], (sfVector2f){30.0f, WIDTH});
    sfRectangleShape_setSize(COLLIDER[3], (sfVector2f){1150.0f, 360.0f});
    sfRectangleShape_setSize(COLLIDER[4], (sfVector2f){465.0f, 360.0f});
    sfRectangleShape_setSize(COLLIDER[5], (sfVector2f){323.0f, 360.0f});
    sfRectangleShape_setSize(COLLIDER[6], (sfVector2f){215.0f, 360.0f});
    sfRectangleShape_setSize(COLLIDER[7], (sfVector2f){108.0f, 360.0f});
    sfRectangleShape_setSize(COLLIDER[8], (sfVector2f){35.0f, 360.0f});
}
