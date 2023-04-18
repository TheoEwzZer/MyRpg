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
    if (BOSSC->life <= 100) {
        direction.x *= 1.5f;
        direction.y *= 1.5f;
    }
    return direction;
}

void set_fireball_position(var_t *var)
{
    for (sfUint32 i = 0; i < MAX_FIREBALL; i++) {
        if (!FIREBALL[i]->is_active) {
            FIREBALL[i]->is_active = sfTrue;
            FIREBALL[i]->direction = get_fireball_direction(var);
            sfSprite_setPosition(FIREBALL[i]->sprite, BOSSV->b_pos);
            sfRectangleShape_setPosition(FIREBALL[i]->hitbox, BOSSV->b_pos);
            break;
        }
    }
}

void move_fireball(var_t *var, sfUint32 i)
{
    if (FIREBALL[i]->is_active) {
        sfSprite_move(FIREBALL[i]->sprite, FIREBALL[i]->direction);
        sfRectangleShape_move(FIREBALL[i]->hitbox, FIREBALL[i]->direction);
        if (sfSprite_getPosition(FIREBALL[i]->sprite).x < 470
        || sfSprite_getPosition(FIREBALL[i]->sprite).x > 1180
        || sfSprite_getPosition(FIREBALL[i]->sprite).y < 2650
        || sfSprite_getPosition(FIREBALL[i]->sprite).y > 3070)
            FIREBALL[i]->is_active = sfFalse;
    }
}

void check_fireball_collision(var_t *var)
{
    sfFloatRect player_bounds = GET_BOUNDS(PLAYER->hitbox);
    sfFloatRect fireball_bounds = {0.0f, 0.0f, 0.0f, 0.0f};

    for (sfUint32 i = 0; i < MAX_FIREBALL; i++) {
        fireball_bounds = GET_BOUNDS(FIREBALL[i]->hitbox);
        if (FIREBALL[i]->is_active
        && sfFloatRect_intersects(&player_bounds, &fireball_bounds, NULL)) {
            PLAYER->life -= 20;
            FIREBALL[i]->is_active = sfFalse;
        }
    }
}
