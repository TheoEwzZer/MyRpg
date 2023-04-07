/*
** EPITECH PROJECT, 2023
** ennemies.c
** File description:
** ennemies.c
*/

#include "my_rpg.h"

void display_orc(var_t *var)
{
    var->orc_pos = sfSprite_getPosition(var->orc->sprite);
    var->orc->times = sfClock_getElapsedTime(var->orc->walk);
    var->orc->second = (float)var->orc->times.microseconds / 1000000.0f;
    var->orc->rect.top = 77;
    var->orc->rect.width = 77;
    var->orc->rect.height = 77;
    if (var->orc->second > 0.05f) {
        if (var->orc->rect.left == 539)
            var->orc->rect.left = 0;
        else {
            var->orc_pos.x -= 2;
            sfSprite_setPosition(var->orc->sprite, var->orc_pos);
            var->orc->rect.left = var->orc->rect.left + 77;
        }
        sfClock_restart(var->orc->walk);
    }
    sfSprite_setTextureRect(var->orc->sprite, var->orc->rect);
    DRAW_SPRITE(var->orc->sprite);
}

void display_orc2(var_t *var)
{
    var->orc_pos = sfSprite_getPosition(var->orc->sprite);
    var->orc->times = sfClock_getElapsedTime(var->orc->walk);
    var->orc->second = (float)var->orc->times.microseconds / 1000000.0f;
    var->orc->rect.top = 154;
    var->orc->rect.width = 77;
    var->orc->rect.height = 77;
    if (var->orc->second > 0.05f) {
        if (var->orc->rect.left == 539)
            var->orc->rect.left = 0;
        else {
            var->orc_pos.x += 2;
            sfSprite_setPosition(var->orc->sprite, var->orc_pos);
            var->orc->rect.left = var->orc->rect.left + 77;
        }
        sfClock_restart(var->orc->walk);
    }
    sfSprite_setTextureRect(var->orc->sprite, var->orc->rect);
    DRAW_SPRITE(var->orc->sprite);
}

void display_skel2(var_t *var)
{
    var->skel_pos = sfSprite_getPosition(var->skel->sprite);
    var->skel->times = sfClock_getElapsedTime(var->skel->walk);
    var->skel->second = (float)var->skel->times.microseconds / 1000000.0f;
    var->skel->rect.top = 77;
    var->skel->rect.width = 77;
    var->skel->rect.height = 77;
    if (var->skel->second > 0.05f) {
        if (var->skel->rect.left == 539)
            var->skel->rect.left = 0;
        if (var->skel_pos.x <= 450 && var->skel->rect.left != 539)
            var->switch_side = true;
        else {
            var->skel_pos.x -= 3;
            sfSprite_setPosition(var->skel->sprite, var->skel_pos);
            var->skel->rect.left = var->skel->rect.left + 77;
        }
        sfClock_restart(var->skel->walk);
    }
    sfSprite_setTextureRect(var->skel->sprite, var->skel->rect);
    DRAW_SPRITE(var->skel->sprite);
}

void display_skel(var_t *var)
{
    var->skel_pos = sfSprite_getPosition(var->skel->sprite);
    var->skel->times = sfClock_getElapsedTime(var->skel->walk);
    var->skel->second = (float)var->skel->times.microseconds / 1000000.0f;
    var->skel->rect.top = 154;
    var->skel->rect.width = 77;
    var->skel->rect.height = 77;
    if (var->skel->second > 0.05f) {
        if (var->skel->rect.left == 539)
            var->skel->rect.left = 0;
        if (var->skel_pos.x >= 770 && var->skel->rect.left != 539)
            var->switch_side = false;
        else {
            var->skel_pos.x += 3;
            sfSprite_setPosition(var->skel->sprite, var->skel_pos);
            var->skel->rect.left = var->skel->rect.left + 77;
        }
        sfClock_restart(var->skel->walk);
    }
    sfSprite_setTextureRect(var->skel->sprite, var->skel->rect);
    DRAW_SPRITE(var->skel->sprite);
}

void check_ennemies(var_t *var)
{
    if (var->switch_side) {
        display_skel(var);
        display_orc(var);
    } else {
        display_skel2(var);
        display_orc2(var);
    }
}
