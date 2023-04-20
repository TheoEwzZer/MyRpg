/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void handle_music(var_t *var, settings_t *menu, mouse_event_t *mouse)
{
    float volume[5] = {0.0f, 25.0f, 50.0f, 75.0f, 100.0f};

    for (int i = 0; i < 5; i++) {
        if (mouse->x > (float)(50 + 125 * i) * mouse->scale_x
        && mouse->x < (float)(100 + 125 * i) * mouse->scale_x
        && mouse->y > 400.0f * mouse->scale_y
        && mouse->y < 440.0f * mouse->scale_y) {
            menu->gauge_m = i;
            sfMusic_setVolume(var->sound->music, volume[i]);
            break;
        }
    }
}

void handle_sound(var_t *var, settings_t *menu, mouse_event_t *mouse)
{
    float volume[5] = {0.0f, 25.0f, 50.0f, 75.0f, 100.0f};

    for (int i = 0; i < 5; i++) {
        if (mouse->x > (float)(500 + 125 * i) * mouse->scale_x
        && mouse->x < (float)(550 + 125 * i) * mouse->scale_x
        && mouse->y > 400.0f * mouse->scale_y
        && mouse->y < 440.0f * mouse->scale_y) {
            menu->gauge_s = i;
            sfSound_setVolume(SOUND->sound, volume[i]);
            break;
        }
    }
}

void handle_res(var_t *var, sfUint32 width, sfUint32 height, sfUint32 style)
{
    sfVideoMode mode = {width, height, 32};

    sfRenderWindow_close(var->window);
    var->default_view = sfView_create();
    sfView_setSize(var->default_view, (sfVector2f){1920, 1080});
    sfView_setCenter(var->default_view, (sfVector2f){1920 / 2, 1080 / 2});
    var->window = sfRenderWindow_create(mode, "My_RPG", style, NULL);
    sfRenderWindow_setView(var->window, var->default_view);
}

void choose_resolution(var_t *var, float scalex, float scaley, sfEvent event)
{
    if (event.mouseButton.x > 730 * scalex && event.mouseButton.x < 980 * scalex
    && event.mouseButton.y > 750 * scaley && event.mouseButton.y < 843 * scaley)
        handle_res(var, 800, 600, sfFullscreen);
    if (event.mouseButton.x > 730 * scalex && event.mouseButton.x < 980 * scalex
    && event.mouseButton.y > 880 * scaley && event.mouseButton.y < 973 * scaley)
        handle_res(var, 1920, 1080, sfFullscreen);
    if (event.mouseButton.x > 180 * scalex && event.mouseButton.x < 430 * scalex
    && event.mouseButton.y > 750 * scaley && event.mouseButton.y < 843 * scaley)
        handle_res(var, 800, 600, sfDefaultStyle);
    if (event.mouseButton.x > 180 * scalex && event.mouseButton.x < 430 * scalex
    && event.mouseButton.y > 880 * scaley && event.mouseButton.y < 973 * scaley)
        handle_res(var, 1920, 1080, sfDefaultStyle);
}

void handle_back(sfEvent event, var_t *var, int is_in_game)
{
    sfVector2u size = sfRenderWindow_getSize(var->window);
    float scalex = (float)size.x / 1920;
    float scaley = (float)size.y / 1080;
    mouse_event_t *mouse = malloc(sizeof(mouse_event_t));

    mouse->x = event.mouseButton.x;
    mouse->y = event.mouseButton.y;
    mouse->scale_x = scalex;
    mouse->scale_y = scaley;
    if (event.mouseButton.x > 0 && event.mouseButton.x < 150 * scalex
    && event.mouseButton.y > 0 * scaley && event.mouseButton.y < 150 * scaley) {
        if (!is_in_game)
            main_menu(var);
        else
            game_engine(var, event);
    }
}
