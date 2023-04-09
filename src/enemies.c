/*
** EPITECH PROJECT, 2023
** enemies.c
** File description:
** enemies.c
*/

#include "my_rpg.h"

void display_orc(var_t *var)
{
    const float enemy_speed = ENEMY_SPEED;
    const sfFloatRect player_rect = sfSprite_getGlobalBounds(var->mc->sprite);
    const sfFloatRect zone_rect = {560.0f, 574.0f, 259.0f, 302.0f};
    const sfVector2f orc_pos = sfSprite_getPosition(ORC->sprite);
    const sfVector2f player_pos = sfSprite_getPosition(var->mc->sprite);
    sfVector2f orc_dir = {0.0f, 0.0f};
    float distance = 0.0f;
    sfVector2f direction = {0.0f, 0.0f};

    if (!sfFloatRect_intersects(&player_rect, &zone_rect, NULL))
        return;
    orc_dir.x = player_pos.x - orc_pos.x;
    orc_dir.y = player_pos.y - orc_pos.y;
    distance = sqrtf(powf(orc_dir.x, 2.0f) + powf(orc_dir.y, 2.0f));
    direction.x = orc_dir.x / distance;
    direction.y = orc_dir.y / distance;
    direction.x *= enemy_speed;
    direction.y *= enemy_speed;
    sfSprite_move(ORC->sprite, direction);
    DRAW_SPRITE(ORC->sprite);
}

void display_skeleton(var_t *var)
{
    const float enemy_speed = ENEMY_SPEED * 1.5f;
    const sfFloatRect player_rect = sfSprite_getGlobalBounds(var->mc->sprite);
    const sfFloatRect zone_rect = {560.0f, 574.0f, 259.0f, 302.0f};
    const sfVector2f skeleton_pos = sfSprite_getPosition(SKELETON->sprite);
    const sfVector2f player_pos = sfSprite_getPosition(var->mc->sprite);
    sfVector2f skeleton_dir = {0.0f, 0.0f};
    float distance = 0.0f;
    sfVector2f direction = {0.0f, 0.0f};

    if (!sfFloatRect_intersects(&player_rect, &zone_rect, NULL))
        return;
    skeleton_dir.x = player_pos.x - skeleton_pos.x;
    skeleton_dir.y = player_pos.y - skeleton_pos.y;
    distance = sqrtf(powf(skeleton_dir.x, 2.0f) + powf(skeleton_dir.y, 2.0f));
    direction.x = skeleton_dir.x / distance;
    direction.y = skeleton_dir.y / distance;
    direction.x *= enemy_speed;
    direction.y *= enemy_speed;
    sfSprite_move(SKELETON->sprite, direction);
    DRAW_SPRITE(SKELETON->sprite);
}

void check_enemies(var_t *var)
{
    display_skeleton(var);
    display_orc(var);
}
