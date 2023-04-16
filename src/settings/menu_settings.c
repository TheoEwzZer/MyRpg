/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void event_menu_settings(var_t *var, sfEvent event, settings_t *menuv)
{
    sfVector2u size = sfRenderWindow_getSize(var->window);
    float scalx = (float)size.x / 1920;
    float scaly = (float)size.y / 1080;
    mouse_event_t *mouse = malloc(sizeof(mouse_event_t));

    mouse->x = event.mouseButton.x;
    mouse->y = event.mouseButton.y;
    mouse->scalx = scalx;
    mouse->scaly = scaly;
    if (event.type == 0 || (event.type == 5 && sfKeyboard_isKeyPressed(36)))
        sfRenderWindow_close(var->window);
    if (event.type == 9 && event.mouseButton.button == sfMouseLeft) {
        if (event.mouseButton.x > 0 && event.mouseButton.x < 150 * scalx
        && event.mouseButton.y > 0 * scaly && event.mouseButton.y < 150 * scaly)
            main_menu(var);
        handle_music(var, menuv, mouse);
        handle_sound(var, menuv, mouse);
        choose_resolution(var, scalx, scaly, event);
    }
}

void draw_settings(settings_t *menuv, sfRenderWindow *window)
{
    if (menuv->jaugem == 0)
        sfRenderWindow_drawSprite(window, menuv->jaugem0, NULL);
    if (menuv->jaugem == 1)
        sfRenderWindow_drawSprite(window, menuv->jaugem1, NULL);
    if (menuv->jaugem == 2)
        sfRenderWindow_drawSprite(window, menuv->jaugem2, NULL);
    if (menuv->jaugem == 3)
        sfRenderWindow_drawSprite(window, menuv->jaugem3, NULL);
    if (menuv->jaugem == 4)
        sfRenderWindow_drawSprite(window, menuv->jaugem4, NULL);
    if (menuv->jauges == 0)
        sfRenderWindow_drawSprite(window, menuv->jauges0, NULL);
    if (menuv->jauges == 1)
        sfRenderWindow_drawSprite(window, menuv->jauges1, NULL);
    if (menuv->jauges == 2)
        sfRenderWindow_drawSprite(window, menuv->jauges2, NULL);
    if (menuv->jauges == 3)
        sfRenderWindow_drawSprite(window, menuv->jauges3, NULL);
    if (menuv->jauges == 4)
        sfRenderWindow_drawSprite(window, menuv->jauges4, NULL);
}

void display_menu_settings(sfRenderWindow *window, settings_t *menuv)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menuv->menusprite, NULL);
    sfRenderWindow_drawSprite(window, menuv->musicsprite, NULL);
    sfRenderWindow_drawSprite(window, menuv->sizesprite, NULL);
    sfRenderWindow_drawSprite(window, menuv->soundsprite, NULL);
    sfRenderWindow_drawSprite(window, menuv->resolutionsprite, NULL);
    sfRenderWindow_drawSprite(window, menuv->mutem, NULL);
    sfRenderWindow_drawSprite(window, menuv->mutes, NULL);
    sfRenderWindow_drawSprite(window, menuv->res1, NULL);
    sfRenderWindow_drawSprite(window, menuv->res2, NULL);
    sfRenderWindow_drawSprite(window, menuv->size1, NULL);
    sfRenderWindow_drawSprite(window, menuv->size2, NULL);
    draw_settings(menuv, window);
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
