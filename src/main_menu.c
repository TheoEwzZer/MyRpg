/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void event_menu(var_t *var, sfEvent event, menu_t *menu)
{
    sfFloatRect game_rect = sfSprite_getGlobalBounds(menu->play_sprite);
    sfFloatRect load_rect = sfSprite_getGlobalBounds(menu->resume_sprite);
    sfFloatRect settings_rect = sfSprite_getGlobalBounds(menu->setting_sprite);
    sfFloatRect exit_rect = sfSprite_getGlobalBounds(menu->exit_sprite);
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

void init_menu(menu_t *menu)
{
    sfTexture *play_texture = CREATE_FROM_FILE("assets/menu/play.png");
    sfTexture *quit_texture = CREATE_FROM_FILE("assets/menu/exit.png");
    sfTexture *resume_texture = CREATE_FROM_FILE("assets/menu/resume.png");
    sfTexture *settings_texture = CREATE_FROM_FILE("assets/menu/settings.png");
    sfTexture *texture = CREATE_FROM_FILE("assets/menu/background.jpg");
    menu->main_menu_sprite = sfSprite_create();
    sfSprite_setTexture(menu->main_menu_sprite, texture, sfTrue);
    menu->play_sprite = sfSprite_create();
    sfSprite_setTexture(menu->play_sprite, play_texture, sfTrue);
    sfSprite_setPosition(menu->play_sprite, (sfVector2f){500, 300});
    menu->exit_sprite = sfSprite_create();
    menu->resume_sprite = sfSprite_create();
    sfSprite_setTexture(menu->resume_sprite, resume_texture, sfTrue);
    sfSprite_setPosition(menu->resume_sprite, (sfVector2f){500, 450});
    menu->setting_sprite = sfSprite_create();
    sfSprite_setTexture(menu->setting_sprite, settings_texture, sfTrue);
    sfSprite_setPosition(menu->setting_sprite, (sfVector2f){500, 600});
    sfSprite_setTexture(menu->exit_sprite, quit_texture, sfTrue);
    sfSprite_setPosition(menu->exit_sprite, (sfVector2f){500, 750});
}

void display_menu(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->main_menu_sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->play_sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->exit_sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->resume_sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->setting_sprite, NULL);
    sfRenderWindow_display(window);
}

void main_menu(var_t *var)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfEvent event;

    init_menu(menu);
    while (sfRenderWindow_isOpen(var->window)) {
        while (sfRenderWindow_pollEvent(var->window, &event))
            event_menu(var, event, menu);
        display_menu(var->window, menu);
    }
}
