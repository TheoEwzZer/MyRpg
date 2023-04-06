/*
** EPITECH PROJECT, 2023
** character_move
** File description:
** character_move
*/

#include "my_rpg.h"

void right_move(var_t *var)
{
    var->mc->times = sfClock_getElapsedTime(var->mc->walk);
    var->mc->second = (float)var->mc->times.microseconds / 1000000.0f;
    var->mc->rect.top = 154;
    var->mc->rect.width = 77;
    var->mc->rect.height = 77;
    if (var->mc->second > 0.05f) {
        if (var->mc->rect.left == 539) {
            var->mc->rect.left = 0;
        } else {
            var->mc->rect.left = var->mc->rect.left + 77;
        }
        sfClock_restart(var->mc->walk);
    }
    sfSprite_setTextureRect(var->mc->sprite, var->mc->rect);
    DRAW_SPRITE(var->mc->sprite);
}

void left_move(var_t *var)
{
    var->mc->times = sfClock_getElapsedTime(var->mc->walk);
    var->mc->second = (float)var->mc->times.microseconds / 1000000.0f;
    var->mc->rect.top = 77;
    var->mc->rect.width = 77;
    var->mc->rect.height = 77;
    if (var->mc->second > 0.05f) {
        if (var->mc->rect.left == 539) {
            var->mc->rect.left = 0;
        } else {
            var->mc->rect.left = var->mc->rect.left + 77;
        }
        sfClock_restart(var->mc->walk);
    }
    sfSprite_setTextureRect(var->mc->sprite, var->mc->rect);
    DRAW_SPRITE(var->mc->sprite);
}

void back_move(var_t *var)
{
    var->mc->times = sfClock_getElapsedTime(var->mc->walk);
    var->mc->second = (float)var->mc->times.microseconds / 1000000.0f;
    var->mc->rect.top = 231;
    var->mc->rect.width = 77;
    var->mc->rect.height = 77;
    if (var->mc->second > 0.05f) {
        if (var->mc->rect.left == 539) {
            var->mc->rect.left = 0;
        } else {
            var->mc->rect.left = var->mc->rect.left + 77;
        }
        sfClock_restart(var->mc->walk);
    }
    sfSprite_setTextureRect(var->mc->sprite, var->mc->rect);
    DRAW_SPRITE(var->mc->sprite);
}

void front_move(var_t *var)
{
    var->mc->times = sfClock_getElapsedTime(var->mc->walk);
    var->mc->second = (float)var->mc->times.microseconds / 1000000.0f;
    var->mc->rect.top = 0;
    var->mc->rect.width = 77;
    var->mc->rect.height = 77;
    if (var->mc->second > 0.05f) {
        if (var->mc->rect.left == 539) {
            var->mc->rect.left = 0;
        } else {
            var->mc->rect.left = var->mc->rect.left + 77;
        }
        sfClock_restart(var->mc->walk);
    }
    sfSprite_setTextureRect(var->mc->sprite, var->mc->rect);
    DRAW_SPRITE(var->mc->sprite);
}
