/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void check_exp(var_t *var)
{
    if (PLAYER->exp == 7)
        sfSprite_setTexture(INVENTORY->bar, INVENTORY->exp7, sfTrue);
    if (PLAYER->exp == 6)
        sfSprite_setTexture(INVENTORY->bar, INVENTORY->exp6, sfTrue);
    if (PLAYER->exp == 5)
        sfSprite_setTexture(INVENTORY->bar, INVENTORY->exp5, sfTrue);
    if (PLAYER->exp == 4)
        sfSprite_setTexture(INVENTORY->bar, INVENTORY->exp4, sfTrue);
    if (PLAYER->exp == 3)
        sfSprite_setTexture(INVENTORY->bar, INVENTORY->exp3, sfTrue);
    if (PLAYER->exp == 2)
        sfSprite_setTexture(INVENTORY->bar, INVENTORY->exp2, sfTrue);
    if (PLAYER->exp == 1)
        sfSprite_setTexture(INVENTORY->bar, INVENTORY->exp1, sfTrue);
    if (PLAYER->exp == 0)
        sfSprite_setTexture(INVENTORY->bar, INVENTORY->exp0, sfTrue);
}

void stat_set_pos(var_t *var, float x, float y)
{
    sfVector2f spear_pos = {0.0f, 0.0f};
    sfVector2f atk_pos = {0.0f, 0.0f};
    spear_pos.x = x + 125.0f;
    spear_pos.y = y + 75.0f;
    atk_pos.x = x + 200.0f;
    atk_pos.y = y + 73.0f;
    sfSprite_setPosition(INVENTORY->lance, spear_pos);
    sfText_setPosition(INVENTORY->atk, atk_pos);
}

void display_inventory(var_t *var)
{
    check_exp(var);
    if (INVENTORY->is_open) {
        DRAW_SPRITE(INVENTORY->sprite);
        DRAW_SPRITE(INVENTORY->bar);
        DRAW_SPRITE(INVENTORY->lance);
        sfRenderWindow_drawText(var->window, INVENTORY->atk, NULL);
    }
}

void display_ui(var_t *var)
{
    sfVector2f offset = sfView_getCenter(var->view);
    sfVector2f position_text = {0.0f, 0.0f};
    sfVector2f inventory = {0.0f, 0.0f};
    sfVector2f exp_pos = {0.0f, 0.0f};
    offset.x -= sfView_getSize(var->view).x / 2.0f;
    offset.y -= sfView_getSize(var->view).y / 2.0f;
    position_text.x = offset.x + var->quest_text->position.x;
    position_text.y = offset.y + var->quest_text->position.y;
    sfSprite_setPosition(var->quest_text->box, offset);
    sfText_setPosition(var->quest_text->text, position_text);
    DRAW_SPRITE(var->quest_text->box);
    sfRenderWindow_drawText(var->window, var->quest_text->text, NULL);
    inventory.x = offset.x + 235.0f;
    inventory.y = offset.y + 75.0f;
    exp_pos.x = inventory.x + 80.0f;
    exp_pos.y = inventory.y - 20.0f;
    sfSprite_setPosition(INVENTORY->sprite, inventory);
    sfSprite_setPosition(INVENTORY->bar, exp_pos);
    stat_set_pos(var, inventory.x, inventory.y);
    display_inventory(var);
}

void init_ui(var_t *var)
{
    sfTexture *box_texture = CREATE_FROM_FILE("assets/box/quest_box.png");
    INVENTORY->texture = CREATE_FROM_FILE("assets/player/inventory.png");

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
    INVENTORY->sprite = sfSprite_create();
    sfSprite_setTexture(INVENTORY->sprite, INVENTORY->texture, sfTrue);
    sfSprite_setScale(INVENTORY->sprite, (sfVector2f){1.5f, 1.5f});
    init_exp(var);
}
