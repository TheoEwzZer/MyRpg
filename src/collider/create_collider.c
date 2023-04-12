/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_collider2(var_t *var)
{
    create_barrier_collider(var);
    create_house_collider(var);
    create_north_west_position(var);
    create_north_west_size(var);
    create_png_collider(var);
    create_sud_collider(var);
    create_tree_collider(var);
    create_water_collider(var);
    create_west_collider(var);
    create_foreground(var);
}

void create_collider(var_t *var)
{
    sfVector2f spear_zone_position = {1700.0f, 1300.0f};
    sfVector2f spear_zone_size = {30.0f, 40.0f};
    sfVector2f hitbox_position = {1700.0f, 1340.0f};

    PLAYER->hitbox = sfRectangleShape_create();
    PLAYER->spear_zone = sfRectangleShape_create();
    sfRectangleShape_setPosition(PLAYER->hitbox, hitbox_position);
    sfRectangleShape_setPosition(PLAYER->spear_zone, spear_zone_position);
    sfRectangleShape_setSize(PLAYER->spear_zone, spear_zone_size);
    COLLIDER = malloc(sizeof(sfRectangleShape *) * 65);
    var->collider_bounds = malloc(sizeof(sfFloatRect) * 65);
    for (unsigned int i = 0; i < 65; i++)
        COLLIDER[i] = sfRectangleShape_create();
    create_collider2(var);
    for (unsigned int i = 0; i < 65; i++)
        var->collider_bounds[i] = GET_BOUNDS(COLLIDER[i]);
}
