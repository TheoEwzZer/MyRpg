/*
** EPITECH PROJECT, 2023
** boss.c
** File description:
** boss.c
*/

#include "my_rpg.h"

sfVector2f get_fireball_direction(var_t *var)
{
    const sfVector2f boss_position = sfSprite_getPosition(BOSSC->sprite);
    const sfVector2f player_position = sfSprite_getPosition(PLAYER->sprite);
    float distance = 0.0f;
    sfVector2f boss_dir = {0.0f, 0.0f};
    sfVector2f direction = {0.0f, 0.0f};

    boss_dir.x = player_position.x - boss_position.x;
    boss_dir.y = player_position.y - boss_position.y;
    distance = sqrtf(powf(boss_dir.x, 2.f) + powf(boss_dir.y, 2.f));
    direction = (sfVector2f){boss_dir.x / distance, boss_dir.y / distance};
    direction.x *= 1.5f;
    direction.y *= 1.5f;
    return direction;
}

void set_fireball_position(var_t *var)
{
    for (sfUint32 i = 0; i < MAX_FIREBALL; i++) {
        if (!FIREBALL[i]->is_active) {
            FIREBALL[i]->is_active = sfTrue;
            FIREBALL[i]->direction = get_fireball_direction(var);
            sfSprite_setPosition(FIREBALL[i]->sprite, BOSSV->b_pos);
            break;
        }
    }
}

void move_fireball(var_t *var, sfUint32 i)
{
    if (FIREBALL[i]->is_active) {
        sfSprite_move(FIREBALL[i]->sprite, FIREBALL[i]->direction);
        if (sfSprite_getPosition(FIREBALL[i]->sprite).x < 470
        || sfSprite_getPosition(FIREBALL[i]->sprite).x > 1180
        || sfSprite_getPosition(FIREBALL[i]->sprite).y < 2650
        || sfSprite_getPosition(FIREBALL[i]->sprite).y > 3070)
            FIREBALL[i]->is_active = sfFalse;
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
    if (BOSSC->second > 3.0f) {
        sfSprite_setPosition(BOSSC->sprite, BOSSV->b_pos);
        BOSSV->b_pos.x += 20.0f;
        BOSSV->b_pos.y += 30.0f;
        set_fireball_position(var);
        sfClock_restart(BOSSC->walk);
    }
    if (BOSSC->fireball_second > 0.01f) {
        for (sfUint32 i = 0; i < MAX_FIREBALL; i++)
            move_fireball(var, i);
        sfClock_restart(BOSSC->fireball);
    }
}

void boss_fight(var_t *var)
{
    BOSSC->rect.left = 0;
    BOSSC->rect.top = 0;
    BOSSC->rect.width = 77;
    BOSSC->rect.height = 77;
    sfSprite_setTextureRect(BOSSC->sprite, BOSSC->rect);
    display_boss(var);
    DRAW_SPRITE(BOSSC->sprite);
    for (sfUint32 i = 0; i < MAX_FIREBALL; i++) {
        if (FIREBALL[i]->is_active)
            DRAW_SPRITE(FIREBALL[i]->sprite);
    }
}
