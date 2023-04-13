/*
** EPITECH PROJECT, 2023
** enemies.c
** File description:
** enemies.c
*/

#include "my_rpg.h"

void animate_orc(var_t *var)
{
    const sfTime time = sfClock_getElapsedTime(ORC->walk);
    const float second = sfTime_asSeconds(time);

    if (second > 0.1f) {
        ORC->rect.left += 77;
        if (ORC->rect.left >= 539)
            ORC->rect.left = 0;
        sfClock_restart(ORC->walk);
    }
}

void change_direction_orc(var_t *var, sfVector2f direction)
{
    if (direction.x > direction.y) {
        if (direction.x > 0 && ORC->direction != RIGHT) {
            ORC->direction = RIGHT;
            ORC->rect.left = 0; ORC->rect.top = 154;
        } if (direction.x < 0 && ORC->direction != LEFT) {
            ORC->direction = LEFT;
            ORC->rect.left = 0; ORC->rect.top = 231;
        }
    } else {
        if (direction.y > 0 && ORC->direction != DOWN) {
            ORC->direction = DOWN;
            ORC->rect.left = 0; ORC->rect.top = 0;
        } if (direction.y < 0 && ORC->direction != UP) {
            ORC->direction = UP;
            ORC->rect.left = 0; ORC->rect.top = 77;
        }
    }
    sfSprite_setTextureRect(ORC->sprite, ORC->rect);
}

void display_orc(var_t *var)
{
    const sfVector2f player_pos = sfSprite_getPosition(PLAYER->sprite);
    const sfVector2f orc_pos = sfSprite_getPosition(ORC->sprite);
    float dist = 0.0f;
    sfFloatRect orc_rect = {0.0f, 0.0f, 0.0f, 0.0f};
    sfVector2f direction, orc_dir = {0.0f, 0.0f};
    orc_dir.x = player_pos.x - orc_pos.x;
    orc_dir.y = player_pos.y - orc_pos.y;
    dist = sqrtf(powf(orc_dir.x, 2.f) + powf(orc_dir.y, 2.f));
    direction = (sfVector2f){orc_dir.x / dist, orc_dir.y / dist};
    orc_rect = create_enemy_rect(direction, ORC);
    if (!check_intersects(orc_rect, var)) {
        direction.x *= ENEMY_SPEED;
        direction.y *= ENEMY_SPEED;
        change_direction_orc(var, direction);
        animate_orc(var);
        sfRectangleShape_move(ORC->hitbox, direction);
        sfSprite_move(ORC->sprite, direction);
    }
    DRAW_RECTANGLE(ORC->hitbox);
    DRAW_SPRITE(ORC->sprite);
}

void init_orc(var_t *var)
{
    ORC->clothes = CREATE_FROM_FILE("assets/pnj/orc.png");
    ORC->direction = DOWN;
    ORC->hitbox = sfRectangleShape_create();
    ORC->life = 60;
    ORC->rect = (sfIntRect){0, 0, 77, 77};
    ORC->sprite = sfSprite_create();
    ORC->walk = sfClock_create();
    sfRectangleShape_setFillColor(ORC->hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(ORC->hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(ORC->hitbox, 2.0f);
    sfRectangleShape_setPosition(ORC->hitbox, (sfVector2f){735.0f, 710.0f});
    sfRectangleShape_setSize(ORC->hitbox, (sfVector2f){25.0f, 45.0f});
    sfSprite_setPosition(ORC->sprite, (sfVector2f){720.0f, 700.0f});
    sfSprite_setScale(ORC->sprite, (sfVector2f){0.75f, 0.75f});
    sfSprite_setTexture(ORC->sprite, ORC->clothes, sfTrue);
    sfSprite_setTextureRect(ORC->sprite, ORC->rect);
}

void fight_orc(var_t *var)
{
    sfFloatRect player_bounds = GET_BOUNDS(PLAYER->hitbox);
    sfFloatRect player_spear_zone = GET_BOUNDS(PLAYER->spear_zone);
    sfFloatRect orc_bounds = GET_BOUNDS(ORC->hitbox);
    static sfClock *clock_player = NULL;
    static sfClock *clock_orc = NULL;

    if (!clock_player)
        clock_player = sfClock_create();
    if (!clock_orc)
        clock_orc = sfClock_create();
    if (sfFloatRect_intersects(&player_bounds, &orc_bounds, NULL)) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(clock_player)) >= 1.0f) {
            PLAYER->life -= 20;
            sfClock_restart(clock_player);
        }
    }
    if (sfFloatRect_intersects(&player_spear_zone, &orc_bounds, NULL)) {
        if (PLAYER->attack)
            knockback(var, clock_orc, ORC);
    }
}
