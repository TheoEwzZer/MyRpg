/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_water_collider(var_t *var)
{
    sfRectangleShape_setPosition(var->collider[42], (sfVector2f){1232, 262});
    sfRectangleShape_setPosition(var->collider[43], (sfVector2f){1191, 293});
    sfRectangleShape_setPosition(var->collider[44], (sfVector2f){1266, 293});
    sfRectangleShape_setPosition(var->collider[45], (sfVector2f){1300, 329});
    sfRectangleShape_setPosition(var->collider[46], (sfVector2f){1615, 363});
    sfRectangleShape_setPosition(var->collider[47], (sfVector2f){1732, 532});
    sfRectangleShape_setPosition(var->collider[48], (sfVector2f){1658, 328});
    sfRectangleShape_setSize(var->collider[42], (sfVector2f){273, 193});
    sfRectangleShape_setSize(var->collider[43], (sfVector2f){42, 132});
    sfRectangleShape_setSize(var->collider[44], (sfVector2f){313, 203});
    sfRectangleShape_setSize(var->collider[45], (sfVector2f){318, 203});
    sfRectangleShape_setSize(var->collider[46], (sfVector2f){183, 169});
    sfRectangleShape_setSize(var->collider[47], (sfVector2f){66, 36});
    sfRectangleShape_setSize(var->collider[48], (sfVector2f){104, 43});
}
