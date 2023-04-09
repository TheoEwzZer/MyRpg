/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void zoom_out(var_t *var, bool *has_zoom)
{
    if (*has_zoom) {
        sfView_zoom(var->view, 1.5f);
        *has_zoom = false;
    }
}

void zoom_in(var_t *var, bool *has_zoom)
{
    if (!*has_zoom) {
        sfView_zoom(var->view, 0.66f);
        *has_zoom = true;
    }
}

void show_blacksmith_dialog(var_t *var)
{
    var->dialog->position = (sfVector2f){500, 1100};
    sfSprite_setPosition(var->dialog->sprite, var->dialog->position);
    sfText_setPosition(var->dialog->name, (sfVector2f){522, 1102});
    DRAW_SPRITE(var->dialog->sprite);
    if (!var->has_talk_to_blacksmith) {
        sfText_setString(var->dialog->text, BLACKSMITH_DIALOG1);
        sfText_setScale(var->dialog->text, (sfVector2f){0.4f, 0.4f});
        sfText_setPosition(var->dialog->text, (sfVector2f){515, 1110});
    } else {
        sfText_setString(var->dialog->text, BLACKSMITH_DIALOG2);
        sfText_setScale(var->dialog->text, (sfVector2f){0.25f, 0.25f});
    sfText_setPosition(var->dialog->text, (sfVector2f){525, 1110});
    }
    sfText_setString(var->dialog->name, "Blacksmith");
    sfRenderWindow_drawText(var->window, var->dialog->text, NULL);
    sfRenderWindow_drawText(var->window, var->dialog->name, NULL);
}

void show_priscilla_dialog(var_t *var)
{
    var->dialog->position = (sfVector2f){1075, 1125};
    sfSprite_setPosition(var->dialog->sprite, var->dialog->position);
    sfText_setPosition(var->dialog->name, (sfVector2f){1100, 1127});
    DRAW_SPRITE(var->dialog->sprite);
    if (!var->has_armor) {
        sfText_setString(var->dialog->text, PRICILLA_DIALOG1);
        sfText_setScale(var->dialog->text, (sfVector2f){0.25f, 0.25f});
        sfText_setPosition(var->dialog->text, (sfVector2f){1090, 1135});
    } else {
        sfText_setString(var->dialog->text, PRICILLA_DIALOG2);
        sfText_setScale(var->dialog->text, (sfVector2f){0.25f, 0.25f});
        sfText_setPosition(var->dialog->text, (sfVector2f){1090, 1135});
    }
    sfText_setString(var->dialog->name, "Priscilla");
    sfRenderWindow_drawText(var->window, var->dialog->text, NULL);
    sfRenderWindow_drawText(var->window, var->dialog->name, NULL);
}

void show_bob_dialog(var_t *var)
{
    var->dialog->position = (sfVector2f){975, 775};
    sfSprite_setPosition(var->dialog->sprite, var->dialog->position);
    sfText_setPosition(var->dialog->name, (sfVector2f){1000, 777});
    DRAW_SPRITE(var->dialog->sprite);
    if (!var->has_kill_all_mobs) {
        sfText_setString(var->dialog->text, BOB_DIALOG1);
        sfText_setScale(var->dialog->text, (sfVector2f){0.4f, 0.4f});
        sfText_setPosition(var->dialog->text, (sfVector2f){985, 785});
    } else {
        sfText_setString(var->dialog->text, BOB_DIALOG2);
        sfText_setScale(var->dialog->text, (sfVector2f){0.25f, 0.25f});
        sfText_setPosition(var->dialog->text, (sfVector2f){980, 785});
    }
    sfText_setString(var->dialog->name, "Bob");
    sfRenderWindow_drawText(var->window, var->dialog->text, NULL);
    sfRenderWindow_drawText(var->window, var->dialog->name, NULL);
}
