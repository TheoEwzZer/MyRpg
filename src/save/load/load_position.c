/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

sfBool load_position_map(var_t *var, char *line)
{
    int pos_int = 0;
    sfVector2f position = sfView_getCenter(var->view);

    if (!my_strncmp(line, "map_position_x: ", 16)) {
        position = sfView_getCenter(var->view);
        pos_int = my_getnbr(line + 16);
        position.x = (float)pos_int;
        sfView_setCenter(var->view, position);
        return sfTrue;
    }
    if (!my_strncmp(line, "map_position_y: ", 16)) {
        position = sfView_getCenter(var->view);
        pos_int = my_getnbr(line + 16);
        position.y = (float)pos_int;
        sfView_setCenter(var->view, position);
        return sfTrue;
    }
    return sfFalse;
}

sfBool load_position_skeleton(var_t *var, char *line)
{
    int pos_int = 0;
    sfVector2f position = sfSprite_getPosition(SKELETON->sprite);
    sfVector2f hitbox_position = sfRectangleShape_getPosition(SKELETON->hitbox);
    if (!my_strncmp(line, "skeleton_position_x: ", 21)) {
        pos_int = my_getnbr(line + 21);
        position.x = (float)pos_int;
        sfSprite_setPosition(SKELETON->sprite, position);
        hitbox_position.x = position.x + 15.0f;
        sfRectangleShape_setPosition(SKELETON->hitbox, hitbox_position);
        return sfTrue;
    }
    if (!my_strncmp(line, "skeleton_position_y: ", 21)) {
        pos_int = my_getnbr(line + 21);
        position.y = (float)pos_int;
        sfSprite_setPosition(SKELETON->sprite, position);
        hitbox_position.y = position.y + 10.0f;
        sfRectangleShape_setPosition(SKELETON->hitbox, hitbox_position);
        return sfTrue;
    }
    return sfFalse;
}

sfBool load_position_orc(var_t *var, char *line)
{
    int pos_int = 0;
    sfVector2f position = sfSprite_getPosition(ORC->sprite);
    sfVector2f hitbox_position = sfRectangleShape_getPosition(ORC->hitbox);
    if (!my_strncmp(line, "orc_position_x: ", 16)) {
        pos_int = my_getnbr(line + 16);
        position.x = (float)pos_int;
        sfSprite_setPosition(ORC->sprite, position);
        hitbox_position.x = position.x + 15.0f;
        sfRectangleShape_setPosition(ORC->hitbox, hitbox_position);
        return sfTrue;
    }
    if (!my_strncmp(line, "orc_position_y: ", 16)) {
        pos_int = my_getnbr(line + 16);
        position.y = (float)pos_int;
        sfSprite_setPosition(ORC->sprite, position);
        hitbox_position.y = position.y + 10.0f;
        sfRectangleShape_setPosition(ORC->hitbox, hitbox_position);
        return sfTrue;
    }
    return sfFalse;
}
