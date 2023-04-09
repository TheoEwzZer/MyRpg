/*
** EPITECH PROJECT, 2023
** character_move
** File description:
** character_move
*/

#include "my_rpg.h"

void init_sound(var_t *var)
{
    SOUND->theme = sfMusic_createFromFile("assets/music/main_theme.ogg");
    sfMusic_setVolume(SOUND->theme, 50.0f);
    SOUND->spear = sfSound_create();
    SOUND->spear_buf = sfSoundBuffer_createFromFile("assets/music/spear.ogg");
    sfSound_setBuffer(SOUND->spear, SOUND->spear_buf);
    sfSound_setVolume(SOUND->spear, 50.0f);
}
