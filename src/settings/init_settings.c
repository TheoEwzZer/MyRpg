/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

settings_t *init_settings(void)
{
    settings_t *menu = malloc(sizeof(settings_t));
    sfTexture *music_texture = CREATE_FROM_FILE("assets/settings/music.png");
    sfTexture *size_texture = CREATE_FROM_FILE("assets/settings/size.png");
    sfTexture *sound_texture = CREATE_FROM_FILE("assets/settings/sound.png");
    sfTexture *texture = CREATE_FROM_FILE("assets/settings/background.jpg");

    menu->menu_sprite = sfSprite_create();
    sfSprite_setTexture(menu->menu_sprite, texture, sfTrue);
    menu->music_sprite = sfSprite_create();
    sfSprite_setTexture(menu->music_sprite, music_texture, sfTrue);
    sfSprite_setPosition(menu->music_sprite, (sfVector2f){50, 150});
    menu->sound_sprite = sfSprite_create();
    sfSprite_setTexture(menu->sound_sprite, sound_texture, sfTrue);
    sfSprite_setPosition(menu->sound_sprite, (sfVector2f){600, 150});
    menu->size_sprite = sfSprite_create();
    sfSprite_setTexture(menu->size_sprite, size_texture, sfTrue);
    sfSprite_setPosition(menu->size_sprite, (sfVector2f){50, 600});
    init_settings_two(menu);
    return menu;
}

void init_settings_two(settings_t *menu)
{
    sfTexture *gauge0_texture = CREATE_FROM_FILE("assets/settings/gauge0.png");
    sfTexture *gauge1_texture = CREATE_FROM_FILE("assets/settings/gauge1.png");
    sfTexture *resolution_texture = CREATE_FROM_FILE("assets/settings/res.png");

    menu->resolution_sprite = sfSprite_create();
    sfSprite_setTexture(menu->resolution_sprite, resolution_texture, sfTrue);
    sfSprite_setPosition(menu->resolution_sprite, (sfVector2f){600, 600});
    menu->gauge_m = 2;
    menu->gauge_s = 2;
    menu->gauge_m0 = sfSprite_create(); menu->gauge_s0 = sfSprite_create();
    sfSprite_setTexture(menu->gauge_m0, gauge0_texture, sfTrue);
    sfSprite_setPosition(menu->gauge_m0, (sfVector2f){100, 400});
    sfSprite_setTexture(menu->gauge_s0, gauge0_texture, sfTrue);
    sfSprite_setPosition(menu->gauge_s0, (sfVector2f){650, 400});
    menu->gauge_m1 = sfSprite_create(); menu->gauge_s1 = sfSprite_create();
    sfSprite_setTexture(menu->gauge_m1, gauge1_texture, sfTrue);
    sfSprite_setPosition(menu->gauge_m1, (sfVector2f){100, 400});
    sfSprite_setTexture(menu->gauge_s1, gauge1_texture, sfTrue);
    sfSprite_setPosition(menu->gauge_s1, (sfVector2f){650, 400});
    init_settings_three(menu);
}

void init_settings_three(settings_t *menu)
{
    sfTexture *gauge2_texture = CREATE_FROM_FILE("assets/settings/gauge2.png");
    sfTexture *gauge3_texture = CREATE_FROM_FILE("assets/settings/gauge3.png");
    sfTexture *gauge4_texture = CREATE_FROM_FILE("assets/settings/gauge4.png");

    menu->gauge_m2 = sfSprite_create(); menu->gauge_s2 = sfSprite_create();
    sfSprite_setTexture(menu->gauge_m2, gauge2_texture, sfTrue);
    sfSprite_setPosition(menu->gauge_m2, (sfVector2f){100, 400});
    sfSprite_setTexture(menu->gauge_s2, gauge2_texture, sfTrue);
    sfSprite_setPosition(menu->gauge_s2, (sfVector2f){650, 400});
    menu->gauge_m3 = sfSprite_create(); menu->gauge_s3 = sfSprite_create();
    sfSprite_setTexture(menu->gauge_m3, gauge3_texture, sfTrue);
    sfSprite_setPosition(menu->gauge_m3, (sfVector2f){100, 400});
    sfSprite_setTexture(menu->gauge_s3, gauge3_texture, sfTrue);
    sfSprite_setPosition(menu->gauge_s3, (sfVector2f){650, 400});
    menu->gauge_m4 = sfSprite_create(); menu->gauge_s4 = sfSprite_create();
    sfSprite_setTexture(menu->gauge_m4, gauge4_texture, sfTrue);
    sfSprite_setPosition(menu->gauge_m4, (sfVector2f){100, 400});
    sfSprite_setTexture(menu->gauge_s4, gauge4_texture, sfTrue);
    sfSprite_setPosition(menu->gauge_s4, (sfVector2f){650, 400});
    init_mute(menu);
}

void init_mute(settings_t *menu)
{
    sfTexture *mute_texture = CREATE_FROM_FILE("assets/settings/mute.png");
    sfVector2f mute_music_pos = {50, 400};
    sfVector2f mute_sound_pos = {600, 400};

    menu->mute_music = sfSprite_create();
    sfSprite_setTexture(menu->mute_music, mute_texture, sfTrue);
    sfSprite_setPosition(menu->mute_music, mute_music_pos);
    menu->mute_sound = sfSprite_create();
    sfSprite_setTexture(menu->mute_sound, mute_texture, sfTrue);
    sfSprite_setPosition(menu->mute_sound, mute_sound_pos);
    init_resolution(menu);
}

void init_resolution(settings_t *menu)
{
    sfTexture *res1_texture = CREATE_FROM_FILE("assets/settings/800.png");
    sfTexture *res2_texture = CREATE_FROM_FILE("assets/settings/1920.png");
    sfVector2f res1_pos = {730, 750};
    sfVector2f res2_pos = {730, 880};
    sfVector2f size1_pos = {180, 750};
    sfVector2f size2_pos = {180, 880};

    menu->res1 = sfSprite_create();
    sfSprite_setTexture(menu->res1, res1_texture, sfTrue);
    sfSprite_setPosition(menu->res1, res1_pos);
    menu->res2 = sfSprite_create();
    sfSprite_setTexture(menu->res2, res2_texture, sfTrue);
    sfSprite_setPosition(menu->res2, res2_pos);
    menu->size1 = sfSprite_create();
    sfSprite_setTexture(menu->size1, res1_texture, sfTrue);
    sfSprite_setPosition(menu->size1, size1_pos);
    menu->size2 = sfSprite_create();
    sfSprite_setTexture(menu->size2, res2_texture, sfTrue);
    sfSprite_setPosition(menu->size2, size2_pos);
}
