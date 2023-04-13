/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

bool load_position_player_x(var_t *var, char *line)
{
    int pos_int = 0;
    sfVector2f sprite_position = sfSprite_getPosition(PLAYER->sprite);
    sfVector2f hitbox_position = sfRectangleShape_getPosition(PLAYER->hitbox);
    sfVector2f spear_position = sfRectangleShape_getPosition(PLAYER->spear);

    if (!my_strncmp(line, "player_position_x: ", 19)) {
        pos_int = my_getnbr(line + 19);
        sprite_position.x = (float)pos_int;
        sfSprite_setPosition(PLAYER->sprite, sprite_position);
        hitbox_position.x = sprite_position.x + 15.0f;
        sfRectangleShape_setPosition(PLAYER->hitbox, hitbox_position);
        spear_position.x = sprite_position.x + 13.0f;
        sfRectangleShape_setPosition(PLAYER->spear, spear_position);
        return true;
    }
    return false;
}

bool load_position_player_y(var_t *var, char *line)
{
    int pos_int = 0;
    sfVector2f sprite_position = sfSprite_getPosition(PLAYER->sprite);
    sfVector2f hitbox_position = sfRectangleShape_getPosition(PLAYER->hitbox);
    sfVector2f spear_position = sfRectangleShape_getPosition(PLAYER->spear);

    if (!my_strncmp(line, "player_position_y: ", 19)) {
        pos_int = my_getnbr(line + 19);
        sprite_position.y = (float)pos_int;
        sfSprite_setPosition(PLAYER->sprite, sprite_position);
        hitbox_position.y = sprite_position.y + 40.0f;
        sfRectangleShape_setPosition(PLAYER->hitbox, hitbox_position);
        spear_position.y = sprite_position.y;
        sfRectangleShape_setPosition(PLAYER->spear, spear_position);
        return true;
    }
    return false;
}

bool load_position_player(var_t *var, char *line)
{
    if (load_position_player_x(var, line))
        return true;
    if (load_position_player_y(var, line))
        return true;
    return false;
}
