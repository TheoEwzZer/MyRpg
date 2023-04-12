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
    blacksmith_move(var);
    girl_move(var);
    pnj_move(var);
    if (var->quest_progress == ENEMIES)
        check_enemies(var);
    DRAW_SPRITE(var->mc->sprite);
    DRAW_RECTANGLE(var->hitbox);
    for (unsigned int i = 0; i < 9; i++)
        DRAW_SPRITE(var->foreground[i]);
    var->frame_count++;
    move_leaves(var);
    move_particle_pnj(var);
    dialog(var);
    display_ui(var);
    display_life(var);
    sfRenderWindow_display(var->window);
}
