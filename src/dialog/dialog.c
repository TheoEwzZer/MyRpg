/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void create_dialog_box(var_t *var)
{
    var->dialog = malloc(sizeof(dialog_t));
    var->dialog->texture = CREATE_FROM_FILE("assets/dialog_box.png");
    var->dialog->sprite = sfSprite_create();
    sfSprite_setTexture(var->dialog->sprite, var->dialog->texture, sfTrue);
    var->dialog->pos = (sfVector2f){500, 1100};
    var->dialog->scale = (sfVector2f){0.05f, 0.05f};
    sfSprite_setScale(var->dialog->sprite, var->dialog->scale);
    var->dialog->font = sfFont_createFromFile("assets/font/arial.ttf");
    var->dialog->text = sfText_create();
    sfText_setFont(var->dialog->text, var->dialog->font);
    sfText_setColor(var->dialog->text, sfBlack);
    var->dialog->name = sfText_create();
    sfText_setFont(var->dialog->name, var->dialog->font);
    sfText_setColor(var->dialog->name, sfWhite);
    sfText_setScale(var->dialog->name, (sfVector2f){0.2f, 0.2f});
    var->has_talk_to_blacksmith = false;
    var->is_talking_to_blacksmith = false;
    var->has_kill_all_mobs = false;
}

void blacksmith_dialog(var_t *var)
{
    sfVector2f sprite_pos = sfSprite_getPosition(var->mc->sprite);
    static bool has_zoom = false;

    if (sprite_pos.x >= 480 && sprite_pos.x <= 580
    && sprite_pos.y >= 1100 && sprite_pos.y <= 1170) {
        zoom_in(var, &has_zoom);
        var->is_talking_to_blacksmith = true;
        show_blacksmith_dialog(var);
    } else {
        zoom_out(var, &has_zoom);
        if (var->is_talking_to_blacksmith)
            var->has_talk_to_blacksmith = true;
    }
}

void priscilla_dialog(var_t *var)
{
    sfVector2f sprite_pos = sfSprite_getPosition(var->mc->sprite);
    static bool has_zoom = false;

    if (sprite_pos.x >= 1000 && sprite_pos.x <= 1150
    && sprite_pos.y >= 1125 && sprite_pos.y <= 1200) {
        zoom_in(var, &has_zoom);
        show_priscilla_dialog(var);
    } else {
        zoom_out(var, &has_zoom);
    }
}

void bob_dialog(var_t *var)
{
    sfVector2f sprite_pos = sfSprite_getPosition(var->mc->sprite);
    static bool has_zoom = false;

    if (sprite_pos.x >= 950 && sprite_pos.x <= 1100
    && sprite_pos.y >= 755 && sprite_pos.y <= 860) {
        zoom_in(var, &has_zoom);
        show_bob_dialog(var);
    } else {
        zoom_out(var, &has_zoom);
    }
}
