/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void event_menu_settings(var_t *var, sfEvent event, settings_t *menu)
{
    sfVector2u size = sfRenderWindow_getSize(var->window);
    float scalex = (float)size.x / 1920;
    float scaley = (float)size.y / 1080;
    mouse_event_t *mouse = malloc(sizeof(mouse_event_t));

    mouse->x = event.mouseButton.x;
    mouse->y = event.mouseButton.y;
    mouse->scale_x = scalex;
    mouse->scale_y = scaley;
    if (event.type == 0 || (event.type == 5 && sfKeyboard_isKeyPressed(36)))
        sfRenderWindow_close(var->window);
    if (event.type == 9 && event.mouseButton.button == sfMouseLeft) {
        if (event.mouseButton.x > 0 && event.mouseButton.x < 150 * scalex &&
        event.mouseButton.y > 0 * scaley && event.mouseButton.y < 150 * scaley)
            main_menu(var);
        handle_music(var, menu, mouse);
        handle_sound(var, menu, mouse);
        choose_resolution(var, scalex, scaley, event);
    }
}

void draw_settings(settings_t *menu, sfRenderWindow *window)
{
    if (menu->gauge_m == 0)
        sfRenderWindow_drawSprite(window, menu->gauge_m0, NULL);
    if (menu->gauge_m == 1)
        sfRenderWindow_drawSprite(window, menu->gauge_m1, NULL);
    if (menu->gauge_m == 2)
        sfRenderWindow_drawSprite(window, menu->gauge_m2, NULL);
    if (menu->gauge_m == 3)
        sfRenderWindow_drawSprite(window, menu->gauge_m3, NULL);
    if (menu->gauge_m == 4)
        sfRenderWindow_drawSprite(window, menu->gauge_m4, NULL);
    if (menu->gauge_s == 0)
        sfRenderWindow_drawSprite(window, menu->gauge_s0, NULL);
    if (menu->gauge_s == 1)
        sfRenderWindow_drawSprite(window, menu->gauge_s1, NULL);
    if (menu->gauge_s == 2)
        sfRenderWindow_drawSprite(window, menu->gauge_s2, NULL);
    if (menu->gauge_s == 3)
        sfRenderWindow_drawSprite(window, menu->gauge_s3, NULL);
    if (menu->gauge_s == 4)
        sfRenderWindow_drawSprite(window, menu->gauge_s4, NULL);
}

void display_menu_settings(sfRenderWindow *window, settings_t *menu)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->menu_sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->music_sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->size_sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->sound_sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->resolution_sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->mute_music, NULL);
    sfRenderWindow_drawSprite(window, menu->mute_sound, NULL);
    sfRenderWindow_drawSprite(window, menu->res1, NULL);
    sfRenderWindow_drawSprite(window, menu->res2, NULL);
    sfRenderWindow_drawSprite(window, menu->size1, NULL);
    sfRenderWindow_drawSprite(window, menu->size2, NULL);
    draw_settings(menu, window);
    sfRenderWindow_display(window);
}

void menu_settings(var_t *var)
{
    settings_t *menus = init_settings();
    sfEvent event;
    while (sfRenderWindow_isOpen(var->window)){
        while (sfRenderWindow_pollEvent(var->window, &event))
            event_menu_settings(var, event, menus);
        display_menu_settings(var->window, menus);
    }
}
