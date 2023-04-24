/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

sfSprite *init_commands(void)
{
    sfTexture *texture = CREATE_FROM_FILE("assets/commands/background.jpg");
    sfSprite *menu_sprite = sfSprite_create();

    sfSprite_setTexture(menu_sprite, texture, sfTrue);
    return menu_sprite;
}

sfText **init_texts_settings(void)
{
    sfText **texts = malloc(sizeof(sfText *) * 6);
    sfFont *font = sfFont_createFromFile("assets/font/arial.ttf");
    const char *str[6] = {"Z", "S", "D", "Q", "E", "SPACE"};
    unsigned int size = 0;
    sfVector2f position = {265.0f, 0.0f};

    for (int i = 0; i < 6; i++) {
        if (my_strlen(str[i]) < 3)
            size = 50;
        else
            size = 30;
        texts[i] = sfText_create();
        position.y = (float)150.0f + (float)i * 130.0f;
        sfText_setString(texts[i], str[i]);
        sfText_setFont(texts[i], font);
        sfText_setCharacterSize(texts[i], size);
        sfText_setPosition(texts[i], position);
    }
    return texts;
}

void display_commands(sfRenderWindow *window, sfSprite *menu_sprite,
    sfText **texts)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu_sprite, NULL);
    for (int i = 0; i < 6; i++)
        sfRenderWindow_drawText(window, texts[i], NULL);
    sfRenderWindow_display(window);
}

void menu_commands(var_t *var)
{
    sfSprite *background = init_commands();
    sfText **texts = init_texts_settings();
    sfEvent event;
    while (sfRenderWindow_isOpen(var->window)){
        while (sfRenderWindow_pollEvent(var->window, &event))
            event_commands(var, event, texts);
        display_commands(var->window, background, texts);
    }
}
