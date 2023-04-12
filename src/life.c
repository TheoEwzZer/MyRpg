/*
** EPITECH PROJECT, 2023
** life.c
** File description:
** life.c
*/

#include "my_rpg.h"

void check_life(var_t *var)
{
    if (var->mc->life == 100)
        var->life->rect.top = 23;
    if (var->mc->life == 80)
        var->life->rect.top = 118;
    if (var->mc->life == 60)
        var->life->rect.top = 216;
    if (var->mc->life == 40)
        var->life->rect.top = 316;
    if (var->mc->life == 20)
        var->life->rect.top = 410;
    if (var->mc->life == 0)
        var->life->rect.top = 495;
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
    var->life->rect = (sfIntRect){0, 23, 600, 108};
    sfSprite_setTexture(var->life->sprite, var->life->hp, sfTrue);
    sfSprite_setTextureRect(var->life->sprite, var->life->rect);
    sfSprite_setScale(var->life->sprite, (sfVector2f){0.5f, 0.5f});
    var->mc->life = 100;
}
