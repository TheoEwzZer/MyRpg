/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

settings_t *init_settings(void)
{
    settings_t *menuv = malloc(sizeof(settings_t));
    sfTexture *music_texture = CREATE_FROM_FILE("assets/settings/music.png");
    sfTexture *size_texture = CREATE_FROM_FILE("assets/settings/size.png");
    sfTexture *sound_texture = CREATE_FROM_FILE("assets/settings/sound.png");
    sfTexture *texture = CREATE_FROM_FILE("assets/settings/background.jpg");

    menuv->menusprite = sfSprite_create();
    sfSprite_setTexture(menuv->menusprite, texture, sfTrue);
    menuv->musicsprite = sfSprite_create();
    sfSprite_setTexture(menuv->musicsprite, music_texture, sfTrue);
    sfSprite_setPosition(menuv->musicsprite, (sfVector2f){50, 150});
    menuv->soundsprite = sfSprite_create();
    sfSprite_setTexture(menuv->soundsprite, sound_texture, sfTrue);
    sfSprite_setPosition(menuv->soundsprite, (sfVector2f){600, 150});
    menuv->sizesprite = sfSprite_create();
    sfSprite_setTexture(menuv->sizesprite, size_texture, sfTrue);
    sfSprite_setPosition(menuv->sizesprite, (sfVector2f){50, 600});
    init_settingstwo(menuv);
    return menuv;
}

void init_settingstwo(settings_t *menuv)
{
    sfTexture *jauge0_texture = CREATE_FROM_FILE("assets/settings/jauge0.png");
    sfTexture *jauge1_texture = CREATE_FROM_FILE("assets/settings/jauge1.png");
    sfTexture *resolution_texture = CREATE_FROM_FILE("assets/settings/res.png");

    menuv->resolutionsprite = sfSprite_create();
    sfSprite_setTexture(menuv->resolutionsprite, resolution_texture, sfTrue);
    sfSprite_setPosition(menuv->resolutionsprite, (sfVector2f){600, 600});
    menuv->jaugem = 2;
    menuv->jauges = 2;
    menuv->jaugem0 = sfSprite_create(); menuv->jauges0 = sfSprite_create();
    sfSprite_setTexture(menuv->jaugem0, jauge0_texture, sfTrue);
    sfSprite_setPosition(menuv->jaugem0, (sfVector2f){100, 400});
    sfSprite_setTexture(menuv->jauges0, jauge0_texture, sfTrue);
    sfSprite_setPosition(menuv->jauges0, (sfVector2f){650, 400});
    menuv->jaugem1 = sfSprite_create(); menuv->jauges1 = sfSprite_create();
    sfSprite_setTexture(menuv->jaugem1, jauge1_texture, sfTrue);
    sfSprite_setPosition(menuv->jaugem1, (sfVector2f){100, 400});
    sfSprite_setTexture(menuv->jauges1, jauge1_texture, sfTrue);
    sfSprite_setPosition(menuv->jauges1, (sfVector2f){650, 400});
    init_settingsthree(menuv);
}

void init_settingsthree(settings_t *menuv)
{
    sfTexture *jauge2_texture = CREATE_FROM_FILE("assets/settings/jauge2.png");
    sfTexture *jauge3_texture = CREATE_FROM_FILE("assets/settings/jauge3.png");
    sfTexture *jauge4_texture = CREATE_FROM_FILE("assets/settings/jauge4.png");

    menuv->jaugem2 = sfSprite_create(); menuv->jauges2 = sfSprite_create();
    sfSprite_setTexture(menuv->jaugem2, jauge2_texture, sfTrue);
    sfSprite_setPosition(menuv->jaugem2, (sfVector2f){100, 400});
    sfSprite_setTexture(menuv->jauges2, jauge2_texture, sfTrue);
    sfSprite_setPosition(menuv->jauges2, (sfVector2f){650, 400});
    menuv->jaugem3 = sfSprite_create(); menuv->jauges3 = sfSprite_create();
    sfSprite_setTexture(menuv->jaugem3, jauge3_texture, sfTrue);
    sfSprite_setPosition(menuv->jaugem3, (sfVector2f){100, 400});
    sfSprite_setTexture(menuv->jauges3, jauge3_texture, sfTrue);
    sfSprite_setPosition(menuv->jauges3, (sfVector2f){650, 400});
    menuv->jaugem4 = sfSprite_create(); menuv->jauges4 = sfSprite_create();
    sfSprite_setTexture(menuv->jaugem4, jauge4_texture, sfTrue);
    sfSprite_setPosition(menuv->jaugem4, (sfVector2f){100, 400});
    sfSprite_setTexture(menuv->jauges4, jauge4_texture, sfTrue);
    sfSprite_setPosition(menuv->jauges4, (sfVector2f){650, 400});
    init_mute(menuv);
}

void init_mute(settings_t *menuv)
{
    sfTexture *mute_texture = CREATE_FROM_FILE("assets/settings/mute.png");
    sfVector2f mutem_pos = {50, 400};
    sfVector2f mutes_pos = {600, 400};

    menuv->mutem = sfSprite_create();
    sfSprite_setTexture(menuv->mutem, mute_texture, sfTrue);
    sfSprite_setPosition(menuv->mutem, mutem_pos);
    menuv->mutes = sfSprite_create();
    sfSprite_setTexture(menuv->mutes, mute_texture, sfTrue);
    sfSprite_setPosition(menuv->mutes, mutes_pos);
    init_resolution(menuv);
}

void init_resolution(settings_t *menuv)
{
    sfTexture *res1_texture = CREATE_FROM_FILE("assets/settings/800.png");
    sfTexture *res2_texture = CREATE_FROM_FILE("assets/settings/1920.png");
    sfVector2f res1_pos = {730, 750};
    sfVector2f res2_pos = {730, 880};
    sfVector2f size1_pos = {180, 750};
    sfVector2f size2_pos = {180, 880};

    menuv->res1 = sfSprite_create();
    sfSprite_setTexture(menuv->res1, res1_texture, sfTrue);
    sfSprite_setPosition(menuv->res1, res1_pos);
    menuv->res2 = sfSprite_create();
    sfSprite_setTexture(menuv->res2, res2_texture, sfTrue);
    sfSprite_setPosition(menuv->res2, res2_pos);
    menuv->size1 = sfSprite_create();
    sfSprite_setTexture(menuv->size1, res1_texture, sfTrue);
    sfSprite_setPosition(menuv->size1, size1_pos);
    menuv->size2 = sfSprite_create();
    sfSprite_setTexture(menuv->size2, res2_texture, sfTrue);
    sfSprite_setPosition(menuv->size2, size2_pos);
}
