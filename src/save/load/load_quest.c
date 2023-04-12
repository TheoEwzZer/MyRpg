/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

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
    if (var->quest_progress == BOSS)
        sfText_setString(var->quest_text->text, "Kill the boss");
}

bool load_quest(var_t *var, char *line)
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
        return true;
    }
    return false;
}
