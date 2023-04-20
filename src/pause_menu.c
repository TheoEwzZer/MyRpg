/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void init_pause_menu(var_t *var)
{
    sfTexture *bg = CREATE_FROM_FILE("assets/ig_menu/pause_menu.png");
    sfTexture *load = CREATE_FROM_FILE("assets/ig_menu/load_button.png");
    sfTexture *player = CREATE_FROM_FILE("assets/ig_menu/player_button.png");
    sfTexture *save = CREATE_FROM_FILE("assets/ig_menu/save_button.png");
    sfTexture *sett = CREATE_FROM_FILE("assets/ig_menu/settings_button.png");
    var->is_paused = sfFalse;
    var->pause = malloc(sizeof(pause_t));
    var->pause->pause_bg = sfSprite_create();
    sfSprite_setTexture(var->pause->pause_bg, bg, sfTrue);
    var->pause->load = sfSprite_create();
    sfSprite_setTexture(var->pause->load, load, sfTrue);
    var->pause->save = sfSprite_create();
    sfSprite_setTexture(var->pause->save, save, sfTrue);
    var->pause->player_opt = sfSprite_create();
    sfSprite_setTexture(var->pause->player_opt, player, sfTrue);
    var->pause->settings = sfSprite_create();
    sfSprite_setTexture(var->pause->settings, sett, sfTrue);
    var->default_view = sfView_create();
    sfView_setSize(var->default_view, (sfVector2f){1920, 1080});
    sfView_setCenter(var->default_view, (sfVector2f){1920 / 2, 1080 / 2});
}

void display_pause_menu(var_t *var)
{
    sfVector2f pos = sfSprite_getPosition(var->player->sprite);

    if (!var->is_paused)
        return;
    SET_POSITION(var->pause->pause_bg, pos.x - 190, pos.y - 190);
    sfSprite_setScale(var->pause->pause_bg, (sfVector2f){0.60f, 0.60f});
    SET_POSITION(var->pause->player_opt, pos.x - 105, pos.y - 130);
    sfSprite_setScale(var->pause->player_opt, (sfVector2f){0.60f, 0.60f});
    SET_POSITION(var->pause->save, pos.x - 105, pos.y - 65);
    sfSprite_setScale(var->pause->save, (sfVector2f){0.60f, 0.60f});
    sfSprite_setPosition(var->pause->load, (sfVector2f){pos.x - 105, pos.y});
    sfSprite_setScale(var->pause->load, (sfVector2f){0.60f, 0.60f});
    SET_POSITION(var->pause->settings, pos.x - 105, pos.y + 65);
    sfSprite_setScale(var->pause->settings, (sfVector2f){0.60f, 0.60f});
    sfRenderWindow_drawSprite(var->window, var->pause->pause_bg, NULL);
    sfRenderWindow_drawSprite(var->window, var->pause->load, NULL);
    sfRenderWindow_drawSprite(var->window, var->pause->save, NULL);
    sfRenderWindow_drawSprite(var->window, var->pause->player_opt, NULL);
    sfRenderWindow_drawSprite(var->window, var->pause->settings, NULL);
}

void check_buttons(var_t *var, sfVector2f mouse)
{
    sfFloatRect load_rect = {700.0f, 561.0f, 880.0f, 110.0f};
    sfFloatRect player_rect = {700.0f, 240.0f, 880.0f, 110.0f};
    sfFloatRect save_rect = {700.0f, 400.0f, 880.0f, 110.0f};
    sfFloatRect settings_rect = {700.0f, 722.0f, 880.0f, 110.0f};

    if (sfFloatRect_contains(&load_rect, mouse.x, mouse.y))
        load_game("save.txt", var);
    if (sfFloatRect_contains(&save_rect, mouse.x, mouse.y))
        save_game("save.txt", var);
    if (sfFloatRect_contains(&player_rect, mouse.x, mouse.y)) {
        INVENTORY->is_open = !INVENTORY->is_open;
        var->is_paused = sfFalse;
    }
    if (sfFloatRect_contains(&settings_rect, mouse.x, mouse.y)) {
        sfRenderWindow_setView(var->window, var->default_view);
        menu_settings(var, 1);
    }
}

sfVector2f find_mouse_pos(var_t *var)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(var->window);
    sfVector2f view_pos = sfView_getCenter(var->view);
    sfVector2f view_size = sfView_getSize(var->view);
    float scalex = view_size.x / 1920;
    float scaley = view_size.y / 1080;
    sfVector2f mouse2 = (sfVector2f){(float)mouse.x, (float)mouse.y};

    mouse.x *= (int)scalex;
    mouse.y *= (int)scaley;
    mouse.x += (int)(view_pos.x - (view_size.x / 2));
    mouse.y += (int)(view_pos.y - (view_size.y / 2));
    return mouse2;
}

void check_pause(var_t *var, sfEvent event)
{
    sfVector2f mouse = find_mouse_pos(var);

    pause_hover(var, mouse);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        var->is_paused = !var->is_paused;
    if (!var->is_paused || !event.mouseButton.button == sfMouseLeft)
        return;
    if (event.type == sfEvtMouseButtonPressed)
        pause_pressed(var, mouse);
    else if (event.type == sfEvtMouseButtonReleased)
        check_buttons(var, mouse);
}
