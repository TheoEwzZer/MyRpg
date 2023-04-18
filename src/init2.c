/*
** EPITECH PROJECT, 2023
** character_move
** File description:
** character_move
*/

#include "my_rpg.h"

void init_sound(var_t *var)
{
    SOUND->music = sfMusic_createFromFile("assets/music/main_theme.ogg");
    sfMusic_setVolume(SOUND->music, 50.0f);
    SOUND->sound = sfSound_create();
    SOUND->buffer = sfSoundBuffer_createFromFile("assets/music/spear.ogg");
    sfSound_setBuffer(SOUND->sound, SOUND->buffer);
    sfSound_setVolume(SOUND->sound, 50.0f);
}

void init_fireball(var_t *var)
{
    sfVector2f size = {20.0f, 20.0f};

    BOSSC->fireball = sfClock_create();
    FIREBALL = malloc(sizeof(fireball_t *) * MAX_FIREBALL);
    for (sfUint32 i = 0; i < MAX_FIREBALL; i++) {
        FIREBALL[i] = malloc(sizeof(fireball_t));
        FIREBALL[i]->is_active = sfFalse;
        FIREBALL[i]->sprite = sfSprite_create();
        sfSprite_setTexture(FIREBALL[i]->sprite, BOSSV->fire, sfTrue);
        sfSprite_setScale(FIREBALL[i]->sprite, (sfVector2f){0.10f, 0.10f});
        FIREBALL[i]->hitbox = sfRectangleShape_create();
        sfRectangleShape_setSize(FIREBALL[i]->hitbox, size);
    }
}

void init_boss(var_t *var)
{
    BOSSC->texture = CREATE_FROM_FILE("assets/pnj/Boss.png");
    BOSSC->sprite = sfSprite_create();
    sfSprite_setTexture(BOSSC->sprite, BOSSC->texture, sfTrue);
    BOSSC->walk = sfClock_create();
    sfSprite_setPosition(BOSSC->sprite, (sfVector2f){750.0f, 2800.0f});
    sfSprite_setScale(BOSSC->sprite, (sfVector2f){0.75f, 0.75f});
    BOSSC->life = 200;
    BOSSV->fire = CREATE_FROM_FILE("assets/particle/fireball.png");
    init_fireball(var);
    BOSSV->clock = sfClock_create();
}
