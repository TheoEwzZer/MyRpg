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
    var->dialog->texture = CREATE_FROM_FILE("assets/box/dialog_box.png");
    var->dialog->sprite = sfSprite_create();
    sfSprite_setTexture(var->dialog->sprite, var->dialog->texture, sfTrue);
    var->dialog->position = (sfVector2f){500.0f, 1100.0f};
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
}

void blacksmith_dialog(var_t *var)
{
    sfVector2f sprite_position = sfSprite_getPosition(PLAYER->sprite);
    static bool has_zoom = false;

    if (sprite_position.x >= 480.0f && sprite_position.x <= 580.0f
    && sprite_position.y >= 1100.0f && sprite_position.y <= 1170.0f
    && var->quest_progress > PRISCILLA) {
        if (var->quest_progress == ENEMIES)
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
    sfVector2f sprite_position = sfSprite_getPosition(PLAYER->sprite);
    static bool has_zoom = false;

    if (sprite_position.x >= 1000.0f && sprite_position.x <= 1150.0f
    && sprite_position.y >= 1125.0f && sprite_position.y <= 1200.0f) {
        if (var->quest_progress == PRISCILLA) {
            sfText_setString(var->quest_text->text, "Go to the blacksmith");
            var->quest_text->position = (sfVector2f){5.0f, 10.0f};
            var->quest_text->scale = (sfVector2f){0.4f, 0.4f};
            sfText_setScale(var->quest_text->text, var->quest_text->scale);
            var->quest_progress = ARMOR;
            move_particle_position_pnj(var, (sfVector2f){555.0f, 1110.0f});
        }
        if (var->quest_progress < ENEMIES)
            zoom_in(var, &has_zoom);
        show_priscilla_dialog(var);
    } else {
        zoom_out(var, &has_zoom);
    }
}

void bob_dialog(var_t *var)
{
    sfVector2f sprite_position = sfSprite_getPosition(PLAYER->sprite);
    static bool has_zoom = false;

    if (sprite_position.x >= 950.0f && sprite_position.x <= 1100.0f
    && sprite_position.y >= 755.0f && sprite_position.y <= 860.0f) {
        if (var->quest_progress == BOB)
            zoom_in(var, &has_zoom);
        show_bob_dialog(var);
    } else {
        zoom_out(var, &has_zoom);
    }
}

void dialog(var_t *var)
{
    priscilla_dialog(var);
    bob_dialog(var);
    blacksmith_dialog(var);
}
