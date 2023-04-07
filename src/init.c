/*
** EPITECH PROJECT, 2023
** character_move
** File description:
** character_move
*/

#include "my_rpg.h"

void init_game(var_t *var)
{
    var->mc = malloc(sizeof(char_t));
    var->forge = malloc(sizeof(char_t));
    var->girl = malloc(sizeof(char_t));
    var->pnj = malloc(sizeof(char_t));
    var->orc = malloc(sizeof(char_t));
    var->skel = malloc(sizeof(char_t));
    var->sound = malloc(sizeof(sound_t));
    var->forge->rect.left = 0;
    var->girl->rect.left = 0;
    var->pnj->rect.left = 0;
    var->sound->theme = sfMusic_createFromFile("assets/music/main_theme.ogg");
    sfMusic_setVolume(var->sound->theme, 50);
    init_char(var);
}

void init_ennemies(var_t *var)
{
    var->orc->clothes = CREATE_FROM_FILE("assets/pnj/orc.png");
    var->orc->sprite = sfSprite_create();
    sfSprite_setTexture(var->orc->sprite, var->orc->clothes, sfTrue);
    var->orc->walk = sfClock_create();
    sfSprite_setPosition(var->orc->sprite, (sfVector2f){720, 700});
    var->orc->rect.left = 0;
    sfSprite_setScale(var->orc->sprite, (sfVector2f){0.75f, 0.75f});
    var->skel->clothes = CREATE_FROM_FILE("assets/pnj/skel.png");
    var->skel->sprite = sfSprite_create();
    var->skel->rect.left = 0;
    sfSprite_setTexture(var->skel->sprite, var->skel->clothes, sfTrue);
    var->skel->walk = sfClock_create();
    sfSprite_setPosition(var->skel->sprite, (sfVector2f){500, 590});
    sfSprite_setScale(var->skel->sprite, (sfVector2f){0.75f, 0.75f});
    var->switch_side = true;
}

void init_player(var_t *var)
{
    var->mc->clothes = CREATE_FROM_FILE("assets/player/mc.png");
    var->mc->sprite = sfSprite_create();
    var->armor = CREATE_FROM_FILE("assets/player/armor.png");
    sfSprite_setTexture(var->mc->sprite, var->mc->clothes, sfTrue);
    var->mc->walk = sfClock_create();
    var->mc->rect.top = 0;
    var->mc->rect.width = 77;
    var->mc->rect.height = 77;
    var->mc->rect.left = 0;
    sfSprite_setTextureRect(var->mc->sprite, var->mc->rect);
    sfSprite_setPosition(var->mc->sprite, (sfVector2f){1685, 1300});
    sfSprite_setScale(var->mc->sprite, (sfVector2f){0.75f, 0.75f});
    var->hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition(var->hitbox, (sfVector2f){1700, 1340});
}

void init_struct(var_t *var)
{
    sfImage *image = sfImage_createFromFile("assets/map/map.png");
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    var->mc = malloc(sizeof(char_t));
    init_player(var);
    var->background_sprite = sfSprite_create();
    sfSprite_setTexture(var->background_sprite, texture, sfTrue);
    var->window = create_window();
    var->view = sfView_createFromRect((sfFloatRect){0, 0, 640, 360});
    sfView_setCenter(var->view, (sfVector2f){1685, 1275});
    create_collider(var);
    sfView_zoom(var->view, 1.15f);
    var->frame_count = 0;
    var->has_armor = false;
}
