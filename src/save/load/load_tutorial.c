/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

sfBool load_tutorial(var_t *var, char *line)
{
    sfVector2f position = sfText_getPosition(var->tutorial->text);

    if (!my_strncmp(line, "tutorial: ", 10)) {
        var->tutorial->is_active = my_getnbr(line + 10);
        if (var->quest_progress >= ENEMIES)
            sfText_setString(var->tutorial->text, CONFIG->tutorial_dialog);
        return sfTrue;
    }
    if (!my_strncmp(line, "tutorial_position_x: ", 21)) {
        sfText_setPosition(var->tutorial->text, position);
        return sfTrue;
    }
    if (!my_strncmp(line, "tutorial_position_y: ", 21)) {
        sfText_setPosition(var->tutorial->text, position);
        return sfTrue;
    }
    return sfFalse;
}
