/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void event_menu(var_t *var, sfEvent event, menu_t *menuv)
{
    sfFloatRect game_rect = sfSprite_getGlobalBounds(menuv->playsprite);
    sfFloatRect load_rect = sfSprite_getGlobalBounds(menuv->resumesprite);
    sfFloatRect settings_rect = sfSprite_getGlobalBounds(menuv->settingsprite);
    sfFloatRect exit_rect = sfSprite_getGlobalBounds(menuv->exitsprite);
    sfIntRect game_button = {INT_RECT(game_rect)};
    sfIntRect load_button = {INT_RECT(load_rect)};
    sfIntRect settings_button = {INT_RECT(settings_rect)};
    sfIntRect exit_button = {INT_RECT(exit_rect)};
    if (event.type == 0 || (event.type == 5 && sfKeyboard_isKeyPressed(36))) {
        sfRenderWindow_close(var->window); return;
    } if (event.type == 9 && event.mouseButton.button == sfMouseLeft) {
        if (RECT_CONTAINS(&game_button))
            game_engine(var, event);
        if (RECT_CONTAINS(&load_button))
            load_game_and_engine(var, event);
        if (RECT_CONTAINS(&settings_button))
            menu_settings(var);
        if (RECT_CONTAINS(&exit_button))
            sfRenderWindow_close(var->window);
    }
}

void init_menu(menu_t *menuv)
{
    sfTexture *play_texture = CREATE_FROM_FILE("assets/menu/play.png");
    sfTexture *quit_texture = CREATE_FROM_FILE("assets/menu/exit.png");
    sfTexture *resume_texture = CREATE_FROM_FILE("assets/menu/resume.png");
    sfTexture *settings_texture = CREATE_FROM_FILE("assets/menu/settings.png");
    sfTexture *texture = CREATE_FROM_FILE("assets/menu/background.jpg");
    menuv->main_menusprite = sfSprite_create();
    sfSprite_setTexture(menuv->main_menusprite, texture, sfTrue);
    menuv->playsprite = sfSprite_create();
    sfSprite_setTexture(menuv->playsprite, play_texture, sfTrue);
    sfSprite_setPosition(menuv->playsprite, (sfVector2f){500, 300});
    menuv->exitsprite = sfSprite_create();
    menuv->resumesprite = sfSprite_create();
    sfSprite_setTexture(menuv->resumesprite, resume_texture, sfTrue);
    sfSprite_setPosition(menuv->resumesprite, (sfVector2f){500, 450});
    menuv->settingsprite = sfSprite_create();
    sfSprite_setTexture(menuv->settingsprite, settings_texture, sfTrue);
    sfSprite_setPosition(menuv->settingsprite, (sfVector2f){500, 600});
    sfSprite_setTexture(menuv->exitsprite, quit_texture, sfTrue);
    sfSprite_setPosition(menuv->exitsprite, (sfVector2f){500, 750});
}

void display_menu(sfRenderWindow *window, menu_t *menuv)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menuv->main_menusprite, NULL);
    sfRenderWindow_drawSprite(window, menuv->playsprite, NULL);
    sfRenderWindow_drawSprite(window, menuv->exitsprite, NULL);
    sfRenderWindow_drawSprite(window, menuv->resumesprite, NULL);
    sfRenderWindow_drawSprite(window, menuv->settingsprite, NULL);
    sfRenderWindow_display(window);
}

void main_menu(var_t *var)
{
    menu_t *menuv = malloc(sizeof(menu_t));
    sfEvent event;

    init_menu(menuv);
    while (sfRenderWindow_isOpen(var->window)) {
        while (sfRenderWindow_pollEvent(var->window, &event))
            event_menu(var, event, menuv);
        display_menu(var->window, menuv);
    }
}
