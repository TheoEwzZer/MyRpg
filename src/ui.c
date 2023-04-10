/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void display_ui(var_t *var)
{
    sfVector2f offset = sfView_getCenter(var->view);
    sfVector2f position_text = {0.0f, 0.0f};

    offset.x -= sfView_getSize(var->view).x / 2.0f;
    offset.y -= sfView_getSize(var->view).y / 2.0f;
    position_text.x = offset.x + var->quest_text->position.x;
    position_text.y = offset.y + var->quest_text->position.y;
    sfSprite_setPosition(var->quest_text->box, offset);
    sfText_setPosition(var->quest_text->text, position_text);
    sfRenderWindow_drawSprite(var->window, var->quest_text->box, NULL);
    sfRenderWindow_drawText(var->window, var->quest_text->text, NULL);
}

void init_ui(var_t *var)
{
    sfTexture *box_texture = CREATE_FROM_FILE("assets/box/quest_box.png");

    var->quest_text->text = sfText_create();
    sfText_setString(var->quest_text->text, "Talk to Priscilla");
    sfText_setFont(var->quest_text->text, var->dialog->font);
    sfText_setCharacterSize(var->quest_text->text, 30);
    var->quest_text->position = (sfVector2f){10.0f, 8.0f};
    var->quest_text->scale = (sfVector2f){0.5f, 0.5f};
    sfText_setPosition(var->quest_text->text, var->quest_text->position);
    sfText_setColor(var->quest_text->text, sfBlack);
    sfText_setScale(var->quest_text->text, var->quest_text->scale);
    var->quest_text->box = sfSprite_create();
    sfSprite_setScale(var->quest_text->box, (sfVector2f){0.05f, 0.05f});
    sfSprite_setTexture(var->quest_text->box, box_texture, sfTrue);
}
