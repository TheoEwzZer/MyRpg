/*
** EPITECH PROJECT, 2023
** enemies.c
** File description:
** enemies.c
*/

#include "my_rpg.h"

void check_enemies(var_t *var)
{
    if (SKELETON->life >= 0) {
        display_skeleton(var);
        fight_skeleton(var);
    }
    if (ORC->life >= 0) {
        display_orc(var);
        fight_orc(var);
    }
}

void knockback(var_t *var, sfClock *clock, char_t *enemy)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 1.0f) {
        enemy->life -= 20;
        sfClock_restart(clock);
        if (PLAYER->direction == UP) {
            sfSprite_move(enemy->sprite, (sfVector2f){0.0f, 30.0f});
            sfRectangleShape_move(enemy->hitbox, (sfVector2f){0.0f, 30.0f});
        }
        if (PLAYER->direction == DOWN) {
            sfSprite_move(enemy->sprite, (sfVector2f){0.0f, -30.0f});
            sfRectangleShape_move(enemy->hitbox, (sfVector2f){0.0f, -30.0f});
        }
        if (PLAYER->direction == LEFT) {
            sfSprite_move(enemy->sprite, (sfVector2f){-30.0f, 0.0f});
            sfRectangleShape_move(enemy->hitbox, (sfVector2f){-30.0f, 0.0f});
        }
        if (PLAYER->direction == RIGHT) {
            sfSprite_move(enemy->sprite, (sfVector2f){30.0f, 0.0f});
            sfRectangleShape_move(enemy->hitbox, (sfVector2f){30.0f, 0.0f});
        }
    }
}
