/*
** EPITECH PROJECT, 2023
** free2.c
** File description:
** free2.C
*/

#include "my_rpg.h"

void free_life_and_quest(var_t *var)
{
    sfSprite_destroy(var->life->sprite);
    sfTexture_destroy(var->life->hp);
    free(var->life);
    sfSprite_destroy(var->quest_text->box);
    sfText_destroy(var->quest_text->text);
    free(var->quest_text);
    sfText_destroy(var->tutorial->text);
    sfMusic_destroy(var->sound->music);
    sfSound_destroy(var->sound->sound);
    sfSoundBuffer_destroy(var->sound->buffer);
    free(var->tutorial);
    free(var->sound);
}
