/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

bool load_position_player(var_t *var, char *line)
{
    if (my_strstr(line, "player_position_x: ")) {
        char *pos_x_str = line + 19;
        sfVector2f pos = sfSprite_getPosition(var->mc->sprite);
        int pos_x_int = my_getnbr(pos_x_str);
        pos.x = (float)pos_x_int;
        sfSprite_setPosition(var->mc->sprite, pos);
        return true;
    }
    if (my_strstr(line, "player_position_y: ")) {
        char *pos_y_str = line + 19;
        sfVector2f pos = sfSprite_getPosition(var->mc->sprite);
        int pos_y_int = my_getnbr(pos_y_str);
        pos.y = (float)pos_y_int;
        sfSprite_setPosition(var->mc->sprite, pos);
        return true;
    }
    return false;
}

bool load_position_map(var_t *var, char *line)
{
    if (my_strstr(line, "map_position_x: ")) {
        char *pos_x_str = line + 16;
        sfVector2f pos = sfView_getCenter(var->view);
        int pos_x_int = my_getnbr(pos_x_str);
        pos.x = (float)pos_x_int;
        sfView_setCenter(var->view, pos);
        return true;
    }
    if (my_strstr(line, "map_position_y: ")) {
        char *pos_y_str = line + 16;
        sfVector2f pos = sfView_getCenter(var->view);
        int pos_y_int = my_getnbr(pos_y_str);
        pos.y = (float)pos_y_int;
        sfView_setCenter(var->view, pos);
        return true;
    }
    return false;
}
