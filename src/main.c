/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1920, 1080, 24};
    sfUint32 style = sfDefaultStyle;
    sfRenderWindow *window = sfRenderWindow_create(
        mode, "My Rpg", style, NULL
    );
    return window;
}

void check_event(var_t *var, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(var->window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyLeft) {
            sfView_move(var->view, (sfVector2f){-4, 0});
            sfSprite_move(var->character_sprite, (sfVector2f){-4, 0});
        }
        if (event.key.code == sfKeyRight) {
            sfView_move(var->view, (sfVector2f){4, 0});
            sfSprite_move(var->character_sprite, (sfVector2f){4, 0});
        }
        if (event.key.code == sfKeyUp) {
            sfView_move(var->view, (sfVector2f){0, -4});
            sfSprite_move(var->character_sprite, (sfVector2f){0, -4});
        }
        if (event.key.code == sfKeyDown) {
            sfView_move(var->view, (sfVector2f){0, 4});
            sfSprite_move(var->character_sprite, (sfVector2f){0, 4});
        }
    }
}

void create_sprite(var_t *var)
{
    sfImage *image = sfImage_createFromFile("assets/map.png");
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    sfImage *character = sfImage_createFromFile("assets/character.png");
    sfTexture *character_texture = sfTexture_createFromImage(character, NULL);
    var->background_sprite = sfSprite_create();
    sfSprite_setTexture(var->background_sprite, texture, sfTrue);
    var->character_sprite = sfSprite_create();
    sfSprite_setTexture(var->character_sprite, character_texture, sfTrue);
}

int main(void)
{
    var_t *var = malloc(sizeof(var_t));
    sfEvent event;
    create_sprite(var);
    var->window = create_window();
    var->view = sfView_createFromRect((sfFloatRect){0, 0, 462, 258});
    sfView_setCenter(var->view, (sfVector2f){231, 129});
    sfSprite_setPosition(var->character_sprite, (sfVector2f){231, 129});
    sfSprite_setScale(var->character_sprite, (sfVector2f){0.25f, 0.25f});
    while (sfRenderWindow_isOpen(var->window)) {
        if (sfRenderWindow_pollEvent(var->window, &event))
            check_event(var, event);
        sfRenderWindow_setView(var->window, var->view);
        sfRenderWindow_clear(var->window, sfBlack);
        sfRenderWindow_drawSprite(var->window, var->background_sprite, NULL);
        sfRenderWindow_drawSprite(var->window, var->character_sprite, NULL);
        sfRenderWindow_display(var->window);
    }
}
