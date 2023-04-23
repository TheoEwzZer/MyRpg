/*
** EPITECH PROJECT, 2023
** move.c
** File description:
** move.c
*/

#include "my_rpg.h"

sfBool check_intersects(sfFloatRect rect1, var_t *var)
{
    for (sfUint32 i = 0; i < 71; i++) {
        if (!COLLIDER[i])
            continue;
        if (sfFloatRect_intersects(&rect1, &var->collider_bounds[i], NULL))
            return sfTrue;
    }
    return sfFalse;
}

void check_move2(var_t *var, sfEvent event, sfFloatRect p_bounds)
{
    if (event.key.code == sfKeyUp || event.key.code == var->key_up) {
        p_bounds.top -= 10.0f;
        if (check_intersects(p_bounds, var))
            return;
        sfView_move(var->view, (sfVector2f){0.0f, -10.0f});
        sfSprite_move(PLAYER->sprite, (sfVector2f){0.0f, -10.0f});
        sfRectangleShape_move(PLAYER->hitbox, (sfVector2f){0.0f, -10.0f});
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){0.0f, -10.0f});
        up_move(var);
    }
    if (event.key.code == sfKeyDown || event.key.code == var->key_down) {
        p_bounds.height += 10.0f;
        if (check_intersects(p_bounds, var))
            return;
        sfView_move(var->view, (sfVector2f){0.0f, 10.0f});
        sfSprite_move(PLAYER->sprite, (sfVector2f){0.0f, 10.0f});
        sfRectangleShape_move(PLAYER->hitbox, (sfVector2f){0.0f, 10.0f});
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){0.0f, 10.0f});
        down_move(var);
    }
}

void check_move1(var_t *var, sfEvent event, sfFloatRect p_bounds)
{
    if (event.key.code == sfKeyLeft || event.key.code == var->key_left) {
        p_bounds.left -= 10.0f;
        if (check_intersects(p_bounds, var))
            return;
        sfView_move(var->view, (sfVector2f){-10.0f, 0.0f});
        sfSprite_move(PLAYER->sprite, (sfVector2f){-10.0f, 0.0f});
        sfRectangleShape_move(PLAYER->hitbox, (sfVector2f){-10.0f, 0.0f});
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){-10.0f, 0.0f});
        left_move(var);
    } if (event.key.code == sfKeyRight || event.key.code == var->key_right) {
        p_bounds.width += 10.0f;
        if (check_intersects(p_bounds, var))
            return;
        sfView_move(var->view, (sfVector2f){10.0f, 0.0f});
        sfSprite_move(PLAYER->sprite, (sfVector2f){10.0f, 0.0f});
        sfRectangleShape_move(PLAYER->hitbox, (sfVector2f){10.0f, 0.0f});
        sfRectangleShape_move(PLAYER->spear, (sfVector2f){10.0f, 0.0f});
        right_move(var);
    }
    check_move2(var, event, p_bounds);
}

void check_move(var_t *var, sfEvent event)
{
    sfFloatRect p_bounds = sfSprite_getGlobalBounds(PLAYER->sprite);
    sfVector2f size = {0.0f, 0.0f};
    float tmp = p_bounds.height;

    if (INVENTORY->is_open || var->is_lose || var->is_win || var->is_paused)
        return;
    p_bounds.height = p_bounds.height / 5.0f;
    p_bounds.top += tmp - p_bounds.height;
    p_bounds.width = 25.0f;
    p_bounds.left += 15.0f;
    size = (sfVector2f){p_bounds.width, p_bounds.height};
    sfRectangleShape_setSize(PLAYER->hitbox, size);
    check_move1(var, event, p_bounds);
}
