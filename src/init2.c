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
    BOSSC->life = 300;
    BOSSV->fire = CREATE_FROM_FILE("assets/particle/fireball.png");
    init_fireball(var);
    BOSSV->clock = sfClock_create();
}

void init_inventory(var_t *var)
{
    sfFont *font = sfFont_createFromFile("assets/font/arial.ttf");

    INVENTORY->atk = sfText_create();
    INVENTORY->bottle = CREATE_FROM_FILE("assets/player/potion.png");
    INVENTORY->drink = sfTrue;
    INVENTORY->lance = sfSprite_create();
    INVENTORY->potion = sfSprite_create();
    INVENTORY->spear = CREATE_FROM_FILE("assets/player/lance.png");
    sfSprite_setScale(INVENTORY->lance, (sfVector2f){0.15f, 0.15f});
    sfSprite_setScale(INVENTORY->potion, (sfVector2f){0.04f, 0.04f});
    sfSprite_setTexture(INVENTORY->lance, INVENTORY->spear, sfTrue);
    sfSprite_setTexture(INVENTORY->potion, INVENTORY->bottle, sfTrue);
    sfText_setCharacterSize(INVENTORY->atk, 30);
    sfText_setColor(INVENTORY->atk, sfBlack);
    sfText_setFont(INVENTORY->atk, font);
    sfText_setScale(INVENTORY->atk, (sfVector2f){1.0f, 1.0f});
    sfText_setString(INVENTORY->atk, "20");
}

void init_exp(var_t *var)
{
    INVENTORY->exp0 = CREATE_FROM_FILE("assets/exp/empty_xp_bare.png");
    INVENTORY->exp1 = CREATE_FROM_FILE("assets/exp/xp_lvl1_1-3.png");
    INVENTORY->exp2 = CREATE_FROM_FILE("assets/exp/xp_lvl1_2-3.png");
    INVENTORY->exp3 = CREATE_FROM_FILE("assets/exp/empty_xp_bare_lvl2.png");
    INVENTORY->exp4 = CREATE_FROM_FILE("assets/exp/xp_lvl2_1-5.png");
    INVENTORY->exp5 = CREATE_FROM_FILE("assets/exp/xp_lvl2_2-5.png");
    INVENTORY->exp6 = CREATE_FROM_FILE("assets/exp/xp_lvl2_3-5.png");
    INVENTORY->exp7 = CREATE_FROM_FILE("assets/exp/xp_lvl2_4-5.png");
    INVENTORY->bar = sfSprite_create();
    sfSprite_setTexture(INVENTORY->bar, INVENTORY->exp0, sfTrue);
    sfSprite_setScale(INVENTORY->bar, (sfVector2f){0.2f, 0.2f});
}
