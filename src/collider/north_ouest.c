/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_north_west_position(var_t *var)
{
    sfRectangleShape_setPosition(var->collider[13], (sfVector2f){0, 0});
    sfRectangleShape_setPosition(var->collider[19], (sfVector2f){0, 0});
    sfRectangleShape_setPosition(var->collider[49], (sfVector2f){0, 753});
    sfRectangleShape_setPosition(var->collider[50], (sfVector2f){144, 710});
    sfRectangleShape_setPosition(var->collider[51], (sfVector2f){216, 675});
    sfRectangleShape_setPosition(var->collider[52], (sfVector2f){252, 646});
    sfRectangleShape_setPosition(var->collider[53], (sfVector2f){324, 610});
    sfRectangleShape_setPosition(var->collider[54], (sfVector2f){360, 575});
    sfRectangleShape_setPosition(var->collider[55], (sfVector2f){396, 538});
    sfRectangleShape_setPosition(var->collider[56], (sfVector2f){612, 466});
    sfRectangleShape_setPosition(var->collider[57], (sfVector2f){684, 430});
    sfRectangleShape_setPosition(var->collider[58], (sfVector2f){720, 394});
    sfRectangleShape_setPosition(var->collider[59], (sfVector2f){756, 358});
    sfRectangleShape_setPosition(var->collider[60], (sfVector2f){828, 322});
    sfRectangleShape_setPosition(var->collider[61], (sfVector2f){936, 214});
}

void create_north_west_size(var_t *var)
{
    sfRectangleShape_setSize(var->collider[13], (sfVector2f){33, WIDTH});
    sfRectangleShape_setSize(var->collider[19], (sfVector2f){1869, 211});
    sfRectangleShape_setSize(var->collider[49], (sfVector2f){144, 73});
    sfRectangleShape_setSize(var->collider[50], (sfVector2f){72, 80});
    sfRectangleShape_setSize(var->collider[51], (sfVector2f){36, 80});
    sfRectangleShape_setSize(var->collider[52], (sfVector2f){72, 72});
    sfRectangleShape_setSize(var->collider[53], (sfVector2f){36, 36});
    sfRectangleShape_setSize(var->collider[54], (sfVector2f){36, 36});
    sfRectangleShape_setSize(var->collider[55], (sfVector2f){216, 36});
    sfRectangleShape_setSize(var->collider[56], (sfVector2f){72, 72});
    sfRectangleShape_setSize(var->collider[57], (sfVector2f){36, 36});
    sfRectangleShape_setSize(var->collider[58], (sfVector2f){36, 36});
    sfRectangleShape_setSize(var->collider[59], (sfVector2f){72, 36});
    sfRectangleShape_setSize(var->collider[60], (sfVector2f){108, 36});
    sfRectangleShape_setSize(var->collider[61], (sfVector2f){72, 108});
}
