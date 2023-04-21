/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void zoom_out(var_t *var, sfBool *has_zoom)
{
    sfVector2f scale_box = sfSprite_getScale(var->quest_text->box);
    sfVector2f scale_text = sfText_getScale(var->quest_text->text);

    if (*has_zoom) {
        sfView_zoom(var->view, 1.5f);
        *has_zoom = sfFalse;
        if (var->quest_progress != BOSS)
            var->is_particle_active = sfTrue;
        scale_box.x *= 1.5f;
        scale_box.y *= 1.5f;
        var->quest_text->scale.x = scale_text.x * 1.5f;
        var->quest_text->scale.y = scale_text.y * 1.5f;
        sfSprite_setScale(var->quest_text->box, scale_box);
        sfText_setScale(var->quest_text->text, var->quest_text->scale);
        var->quest_text->position.x += 2.0f;
        var->quest_text->position.y += 3.0f;
        sfText_setPosition(var->quest_text->text, var->quest_text->position);
        sfSprite_setScale(var->life->sprite, (sfVector2f){0.5f, 0.5f});
        sfText_setScale(var->tutorial->text, (sfVector2f){0.5f, 0.5f});
    }
}

void zoom_in(var_t *var, sfBool *has_zoom)
{
    sfVector2f scale_box = sfSprite_getScale(var->quest_text->box);
    sfVector2f scale_text = sfText_getScale(var->quest_text->text);
    sfVector2f scale_life = sfSprite_getScale(var->life->sprite);
    sfVector2f scale_tutorial = sfText_getScale(var->tutorial->text);
    if (!*has_zoom) {
        sfView_zoom(var->view, 2.0f / 3.0f);
        *has_zoom = sfTrue; var->is_particle_active = sfFalse;
        scale_box.x /= 1.5f; scale_box.y /= 1.5f;
        var->quest_text->scale.x = scale_text.x / 1.5f;
        var->quest_text->scale.y = scale_text.y / 1.5f;
        sfSprite_setScale(var->quest_text->box, scale_box);
        sfText_setScale(var->quest_text->text, var->quest_text->scale);
        var->quest_text->position.x -= 2.0f;
        var->quest_text->position.y -= 3.0f;
        sfText_setPosition(var->quest_text->text, var->quest_text->position);
        scale_life.x /= 1.5f; scale_life.y /= 1.5f;
        sfSprite_setScale(var->life->sprite, scale_life);
        scale_tutorial.x /= 1.5f; scale_tutorial.y /= 1.5f;
        sfText_setScale(var->tutorial->text, scale_tutorial);
    }
}

void show_blacksmith_dialog(var_t *var)
{
    var->dialog->position = (sfVector2f){500.0f, 1100.0f};
    sfSprite_setPosition(var->dialog->sprite, var->dialog->position);
    sfText_setPosition(var->dialog->name, (sfVector2f){522.0f, 1102.0f});
    DRAW_SPRITE(var->dialog->sprite);
    if (!var->has_talk_to_blacksmith) {
        sfText_setString(var->dialog->text, CONFIG->blacksmith_dialog);
        sfText_setScale(var->dialog->text, (sfVector2f){0.4f, 0.4f});
        sfText_setPosition(var->dialog->text, (sfVector2f){515.0f, 1110.0f});
        INVENTORY->texture = CREATE_FROM_FILE("assets/player/inventory_2.png");
        sfSprite_setTexture(INVENTORY->sprite, INVENTORY->texture, sfTrue);
        sfText_setString(var->tutorial->text, CONFIG->tutorial_dialog);
        var->tutorial->is_active = sfTrue;
    } else {
        sfText_setString(var->dialog->text, CONFIG->blacksmith_dialog2);
        sfText_setScale(var->dialog->text, (sfVector2f){0.25f, 0.25f});
        sfText_setPosition(var->dialog->text, (sfVector2f){525.0f, 1110.0f});
    }
    sfText_setString(var->dialog->name, "Blacksmith");
    sfRenderWindow_drawText(var->window, var->dialog->text, NULL);
    sfRenderWindow_drawText(var->window, var->dialog->name, NULL);
}

void show_priscilla_dialog(var_t *var)
{
    var->dialog->position = (sfVector2f){1075.0f, 1125.0f};
    sfSprite_setPosition(var->dialog->sprite, var->dialog->position);
    sfText_setPosition(var->dialog->name, (sfVector2f){1100.0f, 1127.0f});
    DRAW_SPRITE(var->dialog->sprite);
    if (var->quest_progress < ENEMIES) {
        sfText_setString(var->dialog->text, CONFIG->priscilla_dialog);
        sfText_setScale(var->dialog->text, (sfVector2f){0.25f, 0.25f});
        sfText_setPosition(var->dialog->text, (sfVector2f){1090.0f, 1135.0f});
    } else {
        sfText_setString(var->dialog->text, CONFIG->priscilla_dialog2);
        sfText_setScale(var->dialog->text, (sfVector2f){0.25f, 0.25f});
        sfText_setPosition(var->dialog->text, (sfVector2f){1090.0f, 1135.0f});
    }
    sfText_setString(var->dialog->name, "Priscilla");
    sfRenderWindow_drawText(var->window, var->dialog->text, NULL);
    sfRenderWindow_drawText(var->window, var->dialog->name, NULL);
}

void show_bob_dialog(var_t *var)
{
    var->dialog->position = (sfVector2f){975.0f, 775.0f};
    sfSprite_setPosition(var->dialog->sprite, var->dialog->position);
    sfText_setPosition(var->dialog->name, (sfVector2f){1000.0f, 777.0f});
    DRAW_SPRITE(var->dialog->sprite);
    if (var->quest_progress <= ENEMIES) {
        sfText_setString(var->dialog->text, CONFIG->bob_dialog);
        sfText_setScale(var->dialog->text, (sfVector2f){0.4f, 0.4f});
        sfText_setPosition(var->dialog->text, (sfVector2f){985.0f, 785.0f});
    } else {
        sfText_setString(var->dialog->text, CONFIG->bob_dialog2);
        sfText_setScale(var->dialog->text, (sfVector2f){0.25f, 0.25f});
        sfText_setPosition(var->dialog->text, (sfVector2f){980.0f, 785.0f});
    }
    sfText_setString(var->dialog->name, "Bob");
    sfRenderWindow_drawText(var->window, var->dialog->text, NULL);
    sfRenderWindow_drawText(var->window, var->dialog->name, NULL);
}
