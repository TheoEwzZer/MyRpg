/*
** EPITECH PROJECT, 2023
** life.c
** File description:
** life.c
*/

#include "my_rpg.h"

void display_tutorial(var_t *var)
{
    sfVector2f offset = sfView_getCenter(var->view);

    if (PLAYER->life <= 0)
        return;
    offset.x -= 100.0f;
    if (var->quest_progress == ENEMIES)
        offset.y -= 25.0f;
    if (var->tutorial->is_active) {
        sfText_setPosition(var->tutorial->text, offset);
        sfRenderWindow_drawText(var->window, var->tutorial->text, NULL);
    }
}
