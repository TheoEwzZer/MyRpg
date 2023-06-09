/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void map(var_t *var)
{
    static sfBool in_boss_room = sfFalse;
    sfVector2f position = {750.0f, 2700.0f};
    BOSSV->p_pos = sfSprite_getPosition(PLAYER->sprite);
    if (BOSSV->p_pos.x >= 470 && BOSSV->p_pos.x <= 1180
    && BOSSV->p_pos.y >= 2650 && BOSSV->p_pos.y <= 3070) {
        DRAW_SPRITE(BOSSV->room); boss_fight(var);
    } else
        DRAW_SPRITE(var->background_sprite);
    if (BOSSV->p_pos.x >= 490 && BOSSV->p_pos.x <= 550
    && BOSSV->p_pos.y >= 1750 && BOSSV->p_pos.y <= 1800 && !in_boss_room) {
        sfSprite_setPosition(PLAYER->sprite, position);
        position.y += 40.0f; position.x += 15.0f;
        sfRectangleShape_setPosition(PLAYER->hitbox, position);
        position.y -= 10.0f;
        sfRectangleShape_setPosition(PLAYER->spear, position);
        sfView_setCenter(var->view, position);
        sfView_zoom(var->view, 1.2f);
        sfMusic_stop(SOUND->music); sfMusic_play(SOUND->boss_music);
        in_boss_room = sfTrue;
    }
}

void check_quest(var_t *var)
{
    if (var->quest_progress == ENEMIES && !var->is_lose)
        check_enemies(var);
    if (var->quest_progress == BOSS)
        DRAW_SPRITE(var->foreground[9]);
}

void load_game_and_engine(var_t *var, sfEvent event)
{
    load_game("save.txt", var);
    game_engine(var, event);
}

void game_engine2(var_t *var)
{
    sfRenderWindow_clear(var->window, sfBlack);
    sfRenderWindow_setView(var->window, var->view);
    map(var);
    if (PLAYER->attack && !var->is_lose && !var->is_win)
        attack_move(var);
    blacksmith_move(var);
    girl_move(var); pnj_move(var);
    check_quest(var);
    DRAW_SPRITE(PLAYER->sprite);
    for (sfUint32 i = 0; i < 9; i++)
        DRAW_SPRITE(var->foreground[i]);
    var->frame_count++;
    if (!var->is_lose && !var->is_win) {
        move_leaves(var);
        move_particle_pnj(var);
        dialog(var);
        get_exp(var); check_win_lose(var);
        display_life(var);
    }
    display_ui(var); sfRenderWindow_display(var->window);
}

void game_engine(var_t *var, sfEvent event)
{
    while (sfRenderWindow_isOpen(var->window)) {
        if (sfRenderWindow_pollEvent(var->window, &event))
            check_event(var, event);
        game_engine2(var);
    }
}
