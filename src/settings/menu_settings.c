/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void settings_hover(settings_t *menu, sfVector2f mouse)
{
    sfFloatRect res1rect = sfSprite_getGlobalBounds(menu->res1);
    sfFloatRect res2rect = sfSprite_getGlobalBounds(menu->res2);
    sfFloatRect size1rect = sfSprite_getGlobalBounds(menu->size1);
    sfFloatRect size2rect = sfSprite_getGlobalBounds(menu->size2);
    if (sfFloatRect_contains(&res1rect, mouse.x, mouse.y))
        sfSprite_setColor(menu->res1, sfYellow);
    else
        sfSprite_setColor(menu->res1, sfWhite);
    if (sfFloatRect_contains(&res2rect, mouse.x, mouse.y))
        sfSprite_setColor(menu->res2, sfYellow);
    else
        sfSprite_setColor(menu->res2, sfWhite);
    if (sfFloatRect_contains(&size1rect, mouse.x, mouse.y))
        sfSprite_setColor(menu->size1, sfYellow);
    else
        sfSprite_setColor(menu->size1, sfWhite);
    if (sfFloatRect_contains(&size2rect, mouse.x, mouse.y))
        sfSprite_setColor(menu->size2, sfYellow);
    else
        sfSprite_setColor(menu->size2, sfWhite);
}

void event_menu_settings(var_t *var, sfEvent event,
settings_t *menu, sfBool is_in_game)
{
    sfVector2u size = sfRenderWindow_getSize(var->window);
    float scalex = (float)size.x / 1920; float scaley = (float)size.y / 1080;
    mouse_event_t *mouse = malloc(sizeof(mouse_event_t));
    sfVector2i mouse2 = sfMouse_getPositionRenderWindow(var->window);
    sfVector2f mouse_float = (sfVector2f){(float)mouse2.x, (float)mouse2.y};

    mouse->x = event.mouseButton.x; mouse->y = event.mouseButton.y;
    mouse->scale_x = scalex; mouse->scale_y = scaley;
    settings_hover(menu, mouse_float);
    if (event.type == 9 && event.mouseButton.button == sfMouseLeft)
        settings_pressed(menu, mouse_float);
    if (event.type == 0 || (event.type == 5 && sfKeyboard_isKeyPressed(36)))
        sfRenderWindow_close(var->window);
    if (event.type == 10 && event.mouseButton.button == sfMouseLeft) {
        handle_back(event, var, is_in_game);
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

void menu_settings(var_t *var, sfBool is_in_game)
{
    settings_t *menus = init_settings();
    sfEvent event;
    while (sfRenderWindow_isOpen(var->window)){
        while (sfRenderWindow_pollEvent(var->window, &event))
            event_menu_settings(var, event, menus, is_in_game);
        display_menu_settings(var->window, menus);
    }
}
