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
    sfRenderWindow_setFramerateLimit(window, 144);
    return window;
}

void change_quest_to_enemies(var_t *var)
{
    sfSprite_setTexture(PLAYER->sprite, var->armor, sfTrue);
    PLAYER->rect = (sfIntRect){0, 0, 77, 77};
    sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
    var->quest_progress = ENEMIES;
    sfText_setString(var->quest_text->text, "Kill the enemies");
    sfText_setScale(var->quest_text->text, (sfVector2f){0.5f, 0.5f});
    var->quest_text->position = (sfVector2f){7.0f, 8.0f};
}

void check_inventory(var_t *var, sfEvent evt)
{
    sfVector2i pos = sfMouse_getPosition((const sfWindow*)var->window);
    if (evt.type == sfEvtKeyPressed && evt.key.code == var->key_inv) {
        INVENTORY->is_open = !INVENTORY->is_open;
        if (var->tutorial->is_active && var->quest_progress >= ENEMIES)
            var->tutorial->is_active = sfFalse;
    }
    if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyEscape)
        INVENTORY->is_open = sfFalse;
    if (INVENTORY->is_open && INVENTORY->drink
    && evt.type == sfEvtMouseButtonPressed
    && pos.x >= 715 && pos.x <= 775
    && pos.y >= 685 && pos.y <= 750
    && evt.type == sfEvtMouseButtonPressed
    && PLAYER->life < 100) {
        if (PLAYER->life <= 0)
            PLAYER->life = 20;
        else
            PLAYER->life += 20;
        INVENTORY->drink = sfFalse;
    }
}

void check_event(var_t *var, sfEvent evt)
{
    sfVector2f sprite_pos = sfSprite_getPosition(PLAYER->sprite);
    if (evt.type == sfEvtClosed)
        sfRenderWindow_close(var->window);
    if (evt.type == sfEvtKeyPressed && !PLAYER->attack)
        check_move(var, evt);
    check_inventory(var, evt);
    check_pause(var, evt);
    buttons_win_lose(var, evt);
    if (var->quest_progress > ARMOR && (evt.type == sfEvtMouseButtonPressed
    || (evt.type == sfEvtKeyPressed && evt.key.code == var->key_attack))) {
        PLAYER->attack = sfTrue;
        PLAYER->rect.height = 77;
        PLAYER->rect.left = 616 - 77;
        PLAYER->rect.width = 77;
    }
    if (sprite_pos.x >= 480.0f && sprite_pos.x <= 580.0f
    && sprite_pos.y >= 1070.0f && sprite_pos.y <= 1170.0f
    && var->quest_progress == ARMOR) {
        change_quest_to_enemies(var);
    }
}

int main(void)
{
    var_t *var = malloc(sizeof(var_t));
    sfTexture *leaf_texture = CREATE_FROM_FILE("assets/particle/leaf.png");
    srand((unsigned)time(NULL));
    create_config("config.txt");
    load_config("config.txt", var);
    init_rpg(var);
    init_pause_menu(var);
    init_win_lose(var);
    sfMusic_setLoop(SOUND->music, sfTrue);
    sfMusic_play(SOUND->music);
    generate_leaves(var, leaf_texture);
    create_dialog_box(var);
    generate_particle_pnj(var, (sfVector2f){1125.0f, 1140.0f});
    init_ui(var);
    splash_screen(var);
    free_all(var);
}
