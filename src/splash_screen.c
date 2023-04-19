/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

splash_t *init_splash(var_t *var)
{
    sfTexture *texture = sfTexture_createFromFile("assets/splash.jpg", NULL);
    splash_t *splash = malloc(sizeof(splash_t));

    splash->splash = sfSprite_create();
    sfSprite_setTexture(splash->splash, texture, sfTrue);
    splash->clock = sfClock_create();
    splash->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setView(var->window, splash->view);
    return splash;
}

void display_splash(sfRenderWindow *window, splash_t *splash)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, splash->splash, NULL);
    sfRenderWindow_display(window);
}

void event_splash(var_t *var, sfEvent event, splash_t *splash, sfBool *is_enter)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(var->window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(var->window);
    }
    if (event.type == sfEvtKeyPressed){
        if (event.key.code == sfKeyEnter){
            *is_enter = sfTrue;
            sfClock_restart(splash->clock);
        }
    }
}

void splash_screen(var_t *var)
{
    sfBool is_enter = sfFalse;
    sfEvent event;
    sfView *default_view = NULL;
    splash_t *splash = init_splash(var);

    while (sfRenderWindow_isOpen(var->window)) {
        while (sfRenderWindow_pollEvent(var->window, &event))
            event_splash(var, event, splash, &is_enter);
        if (sfClock_getElapsedTime(splash->clock).microseconds > 2000000
        && is_enter) {
            sfView_zoom(splash->view, 0.995f);
            sfRenderWindow_setView(var->window, splash->view);
        }
        if (sfClock_getElapsedTime(splash->clock).microseconds > 4000000
        && is_enter) {
            default_view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
            sfRenderWindow_setView(var->window, default_view);
            main_menu(var);
        }
        display_splash(var->window, splash);
    }
}