/*
** EPITECH PROJECT, 2023
** boss.c
** File description:
** boss.c
*/

#include "my_rpg.h"

void display_boss(var_t *var)
{
    BOSSV->boss_left = 470;
    BOSSV->boss_top = 2650;
    BOSSV->boss_height = 420;
    BOSSV->boss_width = 710;
    BOSSV->b_pos.x = (float)(BOSSV->boss_left + (rand() % BOSSV->boss_width));
    BOSSV->b_pos.y = (float)(BOSSV->boss_top + (rand() % BOSSV->boss_height));
    BOSSV->boss->times = sfClock_getElapsedTime(BOSSV->boss->walk);
    BOSSV->boss->second = (float)BOSSV->boss->times.microseconds / 1000000.0f;
    if (BOSSV->boss->second > 5.0f) {
        sfSprite_setPosition(BOSSV->boss->sprite, BOSSV->b_pos);
        sfClock_restart(BOSSV->boss->walk);
    }
}

void boss_fight(var_t *var)
{
    BOSSV->boss->rect.left = 0;
    BOSSV->boss->rect.top = 0;
    BOSSV->boss->rect.width = 77;
    BOSSV->boss->rect.height = 77;
    sfSprite_setTextureRect(BOSSV->boss->sprite, BOSSV->boss->rect);
    display_boss(var);
    DRAW_SPRITE(BOSSV->boss->sprite);
}
