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
    sfFloatRect enemy_rect = sfSprite_getGlobalBounds(enemy->sprite);
    sfVector2f offset = {0.0f, 0.0f};

    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 1.0f) {
        enemy->life -= 20;
        sfClock_restart(clock);
        if (PLAYER->direction == UP) {
            enemy_rect.top -= 30.0f; offset.y = 30.0f;
        } if (PLAYER->direction == DOWN) {
            enemy_rect.top += 30.0f; offset.y = -30.0f;
        } if (PLAYER->direction == LEFT) {
            enemy_rect.left -= 30.0f; offset.x = -30.0f;
        } if (PLAYER->direction == RIGHT) {
            enemy_rect.left += 30.0f; offset.x = 30.0f;
        }
        if (!check_intersects(enemy_rect, var)) {
            sfSprite_move(enemy->sprite, offset);
            sfRectangleShape_move(enemy->hitbox, offset);
        }
    }
}

sfFloatRect create_enemy_rect(sfVector2f direction, char_t *enemy)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(enemy->sprite);
    float tmp = rect.height;

    rect.height = rect.height / 5.0f;
    rect.top += tmp - rect.height;
    rect.width = 25.0f;
    if (direction.x > 0) {
        rect.width += 1.0f;
    } else if (direction.x < 0) {
        rect.left -= 1.0f;
        rect.width += 1.0f;
    }
    if (direction.y > 0) {
        rect.height += 1.0f;
    } else if (direction.y < 0) {
        rect.top -= 1.0f;
        rect.height += 1.0f;
    }
    return rect;
}
