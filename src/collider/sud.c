/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_sud_collider(var_t *var)
{
    sfRectangleShape_setPosition(var->collider[10], (sfVector2f){0, 1763});
    sfRectangleShape_setPosition(var->collider[11], (sfVector2f){0, 1727});
    sfRectangleShape_setPosition(var->collider[12], (sfVector2f){0, 1691});
    sfRectangleShape_setPosition(var->collider[2], (sfVector2f){1838, 0});
    sfRectangleShape_setPosition(var->collider[3], (sfVector2f){755, 1474});
    sfRectangleShape_setPosition(var->collider[4], (sfVector2f){1045, 1367});
    sfRectangleShape_setPosition(var->collider[5], (sfVector2f){1117, 1330});
    sfRectangleShape_setPosition(var->collider[6], (sfVector2f){1189, 1295});
    sfRectangleShape_setPosition(var->collider[7], (sfVector2f){937, 1439});
    sfRectangleShape_setPosition(var->collider[8], (sfVector2f){721, 1655});
    sfRectangleShape_setSize(var->collider[10], (sfVector2f){360, 35});
    sfRectangleShape_setSize(var->collider[11], (sfVector2f){179, 35});
    sfRectangleShape_setSize(var->collider[12], (sfVector2f){143, 35});
    sfRectangleShape_setSize(var->collider[2], (sfVector2f){30, WIDTH});
    sfRectangleShape_setSize(var->collider[3], (sfVector2f){1150, 360});
    sfRectangleShape_setSize(var->collider[4], (sfVector2f){465, 360});
    sfRectangleShape_setSize(var->collider[5], (sfVector2f){323, 360});
    sfRectangleShape_setSize(var->collider[6], (sfVector2f){215, 360});
    sfRectangleShape_setSize(var->collider[7], (sfVector2f){108, 360});
    sfRectangleShape_setSize(var->collider[8], (sfVector2f){35, 360});
}
