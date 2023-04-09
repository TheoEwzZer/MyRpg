/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_water_collider(var_t *var)
{
    sfRectangleShape_setPosition(COLLIDER[42], (sfVector2f){1232.0f, 262.0f});
    sfRectangleShape_setPosition(COLLIDER[43], (sfVector2f){1191.0f, 293.0f});
    sfRectangleShape_setPosition(COLLIDER[44], (sfVector2f){1266.0f, 293.0f});
    sfRectangleShape_setPosition(COLLIDER[45], (sfVector2f){1300.0f, 329.0f});
    sfRectangleShape_setPosition(COLLIDER[46], (sfVector2f){1615.0f, 363.0f});
    sfRectangleShape_setPosition(COLLIDER[47], (sfVector2f){1732.0f, 532.0f});
    sfRectangleShape_setPosition(COLLIDER[48], (sfVector2f){1658.0f, 328.0f});
    sfRectangleShape_setSize(COLLIDER[42], (sfVector2f){273.0f, 193.0f});
    sfRectangleShape_setSize(COLLIDER[43], (sfVector2f){42.0f, 132.0f});
    sfRectangleShape_setSize(COLLIDER[44], (sfVector2f){313.0f, 203.0f});
    sfRectangleShape_setSize(COLLIDER[45], (sfVector2f){318.0f, 203.0f});
    sfRectangleShape_setSize(COLLIDER[46], (sfVector2f){183.0f, 169.0f});
    sfRectangleShape_setSize(COLLIDER[47], (sfVector2f){66.0f, 36.0f});
    sfRectangleShape_setSize(COLLIDER[48], (sfVector2f){104.0f, 43.0f});
}
