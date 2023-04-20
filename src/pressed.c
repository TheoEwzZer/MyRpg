/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"


void menu_pressed(menu_t *menu, sfVector2f mouse)
{
    sfFloatRect exit_rect = sfSprite_getGlobalBounds(menu->exit_sprite);
    sfFloatRect game_rect = sfSprite_getGlobalBounds(menu->play_sprite);
    sfFloatRect load_rect = sfSprite_getGlobalBounds(menu->resume_sprite);
    sfFloatRect settings_rect = sfSprite_getGlobalBounds(menu->setting_sprite);
    if (sfFloatRect_contains(&game_rect, mouse.x, mouse.y))
        sfSprite_setColor(menu->play_sprite, sfRed);
    else
        sfSprite_setColor(menu->play_sprite, sfWhite);
    if (sfFloatRect_contains(&load_rect, mouse.x, mouse.y))
        sfSprite_setColor(menu->resume_sprite, sfRed);
    else
        sfSprite_setColor(menu->resume_sprite, sfWhite);
    if (sfFloatRect_contains(&settings_rect, mouse.x, mouse.y))
        sfSprite_setColor(menu->setting_sprite, sfRed);
    else
        sfSprite_setColor(menu->setting_sprite, sfWhite);
    if (sfFloatRect_contains(&exit_rect, mouse.x, mouse.y))
        sfSprite_setColor(menu->exit_sprite, sfRed);
    else
        sfSprite_setColor(menu->exit_sprite, sfWhite);
}

void settings_pressed(settings_t *menu, sfVector2f mouse)
{
    sfFloatRect res1rect = sfSprite_getGlobalBounds(menu->res1);
    sfFloatRect res2rect = sfSprite_getGlobalBounds(menu->res2);
    sfFloatRect size1rect = sfSprite_getGlobalBounds(menu->size1);
    sfFloatRect size2rect = sfSprite_getGlobalBounds(menu->size2);
    if (sfFloatRect_contains(&res1rect, mouse.x, mouse.y))
        sfSprite_setColor(menu->res1, sfRed);
    else
        sfSprite_setColor(menu->res1, sfWhite);
    if (sfFloatRect_contains(&res2rect, mouse.x, mouse.y))
        sfSprite_setColor(menu->res2, sfRed);
    else
        sfSprite_setColor(menu->res2, sfWhite);
    if (sfFloatRect_contains(&size1rect, mouse.x, mouse.y))
        sfSprite_setColor(menu->size1, sfRed);
    else
        sfSprite_setColor(menu->size1, sfWhite);
    if (sfFloatRect_contains(&size2rect, mouse.x, mouse.y))
        sfSprite_setColor(menu->size2, sfRed);
    else
        sfSprite_setColor(menu->size2, sfWhite);
}

void pause_pressed(var_t *var, sfVector2f mouse)
{
    sfFloatRect load_rect = {700.0f, 561.0f, 880.0f, 110.0f};
    sfFloatRect player_rect = {700.0f, 240.0f, 880.0f, 110.0f};
    sfFloatRect save_rect = {700.0f, 400.0f, 880.0f, 110.0f};
    sfFloatRect settings_rect = {700.0f, 722.0f, 880.0f, 110.0f};
    if (sfFloatRect_contains(&load_rect, mouse.x, mouse.y))
        sfSprite_setColor(var->pause->load, sfRed);
    else
        sfSprite_setColor(var->pause->load, sfWhite);
    if (sfFloatRect_contains(&settings_rect, mouse.x, mouse.y))
        sfSprite_setColor(var->pause->settings, sfRed);
    else
        sfSprite_setColor(var->pause->settings, sfWhite);
    if (sfFloatRect_contains(&save_rect, mouse.x, mouse.y))
        sfSprite_setColor(var->pause->save, sfRed);
    else
        sfSprite_setColor(var->pause->save, sfWhite);
    if (sfFloatRect_contains(&player_rect, mouse.x, mouse.y))
        sfSprite_setColor(var->pause->player_opt, sfRed);
    else
        sfSprite_setColor(var->pause->player_opt, sfWhite);
}

void pause_hover(var_t *var, sfVector2f mouse)
{
    sfFloatRect load_rect = {700.0f, 561.0f, 880.0f, 110.0f};
    sfFloatRect player_rect = {700.0f, 240.0f, 880.0f, 110.0f};
    sfFloatRect save_rect = {700.0f, 400.0f, 880.0f, 110.0f};
    sfFloatRect settings_rect = {700.0f, 722.0f, 880.0f, 110.0f};
    if (sfFloatRect_contains(&load_rect, mouse.x, mouse.y))
        sfSprite_setColor(var->pause->load, sfGreen);
    else
        sfSprite_setColor(var->pause->load, sfWhite);
    if (sfFloatRect_contains(&settings_rect, mouse.x, mouse.y))
        sfSprite_setColor(var->pause->settings, sfGreen);
    else
        sfSprite_setColor(var->pause->settings, sfWhite);
    if (sfFloatRect_contains(&save_rect, mouse.x, mouse.y))
        sfSprite_setColor(var->pause->save, sfGreen);
    else
        sfSprite_setColor(var->pause->save, sfWhite);
    if (sfFloatRect_contains(&player_rect, mouse.x, mouse.y))
        sfSprite_setColor(var->pause->player_opt, sfGreen);
    else
        sfSprite_setColor(var->pause->player_opt, sfWhite);
}
