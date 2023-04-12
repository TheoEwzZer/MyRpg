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

void change_quest_to_enemies(var_t *var)
{
    sfSprite_setTexture(var->mc->sprite, var->armor, sfTrue);
    var->mc->rect = (sfIntRect){0, 0, 77, 77};
    sfSprite_setTextureRect(var->mc->sprite, var->mc->rect);
    var->quest_progress = ENEMIES;
    sfText_setString(var->quest_text->text, "Kill the enemies");
    sfText_setScale(var->quest_text->text, (sfVector2f){0.5f, 0.5f});
    var->quest_text->position = (sfVector2f){7.0f, 8.0f};
}

void check_event(var_t *var, sfEvent event)
{
    sfVector2f sprite_pos = sfSprite_getPosition(var->mc->sprite);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(var->window);
    if (event.type == sfEvtKeyPressed && !var->mc->attack)
        check_move(var, event);
    if (var->quest_progress > ARMOR && event.type == sfEvtMouseButtonPressed) {
        var->mc->rect.left = 616 - 77;
        var->mc->rect.width = 77;
        var->mc->rect.height = 77;
        var->mc->attack = true;
    } if (sprite_pos.x >= 480.0f && sprite_pos.x <= 580.0f
    && sprite_pos.y >= 1070.0f && sprite_pos.y <= 1170.0f
    && var->quest_progress == ARMOR) {
        change_quest_to_enemies(var);
    }
}

int main(int argc, char **argv)
{
    var_t *var = malloc(sizeof(var_t));
    sfEvent event;
    sfTexture *leaf_texture = CREATE_FROM_FILE("assets/particle/leaf.png");
    (void)(argv);
    srand((unsigned)time(NULL));
    init_rpg(var);
    sfMusic_setLoop(SOUND->theme, sfTrue);
    sfMusic_play(SOUND->theme);
    generate_leaves(var, leaf_texture);
    create_dialog_box(var);
    generate_particle_pnj(var, (sfVector2f){1125.0f, 1140.0f});
    init_ui(var);
    if (argc == 1)
        load_game("save.txt", var);
    while (sfRenderWindow_isOpen(var->window)) {
        if (sfRenderWindow_pollEvent(var->window, &event))
            check_event(var, event);
        game_engine(var);
    }
    save_game("save.txt", var);
}
