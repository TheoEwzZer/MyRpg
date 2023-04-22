/*
** EPITECH PROJECT, 2023
** life.c
** File description:
** life.c
*/

#include "my_rpg.h"

void check_life(var_t *var)
{
    if (PLAYER->life >= 100)
        var->life->rect.top = 23;
    if (PLAYER->life == 80)
        var->life->rect.top = 95;
    if (PLAYER->life == 60)
        var->life->rect.top = 180;
    if (PLAYER->life == 40)
        var->life->rect.top = 260;
    if (PLAYER->life == 20)
        var->life->rect.top = 340;
    if (PLAYER->life <= 0)
        var->life->rect.top = 410;
    sfSprite_setTextureRect(var->life->sprite, var->life->rect);
}

void display_life(var_t *var)
{
    sfVector2f offset = sfView_getCenter(var->view);
    offset.x += sfView_getSize(var->view).x / 2.0f
    - sfSprite_getGlobalBounds(var->life->sprite).width;
    offset.y -= sfView_getSize(var->view).y / 2.0f;
    sfSprite_setPosition(var->life->sprite, offset);
    check_life(var);
    DRAW_SPRITE(var->life->sprite);
}

void init_life(var_t *var)
{
    var->life->hp = CREATE_FROM_FILE("assets/player/vie.png");
    var->life->sprite = sfSprite_create();
    var->life->rect = (sfIntRect){0, 23, 600, 70};
    sfSprite_setTexture(var->life->sprite, var->life->hp, sfTrue);
    sfSprite_setTextureRect(var->life->sprite, var->life->rect);
    sfSprite_setScale(var->life->sprite, (sfVector2f){0.5f, 0.5f});
    PLAYER->life = 100;
}

void get_exp(var_t *var)
{
    if (var->quest_progress == ARMOR)
        PLAYER->exp = 1;
    if (var->quest_progress == ENEMIES)
        PLAYER->exp = 2;
    if (var->quest_progress == BOB) {
        PLAYER->exp = 5;
        sfText_setString(INVENTORY->atk, "30");
    }
    if (var->quest_progress == BOSS)
        PLAYER->exp = 7;
}
