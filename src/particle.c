/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void move_particle_position_pnj(var_t *var, sfVector2f position)
{
    particle_t *particle = NULL;

    for (sfUint32 i = 0; i < CONFIG->max_particles; i++) {
        particle = &var->particles_pnj[i];
        particle->base_pos.x = position.x;
        particle->base_pos.y = position.y;
        particle->actual_pos.x = (float)(rand() % 21) + position.x - 10.0f;
        particle->actual_pos.y = position.y;
    }
}

void generate_particle_pnj(var_t *var, sfVector2f position)
{
    particle_t *p = NULL;
    sfTexture *texture = CREATE_FROM_FILE("assets/particle/pnj.png");

    var->particles_pnj = malloc(sizeof(particle_t) * CONFIG->max_particles);
    for (sfUint32 i = 0; i < CONFIG->max_particles; i++) {
        p = &var->particles_pnj[i];
        p->base_pos.x = position.x;
        p->base_pos.y = position.y;
        p->actual_pos.x = (float)(rand() % 21) + position.x - 10.0f;
        p->actual_pos.y = position.y;
        p->speed = (float)(rand() % 15 + 1) / 1000.0f;
        p->shape = sfRectangleShape_create();
        p->size = 0.2f;
        p->direction_x = (float)(rand() % 3 - 1) / 1.0f;
        p->sprite = sfSprite_create();
        sfSprite_setTexture(p->sprite, texture, sfTrue);
        sfSprite_setScale(p->sprite, (sfVector2f){p->size, p->size});
    }
}

void move_particle_pnj(var_t *var)
{
    particle_t *p = NULL;
    sfVector2f position = {0.0f, 0.0f};
    if (!var->is_particle_active)
        return;
    for (sfUint32 i = 0; i < CONFIG->max_particles; i++) {
        p = &var->particles_pnj[i];
        p->actual_pos.x += (float)(p->direction_x) * p->speed / 2.0f;
        p->actual_pos.y -= p->speed;
        p->size -= 0.0001f;
        if (p->actual_pos.y < p->base_pos.y - 10.0f || p->size < 0.0f) {
            p->actual_pos.y = p->base_pos.y;
            p->size = 0.2f;
            p->actual_pos.x = (float)(rand() % 21) + p->base_pos.x - 10.0f;
            p->direction_x = (float)(rand() % 3) - 1.0f;
        }
        position = (sfVector2f){p->actual_pos.x, p->actual_pos.y};
        sfSprite_setPosition(p->sprite, position);
        sfSprite_setScale(p->sprite, (sfVector2f){p->size, p->size});
        DRAW_SPRITE(p->sprite);
    }
}

void generate_leaves(var_t *var, sfTexture *leaf_texture)
{
    particle_t *leaf = NULL;

    var->particles_leaves = malloc(sizeof(particle_t) * CONFIG->max_leaves);
    for (sfUint32 i = 0; i < CONFIG->max_leaves; i++) {
        leaf = &var->particles_leaves[i];
        leaf->actual_pos.x = (float)(rand() % WIDTH - 1000) + 1000.0f;
        leaf->actual_pos.y = 0.0f;
        leaf->speed = (float)(rand() % 25 + 1) / 100.0f;
        leaf->oscillation = (float)(rand() / RAND_MAX) * 2.0f * (float)PI;
        leaf->rotation = 0.0f;
        leaf->sprite = sfSprite_create();
        sfSprite_setTexture(leaf->sprite, leaf_texture, sfTrue);
        sfSprite_setScale(leaf->sprite, (sfVector2f){0.005f, 0.005f});
    }
}

void move_leaves(var_t *var)
{
    float x = 0.0f;
    particle_t *leaf = NULL;
    sfVector2f position = {0.0f, 0.0f};

    for (sfUint32 i = 0; i < CONFIG->max_leaves; i++) {
        x = (float)var->frame_count * (float)(i / 2 + 1) * 0.0005f;
        leaf = &var->particles_leaves[i];
        leaf->actual_pos.x += sinf(leaf->oscillation + x) / 10.0f;
        leaf->actual_pos.y += leaf->speed;
        leaf->rotation -= sinf(leaf->oscillation + x) / 10.0f;
        if (leaf->actual_pos.y > 1920.0f) {
            leaf->actual_pos.y = 0.0f;
            leaf->speed = (float)(rand() % 25 + 1) / 100.0f;
        }
        position = leaf->actual_pos;
        sfSprite_setPosition(leaf->sprite, position);
        sfSprite_setRotation(leaf->sprite, leaf->rotation);
        DRAW_SPRITE(leaf->sprite);
    }
}
