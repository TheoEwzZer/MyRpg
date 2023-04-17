/*
** EPITECH PROJECT, 2023
** character_move
** File description:
** character_move
*/

#include "my_rpg.h"

void init_sound(var_t *var)
{
    SOUND->theme = sfMusic_createFromFile("assets/music/main_theme.ogg");
    sfMusic_setVolume(SOUND->theme, 50.0f);
    SOUND->spear = sfSound_create();
    SOUND->spear_buf = sfSoundBuffer_createFromFile("assets/music/spear.ogg");
    sfSound_setBuffer(SOUND->spear, SOUND->spear_buf);
    sfSound_setVolume(SOUND->spear, 50.0f);
}

void init_boss(var_t *var)
{
    BOSSV->boss->clothes = CREATE_FROM_FILE("assets/pnj/Boss.png");
    BOSSV->boss->sprite = sfSprite_create();
    sfSprite_setTexture(BOSSV->boss->sprite, BOSSV->boss->clothes, sfTrue);
    BOSSV->boss->walk = sfClock_create();
    sfSprite_setPosition(BOSSV->boss->sprite, (sfVector2f){750.0f, 2800.0f});
    sfSprite_setScale(BOSSV->boss->sprite, (sfVector2f){0.75f, 0.75f});
    BOSSV->boss->life = 200;
    BOSSV->fire = CREATE_FROM_FILE("assets/particle/fireball.png");
    BOSSV->fireball = sfSprite_create();
    sfSprite_setTexture(BOSSV->fireball, BOSSV->fire, sfTrue);
    BOSSV->clock = sfClock_create();
}
