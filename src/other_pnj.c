/*
** EPITECH PROJECT, 2023
** other_pnj
** File description:
** other_pnj
*/

#include "my_rpg.h"

void init_char(var_t *var)
{
    var->forge->clothes = CREATE_FROM_FILE("assets/pnj/forg.png");
    var->forge->sprite = sfSprite_create();
    sfSprite_setTexture(var->forge->sprite, var->forge->clothes, sfTrue);
    var->forge->walk = sfClock_create();
    sfSprite_setPosition(var->forge->sprite, (sfVector2f){530, 1120});
    sfSprite_setScale(var->forge->sprite, (sfVector2f){0.75f, 0.75f});
    var->girl->clothes = CREATE_FROM_FILE("assets/pnj/Woman.png");
    var->girl->sprite = sfSprite_create();
    sfSprite_setTexture(var->girl->sprite, var->girl->clothes, sfTrue);
    var->girl->walk = sfClock_create();
    sfSprite_setPosition(var->girl->sprite, (sfVector2f){1100, 1150});
    sfSprite_setScale(var->girl->sprite, (sfVector2f){0.75f, 0.75f});
    var->pnj->clothes = CREATE_FROM_FILE("assets/pnj/pnj.png");
    var->pnj->sprite = sfSprite_create();
    sfSprite_setTexture(var->pnj->sprite, var->pnj->clothes, sfTrue);
    var->pnj->walk = sfClock_create();
    sfSprite_setPosition(var->pnj->sprite, (sfVector2f){1000, 800});
    sfSprite_setScale(var->pnj->sprite, (sfVector2f){0.75f, 0.75f});
}

void forge_move(var_t *var)
{
    var->forge->times = sfClock_getElapsedTime(var->forge->walk);
    var->forge->second = (float)var->forge->times.microseconds / 1000000.0f;
    var->forge->rect.top = 0;
    var->forge->rect.width = 77;
    var->forge->rect.height = 77;
    if (var->forge->second > 0.8f) {
        if (var->forge->rect.left == 77)
            var->forge->rect.left = 0;
        else
            var->forge->rect.left = var->forge->rect.left + 77;
        sfClock_restart(var->forge->walk);
    }
    sfSprite_setTextureRect(var->forge->sprite, var->forge->rect);
    DRAW_SPRITE(var->forge->sprite);
}

void girl_move(var_t *var)
{
    var->girl->times = sfClock_getElapsedTime(var->girl->walk);
    var->girl->second = (float)var->girl->times.microseconds / 1000000.0f;
    var->girl->rect.top = 0;
    var->girl->rect.width = 77;
    var->girl->rect.height = 77;
    if (var->girl->second > 0.8f) {
        if (var->girl->rect.left == 77)
            var->girl->rect.left = 0;
        else
            var->girl->rect.left = var->girl->rect.left + 77;
        sfClock_restart(var->girl->walk);
    }
    sfSprite_setTextureRect(var->girl->sprite, var->girl->rect);
    DRAW_SPRITE(var->girl->sprite);
}

void pnj_move(var_t *var)
{
    var->pnj->times = sfClock_getElapsedTime(var->pnj->walk);
    var->pnj->second = (float)var->pnj->times.microseconds / 1000000.0f;
    var->pnj->rect.top = 0;
    var->pnj->rect.width = 77;
    var->pnj->rect.height = 77;
    if (var->pnj->second > 0.8f) {
        if (var->pnj->rect.left == 77)
            var->pnj->rect.left = 0;
        else
            var->pnj->rect.left = var->pnj->rect.left + 77;
        sfClock_restart(var->pnj->walk);
    }
    sfSprite_setTextureRect(var->pnj->sprite, var->pnj->rect);
    DRAW_SPRITE(var->pnj->sprite);
}
