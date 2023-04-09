/*
** EPITECH PROJECT, 2023
** attack.c
** File description:
** attack.c
*/

#include "my_rpg.h"

void attack_right(var_t *var)
{
    var->mc->times = sfClock_getElapsedTime(var->mc->walk);
    var->mc->second = (float)var->mc->times.microseconds / 1000000.0f;
    var->mc->rect.top = 154;
    if (var->mc->second > 0.1f) {
        var->mc->rect.left += 77;
        if (var->mc->rect.left >= 924) {
            var->mc->rect.left = 0;
            var->mc->attack = 0;
        }
        sfClock_restart(var->mc->walk);
    }
    sfSprite_setTextureRect(var->mc->sprite, var->mc->rect);
}

void attack_down(var_t *var)
{
    var->mc->times = sfClock_getElapsedTime(var->mc->walk);
    var->mc->second = (float)var->mc->times.microseconds / 1000000.0f;
    var->mc->rect.top = 231;
    if (var->mc->second > 0.1f) {
        var->mc->rect.left += 77;
        if (var->mc->rect.left >= 924) {
            var->mc->rect.left = 0;
            var->mc->attack = 0;
        }
        sfClock_restart(var->mc->walk);
    }
    sfSprite_setTextureRect(var->mc->sprite, var->mc->rect);
}

void attack_up(var_t *var)
{
    var->mc->times = sfClock_getElapsedTime(var->mc->walk);
    var->mc->second = (float)var->mc->times.microseconds / 1000000.0f;
    var->mc->rect.top = 0;
    if (var->mc->second > 0.1f) {
        var->mc->rect.left += 77;
        if (var->mc->rect.left >= 924) {
            var->mc->rect.left = 0;
            var->mc->attack = 0;
        }
        sfClock_restart(var->mc->walk);
    }
    sfSprite_setTextureRect(var->mc->sprite, var->mc->rect);
}

void attack_left(var_t *var)
{
    var->mc->times = sfClock_getElapsedTime(var->mc->walk);
    var->mc->second = (float)var->mc->times.microseconds / 1000000.0f;
    var->mc->rect.top = 77;
    if (var->mc->second > 0.1f) {
        var->mc->rect.left += 77;
        if (var->mc->rect.left >= 924) {
            var->mc->rect.left = 0;
            var->mc->attack = false;
        }
        sfClock_restart(var->mc->walk);
    }
    sfSprite_setTextureRect(var->mc->sprite, var->mc->rect);
}

void attack_move(var_t *var)
{
    sfSound_play(SOUND->spear);
    if (var->direction == UP)
        attack_up(var);
    if (var->direction == LEFT)
        attack_left(var);
    if (var->direction == RIGHT)
        attack_right(var);
    if (var->direction == DOWN)
        attack_down(var);
}
