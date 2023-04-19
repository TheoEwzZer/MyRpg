/*
** EPITECH PROJECT, 2023
** character_move
** File description:
** character_move
*/

#include "my_rpg.h"

void init_game(var_t *var)
{
    BLACKSMITH = malloc(sizeof(char_t));
    BLACKSMITH->rect.left = 0;
    INVENTORY = malloc(sizeof(inventory_t));
    INVENTORY->is_open = sfFalse;
    ORC = malloc(sizeof(char_t));
    PLAYER = malloc(sizeof(char_t));
    SKELETON = malloc(sizeof(char_t));
    SOUND = malloc(sizeof(sound_t));
    BOSSV = malloc(sizeof(boss_t));
    BOSSC = malloc(sizeof(char_t));
    var->girl = malloc(sizeof(char_t));
    var->girl->rect.left = 0;
    var->is_particle_active = sfTrue;
    var->life = malloc(sizeof(life_t));
    var->pnj = malloc(sizeof(char_t));
    var->pnj->rect.left = 0;
    var->quest_text = malloc(sizeof(quest_text_t));
    init_char(var);
}

void init_player(var_t *var)
{
    PLAYER->texture = CREATE_FROM_FILE("assets/player/player.png");
    PLAYER->sprite = sfSprite_create();
    var->armor = CREATE_FROM_FILE("assets/player/armor.png");
    sfSprite_setTexture(PLAYER->sprite, PLAYER->texture, sfTrue);
    PLAYER->walk = sfClock_create();
    PLAYER->rect = (sfIntRect){0, 0, 77, 77};
    sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
    sfSprite_setPosition(PLAYER->sprite, (sfVector2f){1685.0f, 1300.0f});
    sfSprite_setScale(PLAYER->sprite, (sfVector2f){0.75f, 0.75f});
    PLAYER->attack = sfFalse;
    PLAYER->direction = DOWN;
    var->player->exp = 0;
}

void init_struct(var_t *var)
{
    sfImage *image = sfImage_createFromFile("assets/map/map.png");

    BOSSV->boss_room = CREATE_FROM_FILE("assets/map/boss_room.png");
    BOSSV->map = sfTexture_createFromImage(image, NULL);
    init_player(var);
    var->background_sprite = sfSprite_create();
    BOSSV->room = sfSprite_create();
    sfSprite_setTexture(BOSSV->room, BOSSV->boss_room, sfTrue);
    sfSprite_setTexture(var->background_sprite, BOSSV->map, sfTrue);
    sfSprite_setPosition(BOSSV->room, (sfVector2f){400.0f, 2500.0f});
    var->window = create_window();
    var->view = sfView_createFromRect((sfFloatRect){0, 0, 640, 360});
    sfView_setCenter(var->view, (sfVector2f){1685.0f, 1275.0f});
    create_collider(var);
    sfView_zoom(var->view, 1.15f);
    var->frame_count = 0;
    var->quest_progress = PRISCILLA;
}

void init_tutorial(var_t *var)
{
    sfFont *font = sfFont_createFromFile("assets/font/arial.ttf");

    var->tutorial = malloc(sizeof(tutorial_t));
    var->tutorial->is_active = sfTrue;
    var->tutorial->text = sfText_create();
    sfText_setFont(var->tutorial->text, font);
    sfText_setCharacterSize(var->tutorial->text, 30);
    sfText_setPosition(var->tutorial->text, (sfVector2f){100.0f, 100.0f});
    sfText_setString(var->tutorial->text, "Use the arrow keys or ZQSD to move");
    sfText_setColor(var->tutorial->text, sfWhite);
    sfText_setOutlineColor(var->tutorial->text, sfBlack);
    sfText_setOutlineThickness(var->tutorial->text, 2.0f);
    sfText_setScale(var->tutorial->text, (sfVector2f){0.5f, 0.5f});
}

void init_rpg(var_t *var)
{
    init_game(var);
    init_orc(var);
    init_skeleton(var);
    init_sound(var);
    init_struct(var);
    init_life(var);
    init_boss(var);
    init_inventory(var);
    init_tutorial(var);
}
