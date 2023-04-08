/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 24};
    sfUint32 style = sfDefaultStyle;
    sfRenderWindow *window = sfRenderWindow_create(
        mode, "My Rpg", style, NULL
    );
    return window;
}

void check_event(var_t *var, sfEvent event)
{
    sfVector2f sprite_pos = sfSprite_getPosition(var->mc->sprite);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(var->window);
    if (event.type == sfEvtKeyPressed && !var->mc->attack)
        check_move(var, event);
    if (var->has_armor == true && event.type == sfEvtMouseButtonPressed) {
        var->mc->rect.left = 616 - 77;
        var->mc->rect.width = 77;
        var->mc->rect.height = 77;
        var->mc->attack = true;
    } if (sprite_pos.x >= 480 && sprite_pos.x <= 580 && sprite_pos.y >= 1070
    && sprite_pos.y <= 1170 && !var->has_armor) {
        sfSprite_setTexture(var->mc->sprite, var->armor, sfTrue);
        var->mc->rect.top = 0;
        var->mc->rect.width = 77;
        var->mc->rect.height = 77;
        var->mc->rect.left = 0;
        sfSprite_setTextureRect(var->mc->sprite, var->mc->rect);
        var->has_armor = true;
    }
}

int main(void)
{
    var_t *var = malloc(sizeof(var_t));
    sfEvent event;
    sfTexture *leaf_texture = CREATE_FROM_FILE("assets/particle/leaf.png");
    sfSprite *particle_sprite = sfSprite_create();
    srand((unsigned)time(NULL));
    init_rpg(var);
    sfMusic_setLoop(var->sound->theme, sfTrue);
    sfMusic_play(var->sound->theme);
    sfSprite_setTexture(particle_sprite, leaf_texture, sfTrue);
    sfSprite_setScale(particle_sprite, (sfVector2f){0.005f, 0.005f});
    generate_particle(var);
    create_dialog_box(var);
    load_game("save", var);
    while (sfRenderWindow_isOpen(var->window)) {
        if (sfRenderWindow_pollEvent(var->window, &event))
            check_event(var, event);
        game_engine(var, particle_sprite);
    }
    save_game("save", var);
}
