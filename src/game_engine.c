/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void game_engine(var_t *var, sfSprite *particle_sprite, sfEvent event)
{
    while (sfRenderWindow_isOpen(var->window)) {
        if (sfRenderWindow_pollEvent(var->window, &event))
            check_event(var, event);
        sfRenderWindow_clear(var->window, sfBlack);
        sfRenderWindow_setView(var->window, var->view);
        DRAW_SPRITE(var->background_sprite);
        forge_move(var);
        girl_move(var);
        pnj_move(var);
        DRAW_SPRITE(var->mc->sprite);
        for (unsigned int i = 0; i < 9; i++)
            DRAW_SPRITE(var->foreground[i]);
        var->frame_count++;
        move_particle(var, particle_sprite);
        if (var->has_armor)
            check_ennemies(var);
        sfRenderWindow_display(var->window);
    }
}
