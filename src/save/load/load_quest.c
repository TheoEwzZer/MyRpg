/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void load_inventory(var_t *var)
{
    if (var->quest_progress >= ENEMIES) {
        INVENTORY->texture = CREATE_FROM_FILE("assets/player/inventory_2.png");
        sfSprite_setTexture(INVENTORY->sprite, INVENTORY->texture, sfTrue);
    }
}

void change_quest_text(var_t *var)
{
    if (var->quest_progress == PRISCILLA) {
        sfText_setString(var->quest_text->text, "Talk to Priscilla");
        var->quest_text->position = (sfVector2f){10.0f, 8.0f};
    }
    if (var->quest_progress == ARMOR) {
        sfText_setString(var->quest_text->text, "Go to the blacksmith");
        var->quest_text->position = (sfVector2f){5.0f, 10.0f};
    }
    if (var->quest_progress == ENEMIES) {
        sfText_setString(var->quest_text->text, "Kill the enemies");
        var->quest_text->position = (sfVector2f){7.0f, 8.0f};
    }
    if (var->quest_progress == BOB)
        sfText_setString(var->quest_text->text, "Talk to Bob");
    if (var->quest_progress == BOSS) {
        sfText_setString(var->quest_text->text, "Kill the boss");
        var->is_particle_active = sfFalse;
        COLLIDER[9] = NULL;
    }
    load_inventory(var);
}

sfBool load_quest(var_t *var, char *line)
{
    if (!my_strncmp(line, "quest_progress: ", 16)) {
        var->quest_progress = my_getnbr(line + 16);
        if (var->quest_progress > ARMOR) {
            sfSprite_setTexture(PLAYER->sprite, var->armor, sfTrue);
            PLAYER->rect = (sfIntRect){0, 0, 77, 77};
            sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
        }
        if (var->quest_progress == ARMOR || var->quest_progress == ENEMIES)
            move_particle_position_pnj(var, (sfVector2f){555.0f, 1110.0f});
        change_quest_text(var);
        return sfTrue;
    }
    if (!my_strncmp(line, "skeleton_life: ", 15)) {
        var->skeleton->life = my_getnbr(line + 15);
        return sfTrue;
    } if (!my_strncmp(line, "orc_life: ", 10)) {
        var->orc->life = my_getnbr(line + 10);
        return sfTrue;
    }
    return sfFalse;
}

sfBool load_boss(var_t *var, char *line)
{
    if (!my_strncmp(line, "boss_life: ", 11)) {
        BOSSC->life = my_getnbr(line + 11);
        return sfTrue;
    }
    if (!my_strncmp(line, "boss_position_x: ", 17)) {
        BOSSV->b_pos.x = my_getnbr(line + 17);
        return sfTrue;
    }
    if (!my_strncmp(line, "boss_position_y: ", 17)) {
        BOSSV->b_pos.y = my_getnbr(line + 17);
        return sfTrue;
    }
    return sfFalse;
}
