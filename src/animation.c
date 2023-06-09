/*
** EPITECH PROJECT, 2023
** character_move
** File description:
** character_move
*/

#include "my_rpg.h"

void right_move(var_t *var)
{
    if (PLAYER->direction == LEFT)
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){60.0f, 0.0f});
    if (PLAYER->direction == UP)
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){30.0f, -15.0f});
    if (PLAYER->direction == DOWN)
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){30.0f, 15.0f});
    PLAYER->times = sfClock_getElapsedTime(PLAYER->walk);
    PLAYER->second = (float)PLAYER->times.microseconds / 1000000.0f;
    PLAYER->rect = (sfIntRect){PLAYER->rect.left, 154, 77, 77};
    if (PLAYER->second > 0.05f) {
        if (PLAYER->rect.left == 539)
            PLAYER->rect.left = 0;
        else
            PLAYER->rect.left += 77;
        sfClock_restart(PLAYER->walk);
    }
    PLAYER->direction = RIGHT;
    sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
}

void left_move(var_t *var)
{
    if (PLAYER->direction == RIGHT)
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){-60.0f, 0.0f});
    if (PLAYER->direction == UP)
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){-30.0f, -15.0f});
    if (PLAYER->direction == DOWN)
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){-30.0f, 15.0f});
    PLAYER->times = sfClock_getElapsedTime(PLAYER->walk);
    PLAYER->second = (float)PLAYER->times.microseconds / 1000000.0f;
    PLAYER->rect = (sfIntRect){PLAYER->rect.left, 77, 77, 77};
    if (PLAYER->second > 0.05f) {
        if (PLAYER->rect.left == 539)
            PLAYER->rect.left = 0;
        else
            PLAYER->rect.left += 77;
        sfClock_restart(PLAYER->walk);
    }
    PLAYER->direction = LEFT;
    sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
    if (var->tutorial->is_active && var->quest_progress == PRISCILLA)
        var->tutorial->is_active = sfFalse;
}

void down_move(var_t *var)
{
    if (PLAYER->direction == LEFT)
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){30.0f, 15.0f});
    if (PLAYER->direction == DOWN)
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){0.0f, 30.0f});
    if (PLAYER->direction == RIGHT)
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){-30.0f, 15.0f});
    PLAYER->times = sfClock_getElapsedTime(PLAYER->walk);
    PLAYER->second = (float)PLAYER->times.microseconds / 1000000.0f;
    PLAYER->rect = (sfIntRect){PLAYER->rect.left, 0, 77, 77};
    if (PLAYER->second > 0.05f) {
        if (PLAYER->rect.left == 539)
            PLAYER->rect.left = 0;
        else
            PLAYER->rect.left += 77;
        sfClock_restart(PLAYER->walk);
    }
    PLAYER->direction = UP;
    sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
}

void up_move(var_t *var)
{
    if (PLAYER->direction == LEFT)
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){30.0f, -15.0f});
    if (PLAYER->direction == UP)
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){0.0f, -30.0f});
    if (PLAYER->direction == RIGHT)
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){-30.0f, -15.0f});
    PLAYER->times = sfClock_getElapsedTime(PLAYER->walk);
    PLAYER->second = (float)PLAYER->times.microseconds / 1000000.0f;
    PLAYER->rect = (sfIntRect){PLAYER->rect.left, 231, 77, 77};
    if (PLAYER->second > 0.05f) {
        if (PLAYER->rect.left == 539)
            PLAYER->rect.left = 0;
        else
            PLAYER->rect.left += 77;
        sfClock_restart(PLAYER->walk);
    }
    PLAYER->direction = DOWN;
    sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
}
