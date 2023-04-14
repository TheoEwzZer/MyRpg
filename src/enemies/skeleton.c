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
    const sfVector2f player_pos = sfSprite_getPosition(PLAYER->sprite);
    const sfVector2f skeleton_pos = sfSprite_getPosition(SKELETON->sprite);
    float dist = 0.0f;
    sfFloatRect skeleton_rect = {0.0f, 0.0f, 0.0f, 0.0f};
    sfVector2f direction, skeleton_dir = {0.0f, 0.0f};
    skeleton_dir.x = player_pos.x - skeleton_pos.x;
    skeleton_dir.y = player_pos.y - skeleton_pos.y;
    dist = sqrtf(powf(skeleton_dir.x, 2.f) + powf(skeleton_dir.y, 2.f));
    direction = (sfVector2f){skeleton_dir.x / dist, skeleton_dir.y / dist};
    skeleton_rect = create_enemy_rect(direction, SKELETON);
    if (!check_intersects(skeleton_rect, var)) {
        direction.x *= ENEMY_SPEED * 1.5f;
        direction.y *= ENEMY_SPEED * 1.5f;
        change_direction_skeleton(var, direction);
        animate_skeleton(var);
        sfRectangleShape_move(SKELETON->hitbox, direction);
        sfSprite_move(SKELETON->sprite, direction);
    }
    DRAW_SPRITE(SKELETON->sprite);
}

void init_skeleton(var_t *var)
{
    SKELETON->clothes = CREATE_FROM_FILE("assets/pnj/skeleton.png");
    SKELETON->direction = DOWN;
    SKELETON->hitbox = sfRectangleShape_create();
    SKELETON->life = 60;
    SKELETON->rect = (sfIntRect){0, 0, 77, 77};
    SKELETON->sprite = sfSprite_create();
    SKELETON->walk = sfClock_create();
    sfRectangleShape_setPosition(SKELETON->hitbox, (sfVector2f){575.f, 595.f});
    sfRectangleShape_setSize(SKELETON->hitbox, (sfVector2f){25.0f, 45.0f});
    sfSprite_setPosition(SKELETON->sprite, (sfVector2f){560.0f, 584.0f});
    sfSprite_setScale(SKELETON->sprite, (sfVector2f){0.75f, 0.75f});
    sfSprite_setTexture(SKELETON->sprite, SKELETON->clothes, sfTrue);
    sfSprite_setTextureRect(SKELETON->sprite, SKELETON->rect);
}

void fight_skeleton(var_t *var)
{
    sfFloatRect player_bounds = GET_BOUNDS(PLAYER->hitbox);
    sfFloatRect player_spear = GET_BOUNDS(PLAYER->spear);
    sfFloatRect skeleton_bounds = GET_BOUNDS(SKELETON->hitbox);
    static sfClock *clock_player = NULL;
    static sfClock *clock_skeleton = NULL;

    if (!clock_player)
        clock_player = sfClock_create();
    if (!clock_skeleton)
        clock_skeleton = sfClock_create();
    if (sfFloatRect_intersects(&player_bounds, &skeleton_bounds, NULL)) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock_player)) >= 1.0f) {
            PLAYER->life -= 20;
            sfClock_restart(clock_player);
        }
    }
    if (sfFloatRect_intersects(&player_spear, &skeleton_bounds, NULL)) {
        if (PLAYER->attack)
            knockback(var, clock_skeleton, SKELETON);
    }
}
