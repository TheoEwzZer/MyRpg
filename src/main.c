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

void check_event(sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

int main(void)
{
    var_t *var = malloc(sizeof(var_t));
    sfEvent event;

    var->window = create_window();
    while (sfRenderWindow_isOpen(var->window)) {
        if (sfRenderWindow_pollEvent(var->window, &event))
            check_event(event, var->window);
        sfRenderWindow_clear(var->window, sfBlack);
        sfRenderWindow_display(var->window);
    }
}
