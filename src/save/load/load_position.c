/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

bool load_position_player(var_t *var, char *line)
{
    char *pos_str = NULL;
    int pos_int = 0;
    sfVector2f pos = sfSprite_getPosition(var->mc->sprite);

    if (my_strstr(line, "player_position_x: ")) {
        pos_str = line + 19;
        pos_int = my_getnbr(pos_str);
        pos.x = (float)pos_int;
        sfSprite_setPosition(var->mc->sprite, pos);
        return true;
    }
    if (my_strstr(line, "player_position_y: ")) {
        pos_str = line + 19;
        pos_int = my_getnbr(pos_str);
        pos.y = (float)pos_int;
        sfSprite_setPosition(var->mc->sprite, pos);
        return true;
    }
    return false;
}

bool load_position_map(var_t *var, char *line)
{
    char *pos_str = NULL;
    int pos_int = 0;
    sfVector2f pos = sfView_getCenter(var->view);
    if (my_strstr(line, "map_position_x: ")) {
        pos_str = line + 16;
        pos = sfView_getCenter(var->view);
        pos_int = my_getnbr(pos_str);
        pos.x = (float)pos_int;
        sfView_setCenter(var->view, pos);
        return true;
    }
    if (my_strstr(line, "map_position_y: ")) {
        pos_str = line + 16;
        pos = sfView_getCenter(var->view);
        pos_int = my_getnbr(pos_str);
        pos.y = (float)pos_int;
        sfView_setCenter(var->view, pos);
        return true;
    }
    return false;
}
