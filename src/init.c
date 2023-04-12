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
    ORC = malloc(sizeof(char_t));
    PLAYER = malloc(sizeof(char_t));
    SKELETON = malloc(sizeof(char_t));
    SOUND = malloc(sizeof(sound_t));
    var->girl = malloc(sizeof(char_t));
    var->girl->rect.left = 0;
    var->is_particle_active = true;
    var->life = malloc(sizeof(life_t));
    var->pnj = malloc(sizeof(char_t));
    var->pnj->rect.left = 0;
    var->quest_text = malloc(sizeof(quest_text_t));
    init_char(var);
}

void init_player(var_t *var)
{
    PLAYER->clothes = CREATE_FROM_FILE("assets/player/player.png");
    PLAYER->sprite = sfSprite_create();
    var->armor = CREATE_FROM_FILE("assets/player/armor.png");
    sfSprite_setTexture(PLAYER->sprite, PLAYER->clothes, sfTrue);
    PLAYER->walk = sfClock_create();
    PLAYER->rect = (sfIntRect){0, 0, 77, 77};
    sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
    sfSprite_setPosition(PLAYER->sprite, (sfVector2f){1685.0f, 1300.0f});
    sfSprite_setScale(PLAYER->sprite, (sfVector2f){0.75f, 0.75f});
    PLAYER->attack = false;
    PLAYER->direction = DOWN;
}

void init_struct(var_t *var)
{
    sfImage *image = sfImage_createFromFile("assets/map/map.png");
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    init_player(var);
    var->background_sprite = sfSprite_create();
    sfSprite_setTexture(var->background_sprite, texture, sfTrue);
    var->window = create_window();
    var->view = sfView_createFromRect((sfFloatRect){0, 0, 640, 360});
    sfView_setCenter(var->view, (sfVector2f){1685.0f, 1275.0f});
    create_collider(var);
    sfView_zoom(var->view, 1.15f);
    var->frame_count = 0;
    var->quest_progress = PRISCILLA;
}

void init_rpg(var_t *var)
{
    init_game(var);
    init_orc(var);
    init_skeleton(var);
    init_sound(var);
    init_struct(var);
    init_life(var);
}
