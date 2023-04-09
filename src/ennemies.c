/*
** EPITECH PROJECT, 2023
** enemies.c
** File description:
** enemies.c
*/

#include "my_rpg.h"

void display_orc(var_t *var)
{
    var->orc_position = sfSprite_getPosition(var->orc->sprite);
    var->orc->times = sfClock_getElapsedTime(var->orc->walk);
    var->orc->second = (float)var->orc->times.microseconds / 1000000.0f;
    var->orc->rect.top = 77;
    var->orc->rect.width = 77;
    var->orc->rect.height = 77;
    if (var->orc->second > 0.05f) {
        if (var->orc->rect.left == 539)
            var->orc->rect.left = 0;
        else {
            var->orc_position.x -= 2;
            sfSprite_setPosition(var->orc->sprite, var->orc_position);
            var->orc->rect.left = var->orc->rect.left + 77;
        }
        sfClock_restart(var->orc->walk);
    }
    sfSprite_setTextureRect(var->orc->sprite, var->orc->rect);
    DRAW_SPRITE(var->orc->sprite);
}

void display_orc2(var_t *var)
{
    var->orc_position = sfSprite_getPosition(var->orc->sprite);
    var->orc->times = sfClock_getElapsedTime(var->orc->walk);
    var->orc->second = (float)var->orc->times.microseconds / 1000000.0f;
    var->orc->rect.top = 154;
    var->orc->rect.width = 77;
    var->orc->rect.height = 77;
    if (var->orc->second > 0.05f) {
        if (var->orc->rect.left == 539)
            var->orc->rect.left = 0;
        else {
            var->orc_position.x += 2;
            sfSprite_setPosition(var->orc->sprite, var->orc_position);
            var->orc->rect.left = var->orc->rect.left + 77;
        }
        sfClock_restart(var->orc->walk);
    }
    sfSprite_setTextureRect(var->orc->sprite, var->orc->rect);
    DRAW_SPRITE(var->orc->sprite);
}

void display_skeleton2(var_t *var)
{
    var->skeleton_position = sfSprite_getPosition(SKELETON->sprite);
    SKELETON->times = sfClock_getElapsedTime(SKELETON->walk);
    SKELETON->second = (float)SKELETON->times.microseconds / 1000000.0f;
    SKELETON->rect.top = 77;
    SKELETON->rect.width = 77;
    SKELETON->rect.height = 77;
    if (SKELETON->second > 0.05f) {
        if (SKELETON->rect.left == 539)
            SKELETON->rect.left = 0;
        if (var->skeleton_position.x <= 450 && SKELETON->rect.left != 539)
            var->switch_side = true;
        else {
            var->skeleton_position.x -= 3;
            sfSprite_setPosition(SKELETON->sprite, var->skeleton_position);
            SKELETON->rect.left = SKELETON->rect.left + 77;
        }
        sfClock_restart(SKELETON->walk);
    }
    sfSprite_setTextureRect(SKELETON->sprite, SKELETON->rect);
    DRAW_SPRITE(SKELETON->sprite);
}

void display_skeleton(var_t *var)
{
    var->skeleton_position = sfSprite_getPosition(SKELETON->sprite);
    SKELETON->times = sfClock_getElapsedTime(SKELETON->walk);
    SKELETON->second = (float)SKELETON->times.microseconds / 1000000.0f;
    SKELETON->rect.top = 154;
    SKELETON->rect.width = 77;
    SKELETON->rect.height = 77;
    if (SKELETON->second > 0.05f) {
        if (SKELETON->rect.left == 539)
            SKELETON->rect.left = 0;
        if (var->skeleton_position.x >= 770 && SKELETON->rect.left != 539)
            var->switch_side = false;
        else {
            var->skeleton_position.x += 3;
            sfSprite_setPosition(SKELETON->sprite, var->skeleton_position);
            SKELETON->rect.left = SKELETON->rect.left + 77;
        }
        sfClock_restart(SKELETON->walk);
    }
    sfSprite_setTextureRect(SKELETON->sprite, SKELETON->rect);
    DRAW_SPRITE(SKELETON->sprite);
}

void check_enemies(var_t *var)
{
    if (var->switch_side) {
        display_skeleton(var);
        display_orc(var);
    } else {
        display_skeleton2(var);
        display_orc2(var);
    }
}
