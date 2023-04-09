/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

bool load_quest(var_t *var, char *line)
{
    if (!my_strncmp(line, "quest_progress: ", 16)) {
        var->quest_progress = my_getnbr(line + 16);
        if (var->quest_progress > 1) {
            sfSprite_setTexture(var->mc->sprite, var->armor, sfTrue);
            var->mc->rect.top = 0;
            var->mc->rect.width = 77;
            var->mc->rect.height = 77;
            var->mc->rect.left = 0;
            sfSprite_setTextureRect(var->mc->sprite, var->mc->rect);
        }
        if (var->quest_progress == 1)
            move_particle_position_pnj(var, (sfVector2f){555, 1110});
        return true;
    }
    return false;
}
