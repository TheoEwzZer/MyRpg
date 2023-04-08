/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void generate_particle_pnj(var_t *var, sfVector2f pos)
{
    particle_t *p = NULL;

    for (unsigned int i = 0; i < MAX_PARTICLES; i++) {
        p = &var->particles2[i];
        p->base_pos.x = pos.x;
        p->base_pos.y = pos.y;
        p->actu_pos.x = (float)(rand() % 21) + pos.x - 10.0f;
        p->actu_pos.y = pos.y;
        p->speed = (float)(rand() % 16 + 5) / 1000.0f;
        p->shape = sfRectangleShape_create();
        p->size = 5.0f;
        p->direction_x = (float)(rand() % 3 - 1) / 1.0f;
        sfRectangleShape_setSize(p->shape, (sfVector2f){p->size, p->size});
        sfRectangleShape_setFillColor(p->shape, sfWhite);
    }
}

void move_particle_pnj(var_t *var)
{
    particle_t *p = NULL;
    sfVector2f position = {0, 0};
    if (!var->is_particle_active)
        return;
    for (unsigned int i = 0; i < MAX_PARTICLES; i++) {
        p = &var->particles2[i];
        p->actu_pos.x += (float)(p->direction_x) * p->speed / 2.0f;
        p->actu_pos.y -= p->speed;
        p->size -= 0.001f;
        if (p->actu_pos.y < p->base_pos.y - 25.0f || p->size < 0.0f) {
            p->actu_pos.y = p->base_pos.y;
            p->size = 5.0f;
            p->actu_pos.x = (float)(rand() % 21) + p->base_pos.x - 10.0f;
            p->direction_x = (float)(rand() % 3) - 1;
        }
        position = (sfVector2f){p->actu_pos.x, p->actu_pos.y};
        sfRectangleShape_setPosition(p->shape, position);
        sfRectangleShape_setSize(p->shape, (sfVector2f){p->size, p->size});
        sfRenderWindow_drawRectangleShape(var->window, p->shape, NULL);
    }
}

void generate_leaves(var_t *var, sfTexture *leaf_texture)
{
    particle_t *leaf = NULL;

    for (unsigned int i = 0; i < MAX_PARTICLES; i++) {
        leaf = &var->particles[i];
        leaf->actu_pos.x = (float)(rand() % WIDTH - 200) + 200;
        leaf->actu_pos.y = 0.0f;
        leaf->speed = (float)(rand() % 5 + 1) / 10.0f;
        leaf->osci = (float)(rand() / RAND_MAX) * 2.0f * (float)PI;
        leaf->rotation = 0.0f;
        leaf->sprite = sfSprite_create();
        sfSprite_setTexture(leaf->sprite, leaf_texture, sfTrue);
        sfSprite_setScale(leaf->sprite, (sfVector2f){0.005f, 0.005f});
    }
}

void move_leaves(var_t *var)
{
    sfVector2f offset = sfView_getCenter(var->view);
    particle_t *leaf = NULL;
    sfVector2f position = {0, 0};
    offset.x -= sfView_getSize(var->view).x / 2;
    offset.y -= sfView_getSize(var->view).y / 2;
    for (unsigned int i = 0; i < MAX_PARTICLES; i++) {
        leaf = &var->particles[i];
        leaf->actu_pos.x += sinf(leaf->osci + (float)var->frame_count * 0.005f);
        leaf->actu_pos.y += leaf->speed;
        leaf->rotation -= sinf(leaf->osci + (float)var->frame_count * 0.005f);
        if (leaf->actu_pos.y > HEIGHT) {
            leaf->actu_pos.y = 0.0f;
            leaf->speed = (float)(rand() % 5 + 1) / 10.0f;
        }
        position.x = leaf->actu_pos.x + offset.x;
        position.y = leaf->actu_pos.y + offset.y;
        sfSprite_setPosition(leaf->sprite, position);
        sfSprite_setRotation(leaf->sprite, leaf->rotation);
        DRAW_SPRITE(leaf->sprite);
    }
}
