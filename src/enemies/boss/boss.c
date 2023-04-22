/*
** EPITECH PROJECT, 2023
** boss.c
** File description:
** boss.c
*/

#include "my_rpg.h"

void fight_boss(var_t *var)
{
    sfFloatRect boss_bounds = sfSprite_getGlobalBounds(BOSSC->sprite);
    sfFloatRect player_spear = GET_BOUNDS(PLAYER->spear);
    static sfClock *clock = NULL;

    if (!clock)
        clock = sfClock_create();
    if (PLAYER->attack
    && sfFloatRect_intersects(&player_spear, &boss_bounds, NULL)) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 1.0f) {
            BOSSC->life -= 30;
            sfClock_restart(clock);
        }
    }
}

void display_boss(var_t *var)
{
    BOSSV->boss_left = 470; BOSSV->boss_top = 2650;
    BOSSV->boss_height = 420; BOSSV->boss_width = 710;
    BOSSV->b_pos.x = (float)(BOSSV->boss_left + (rand() % BOSSV->boss_width));
    BOSSV->b_pos.y = (float)(BOSSV->boss_top + (rand() % BOSSV->boss_height));
    BOSSC->times = sfClock_getElapsedTime(BOSSC->walk);
    BOSSC->fireball_t = sfClock_getElapsedTime(BOSSC->fireball);
    BOSSC->second = (float)BOSSC->times.microseconds / 1000000.0f;
    BOSSC->fireball_second = (float)BOSSC->fireball_t.microseconds / 1000000.0f;
    if (BOSSC->second > 5.0f && !var->is_paused) {
        sfSprite_setPosition(BOSSC->sprite, BOSSV->b_pos);
        BOSSV->b_pos.x += 20.0f;
        BOSSV->b_pos.y += 30.0f;
        set_fireball_position(var);
        sfClock_restart(BOSSC->walk);
    }
    if (BOSSC->fireball_second > 0.01f && !var->is_paused) {
        for (sfUint32 i = 0; i < CONFIG->max_fireball; i++)
            move_fireball(var, i);
        sfClock_restart(BOSSC->fireball);
    }
}

void boss_fight(var_t *var)
{
    if (BOSSC->life <= 0)
        return;
    BOSSC->rect.left = 0;
    BOSSC->rect.top = 0;
    BOSSC->rect.width = 77;
    BOSSC->rect.height = 77;
    sfSprite_setTextureRect(BOSSC->sprite, BOSSC->rect);
    display_boss(var);
    fight_boss(var);
    DRAW_SPRITE(BOSSC->sprite);
    check_fireball_collision(var);
    for (sfUint32 i = 0; i < CONFIG->max_fireball; i++) {
        if (FIREBALL[i]->is_active) {
            DRAW_SPRITE(FIREBALL[i]->sprite);
        }
    }
}
