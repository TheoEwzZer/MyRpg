/*
** EPITECH PROJECT, 2023
** free.c
** File description:
** free.c
*/

#include "my_rpg.h"

void free_inventory_and_dialog(var_t *var)
{
    sfFont_destroy(var->dialog->font);
    sfSprite_destroy(var->dialog->sprite);
    sfText_destroy(var->dialog->name);
    sfText_destroy(var->dialog->text);
    sfTexture_destroy(var->dialog->texture);
    sfSprite_destroy(INVENTORY->bar);
    sfSprite_destroy(INVENTORY->lance);
    sfSprite_destroy(INVENTORY->potion);
    sfText_destroy(INVENTORY->atk);
    sfTexture_destroy(INVENTORY->exp0);
    sfTexture_destroy(INVENTORY->exp1);
    sfTexture_destroy(INVENTORY->exp2);
    sfTexture_destroy(INVENTORY->exp3);
    sfTexture_destroy(INVENTORY->exp4);
    sfTexture_destroy(INVENTORY->exp5);
    sfTexture_destroy(INVENTORY->exp6);
    sfTexture_destroy(INVENTORY->exp7);
    sfTexture_destroy(INVENTORY->spear);
    sfTexture_destroy(INVENTORY->texture);
    free(var->dialog); free(INVENTORY);
}

void free_character2(var_t *var)
{
    sfClock_destroy(PLAYER->walk);
    sfSprite_destroy(PLAYER->sprite);
    sfTexture_destroy(PLAYER->texture);
    free(PLAYER);
    sfClock_destroy(var->pnj->walk);
    sfSprite_destroy(var->pnj->sprite);
    sfTexture_destroy(var->pnj->texture);
    free(var->pnj);
    sfClock_destroy(SKELETON->walk);
    sfSprite_destroy(SKELETON->sprite);
    sfTexture_destroy(SKELETON->texture);
    free(SKELETON);
}

void free_character(var_t *var)
{
    sfClock_destroy(BLACKSMITH->walk);
    sfSprite_destroy(BLACKSMITH->sprite);
    sfTexture_destroy(BLACKSMITH->texture);
    free(BLACKSMITH);
    sfClock_destroy(var->girl->walk);
    sfSprite_destroy(var->girl->sprite);
    sfTexture_destroy(var->girl->texture);
    free(var->girl);
    sfClock_destroy(ORC->walk);
    sfSprite_destroy(ORC->sprite);
    sfTexture_destroy(ORC->texture);
    free(ORC);
}

void free_boss(var_t *var)
{
    sfClock_destroy(BOSSV->clock);
    sfSprite_destroy(BOSSV->room);
    sfTexture_destroy(BOSSV->boss_room);
    sfTexture_destroy(BOSSV->map);
    sfTexture_destroy(BOSSV->fire);
    sfClock_destroy(BOSSC->fireball);
    sfClock_destroy(BOSSC->walk);
    sfSprite_destroy(BOSSC->sprite);
    sfTexture_destroy(BOSSC->texture);
    free(BOSSC);
    free(BOSSV);
    sfSprite_destroy(var->background_sprite);
    sfTexture_destroy(var->armor);
    sfView_destroy(var->default_view);
    sfView_destroy(var->view);
    sfRenderWindow_destroy(var->window);
}

void free_all(var_t *var)
{
    free_boss(var);
    free_character(var);
    free_character2(var);
    free_inventory_and_dialog(var);
    free_life_and_quest(var);
    free(var);
}
