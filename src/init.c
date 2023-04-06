/*
** EPITECH PROJECT, 2023
** character_move
** File description:
** character_move
*/

#include "my_rpg.h"

void init_game(var_t *var)
{
    var->mc = malloc(sizeof(char_t));
    var->forge = malloc(sizeof(char_t));
    var->girl = malloc(sizeof(char_t));
    var->pnj = malloc(sizeof(char_t));
    var->sound = malloc(sizeof(sound_t));
    var->forge->rect.left = 0;
    var->girl->rect.left = 0;
    var->pnj->rect.left = 0;
    var->sound->theme = sfMusic_createFromFile("assets/music/main_theme.ogg");
    sfMusic_setVolume(var->sound->theme, 50);
    init_char(var);
}
