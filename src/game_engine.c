/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void game_engine(var_t *var)
{
    sfRenderWindow_clear(var->window, sfBlack);
    sfRenderWindow_setView(var->window, var->view);
    DRAW_SPRITE(var->background_sprite);
    if (var->mc->attack)
        attack_move(var);
    forge_move(var);
    girl_move(var);
    pnj_move(var);
    DRAW_SPRITE(var->mc->sprite);
    for (unsigned int i = 0; i < 9; i++)
        DRAW_SPRITE(var->foreground[i]);
    var->frame_count++;
    move_leaves(var);
    if (var->has_armor)
        check_ennemies(var);
    blacksmith_dialog(var);
    priscilla_dialog(var);
    bob_dialog(var);
    move_particle_pnj(var);
    sfRenderWindow_display(var->window);
}
