/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_collider(var_t *var)
{
    var->hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition(var->hitbox, (sfVector2f){1700, 1340});
    var->collider = malloc(sizeof(sfRectangleShape *) * 62);
    var->collider_bounds = malloc(sizeof(sfFloatRect) * 62);
    for (int i = 0; i < 62; i++)
        var->collider[i] = sfRectangleShape_create();
    create_water_collider(var);
    create_north_ouest_position(var);
    create_north_ouest_size(var);
    create_house_collider(var);
    create_barrer_collider(var);
    create_tree_collider(var);
    create_west_collider(var);
    create_sud_collider(var);
    for (int i = 0; i < 62; i++)
        var->collider_bounds[i] = GET_BOUNDS(var->collider[i]);
}
