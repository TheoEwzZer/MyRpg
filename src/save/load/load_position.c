/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

bool load_position_player(var_t *var, char *line)
{
    int pos_int = 0;
    sfVector2f position = sfSprite_getPosition(PLAYER->sprite);

    if (!my_strncmp(line, "player_position_x: ", 19)) {
        pos_int = my_getnbr(line + 19);
        position.x = (float)pos_int;
        sfSprite_setPosition(PLAYER->sprite, position);
        return true;
    }
    if (!my_strncmp(line, "player_position_y: ", 19)) {
        pos_int = my_getnbr(line + 19);
        position.y = (float)pos_int;
        sfSprite_setPosition(PLAYER->sprite, position);
        return true;
    }
    return false;
}

bool load_position_map(var_t *var, char *line)
{
    int pos_int = 0;
    sfVector2f position = sfView_getCenter(var->view);

    if (!my_strncmp(line, "map_position_x: ", 16)) {
        position = sfView_getCenter(var->view);
        pos_int = my_getnbr(line + 16);
        position.x = (float)pos_int;
        sfView_setCenter(var->view, position);
        return true;
    }
    if (!my_strncmp(line, "map_position_y: ", 16)) {
        position = sfView_getCenter(var->view);
        pos_int = my_getnbr(line + 16);
        position.y = (float)pos_int;
        sfView_setCenter(var->view, position);
        return true;
    }
    return false;
}
