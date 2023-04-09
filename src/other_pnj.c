/*
** EPITECH PROJECT, 2023
** other_pnj
** File description:
** other_pnj
*/

#include "my_rpg.h"

void init_char(var_t *var)
{
    BLACKSMITH->clothes = CREATE_FROM_FILE("assets/pnj/blacksmith.png");
    BLACKSMITH->sprite = sfSprite_create();
    sfSprite_setTexture(BLACKSMITH->sprite, BLACKSMITH->clothes, sfTrue);
    BLACKSMITH->walk = sfClock_create();
    sfSprite_setPosition(BLACKSMITH->sprite, (sfVector2f){530, 1120});
    sfSprite_setScale(BLACKSMITH->sprite, (sfVector2f){0.75f, 0.75f});
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

void blacksmith_move(var_t *var)
{
    BLACKSMITH->times = sfClock_getElapsedTime(BLACKSMITH->walk);
    BLACKSMITH->second = (float)BLACKSMITH->times.microseconds / 1000000.0f;
    BLACKSMITH->rect.top = 0;
    BLACKSMITH->rect.width = 77;
    BLACKSMITH->rect.height = 77;
    if (BLACKSMITH->second > 0.8f) {
        if (BLACKSMITH->rect.left == 77)
            BLACKSMITH->rect.left = 0;
        else
            BLACKSMITH->rect.left = BLACKSMITH->rect.left + 77;
        sfClock_restart(BLACKSMITH->walk);
    }
    sfSprite_setTextureRect(BLACKSMITH->sprite, BLACKSMITH->rect);
    DRAW_SPRITE(BLACKSMITH->sprite);
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
