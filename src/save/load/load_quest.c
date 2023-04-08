/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

bool load_quest(var_t *var, char *line)
{
    bool has_armor_bool = false;
    char *has_armor_str = NULL;

    if (my_strstr(line, "has_armor: ")) {
        has_armor_str = line + 11;
        has_armor_bool = my_getnbr(has_armor_str);
        if (has_armor_bool) {
            sfSprite_setTexture(var->mc->sprite, var->armor, sfTrue);
            var->mc->rect.top = 0;
            var->mc->rect.width = 77;
            var->mc->rect.height = 77;
            var->mc->rect.left = 0;
            sfSprite_setTextureRect(var->mc->sprite, var->mc->rect);
            var->has_armor = true;
        }
        return true;
    }
    return false;
}
