/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_boss_room_collider(var_t *var)
{
    sfRectangleShape_setPosition(COLLIDER[67], (sfVector2f){450.0f, 2550.0f});
    sfRectangleShape_setPosition(COLLIDER[68], (sfVector2f){450.0f, 2550.0f});
    sfRectangleShape_setPosition(COLLIDER[69], (sfVector2f){450.0f, 3125.0f});
    sfRectangleShape_setPosition(COLLIDER[70], (sfVector2f){1215.0f, 2550.0f});
    sfRectangleShape_setSize(COLLIDER[67], (sfVector2f){45.0f, 620.0f});
    sfRectangleShape_setSize(COLLIDER[68], (sfVector2f){816.0f, 144.0f});
    sfRectangleShape_setSize(COLLIDER[69], (sfVector2f){815.0f, 45.0f});
    sfRectangleShape_setSize(COLLIDER[70], (sfVector2f){45.0f, 620.0f});
}