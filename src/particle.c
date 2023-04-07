/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void generate_particle(var_t *var)
{
    particle_t *p = NULL;

    for (unsigned int i = 0; i < 10; i++) {
        p = &var->particles[i];
        p->x = (float)(rand() % WIDTH - 200) + 200;
        p->y = 0.0f;
        p->speed = (float)(rand() % 2 + 1) / 10.0f;
        p->oscillation = (float)(rand() / RAND_MAX) * 2.0f * (float)PI;
        p->rotation = 0.0f;
        p->rotationSpeed = (float)(rand() % 10 + 1) / 10.0f;
    }
}

void move_particle(var_t *var, sfSprite *particle_sprite)
{
    sfVector2f view_offset = sfView_getCenter(var->view);
    particle_t *p = NULL;
    sfVector2f position = {0, 0};
    view_offset.x -= sfView_getSize(var->view).x / 2;
    view_offset.y -= sfView_getSize(var->view).y / 2;
    for (unsigned int i = 0; i < MAX_PARTICLES; i++) {
        p = &var->particles[i];
        p->x += sinf(p->oscillation + (float)var->frame_count * 0.005f);
        p->y += p->speed; p->rotation += p->rotationSpeed;
        if (p->x < -10.0f || p->x > WIDTH + 10 || p->y > HEIGHT + 10) {
            p->x = (float)(rand() % WIDTH - 200) + 200;
            p->y = 0.0f;
            p->rotation = 0.0f;
            p->rotationSpeed = (float)(rand() % 10 + 1) / 10.0f;
        }
        position = (sfVector2f){p->x + view_offset.x, p->y + view_offset.y};
        sfSprite_setPosition(particle_sprite, position);
        sfSprite_setRotation(particle_sprite, p->rotation);
        sfRenderWindow_drawSprite(var->window, particle_sprite, NULL);
    }
}
