/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void init_win_lose(var_t *var)
{
    sfTexture *lose_message_tx = CREATE_FROM_FILE("assets/lose/lose_mess.png");
    sfTexture *menu_tx = CREATE_FROM_FILE("assets/lose/title_screen.png");
    sfTexture *win_message_tx = CREATE_FROM_FILE("assets/win/win_message.png");

    var->win = malloc(sizeof(win_t));
    var->lose = malloc(sizeof(lose_t));
    var->lose->lose_message = sfSprite_create();
    var->lose->menu_sprite = sfSprite_create();
    var->win->menu_sprite = sfSprite_create();
    var->win->win_message = sfSprite_create();
    sfSprite_setTexture(var->lose->lose_message, lose_message_tx, sfTrue);
    sfSprite_setTexture(var->lose->menu_sprite, menu_tx, sfTrue);
    sfSprite_setTexture(var->win->menu_sprite, menu_tx, sfTrue);
    sfSprite_setTexture(var->win->win_message, win_message_tx, sfTrue);
    var->is_lose = sfFalse;
    var->is_win = sfFalse;
}

void display_lose_menu(var_t *var)
{
    sfVector2f pos = sfSprite_getPosition(var->player->sprite);

    if (!var->is_lose)
        return;
    sfSprite_setColor(var->background_sprite, (sfColor){128, 128, 128, 100});
    sfSprite_setColor(var->boss->room, (sfColor){128, 128, 128, 100});
    for (int i = 0; i < 10 ; i++)
        sfSprite_setColor(var->foreground[i], (sfColor){128, 128, 128, 100});
    sfSprite_setScale(var->lose->lose_message, (sfVector2f){0.7f, 0.7f});
    sfSprite_setScale(var->lose->menu_sprite, (sfVector2f){0.7f, 0.7f});
    SET_POSITION(var->lose->lose_message, pos.x - 180, pos.y - 180);
    SET_POSITION(var->lose->menu_sprite, pos.x - 180, pos.y + 120);
    sfRenderWindow_drawSprite(var->window, var->lose->lose_message, NULL);
    sfRenderWindow_drawSprite(var->window, var->lose->menu_sprite, NULL);
}

void display_win_menu(var_t *var)
{
    sfVector2f pos = sfSprite_getPosition(var->player->sprite);

    if (!var->is_win)
        return;
    sfSprite_setColor(var->background_sprite, (sfColor){128, 128, 128, 100});
    sfSprite_setColor(var->boss->room, (sfColor){128, 128, 128, 100});
    for (int i = 0; i < 10 ; i++)
        sfSprite_setColor(var->foreground[i], (sfColor){128, 128, 128, 100});
    sfSprite_setScale(var->win->win_message, (sfVector2f){0.7f, 0.7f});
    sfSprite_setScale(var->win->menu_sprite, (sfVector2f){0.7f, 0.7f});
    SET_POSITION(var->win->menu_sprite, pos.x - 180, pos.y + 120);
    SET_POSITION(var->win->win_message, pos.x - 180, pos.y - 180);
    sfRenderWindow_drawSprite(var->window, var->win->menu_sprite, NULL);
    sfRenderWindow_drawSprite(var->window, var->win->win_message, NULL);
}

void check_win_lose(var_t *var)
{
    if (var->player->life <= 0)
        var->is_lose = sfTrue;
    if (var->boss->boss->life <= 0)
        var->is_win = sfTrue;
}
