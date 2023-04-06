/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_house_collider(var_t *var)
{
    sfRectangleShape_setPosition(var->collider[0], (sfVector2f){1656, 1144});
    sfRectangleShape_setPosition(var->collider[26], (sfVector2f){864, 1000});
    sfRectangleShape_setPosition(var->collider[27], (sfVector2f){1080, 1000});
    sfRectangleShape_setPosition(var->collider[28], (sfVector2f){576, 1324});
    sfRectangleShape_setPosition(var->collider[29], (sfVector2f){252, 1432});
    sfRectangleShape_setPosition(var->collider[30], (sfVector2f){144, 1144});
    sfRectangleShape_setPosition(var->collider[31], (sfVector2f){288, 784});
    sfRectangleShape_setPosition(var->collider[32], (sfVector2f){468, 784});
    sfRectangleShape_setPosition(var->collider[34], (sfVector2f){864, 604});
    sfRectangleShape_setPosition(var->collider[35], (sfVector2f){900, 718});
    sfRectangleShape_setSize(var->collider[0], (sfVector2f){144, 150});
    sfRectangleShape_setSize(var->collider[26], (sfVector2f){216, 186});
    sfRectangleShape_setSize(var->collider[27], (sfVector2f){36, 150});
    sfRectangleShape_setSize(var->collider[28], (sfVector2f){144, 150});
    sfRectangleShape_setSize(var->collider[29], (sfVector2f){144, 150});
    sfRectangleShape_setSize(var->collider[30], (sfVector2f){180, 150});
    sfRectangleShape_setSize(var->collider[31], (sfVector2f){180, 186});
    sfRectangleShape_setSize(var->collider[32], (sfVector2f){72, 150});
    sfRectangleShape_setSize(var->collider[34], (sfVector2f){252, 114});
    sfRectangleShape_setSize(var->collider[35], (sfVector2f){180, 36});
}
