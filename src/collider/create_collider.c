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
    var->collider = malloc(sizeof(sfRectangleShape *) * 65);
    var->collider_bounds = malloc(sizeof(sfFloatRect) * 65);
    for (unsigned int i = 0; i < 65; i++)
        var->collider[i] = sfRectangleShape_create();
    create_water_collider(var);
    create_north_ouest_position(var);
    create_north_ouest_size(var);
    create_house_collider(var);
    create_barrer_collider(var);
    create_tree_collider(var);
    create_west_collider(var);
    create_sud_collider(var);
    create_png_collider(var);
    create_foreground(var);
    for (unsigned int i = 0; i < 65; i++)
        var->collider_bounds[i] = GET_BOUNDS(var->collider[i]);
}
