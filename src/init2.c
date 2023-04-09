/*
** EPITECH PROJECT, 2023
** character_move
** File description:
** character_move
*/

#include "my_rpg.h"

void init_sound(var_t *var)
{
    var->sound->theme = sfMusic_createFromFile("assets/music/main_theme.ogg");
    sfMusic_setVolume(var->sound->theme, 50);
    var->sound->spear = sfSound_create();
    var->sound->spear_buf = sfSoundBuffer_createFromFile("assets/music/spear.ogg");
    sfSound_setBuffer(var->sound->spear, var->sound->spear_buf);
    sfSound_setVolume(var->sound->spear, 50);
}

