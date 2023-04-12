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
    const sfFloatRect player_rect = sfSprite_getGlobalBounds(var->mc->sprite);
    const sfFloatRect zone_rect = {560.0f, 574.0f, 259.0f, 302.0f};
    const sfVector2f orc_pos = sfSprite_getPosition(ORC->sprite);
    const sfVector2f player_pos = sfSprite_getPosition(var->mc->sprite);
    sfVector2f orc_dir = {0.0f, 0.0f}; sfVector2f direction = {0.0f, 0.0f};
    float distance = 0.0f;
    if (sfFloatRect_intersects(&player_rect, &zone_rect, NULL)) {
        orc_dir.x = player_pos.x - orc_pos.x;
        orc_dir.y = player_pos.y - orc_pos.y;
        distance = sqrtf(powf(orc_dir.x, 2.0f) + powf(orc_dir.y, 2.0f));
        direction.x = orc_dir.x / distance;
        direction.y = orc_dir.y / distance;
        direction.x *= ENEMY_SPEED; direction.y *= ENEMY_SPEED;
        change_direction_orc(var, direction);
        animate_orc(var);
    }
    sfRectangleShape_move(ORC->hitbox, direction);
    sfSprite_move(ORC->sprite, direction);
    DRAW_RECTANGLE(ORC->hitbox);
    DRAW_SPRITE(ORC->sprite);
}

void init_orc(var_t *var)
{
    ORC->clothes = CREATE_FROM_FILE("assets/pnj/orc.png");
    ORC->direction = DOWN;
    ORC->hitbox = sfRectangleShape_create();
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
