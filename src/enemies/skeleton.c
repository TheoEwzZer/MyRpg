/*
** EPITECH PROJECT, 2023
** enemies.c
** File description:
** enemies.c
*/

#include "my_rpg.h"

void animate_skeleton(var_t *var)
{
    const sfTime time = sfClock_getElapsedTime(SKELETON->walk);
    const float second = sfTime_asSeconds(time);

    if (second > 0.1f) {
        SKELETON->rect.left += 77;
        if (SKELETON->rect.left >= 539)
            SKELETON->rect.left = 0;
        sfClock_restart(SKELETON->walk);
    }
}

void change_direction_skeleton(var_t *var, sfVector2f direction)
{
    if (direction.x > direction.y) {
        if (direction.x > 0 && SKELETON->direction != RIGHT) {
            SKELETON->direction = RIGHT;
            SKELETON->rect.left = 0; SKELETON->rect.top = 154;
        } if (direction.x < 0 && SKELETON->direction != LEFT) {
            SKELETON->direction = LEFT;
            SKELETON->rect.left = 0; SKELETON->rect.top = 231;
        }
    } else {
        if (direction.y > 0 && SKELETON->direction != DOWN) {
            SKELETON->direction = DOWN;
            SKELETON->rect.left = 0; SKELETON->rect.top = 0;
        } if (direction.y < 0 && SKELETON->direction != UP) {
            SKELETON->direction = UP;
            SKELETON->rect.left = 0; SKELETON->rect.top = 77;
        }
    }
    sfSprite_setTextureRect(SKELETON->sprite, SKELETON->rect);
}

void display_skeleton(var_t *var)
{
    const sfFloatRect player_rect = sfSprite_getGlobalBounds(var->mc->sprite);
    const sfFloatRect zone_rect = {560.0f, 574.0f, 259.0f, 302.0f};
    const sfVector2f skeleton_pos = sfSprite_getPosition(SKELETON->sprite);
    const sfVector2f player_pos = sfSprite_getPosition(var->mc->sprite);
    sfVector2f skeleton_dir = {0.0f, 0.0f};
    float distance = 0.0f;
    sfVector2f direction = {0.0f, 0.0f};
    if (sfFloatRect_intersects(&player_rect, &zone_rect, NULL)) {
        skeleton_dir.x = player_pos.x - skeleton_pos.x;
        skeleton_dir.y = player_pos.y - skeleton_pos.y;
        distance = sqrtf(powf(skeleton_dir.x, 2.f) + powf(skeleton_dir.y, 2.f));
        direction.x = skeleton_dir.x / distance;
        direction.y = skeleton_dir.y / distance;
        direction.x *= ENEMY_SPEED * 1.5f;
        direction.y *= ENEMY_SPEED * 1.5f;
        change_direction_skeleton(var, direction);
        animate_skeleton(var);
    }
    sfSprite_move(SKELETON->sprite, direction);
    DRAW_SPRITE(SKELETON->sprite);
}

void init_skeleton(var_t *var)
{
    SKELETON->clothes = CREATE_FROM_FILE("assets/pnj/skeleton.png");
    SKELETON->direction = DOWN;
    SKELETON->rect = (sfIntRect){0, 0, 77, 77};
    SKELETON->sprite = sfSprite_create();
    SKELETON->walk = sfClock_create();
    sfSprite_setPosition(SKELETON->sprite, (sfVector2f){560.0f, 574.0f});
    sfSprite_setScale(SKELETON->sprite, (sfVector2f){0.75f, 0.75f});
    sfSprite_setTexture(SKELETON->sprite, SKELETON->clothes, sfTrue);
    sfSprite_setTextureRect(SKELETON->sprite, SKELETON->rect);
}

void check_enemies(var_t *var)
{
    display_skeleton(var);
    display_orc(var);
}
