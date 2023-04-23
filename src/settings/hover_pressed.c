/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void settings_hover2(settings_t *menu, sfVector2f mouse)
{
    sfFloatRect cmds = sfSprite_getGlobalBounds(menu->commands);
    if (sfFloatRect_contains(&cmds, mouse.x, mouse.y))
        sfSprite_setColor(menu->commands, sfYellow);
    else
        sfSprite_setColor(menu->commands, sfWhite);
}

void settings_pressed2(settings_t *menu, sfVector2f mouse)
{
    sfFloatRect cmds = sfSprite_getGlobalBounds(menu->commands);
    if (sfFloatRect_contains(&cmds, mouse.x, mouse.y))
        sfSprite_setColor(menu->commands, sfRed);
    else
        sfSprite_setColor(menu->commands, sfWhite);
}

void handle_commands(var_t *var, settings_t *menu, sfVector2f mouse)
{
    sfFloatRect cmds = sfSprite_getGlobalBounds(menu->commands);
    if (sfFloatRect_contains(&cmds, mouse.x, mouse.y)) {
        menu_commands(var);
    }
}
