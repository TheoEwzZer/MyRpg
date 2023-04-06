/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_west_collider(var_t *var)
{
    sfRectangleShape_setPosition(var->collider[14], (sfVector2f){1404, 754});
    sfRectangleShape_setPosition(var->collider[15], (sfVector2f){1404, 1042});
    sfRectangleShape_setPosition(var->collider[16], (sfVector2f){1548, 682});
    sfRectangleShape_setPosition(var->collider[17], (sfVector2f){1440, 1078});
    sfRectangleShape_setPosition(var->collider[18], (sfVector2f){1800, 610});
    sfRectangleShape_setSize(var->collider[14], (sfVector2f){466, 288});
    sfRectangleShape_setSize(var->collider[15], (sfVector2f){288, 36});
    sfRectangleShape_setSize(var->collider[16], (sfVector2f){322, 72});
    sfRectangleShape_setSize(var->collider[17], (sfVector2f){216, 36});
    sfRectangleShape_setSize(var->collider[18], (sfVector2f){72, 72});
}
