/*
** EPITECH PROJECT, 2023
** attack.c
** File description:
** attack.c
*/

#include "my_rpg.h"

void attack_right(var_t *var)
{
    PLAYER->times = sfClock_getElapsedTime(PLAYER->walk);
    PLAYER->second = (float)PLAYER->times.microseconds / 1000000.0f;
    PLAYER->rect.top = 154;
    if (PLAYER->second > 0.1f) {
        PLAYER->rect.left += 77;
        if (PLAYER->rect.left >= 924) {
            PLAYER->rect.left = 0;
            PLAYER->attack = sfFalse;
        }
        sfClock_restart(PLAYER->walk);
    }
    sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
}

void attack_down(var_t *var)
{
    PLAYER->times = sfClock_getElapsedTime(PLAYER->walk);
    PLAYER->second = (float)PLAYER->times.microseconds / 1000000.0f;
    PLAYER->rect.top = 231;
    if (PLAYER->second > 0.1f) {
        PLAYER->rect.left += 77;
        if (PLAYER->rect.left >= 924) {
            PLAYER->rect.left = 0;
            PLAYER->attack = sfFalse;
        }
        sfClock_restart(PLAYER->walk);
    }
    sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
}

void attack_up(var_t *var)
{
    PLAYER->times = sfClock_getElapsedTime(PLAYER->walk);
    PLAYER->second = (float)PLAYER->times.microseconds / 1000000.0f;
    PLAYER->rect.top = 0;
    if (PLAYER->second > 0.1f) {
        PLAYER->rect.left += 77;
        if (PLAYER->rect.left >= 924) {
            PLAYER->rect.left = 0;
            PLAYER->attack = sfFalse;
        }
        sfClock_restart(PLAYER->walk);
    }
    sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
}

void attack_left(var_t *var)
{
    PLAYER->times = sfClock_getElapsedTime(PLAYER->walk);
    PLAYER->second = (float)PLAYER->times.microseconds / 1000000.0f;
    PLAYER->rect.top = 77;
    if (PLAYER->second > 0.1f) {
        PLAYER->rect.left += 77;
        if (PLAYER->rect.left >= 924) {
            PLAYER->rect.left = 0;
            PLAYER->attack = sfFalse;
        }
        sfClock_restart(PLAYER->walk);
    }
    sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
}

void attack_move(var_t *var)
{
    sfSound_play(SOUND->spear);
    if (PLAYER->direction == UP)
        attack_up(var);
    if (PLAYER->direction == LEFT)
        attack_left(var);
    if (PLAYER->direction == RIGHT)
        attack_right(var);
    if (PLAYER->direction == DOWN)
        attack_down(var);
}
