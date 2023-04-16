/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void handle_music(var_t *var, settings_t *menuv, mouse_event_t *mouse)
{
    float volume[5] = {0.0f, 25.0f, 50.0f, 75.0f, 100.0f};

    for (int i = 0; i < 5; i++) {
        if (mouse->x > (float)(50 + 125 * i) * mouse->scalx
        && mouse->x < (float)(100 + 125 * i) * mouse->scalx
        && mouse->y > 400.0f * mouse->scaly
        && mouse->y < 440.0f * mouse->scaly) {
            menuv->jaugem = i;
            sfMusic_setVolume(var->sound->theme, volume[i]);
            break;
        }
    }
}

void handle_sound(var_t *var, settings_t *menuv, mouse_event_t *mouse)
{
    float volume[5] = {0.0f, 25.0f, 50.0f, 75.0f, 100.0f};

    for (int i = 0; i < 5; i++) {
        if (mouse->x > (float)(500 + 125 * i) * mouse->scalx
        && mouse->x < (float)(550 + 125 * i) * mouse->scalx
        && mouse->y > 400.0f * mouse->scaly
        && mouse->y < 440.0f * mouse->scaly) {
            menuv->jauges = i;
            sfSound_setVolume(var->sound->spear, volume[i]);
            break;
        }
    }
}

void handle_res(var_t *var, sfUint32 width, sfUint32 height, sfUint32 style)
{
    sfVideoMode mode = {width, height, 32};

    sfRenderWindow_close(var->window);
    var->defaultview = sfView_create();
    sfView_setSize(var->defaultview, (sfVector2f){1920, 1080});
    sfView_setCenter(var->defaultview, (sfVector2f){1920 / 2, 1080 / 2});
    var->window = sfRenderWindow_create(mode, "My_RPG", style, NULL);
    sfRenderWindow_setView(var->window, var->defaultview);
}

void choose_resolution(var_t *var, float scalx, float scaly, sfEvent event)
{
    if (event.mouseButton.x > 730 * scalx && event.mouseButton.x < 980 * scalx
    && event.mouseButton.y > 750 * scaly && event.mouseButton.y < 843 * scaly)
        handle_res(var, 800, 600, sfFullscreen);
    if (event.mouseButton.x > 730 * scalx && event.mouseButton.x < 980 * scalx
    && event.mouseButton.y > 880 * scaly && event.mouseButton.y < 973 * scaly)
        handle_res(var, 1920, 1080, sfFullscreen);
    if (event.mouseButton.x > 180 * scalx && event.mouseButton.x < 430 * scalx
    && event.mouseButton.y > 750 * scaly && event.mouseButton.y < 843 * scaly)
        handle_res(var, 800, 600, sfDefaultStyle);
    if (event.mouseButton.x > 180 * scalx && event.mouseButton.x < 430 * scalx
    && event.mouseButton.y > 880 * scaly && event.mouseButton.y < 973 * scaly)
        handle_res(var, 1920, 1080, sfDefaultStyle);
}
