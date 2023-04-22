/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void lose_buttons(var_t *var)
{
    sfVector2f mouse = find_mouse_pos(var);
    sfFloatRect menu_rect = {500.0f, 890.0f, 910.0f, 90.0f};
    if (sfFloatRect_contains(&menu_rect, mouse.x, mouse.y)){
        sfSprite_setColor(var->background_sprite, sfWhite);
        sfSprite_setColor(var->boss->room, sfWhite);
        for (int i = 0; i < 10 ; i++)
            sfSprite_setColor(var->foreground[i], sfWhite);
        var->is_lose = sfFalse;
        sfRenderWindow_setView(var->window, var->default_view);
        main_menu(var);
    }
}

void win_buttons(var_t *var)
{
    sfVector2f mouse = find_mouse_pos(var);

    sfFloatRect menu_rect = {500.0f, 890.0f, 910.0f, 90.0f};
    if (sfFloatRect_contains(&menu_rect, mouse.x, mouse.x)){
        sfSprite_setColor(var->background_sprite, sfWhite);
        sfSprite_setColor(var->boss->room, sfWhite);
        for (int i = 0; i < 10 ; i++)
            sfSprite_setColor(var->foreground[i], sfWhite);
        var->is_win = sfFalse;
        sfRenderWindow_setView(var->window, var->default_view);
        main_menu(var);
        main_menu(var);
    }
}

void buttons_win_lose(var_t *var, sfEvent event)
{
    if (!var->is_lose && !var->is_win)
        return;
    if (var->is_lose && event.type == sfEvtMouseButtonReleased){
        lose_buttons(var);
    }
    if (var->is_win && event.type == sfEvtMouseButtonReleased){
        win_buttons(var);
    }
}
